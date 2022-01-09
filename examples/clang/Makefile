CFLAGS += -I../..
LDFLAGS += -lm
W2C2 ?= ../../w2c2

clang: ../../wasi/wasi.o inits.o
	$(MAKE) $(patsubst %.c,%.o,$(wildcard *.c))
	$(CC) $(CFLAGS) $(patsubst %.c,%.o,$(wildcard *.c)) ../../wasi/wasi.o -o clang $(LDFLAGS)

inits.o: CFLAGS += -O0

%.o: %.c
	$(CC) -I.. -O3 $(CFLAGS) -c $< -o $@

inits.c: clang.wasm
	$(W2C2) -j 12 -o . -f 100 $^

.PHONY: clean
clean:
	rm -f clang decls.h $(filter-out main.c,$(wildcard *.c)) *.o
