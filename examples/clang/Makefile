CFLAGS += -I../../w2c2
LDFLAGS += -lm -L../../wasi -lw2c2wasi
W2C2 ?= ../../w2c2/w2c2

MODE ?= gnu-ld

ifneq (,$(findstring sectcreate,$(MODE)))
	LDFLAGS += -sectcreate __DATA __datasegments datasegments
endif
ifeq ($(MODE),gnu-ld)
    OBJS += datasegments.o
endif

sys/bin/llvm: llvm.o
	$(MAKE) -f Submake CC="$(CC)" CFLAGS="$(CFLAGS)" LDFLAGS="$(LDFLAGS)" OBJS="$(OBJS)"

llvm.c: llvm.wasm
	$(W2C2) -d $(MODE) -f 100 $^ $@

.PHONY: clean
clean:
	rm -f sys/bin/llvm llvm.h datasegments $(filter-out main.c,$(wildcard *.c)) *.o
