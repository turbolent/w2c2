
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_align.107.h"

void test() {
    align107Instance instance;
    align107Instantiate(&instance, resolveTestImports);
    printStart("align.107.wasm");
    assertEqualU32(
        align107_load(&instance, 65532u),
        0u,
        "load(65532u)"
    );
}
