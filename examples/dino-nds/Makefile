ifeq ($(strip $(DEVKITPRO)),)
$(error "Please set DEVKITPRO in your environment")
endif

ifeq ($(strip $(DEVKITARM)),)
$(error "Please set DEVKITARM in your environment")
endif

include $(DEVKITARM)/ds_rules

CFLAGS = -O3 -I$(DEVKITPRO)/libnds/include -DARM9 -march=armv5te -mtune=arm946e-s -fomit-frame-pointer -mthumb -mthumb-interwork -ffast-math
LDFLAGS = -specs=ds_arm9.specs -mthumb -mthumb-interwork -L$(DEVKITPRO)/libnds/lib -lnds9 -lm

%.elf:


dino.nds: dino.elf

dino.elf: dino.o main.o
	$(CC) $^ -o $@ $(LDFLAGS)

%.c: %.wasm
	../../w2c2 $< > $@

%.o: %.c
	$(CC) -I../.. $(CFLAGS) -c $< -o $@

.PHONY: clean
clean:
	rm -f *.o dino.c dino.elf
