run-tests: run-test-table_grow_checked
test_table_grow$(EXE) test_table_grow_checked$(EXE): CFLAGS += -std=c89
test_table_grow$(EXE) test_table_grow_checked$(EXE): gen/assert_table_grow.c main.c test_table_grow.0.c test_table_grow.1.c test_table_grow.2.c test_table_grow.3.c test_table_grow.4.c test_table_grow.5.c test_table_grow.6.c test_table_grow.7.c test_table_grow.15.c
test_table_grow$(EXE):
	$(CC) $(CFLAGS) -I. $^ -o $@ $(LDFLAGS)
test_table_grow_checked$(EXE):
	$(CC) $(CFLAGS) -DW2C2_RUNTIME_CHECKS=1 -I. $^ -o $@ $(LDFLAGS)
test_table_grow.0.c: gen/table_grow.0.wasm
	$(W2C2) -m $< $@
test_table_grow.1.c: gen/table_grow.1.wasm
	$(W2C2) -m $< $@
test_table_grow.2.c: gen/table_grow.2.wasm
	$(W2C2) -m $< $@
test_table_grow.3.c: gen/table_grow.3.wasm
	$(W2C2) -m $< $@
test_table_grow.4.c: gen/table_grow.4.wasm
	$(W2C2) -m $< $@
test_table_grow.5.c: gen/table_grow.5.wasm
	$(W2C2) -m $< $@
test_table_grow.6.c: gen/table_grow.6.wasm
	$(W2C2) -m $< $@
test_table_grow.7.c: gen/table_grow.7.wasm
	$(W2C2) -m $< $@
test_table_grow.15.c: gen/table_grow.15.wasm
	$(W2C2) -m $< $@
