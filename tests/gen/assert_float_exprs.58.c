
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_float_exprs.58.h"

void test() {
    floatexprs58Instance instance;
    floatexprs58Instantiate(&instance, resolveTestImports);
    printStart("float_exprs.58.wasm");
    assertEqualF32(
        floatexprs58_f32X2EnoX5FalgebraicX5Ffactoring(&instance, 2.2102996109817433e-14, 3.146527526379228e-12),
        -9.900147562538522e-24,
        "f32.no_algebraic_factoring(2.2102996109817433e-14, 3.146527526379228e-12)"
    );
    assertEqualF32(
        floatexprs58_f32X2EnoX5FalgebraicX5Ffactoring(&instance, -3289460768768.0, -15941538816.0),
        1.082029860086528e+25,
        "f32.no_algebraic_factoring(-3289460768768.0, -15941538816.0)"
    );
    assertEqualF32(
        floatexprs58_f32X2EnoX5FalgebraicX5Ffactoring(&instance, 0.00036497542168945074, -0.00016153714386746287),
        1.0711280395980793e-07,
        "f32.no_algebraic_factoring(0.00036497542168945074, -0.00016153714386746287)"
    );
    assertEqualF32(
        floatexprs58_f32X2EnoX5FalgebraicX5Ffactoring(&instance, 6.538326602139807e-14, -2.7412772911545626e-14),
        3.523511174043803e-27,
        "f32.no_algebraic_factoring(6.538326602139807e-14, -2.7412772911545626e-14)"
    );
    assertEqualF32(
        floatexprs58_f32X2EnoX5FalgebraicX5Ffactoring(&instance, 3609681910038528.0, -5260104429469696.0),
        -1.463889604789756e+31,
        "f32.no_algebraic_factoring(3609681910038528.0, -5260104429469696.0)"
    );
    assertEqualF64(
        floatexprs58_f64X2EnoX5FalgebraicX5Ffactoring(&instance, 2.136404543498951e+107, -2.928587558394428e+101),
        4.564224373474385e+214,
        "f64.no_algebraic_factoring(2.136404543498951e+107, -2.928587558394428e+101)"
    );
    assertEqualF64(
        floatexprs58_f64X2EnoX5FalgebraicX5Ffactoring(&instance, -1.2290171159244358e+93, -8.2221589190166e+99),
        -6.760389728956271e+199,
        "f64.no_algebraic_factoring(-1.2290171159244358e+93, -8.2221589190166e+99)"
    );
    assertEqualF64(
        floatexprs58_f64X2EnoX5FalgebraicX5Ffactoring(&instance, 5477733829752.252, -970738900948.5906),
        2.9063233895797397e+25,
        "f64.no_algebraic_factoring(5477733829752.252, -970738900948.5906)"
    );
    assertEqualF64(
        floatexprs58_f64X2EnoX5FalgebraicX5Ffactoring(&instance, -1.0689141744923551e+55, -1.7337839359373804e+50),
        1.1425775121300724e+110,
        "f64.no_algebraic_factoring(-1.0689141744923551e+55, -1.7337839359373804e+50)"
    );
    assertEqualF64(
        floatexprs58_f64X2EnoX5FalgebraicX5Ffactoring(&instance, -1.0295699877022106e-71, -8.952274637805908e-72),
        2.5858214767010105e-143,
        "f64.no_algebraic_factoring(-1.0295699877022106e-71, -8.952274637805908e-72)"
    );
}
