LDFLAGS += -lm $(shell sdl-config --libs)
CFLAGS += $(shell sdl-config --cflags)

dino: dino.o main.o
	$(CC) $^ -o $@ $(LDFLAGS)

%.c: %.wasm
	../../w2c2 $< > $@

%.o: %.c
	$(CC) -I../.. $(CFLAGS) -c $< -o $@

.PHONY: clean
clean:
	rm -f *.o dino.c dino
