CC = ${WASI_SDK_PATH}/bin/clang

threads.wasm: main.c wasi_thread_spawn.S
	$(CC) --target=wasm32-wasi-threads --sysroot ${WASI_SDK_PATH}/share/wasi-sysroot -O0 -g -pthread -o $@ $^

.PHONY:
clean:
	rm threads.wasm
