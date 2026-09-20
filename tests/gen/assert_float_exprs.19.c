
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_float_exprs.19.h"

void test() {
    m14_floatX5FexprsX2E19Instance instance;
    m14_floatX5FexprsX2E19Instantiate(&instance, resolveTestImports);
    printStart("float_exprs.19.wasm");
    assertEqualU32(
        i32_reinterpret_f32(m14_floatX5FexprsX2E19Export22_f32X2EnoX5FregroupX5FdivX5Fmul(&instance, -2.831348900581148e-35, -7.270787044900695e-20, 1.6406605104124838e-35)),
        538190437u,
        "f32.no_regroup_div_mul(-2.831348900581148e-35, -7.270787044900695e-20, 1.6406605104124838e-35)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m14_floatX5FexprsX2E19Export22_f32X2EnoX5FregroupX5FdivX5Fmul(&instance, -3.145897699301651e+27, -4.0864003417251035e-35, -9.245928315588461e+21)),
        2147483648u,
        "f32.no_regroup_div_mul(-3.145897699301651e+27, -4.0864003417251035e-35, -9.245928315588461e+21)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m14_floatX5FexprsX2E19Export22_f32X2EnoX5FregroupX5FdivX5Fmul(&instance, -93157.4296875, -8.129265438583388e-07, -1.5469396736694269e-37)),
        4206661932u,
        "f32.no_regroup_div_mul(-93157.4296875, -8.129265438583388e-07, -1.5469396736694269e-37)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m14_floatX5FexprsX2E19Export22_f32X2EnoX5FregroupX5FdivX5Fmul(&instance, -8.899642828403211e-29, 1.7887724636863027e+22, 5.146802318776667e+20)),
        2473922297u,
        "f32.no_regroup_div_mul(-8.899642828403211e-29, 1.7887724636863027e+22, 5.146802318776667e+20)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m14_floatX5FexprsX2E19Export22_f32X2EnoX5FregroupX5FdivX5Fmul(&instance, 9.222036179566499e+33, 33330492.0, -3.253108762736574e+21)),
        3768838261u,
        "f32.no_regroup_div_mul(9.222036179566499e+33, 33330492.0, -3.253108762736574e+21)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m14_floatX5FexprsX2E19Export22_f64X2EnoX5FregroupX5FdivX5Fmul(&instance, 5.698811412550059e-128, -1.8313439132919336e-36, 9.543270551003098e-194)),
        14279677686886620461ull,
        "f64.no_regroup_div_mul(5.698811412550059e-128, -1.8313439132919336e-36, 9.543270551003098e-194)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m14_floatX5FexprsX2E19Export22_f64X2EnoX5FregroupX5FdivX5Fmul(&instance, 3.5728928842550755e+101, 3.952760844538651e-135, -1.4507812412549008e+240)),
        9223372036854775808ull,
        "f64.no_regroup_div_mul(3.5728928842550755e+101, 3.952760844538651e-135, -1.4507812412549008e+240)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m14_floatX5FexprsX2E19Export22_f64X2EnoX5FregroupX5FdivX5Fmul(&instance, 9.124278383497107e-145, 5.556134527714797e+271, 2.5090826940306507e-135)),
        9218868437227405312ull,
        "f64.no_regroup_div_mul(9.124278383497107e-145, 5.556134527714797e+271, 2.5090826940306507e-135)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m14_floatX5FexprsX2E19Export22_f64X2EnoX5FregroupX5FdivX5Fmul(&instance, -4.492093000352015e+144, -1.2087878984017852e+184, -5.966133806260623e+251)),
        14981548491626301009ull,
        "f64.no_regroup_div_mul(-4.492093000352015e+144, -1.2087878984017852e+184, -5.966133806260623e+251)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m14_floatX5FexprsX2E19Export22_f64X2EnoX5FregroupX5FdivX5Fmul(&instance, 7.470269158630455e-181, 7.568026329781282e-265, -1.055389683973521e-252)),
        10953754119023888080ull,
        "f64.no_regroup_div_mul(7.470269158630455e-181, 7.568026329781282e-265, -1.055389683973521e-252)"
    );
}
