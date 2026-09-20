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
	SUFFIX := .exe
endif
ifeq ($(UNAME),WASI)
	SUFFIX := .wasm
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

SHARED_LIB ?= 0
PREFIX ?= /usr/local
LIBDIR ?= $(PREFIX)/lib
INCLUDEDIR ?= $(PREFIX)/include/w2c2
BINDIR ?= $(PREFIX)/bin

LIB_SOURCES = $(filter-out main.c compat.c file.c %_test.c test.c,$(wildcard *.c))
LIB_OBJECTS = $(LIB_SOURCES:.c=.o)
TEST_OBJECTS = $(patsubst %.c,%.o,$(filter %_test.c test.c,$(wildcard *.c)))
LIBRARY = libw2c2.a

ifeq ($(SHARED_LIB),1)
ifneq (,$(filter Windows WASI,$(UNAME)))
$(error Shared w2c2 libraries are supported only on POSIX systems)
endif
LIB_OBJECTS = $(LIB_SOURCES:.c=.pic.o)
ifeq ($(UNAME),Darwin)
LIBRARY = libw2c2.dylib
SHARED_FLAGS = -dynamiclib -Wl,-install_name,@rpath/libw2c2.dylib
RPATH = -Wl,-rpath,@loader_path -Wl,-rpath,@loader_path/../lib
else
LIBRARY = libw2c2.so
SHARED_FLAGS = -shared -Wl,-soname,libw2c2.so
RPATH = -Wl,-rpath,'$$ORIGIN' -Wl,-rpath,'$$ORIGIN/../lib'
endif
endif

w2c2$(SUFFIX): main.o compat.o file.o $(LIBRARY)
w2c2_test$(SUFFIX): $(TEST_OBJECTS) file.o $(LIBRARY)
w2c2_embed$(SUFFIX): ../examples/embed/main.c $(LIBRARY)
w2c2_embedding_test$(SUFFIX): ../tests/embedding/main.c $(LIBRARY)

w2c2$(SUFFIX) w2c2_test$(SUFFIX) w2c2_embed$(SUFFIX) w2c2_embedding_test$(SUFFIX):
	$(CC) $(CFLAGS) -I. $^ -o $@ $(LDFLAGS) $(RPATH)

$(LIBRARY): $(LIB_OBJECTS)
ifeq ($(SHARED_LIB),1)
	$(CC) $(CFLAGS) $(SHARED_FLAGS) $^ -o $@ $(LDFLAGS)
else
	$(AR) rcs $@ $^
endif

%.o: %.c $(wildcard *.h)
	$(CC) $(CFLAGS) -c $< -o $@

%.pic.o: %.c $(wildcard *.h)
	$(CC) $(CFLAGS) -fPIC -c $< -o $@

.PHONY: test
test: w2c2_test$(SUFFIX) w2c2_embedding_test$(SUFFIX) w2c2_embed$(SUFFIX)
	./w2c2_test$(SUFFIX)
	./w2c2_embedding_test$(SUFFIX)
	./w2c2_embed$(SUFFIX)

PUBLIC_HEADERS = $(shell cat public_headers.txt)

.PHONY: install
install: w2c2$(SUFFIX)
	mkdir -p "$(DESTDIR)$(LIBDIR)" "$(DESTDIR)$(INCLUDEDIR)" "$(DESTDIR)$(BINDIR)"
	cp $(LIBRARY) "$(DESTDIR)$(LIBDIR)/"
	cp $(PUBLIC_HEADERS) "$(DESTDIR)$(INCLUDEDIR)/"
	cp w2c2$(SUFFIX) "$(DESTDIR)$(BINDIR)/"

.PHONY: clean
clean:
	-rm -f *.o libw2c2.a libw2c2.so libw2c2.dylib
	-rm -f w2c2$(SUFFIX) w2c2_test$(SUFFIX) w2c2_embed$(SUFFIX) w2c2_embedding_test$(SUFFIX)
