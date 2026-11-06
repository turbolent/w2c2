#include "test.h"
#include "test_int_exprs.7.h"

void test(void) {
    static m11_intX5FexprsX2E7Instance instance;
    m11_intX5FexprsX2E7Instantiate(&instance, resolveTestImports);
    printStart("int_exprs.7.wasm");
#if W2C2_RUNTIME_CHECKS
    assertTrap(m11_intX5FexprsX2E7Export22_i32X2EnoX5FfoldX5FremX5FsX5Fself(&instance, 0u), trapDivByZero, "i32.no_fold_rem_s_self(0u)");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m11_intX5FexprsX2E7Export22_i32X2EnoX5FfoldX5FremX5FuX5Fself(&instance, 0u), trapDivByZero, "i32.no_fold_rem_u_self(0u)");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m11_intX5FexprsX2E7Export22_i64X2EnoX5FfoldX5FremX5FsX5Fself(&instance, 0ull), trapDivByZero, "i64.no_fold_rem_s_self(0ull)");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m11_intX5FexprsX2E7Export22_i64X2EnoX5FfoldX5FremX5FuX5Fself(&instance, 0ull), trapDivByZero, "i64.no_fold_rem_u_self(0ull)");
#endif
    m11_intX5FexprsX2E7FreeInstance(&instance);
}
