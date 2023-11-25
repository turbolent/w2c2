LDFLAGS += -lm

ifeq ($(BUILD),release)
	CFLAGS += -O3
else
	CFLAGS += -g -O0
endif

WARNS ?= -Wunused-result -Wall -Wpedantic -Wno-long-long -Wno-unused-function

CFLAGS += -std=c89 $(WARNS)

FEATURES ?= pthreads

ifneq (,$(findstring pthreads,$(FEATURES)))
	CFLAGS += -pthread -DWASM_THREADS_PTHREADS
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

test: $(TEST_OBJECTS)
	$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS)

clean:
	-rm -f *.o *.a
	-rm -f test
