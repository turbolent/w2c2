CFLAGS += -I../../w2c2 -O0 -g
LDFLAGS += -lm -L../../wasi -lw2c2wasi
W2C2 ?= ../../w2c2/w2c2

MODE ?= gnu-ld

ifneq (,$(findstring sectcreate,$(MODE)))
	LDFLAGS += -sectcreate __DATA __datasegments datasegments
endif
ifeq ($(MODE),gnu-ld)
    OBJS += datasegments.o
endif

swift-wasi: swiftwasi.o
	$(MAKE) -f Submake CC="$(CC)" CFLAGS="$(CFLAGS)" LDFLAGS="$(LDFLAGS)" OBJS="$(OBJS)"

swiftwasi.c: swift-wasi.wasm
	$(W2C2) -d $(MODE) -f 100 $^ $@

.build/wasm32-unknown-wasi/release/swift-wasi.wasm:
	swift build -Xswiftc -Osize -c release --triple wasm32-unknown-wasi

swift-wasi.wasm: .build/wasm32-unknown-wasi/release/swift-wasi.wasm
	wasm-opt --strip-dwarf -O4 -o $@ $<

.PHONY: clean
clean:
	rm -f swift-wasi swiftwasi.h datasegments $(filter-out main.c,$(wildcard *.c)) *.o
