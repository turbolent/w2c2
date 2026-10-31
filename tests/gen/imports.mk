run-tests: run-test-imports_checked
test_imports$(EXE) test_imports_checked$(EXE): CFLAGS += -std=c89
test_imports$(EXE) test_imports_checked$(EXE): gen/assert_imports.c main.c test_imports.0.c test_imports.1.c test_imports.2.c test_imports.3.c test_imports.4.c test_imports.5.c test_imports.7.c test_imports.8.c test_imports.9.c test_imports.10.c test_imports.11.c test_imports.12.c test_imports.13.c test_imports.14.c test_imports.15.c test_imports.40.c test_imports.41.c test_imports.42.c test_imports.43.c test_imports.64.c test_imports.65.c test_imports.66.c test_imports.67.c test_imports.68.c test_imports.69.c test_imports.70.c test_imports.71.c test_imports.72.c test_imports.73.c test_imports.74.c test_imports.75.c test_imports.76.c test_imports.77.c test_imports.78.c test_imports.79.c test_imports.80.c test_imports.81.c test_imports.82.c test_imports.83.c test_imports.84.c test_imports.85.c test_imports.86.c test_imports.87.c test_imports.88.c test_imports.89.c test_imports.102.c test_imports.103.c test_imports.104.c test_imports.105.c test_imports.106.c test_imports.107.c test_imports.108.c test_imports.109.c test_imports.110.c test_imports.111.c test_imports.112.c test_imports.113.c test_imports.114.c test_imports.115.c test_imports.116.c test_imports.117.c test_imports.118.c test_imports.119.c test_imports.120.c test_imports.121.c test_imports.122.c test_imports.153.c test_imports.170.c
test_imports$(EXE):
	$(CC) $(CFLAGS) -I. $^ -o $@ $(LDFLAGS)
test_imports_checked$(EXE):
	$(CC) $(CFLAGS) -DW2C2_RUNTIME_CHECKS=1 -I. $^ -o $@ $(LDFLAGS)
test_imports.0.c: gen/imports.0.wasm
	$(W2C2) -m $< $@
test_imports.1.c: gen/imports.1.wasm
	$(W2C2) -m $< $@
test_imports.2.c: gen/imports.2.wasm
	$(W2C2) -m $< $@
test_imports.3.c: gen/imports.3.wasm
	$(W2C2) -m $< $@
test_imports.4.c: gen/imports.4.wasm
	$(W2C2) -m $< $@
test_imports.5.c: gen/imports.5.wasm
	$(W2C2) -m $< $@
test_imports.7.c: gen/imports.7.wasm
	$(W2C2) -m $< $@
test_imports.8.c: gen/imports.8.wasm
	$(W2C2) -m $< $@
test_imports.9.c: gen/imports.9.wasm
	$(W2C2) -m $< $@
test_imports.10.c: gen/imports.10.wasm
	$(W2C2) -m $< $@
test_imports.11.c: gen/imports.11.wasm
	$(W2C2) -m $< $@
test_imports.12.c: gen/imports.12.wasm
	$(W2C2) -m $< $@
test_imports.13.c: gen/imports.13.wasm
	$(W2C2) -m $< $@
test_imports.14.c: gen/imports.14.wasm
	$(W2C2) -m $< $@
test_imports.15.c: gen/imports.15.wasm
	$(W2C2) -m $< $@
test_imports.40.c: gen/imports.40.wasm
	$(W2C2) -m $< $@
test_imports.41.c: gen/imports.41.wasm
	$(W2C2) -m $< $@
test_imports.42.c: gen/imports.42.wasm
	$(W2C2) -m $< $@
test_imports.43.c: gen/imports.43.wasm
	$(W2C2) -m $< $@
test_imports.64.c: gen/imports.64.wasm
	$(W2C2) -m $< $@
test_imports.65.c: gen/imports.65.wasm
	$(W2C2) -m $< $@
test_imports.66.c: gen/imports.66.wasm
	$(W2C2) -m $< $@
test_imports.67.c: gen/imports.67.wasm
	$(W2C2) -m $< $@
