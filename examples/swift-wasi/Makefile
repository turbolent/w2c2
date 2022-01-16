W2C2 ?= ../../w2c2
LDFLAGS += -lm
CFLAGS += -O3

swift-wasi: .build/wasm32-unknown-wasi/release/swift-wasi.opt.o main.o ../../wasi/wasi.o
	$(CC) $(CFLAGS) $^ -o swift-wasi $(LDFLAGS)

%.c: %.wasm
	$(W2C2) -o $@ $<

%.o: %.c
	$(CC) -I../.. $(CFLAGS) -c $< -o $@

.build/wasm32-unknown-wasi/release/swift-wasi.wasm:
	swift build -c release --triple wasm32-unknown-wasi

%.opt.wasm: %.wasm
	wasm-opt --strip-dwarf -O4 -o $@ $<

.PHONY: clean
clean:
	rm -f *.o swift-wasi
