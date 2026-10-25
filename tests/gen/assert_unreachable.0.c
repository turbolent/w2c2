
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_unreachable.0.h"

void test() {
    m13_unreachableX2E0Instance instance;
    m13_unreachableX2E0Instantiate(&instance, resolveTestImports);
    printStart("unreachable.0.wasm");
    assertEqualU32(
        m13_unreachableX2E0Export14_asX2DblockX2Dbroke(&instance),
        1u,
        "as-block-broke()"
    );
    assertEqualU32(
        m13_unreachableX2E0Export13_asX2DloopX2Dbroke(&instance),
        1u,
        "as-loop-broke()"
    );
    assertEqualU32(
        m13_unreachableX2E0Export10_asX2DifX2Dthen(&instance, 0u, 6u),
        6u,
        "as-if-then(0u, 6u)"
    );
    assertEqualU32(
        m13_unreachableX2E0Export10_asX2DifX2Delse(&instance, 1u, 6u),
        6u,
        "as-if-else(1u, 6u)"
    );
    assertEqualU32(
        m13_unreachableX2E0Export18_asX2DifX2DthenX2DnoX2Delse(&instance, 0u, 6u),
        6u,
        "as-if-then-no-else(0u, 6u)"
    );
}
