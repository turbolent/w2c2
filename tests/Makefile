W2C2 ?= ../w2c2/w2c2
PYTHON3 ?= python3

CFLAGS += -I../w2c2 -O0 -g

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

RUNTIME_LIFECYCLE_SOURCES = \
	test_runtime_lifecycle_owned.c \
	test_runtime_lifecycle_shared.c \
	test_runtime_lifecycle_imports.c
RUNTIME_LIFECYCLE_LDFLAGS = $(filter-out -lw2c2futex -L../futex,$(LDFLAGS))

runtime-lifecycle-test: test_runtime_lifecycle
	./test_runtime_lifecycle

test_runtime_lifecycle: runtime_lifecycle_test.c $(RUNTIME_LIFECYCLE_SOURCES)
	$(CC) $(CFLAGS) $^ -o $@ $(RUNTIME_LIFECYCLE_LDFLAGS)

test_runtime_lifecycle_owned.c: gen/runtime_lifecycle.0.wasm
	$(W2C2) -m $< $@

test_runtime_lifecycle_shared.c: gen/runtime_lifecycle.1.wasm
	$(W2C2) -m $< $@

test_runtime_lifecycle_imports.c: gen/runtime_lifecycle.2.wasm
	$(W2C2) -m $< $@

table-instances-test: run-test-table_instances

test_table_instances$(EXE): table_instances_test.c test_table_owner.c test_table_caller.c
	$(CC) $(CFLAGS) $^ -o $@ $(filter-out -lw2c2futex -L../futex,$(LDFLAGS))

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

run-tests: generator-test atomic-offsets-test c-strings-test binary-names-test table-instances-test $(patsubst gen/assert_%.c,run-test-%,$(wildcard gen/assert_*.c))

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

gen: gen-atomic-offsets gen-c-strings gen-binary-names gen-table-instances
	$(PYTHON3) gen.py

gen-atomic-offsets:
	wat2wasm --enable-threads atomic_offsets.wat -o gen/atomic_offsets.wasm

gen-c-strings:
	wat2wasm --debug-names c_strings.wat -o gen/c_strings.wasm

gen-binary-names:
	wat2wasm binary_names.wat -o gen/binary_names.wasm

gen-table-instances:
	wat2wasm table_owner.wat -o gen/table_owner.wasm
	wat2wasm table_caller.wat -o gen/table_caller.wasm

gen-%:
	$(PYTHON3) gen.py $*

clean:
	-rm -f main.o test_*.o test_*.h
	-rm -f test_atomic_offsets$(EXE) test_atomic_offsets.c
	-rm -f test_c_strings$(EXE) test_c_strings.c
	-rm -f test_binary_names$(EXE) test_binary_names.c
	-rm -f test_runtime_lifecycle $(RUNTIME_LIFECYCLE_SOURCES)
	-rm -f $(RUNTIME_LIFECYCLE_SOURCES:.c=.h)
	-rm -f test_table_instances$(EXE) test_table_owner.c test_table_caller.c
