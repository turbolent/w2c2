
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_float_exprs.59.h"

void test() {
    m14_floatX5FexprsX2E59Instance instance;
    m14_floatX5FexprsX2E59Instantiate(&instance, resolveTestImports);
    printStart("float_exprs.59.wasm");
    assertEqualU32(
        i32_reinterpret_f32(m14_floatX5FexprsX2E59Export26_f32X2EnoX5FalgebraicX5Ffactoring(&instance, -5.371186465411003e-17, 9.744327905706555e-17)),
        2315864577u,
        "f32.no_algebraic_factoring(-5.371186465411003e-17, 9.744327905706555e-17)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m14_floatX5FexprsX2E59Export26_f32X2EnoX5FalgebraicX5Ffactoring(&instance, -19756732.0, 32770204.0)),
        3625675853u,
        "f32.no_algebraic_factoring(-19756732.0, 32770204.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m14_floatX5FexprsX2E59Export26_f32X2EnoX5FalgebraicX5Ffactoring(&instance, 52314148700160.0, -145309984358400.0)),
        4000155759u,
        "f32.no_algebraic_factoring(52314148700160.0, -145309984358400.0)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m14_floatX5FexprsX2E59Export26_f32X2EnoX5FalgebraicX5Ffactoring(&instance, 195260.375, -227.75723266601562)),
        1359874131u,
        "f32.no_algebraic_factoring(195260.375, -227.75723266601562)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m14_floatX5FexprsX2E59Export26_f32X2EnoX5FalgebraicX5Ffactoring(&instance, -237.487060546875, -972341.5)),
        3546030359u,
        "f32.no_algebraic_factoring(-237.487060546875, -972341.5)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m14_floatX5FexprsX2E59Export26_f64X2EnoX5FalgebraicX5Ffactoring(&instance, 9.639720335949767e-144, 8.019175443606207e-140)),
        9668435399096543331ull,
        "f64.no_algebraic_factoring(9.639720335949767e-144, 8.019175443606207e-140)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m14_floatX5FexprsX2E59Export26_f64X2EnoX5FalgebraicX5Ffactoring(&instance, 5.166066590392027e-114, 1.494333315888213e-120)),
        1217162942843921803ull,
        "f64.no_algebraic_factoring(5.166066590392027e-114, 1.494333315888213e-120)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m14_floatX5FexprsX2E59Export26_f64X2EnoX5FalgebraicX5Ffactoring(&instance, -2.866135870517635e-114, -1.2114355254268516e-111)),
        10511676135434922533ull,
        "f64.no_algebraic_factoring(-2.866135870517635e-114, -1.2114355254268516e-111)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m14_floatX5FexprsX2E59Export26_f64X2EnoX5FalgebraicX5Ffactoring(&instance, -1.2920992810078149e+54, 6.62717187728034e+56)),
        15530333405173431543ull,
        "f64.no_algebraic_factoring(-1.2920992810078149e+54, 6.62717187728034e+56)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m14_floatX5FexprsX2E59Export26_f64X2EnoX5FalgebraicX5Ffactoring(&instance, 2.624279568901057e+34, -1.6250233986050802e+27)),
        5636689734063865714ull,
        "f64.no_algebraic_factoring(2.624279568901057e+34, -1.6250233986050802e+27)"
    );
}
