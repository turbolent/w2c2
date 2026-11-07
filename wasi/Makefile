BUILD := release

ifeq ($(OS),Windows_NT)
	UNAME := Windows
endif
ifndef UNAME
	UNAME := $(shell uname -s)
endif

WARNS ?= -Wunused-result -Wall -Wpedantic -Wno-long-long -Wno-unused-function

ifeq ($(BUILD),release)
	CFLAGS += -O3
else
	CFLAGS += -g -O0
endif

CFLAGS += -std=c89 $(WARNS)

ifeq ($(UNAME),Darwin)
	CFLAGS += -D_BSD_SOURCE=1
endif

# By default assume the system has
# - unistd.h
# - sys/uio.h
# - sys/time.h
# - sys/resource.h
# - strndup
# - fcntl
# - timespec
# - lstat
# - getentropy
# - poll
# - sched_yield (except on Windows)
# - futimens, utimensat, futimes, utimes, lutimes, utime (except on Windows)
# - linkat, link, realpath (except on Windows)
# - posix_fallocate, posix_fadvise (on Linux)
# - F_PREALLOCATE (on Darwin)
# - threads
DEFAULT_FEATURES := unistd sysuio systime sysresource strndup fcntl timespec lstat getentropy threads
ifneq ($(UNAME),Windows)
DEFAULT_FEATURES += poll sched_yield futimens utimensat futimes utimes lutimes utime
DEFAULT_FEATURES += linkat link realpath
endif
ifeq ($(UNAME),Linux)
DEFAULT_FEATURES += posix_fallocate posix_fadvise
endif
ifeq ($(UNAME),Darwin)
DEFAULT_FEATURES += f_preallocate
endif
FEATURES ?= $(DEFAULT_FEATURES)

ifeq ($(UNAME),Linux)
	LDFLAGS += -lm
endif

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

ifneq (,$(findstring timespec,$(FEATURES)))
	CFLAGS += -DHAS_TIMESPEC=1
endif

ifneq (,$(findstring fcntl,$(FEATURES)))
	CFLAGS += -DHAS_FCNTL=1
endif

ifneq (,$(findstring lstat,$(FEATURES)))
	CFLAGS += -DHAS_LSTAT=1
endif

ifneq (,$(findstring getentropy,$(FEATURES)))
	CFLAGS += -DHAS_GETENTROPY=1
endif

ifneq (,$(findstring poll,$(FEATURES)))
	CFLAGS += -DHAS_POLL=1
endif

ifneq (,$(findstring sched_yield,$(FEATURES)))
	CFLAGS += -DHAS_SCHED_YIELD=1
endif

ifneq (,$(filter futimens,$(FEATURES)))
	CFLAGS += -DHAS_FUTIMENS=1
endif

ifneq (,$(filter utimensat,$(FEATURES)))
	CFLAGS += -DHAS_UTIMENSAT=1
endif

ifneq (,$(filter futimes,$(FEATURES)))
	CFLAGS += -DHAS_FUTIMES=1
endif

ifneq (,$(filter utimes,$(FEATURES)))
	CFLAGS += -DHAS_UTIMES=1
endif

ifneq (,$(filter lutimes,$(FEATURES)))
	CFLAGS += -DHAS_LUTIMES=1
endif

ifneq (,$(filter utime,$(FEATURES)))
	CFLAGS += -DHAS_UTIME=1
endif

ifneq (,$(filter linkat,$(FEATURES)))
	CFLAGS += -DHAS_LINKAT=1
endif

ifneq (,$(filter link,$(FEATURES)))
	CFLAGS += -DHAS_LINK=1
endif

ifneq (,$(filter realpath,$(FEATURES)))
	CFLAGS += -DHAS_REALPATH=1
endif

ifneq (,$(filter posix_fallocate,$(FEATURES)))
	CFLAGS += -DHAS_POSIX_FALLOCATE=1
endif

ifneq (,$(filter posix_fadvise,$(FEATURES)))
	CFLAGS += -DHAS_POSIX_FADVISE=1
endif

ifneq (,$(filter f_preallocate,$(FEATURES)))
	CFLAGS += -DHAS_F_PREALLOCATE=1
endif

ifneq (,$(findstring threads,$(FEATURES)))
ifeq ($(UNAME),Windows)
	CFLAGS += -DWASM_THREADS_WIN32
else
	CFLAGS += -pthread -DWASM_THREADS_PTHREADS
endif
endif

ifneq (,$(findstring tracing,$(FEATURES)))
	CFLAGS += -DWASI_TRACE_ENABLED=1
endif

ifneq (,$(findstring base,$(SANITIZERS)))
CFLAGS += -fsanitize=undefined
endif
ifneq (,$(findstring clang,$(SANITIZERS)))
CFLAGS += -fsanitize=integer -fsanitize=implicit-conversion
endif
ifneq (,$(findstring address,$(SANITIZERS)))
CFLAGS += -fsanitize=address -fno-omit-frame-pointer
endif
ifneq (,$(findstring thread,$(SANITIZERS)))
CFLAGS += -fsanitize=thread
endif

.PHONY: clean

SOURCES := $(filter-out test.c,$(wildcard *.c))
ifneq ($(UNAME),Windows)
SOURCES := $(filter-out win32.c,$(SOURCES))
endif
OBJECTS = $(patsubst %.c,%.o,$(SOURCES))

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

libw2c2wasi.a: $(OBJECTS)
	$(AR) qc $@ $^
	ranlib $@

.PHONY: test
test: wasi_test
	./wasi_test

wasi_test: $(OBJECTS) test.c
	$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS)

clean:
	-rm -f *.o *.a
	-rm -f wasi_test
