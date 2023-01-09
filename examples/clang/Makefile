CFLAGS += -I../../w2c2
LDFLAGS += -lm -L../../wasi -lw2c2wasi
W2C2 ?= ../../w2c2/w2c2

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

clang: clang.o
	$(MAKE) $(patsubst %.c,%.o,$(wildcard *.c)) $(OBJS)
	$(CC) $(CFLAGS) $(patsubst %.c,%.o,$(wildcard *.c)) $(OBJS) -o clang $(LDFLAGS)

datasegments.o: clang.c
	ld -r -b binary -o datasegments.o datasegments

clang.o: CFLAGS += -O0

%.o: %.c
	$(CC) -I.. -O3 $(CFLAGS) -c $< -o $@

clang.c: clang.wasm
	$(W2C2) -d $(MODE) -f 100 $^ $@

.PHONY: clean
clean:
	rm -f clang clang.h datasegments $(filter-out main.c,$(wildcard *.c)) *.o
