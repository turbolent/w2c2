CFLAGS += -I../../w2c2 -O0 -g
LDFLAGS += -lm -L../../wasi -lw2c2wasi
W2C2 ?= ../../w2c2/w2c2

MODE ?= gnu-ld

ifneq (,$(findstring sectcreate,$(MODE)))
	LDFLAGS += -sectcreate __DATA m9_rustX2Dwasi m9_rustx2dwasi.data
endif
ifeq ($(MODE),gnu-ld)
    OBJS += m9_rustx2dwasi.data.o
endif

rust-wasi: rustwasi.o
	$(MAKE) -f Submake CC="$(CC)" CFLAGS="$(CFLAGS)" LDFLAGS="$(LDFLAGS)" OBJS="$(OBJS)"

rustwasi.c: target/wasm32-wasip1/debug/rust-wasi.wasm
	$(W2C2) -d $(MODE) -f 100 $^ $@


target/wasm32-wasip1/debug/rust-wasi.wasm: src/main.rs Cargo.toml Cargo.lock
	cargo build --locked --target wasm32-wasip1

.PHONY: clean
clean:
	rm -f rust-wasi rustwasi.h m9_rustx2dwasi.data $(filter-out main.c,$(wildcard *.c)) *.o
