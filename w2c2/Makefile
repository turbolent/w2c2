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

WARNS ?= -Wunused-result -Wall -Wpedantic -Werror=conversion -Wno-long-long -Wno-unused-function

ifeq ($(BUILD),release)
	CFLAGS += -O3
else
	CFLAGS += -g -O0
endif

CFLAGS += -std=c89 $(WARNS)

# By default assume the system has
# - pthreads
# - getopt
# - unistd.h
# - libgen.h
# - strdup
# - glob
FEATURES ?= threads getopt unistd libgen strdup glob

ifeq ($(UNAME),Windows)
	OUTPUT := w2c2.exe
endif
ifeq ($(UNAME),WASI)
	OUTPUT := w2c2.wasm
endif
ifeq ($(UNAME),Linux)
	LDFLAGS += -lm
ifneq (,$(findstring debugging,$(FEATURES)))
	CFLAGS += -I/usr/include/libdwarf
endif
	ifneq (,$(findstring threads,$(FEATURES)))
	CFLAGS += -pthread
	endif
endif

ifneq (,$(findstring threads,$(FEATURES)))
	CFLAGS += -DHAS_PTHREAD=1
endif

ifneq (,$(findstring getopt,$(FEATURES)))
	CFLAGS += -DHAS_GETOPT=1
endif

ifneq (,$(findstring unistd,$(FEATURES)))
	CFLAGS += -DHAS_UNISTD=1
endif

ifneq (,$(findstring libgen,$(FEATURES)))
	CFLAGS += -DHAS_LIBGEN=1
endif

ifneq (,$(findstring strdup,$(FEATURES)))
	CFLAGS += -DHAS_STRDUP=1
endif

ifneq (,$(findstring glob,$(FEATURES)))
	CFLAGS += -DHAS_GLOB=1
endif

ifneq (,$(findstring debugging,$(FEATURES)))
	CFLAGS += -DHAS_LIBDWARF=1
	LDFLAGS += -ldwarf
endif

ifneq (,$(findstring old_debugging,$(FEATURES)))
	CFLAGS += -DHAS_OLD_LIBDWARF=1
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
