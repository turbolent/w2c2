CFLAGS += -I../../w2c2
LDFLAGS += -lm -L../../wasi -lw2c2wasi
W2C2 ?= ../../w2c2/w2c2

MODE ?= gnu-ld

ifneq (,$(findstring sectcreate,$(MODE)))
	LDFLAGS += -sectcreate __DATA m4_llvm m4_llvm.data
endif
ifeq ($(MODE),gnu-ld)
    OBJS += m4_llvm.data.o
endif

sys/bin/llvm: llvm.o
	$(MAKE) -f Submake CC="$(CC)" CFLAGS="$(CFLAGS)" LDFLAGS="$(LDFLAGS)" OBJS="$(OBJS)"

llvm.c: llvm.wasm
	$(W2C2) -d $(MODE) -f 100 $^ $@

.PHONY: clean
clean:
	rm -f sys/bin/llvm llvm.h m4_llvm.data $(filter-out main.c,$(wildcard *.c)) *.o
