package main

import (
	"os"
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
