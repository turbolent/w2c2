W2C2 ?= ../../w2c2
LDFLAGS += -lm

swift-wasi: ../../wasi/wasi.o inits.o
	$(MAKE) $(patsubst %.c,%.o,$(wildcard *.c))
	$(CC) $(CFLAGS) $(patsubst %.c,%.o,$(wildcard *.c)) ../../wasi/wasi.o -o swift-wasi $(LDFLAGS)

%.c: %.wasm
	$(W2C2) -o $@ $<

%.o: %.c
	$(CC) -I../.. -O3 $(CFLAGS) -c $< -o $@

inits.o: CFLAGS += -O0

inits.c: .build/wasm32-unknown-wasi/release/swift-wasi.opt.wasm
	$(W2C2) -j 12 -o . -f 100 $^

.build/wasm32-unknown-wasi/release/swift-wasi.wasm:
	swift build -Xswiftc -Osize -c release --triple wasm32-unknown-wasi

%.opt.wasm: %.wasm
	wasm-opt --strip-dwarf -O4 -o $@ $<

.PHONY: clean
clean:
	rm -f .build/wasm32-unknown-wasi/release/swift-wasi.opt.c .build/wasm32-unknown-wasi/release/swift-wasi.opt.o decls.h $(filter-out main.c,$(wildcard *.c)) *.o swift-wasi
