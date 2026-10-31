run-tests: run-test-global_checked
test_global$(EXE) test_global_checked$(EXE): CFLAGS += -std=c89
test_global$(EXE) test_global_checked$(EXE): gen/assert_global.c main.c test_global.0.c test_global.3.c test_global.4.c test_global.18.c test_global.19.c test_global.23.c test_global.26.c test_global.49.c test_global.50.c
test_global$(EXE):
	$(CC) $(CFLAGS) -I. $^ -o $@ $(LDFLAGS)
test_global_checked$(EXE):
	$(CC) $(CFLAGS) -DW2C2_RUNTIME_CHECKS=1 -I. $^ -o $@ $(LDFLAGS)
test_global.0.c: gen/global.0.wasm
	$(W2C2) -m $< $@
test_global.3.c: gen/global.3.wasm
	$(W2C2) -m $< $@
test_global.4.c: gen/global.4.wasm
	$(W2C2) -m $< $@
test_global.18.c: gen/global.18.wasm
	$(W2C2) -m $< $@
test_global.19.c: gen/global.19.wasm
	$(W2C2) -m $< $@
test_global.23.c: gen/global.23.wasm
	$(W2C2) -m $< $@
test_global.26.c: gen/global.26.wasm
	$(W2C2) -m $< $@
test_global.49.c: gen/global.49.wasm
	$(W2C2) -m $< $@
test_global.50.c: gen/global.50.wasm
	$(W2C2) -m $< $@
