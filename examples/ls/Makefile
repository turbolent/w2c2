LDFLAGS += -lm
CFLAGS += -O3
W2C2 ?= ../../w2c2

ls: ls.o main.o
	$(CC) $^ ../../wasi/wasi.a -o ls $(LDFLAGS)

%.c: src/%.wasm
	$(W2C2) $< $@

%.o: %.c
	$(CC) -I../.. -c $(CFLAGS) $< -o $@

.PHONY: clean
clean:
	rm -f *.o ls ls.h
