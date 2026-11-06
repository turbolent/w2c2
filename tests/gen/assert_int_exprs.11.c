#include "test.h"
#include "test_int_exprs.11.h"

void test(void) {
    static m12_intX5FexprsX2E11Instance instance;
    m12_intX5FexprsX2E11Instantiate(&instance, resolveTestImports);
    printStart("int_exprs.11.wasm");
#if W2C2_RUNTIME_CHECKS
    assertTrap(m12_intX5FexprsX2E11Export11_i32X2EdivX5FsX5F0(&instance, 71u), trapDivByZero, "i32.div_s_0(71u)");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m12_intX5FexprsX2E11Export11_i32X2EdivX5FuX5F0(&instance, 71u), trapDivByZero, "i32.div_u_0(71u)");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m12_intX5FexprsX2E11Export11_i64X2EdivX5FsX5F0(&instance, 71ull), trapDivByZero, "i64.div_s_0(71ull)");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m12_intX5FexprsX2E11Export11_i64X2EdivX5FuX5F0(&instance, 71ull), trapDivByZero, "i64.div_u_0(71ull)");
#endif
    m12_intX5FexprsX2E11FreeInstance(&instance);
}
