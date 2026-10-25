CFLAGS += -I../../w2c2 -O0 -g
LDFLAGS += -lm -L../../wasi -lw2c2wasi
W2C2 ?= ../../w2c2/w2c2

MODE ?= gnu-ld

ifneq (,$(findstring sectcreate,$(MODE)))
	LDFLAGS += -sectcreate __DATA m10_swiftX2Dwasi m10_swiftx2dwasi.data
endif
ifeq ($(MODE),gnu-ld)
    OBJS += m10_swiftx2dwasi.data.o
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
	rm -f swift-wasi swiftwasi.h m10_swiftx2dwasi.data $(filter-out main.c,$(wildcard *.c)) *.o
