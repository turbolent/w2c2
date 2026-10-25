CFLAGS += -I../../w2c2 -O0 -g
LDFLAGS += -lm -L../../wasi -lw2c2wasi
W2C2 ?= ../../w2c2/w2c2

MODE ?= gnu-ld

ifneq (,$(findstring sectcreate,$(MODE)))
	LDFLAGS += -sectcreate __DATA m6_python m6_python.data
endif
ifeq ($(MODE),gnu-ld)
    OBJS += m6_python.data.o
endif

python: python.c
	$(MAKE) -fSubmake CC="$(CC)" CFLAGS="$(CFLAGS)" LDFLAGS="$(LDFLAGS)" OBJS="$(OBJS)"

python.c: python.wasm
	$(W2C2) -d $(MODE) -f 100 $^ $@

.PHONY: clean
clean:
	rm -f python python.h m6_python.data $(filter-out main.c,$(wildcard *.c)) *.o
