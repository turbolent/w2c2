
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_unreachable.0.h"

void test() {
    unreachable0Instance instance;
    unreachable0Instantiate(&instance, resolveTestImports);
    printStart("unreachable.0.wasm");
    assertEqualU32(
        unreachable0_asX2DblockX2Dbroke(&instance),
        1u,
        "as-block-broke()"
    );
    assertEqualU32(
        unreachable0_asX2DloopX2Dbroke(&instance),
        1u,
        "as-loop-broke()"
    );
    assertEqualU32(
        unreachable0_asX2DifX2Dthen(&instance, 0u, 6u),
        6u,
        "as-if-then(0u, 6u)"
    );
    assertEqualU32(
        unreachable0_asX2DifX2Delse(&instance, 1u, 6u),
        6u,
        "as-if-else(1u, 6u)"
    );
    assertEqualU32(
        unreachable0_asX2DifX2DthenX2DnoX2Delse(&instance, 0u, 6u),
        6u,
        "as-if-then-no-else(0u, 6u)"
    );
}
