W2C2 ?= ../../w2c2/w2c2
LDFLAGS += -lm $(shell sdl2-config --libs)
CFLAGS += $(shell sdl2-config --cflags)

dino: dino.o main.o
	$(CC) $^ -o $@ $(LDFLAGS)

%.c: %.wasm
	$(W2C2) $< $@

%.o: %.c
	$(CC) -I../.. $(CFLAGS) -c $< -o $@

.PHONY: clean
clean:
	rm -f *.o dino.c dino.h dino
