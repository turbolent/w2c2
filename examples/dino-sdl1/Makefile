W2C2 ?= ../../w2c2
LDFLAGS += -lm $(shell sdl-config --libs)
CFLAGS += $(shell sdl-config --cflags)

dino: dino.o main.o
	$(CC) $^ -o $@ $(LDFLAGS)

%.c: %.wasm
	$(W2C2) -o $@ $<

%.o: %.c
	$(CC) -I../.. $(CFLAGS) -c $< -o $@

.PHONY: clean
clean:
	rm -f *.o dino.c dino
