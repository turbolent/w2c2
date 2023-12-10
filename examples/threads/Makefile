LDFLAGS += -lm -L../../wasi -lw2c2wasi -L../../futex -lw2c2futex
CFLAGS += -O0 -g
W2C2 ?= ../../w2c2/w2c2

ifeq ($(OS),Windows_NT)
	CFLAGS += -DWASM_THREADS_WIN32
else
	CFLAGS += -pthread -DWASM_THREADS_PTHREADS
endif

threads: threads.o main.o
	$(CC) $(CFLAGS) $^ -o threads $(LDFLAGS)

%.c: src/%.wasm
	$(W2C2) -g $< $@

%.o: %.c
	$(CC) -I../../w2c2 -c $(CFLAGS) $< -o $@

.PHONY: clean
clean:
	rm -f *.o threads threads.h
