TARGET = w2c2
TEST_TARGET = $(TARGET)_test
CFLAGS = -std=c89 -Wunused-result -Wall -Wpedantic -Wno-long-long -Wno-unused-function

.PHONY: release debug clean

release: CFLAGS += -O3
release: $(TARGET)

debug: CFLAGS += -g -O0 -fsanitize=undefined -fsanitize=integer -fsanitize=implicit-conversion -fsanitize=address
debug: $(TARGET)

SUB_OBJECTS = $(filter-out main.o test.o,$(patsubst %.c, %.o, $(wildcard *.c)))
TARGET_OBJECTS = $(filter-out $(wildcard *_test.o),$(SUB_OBJECTS)) main.o
TEST_OBJECTS = $(SUB_OBJECTS) test.o
HEADERS = $(wildcard *.h)

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

$(TARGET): $(TARGET_OBJECTS)
	$(CC) $(CFLAGS) $(TARGET_OBJECTS) -Wall -o $@

$(TEST_TARGET): $(TEST_OBJECTS)
	$(CC) $(CFLAGS) $(TEST_OBJECTS) -Wall $(LIBS) -o $@

clean:
	-rm -f *.o
	-rm -f $(TARGET) $(TEST_TARGET)
