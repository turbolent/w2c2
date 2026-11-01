W2C2 ?= ../w2c2/w2c2
PYTHON3 ?= python3

OPT ?= -O0
CFLAGS += -I../w2c2 $(OPT) -g

EXE =

ifeq ($(OS),Windows_NT)
	CFLAGS += -DWASM_THREADS_WIN32
else
	CFLAGS += -pthread -DWASM_THREADS_PTHREADS
	LDFLAGS += -lm
endif

LDFLAGS := -lw2c2futex -L../futex $(LDFLAGS)

ifneq (,$(findstring address,$(SANITIZERS)))
CFLAGS += -fsanitize=address -fno-omit-frame-pointer
endif

ifeq ($(TARGET),Wii)

ifeq ($(strip $(DEVKITPRO)),)
$(error "Please set DEVKITPRO in your environment")
endif

ifeq ($(strip $(DEVKITPPC)),)
$(error "Please set DEVKITPPC in your environment")
endif

include $(DEVKITPPC)/wii_rules

CFLAGS = $(MACHDEP)
LDFLAGS = $(MACHDEP) -L$(DEVKITPRO)/libogc/lib/wii -logc
EXE = .elf

DOLPHIN ?= dolphin
EXECUTE ?= $(DOLPHIN) -b -e

%.elf:

endif

.SILENT:

.PHONY: run-tests generator-test runtime-lifecycle-test table-instances-test atomic-offsets-test c-strings-test binary-names-test gen gen-atomic-offsets gen-c-strings gen-binary-names gen-table-instances clean clean-wasm-json clean-assertions clean-compiled
.PHONY: runtime-checks-test gen-runtime-checks

RUNTIME_CHECK_SOURCES = test_runtime_checks.c test_check_segments.c test_check_empty_segments.c

runtime-checks-test: run-test-runtime_checks run-test-runtime_checks_checked

test_runtime_checks$(EXE): runtime_checks_test.c $(RUNTIME_CHECK_SOURCES)
	$(CC) $(CFLAGS) $^ -o $@ $(filter-out -lw2c2futex -L../futex,$(LDFLAGS))

test_runtime_checks_checked$(EXE): runtime_checks_test.c $(RUNTIME_CHECK_SOURCES)
	$(CC) $(CFLAGS) -DW2C2_RUNTIME_CHECKS=1 $^ -o $@ $(filter-out -lw2c2futex -L../futex,$(LDFLAGS))

$(RUNTIME_CHECK_SOURCES): test_%.c: gen/%.wasm
	$(W2C2) -m $< $@

# Reuse the existing i386 test run for the Apple byte-order API regression.
ifeq ($(ARCH),i386)
run-tests: apple-byte-order-test
endif

.PHONY: apple-byte-order-test
apple-byte-order-test:
	$(CC) -std=c89 -Werror=conversion $(CFLAGS) -D__APPLE__ -DWASM_ENDIAN=WASM_BIG_ENDIAN -Iapple_byte_order -fsyntax-only ../w2c2/runtime_table_test.c

RUNTIME_LIFECYCLE_SOURCES = \
	test_runtime_lifecycle_owned.c \
	test_runtime_lifecycle_shared.c \
	test_runtime_lifecycle_imports.c
RUNTIME_LIFECYCLE_LDFLAGS = $(filter-out -lw2c2futex -L../futex,$(LDFLAGS))

runtime-lifecycle-test: run-test-runtime_lifecycle run-test-runtime_lifecycle_checked

test_runtime_lifecycle$(EXE): runtime_lifecycle_test.c $(RUNTIME_LIFECYCLE_SOURCES)
	$(CC) $(CFLAGS) $^ -o $@ $(RUNTIME_LIFECYCLE_LDFLAGS)

test_runtime_lifecycle_checked$(EXE): runtime_lifecycle_test.c $(RUNTIME_LIFECYCLE_SOURCES)
	$(CC) $(CFLAGS) -DW2C2_RUNTIME_CHECKS=1 $^ -o $@ $(RUNTIME_LIFECYCLE_LDFLAGS)

test_runtime_lifecycle_owned.c: gen/runtime_lifecycle.0.wasm
	$(W2C2) -m $< $@

test_runtime_lifecycle_shared.c: gen/runtime_lifecycle.1.wasm
	$(W2C2) -m $< $@

test_runtime_lifecycle_imports.c: gen/runtime_lifecycle.2.wasm
	$(W2C2) -m $< $@

table-instances-test: run-test-table_instances run-test-table_instances_checked

test_table_instances$(EXE) test_table_instances_checked$(EXE): CFLAGS += -std=c89

test_table_instances$(EXE): table_instances_test.c test_table_owner.c test_table_caller.c
	$(CC) $(CFLAGS) $^ -o $@ $(filter-out -lw2c2futex -L../futex,$(LDFLAGS))

test_table_instances_checked$(EXE): table_instances_test.c test_table_owner.c test_table_caller.c
	$(CC) $(CFLAGS) -DW2C2_RUNTIME_CHECKS=1 $^ -o $@ $(filter-out -lw2c2futex -L../futex,$(LDFLAGS))

test_table_owner.c: gen/table_owner.wasm
	$(W2C2) -m $< $@

test_table_caller.c: gen/table_caller.wasm
	$(W2C2) -m $< $@

atomic-offsets-test: run-test-atomic_offsets

test_atomic_offsets$(EXE): atomic_offsets_test.c test_atomic_offsets.c
	$(CC) $(CFLAGS) $^ -o $@ $(filter-out -lw2c2futex -L../futex,$(LDFLAGS))

test_atomic_offsets.c: gen/atomic_offsets.wasm
	$(W2C2) $< $@

c-strings-test: run-test-c_strings

