
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_float_exprs.69.h"

void test() {
    m14_floatX5FexprsX2E69Instance instance;
    m14_floatX5FexprsX2E69Instantiate(&instance, resolveTestImports);
    printStart("float_exprs.69.wasm");
    assertEqualU32(
        i32_reinterpret_f32(m14_floatX5FexprsX2E69Export22_f32X2EnoX5FfoldX5F6xX5FviaX5Fadd(&instance, -8.555137345589493e+29)),
        4068578245u,
        "f32.no_fold_6x_via_add(-8.555137345589493e+29)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m14_floatX5FexprsX2E69Export22_f32X2EnoX5FfoldX5F6xX5FviaX5Fadd(&instance, -1.2095059945729172e-23)),
        2595190497u,
        "f32.no_fold_6x_via_add(-1.2095059945729172e-23)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m14_floatX5FexprsX2E69Export22_f32X2EnoX5FfoldX5F6xX5FviaX5Fadd(&instance, 6.642689238252199e-24)),
        440449921u,
        "f32.no_fold_6x_via_add(6.642689238252199e-24)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m14_floatX5FexprsX2E69Export22_f32X2EnoX5FfoldX5F6xX5FviaX5Fadd(&instance, -6.147345965601403e-10)),
        2977789734u,
        "f32.no_fold_6x_via_add(-6.147345965601403e-10)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m14_floatX5FexprsX2E69Export22_f32X2EnoX5FfoldX5F6xX5FviaX5Fadd(&instance, -1.209858100766292e+24)),
        3904906727u,
        "f32.no_fold_6x_via_add(-1.209858100766292e+24)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m14_floatX5FexprsX2E69Export22_f64X2EnoX5FfoldX5F6xX5FviaX5Fadd(&instance, -3.517044906027714e+20)),
        14149352706895019994ull,
        "f64.no_fold_6x_via_add(-3.517044906027714e+20)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m14_floatX5FexprsX2E69Export22_f64X2EnoX5FfoldX5F6xX5FviaX5Fadd(&instance, -1.4824294109868734e-161)),
        11435767596137037638ull,
        "f64.no_fold_6x_via_add(-1.4824294109868734e-161)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m14_floatX5FexprsX2E69Export22_f64X2EnoX5FfoldX5F6xX5FviaX5Fadd(&instance, -7.484567838781003e+81)),
        15066699987142021125ull,
        "f64.no_fold_6x_via_add(-7.484567838781003e+81)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m14_floatX5FexprsX2E69Export22_f64X2EnoX5FfoldX5F6xX5FviaX5Fadd(&instance, 1.7277868192936067e+226)),
        8003319959635773419ull,
        "f64.no_fold_6x_via_add(1.7277868192936067e+226)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m14_floatX5FexprsX2E69Export22_f64X2EnoX5FfoldX5F6xX5FviaX5Fadd(&instance, -4.311639752519561e+70)),
        14898679235615764511ull,
        "f64.no_fold_6x_via_add(-4.311639752519561e+70)"
    );
}
