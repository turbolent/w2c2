LDFLAGS += -lm
CFLAGS += -O3

rust-wasi: rust-wasi.o main.o ../../wasi/wasi.o
	$(CC) $^ -o rust-wasi $(LDFLAGS)

%.c: %.wasm
	../../w2c2 -o $@ $<

%.o: %.c
	$(CC) -I../.. $(CFLAGS) -c $< -o $@

.PHONY: clean
clean:
	rm -f *.o rust-wasi
