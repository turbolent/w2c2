BUILD := release

ifeq ($(OS),Windows_NT)
	UNAME := Windows
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
# - unistd.h
# - threads
FEATURES ?= unistd threads

ifeq ($(UNAME),Linux)
	LDFLAGS += -lm
endif

ifneq (,$(findstring unistd,$(FEATURES)))
	CFLAGS += -DHAS_UNISTD=1
endif

ifneq (,$(findstring threads,$(FEATURES)))
ifeq ($(UNAME),Windows)
	CFLAGS += -DWASM_THREADS_WIN32
else
	CFLAGS += -pthread -DWASM_THREADS_PTHREADS
endif
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

.PHONY: clean

TARGET_OBJECTS = $(patsubst %.c,%.o,$(filter-out %_test.c test.c,$(wildcard *.c)))
TEST_OBJECTS = $(patsubst %.c,%.o,$(filter-out main.c,$(wildcard *.c)))

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

libw2c2futex.a: $(TARGET_OBJECTS)
	$(AR) qc $@ $^
	ranlib $@

futex_test: $(TEST_OBJECTS)
	$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS)

.PHONY: test
test: futex_test
	./futex_test

clean:
	-rm -f *.o *.a
	-rm -f futex_test
