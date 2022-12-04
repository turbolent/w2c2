
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.422.h"

void test() {
    const422Instance instance;
    const422Instantiate(&instance, resolveTestImports);
    printStart("const.422.wasm");
    assertEqualF64(
        const422_f(&instance),
        1.5845632502852875e+29,
        "f()"
    );
}
