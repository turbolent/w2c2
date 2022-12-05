W2C2 ?= ../w2c2
PYTHON3 ?= python3

CFLAGS ?= -O0 -g

EXE =

ifeq ($(TARGET),Wii)

ifeq ($(strip $(DEVKITPRO)),)
$(error "Please set DEVKITPRO in your environment")
endif

ifeq ($(strip $(DEVKITPPC)),)
$(error "Please set DEVKITPPC in your environment")
endif

include $(DEVKITPPC)/wii_rules

CFLAGS = $(MACHDEP)
LDFLAGS = $(MACHDEP) -L$(DEVKITPRO)/libogc/lib/wii -logc
EXE = .elf

DOLPHIN ?= dolphin
EXECUTE ?= $(DOLPHIN) -b -e

%.elf:

endif

LDFLAGS += -lm

.SILENT:

.PHONY: run-tests gen clean clean-wasm-json clean-assertions clean-compiled

run-tests: $(patsubst gen/assert_%.c,run-test-%,$(wildcard gen/assert_*.c))

run-tests-%:
	$(MAKE) $(patsubst gen/assert_%.c,run-test-%,$(wildcard gen/assert_$**.c))

run-test-%: test_%$(EXE)
	echo ">>>" $<
	$(EXECUTE) ./$<
	echo

test_%$(EXE): test_%.o main.o
	$(CC) $< main.o -o $@ $(LDFLAGS)

test_%.c: gen/%.wasm
	echo "#include \"test.h\"" > $@
	$(W2C2) $< $@
	cat $(patsubst test_%.c,gen/assert_%.c,$@) >> $@

%.o: %.c
	$(CC) -I.. $(CFLAGS) -c $< -o $@

gen:
	$(PYTHON3) gen.py

gen-%:
	$(PYTHON3) gen.py $*

clean:
	-rm -f main.o test_*
