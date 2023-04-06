
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_float_exprs.35.h"

void test() {
    floatexprs35Instance instance;
    floatexprs35Instantiate(&instance, resolveTestImports);
    printStart("float_exprs.35.wasm");
    assertEqualF64(
        floatexprs35_no_fold_demote_promote(&instance, -1.7176297220569481e-40),
        -1.7176275796615013e-40,
        "no_fold_demote_promote(-1.7176297220569481e-40)"
    );
    assertEqualF64(
        floatexprs35_no_fold_demote_promote(&instance, -2.8464775573304055e-26),
        -2.846477619188087e-26,
        "no_fold_demote_promote(-2.8464775573304055e-26)"
    );
    assertEqualF64(
        floatexprs35_no_fold_demote_promote(&instance, 2.0897069969990923e+32),
        2.08970700445326e+32,
        "no_fold_demote_promote(2.0897069969990923e+32)"
    );
    assertEqualF64(
        floatexprs35_no_fold_demote_promote(&instance, -4.7074160416121775e-27),
        -4.7074161331556024e-27,
        "no_fold_demote_promote(-4.7074160416121775e-27)"
    );
    assertEqualF64(
        floatexprs35_no_fold_demote_promote(&instance, 2.335945149795088e+31),
        2.3359452224542198e+31,
        "no_fold_demote_promote(2.335945149795088e+31)"
    );
}
