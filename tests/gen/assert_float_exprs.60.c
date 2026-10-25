
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_float_exprs.60.h"

void test() {
    m14_floatX5FexprsX2E60Instance instance;
    m14_floatX5FexprsX2E60Instantiate(&instance, resolveTestImports);
    printStart("float_exprs.60.wasm");
    assertEqualU32(
        i32_reinterpret_f32(m14_floatX5FexprsX2E60Export26_f32X2EnoX5FalgebraicX5Ffactoring(&instance, 2.2102996109817433e-14, 3.146527526379228e-12)),
        2571075368u,
        "f32.no_algebraic_factoring(2.2102996109817433e-14, 3.146527526379228e-12)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m14_floatX5FexprsX2E60Export26_f32X2EnoX5FalgebraicX5Ffactoring(&instance, -3289460768768.0, -15941538816.0)),
        1762604185u,
        "f32.no_algebraic_factoring(-3289460768768.0, -15941538816.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m14_floatX5FexprsX2E60Export26_f32X2EnoX5FalgebraicX5Ffactoring(&instance, 0.00036497542168945074, -0.00016153714386746287)),
        870712803u,
        "f32.no_algebraic_factoring(0.00036497542168945074, -0.00016153714386746287)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m14_floatX5FexprsX2E60Export26_f32X2EnoX5FalgebraicX5Ffactoring(&instance, 6.538326602139807e-14, -2.7412772911545626e-14)),
        327914662u,
        "f32.no_algebraic_factoring(6.538326602139807e-14, -2.7412772911545626e-14)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m14_floatX5FexprsX2E60Export26_f32X2EnoX5FalgebraicX5Ffactoring(&instance, 3609681910038528.0, -5260104429469696.0)),
        4080583891u,
        "f32.no_algebraic_factoring(3609681910038528.0, -5260104429469696.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m14_floatX5FexprsX2E60Export26_f64X2EnoX5FalgebraicX5Ffactoring(&instance, 2.136404543498951e+107, -2.928587558394428e+101)),
        7818515589337550196ull,
        "f64.no_algebraic_factoring(2.136404543498951e+107, -2.928587558394428e+101)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m14_floatX5FexprsX2E60Export26_f64X2EnoX5FalgebraicX5Ffactoring(&instance, -1.2290171159244358e+93, -8.2221589190166e+99)),
        16819892485880140289ull,
        "f64.no_algebraic_factoring(-1.2290171159244358e+93, -8.2221589190166e+99)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m14_floatX5FexprsX2E60Export26_f64X2EnoX5FalgebraicX5Ffactoring(&instance, 5477733829752.252, -970738900948.5906)),
        4987747999326390045ull,
        "f64.no_algebraic_factoring(5477733829752.252, -970738900948.5906)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m14_floatX5FexprsX2E60Export26_f64X2EnoX5FalgebraicX5Ffactoring(&instance, -1.0689141744923551e+55, -1.7337839359373804e+50)),
        6253339631158964222ull,
        "f64.no_algebraic_factoring(-1.0689141744923551e+55, -1.7337839359373804e+50)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m14_floatX5FexprsX2E60Export26_f64X2EnoX5FalgebraicX5Ffactoring(&instance, -1.0295699877022106e-71, -8.952274637805908e-72)),
        2473652960990319032ull,
        "f64.no_algebraic_factoring(-1.0295699877022106e-71, -8.952274637805908e-72)"
    );
}
