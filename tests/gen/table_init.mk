run-tests: run-test-table_init_checked
test_table_init$(EXE) test_table_init_checked$(EXE): CFLAGS += -std=c89
test_table_init$(EXE) test_table_init_checked$(EXE): gen/assert_table_init.c main.c test_table_init.0.c test_table_init.1.c test_table_init.2.c test_table_init.3.c test_table_init.4.c test_table_init.5.c test_table_init.6.c test_table_init.11.c test_table_init.12.c test_table_init.13.c test_table_init.14.c test_table_init.15.c test_table_init.16.c test_table_init.17.c test_table_init.18.c test_table_init.19.c test_table_init.20.c test_table_init.21.c test_table_init.22.c test_table_init.23.c test_table_init.24.c test_table_init.25.c test_table_init.26.c test_table_init.27.c test_table_init.28.c test_table_init.29.c test_table_init.30.c test_table_init.31.c test_table_init.32.c test_table_init.33.c test_table_init.34.c test_table_init.35.c test_table_init.36.c test_table_init.100.c test_table_init.101.c test_table_init.102.c test_table_init.103.c test_table_init.104.c test_table_init.105.c test_table_init.106.c
test_table_init$(EXE):
	$(CC) $(CFLAGS) -I. $^ -o $@ $(LDFLAGS)
test_table_init_checked$(EXE):
	$(CC) $(CFLAGS) -DW2C2_RUNTIME_CHECKS=1 -I. $^ -o $@ $(LDFLAGS)
test_table_init.0.c: gen/table_init.0.wasm
	$(W2C2) -m $< $@
test_table_init.1.c: gen/table_init.1.wasm
	$(W2C2) -m $< $@
test_table_init.2.c: gen/table_init.2.wasm
	$(W2C2) -m $< $@
test_table_init.3.c: gen/table_init.3.wasm
	$(W2C2) -m $< $@
test_table_init.4.c: gen/table_init.4.wasm
	$(W2C2) -m $< $@
test_table_init.5.c: gen/table_init.5.wasm
	$(W2C2) -m $< $@
test_table_init.6.c: gen/table_init.6.wasm
	$(W2C2) -m $< $@
test_table_init.11.c: gen/table_init.11.wasm
	$(W2C2) -m $< $@
test_table_init.12.c: gen/table_init.12.wasm
	$(W2C2) -m $< $@
test_table_init.13.c: gen/table_init.13.wasm
	$(W2C2) -m $< $@
test_table_init.14.c: gen/table_init.14.wasm
	$(W2C2) -m $< $@
test_table_init.15.c: gen/table_init.15.wasm
	$(W2C2) -m $< $@
test_table_init.16.c: gen/table_init.16.wasm
	$(W2C2) -m $< $@
test_table_init.17.c: gen/table_init.17.wasm
	$(W2C2) -m $< $@
test_table_init.18.c: gen/table_init.18.wasm
	$(W2C2) -m $< $@
test_table_init.19.c: gen/table_init.19.wasm
	$(W2C2) -m $< $@
test_table_init.20.c: gen/table_init.20.wasm
	$(W2C2) -m $< $@
test_table_init.21.c: gen/table_init.21.wasm
	$(W2C2) -m $< $@
test_table_init.22.c: gen/table_init.22.wasm
	$(W2C2) -m $< $@
test_table_init.23.c: gen/table_init.23.wasm
	$(W2C2) -m $< $@
test_table_init.24.c: gen/table_init.24.wasm
	$(W2C2) -m $< $@
test_table_init.25.c: gen/table_init.25.wasm
	$(W2C2) -m $< $@
test_table_init.26.c: gen/table_init.26.wasm
	$(W2C2) -m $< $@
test_table_init.27.c: gen/table_init.27.wasm
	$(W2C2) -m $< $@
test_table_init.28.c: gen/table_init.28.wasm
	$(W2C2) -m $< $@
test_table_init.29.c: gen/table_init.29.wasm
	$(W2C2) -m $< $@
test_table_init.30.c: gen/table_init.30.wasm
	$(W2C2) -m $< $@
test_table_init.31.c: gen/table_init.31.wasm
	$(W2C2) -m $< $@
test_table_init.32.c: gen/table_init.32.wasm
	$(W2C2) -m $< $@
test_table_init.33.c: gen/table_init.33.wasm
	$(W2C2) -m $< $@
test_table_init.34.c: gen/table_init.34.wasm
	$(W2C2) -m $< $@
test_table_init.35.c: gen/table_init.35.wasm
	$(W2C2) -m $< $@
test_table_init.36.c: gen/table_init.36.wasm
	$(W2C2) -m $< $@
test_table_init.100.c: gen/table_init.100.wasm
	$(W2C2) -m $< $@
test_table_init.101.c: gen/table_init.101.wasm
	$(W2C2) -m $< $@
test_table_init.102.c: gen/table_init.102.wasm
	$(W2C2) -m $< $@
test_table_init.103.c: gen/table_init.103.wasm
	$(W2C2) -m $< $@
test_table_init.104.c: gen/table_init.104.wasm
	$(W2C2) -m $< $@
test_table_init.105.c: gen/table_init.105.wasm
	$(W2C2) -m $< $@
test_table_init.106.c: gen/table_init.106.wasm
	$(W2C2) -m $< $@
