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

rust-wasi: rustwasi.o
	$(MAKE) $(patsubst %.c,%.o,$(wildcard *.c))
	$(CC) $(CFLAGS) $(patsubst %.c,%.o,$(wildcard *.c)) -o rust-wasi $(LDFLAGS)

datasegments.o: rustwasi.c
	ld -r -b binary -o datasegments.o datasegments

%.o: %.c
	$(CC) -I.. $(CFLAGS) -c $< -o $@

rustwasi.c: target/wasm32-wasi/debug/rust-wasi.wasm
	$(W2C2) -d $(MODE) -f 100 $^ $@


target/wasm32-wasi/debug/rust-wasi.wasm:
	cargo build --target wasm32-wasi

.PHONY: clean
clean:
	rm -f rust-wasi rustwasi.h $(filter-out main.c,$(wildcard *.c)) *.o
