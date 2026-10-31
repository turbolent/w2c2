run-tests: run-test-elem_checked
test_elem$(EXE) test_elem_checked$(EXE): CFLAGS += -std=c89
test_elem$(EXE) test_elem_checked$(EXE): gen/assert_elem.c main.c test_elem.0.c test_elem.1.c test_elem.2.c test_elem.3.c test_elem.4.c test_elem.5.c test_elem.6.c test_elem.7.c test_elem.8.c test_elem.9.c test_elem.10.c test_elem.11.c test_elem.12.c test_elem.13.c test_elem.14.c test_elem.15.c test_elem.16.c test_elem.17.c test_elem.18.c test_elem.19.c test_elem.20.c test_elem.21.c test_elem.22.c test_elem.23.c test_elem.24.c test_elem.25.c test_elem.26.c test_elem.27.c test_elem.28.c test_elem.29.c test_elem.30.c test_elem.31.c test_elem.32.c test_elem.33.c test_elem.34.c test_elem.35.c test_elem.36.c test_elem.37.c test_elem.38.c test_elem.39.c test_elem.40.c test_elem.41.c test_elem.42.c test_elem.43.c test_elem.44.c test_elem.57.c test_elem.58.c test_elem.79.c test_elem.80.c test_elem.81.c test_elem.82.c test_elem.83.c test_elem.88.c test_elem.89.c test_elem.90.c test_elem.91.c test_elem.92.c test_elem.93.c test_elem.94.c test_elem.95.c test_elem.96.c
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
test_elem.10.c: gen/elem.10.wasm
	$(W2C2) -m $< $@
test_elem.11.c: gen/elem.11.wasm
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
test_elem.22.c: gen/elem.22.wasm
	$(W2C2) -m $< $@
test_elem.23.c: gen/elem.23.wasm
	$(W2C2) -m $< $@
test_elem.24.c: gen/elem.24.wasm
	$(W2C2) -m $< $@
test_elem.25.c: gen/elem.25.wasm
	$(W2C2) -m $< $@
test_elem.26.c: gen/elem.26.wasm
	$(W2C2) -m $< $@
test_elem.27.c: gen/elem.27.wasm
	$(W2C2) -m $< $@
test_elem.28.c: gen/elem.28.wasm
	$(W2C2) -m $< $@
test_elem.29.c: gen/elem.29.wasm
	$(W2C2) -m $< $@
test_elem.30.c: gen/elem.30.wasm
	$(W2C2) -m $< $@
test_elem.31.c: gen/elem.31.wasm
	$(W2C2) -m $< $@
test_elem.32.c: gen/elem.32.wasm
	$(W2C2) -m $< $@
test_elem.33.c: gen/elem.33.wasm
	$(W2C2) -m $< $@
test_elem.34.c: gen/elem.34.wasm
	$(W2C2) -m $< $@
test_elem.35.c: gen/elem.35.wasm
	$(W2C2) -m $< $@
test_elem.36.c: gen/elem.36.wasm
	$(W2C2) -m $< $@
test_elem.37.c: gen/elem.37.wasm
	$(W2C2) -m $< $@
test_elem.38.c: gen/elem.38.wasm
	$(W2C2) -m $< $@
test_elem.39.c: gen/elem.39.wasm
	$(W2C2) -m $< $@
test_elem.40.c: gen/elem.40.wasm
	$(W2C2) -m $< $@
test_elem.41.c: gen/elem.41.wasm
	$(W2C2) -m $< $@
test_elem.42.c: gen/elem.42.wasm
	$(W2C2) -m $< $@
test_elem.43.c: gen/elem.43.wasm
	$(W2C2) -m $< $@
test_elem.44.c: gen/elem.44.wasm
	$(W2C2) -m $< $@
test_elem.57.c: gen/elem.57.wasm
	$(W2C2) -m $< $@
test_elem.58.c: gen/elem.58.wasm
	$(W2C2) -m $< $@
test_elem.79.c: gen/elem.79.wasm
	$(W2C2) -m $< $@
test_elem.80.c: gen/elem.80.wasm
	$(W2C2) -m $< $@
test_elem.81.c: gen/elem.81.wasm
	$(W2C2) -m $< $@
test_elem.82.c: gen/elem.82.wasm
	$(W2C2) -m $< $@
test_elem.83.c: gen/elem.83.wasm
	$(W2C2) -m $< $@
test_elem.88.c: gen/elem.88.wasm
	$(W2C2) -m $< $@
test_elem.89.c: gen/elem.89.wasm
	$(W2C2) -m $< $@
test_elem.90.c: gen/elem.90.wasm
	$(W2C2) -m $< $@
test_elem.91.c: gen/elem.91.wasm
	$(W2C2) -m $< $@
test_elem.92.c: gen/elem.92.wasm
	$(W2C2) -m $< $@
test_elem.93.c: gen/elem.93.wasm
	$(W2C2) -m $< $@
test_elem.94.c: gen/elem.94.wasm
	$(W2C2) -m $< $@
test_elem.95.c: gen/elem.95.wasm
	$(W2C2) -m $< $@
test_elem.96.c: gen/elem.96.wasm
	$(W2C2) -m $< $@
