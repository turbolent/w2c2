W2C2 ?= ../../w2c2
LDFLAGS += -lm

swift-wasi: swiftwasi.o
	$(MAKE) $(patsubst %.c,%.o,$(wildcard *.c))
	$(CC) $(CFLAGS) $(patsubst %.c,%.o,$(wildcard *.c)) ../../wasi/wasi.o -o swift-wasi $(LDFLAGS)

swiftwasi.o: CFLAGS += -O0

%.o: %.c
	$(CC) -I../.. -O3 $(CFLAGS) -c $< -o $@

swiftwasi.c: swift-wasi.wasm
	$(W2C2) -f 100 $^ $@

.build/wasm32-unknown-wasi/release/swift-wasi.wasm:
	swift build -Xswiftc -Osize -c release --triple wasm32-unknown-wasi

swift-wasi.wasm: .build/wasm32-unknown-wasi/release/swift-wasi.wasm
	wasm-opt --strip-dwarf -O4 -o $@ $<

.PHONY: clean
clean:
	rm -f $(filter-out main.c,$(wildcard *.c)) *.o swiftwasi.h swift-wasi swift-wasi.wasm
