
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_const.342.h"

void test() {
    const342Instance instance;
    const342Instantiate(&instance, resolveTestImports);
    printStart("const.342.wasm");
    assertEqualF64(
        const342_f(&instance),
        2.409919865102885e-181,
        "f()"
    );
}
