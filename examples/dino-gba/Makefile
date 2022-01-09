W2C2 ?= ../../w2c2

ifeq ($(strip $(DEVKITPRO)),)
$(error "Please set DEVKITPRO in your environment")
endif

ifeq ($(strip $(DEVKITARM)),)
$(error "Please set DEVKITARM in your environment")
endif

include $(DEVKITARM)/gba_rules

CFLAGS = -O3 -Wall -I$(DEVKITPRO)/libgba/include -mcpu=arm7tdmi -mtune=arm7tdmi -fomit-frame-pointer -ffast-math -mthumb -mthumb-interwork
LDFLAGS = -specs=gba.specs -mthumb -mthumb-interwork -L$(DEVKITPRO)/libgba/lib -lgba -lm

%.elf:

dino.elf: dino.o main.o
	$(CC) $^ -o $@ $(LDFLAGS)

dingo.gba: dino.elf

%.c: %.wasm
	$(W2C2) -o $@ $<

%.o: %.c
	$(CC) -I../.. $(CFLAGS) -c $< -o $@

.PHONY: clean
clean:
	rm -f *.o dino.c dino.elf
