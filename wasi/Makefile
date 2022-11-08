CFLAGS += -std=c89 -Wunused-result -Wall -Wno-long-long -Wno-unused-function -DPATH_MAX=65536
LDFLAGS += -lm

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

OBJECTS = $(patsubst %.c,%.o,$(wildcard *.c))

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

test: CFLAGS += -g -O0
test: $(OBJECTS)
	$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS)

clean:
	-rm -f *.o
	-rm -f test
