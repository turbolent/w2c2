
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_align.107.h"

void test() {
    m9_alignX2E107Instance instance;
    m9_alignX2E107Instantiate(&instance, resolveTestImports);
    printStart("align.107.wasm");
    assertEqualU32(
        m9_alignX2E107Export4_load(&instance, 65532u),
        0u,
        "load(65532u)"
    );
}
