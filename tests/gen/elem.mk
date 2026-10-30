run-tests: run-test-elem_checked
test_elem$(EXE) test_elem_checked$(EXE): CFLAGS += -std=c89
test_elem$(EXE) test_elem_checked$(EXE): gen/assert_elem.c main.c test_elem.0.c test_elem.1.c test_elem.2.c test_elem.3.c test_elem.4.c test_elem.5.c test_elem.6.c test_elem.7.c test_elem.8.c test_elem.9.c test_elem.12.c test_elem.13.c test_elem.14.c test_elem.15.c test_elem.16.c test_elem.17.c test_elem.18.c test_elem.19.c test_elem.20.c test_elem.21.c test_elem.34.c test_elem.35.c test_elem.56.c test_elem.57.c test_elem.58.c test_elem.59.c test_elem.60.c test_elem.61.c test_elem.62.c
test_elem$(EXE):
	$(CC) $(CFLAGS) -I. $^ -o $@ $(LDFLAGS)
test_elem_checked$(EXE):
	$(CC) $(CFLAGS) -DW2C2_RUNTIME_CHECKS=1 -I. $^ -o $@ $(LDFLAGS)
test_elem.0.c: gen/elem.0.wasm
	$(W2C2) -m $< $@
test_elem.1.c: gen/elem.1.wasm
	$(W2C2) -m $< $@
test_elem.2.c: gen/elem.2.wasm
	$(W2C2) -m $< $@
test_elem.3.c: gen/elem.3.wasm
	$(W2C2) -m $< $@
test_elem.4.c: gen/elem.4.wasm
	$(W2C2) -m $< $@
test_elem.5.c: gen/elem.5.wasm
	$(W2C2) -m $< $@
test_elem.6.c: gen/elem.6.wasm
	$(W2C2) -m $< $@
test_elem.7.c: gen/elem.7.wasm
	$(W2C2) -m $< $@
test_elem.8.c: gen/elem.8.wasm
	$(W2C2) -m $< $@
test_elem.9.c: gen/elem.9.wasm
	$(W2C2) -m $< $@
test_elem.12.c: gen/elem.12.wasm
	$(W2C2) -m $< $@
test_elem.13.c: gen/elem.13.wasm
	$(W2C2) -m $< $@
test_elem.14.c: gen/elem.14.wasm
	$(W2C2) -m $< $@
test_elem.15.c: gen/elem.15.wasm
	$(W2C2) -m $< $@
test_elem.16.c: gen/elem.16.wasm
	$(W2C2) -m $< $@
test_elem.17.c: gen/elem.17.wasm
	$(W2C2) -m $< $@
test_elem.18.c: gen/elem.18.wasm
	$(W2C2) -m $< $@
test_elem.19.c: gen/elem.19.wasm
	$(W2C2) -m $< $@
test_elem.20.c: gen/elem.20.wasm
	$(W2C2) -m $< $@
test_elem.21.c: gen/elem.21.wasm
	$(W2C2) -m $< $@
test_elem.34.c: gen/elem.34.wasm
	$(W2C2) -m $< $@
test_elem.35.c: gen/elem.35.wasm
	$(W2C2) -m $< $@
test_elem.56.c: gen/elem.56.wasm
	$(W2C2) -m $< $@
test_elem.57.c: gen/elem.57.wasm
	$(W2C2) -m $< $@
test_elem.58.c: gen/elem.58.wasm
	$(W2C2) -m $< $@
test_elem.59.c: gen/elem.59.wasm
	$(W2C2) -m $< $@
test_elem.60.c: gen/elem.60.wasm
	$(W2C2) -m $< $@
test_elem.61.c: gen/elem.61.wasm
	$(W2C2) -m $< $@
test_elem.62.c: gen/elem.62.wasm
	$(W2C2) -m $< $@
