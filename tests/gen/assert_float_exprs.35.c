
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_float_exprs.35.h"

void test() {
    m14_floatX5FexprsX2E35Instance instance;
    m14_floatX5FexprsX2E35Instantiate(&instance, resolveTestImports);
    printStart("float_exprs.35.wasm");
    assertEqualU64(
        i64_reinterpret_f64(m14_floatX5FexprsX2E35Export22_noX5FfoldX5FdemoteX5Fpromote(&instance, -1.7176297220569481e-40)),
        13235495326728585216ull,
        "no_fold_demote_promote(-1.7176297220569481e-40)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m14_floatX5FexprsX2E35Export22_noX5FfoldX5FdemoteX5Fpromote(&instance, -2.8464775573304055e-26)),
        13448204151146151936ull,
        "no_fold_demote_promote(-2.8464775573304055e-26)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m14_floatX5FexprsX2E35Export22_noX5FfoldX5FdemoteX5Fpromote(&instance, 2.0897069969990923e+32)),
        5090364081378951168ull,
        "no_fold_demote_promote(2.0897069969990923e+32)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m14_floatX5FexprsX2E35Export22_noX5FfoldX5FdemoteX5Fpromote(&instance, -4.7074160416121775e-27)),
        13436295269301878784ull,
        "no_fold_demote_promote(-4.7074160416121775e-27)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m14_floatX5FexprsX2E35Export22_noX5FfoldX5FdemoteX5Fpromote(&instance, 2.335945149795088e+31)),
        5076240020759642112ull,
        "no_fold_demote_promote(2.335945149795088e+31)"
    );
}
