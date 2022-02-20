BUILD := release

ifeq ($(OS),Windows_NT)
	UNAME := Windows
endif
ifdef WASI_CC
	UNAME := WASI
	CC := $(WASI_CC)
endif
ifndef UNAME
	UNAME := $(shell uname -s)
endif

ifeq ($(BUILD),release)
	CFLAGS += -O3
else
	CFLAGS += -g -O0
endif

CFLAGS += -std=c89 -Wunused-result -Wall -Wpedantic -Wno-long-long -Wno-unused-function

ifeq ($(UNAME),Windows)
	OUTPUT := w2c2.exe
	CC := clang
	CFLAGS += -D_CRT_SECURE_NO_WARNINGS
endif
ifeq ($(UNAME),WASI)
	OUTPUT := w2c2.wasm
endif
ifeq ($(UNAME),Linux)
	LDFLAGS += -lm
	ifneq (,$(findstring threads,$(FEATURES)))
	CFLAGS += -pthread
	endif
endif

ifneq (,$(findstring threads,$(FEATURES)))
	CFLAGS += -DHAS_PTHREAD
endif

ifneq (,$(findstring getopt,$(FEATURES)))
	CFLAGS += -DHAS_GETOPT
endif

ifneq (,$(findstring debugging,$(FEATURES)))
	CFLAGS += -DHAS_LIBDWARF
	LDFLAGS += -ldwarf
endif

ifndef OUTPUT
	OUTPUT := w2c2
endif

ifneq (,$(findstring base,$(SANITIZERS)))
CFLAGS += -fsanitize=undefined
endif
ifneq (,$(findstring clang,$(SANITIZERS)))
CFLAGS += -fsanitize=integer -fsanitize=implicit-conversion
endif
ifneq (,$(findstring address,$(SANITIZERS)))
CFLAGS += -fsanitize=address
endif
ifneq (,$(findstring thread,$(SANITIZERS)))
CFLAGS += -fsanitize=thread
endif

.PHONY: all clean

all: $(OUTPUT)

TARGET_OBJECTS = $(patsubst %.c,%.o,$(filter-out %_test.c test.c,$(wildcard *.c)))
TEST_OBJECTS = $(patsubst %.c,%.o,$(filter-out main.c,$(wildcard *.c)))

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(OUTPUT): $(TARGET_OBJECTS)
	$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS)

w2c2_test: $(TEST_OBJECTS)
	$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS)

clean:
	-rm -f *.o
	-rm -f $(OUTPUT) w2c2_test
