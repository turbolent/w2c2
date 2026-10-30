run-tests: run-test-table_copy_checked
test_table_copy$(EXE) test_table_copy_checked$(EXE): CFLAGS += -std=c89
test_table_copy$(EXE) test_table_copy_checked$(EXE): gen/assert_table_copy.c main.c test_table_copy.0.c test_table_copy.1.c test_table_copy.2.c test_table_copy.3.c test_table_copy.4.c test_table_copy.5.c test_table_copy.6.c test_table_copy.7.c test_table_copy.8.c test_table_copy.9.c test_table_copy.10.c test_table_copy.11.c test_table_copy.12.c test_table_copy.13.c test_table_copy.14.c test_table_copy.15.c test_table_copy.16.c test_table_copy.17.c test_table_copy.18.c test_table_copy.19.c test_table_copy.20.c test_table_copy.21.c test_table_copy.22.c test_table_copy.23.c test_table_copy.24.c test_table_copy.25.c test_table_copy.26.c test_table_copy.27.c test_table_copy.28.c test_table_copy.29.c test_table_copy.30.c test_table_copy.31.c test_table_copy.32.c test_table_copy.33.c test_table_copy.34.c test_table_copy.35.c test_table_copy.36.c test_table_copy.37.c test_table_copy.38.c test_table_copy.39.c test_table_copy.40.c test_table_copy.41.c test_table_copy.42.c test_table_copy.43.c test_table_copy.44.c test_table_copy.45.c test_table_copy.46.c test_table_copy.47.c test_table_copy.48.c test_table_copy.49.c test_table_copy.50.c test_table_copy.51.c
test_table_copy$(EXE):
	$(CC) $(CFLAGS) -I. $^ -o $@ $(LDFLAGS)
test_table_copy_checked$(EXE):
	$(CC) $(CFLAGS) -DW2C2_RUNTIME_CHECKS=1 -I. $^ -o $@ $(LDFLAGS)
test_table_copy.0.c: gen/table_copy.0.wasm
	$(W2C2) -m $< $@
test_table_copy.1.c: gen/table_copy.1.wasm
	$(W2C2) -m $< $@
test_table_copy.2.c: gen/table_copy.2.wasm
	$(W2C2) -m $< $@
test_table_copy.3.c: gen/table_copy.3.wasm
	$(W2C2) -m $< $@
test_table_copy.4.c: gen/table_copy.4.wasm
	$(W2C2) -m $< $@
test_table_copy.5.c: gen/table_copy.5.wasm
	$(W2C2) -m $< $@
test_table_copy.6.c: gen/table_copy.6.wasm
	$(W2C2) -m $< $@
test_table_copy.7.c: gen/table_copy.7.wasm
	$(W2C2) -m $< $@
test_table_copy.8.c: gen/table_copy.8.wasm
	$(W2C2) -m $< $@
test_table_copy.9.c: gen/table_copy.9.wasm
	$(W2C2) -m $< $@
test_table_copy.10.c: gen/table_copy.10.wasm
	$(W2C2) -m $< $@
test_table_copy.11.c: gen/table_copy.11.wasm
	$(W2C2) -m $< $@
test_table_copy.12.c: gen/table_copy.12.wasm
	$(W2C2) -m $< $@
test_table_copy.13.c: gen/table_copy.13.wasm
	$(W2C2) -m $< $@
test_table_copy.14.c: gen/table_copy.14.wasm
	$(W2C2) -m $< $@
test_table_copy.15.c: gen/table_copy.15.wasm
	$(W2C2) -m $< $@
test_table_copy.16.c: gen/table_copy.16.wasm
	$(W2C2) -m $< $@
test_table_copy.17.c: gen/table_copy.17.wasm
	$(W2C2) -m $< $@
test_table_copy.18.c: gen/table_copy.18.wasm
	$(W2C2) -m $< $@
test_table_copy.19.c: gen/table_copy.19.wasm
	$(W2C2) -m $< $@
test_table_copy.20.c: gen/table_copy.20.wasm
	$(W2C2) -m $< $@
test_table_copy.21.c: gen/table_copy.21.wasm
	$(W2C2) -m $< $@
test_table_copy.22.c: gen/table_copy.22.wasm
	$(W2C2) -m $< $@
test_table_copy.23.c: gen/table_copy.23.wasm
	$(W2C2) -m $< $@
test_table_copy.24.c: gen/table_copy.24.wasm
	$(W2C2) -m $< $@
test_table_copy.25.c: gen/table_copy.25.wasm
	$(W2C2) -m $< $@
test_table_copy.26.c: gen/table_copy.26.wasm
	$(W2C2) -m $< $@
test_table_copy.27.c: gen/table_copy.27.wasm
	$(W2C2) -m $< $@
test_table_copy.28.c: gen/table_copy.28.wasm
	$(W2C2) -m $< $@
test_table_copy.29.c: gen/table_copy.29.wasm
	$(W2C2) -m $< $@
test_table_copy.30.c: gen/table_copy.30.wasm
	$(W2C2) -m $< $@
test_table_copy.31.c: gen/table_copy.31.wasm
	$(W2C2) -m $< $@
test_table_copy.32.c: gen/table_copy.32.wasm
	$(W2C2) -m $< $@
test_table_copy.33.c: gen/table_copy.33.wasm
	$(W2C2) -m $< $@
test_table_copy.34.c: gen/table_copy.34.wasm
	$(W2C2) -m $< $@
test_table_copy.35.c: gen/table_copy.35.wasm
	$(W2C2) -m $< $@
test_table_copy.36.c: gen/table_copy.36.wasm
	$(W2C2) -m $< $@
test_table_copy.37.c: gen/table_copy.37.wasm
	$(W2C2) -m $< $@
test_table_copy.38.c: gen/table_copy.38.wasm
	$(W2C2) -m $< $@
test_table_copy.39.c: gen/table_copy.39.wasm
	$(W2C2) -m $< $@
test_table_copy.40.c: gen/table_copy.40.wasm
	$(W2C2) -m $< $@
test_table_copy.41.c: gen/table_copy.41.wasm
	$(W2C2) -m $< $@
test_table_copy.42.c: gen/table_copy.42.wasm
	$(W2C2) -m $< $@
test_table_copy.43.c: gen/table_copy.43.wasm
	$(W2C2) -m $< $@
test_table_copy.44.c: gen/table_copy.44.wasm
	$(W2C2) -m $< $@
test_table_copy.45.c: gen/table_copy.45.wasm
	$(W2C2) -m $< $@
test_table_copy.46.c: gen/table_copy.46.wasm
	$(W2C2) -m $< $@
test_table_copy.47.c: gen/table_copy.47.wasm
	$(W2C2) -m $< $@
test_table_copy.48.c: gen/table_copy.48.wasm
	$(W2C2) -m $< $@
test_table_copy.49.c: gen/table_copy.49.wasm
	$(W2C2) -m $< $@
test_table_copy.50.c: gen/table_copy.50.wasm
	$(W2C2) -m $< $@
test_table_copy.51.c: gen/table_copy.51.wasm
	$(W2C2) -m $< $@
