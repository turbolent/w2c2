CC = ${WASI_SDK_PATH}/bin/clang

CFLAGS += "--target=wasm32-unknown-wasi --sysroot ${WASI_SDK_PATH}/share/wasi-sysroot -O2"

ls.wasm: main.o

.PHONY:
clean:
	rm ls.wasm
