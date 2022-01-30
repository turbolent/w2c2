CFLAGS += -I../..
LDFLAGS += -lm
W2C2 ?= ../../w2c2

OBJS :=  ../../wasi/wasi.o inits.o

ifeq ($(shell uname -s),Darwin)
    LDFLAGS += -sectcreate __DATA __datasegments datasegments
else
    OBJS += datasegments.o
endif

clang: $(OBJS)
	$(MAKE) $(patsubst %.c,%.o,$(wildcard *.c))
	$(CC) $(CFLAGS) $(filter-out inits.o, $(patsubst %.c,%.o,$(wildcard *.c))) $(OBJS) -o clang $(LDFLAGS)

datasegments.o: inits.c
	ld -r -b binary -o datasegments.o datasegments

inits.o: CFLAGS += -O0

%.o: %.c
	$(CC) -I.. -O3 $(CFLAGS) -c $< -o $@

inits.c: clang.wasm
	$(W2C2) -d gnu-ld -j 12 -o . -f 100 $^

.PHONY: clean
clean:
	rm -f clang datasegments decls.h $(filter-out main.c,$(wildcard *.c)) *.o
