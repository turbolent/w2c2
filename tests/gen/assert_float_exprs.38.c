
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_float_exprs.38.h"

void test() {
    floatexprs38Instance instance;
    floatexprs38Instantiate(&instance, resolveTestImports);
    printStart("float_exprs.38.wasm");
    assertEqualF32(
        floatexprs38_no_demote_mixed_sub(&instance, 7.869935327202668e+24, 4.0863470592574095e+18),
        7.869930965402192e+24,
        "no_demote_mixed_sub(7.869935327202668e+24, 4.0863470592574095e+18)"
    );
    assertEqualF32(
        floatexprs38_no_demote_mixed_sub(&instance, -1535841968.9056544, 239897.28125),
        -1536081920.0,
        "no_demote_mixed_sub(-1535841968.9056544, 239897.28125)"
    );
    assertEqualF32(
        floatexprs38_no_demote_mixed_sub(&instance, -102.19459272722602, 0.0003942613839171827),
        -102.19498443603516,
        "no_demote_mixed_sub(-102.19459272722602, 0.0003942613839171827)"
    );
    assertEqualF32(
        floatexprs38_no_demote_mixed_sub(&instance, 5.645470375565188e-17, 5.85107700707483e-22),
        5.645411727723358e-17,
        "no_demote_mixed_sub(5.645470375565188e-17, 5.85107700707483e-22)"
    );
    assertEqualF32(
        floatexprs38_no_demote_mixed_sub(&instance, 27090.388466832894, 63120.890625),
        -36030.50390625,
        "no_demote_mixed_sub(27090.388466832894, 63120.890625)"
    );
}
