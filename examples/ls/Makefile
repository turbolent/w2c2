LDFLAGS += -lm -L../../wasi -lw2c2wasi
CFLAGS += -O3
W2C2 ?= ../../w2c2/w2c2

ls: ls.o main.o
	$(CC) $^ -o ls $(LDFLAGS)

%.c: src/%.wasm
	$(W2C2) $< $@

%.o: %.c
	$(CC) -I../../w2c2 -c $(CFLAGS) $< -o $@

.PHONY: clean
clean:
	rm -f *.o ls ls.h
