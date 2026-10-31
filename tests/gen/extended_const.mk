run-tests: run-test-extended_const_checked
test_extended_const$(EXE) test_extended_const_checked$(EXE): CFLAGS += -std=c89
test_extended_const$(EXE) test_extended_const_checked$(EXE): gen/assert_extended_const.c main.c test_extended_const.0.c test_extended_const.1.c test_extended_const.2.c
test_extended_const$(EXE):
	$(CC) $(CFLAGS) -I. $^ -o $@ $(LDFLAGS)
test_extended_const_checked$(EXE):
	$(CC) $(CFLAGS) -DW2C2_RUNTIME_CHECKS=1 -I. $^ -o $@ $(LDFLAGS)
test_extended_const.0.c: gen/extended_const.0.wasm
	$(W2C2) -m $< $@
test_extended_const.1.c: gen/extended_const.1.wasm
	$(W2C2) -m $< $@
test_extended_const.2.c: gen/extended_const.2.wasm
	$(W2C2) -m $< $@
