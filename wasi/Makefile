LDFLAGS += -lm

ifeq ($(BUILD),release)
	CFLAGS += -O3
else
	CFLAGS += -g -O0
endif

WARNS ?= -Wunused-result -Wall -Wpedantic -Wno-long-long -Wno-unused-function

CFLAGS += -std=c89 $(WARNS)

# By default assume the system has
# - unistd.h
# - sys/uio.h
# - sys/time.h
# - sys/resource.h
# - strndup
FEATURES ?= unistd sysuio systime sysresource strndup

ifneq (,$(findstring unistd,$(FEATURES)))
	CFLAGS += -DHAS_UNISTD=1
endif

ifneq (,$(findstring sysuio,$(FEATURES)))
	CFLAGS += -DHAS_SYSUIO=1
endif

ifneq (,$(findstring systime,$(FEATURES)))
	CFLAGS += -DHAS_SYSTIME=1
endif

ifneq (,$(findstring sysresource,$(FEATURES)))
	CFLAGS += -DHAS_SYSRESOURCE=1
endif

ifneq (,$(findstring strndup,$(FEATURES)))
	CFLAGS += -DHAS_STRNDUP=1
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

OBJECTS = $(patsubst %.c,%.o,$(wildcard *.c))

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

test: $(OBJECTS)
	$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS)

clean:
	-rm -f *.o
	-rm -f test
