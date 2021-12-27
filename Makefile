CFLAGS = -std=c89 -Wunused-result -Wall -Wpedantic -Wno-long-long -Wno-unused-function -pthread

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

.PHONY: release debug clean

release: CFLAGS += -O3
release: w2c2

debug: CFLAGS += -g -O0
debug: w2c2

TARGET_OBJECTS = $(patsubst %.c,%.o,$(filter-out %_test.c test.c,$(wildcard *.c)))
TEST_OBJECTS = $(patsubst %.c,%.o,$(filter-out main.c,$(wildcard *.c)))

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

w2c2: $(TARGET_OBJECTS)
	$(CC) $(CFLAGS) $^ -o $@

w2c2_test: $(TEST_OBJECTS)
	$(CC) $(CFLAGS) $^ -o $@

clean:
	-rm -f *.o
	-rm -f w2c2 w2c2_test
