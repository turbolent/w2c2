CFLAGS += -I../../w2c2 -O0 -g
LDFLAGS += -lm -L../../wasi -lw2c2wasi
W2C2 ?= ../../w2c2/w2c2

MODE ?= gnu-ld

ifneq (,$(findstring sectcreate,$(MODE)))
	LDFLAGS += -sectcreate __DATA __datasegments datasegments
endif
ifeq ($(MODE),gnu-ld)
    OBJS += datasegments.o
endif

go-wasi: gowasi.o
	$(MAKE) -f Submake CC="$(CC)" CFLAGS="$(CFLAGS)" LDFLAGS="$(LDFLAGS)" OBJS="$(OBJS)"

gowasi.c: gowasi.wasm
	$(W2C2) -d $(MODE) -f 100 $^ $@

gowasi.wasm: src/main.go
	GOOS=wasip1 GOARCH=wasm go build -ldflags="-s -w" -o gowasi.wasm src/main.go

.PHONY: clean
clean:
	rm -f go-wasi gowasi.h datasegments $(filter-out main.c,$(wildcard *.c)) *.o
