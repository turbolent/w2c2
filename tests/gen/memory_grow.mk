test_memory_grow$(EXE) test_memory_grow_checked$(EXE): CFLAGS += -std=c89
test_memory_grow$(EXE) test_memory_grow_checked$(EXE): gen/assert_memory_grow.c main.c test_memory_grow.0.c test_memory_grow.1.c test_memory_grow.2.c test_memory_grow.3.c test_memory_grow.4.c test_memory_grow.5.c $(TEST_HEADERS)
test_memory_grow$(EXE):
	$(CC) $(CFLAGS) -I. $(filter %.c,$^) -o $@ $(FUTEX_LDFLAGS) $(LDFLAGS)
test_memory_grow_checked$(EXE): $(CHECKED_FUTEX_OBJECTS)
	$(CC) $(CFLAGS) -DW2C2_RUNTIME_CHECKS=1 -I. $(filter %.c %.o,$^) -o $@ $(LDFLAGS)
test_memory_grow.0.c: gen/memory_grow.0.wasm
	$(W2C2) -m $< $@
test_memory_grow.1.c: gen/memory_grow.1.wasm
	$(W2C2) -m $< $@
test_memory_grow.2.c: gen/memory_grow.2.wasm
	$(W2C2) -m $< $@
test_memory_grow.3.c: gen/memory_grow.3.wasm
	$(W2C2) -m $< $@
test_memory_grow.4.c: gen/memory_grow.4.wasm
	$(W2C2) -m $< $@
test_memory_grow.5.c: gen/memory_grow.5.wasm
	$(W2C2) -m $< $@
