CFLAGS += -I../..
LDFLAGS += -lm
W2C2 ?= ../../w2c2

OBJS := ../../wasi/wasi.o python.o

python: $(OBJS)
	$(MAKE) $(patsubst %.c,%.o,$(wildcard *.c))
	$(CC) $(CFLAGS) $(filter-out python.o, $(patsubst %.c,%.o,$(wildcard *.c))) $(OBJS) -o python $(LDFLAGS)

%.o: %.c
	$(CC) -I.. -O2 $(CFLAGS) -c $< -o $@

python.c: python.wasm
	$(W2C2) -j 8 -f 100 $^ $@

.PHONY: clean
clean:
	rm -f python python.h $(filter-out main.c,$(wildcard *.c)) *.o
