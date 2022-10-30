LDFLAGS += -lm
CFLAGS += -O3
W2C2 ?= ../../w2c2

fac: fac.o main.o
	$(CC) $^ -o fac $(LDFLAGS)

%.c: %.wasm
	$(W2C2) $< $@

%.o: %.c
	$(CC) -I../.. -c $(CFLAGS) $< -o $@

.PHONY: clean
clean:
	rm -f *.o fac fac.h
