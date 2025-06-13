#include <stdio.h>
#include "typestack.h"
#include "typestack_test.h"

void
testTypeStack(void) {
    WasmTypeStack typeStack = wasmEmptyTypeStack;

    {
        const size_t actualLength = typeStack.length;
        if (actualLength != 0) {
            fprintf(stderr, "FAIL testTypeStack: incorrect length: %ld != %d\n", actualLength, 0);
            exit(1);
        }
    }

    if (!wasmTypeStackSet(&typeStack, 1, wasmValueTypeI64)) {
        fprintf(stderr, "FAIL testTypeStack: failed to set\n");
        exit(1);
    }

    if (!wasmTypeStackSet(&typeStack, 5, wasmValueTypeI32)) {
        fprintf(stderr, "FAIL testTypeStack: failed to set\n");
        exit(1);
    }

    if (!wasmTypeStackSet(&typeStack, 0, wasmValueTypeF64)) {
        fprintf(stderr, "FAIL testTypeStack: failed to set\n");
        exit(1);
    }

    if (!wasmTypeStackSet(&typeStack, 3, wasmValueTypeF32)) {
        fprintf(stderr, "FAIL testTypeStack: failed to set\n");
        exit(1);
    }

    if (!wasmTypeStackSet(&typeStack, 1, wasmValueTypeI32)) {
        fprintf(stderr, "FAIL testTypeStack: failed to set\n");
        exit(1);
    }

    {
        const size_t expectedLength = 6;
        const size_t actualLength = typeStack.length;

        if (actualLength != expectedLength) {
            fprintf(
                stderr,
                "FAIL testTypeStack: incorrect length after sets: %ld != %ld\n",
                actualLength,
                expectedLength
            );
            exit(1);
        }

        {
            const WasmValueType expectedValues[6] = {
                1 << wasmValueTypeF64,
                (1 << wasmValueTypeI64) | (1 << wasmValueTypeI32),
                0,
                1 << wasmValueTypeF32,
                0,
                1 << wasmValueTypeI32
            };

            U32 index = 0;
            for (; index < actualLength; index++) {
                const WasmValueType actual = typeStack.valueTypes[index];
                const WasmValueType expected = expectedValues[index];

                if (actual != expected) {
                    fprintf(
                        stderr,
                        "FAIL testTypeStack: incorrect value at index %u: %u != %u\n",
                        index,
                        actual,
                        expected
                    );
                    exit(1);
                }
            }
        }
    }
    fprintf(stderr, "PASS testTypeStack\n");
}
