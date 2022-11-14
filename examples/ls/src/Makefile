CC = ${WASI_SDK_PATH}/bin/clang

ls.wasm: main.c
	$(CC) --target=wasm32-unknown-wasi --sysroot ${WASI_SDK_PATH}/share/wasi-sysroot -O2 -o $@ $<

.PHONY:
clean:
	rm ls.wasm
