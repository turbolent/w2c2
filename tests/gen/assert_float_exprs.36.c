
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_float_exprs.36.h"

void test() {
    floatexprs36Instance instance;
    floatexprs36Instantiate(&instance, resolveTestImports);
    printStart("float_exprs.36.wasm");
    assertEqualF32(
        floatexprs36_no_fold_promote_demote(&instance, 0.0),
        0.0,
        "no_fold_promote_demote(0.0)"
    );
    assertEqualF32(
        floatexprs36_no_fold_promote_demote(&instance, -0.0),
        -0.0,
        "no_fold_promote_demote(-0.0)"
    );
    assertEqualF32(
        floatexprs36_no_fold_promote_demote(&instance, 1.401298464324817e-45),
        1.401298464324817e-45,
        "no_fold_promote_demote(1.401298464324817e-45)"
    );
    assertEqualF32(
        floatexprs36_no_fold_promote_demote(&instance, -1.401298464324817e-45),
        -1.401298464324817e-45,
        "no_fold_promote_demote(-1.401298464324817e-45)"
    );
    assertEqualF32(
        floatexprs36_no_fold_promote_demote(&instance, 1.1754942106924411e-38),
        1.1754942106924411e-38,
        "no_fold_promote_demote(1.1754942106924411e-38)"
    );
    assertEqualF32(
        floatexprs36_no_fold_promote_demote(&instance, -1.1754942106924411e-38),
        -1.1754942106924411e-38,
        "no_fold_promote_demote(-1.1754942106924411e-38)"
    );
    assertEqualF32(
        floatexprs36_no_fold_promote_demote(&instance, 1.1754943508222875e-38),
        1.1754943508222875e-38,
        "no_fold_promote_demote(1.1754943508222875e-38)"
    );
    assertEqualF32(
        floatexprs36_no_fold_promote_demote(&instance, -1.1754943508222875e-38),
        -1.1754943508222875e-38,
        "no_fold_promote_demote(-1.1754943508222875e-38)"
    );
    assertEqualF32(
        floatexprs36_no_fold_promote_demote(&instance, 3.4028234663852886e+38),
        3.4028234663852886e+38,
        "no_fold_promote_demote(3.4028234663852886e+38)"
    );
    assertEqualF32(
        floatexprs36_no_fold_promote_demote(&instance, -3.4028234663852886e+38),
        -3.4028234663852886e+38,
        "no_fold_promote_demote(-3.4028234663852886e+38)"
    );
    assertEqualF32(
        floatexprs36_no_fold_promote_demote(&instance, INFINITY),
        INFINITY,
        "no_fold_promote_demote(INFINITY)"
    );
    assertEqualF32(
        floatexprs36_no_fold_promote_demote(&instance, -INFINITY),
        -INFINITY,
        "no_fold_promote_demote(-INFINITY)"
    );
}
