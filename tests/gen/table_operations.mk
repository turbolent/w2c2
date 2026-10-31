run-tests: run-test-table_operations_checked
test_table_operations$(EXE) test_table_operations_checked$(EXE): CFLAGS += -std=c89
test_table_operations$(EXE) test_table_operations_checked$(EXE): gen/assert_table_operations.c main.c test_table_operations.0.c test_table_operations.1.c test_table_operations.2.c test_table_operations.3.c test_table_operations.4.c test_table_operations.5.c test_table_operations.6.c test_table_operations.7.c test_table_operations.8.c test_table_operations.9.c
test_table_operations$(EXE):
	$(CC) $(CFLAGS) -I. $^ -o $@ $(LDFLAGS)
test_table_operations_checked$(EXE):
	$(CC) $(CFLAGS) -DW2C2_RUNTIME_CHECKS=1 -I. $^ -o $@ $(LDFLAGS)
test_table_operations.0.c: gen/table_operations.0.wasm
	$(W2C2) -m $< $@
test_table_operations.1.c: gen/table_operations.1.wasm
	$(W2C2) -m $< $@
test_table_operations.2.c: gen/table_operations.2.wasm
	$(W2C2) -m $< $@
test_table_operations.3.c: gen/table_operations.3.wasm
	$(W2C2) -m $< $@
test_table_operations.4.c: gen/table_operations.4.wasm
	$(W2C2) -m $< $@
test_table_operations.5.c: gen/table_operations.5.wasm
	$(W2C2) -m $< $@
test_table_operations.6.c: gen/table_operations.6.wasm
	$(W2C2) -m $< $@
test_table_operations.7.c: gen/table_operations.7.wasm
	$(W2C2) -m $< $@
test_table_operations.8.c: gen/table_operations.8.wasm
	$(W2C2) -m $< $@
test_table_operations.9.c: gen/table_operations.9.wasm
	$(W2C2) -m $< $@