test_imports.68.c: gen/imports.68.wasm
	$(W2C2) -m $< $@
test_imports.69.c: gen/imports.69.wasm
	$(W2C2) -m $< $@
test_imports.70.c: gen/imports.70.wasm
	$(W2C2) -m $< $@
test_imports.71.c: gen/imports.71.wasm
	$(W2C2) -m $< $@
test_imports.72.c: gen/imports.72.wasm
	$(W2C2) -m $< $@
test_imports.73.c: gen/imports.73.wasm
	$(W2C2) -m $< $@
test_imports.74.c: gen/imports.74.wasm
	$(W2C2) -m $< $@
test_imports.75.c: gen/imports.75.wasm
	$(W2C2) -m $< $@
test_imports.76.c: gen/imports.76.wasm
	$(W2C2) -m $< $@
test_imports.77.c: gen/imports.77.wasm
	$(W2C2) -m $< $@
test_imports.78.c: gen/imports.78.wasm
	$(W2C2) -m $< $@
test_imports.79.c: gen/imports.79.wasm
	$(W2C2) -m $< $@
test_imports.80.c: gen/imports.80.wasm
	$(W2C2) -m $< $@
test_imports.81.c: gen/imports.81.wasm
	$(W2C2) -m $< $@
test_imports.82.c: gen/imports.82.wasm
	$(W2C2) -m $< $@
test_imports.83.c: gen/imports.83.wasm
	$(W2C2) -m $< $@
test_imports.84.c: gen/imports.84.wasm
	$(W2C2) -m $< $@
test_imports.85.c: gen/imports.85.wasm
	$(W2C2) -m $< $@
test_imports.86.c: gen/imports.86.wasm
	$(W2C2) -m $< $@
test_imports.87.c: gen/imports.87.wasm
	$(W2C2) -m $< $@
test_imports.88.c: gen/imports.88.wasm
	$(W2C2) -m $< $@
test_imports.89.c: gen/imports.89.wasm
	$(W2C2) -m $< $@
test_imports.102.c: gen/imports.102.wasm
	$(W2C2) -m $< $@
test_imports.103.c: gen/imports.103.wasm
	$(W2C2) -m $< $@
test_imports.104.c: gen/imports.104.wasm
	$(W2C2) -m $< $@
test_imports.105.c: gen/imports.105.wasm
	$(W2C2) -m $< $@
test_imports.106.c: gen/imports.106.wasm
	$(W2C2) -m $< $@
test_imports.107.c: gen/imports.107.wasm
	$(W2C2) -m $< $@
test_imports.108.c: gen/imports.108.wasm
	$(W2C2) -m $< $@
test_imports.109.c: gen/imports.109.wasm
	$(W2C2) -m $< $@
test_imports.110.c: gen/imports.110.wasm
	$(W2C2) -m $< $@
test_imports.111.c: gen/imports.111.wasm
	$(W2C2) -m $< $@
test_imports.112.c: gen/imports.112.wasm
	$(W2C2) -m $< $@
test_imports.113.c: gen/imports.113.wasm
	$(W2C2) -m $< $@
test_imports.114.c: gen/imports.114.wasm
	$(W2C2) -m $< $@
test_imports.115.c: gen/imports.115.wasm
	$(W2C2) -m $< $@
test_imports.116.c: gen/imports.116.wasm
	$(W2C2) -m $< $@
test_imports.117.c: gen/imports.117.wasm
	$(W2C2) -m $< $@
test_imports.118.c: gen/imports.118.wasm
	$(W2C2) -m $< $@
test_imports.119.c: gen/imports.119.wasm
	$(W2C2) -m $< $@
test_imports.120.c: gen/imports.120.wasm
	$(W2C2) -m $< $@
test_imports.121.c: gen/imports.121.wasm
	$(W2C2) -m $< $@
test_imports.122.c: gen/imports.122.wasm
	$(W2C2) -m $< $@
test_imports.153.c: gen/imports.153.wasm
	$(W2C2) -m $< $@
test_imports.170.c: gen/imports.170.wasm
	$(W2C2) -m $< $@
