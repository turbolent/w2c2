CFLAGS += -I../.. -O0 -g
LDFLAGS += -lm -L../../wasi -lwasi
W2C2 ?= ../../w2c2

MODE := gnu-ld

ifeq ($(shell uname -s),Darwin)
    # at least Darwin 11 / Mac OS X 10.7 ?
    ifeq ($(shell test `uname -r | egrep -o "^[0-9]+"` -gt 10; echo $$?),0)
    MODE = sectcreate1
    else
    MODE = sectcreate2
    endif
    LDFLAGS += -sectcreate __DATA __datasegments datasegments
else
    OBJS += datasegments.o
endif

swift-wasi: swiftwasi.o
	$(MAKE) $(patsubst %.c,%.o,$(wildcard *.c))
	$(CC) $(CFLAGS) $(patsubst %.c,%.o,$(wildcard *.c)) -o swift-wasi $(LDFLAGS)

datasegments.o: swiftwasi.c
	ld -r -b binary -o datasegments.o datasegments

%.o: %.c
	$(CC) -I.. $(CFLAGS) -c $< -o $@

swiftwasi.c: swift-wasi.wasm
	$(W2C2) -d $(MODE) -f 100 $^ $@

.build/wasm32-unknown-wasi/release/swift-wasi.wasm:
	swift build -Xswiftc -Osize -c release --triple wasm32-unknown-wasi

swift-wasi.wasm: .build/wasm32-unknown-wasi/release/swift-wasi.wasm
	wasm-opt --strip-dwarf -O4 -o $@ $<

.PHONY: clean
clean:
	rm -f swift-wasi swiftwasi.h $(filter-out main.c,$(wildcard *.c)) *.o
