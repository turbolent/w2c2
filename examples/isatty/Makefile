LDFLAGS += -lm -L../../wasi -lcwasi
CFLAGS += -O3
W2C2 ?= ../../w2c2

isatty: isatty.o main.o
	$(CC) $^ -o isatty $(LDFLAGS)

%.c: %.wasm
	$(W2C2) $< $@

%.o: %.c
	$(CC) -I../.. -c $(CFLAGS) $< -o $@

.PHONY: clean
clean:
	rm -f *.o isatty isatty.c isatty.h
