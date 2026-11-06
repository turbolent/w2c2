#include "test.h"
#include "test_int_exprs.18.h"

void test(void) {
    static m12_intX5FexprsX2E18Instance instance;
    m12_intX5FexprsX2E18Instantiate(&instance, resolveTestImports);
    printStart("int_exprs.18.wasm");
#if W2C2_RUNTIME_CHECKS
    assertTrap(m12_intX5FexprsX2E18Export20_i32X2EnoX5FfoldX5FdivX5Fneg1(&instance, 2147483648u), trapIntOverflow, "i32.no_fold_div_neg1(2147483648u)");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m12_intX5FexprsX2E18Export20_i64X2EnoX5FfoldX5FdivX5Fneg1(&instance, 9223372036854775808ull), trapIntOverflow, "i64.no_fold_div_neg1(9223372036854775808ull)");
#endif
    m12_intX5FexprsX2E18FreeInstance(&instance);
}