test_c_strings$(EXE): CFLAGS += -std=c89
test_c_strings$(EXE): c_strings_test.c test_c_strings.c
	$(CC) $(CFLAGS) $^ -o $@ $(filter-out -lw2c2futex -L../futex,$(LDFLAGS))

test_c_strings.c: gen/c_strings.wasm
	$(W2C2) -g $< $@

binary-names-test: run-test-binary_names

test_binary_names$(EXE): CFLAGS += -std=c89
test_binary_names$(EXE): binary_names_test.c test_binary_names.c
	$(CC) $(CFLAGS) $^ -o $@ $(filter-out -lw2c2futex -L../futex,$(LDFLAGS))

test_binary_names.c: gen/binary_names.wasm
	$(W2C2) $< $@

generator-test:
	$(PYTHON3) -m unittest gen_test

MULTIVALUE_SOURCES = test_multivalue_owner.c test_multivalue_caller.c

test_multivalue$(EXE) test_multivalue_checked$(EXE): CFLAGS += -std=c89

test_multivalue$(EXE): multivalue_test.c $(MULTIVALUE_SOURCES)
	$(CC) $(CFLAGS) $^ -o $@ $(filter-out -lw2c2futex -L../futex,$(LDFLAGS))

test_multivalue_checked$(EXE): multivalue_test.c $(MULTIVALUE_SOURCES)
	$(CC) $(CFLAGS) -DW2C2_RUNTIME_CHECKS=1 $^ -o $@ $(filter-out -lw2c2futex -L../futex,$(LDFLAGS))

$(MULTIVALUE_SOURCES): test_%.c: gen/%.wasm
	$(W2C2) -m $< $@

run-tests: generator-test atomic-offsets-test c-strings-test binary-names-test table-instances-test runtime-lifecycle-test runtime-checks-test run-test-multivalue run-test-multivalue_checked $(patsubst gen/assert_%.c,run-test-%,$(wildcard gen/assert_*.c))

-include $(wildcard gen/*.mk)

run-tests-%:
	$(MAKE) $(patsubst gen/assert_%.c,run-test-%,$(wildcard gen/assert_$**.c))

run-test-%: test_%$(EXE)
	echo ">>>" $<
	$(PYTHON3) run.py $(if $(EXECUTE),-e "$(EXECUTE)",) $(if $(ARCH),-a $(ARCH),) $<
	echo

test_%$(EXE): test_%.o main.o
	$(CC) $(CFLAGS) $< main.o -o $@ $(LDFLAGS)

test_%.c: gen/%.wasm
	echo "#include \"test.h\"" > $@
	$(W2C2) $< $@
	cat $(patsubst test_%.c,gen/assert_%.c,$@) >> $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

gen: gen-atomic-offsets gen-c-strings gen-binary-names gen-table-instances gen-runtime-checks gen-multivalue
	$(PYTHON3) gen.py $(filter-out simd_%.wast,$(wildcard *.wast))

gen-atomic-offsets:
	wat2wasm --enable-threads atomic_offsets.wat -o gen/atomic_offsets.wasm

gen-c-strings:
	wat2wasm --debug-names c_strings.wat -o gen/c_strings.wasm

gen-binary-names:
	wat2wasm binary_names.wat -o gen/binary_names.wasm

gen-table-instances:
	wat2wasm table_owner.wat -o gen/table_owner.wasm
	wat2wasm table_caller.wat -o gen/table_caller.wasm

gen-runtime-checks:
	wat2wasm --enable-threads runtime_checks.wat -o gen/runtime_checks.wasm
	wat2wasm check_segments.wat -o gen/check_segments.wasm
	wat2wasm check_empty_segments.wat -o gen/check_empty_segments.wasm

.PHONY: gen-multivalue
gen-multivalue:
	wat2wasm multivalue_owner.wat -o gen/multivalue_owner.wasm
	wat2wasm multivalue_caller.wat -o gen/multivalue_caller.wasm

gen-%:
	$(PYTHON3) gen.py $*

clean:
	-rm -f main.o test_*.o test_*.h
	-rm -f test_atomic_offsets$(EXE) test_atomic_offsets.c
	-rm -f test_c_strings$(EXE) test_c_strings.c
	-rm -f test_binary_names$(EXE) test_binary_names.c
	-rm -f test_runtime_lifecycle$(EXE) test_runtime_lifecycle_checked$(EXE) $(RUNTIME_LIFECYCLE_SOURCES)
	-rm -f $(RUNTIME_LIFECYCLE_SOURCES:.c=.h)
	-rm -f test_table_instances$(EXE) test_table_instances_checked$(EXE) test_table_owner.c test_table_caller.c
	-rm -f test_runtime_checks$(EXE) test_runtime_checks_checked$(EXE) $(RUNTIME_CHECK_SOURCES)
	-rm -f test_multivalue$(EXE) test_multivalue_checked$(EXE) $(MULTIVALUE_SOURCES)

SIMD_CFLAGS ?= -O2 -Werror=conversion -Werror=float-conversion
SIMD_SPEC_TESTS = $(filter-out simd_memory-multi.wast,$(wildcard simd_*.wast))

.PHONY: simd-test simd-regression-test simd-spec-test simd-benchmark
simd-test: simd-regression-test simd-spec-test

simd-regression-test:
	W2C2=$(W2C2) SIMD_CFLAGS="$(SIMD_CFLAGS)" $(PYTHON3) simd_test.py

simd-spec-test:
	$(PYTHON3) run.py --w2c2 $(W2C2) --cc "$(CC)" --cflags="$(SIMD_CFLAGS)" $(SIMD_SPEC_TESTS)

simd-benchmark:
	$(PYTHON3) simd_bench.py --w2c2 $(W2C2) --cc "$(CC)"
