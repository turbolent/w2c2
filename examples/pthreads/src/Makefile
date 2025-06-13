CC = ${WASI_SDK_PATH}/bin/clang

pthreads.wasm: main.c
	$(CC) --target=wasm32-wasi-threads --sysroot ${WASI_SDK_PATH}/share/wasi-sysroot -O0 -g -pthread -Wl,--import-memory,--export-memory,--max-memory=67108864 -o $@ $<

.PHONY:
clean:
	rm pthreads.wasm
