test_ref_func$(EXE) test_ref_func_checked$(EXE): CFLAGS += -std=c89
test_ref_func$(EXE) test_ref_func_checked$(EXE): gen/assert_ref_func.c main.c test_ref_func.0.c test_ref_func.1.c test_ref_func.3.c $(TEST_HEADERS)
test_ref_func$(EXE):
	$(CC) $(CFLAGS) -I. $(filter %.c,$^) -o $@ $(FUTEX_LDFLAGS) $(LDFLAGS)
test_ref_func_checked$(EXE): $(CHECKED_FUTEX_OBJECTS)
	$(CC) $(CFLAGS) -DW2C2_RUNTIME_CHECKS=1 -I. $(filter %.c %.o,$^) -o $@ $(LDFLAGS)
test_ref_func.0.c: gen/ref_func.0.wasm
	$(W2C2) -m $< $@
test_ref_func.1.c: gen/ref_func.1.wasm
	$(W2C2) -m $< $@
test_ref_func.3.c: gen/ref_func.3.wasm
	$(W2C2) -m $< $@
