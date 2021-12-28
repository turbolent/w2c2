LDFLAGS += -lm
CFLAGS += -O3

rust-wasi: target/wasm32-wasi/debug/rust-wasi.o main.o ../../wasi/wasi.o
	$(CC) $^ -o rust-wasi $(LDFLAGS)

%.c: %.wasm
	../../w2c2 -o $@ $<

%.o: %.c
	$(CC) -I../.. $(CFLAGS) -c $< -o $@

target/wasm32-wasi/debug/rust-wasi.wasm:
	cargo build --target wasm32-wasi

.PHONY: clean
clean:
	rm -f *.o rust-wasi
