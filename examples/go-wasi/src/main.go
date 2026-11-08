package main

import (
	"io"
	"net"
	"os"
	"strconv"
	"syscall"
	"time"
)

func check(err error) {
	if err != nil {
		panic(err)
	}
}

func main() {
	println("Hello from Go!")
	testSockets()

	directory, err := os.MkdirTemp("/tmp", "go-wasi-")
	check(err)
	defer func() {
		check(os.RemoveAll(directory))
	}()

	path := directory + "/original"
	file, err := os.Create(path)
	check(err)
	defer file.Close()

	fd := int(file.Fd())
	check(syscall.SetNonblock(fd, true))
	check(syscall.SetNonblock(fd, false))
	println("Toggled nonblocking mode")

	const contents = "Hello through a hard link!\n"
	_, err = file.WriteString(contents)
	check(err)
	check(file.Close())

	modified := time.Unix(1700000000, 0)
	check(os.Chtimes(path, modified, modified))
	info, err := os.Stat(path)
	check(err)
	if !info.ModTime().Equal(modified) {
		panic("modification time was not updated")
	}
	println("Updated file timestamps")

	link := directory + "/link"
	check(os.Link(path, link))
	linkInfo, err := os.Stat(link)
	check(err)
	if !os.SameFile(info, linkInfo) {
		panic("hard link does not refer to the original file")
	}
	check(os.Remove(path))
	data, err := os.ReadFile(link)
	check(err)
	if string(data) != contents {
		panic("hard link contents changed")
	}
	println("Read hard link after removing the original")
}

func socketFile(argument, name string) *os.File {
	fd, err := strconv.Atoi(argument)
	check(err)
	file := os.NewFile(uintptr(fd), name)
	if file == nil {
		panic("invalid socket descriptor")
	}
	return file
}

func testSockets() {
	if len(os.Args) != 3 {
		panic("expected listener and client descriptors")
	}
	listenerFile := socketFile(os.Args[1], "listener")
	listener, err := net.FileListener(listenerFile)
	check(err)
	check(listenerFile.Close())
	defer listener.Close()
	check(listener.(*net.TCPListener).SetDeadline(time.Now().Add(5 * time.Second)))

	clientFile := socketFile(os.Args[2], "client")
	client, err := net.FileConn(clientFile)
	check(err)
	check(clientFile.Close())
	defer client.Close()
	check(client.SetDeadline(time.Now().Add(5 * time.Second)))

	const request = "Hello through a socket!"
	const reply = "Received the complete request."
	done := make(chan struct{})
	go func() {
		defer close(done)
		server, err := listener.Accept()
		check(err)
		defer server.Close()
		check(server.SetDeadline(time.Now().Add(5 * time.Second)))
		data, err := io.ReadAll(server)
		check(err)
		if string(data) != request {
			panic("socket request changed")
		}
		_, err = io.WriteString(server, reply)
		check(err)
		check(server.(*net.TCPConn).CloseWrite())
	}()

	_, err = io.WriteString(client, request)
	check(err)
	check(client.(*net.TCPConn).CloseWrite())
	data, err := io.ReadAll(client)
	check(err)
	if string(data) != reply {
		panic("socket reply changed")
	}
	<-done
	println("Exchanged socket messages and closed each write channel")
}
