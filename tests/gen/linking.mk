run-tests: run-test-linking_checked
test_linking$(EXE) test_linking_checked$(EXE): CFLAGS += -std=c89
test_linking$(EXE) test_linking_checked$(EXE): gen/assert_linking.c main.c test_linking.0.c test_linking.1.c test_linking.2.c test_linking.5.c test_linking.6.c test_linking.9.c test_linking.10.c test_linking.11.c test_linking.12.c test_linking.13.c test_linking.14.c test_linking.15.c test_linking.16.c test_linking.18.c test_linking.19.c test_linking.20.c test_linking.21.c test_linking.22.c test_linking.23.c test_linking.24.c test_linking.26.c
test_linking$(EXE):
	$(CC) $(CFLAGS) -I. $^ -o $@ $(LDFLAGS)
test_linking_checked$(EXE):
	$(CC) $(CFLAGS) -DW2C2_RUNTIME_CHECKS=1 -I. $^ -o $@ $(LDFLAGS)
test_linking.0.c: gen/linking.0.wasm
	$(W2C2) -m $< $@
test_linking.1.c: gen/linking.1.wasm
	$(W2C2) -m $< $@
test_linking.2.c: gen/linking.2.wasm
	$(W2C2) -m $< $@
test_linking.5.c: gen/linking.5.wasm
	$(W2C2) -m $< $@
test_linking.6.c: gen/linking.6.wasm
	$(W2C2) -m $< $@
test_linking.9.c: gen/linking.9.wasm
	$(W2C2) -m $< $@
test_linking.10.c: gen/linking.10.wasm
	$(W2C2) -m $< $@
test_linking.11.c: gen/linking.11.wasm
	$(W2C2) -m $< $@
test_linking.12.c: gen/linking.12.wasm
	$(W2C2) -m $< $@
test_linking.13.c: gen/linking.13.wasm
	$(W2C2) -m $< $@
test_linking.14.c: gen/linking.14.wasm
	$(W2C2) -m $< $@
test_linking.15.c: gen/linking.15.wasm
	$(W2C2) -m $< $@
test_linking.16.c: gen/linking.16.wasm
	$(W2C2) -m $< $@
test_linking.18.c: gen/linking.18.wasm
	$(W2C2) -m $< $@
test_linking.19.c: gen/linking.19.wasm
	$(W2C2) -m $< $@
test_linking.20.c: gen/linking.20.wasm
	$(W2C2) -m $< $@
test_linking.21.c: gen/linking.21.wasm
	$(W2C2) -m $< $@
test_linking.22.c: gen/linking.22.wasm
	$(W2C2) -m $< $@
test_linking.23.c: gen/linking.23.wasm
	$(W2C2) -m $< $@
test_linking.24.c: gen/linking.24.wasm
	$(W2C2) -m $< $@
test_linking.26.c: gen/linking.26.wasm
	$(W2C2) -m $< $@
