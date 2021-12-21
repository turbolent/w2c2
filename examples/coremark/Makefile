LDFLAGS += -lm
CFLAGS += -O3

coremark: coremark.o main.o ../../wasi/wasi.o
	$(CC) $^ -o coremark $(LDFLAGS)

%.c: %.wasm
	../../w2c2 $< > $@

%.o: %.c
	$(CC) -I../.. -c $(CFLAGS) $< -o $@

.PHONY: clean
clean:
	rm -f *.o coremark
