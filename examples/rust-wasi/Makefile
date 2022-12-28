W2C2 ?= ../../w2c2
LDFLAGS += -lm
CFLAGS += -O3

rust-wasi: target/wasm32-wasi/debug/rust-wasi.o main.o
	$(CC) $(CFLAGS) $^ ../../wasi/wasi.a -o rust-wasi $(LDFLAGS)

%.c: %.wasm
	$(W2C2) $< $@

%.o: %.c
	$(CC) -I../.. $(CFLAGS) -c $< -o $@

target/wasm32-wasi/debug/rust-wasi.wasm:
	cargo build --target wasm32-wasi

.PHONY: clean
clean:
	rm -f target/wasm32-wasi/debug/rust-wasi.c target/wasm32-wasi/debug/rust-wasi.o *.o rust-wasi rustwasi.h rustwasi.c
