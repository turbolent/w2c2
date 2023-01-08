LDFLAGS += -lm -L../../wasi -lwasi
CFLAGS += -O3
W2C2 ?= ../../w2c2/w2c2

isatty: isatty.o main.o
	$(CC) $^ -o isatty $(LDFLAGS)

%.c: %.wasm
	$(W2C2) $< $@

%.o: %.c
	$(CC) -I../../w2c2 -c $(CFLAGS) $< -o $@

.PHONY: clean
clean:
	rm -f *.o isatty isatty.c isatty.h
