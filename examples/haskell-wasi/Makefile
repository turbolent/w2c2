CFLAGS += -I../../w2c2 -O0 -g
LDFLAGS += -lm -L../../wasi -lw2c2wasi
W2C2 ?= ../../w2c2/w2c2
GHC ?= wasm32-wasi-ghc
GHCFLAGS ?= -O2

MODE ?= gnu-ld

ifneq (,$(findstring sectcreate,$(MODE)))
	LDFLAGS += -sectcreate __DATA m11_haskellwasi m11_haskellwasi.data
endif
ifeq ($(MODE),gnu-ld)
    OBJS += m11_haskellwasi.data.o
endif

.PHONY: haskell-wasi
haskell-wasi: haskellwasi.c
	$(MAKE) -f Submake CC="$(CC)" CFLAGS="$(CFLAGS)" LDFLAGS="$(LDFLAGS)" OBJS="$(OBJS)"

haskellwasi.c: haskellwasi.wasm
	$(W2C2) -d $(MODE) -f 100 $< $@

haskellwasi.wasm: src/Main.hs
	$(GHC) $(GHCFLAGS) -o $@ $<

.PHONY: clean
clean:
	rm -f haskell-wasi haskellwasi.wasm haskellwasi.h m11_haskellwasi.data $(filter-out main.c,$(wildcard *.c)) *.o src/*.o src/*.hi
