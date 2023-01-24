CFLAGS += -I../../w2c2
LDFLAGS += -lm -L../../wasi -lw2c2wasi
W2C2 ?= ../../w2c2/w2c2

MODE ?= gnu-ld

ifeq ($(shell uname -s),Darwin)
    ifeq ($(MODE),gnu-ld)
        # at least Darwin 11 / Mac OS X 10.7 ?
        ifeq ($(shell test `uname -r | egrep -o "^[0-9]+"` -gt 10; echo $$?),0)
            MODE = sectcreate1
        else
            MODE = sectcreate2
        endif
        LDFLAGS += -sectcreate __DATA __datasegments datasegments
    endif
endif
ifeq ($(MODE),gnu-ld)
    OBJS += datasegments.o
endif


clang: clang.o
	$(MAKE) -f Submake CC="$(CC)" CFLAGS="$(CFLAGS)" LDFLAGS="$(LDFLAGS)" OBJS="$(OBJS)"

clang.c: clang.wasm
	$(W2C2) -d $(MODE) -f 100 $^ $@

.PHONY: clean
clean:
	rm -f clang clang.h datasegments $(filter-out main.c,$(wildcard *.c)) *.o
