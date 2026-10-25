
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_f64.0.h"

void test() {
    m5_f64X2E0Instance instance;
    m5_f64X2E0Instantiate(&instance, resolveTestImports);
    printStart("f64.0.wasm");
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, -0.0, -0.0)),
        9223372036854775808ull,
        "add(-0.0, -0.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, -0.0, 0.0)),
        0ull,
        "add(-0.0, 0.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, 0.0, -0.0)),
        0ull,
        "add(0.0, -0.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, 0.0, 0.0)),
        0ull,
        "add(0.0, 0.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, -0.0, -5e-324)),
        9223372036854775809ull,
        "add(-0.0, -5e-324)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, -0.0, 5e-324)),
        1ull,
        "add(-0.0, 5e-324)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, 0.0, -5e-324)),
        9223372036854775809ull,
        "add(0.0, -5e-324)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, 0.0, 5e-324)),
        1ull,
        "add(0.0, 5e-324)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, -0.0, -2.2250738585072014e-308)),
        9227875636482146304ull,
        "add(-0.0, -2.2250738585072014e-308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, -0.0, 2.2250738585072014e-308)),
        4503599627370496ull,
        "add(-0.0, 2.2250738585072014e-308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, 0.0, -2.2250738585072014e-308)),
        9227875636482146304ull,
        "add(0.0, -2.2250738585072014e-308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, 0.0, 2.2250738585072014e-308)),
        4503599627370496ull,
        "add(0.0, 2.2250738585072014e-308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, -0.0, -0.5)),
        13826050856027422720ull,
        "add(-0.0, -0.5)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, -0.0, 0.5)),
        4602678819172646912ull,
        "add(-0.0, 0.5)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, 0.0, -0.5)),
        13826050856027422720ull,
        "add(0.0, -0.5)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, 0.0, 0.5)),
        4602678819172646912ull,
        "add(0.0, 0.5)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, -0.0, -1.0)),
        13830554455654793216ull,
        "add(-0.0, -1.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, -0.0, 1.0)),
        4607182418800017408ull,
        "add(-0.0, 1.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, 0.0, -1.0)),
        13830554455654793216ull,
        "add(0.0, -1.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, 0.0, 1.0)),
        4607182418800017408ull,
        "add(0.0, 1.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, -0.0, -6.283185307179586)),
        13842132293034192152ull,
        "add(-0.0, -6.283185307179586)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, -0.0, 6.283185307179586)),
        4618760256179416344ull,
        "add(-0.0, 6.283185307179586)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, 0.0, -6.283185307179586)),
        13842132293034192152ull,
        "add(0.0, -6.283185307179586)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, 0.0, 6.283185307179586)),
        4618760256179416344ull,
        "add(0.0, 6.283185307179586)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, -0.0, -1.7976931348623157e+308)),
        18442240474082181119ull,
        "add(-0.0, -1.7976931348623157e+308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, -0.0, 1.7976931348623157e+308)),
        9218868437227405311ull,
        "add(-0.0, 1.7976931348623157e+308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, 0.0, -1.7976931348623157e+308)),
        18442240474082181119ull,
        "add(0.0, -1.7976931348623157e+308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, 0.0, 1.7976931348623157e+308)),
        9218868437227405311ull,
        "add(0.0, 1.7976931348623157e+308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, -0.0, -INFINITY)),
        18442240474082181120ull,
        "add(-0.0, -INFINITY)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, -0.0, INFINITY)),
        9218868437227405312ull,
        "add(-0.0, INFINITY)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, 0.0, -INFINITY)),
        18442240474082181120ull,
        "add(0.0, -INFINITY)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, 0.0, INFINITY)),
        9218868437227405312ull,
        "add(0.0, INFINITY)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, -0.0, f64_reinterpret_i64(0xfff8000000000000ull))) & 9223372036854775807ull),
        9221120237041090560ull,
        "add(-0.0, f64_reinterpret_i64(0xfff8000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, -0.0, f64_reinterpret_i64(0xfff4000000000000ull))) & 9221120237041090560ull),
        9221120237041090560ull,
        "add(-0.0, f64_reinterpret_i64(0xfff4000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, -0.0, f64_reinterpret_i64(0x7ff8000000000000ull))) & 9223372036854775807ull),
        9221120237041090560ull,
        "add(-0.0, f64_reinterpret_i64(0x7ff8000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, -0.0, f64_reinterpret_i64(0x7ff4000000000000ull))) & 9221120237041090560ull),
        9221120237041090560ull,
        "add(-0.0, f64_reinterpret_i64(0x7ff4000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, 0.0, f64_reinterpret_i64(0xfff8000000000000ull))) & 9223372036854775807ull),
        9221120237041090560ull,
        "add(0.0, f64_reinterpret_i64(0xfff8000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, 0.0, f64_reinterpret_i64(0xfff4000000000000ull))) & 9221120237041090560ull),
        9221120237041090560ull,
        "add(0.0, f64_reinterpret_i64(0xfff4000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, 0.0, f64_reinterpret_i64(0x7ff8000000000000ull))) & 9223372036854775807ull),
        9221120237041090560ull,
        "add(0.0, f64_reinterpret_i64(0x7ff8000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, 0.0, f64_reinterpret_i64(0x7ff4000000000000ull))) & 9221120237041090560ull),
        9221120237041090560ull,
        "add(0.0, f64_reinterpret_i64(0x7ff4000000000000ull))"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, -5e-324, -0.0)),
        9223372036854775809ull,
        "add(-5e-324, -0.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, -5e-324, 0.0)),
        9223372036854775809ull,
        "add(-5e-324, 0.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, 5e-324, -0.0)),
        1ull,
        "add(5e-324, -0.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, 5e-324, 0.0)),
        1ull,
        "add(5e-324, 0.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, -5e-324, -5e-324)),
        9223372036854775810ull,
        "add(-5e-324, -5e-324)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, -5e-324, 5e-324)),
        0ull,
        "add(-5e-324, 5e-324)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, 5e-324, -5e-324)),
        0ull,
        "add(5e-324, -5e-324)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, 5e-324, 5e-324)),
        2ull,
        "add(5e-324, 5e-324)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, -5e-324, -2.2250738585072014e-308)),
        9227875636482146305ull,
        "add(-5e-324, -2.2250738585072014e-308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, -5e-324, 2.2250738585072014e-308)),
        4503599627370495ull,
        "add(-5e-324, 2.2250738585072014e-308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, 5e-324, -2.2250738585072014e-308)),
        9227875636482146303ull,
        "add(5e-324, -2.2250738585072014e-308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, 5e-324, 2.2250738585072014e-308)),
        4503599627370497ull,
        "add(5e-324, 2.2250738585072014e-308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, -5e-324, -0.5)),
        13826050856027422720ull,
        "add(-5e-324, -0.5)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, -5e-324, 0.5)),
        4602678819172646912ull,
        "add(-5e-324, 0.5)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, 5e-324, -0.5)),
        13826050856027422720ull,
        "add(5e-324, -0.5)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, 5e-324, 0.5)),
        4602678819172646912ull,
        "add(5e-324, 0.5)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, -5e-324, -1.0)),
        13830554455654793216ull,
        "add(-5e-324, -1.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, -5e-324, 1.0)),
        4607182418800017408ull,
        "add(-5e-324, 1.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, 5e-324, -1.0)),
        13830554455654793216ull,
        "add(5e-324, -1.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, 5e-324, 1.0)),
        4607182418800017408ull,
        "add(5e-324, 1.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, -5e-324, -6.283185307179586)),
        13842132293034192152ull,
        "add(-5e-324, -6.283185307179586)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, -5e-324, 6.283185307179586)),
        4618760256179416344ull,
        "add(-5e-324, 6.283185307179586)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, 5e-324, -6.283185307179586)),
        13842132293034192152ull,
        "add(5e-324, -6.283185307179586)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, 5e-324, 6.283185307179586)),
        4618760256179416344ull,
        "add(5e-324, 6.283185307179586)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, -5e-324, -1.7976931348623157e+308)),
        18442240474082181119ull,
        "add(-5e-324, -1.7976931348623157e+308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, -5e-324, 1.7976931348623157e+308)),
        9218868437227405311ull,
        "add(-5e-324, 1.7976931348623157e+308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, 5e-324, -1.7976931348623157e+308)),
        18442240474082181119ull,
        "add(5e-324, -1.7976931348623157e+308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, 5e-324, 1.7976931348623157e+308)),
        9218868437227405311ull,
        "add(5e-324, 1.7976931348623157e+308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, -5e-324, -INFINITY)),
        18442240474082181120ull,
        "add(-5e-324, -INFINITY)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, -5e-324, INFINITY)),
        9218868437227405312ull,
        "add(-5e-324, INFINITY)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, 5e-324, -INFINITY)),
        18442240474082181120ull,
        "add(5e-324, -INFINITY)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, 5e-324, INFINITY)),
        9218868437227405312ull,
        "add(5e-324, INFINITY)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, -5e-324, f64_reinterpret_i64(0xfff8000000000000ull))) & 9223372036854775807ull),
        9221120237041090560ull,
        "add(-5e-324, f64_reinterpret_i64(0xfff8000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, -5e-324, f64_reinterpret_i64(0xfff4000000000000ull))) & 9221120237041090560ull),
        9221120237041090560ull,
        "add(-5e-324, f64_reinterpret_i64(0xfff4000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, -5e-324, f64_reinterpret_i64(0x7ff8000000000000ull))) & 9223372036854775807ull),
        9221120237041090560ull,
        "add(-5e-324, f64_reinterpret_i64(0x7ff8000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, -5e-324, f64_reinterpret_i64(0x7ff4000000000000ull))) & 9221120237041090560ull),
        9221120237041090560ull,
        "add(-5e-324, f64_reinterpret_i64(0x7ff4000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, 5e-324, f64_reinterpret_i64(0xfff8000000000000ull))) & 9223372036854775807ull),
        9221120237041090560ull,
        "add(5e-324, f64_reinterpret_i64(0xfff8000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, 5e-324, f64_reinterpret_i64(0xfff4000000000000ull))) & 9221120237041090560ull),
        9221120237041090560ull,
        "add(5e-324, f64_reinterpret_i64(0xfff4000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, 5e-324, f64_reinterpret_i64(0x7ff8000000000000ull))) & 9223372036854775807ull),
        9221120237041090560ull,
        "add(5e-324, f64_reinterpret_i64(0x7ff8000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, 5e-324, f64_reinterpret_i64(0x7ff4000000000000ull))) & 9221120237041090560ull),
        9221120237041090560ull,
        "add(5e-324, f64_reinterpret_i64(0x7ff4000000000000ull))"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, -2.2250738585072014e-308, -0.0)),
        9227875636482146304ull,
        "add(-2.2250738585072014e-308, -0.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, -2.2250738585072014e-308, 0.0)),
        9227875636482146304ull,
        "add(-2.2250738585072014e-308, 0.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, 2.2250738585072014e-308, -0.0)),
        4503599627370496ull,
        "add(2.2250738585072014e-308, -0.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, 2.2250738585072014e-308, 0.0)),
        4503599627370496ull,
        "add(2.2250738585072014e-308, 0.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, -2.2250738585072014e-308, -5e-324)),
        9227875636482146305ull,
        "add(-2.2250738585072014e-308, -5e-324)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, -2.2250738585072014e-308, 5e-324)),
        9227875636482146303ull,
        "add(-2.2250738585072014e-308, 5e-324)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, 2.2250738585072014e-308, -5e-324)),
        4503599627370495ull,
        "add(2.2250738585072014e-308, -5e-324)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, 2.2250738585072014e-308, 5e-324)),
        4503599627370497ull,
        "add(2.2250738585072014e-308, 5e-324)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, -2.2250738585072014e-308, -2.2250738585072014e-308)),
        9232379236109516800ull,
        "add(-2.2250738585072014e-308, -2.2250738585072014e-308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, -2.2250738585072014e-308, 2.2250738585072014e-308)),
        0ull,
        "add(-2.2250738585072014e-308, 2.2250738585072014e-308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, 2.2250738585072014e-308, -2.2250738585072014e-308)),
        0ull,
        "add(2.2250738585072014e-308, -2.2250738585072014e-308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, 2.2250738585072014e-308, 2.2250738585072014e-308)),
        9007199254740992ull,
        "add(2.2250738585072014e-308, 2.2250738585072014e-308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, -2.2250738585072014e-308, -0.5)),
        13826050856027422720ull,
        "add(-2.2250738585072014e-308, -0.5)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, -2.2250738585072014e-308, 0.5)),
        4602678819172646912ull,
        "add(-2.2250738585072014e-308, 0.5)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, 2.2250738585072014e-308, -0.5)),
        13826050856027422720ull,
        "add(2.2250738585072014e-308, -0.5)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, 2.2250738585072014e-308, 0.5)),
        4602678819172646912ull,
        "add(2.2250738585072014e-308, 0.5)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, -2.2250738585072014e-308, -1.0)),
        13830554455654793216ull,
        "add(-2.2250738585072014e-308, -1.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, -2.2250738585072014e-308, 1.0)),
        4607182418800017408ull,
        "add(-2.2250738585072014e-308, 1.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, 2.2250738585072014e-308, -1.0)),
        13830554455654793216ull,
        "add(2.2250738585072014e-308, -1.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, 2.2250738585072014e-308, 1.0)),
        4607182418800017408ull,
        "add(2.2250738585072014e-308, 1.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, -2.2250738585072014e-308, -6.283185307179586)),
        13842132293034192152ull,
        "add(-2.2250738585072014e-308, -6.283185307179586)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, -2.2250738585072014e-308, 6.283185307179586)),
        4618760256179416344ull,
        "add(-2.2250738585072014e-308, 6.283185307179586)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, 2.2250738585072014e-308, -6.283185307179586)),
        13842132293034192152ull,
        "add(2.2250738585072014e-308, -6.283185307179586)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, 2.2250738585072014e-308, 6.283185307179586)),
        4618760256179416344ull,
        "add(2.2250738585072014e-308, 6.283185307179586)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, -2.2250738585072014e-308, -1.7976931348623157e+308)),
        18442240474082181119ull,
        "add(-2.2250738585072014e-308, -1.7976931348623157e+308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, -2.2250738585072014e-308, 1.7976931348623157e+308)),
        9218868437227405311ull,
        "add(-2.2250738585072014e-308, 1.7976931348623157e+308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, 2.2250738585072014e-308, -1.7976931348623157e+308)),
        18442240474082181119ull,
        "add(2.2250738585072014e-308, -1.7976931348623157e+308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, 2.2250738585072014e-308, 1.7976931348623157e+308)),
        9218868437227405311ull,
        "add(2.2250738585072014e-308, 1.7976931348623157e+308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, -2.2250738585072014e-308, -INFINITY)),
        18442240474082181120ull,
        "add(-2.2250738585072014e-308, -INFINITY)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, -2.2250738585072014e-308, INFINITY)),
        9218868437227405312ull,
        "add(-2.2250738585072014e-308, INFINITY)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, 2.2250738585072014e-308, -INFINITY)),
        18442240474082181120ull,
        "add(2.2250738585072014e-308, -INFINITY)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, 2.2250738585072014e-308, INFINITY)),
        9218868437227405312ull,
        "add(2.2250738585072014e-308, INFINITY)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, -2.2250738585072014e-308, f64_reinterpret_i64(0xfff8000000000000ull))) & 9223372036854775807ull),
        9221120237041090560ull,
        "add(-2.2250738585072014e-308, f64_reinterpret_i64(0xfff8000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, -2.2250738585072014e-308, f64_reinterpret_i64(0xfff4000000000000ull))) & 9221120237041090560ull),
        9221120237041090560ull,
        "add(-2.2250738585072014e-308, f64_reinterpret_i64(0xfff4000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, -2.2250738585072014e-308, f64_reinterpret_i64(0x7ff8000000000000ull))) & 9223372036854775807ull),
        9221120237041090560ull,
        "add(-2.2250738585072014e-308, f64_reinterpret_i64(0x7ff8000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, -2.2250738585072014e-308, f64_reinterpret_i64(0x7ff4000000000000ull))) & 9221120237041090560ull),
        9221120237041090560ull,
        "add(-2.2250738585072014e-308, f64_reinterpret_i64(0x7ff4000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, 2.2250738585072014e-308, f64_reinterpret_i64(0xfff8000000000000ull))) & 9223372036854775807ull),
        9221120237041090560ull,
        "add(2.2250738585072014e-308, f64_reinterpret_i64(0xfff8000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, 2.2250738585072014e-308, f64_reinterpret_i64(0xfff4000000000000ull))) & 9221120237041090560ull),
        9221120237041090560ull,
        "add(2.2250738585072014e-308, f64_reinterpret_i64(0xfff4000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, 2.2250738585072014e-308, f64_reinterpret_i64(0x7ff8000000000000ull))) & 9223372036854775807ull),
        9221120237041090560ull,
        "add(2.2250738585072014e-308, f64_reinterpret_i64(0x7ff8000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, 2.2250738585072014e-308, f64_reinterpret_i64(0x7ff4000000000000ull))) & 9221120237041090560ull),
        9221120237041090560ull,
        "add(2.2250738585072014e-308, f64_reinterpret_i64(0x7ff4000000000000ull))"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, -0.5, -0.0)),
        13826050856027422720ull,
        "add(-0.5, -0.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, -0.5, 0.0)),
        13826050856027422720ull,
        "add(-0.5, 0.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, 0.5, -0.0)),
        4602678819172646912ull,
        "add(0.5, -0.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, 0.5, 0.0)),
        4602678819172646912ull,
        "add(0.5, 0.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, -0.5, -5e-324)),
        13826050856027422720ull,
        "add(-0.5, -5e-324)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, -0.5, 5e-324)),
        13826050856027422720ull,
        "add(-0.5, 5e-324)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, 0.5, -5e-324)),
        4602678819172646912ull,
        "add(0.5, -5e-324)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, 0.5, 5e-324)),
        4602678819172646912ull,
        "add(0.5, 5e-324)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, -0.5, -2.2250738585072014e-308)),
        13826050856027422720ull,
        "add(-0.5, -2.2250738585072014e-308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, -0.5, 2.2250738585072014e-308)),
        13826050856027422720ull,
        "add(-0.5, 2.2250738585072014e-308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, 0.5, -2.2250738585072014e-308)),
        4602678819172646912ull,
        "add(0.5, -2.2250738585072014e-308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, 0.5, 2.2250738585072014e-308)),
        4602678819172646912ull,
        "add(0.5, 2.2250738585072014e-308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, -0.5, -0.5)),
        13830554455654793216ull,
        "add(-0.5, -0.5)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, -0.5, 0.5)),
        0ull,
        "add(-0.5, 0.5)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, 0.5, -0.5)),
        0ull,
        "add(0.5, -0.5)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, 0.5, 0.5)),
        4607182418800017408ull,
        "add(0.5, 0.5)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, -0.5, -1.0)),
        13832806255468478464ull,
        "add(-0.5, -1.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, -0.5, 1.0)),
        4602678819172646912ull,
        "add(-0.5, 1.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, 0.5, -1.0)),
        13826050856027422720ull,
        "add(0.5, -1.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, 0.5, 1.0)),
        4609434218613702656ull,
        "add(0.5, 1.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, -0.5, -6.283185307179586)),
        13842695242987613464ull,
        "add(-0.5, -6.283185307179586)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, -0.5, 6.283185307179586)),
        4618197306225995032ull,
        "add(-0.5, 6.283185307179586)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, 0.5, -6.283185307179586)),
        13841569343080770840ull,
        "add(0.5, -6.283185307179586)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, 0.5, 6.283185307179586)),
        4619323206132837656ull,
        "add(0.5, 6.283185307179586)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, -0.5, -1.7976931348623157e+308)),
        18442240474082181119ull,
        "add(-0.5, -1.7976931348623157e+308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, -0.5, 1.7976931348623157e+308)),
        9218868437227405311ull,
        "add(-0.5, 1.7976931348623157e+308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, 0.5, -1.7976931348623157e+308)),
        18442240474082181119ull,
        "add(0.5, -1.7976931348623157e+308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, 0.5, 1.7976931348623157e+308)),
        9218868437227405311ull,
        "add(0.5, 1.7976931348623157e+308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, -0.5, -INFINITY)),
        18442240474082181120ull,
        "add(-0.5, -INFINITY)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, -0.5, INFINITY)),
        9218868437227405312ull,
        "add(-0.5, INFINITY)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, 0.5, -INFINITY)),
        18442240474082181120ull,
        "add(0.5, -INFINITY)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, 0.5, INFINITY)),
        9218868437227405312ull,
        "add(0.5, INFINITY)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, -0.5, f64_reinterpret_i64(0xfff8000000000000ull))) & 9223372036854775807ull),
        9221120237041090560ull,
        "add(-0.5, f64_reinterpret_i64(0xfff8000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, -0.5, f64_reinterpret_i64(0xfff4000000000000ull))) & 9221120237041090560ull),
        9221120237041090560ull,
        "add(-0.5, f64_reinterpret_i64(0xfff4000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, -0.5, f64_reinterpret_i64(0x7ff8000000000000ull))) & 9223372036854775807ull),
        9221120237041090560ull,
        "add(-0.5, f64_reinterpret_i64(0x7ff8000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, -0.5, f64_reinterpret_i64(0x7ff4000000000000ull))) & 9221120237041090560ull),
        9221120237041090560ull,
        "add(-0.5, f64_reinterpret_i64(0x7ff4000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, 0.5, f64_reinterpret_i64(0xfff8000000000000ull))) & 9223372036854775807ull),
        9221120237041090560ull,
        "add(0.5, f64_reinterpret_i64(0xfff8000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, 0.5, f64_reinterpret_i64(0xfff4000000000000ull))) & 9221120237041090560ull),
        9221120237041090560ull,
        "add(0.5, f64_reinterpret_i64(0xfff4000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, 0.5, f64_reinterpret_i64(0x7ff8000000000000ull))) & 9223372036854775807ull),
        9221120237041090560ull,
        "add(0.5, f64_reinterpret_i64(0x7ff8000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, 0.5, f64_reinterpret_i64(0x7ff4000000000000ull))) & 9221120237041090560ull),
        9221120237041090560ull,
        "add(0.5, f64_reinterpret_i64(0x7ff4000000000000ull))"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, -1.0, -0.0)),
        13830554455654793216ull,
        "add(-1.0, -0.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, -1.0, 0.0)),
        13830554455654793216ull,
        "add(-1.0, 0.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, 1.0, -0.0)),
        4607182418800017408ull,
        "add(1.0, -0.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, 1.0, 0.0)),
        4607182418800017408ull,
        "add(1.0, 0.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, -1.0, -5e-324)),
        13830554455654793216ull,
        "add(-1.0, -5e-324)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, -1.0, 5e-324)),
        13830554455654793216ull,
        "add(-1.0, 5e-324)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, 1.0, -5e-324)),
        4607182418800017408ull,
        "add(1.0, -5e-324)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, 1.0, 5e-324)),
        4607182418800017408ull,
        "add(1.0, 5e-324)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, -1.0, -2.2250738585072014e-308)),
        13830554455654793216ull,
        "add(-1.0, -2.2250738585072014e-308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, -1.0, 2.2250738585072014e-308)),
        13830554455654793216ull,
        "add(-1.0, 2.2250738585072014e-308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, 1.0, -2.2250738585072014e-308)),
        4607182418800017408ull,
        "add(1.0, -2.2250738585072014e-308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, 1.0, 2.2250738585072014e-308)),
        4607182418800017408ull,
        "add(1.0, 2.2250738585072014e-308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, -1.0, -0.5)),
        13832806255468478464ull,
        "add(-1.0, -0.5)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, -1.0, 0.5)),
        13826050856027422720ull,
        "add(-1.0, 0.5)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, 1.0, -0.5)),
        4602678819172646912ull,
        "add(1.0, -0.5)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, 1.0, 0.5)),
        4609434218613702656ull,
        "add(1.0, 0.5)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, -1.0, -1.0)),
        13835058055282163712ull,
        "add(-1.0, -1.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, -1.0, 1.0)),
        0ull,
        "add(-1.0, 1.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, 1.0, -1.0)),
        0ull,
        "add(1.0, -1.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, 1.0, 1.0)),
        4611686018427387904ull,
        "add(1.0, 1.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, -1.0, -6.283185307179586)),
        13843258192941034776ull,
        "add(-1.0, -6.283185307179586)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, -1.0, 6.283185307179586)),
        4617634356272573720ull,
        "add(-1.0, 6.283185307179586)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, 1.0, -6.283185307179586)),
        13841006393127349528ull,
        "add(1.0, -6.283185307179586)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, 1.0, 6.283185307179586)),
        4619886156086258968ull,
        "add(1.0, 6.283185307179586)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, -1.0, -1.7976931348623157e+308)),
        18442240474082181119ull,
        "add(-1.0, -1.7976931348623157e+308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, -1.0, 1.7976931348623157e+308)),
        9218868437227405311ull,
        "add(-1.0, 1.7976931348623157e+308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, 1.0, -1.7976931348623157e+308)),
        18442240474082181119ull,
        "add(1.0, -1.7976931348623157e+308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, 1.0, 1.7976931348623157e+308)),
        9218868437227405311ull,
        "add(1.0, 1.7976931348623157e+308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, -1.0, -INFINITY)),
        18442240474082181120ull,
        "add(-1.0, -INFINITY)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, -1.0, INFINITY)),
        9218868437227405312ull,
        "add(-1.0, INFINITY)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, 1.0, -INFINITY)),
        18442240474082181120ull,
        "add(1.0, -INFINITY)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, 1.0, INFINITY)),
        9218868437227405312ull,
        "add(1.0, INFINITY)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, -1.0, f64_reinterpret_i64(0xfff8000000000000ull))) & 9223372036854775807ull),
        9221120237041090560ull,
        "add(-1.0, f64_reinterpret_i64(0xfff8000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, -1.0, f64_reinterpret_i64(0xfff4000000000000ull))) & 9221120237041090560ull),
        9221120237041090560ull,
        "add(-1.0, f64_reinterpret_i64(0xfff4000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, -1.0, f64_reinterpret_i64(0x7ff8000000000000ull))) & 9223372036854775807ull),
        9221120237041090560ull,
        "add(-1.0, f64_reinterpret_i64(0x7ff8000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, -1.0, f64_reinterpret_i64(0x7ff4000000000000ull))) & 9221120237041090560ull),
        9221120237041090560ull,
        "add(-1.0, f64_reinterpret_i64(0x7ff4000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, 1.0, f64_reinterpret_i64(0xfff8000000000000ull))) & 9223372036854775807ull),
        9221120237041090560ull,
        "add(1.0, f64_reinterpret_i64(0xfff8000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, 1.0, f64_reinterpret_i64(0xfff4000000000000ull))) & 9221120237041090560ull),
        9221120237041090560ull,
        "add(1.0, f64_reinterpret_i64(0xfff4000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, 1.0, f64_reinterpret_i64(0x7ff8000000000000ull))) & 9223372036854775807ull),
        9221120237041090560ull,
        "add(1.0, f64_reinterpret_i64(0x7ff8000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, 1.0, f64_reinterpret_i64(0x7ff4000000000000ull))) & 9221120237041090560ull),
        9221120237041090560ull,
        "add(1.0, f64_reinterpret_i64(0x7ff4000000000000ull))"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, -6.283185307179586, -0.0)),
        13842132293034192152ull,
        "add(-6.283185307179586, -0.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, -6.283185307179586, 0.0)),
        13842132293034192152ull,
        "add(-6.283185307179586, 0.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, 6.283185307179586, -0.0)),
        4618760256179416344ull,
        "add(6.283185307179586, -0.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, 6.283185307179586, 0.0)),
        4618760256179416344ull,
        "add(6.283185307179586, 0.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, -6.283185307179586, -5e-324)),
        13842132293034192152ull,
        "add(-6.283185307179586, -5e-324)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, -6.283185307179586, 5e-324)),
        13842132293034192152ull,
        "add(-6.283185307179586, 5e-324)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, 6.283185307179586, -5e-324)),
        4618760256179416344ull,
        "add(6.283185307179586, -5e-324)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, 6.283185307179586, 5e-324)),
        4618760256179416344ull,
        "add(6.283185307179586, 5e-324)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, -6.283185307179586, -2.2250738585072014e-308)),
        13842132293034192152ull,
        "add(-6.283185307179586, -2.2250738585072014e-308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, -6.283185307179586, 2.2250738585072014e-308)),
        13842132293034192152ull,
        "add(-6.283185307179586, 2.2250738585072014e-308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, 6.283185307179586, -2.2250738585072014e-308)),
        4618760256179416344ull,
        "add(6.283185307179586, -2.2250738585072014e-308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, 6.283185307179586, 2.2250738585072014e-308)),
        4618760256179416344ull,
        "add(6.283185307179586, 2.2250738585072014e-308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, -6.283185307179586, -0.5)),
        13842695242987613464ull,
        "add(-6.283185307179586, -0.5)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, -6.283185307179586, 0.5)),
        13841569343080770840ull,
        "add(-6.283185307179586, 0.5)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, 6.283185307179586, -0.5)),
        4618197306225995032ull,
        "add(6.283185307179586, -0.5)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, 6.283185307179586, 0.5)),
        4619323206132837656ull,
        "add(6.283185307179586, 0.5)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, -6.283185307179586, -1.0)),
        13843258192941034776ull,
        "add(-6.283185307179586, -1.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, -6.283185307179586, 1.0)),
        13841006393127349528ull,
        "add(-6.283185307179586, 1.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, 6.283185307179586, -1.0)),
        4617634356272573720ull,
        "add(6.283185307179586, -1.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, 6.283185307179586, 1.0)),
        4619886156086258968ull,
        "add(6.283185307179586, 1.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, -6.283185307179586, -6.283185307179586)),
        13846635892661562648ull,
        "add(-6.283185307179586, -6.283185307179586)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, -6.283185307179586, 6.283185307179586)),
        0ull,
        "add(-6.283185307179586, 6.283185307179586)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, 6.283185307179586, -6.283185307179586)),
        0ull,
        "add(6.283185307179586, -6.283185307179586)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, 6.283185307179586, 6.283185307179586)),
        4623263855806786840ull,
        "add(6.283185307179586, 6.283185307179586)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, -6.283185307179586, -1.7976931348623157e+308)),
        18442240474082181119ull,
        "add(-6.283185307179586, -1.7976931348623157e+308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, -6.283185307179586, 1.7976931348623157e+308)),
        9218868437227405311ull,
        "add(-6.283185307179586, 1.7976931348623157e+308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, 6.283185307179586, -1.7976931348623157e+308)),
        18442240474082181119ull,
        "add(6.283185307179586, -1.7976931348623157e+308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, 6.283185307179586, 1.7976931348623157e+308)),
        9218868437227405311ull,
        "add(6.283185307179586, 1.7976931348623157e+308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, -6.283185307179586, -INFINITY)),
        18442240474082181120ull,
        "add(-6.283185307179586, -INFINITY)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, -6.283185307179586, INFINITY)),
        9218868437227405312ull,
        "add(-6.283185307179586, INFINITY)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, 6.283185307179586, -INFINITY)),
        18442240474082181120ull,
        "add(6.283185307179586, -INFINITY)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, 6.283185307179586, INFINITY)),
        9218868437227405312ull,
        "add(6.283185307179586, INFINITY)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, -6.283185307179586, f64_reinterpret_i64(0xfff8000000000000ull))) & 9223372036854775807ull),
        9221120237041090560ull,
        "add(-6.283185307179586, f64_reinterpret_i64(0xfff8000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, -6.283185307179586, f64_reinterpret_i64(0xfff4000000000000ull))) & 9221120237041090560ull),
        9221120237041090560ull,
        "add(-6.283185307179586, f64_reinterpret_i64(0xfff4000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, -6.283185307179586, f64_reinterpret_i64(0x7ff8000000000000ull))) & 9223372036854775807ull),
        9221120237041090560ull,
        "add(-6.283185307179586, f64_reinterpret_i64(0x7ff8000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, -6.283185307179586, f64_reinterpret_i64(0x7ff4000000000000ull))) & 9221120237041090560ull),
        9221120237041090560ull,
        "add(-6.283185307179586, f64_reinterpret_i64(0x7ff4000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, 6.283185307179586, f64_reinterpret_i64(0xfff8000000000000ull))) & 9223372036854775807ull),
        9221120237041090560ull,
        "add(6.283185307179586, f64_reinterpret_i64(0xfff8000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, 6.283185307179586, f64_reinterpret_i64(0xfff4000000000000ull))) & 9221120237041090560ull),
        9221120237041090560ull,
        "add(6.283185307179586, f64_reinterpret_i64(0xfff4000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, 6.283185307179586, f64_reinterpret_i64(0x7ff8000000000000ull))) & 9223372036854775807ull),
        9221120237041090560ull,
        "add(6.283185307179586, f64_reinterpret_i64(0x7ff8000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, 6.283185307179586, f64_reinterpret_i64(0x7ff4000000000000ull))) & 9221120237041090560ull),
        9221120237041090560ull,
        "add(6.283185307179586, f64_reinterpret_i64(0x7ff4000000000000ull))"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, -1.7976931348623157e+308, -0.0)),
        18442240474082181119ull,
        "add(-1.7976931348623157e+308, -0.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, -1.7976931348623157e+308, 0.0)),
        18442240474082181119ull,
        "add(-1.7976931348623157e+308, 0.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, 1.7976931348623157e+308, -0.0)),
        9218868437227405311ull,
        "add(1.7976931348623157e+308, -0.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, 1.7976931348623157e+308, 0.0)),
        9218868437227405311ull,
        "add(1.7976931348623157e+308, 0.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, -1.7976931348623157e+308, -5e-324)),
        18442240474082181119ull,
        "add(-1.7976931348623157e+308, -5e-324)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, -1.7976931348623157e+308, 5e-324)),
        18442240474082181119ull,
        "add(-1.7976931348623157e+308, 5e-324)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, 1.7976931348623157e+308, -5e-324)),
        9218868437227405311ull,
        "add(1.7976931348623157e+308, -5e-324)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, 1.7976931348623157e+308, 5e-324)),
        9218868437227405311ull,
        "add(1.7976931348623157e+308, 5e-324)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, -1.7976931348623157e+308, -2.2250738585072014e-308)),
        18442240474082181119ull,
        "add(-1.7976931348623157e+308, -2.2250738585072014e-308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, -1.7976931348623157e+308, 2.2250738585072014e-308)),
        18442240474082181119ull,
        "add(-1.7976931348623157e+308, 2.2250738585072014e-308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, 1.7976931348623157e+308, -2.2250738585072014e-308)),
        9218868437227405311ull,
        "add(1.7976931348623157e+308, -2.2250738585072014e-308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, 1.7976931348623157e+308, 2.2250738585072014e-308)),
        9218868437227405311ull,
        "add(1.7976931348623157e+308, 2.2250738585072014e-308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, -1.7976931348623157e+308, -0.5)),
        18442240474082181119ull,
        "add(-1.7976931348623157e+308, -0.5)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, -1.7976931348623157e+308, 0.5)),
        18442240474082181119ull,
        "add(-1.7976931348623157e+308, 0.5)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, 1.7976931348623157e+308, -0.5)),
        9218868437227405311ull,
        "add(1.7976931348623157e+308, -0.5)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, 1.7976931348623157e+308, 0.5)),
        9218868437227405311ull,
        "add(1.7976931348623157e+308, 0.5)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, -1.7976931348623157e+308, -1.0)),
        18442240474082181119ull,
        "add(-1.7976931348623157e+308, -1.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, -1.7976931348623157e+308, 1.0)),
        18442240474082181119ull,
        "add(-1.7976931348623157e+308, 1.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, 1.7976931348623157e+308, -1.0)),
        9218868437227405311ull,
        "add(1.7976931348623157e+308, -1.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, 1.7976931348623157e+308, 1.0)),
        9218868437227405311ull,
        "add(1.7976931348623157e+308, 1.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, -1.7976931348623157e+308, -6.283185307179586)),
        18442240474082181119ull,
        "add(-1.7976931348623157e+308, -6.283185307179586)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, -1.7976931348623157e+308, 6.283185307179586)),
        18442240474082181119ull,
        "add(-1.7976931348623157e+308, 6.283185307179586)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, 1.7976931348623157e+308, -6.283185307179586)),
        9218868437227405311ull,
        "add(1.7976931348623157e+308, -6.283185307179586)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, 1.7976931348623157e+308, 6.283185307179586)),
        9218868437227405311ull,
        "add(1.7976931348623157e+308, 6.283185307179586)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, -1.7976931348623157e+308, -1.7976931348623157e+308)),
        18442240474082181120ull,
        "add(-1.7976931348623157e+308, -1.7976931348623157e+308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, -1.7976931348623157e+308, 1.7976931348623157e+308)),
        0ull,
        "add(-1.7976931348623157e+308, 1.7976931348623157e+308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, 1.7976931348623157e+308, -1.7976931348623157e+308)),
        0ull,
        "add(1.7976931348623157e+308, -1.7976931348623157e+308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, 1.7976931348623157e+308, 1.7976931348623157e+308)),
        9218868437227405312ull,
        "add(1.7976931348623157e+308, 1.7976931348623157e+308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, -1.7976931348623157e+308, -INFINITY)),
        18442240474082181120ull,
        "add(-1.7976931348623157e+308, -INFINITY)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, -1.7976931348623157e+308, INFINITY)),
        9218868437227405312ull,
        "add(-1.7976931348623157e+308, INFINITY)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, 1.7976931348623157e+308, -INFINITY)),
        18442240474082181120ull,
        "add(1.7976931348623157e+308, -INFINITY)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, 1.7976931348623157e+308, INFINITY)),
        9218868437227405312ull,
        "add(1.7976931348623157e+308, INFINITY)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, -1.7976931348623157e+308, f64_reinterpret_i64(0xfff8000000000000ull))) & 9223372036854775807ull),
        9221120237041090560ull,
        "add(-1.7976931348623157e+308, f64_reinterpret_i64(0xfff8000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, -1.7976931348623157e+308, f64_reinterpret_i64(0xfff4000000000000ull))) & 9221120237041090560ull),
        9221120237041090560ull,
        "add(-1.7976931348623157e+308, f64_reinterpret_i64(0xfff4000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, -1.7976931348623157e+308, f64_reinterpret_i64(0x7ff8000000000000ull))) & 9223372036854775807ull),
        9221120237041090560ull,
        "add(-1.7976931348623157e+308, f64_reinterpret_i64(0x7ff8000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, -1.7976931348623157e+308, f64_reinterpret_i64(0x7ff4000000000000ull))) & 9221120237041090560ull),
        9221120237041090560ull,
        "add(-1.7976931348623157e+308, f64_reinterpret_i64(0x7ff4000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, 1.7976931348623157e+308, f64_reinterpret_i64(0xfff8000000000000ull))) & 9223372036854775807ull),
        9221120237041090560ull,
        "add(1.7976931348623157e+308, f64_reinterpret_i64(0xfff8000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, 1.7976931348623157e+308, f64_reinterpret_i64(0xfff4000000000000ull))) & 9221120237041090560ull),
        9221120237041090560ull,
        "add(1.7976931348623157e+308, f64_reinterpret_i64(0xfff4000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, 1.7976931348623157e+308, f64_reinterpret_i64(0x7ff8000000000000ull))) & 9223372036854775807ull),
        9221120237041090560ull,
        "add(1.7976931348623157e+308, f64_reinterpret_i64(0x7ff8000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, 1.7976931348623157e+308, f64_reinterpret_i64(0x7ff4000000000000ull))) & 9221120237041090560ull),
        9221120237041090560ull,
        "add(1.7976931348623157e+308, f64_reinterpret_i64(0x7ff4000000000000ull))"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, -INFINITY, -0.0)),
        18442240474082181120ull,
        "add(-INFINITY, -0.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, -INFINITY, 0.0)),
        18442240474082181120ull,
        "add(-INFINITY, 0.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, INFINITY, -0.0)),
        9218868437227405312ull,
        "add(INFINITY, -0.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, INFINITY, 0.0)),
        9218868437227405312ull,
        "add(INFINITY, 0.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, -INFINITY, -5e-324)),
        18442240474082181120ull,
        "add(-INFINITY, -5e-324)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, -INFINITY, 5e-324)),
        18442240474082181120ull,
        "add(-INFINITY, 5e-324)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, INFINITY, -5e-324)),
        9218868437227405312ull,
        "add(INFINITY, -5e-324)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, INFINITY, 5e-324)),
        9218868437227405312ull,
        "add(INFINITY, 5e-324)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, -INFINITY, -2.2250738585072014e-308)),
        18442240474082181120ull,
        "add(-INFINITY, -2.2250738585072014e-308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, -INFINITY, 2.2250738585072014e-308)),
        18442240474082181120ull,
        "add(-INFINITY, 2.2250738585072014e-308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, INFINITY, -2.2250738585072014e-308)),
        9218868437227405312ull,
        "add(INFINITY, -2.2250738585072014e-308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, INFINITY, 2.2250738585072014e-308)),
        9218868437227405312ull,
        "add(INFINITY, 2.2250738585072014e-308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, -INFINITY, -0.5)),
        18442240474082181120ull,
        "add(-INFINITY, -0.5)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, -INFINITY, 0.5)),
        18442240474082181120ull,
        "add(-INFINITY, 0.5)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, INFINITY, -0.5)),
        9218868437227405312ull,
        "add(INFINITY, -0.5)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, INFINITY, 0.5)),
        9218868437227405312ull,
        "add(INFINITY, 0.5)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, -INFINITY, -1.0)),
        18442240474082181120ull,
        "add(-INFINITY, -1.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, -INFINITY, 1.0)),
        18442240474082181120ull,
        "add(-INFINITY, 1.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, INFINITY, -1.0)),
        9218868437227405312ull,
        "add(INFINITY, -1.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, INFINITY, 1.0)),
        9218868437227405312ull,
        "add(INFINITY, 1.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, -INFINITY, -6.283185307179586)),
        18442240474082181120ull,
        "add(-INFINITY, -6.283185307179586)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, -INFINITY, 6.283185307179586)),
        18442240474082181120ull,
        "add(-INFINITY, 6.283185307179586)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, INFINITY, -6.283185307179586)),
        9218868437227405312ull,
        "add(INFINITY, -6.283185307179586)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, INFINITY, 6.283185307179586)),
        9218868437227405312ull,
        "add(INFINITY, 6.283185307179586)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, -INFINITY, -1.7976931348623157e+308)),
        18442240474082181120ull,
        "add(-INFINITY, -1.7976931348623157e+308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, -INFINITY, 1.7976931348623157e+308)),
        18442240474082181120ull,
        "add(-INFINITY, 1.7976931348623157e+308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, INFINITY, -1.7976931348623157e+308)),
        9218868437227405312ull,
        "add(INFINITY, -1.7976931348623157e+308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, INFINITY, 1.7976931348623157e+308)),
        9218868437227405312ull,
        "add(INFINITY, 1.7976931348623157e+308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, -INFINITY, -INFINITY)),
        18442240474082181120ull,
        "add(-INFINITY, -INFINITY)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, -INFINITY, INFINITY)) & 9223372036854775807ull),
        9221120237041090560ull,
        "add(-INFINITY, INFINITY)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, INFINITY, -INFINITY)) & 9223372036854775807ull),
        9221120237041090560ull,
        "add(INFINITY, -INFINITY)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, INFINITY, INFINITY)),
        9218868437227405312ull,
        "add(INFINITY, INFINITY)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, -INFINITY, f64_reinterpret_i64(0xfff8000000000000ull))) & 9223372036854775807ull),
        9221120237041090560ull,
        "add(-INFINITY, f64_reinterpret_i64(0xfff8000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, -INFINITY, f64_reinterpret_i64(0xfff4000000000000ull))) & 9221120237041090560ull),
        9221120237041090560ull,
        "add(-INFINITY, f64_reinterpret_i64(0xfff4000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, -INFINITY, f64_reinterpret_i64(0x7ff8000000000000ull))) & 9223372036854775807ull),
        9221120237041090560ull,
        "add(-INFINITY, f64_reinterpret_i64(0x7ff8000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, -INFINITY, f64_reinterpret_i64(0x7ff4000000000000ull))) & 9221120237041090560ull),
        9221120237041090560ull,
        "add(-INFINITY, f64_reinterpret_i64(0x7ff4000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, INFINITY, f64_reinterpret_i64(0xfff8000000000000ull))) & 9223372036854775807ull),
        9221120237041090560ull,
        "add(INFINITY, f64_reinterpret_i64(0xfff8000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, INFINITY, f64_reinterpret_i64(0xfff4000000000000ull))) & 9221120237041090560ull),
        9221120237041090560ull,
        "add(INFINITY, f64_reinterpret_i64(0xfff4000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, INFINITY, f64_reinterpret_i64(0x7ff8000000000000ull))) & 9223372036854775807ull),
        9221120237041090560ull,
        "add(INFINITY, f64_reinterpret_i64(0x7ff8000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, INFINITY, f64_reinterpret_i64(0x7ff4000000000000ull))) & 9221120237041090560ull),
        9221120237041090560ull,
        "add(INFINITY, f64_reinterpret_i64(0x7ff4000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, f64_reinterpret_i64(0xfff8000000000000ull), -0.0)) & 9223372036854775807ull),
        9221120237041090560ull,
        "add(f64_reinterpret_i64(0xfff8000000000000ull), -0.0)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, f64_reinterpret_i64(0xfff4000000000000ull), -0.0)) & 9221120237041090560ull),
        9221120237041090560ull,
        "add(f64_reinterpret_i64(0xfff4000000000000ull), -0.0)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, f64_reinterpret_i64(0xfff8000000000000ull), 0.0)) & 9223372036854775807ull),
        9221120237041090560ull,
        "add(f64_reinterpret_i64(0xfff8000000000000ull), 0.0)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, f64_reinterpret_i64(0xfff4000000000000ull), 0.0)) & 9221120237041090560ull),
        9221120237041090560ull,
        "add(f64_reinterpret_i64(0xfff4000000000000ull), 0.0)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, f64_reinterpret_i64(0x7ff8000000000000ull), -0.0)) & 9223372036854775807ull),
        9221120237041090560ull,
        "add(f64_reinterpret_i64(0x7ff8000000000000ull), -0.0)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, f64_reinterpret_i64(0x7ff4000000000000ull), -0.0)) & 9221120237041090560ull),
        9221120237041090560ull,
        "add(f64_reinterpret_i64(0x7ff4000000000000ull), -0.0)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, f64_reinterpret_i64(0x7ff8000000000000ull), 0.0)) & 9223372036854775807ull),
        9221120237041090560ull,
        "add(f64_reinterpret_i64(0x7ff8000000000000ull), 0.0)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, f64_reinterpret_i64(0x7ff4000000000000ull), 0.0)) & 9221120237041090560ull),
        9221120237041090560ull,
        "add(f64_reinterpret_i64(0x7ff4000000000000ull), 0.0)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, f64_reinterpret_i64(0xfff8000000000000ull), -5e-324)) & 9223372036854775807ull),
        9221120237041090560ull,
        "add(f64_reinterpret_i64(0xfff8000000000000ull), -5e-324)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, f64_reinterpret_i64(0xfff4000000000000ull), -5e-324)) & 9221120237041090560ull),
        9221120237041090560ull,
        "add(f64_reinterpret_i64(0xfff4000000000000ull), -5e-324)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, f64_reinterpret_i64(0xfff8000000000000ull), 5e-324)) & 9223372036854775807ull),
        9221120237041090560ull,
        "add(f64_reinterpret_i64(0xfff8000000000000ull), 5e-324)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, f64_reinterpret_i64(0xfff4000000000000ull), 5e-324)) & 9221120237041090560ull),
        9221120237041090560ull,
        "add(f64_reinterpret_i64(0xfff4000000000000ull), 5e-324)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, f64_reinterpret_i64(0x7ff8000000000000ull), -5e-324)) & 9223372036854775807ull),
        9221120237041090560ull,
        "add(f64_reinterpret_i64(0x7ff8000000000000ull), -5e-324)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, f64_reinterpret_i64(0x7ff4000000000000ull), -5e-324)) & 9221120237041090560ull),
        9221120237041090560ull,
        "add(f64_reinterpret_i64(0x7ff4000000000000ull), -5e-324)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, f64_reinterpret_i64(0x7ff8000000000000ull), 5e-324)) & 9223372036854775807ull),
        9221120237041090560ull,
        "add(f64_reinterpret_i64(0x7ff8000000000000ull), 5e-324)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, f64_reinterpret_i64(0x7ff4000000000000ull), 5e-324)) & 9221120237041090560ull),
        9221120237041090560ull,
        "add(f64_reinterpret_i64(0x7ff4000000000000ull), 5e-324)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, f64_reinterpret_i64(0xfff8000000000000ull), -2.2250738585072014e-308)) & 9223372036854775807ull),
        9221120237041090560ull,
        "add(f64_reinterpret_i64(0xfff8000000000000ull), -2.2250738585072014e-308)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, f64_reinterpret_i64(0xfff4000000000000ull), -2.2250738585072014e-308)) & 9221120237041090560ull),
        9221120237041090560ull,
        "add(f64_reinterpret_i64(0xfff4000000000000ull), -2.2250738585072014e-308)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, f64_reinterpret_i64(0xfff8000000000000ull), 2.2250738585072014e-308)) & 9223372036854775807ull),
        9221120237041090560ull,
        "add(f64_reinterpret_i64(0xfff8000000000000ull), 2.2250738585072014e-308)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, f64_reinterpret_i64(0xfff4000000000000ull), 2.2250738585072014e-308)) & 9221120237041090560ull),
        9221120237041090560ull,
        "add(f64_reinterpret_i64(0xfff4000000000000ull), 2.2250738585072014e-308)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, f64_reinterpret_i64(0x7ff8000000000000ull), -2.2250738585072014e-308)) & 9223372036854775807ull),
        9221120237041090560ull,
        "add(f64_reinterpret_i64(0x7ff8000000000000ull), -2.2250738585072014e-308)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, f64_reinterpret_i64(0x7ff4000000000000ull), -2.2250738585072014e-308)) & 9221120237041090560ull),
        9221120237041090560ull,
        "add(f64_reinterpret_i64(0x7ff4000000000000ull), -2.2250738585072014e-308)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, f64_reinterpret_i64(0x7ff8000000000000ull), 2.2250738585072014e-308)) & 9223372036854775807ull),
        9221120237041090560ull,
        "add(f64_reinterpret_i64(0x7ff8000000000000ull), 2.2250738585072014e-308)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, f64_reinterpret_i64(0x7ff4000000000000ull), 2.2250738585072014e-308)) & 9221120237041090560ull),
        9221120237041090560ull,
        "add(f64_reinterpret_i64(0x7ff4000000000000ull), 2.2250738585072014e-308)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, f64_reinterpret_i64(0xfff8000000000000ull), -0.5)) & 9223372036854775807ull),
        9221120237041090560ull,
        "add(f64_reinterpret_i64(0xfff8000000000000ull), -0.5)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, f64_reinterpret_i64(0xfff4000000000000ull), -0.5)) & 9221120237041090560ull),
        9221120237041090560ull,
        "add(f64_reinterpret_i64(0xfff4000000000000ull), -0.5)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, f64_reinterpret_i64(0xfff8000000000000ull), 0.5)) & 9223372036854775807ull),
        9221120237041090560ull,
        "add(f64_reinterpret_i64(0xfff8000000000000ull), 0.5)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, f64_reinterpret_i64(0xfff4000000000000ull), 0.5)) & 9221120237041090560ull),
        9221120237041090560ull,
        "add(f64_reinterpret_i64(0xfff4000000000000ull), 0.5)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, f64_reinterpret_i64(0x7ff8000000000000ull), -0.5)) & 9223372036854775807ull),
        9221120237041090560ull,
        "add(f64_reinterpret_i64(0x7ff8000000000000ull), -0.5)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, f64_reinterpret_i64(0x7ff4000000000000ull), -0.5)) & 9221120237041090560ull),
        9221120237041090560ull,
        "add(f64_reinterpret_i64(0x7ff4000000000000ull), -0.5)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, f64_reinterpret_i64(0x7ff8000000000000ull), 0.5)) & 9223372036854775807ull),
        9221120237041090560ull,
        "add(f64_reinterpret_i64(0x7ff8000000000000ull), 0.5)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, f64_reinterpret_i64(0x7ff4000000000000ull), 0.5)) & 9221120237041090560ull),
        9221120237041090560ull,
        "add(f64_reinterpret_i64(0x7ff4000000000000ull), 0.5)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, f64_reinterpret_i64(0xfff8000000000000ull), -1.0)) & 9223372036854775807ull),
        9221120237041090560ull,
        "add(f64_reinterpret_i64(0xfff8000000000000ull), -1.0)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, f64_reinterpret_i64(0xfff4000000000000ull), -1.0)) & 9221120237041090560ull),
        9221120237041090560ull,
        "add(f64_reinterpret_i64(0xfff4000000000000ull), -1.0)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, f64_reinterpret_i64(0xfff8000000000000ull), 1.0)) & 9223372036854775807ull),
        9221120237041090560ull,
        "add(f64_reinterpret_i64(0xfff8000000000000ull), 1.0)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, f64_reinterpret_i64(0xfff4000000000000ull), 1.0)) & 9221120237041090560ull),
        9221120237041090560ull,
        "add(f64_reinterpret_i64(0xfff4000000000000ull), 1.0)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, f64_reinterpret_i64(0x7ff8000000000000ull), -1.0)) & 9223372036854775807ull),
        9221120237041090560ull,
        "add(f64_reinterpret_i64(0x7ff8000000000000ull), -1.0)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, f64_reinterpret_i64(0x7ff4000000000000ull), -1.0)) & 9221120237041090560ull),
        9221120237041090560ull,
        "add(f64_reinterpret_i64(0x7ff4000000000000ull), -1.0)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, f64_reinterpret_i64(0x7ff8000000000000ull), 1.0)) & 9223372036854775807ull),
        9221120237041090560ull,
        "add(f64_reinterpret_i64(0x7ff8000000000000ull), 1.0)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, f64_reinterpret_i64(0x7ff4000000000000ull), 1.0)) & 9221120237041090560ull),
        9221120237041090560ull,
        "add(f64_reinterpret_i64(0x7ff4000000000000ull), 1.0)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, f64_reinterpret_i64(0xfff8000000000000ull), -6.283185307179586)) & 9223372036854775807ull),
        9221120237041090560ull,
        "add(f64_reinterpret_i64(0xfff8000000000000ull), -6.283185307179586)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, f64_reinterpret_i64(0xfff4000000000000ull), -6.283185307179586)) & 9221120237041090560ull),
        9221120237041090560ull,
        "add(f64_reinterpret_i64(0xfff4000000000000ull), -6.283185307179586)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, f64_reinterpret_i64(0xfff8000000000000ull), 6.283185307179586)) & 9223372036854775807ull),
        9221120237041090560ull,
        "add(f64_reinterpret_i64(0xfff8000000000000ull), 6.283185307179586)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, f64_reinterpret_i64(0xfff4000000000000ull), 6.283185307179586)) & 9221120237041090560ull),
        9221120237041090560ull,
        "add(f64_reinterpret_i64(0xfff4000000000000ull), 6.283185307179586)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, f64_reinterpret_i64(0x7ff8000000000000ull), -6.283185307179586)) & 9223372036854775807ull),
        9221120237041090560ull,
        "add(f64_reinterpret_i64(0x7ff8000000000000ull), -6.283185307179586)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, f64_reinterpret_i64(0x7ff4000000000000ull), -6.283185307179586)) & 9221120237041090560ull),
        9221120237041090560ull,
        "add(f64_reinterpret_i64(0x7ff4000000000000ull), -6.283185307179586)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, f64_reinterpret_i64(0x7ff8000000000000ull), 6.283185307179586)) & 9223372036854775807ull),
        9221120237041090560ull,
        "add(f64_reinterpret_i64(0x7ff8000000000000ull), 6.283185307179586)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, f64_reinterpret_i64(0x7ff4000000000000ull), 6.283185307179586)) & 9221120237041090560ull),
        9221120237041090560ull,
        "add(f64_reinterpret_i64(0x7ff4000000000000ull), 6.283185307179586)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, f64_reinterpret_i64(0xfff8000000000000ull), -1.7976931348623157e+308)) & 9223372036854775807ull),
        9221120237041090560ull,
        "add(f64_reinterpret_i64(0xfff8000000000000ull), -1.7976931348623157e+308)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, f64_reinterpret_i64(0xfff4000000000000ull), -1.7976931348623157e+308)) & 9221120237041090560ull),
        9221120237041090560ull,
        "add(f64_reinterpret_i64(0xfff4000000000000ull), -1.7976931348623157e+308)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, f64_reinterpret_i64(0xfff8000000000000ull), 1.7976931348623157e+308)) & 9223372036854775807ull),
        9221120237041090560ull,
        "add(f64_reinterpret_i64(0xfff8000000000000ull), 1.7976931348623157e+308)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, f64_reinterpret_i64(0xfff4000000000000ull), 1.7976931348623157e+308)) & 9221120237041090560ull),
        9221120237041090560ull,
        "add(f64_reinterpret_i64(0xfff4000000000000ull), 1.7976931348623157e+308)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, f64_reinterpret_i64(0x7ff8000000000000ull), -1.7976931348623157e+308)) & 9223372036854775807ull),
        9221120237041090560ull,
        "add(f64_reinterpret_i64(0x7ff8000000000000ull), -1.7976931348623157e+308)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, f64_reinterpret_i64(0x7ff4000000000000ull), -1.7976931348623157e+308)) & 9221120237041090560ull),
        9221120237041090560ull,
        "add(f64_reinterpret_i64(0x7ff4000000000000ull), -1.7976931348623157e+308)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, f64_reinterpret_i64(0x7ff8000000000000ull), 1.7976931348623157e+308)) & 9223372036854775807ull),
        9221120237041090560ull,
        "add(f64_reinterpret_i64(0x7ff8000000000000ull), 1.7976931348623157e+308)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, f64_reinterpret_i64(0x7ff4000000000000ull), 1.7976931348623157e+308)) & 9221120237041090560ull),
        9221120237041090560ull,
        "add(f64_reinterpret_i64(0x7ff4000000000000ull), 1.7976931348623157e+308)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, f64_reinterpret_i64(0xfff8000000000000ull), -INFINITY)) & 9223372036854775807ull),
        9221120237041090560ull,
        "add(f64_reinterpret_i64(0xfff8000000000000ull), -INFINITY)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, f64_reinterpret_i64(0xfff4000000000000ull), -INFINITY)) & 9221120237041090560ull),
        9221120237041090560ull,
        "add(f64_reinterpret_i64(0xfff4000000000000ull), -INFINITY)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, f64_reinterpret_i64(0xfff8000000000000ull), INFINITY)) & 9223372036854775807ull),
        9221120237041090560ull,
        "add(f64_reinterpret_i64(0xfff8000000000000ull), INFINITY)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, f64_reinterpret_i64(0xfff4000000000000ull), INFINITY)) & 9221120237041090560ull),
        9221120237041090560ull,
        "add(f64_reinterpret_i64(0xfff4000000000000ull), INFINITY)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, f64_reinterpret_i64(0x7ff8000000000000ull), -INFINITY)) & 9223372036854775807ull),
        9221120237041090560ull,
        "add(f64_reinterpret_i64(0x7ff8000000000000ull), -INFINITY)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, f64_reinterpret_i64(0x7ff4000000000000ull), -INFINITY)) & 9221120237041090560ull),
        9221120237041090560ull,
        "add(f64_reinterpret_i64(0x7ff4000000000000ull), -INFINITY)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, f64_reinterpret_i64(0x7ff8000000000000ull), INFINITY)) & 9223372036854775807ull),
        9221120237041090560ull,
        "add(f64_reinterpret_i64(0x7ff8000000000000ull), INFINITY)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, f64_reinterpret_i64(0x7ff4000000000000ull), INFINITY)) & 9221120237041090560ull),
        9221120237041090560ull,
        "add(f64_reinterpret_i64(0x7ff4000000000000ull), INFINITY)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, f64_reinterpret_i64(0xfff8000000000000ull), f64_reinterpret_i64(0xfff8000000000000ull))) & 9223372036854775807ull),
        9221120237041090560ull,
        "add(f64_reinterpret_i64(0xfff8000000000000ull), f64_reinterpret_i64(0xfff8000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, f64_reinterpret_i64(0xfff4000000000000ull), f64_reinterpret_i64(0xfff8000000000000ull))) & 9221120237041090560ull),
        9221120237041090560ull,
        "add(f64_reinterpret_i64(0xfff4000000000000ull), f64_reinterpret_i64(0xfff8000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, f64_reinterpret_i64(0xfff8000000000000ull), f64_reinterpret_i64(0xfff4000000000000ull))) & 9221120237041090560ull),
        9221120237041090560ull,
        "add(f64_reinterpret_i64(0xfff8000000000000ull), f64_reinterpret_i64(0xfff4000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, f64_reinterpret_i64(0xfff4000000000000ull), f64_reinterpret_i64(0xfff4000000000000ull))) & 9221120237041090560ull),
        9221120237041090560ull,
        "add(f64_reinterpret_i64(0xfff4000000000000ull), f64_reinterpret_i64(0xfff4000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, f64_reinterpret_i64(0xfff8000000000000ull), f64_reinterpret_i64(0x7ff8000000000000ull))) & 9223372036854775807ull),
        9221120237041090560ull,
        "add(f64_reinterpret_i64(0xfff8000000000000ull), f64_reinterpret_i64(0x7ff8000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, f64_reinterpret_i64(0xfff4000000000000ull), f64_reinterpret_i64(0x7ff8000000000000ull))) & 9221120237041090560ull),
        9221120237041090560ull,
        "add(f64_reinterpret_i64(0xfff4000000000000ull), f64_reinterpret_i64(0x7ff8000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, f64_reinterpret_i64(0xfff8000000000000ull), f64_reinterpret_i64(0x7ff4000000000000ull))) & 9221120237041090560ull),
        9221120237041090560ull,
        "add(f64_reinterpret_i64(0xfff8000000000000ull), f64_reinterpret_i64(0x7ff4000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, f64_reinterpret_i64(0xfff4000000000000ull), f64_reinterpret_i64(0x7ff4000000000000ull))) & 9221120237041090560ull),
        9221120237041090560ull,
        "add(f64_reinterpret_i64(0xfff4000000000000ull), f64_reinterpret_i64(0x7ff4000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, f64_reinterpret_i64(0x7ff8000000000000ull), f64_reinterpret_i64(0xfff8000000000000ull))) & 9223372036854775807ull),
        9221120237041090560ull,
        "add(f64_reinterpret_i64(0x7ff8000000000000ull), f64_reinterpret_i64(0xfff8000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, f64_reinterpret_i64(0x7ff4000000000000ull), f64_reinterpret_i64(0xfff8000000000000ull))) & 9221120237041090560ull),
        9221120237041090560ull,
        "add(f64_reinterpret_i64(0x7ff4000000000000ull), f64_reinterpret_i64(0xfff8000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, f64_reinterpret_i64(0x7ff8000000000000ull), f64_reinterpret_i64(0xfff4000000000000ull))) & 9221120237041090560ull),
        9221120237041090560ull,
        "add(f64_reinterpret_i64(0x7ff8000000000000ull), f64_reinterpret_i64(0xfff4000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, f64_reinterpret_i64(0x7ff4000000000000ull), f64_reinterpret_i64(0xfff4000000000000ull))) & 9221120237041090560ull),
        9221120237041090560ull,
        "add(f64_reinterpret_i64(0x7ff4000000000000ull), f64_reinterpret_i64(0xfff4000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, f64_reinterpret_i64(0x7ff8000000000000ull), f64_reinterpret_i64(0x7ff8000000000000ull))) & 9223372036854775807ull),
        9221120237041090560ull,
        "add(f64_reinterpret_i64(0x7ff8000000000000ull), f64_reinterpret_i64(0x7ff8000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, f64_reinterpret_i64(0x7ff4000000000000ull), f64_reinterpret_i64(0x7ff8000000000000ull))) & 9221120237041090560ull),
        9221120237041090560ull,
        "add(f64_reinterpret_i64(0x7ff4000000000000ull), f64_reinterpret_i64(0x7ff8000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, f64_reinterpret_i64(0x7ff8000000000000ull), f64_reinterpret_i64(0x7ff4000000000000ull))) & 9221120237041090560ull),
        9221120237041090560ull,
        "add(f64_reinterpret_i64(0x7ff8000000000000ull), f64_reinterpret_i64(0x7ff4000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_add(&instance, f64_reinterpret_i64(0x7ff4000000000000ull), f64_reinterpret_i64(0x7ff4000000000000ull))) & 9221120237041090560ull),
        9221120237041090560ull,
        "add(f64_reinterpret_i64(0x7ff4000000000000ull), f64_reinterpret_i64(0x7ff4000000000000ull))"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, -0.0, -0.0)),
        0ull,
        "sub(-0.0, -0.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, -0.0, 0.0)),
        9223372036854775808ull,
        "sub(-0.0, 0.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, 0.0, -0.0)),
        0ull,
        "sub(0.0, -0.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, 0.0, 0.0)),
        0ull,
        "sub(0.0, 0.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, -0.0, -5e-324)),
        1ull,
        "sub(-0.0, -5e-324)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, -0.0, 5e-324)),
        9223372036854775809ull,
        "sub(-0.0, 5e-324)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, 0.0, -5e-324)),
        1ull,
        "sub(0.0, -5e-324)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, 0.0, 5e-324)),
        9223372036854775809ull,
        "sub(0.0, 5e-324)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, -0.0, -2.2250738585072014e-308)),
        4503599627370496ull,
        "sub(-0.0, -2.2250738585072014e-308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, -0.0, 2.2250738585072014e-308)),
        9227875636482146304ull,
        "sub(-0.0, 2.2250738585072014e-308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, 0.0, -2.2250738585072014e-308)),
        4503599627370496ull,
        "sub(0.0, -2.2250738585072014e-308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, 0.0, 2.2250738585072014e-308)),
        9227875636482146304ull,
        "sub(0.0, 2.2250738585072014e-308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, -0.0, -0.5)),
        4602678819172646912ull,
        "sub(-0.0, -0.5)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, -0.0, 0.5)),
        13826050856027422720ull,
        "sub(-0.0, 0.5)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, 0.0, -0.5)),
        4602678819172646912ull,
        "sub(0.0, -0.5)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, 0.0, 0.5)),
        13826050856027422720ull,
        "sub(0.0, 0.5)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, -0.0, -1.0)),
        4607182418800017408ull,
        "sub(-0.0, -1.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, -0.0, 1.0)),
        13830554455654793216ull,
        "sub(-0.0, 1.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, 0.0, -1.0)),
        4607182418800017408ull,
        "sub(0.0, -1.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, 0.0, 1.0)),
        13830554455654793216ull,
        "sub(0.0, 1.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, -0.0, -6.283185307179586)),
        4618760256179416344ull,
        "sub(-0.0, -6.283185307179586)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, -0.0, 6.283185307179586)),
        13842132293034192152ull,
        "sub(-0.0, 6.283185307179586)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, 0.0, -6.283185307179586)),
        4618760256179416344ull,
        "sub(0.0, -6.283185307179586)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, 0.0, 6.283185307179586)),
        13842132293034192152ull,
        "sub(0.0, 6.283185307179586)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, -0.0, -1.7976931348623157e+308)),
        9218868437227405311ull,
        "sub(-0.0, -1.7976931348623157e+308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, -0.0, 1.7976931348623157e+308)),
        18442240474082181119ull,
        "sub(-0.0, 1.7976931348623157e+308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, 0.0, -1.7976931348623157e+308)),
        9218868437227405311ull,
        "sub(0.0, -1.7976931348623157e+308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, 0.0, 1.7976931348623157e+308)),
        18442240474082181119ull,
        "sub(0.0, 1.7976931348623157e+308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, -0.0, -INFINITY)),
        9218868437227405312ull,
        "sub(-0.0, -INFINITY)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, -0.0, INFINITY)),
        18442240474082181120ull,
        "sub(-0.0, INFINITY)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, 0.0, -INFINITY)),
        9218868437227405312ull,
        "sub(0.0, -INFINITY)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, 0.0, INFINITY)),
        18442240474082181120ull,
        "sub(0.0, INFINITY)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, -0.0, f64_reinterpret_i64(0xfff8000000000000ull))) & 9223372036854775807ull),
        9221120237041090560ull,
        "sub(-0.0, f64_reinterpret_i64(0xfff8000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, -0.0, f64_reinterpret_i64(0xfff4000000000000ull))) & 9221120237041090560ull),
        9221120237041090560ull,
        "sub(-0.0, f64_reinterpret_i64(0xfff4000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, -0.0, f64_reinterpret_i64(0x7ff8000000000000ull))) & 9223372036854775807ull),
        9221120237041090560ull,
        "sub(-0.0, f64_reinterpret_i64(0x7ff8000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, -0.0, f64_reinterpret_i64(0x7ff4000000000000ull))) & 9221120237041090560ull),
        9221120237041090560ull,
        "sub(-0.0, f64_reinterpret_i64(0x7ff4000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, 0.0, f64_reinterpret_i64(0xfff8000000000000ull))) & 9223372036854775807ull),
        9221120237041090560ull,
        "sub(0.0, f64_reinterpret_i64(0xfff8000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, 0.0, f64_reinterpret_i64(0xfff4000000000000ull))) & 9221120237041090560ull),
        9221120237041090560ull,
        "sub(0.0, f64_reinterpret_i64(0xfff4000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, 0.0, f64_reinterpret_i64(0x7ff8000000000000ull))) & 9223372036854775807ull),
        9221120237041090560ull,
        "sub(0.0, f64_reinterpret_i64(0x7ff8000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, 0.0, f64_reinterpret_i64(0x7ff4000000000000ull))) & 9221120237041090560ull),
        9221120237041090560ull,
        "sub(0.0, f64_reinterpret_i64(0x7ff4000000000000ull))"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, -5e-324, -0.0)),
        9223372036854775809ull,
        "sub(-5e-324, -0.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, -5e-324, 0.0)),
        9223372036854775809ull,
        "sub(-5e-324, 0.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, 5e-324, -0.0)),
        1ull,
        "sub(5e-324, -0.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, 5e-324, 0.0)),
        1ull,
        "sub(5e-324, 0.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, -5e-324, -5e-324)),
        0ull,
        "sub(-5e-324, -5e-324)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, -5e-324, 5e-324)),
        9223372036854775810ull,
        "sub(-5e-324, 5e-324)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, 5e-324, -5e-324)),
        2ull,
        "sub(5e-324, -5e-324)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, 5e-324, 5e-324)),
        0ull,
        "sub(5e-324, 5e-324)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, -5e-324, -2.2250738585072014e-308)),
        4503599627370495ull,
        "sub(-5e-324, -2.2250738585072014e-308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, -5e-324, 2.2250738585072014e-308)),
        9227875636482146305ull,
        "sub(-5e-324, 2.2250738585072014e-308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, 5e-324, -2.2250738585072014e-308)),
        4503599627370497ull,
        "sub(5e-324, -2.2250738585072014e-308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, 5e-324, 2.2250738585072014e-308)),
        9227875636482146303ull,
        "sub(5e-324, 2.2250738585072014e-308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, -5e-324, -0.5)),
        4602678819172646912ull,
        "sub(-5e-324, -0.5)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, -5e-324, 0.5)),
        13826050856027422720ull,
        "sub(-5e-324, 0.5)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, 5e-324, -0.5)),
        4602678819172646912ull,
        "sub(5e-324, -0.5)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, 5e-324, 0.5)),
        13826050856027422720ull,
        "sub(5e-324, 0.5)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, -5e-324, -1.0)),
        4607182418800017408ull,
        "sub(-5e-324, -1.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, -5e-324, 1.0)),
        13830554455654793216ull,
        "sub(-5e-324, 1.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, 5e-324, -1.0)),
        4607182418800017408ull,
        "sub(5e-324, -1.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, 5e-324, 1.0)),
        13830554455654793216ull,
        "sub(5e-324, 1.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, -5e-324, -6.283185307179586)),
        4618760256179416344ull,
        "sub(-5e-324, -6.283185307179586)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, -5e-324, 6.283185307179586)),
        13842132293034192152ull,
        "sub(-5e-324, 6.283185307179586)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, 5e-324, -6.283185307179586)),
        4618760256179416344ull,
        "sub(5e-324, -6.283185307179586)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, 5e-324, 6.283185307179586)),
        13842132293034192152ull,
        "sub(5e-324, 6.283185307179586)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, -5e-324, -1.7976931348623157e+308)),
        9218868437227405311ull,
        "sub(-5e-324, -1.7976931348623157e+308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, -5e-324, 1.7976931348623157e+308)),
        18442240474082181119ull,
        "sub(-5e-324, 1.7976931348623157e+308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, 5e-324, -1.7976931348623157e+308)),
        9218868437227405311ull,
        "sub(5e-324, -1.7976931348623157e+308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, 5e-324, 1.7976931348623157e+308)),
        18442240474082181119ull,
        "sub(5e-324, 1.7976931348623157e+308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, -5e-324, -INFINITY)),
        9218868437227405312ull,
        "sub(-5e-324, -INFINITY)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, -5e-324, INFINITY)),
        18442240474082181120ull,
        "sub(-5e-324, INFINITY)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, 5e-324, -INFINITY)),
        9218868437227405312ull,
        "sub(5e-324, -INFINITY)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, 5e-324, INFINITY)),
        18442240474082181120ull,
        "sub(5e-324, INFINITY)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, -5e-324, f64_reinterpret_i64(0xfff8000000000000ull))) & 9223372036854775807ull),
        9221120237041090560ull,
        "sub(-5e-324, f64_reinterpret_i64(0xfff8000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, -5e-324, f64_reinterpret_i64(0xfff4000000000000ull))) & 9221120237041090560ull),
        9221120237041090560ull,
        "sub(-5e-324, f64_reinterpret_i64(0xfff4000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, -5e-324, f64_reinterpret_i64(0x7ff8000000000000ull))) & 9223372036854775807ull),
        9221120237041090560ull,
        "sub(-5e-324, f64_reinterpret_i64(0x7ff8000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, -5e-324, f64_reinterpret_i64(0x7ff4000000000000ull))) & 9221120237041090560ull),
        9221120237041090560ull,
        "sub(-5e-324, f64_reinterpret_i64(0x7ff4000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, 5e-324, f64_reinterpret_i64(0xfff8000000000000ull))) & 9223372036854775807ull),
        9221120237041090560ull,
        "sub(5e-324, f64_reinterpret_i64(0xfff8000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, 5e-324, f64_reinterpret_i64(0xfff4000000000000ull))) & 9221120237041090560ull),
        9221120237041090560ull,
        "sub(5e-324, f64_reinterpret_i64(0xfff4000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, 5e-324, f64_reinterpret_i64(0x7ff8000000000000ull))) & 9223372036854775807ull),
        9221120237041090560ull,
        "sub(5e-324, f64_reinterpret_i64(0x7ff8000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, 5e-324, f64_reinterpret_i64(0x7ff4000000000000ull))) & 9221120237041090560ull),
        9221120237041090560ull,
        "sub(5e-324, f64_reinterpret_i64(0x7ff4000000000000ull))"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, -2.2250738585072014e-308, -0.0)),
        9227875636482146304ull,
        "sub(-2.2250738585072014e-308, -0.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, -2.2250738585072014e-308, 0.0)),
        9227875636482146304ull,
        "sub(-2.2250738585072014e-308, 0.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, 2.2250738585072014e-308, -0.0)),
        4503599627370496ull,
        "sub(2.2250738585072014e-308, -0.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, 2.2250738585072014e-308, 0.0)),
        4503599627370496ull,
        "sub(2.2250738585072014e-308, 0.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, -2.2250738585072014e-308, -5e-324)),
        9227875636482146303ull,
        "sub(-2.2250738585072014e-308, -5e-324)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, -2.2250738585072014e-308, 5e-324)),
        9227875636482146305ull,
        "sub(-2.2250738585072014e-308, 5e-324)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, 2.2250738585072014e-308, -5e-324)),
        4503599627370497ull,
        "sub(2.2250738585072014e-308, -5e-324)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, 2.2250738585072014e-308, 5e-324)),
        4503599627370495ull,
        "sub(2.2250738585072014e-308, 5e-324)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, -2.2250738585072014e-308, -2.2250738585072014e-308)),
        0ull,
        "sub(-2.2250738585072014e-308, -2.2250738585072014e-308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, -2.2250738585072014e-308, 2.2250738585072014e-308)),
        9232379236109516800ull,
        "sub(-2.2250738585072014e-308, 2.2250738585072014e-308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, 2.2250738585072014e-308, -2.2250738585072014e-308)),
        9007199254740992ull,
        "sub(2.2250738585072014e-308, -2.2250738585072014e-308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, 2.2250738585072014e-308, 2.2250738585072014e-308)),
        0ull,
        "sub(2.2250738585072014e-308, 2.2250738585072014e-308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, -2.2250738585072014e-308, -0.5)),
        4602678819172646912ull,
        "sub(-2.2250738585072014e-308, -0.5)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, -2.2250738585072014e-308, 0.5)),
        13826050856027422720ull,
        "sub(-2.2250738585072014e-308, 0.5)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, 2.2250738585072014e-308, -0.5)),
        4602678819172646912ull,
        "sub(2.2250738585072014e-308, -0.5)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, 2.2250738585072014e-308, 0.5)),
        13826050856027422720ull,
        "sub(2.2250738585072014e-308, 0.5)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, -2.2250738585072014e-308, -1.0)),
        4607182418800017408ull,
        "sub(-2.2250738585072014e-308, -1.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, -2.2250738585072014e-308, 1.0)),
        13830554455654793216ull,
        "sub(-2.2250738585072014e-308, 1.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, 2.2250738585072014e-308, -1.0)),
        4607182418800017408ull,
        "sub(2.2250738585072014e-308, -1.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, 2.2250738585072014e-308, 1.0)),
        13830554455654793216ull,
        "sub(2.2250738585072014e-308, 1.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, -2.2250738585072014e-308, -6.283185307179586)),
        4618760256179416344ull,
        "sub(-2.2250738585072014e-308, -6.283185307179586)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, -2.2250738585072014e-308, 6.283185307179586)),
        13842132293034192152ull,
        "sub(-2.2250738585072014e-308, 6.283185307179586)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, 2.2250738585072014e-308, -6.283185307179586)),
        4618760256179416344ull,
        "sub(2.2250738585072014e-308, -6.283185307179586)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, 2.2250738585072014e-308, 6.283185307179586)),
        13842132293034192152ull,
        "sub(2.2250738585072014e-308, 6.283185307179586)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, -2.2250738585072014e-308, -1.7976931348623157e+308)),
        9218868437227405311ull,
        "sub(-2.2250738585072014e-308, -1.7976931348623157e+308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, -2.2250738585072014e-308, 1.7976931348623157e+308)),
        18442240474082181119ull,
        "sub(-2.2250738585072014e-308, 1.7976931348623157e+308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, 2.2250738585072014e-308, -1.7976931348623157e+308)),
        9218868437227405311ull,
        "sub(2.2250738585072014e-308, -1.7976931348623157e+308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, 2.2250738585072014e-308, 1.7976931348623157e+308)),
        18442240474082181119ull,
        "sub(2.2250738585072014e-308, 1.7976931348623157e+308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, -2.2250738585072014e-308, -INFINITY)),
        9218868437227405312ull,
        "sub(-2.2250738585072014e-308, -INFINITY)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, -2.2250738585072014e-308, INFINITY)),
        18442240474082181120ull,
        "sub(-2.2250738585072014e-308, INFINITY)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, 2.2250738585072014e-308, -INFINITY)),
        9218868437227405312ull,
        "sub(2.2250738585072014e-308, -INFINITY)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, 2.2250738585072014e-308, INFINITY)),
        18442240474082181120ull,
        "sub(2.2250738585072014e-308, INFINITY)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, -2.2250738585072014e-308, f64_reinterpret_i64(0xfff8000000000000ull))) & 9223372036854775807ull),
        9221120237041090560ull,
        "sub(-2.2250738585072014e-308, f64_reinterpret_i64(0xfff8000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, -2.2250738585072014e-308, f64_reinterpret_i64(0xfff4000000000000ull))) & 9221120237041090560ull),
        9221120237041090560ull,
        "sub(-2.2250738585072014e-308, f64_reinterpret_i64(0xfff4000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, -2.2250738585072014e-308, f64_reinterpret_i64(0x7ff8000000000000ull))) & 9223372036854775807ull),
        9221120237041090560ull,
        "sub(-2.2250738585072014e-308, f64_reinterpret_i64(0x7ff8000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, -2.2250738585072014e-308, f64_reinterpret_i64(0x7ff4000000000000ull))) & 9221120237041090560ull),
        9221120237041090560ull,
        "sub(-2.2250738585072014e-308, f64_reinterpret_i64(0x7ff4000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, 2.2250738585072014e-308, f64_reinterpret_i64(0xfff8000000000000ull))) & 9223372036854775807ull),
        9221120237041090560ull,
        "sub(2.2250738585072014e-308, f64_reinterpret_i64(0xfff8000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, 2.2250738585072014e-308, f64_reinterpret_i64(0xfff4000000000000ull))) & 9221120237041090560ull),
        9221120237041090560ull,
        "sub(2.2250738585072014e-308, f64_reinterpret_i64(0xfff4000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, 2.2250738585072014e-308, f64_reinterpret_i64(0x7ff8000000000000ull))) & 9223372036854775807ull),
        9221120237041090560ull,
        "sub(2.2250738585072014e-308, f64_reinterpret_i64(0x7ff8000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, 2.2250738585072014e-308, f64_reinterpret_i64(0x7ff4000000000000ull))) & 9221120237041090560ull),
        9221120237041090560ull,
        "sub(2.2250738585072014e-308, f64_reinterpret_i64(0x7ff4000000000000ull))"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, -0.5, -0.0)),
        13826050856027422720ull,
        "sub(-0.5, -0.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, -0.5, 0.0)),
        13826050856027422720ull,
        "sub(-0.5, 0.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, 0.5, -0.0)),
        4602678819172646912ull,
        "sub(0.5, -0.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, 0.5, 0.0)),
        4602678819172646912ull,
        "sub(0.5, 0.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, -0.5, -5e-324)),
        13826050856027422720ull,
        "sub(-0.5, -5e-324)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, -0.5, 5e-324)),
        13826050856027422720ull,
        "sub(-0.5, 5e-324)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, 0.5, -5e-324)),
        4602678819172646912ull,
        "sub(0.5, -5e-324)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, 0.5, 5e-324)),
        4602678819172646912ull,
        "sub(0.5, 5e-324)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, -0.5, -2.2250738585072014e-308)),
        13826050856027422720ull,
        "sub(-0.5, -2.2250738585072014e-308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, -0.5, 2.2250738585072014e-308)),
        13826050856027422720ull,
        "sub(-0.5, 2.2250738585072014e-308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, 0.5, -2.2250738585072014e-308)),
        4602678819172646912ull,
        "sub(0.5, -2.2250738585072014e-308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, 0.5, 2.2250738585072014e-308)),
        4602678819172646912ull,
        "sub(0.5, 2.2250738585072014e-308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, -0.5, -0.5)),
        0ull,
        "sub(-0.5, -0.5)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, -0.5, 0.5)),
        13830554455654793216ull,
        "sub(-0.5, 0.5)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, 0.5, -0.5)),
        4607182418800017408ull,
        "sub(0.5, -0.5)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, 0.5, 0.5)),
        0ull,
        "sub(0.5, 0.5)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, -0.5, -1.0)),
        4602678819172646912ull,
        "sub(-0.5, -1.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, -0.5, 1.0)),
        13832806255468478464ull,
        "sub(-0.5, 1.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, 0.5, -1.0)),
        4609434218613702656ull,
        "sub(0.5, -1.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, 0.5, 1.0)),
        13826050856027422720ull,
        "sub(0.5, 1.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, -0.5, -6.283185307179586)),
        4618197306225995032ull,
        "sub(-0.5, -6.283185307179586)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, -0.5, 6.283185307179586)),
        13842695242987613464ull,
        "sub(-0.5, 6.283185307179586)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, 0.5, -6.283185307179586)),
        4619323206132837656ull,
        "sub(0.5, -6.283185307179586)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, 0.5, 6.283185307179586)),
        13841569343080770840ull,
        "sub(0.5, 6.283185307179586)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, -0.5, -1.7976931348623157e+308)),
        9218868437227405311ull,
        "sub(-0.5, -1.7976931348623157e+308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, -0.5, 1.7976931348623157e+308)),
        18442240474082181119ull,
        "sub(-0.5, 1.7976931348623157e+308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, 0.5, -1.7976931348623157e+308)),
        9218868437227405311ull,
        "sub(0.5, -1.7976931348623157e+308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, 0.5, 1.7976931348623157e+308)),
        18442240474082181119ull,
        "sub(0.5, 1.7976931348623157e+308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, -0.5, -INFINITY)),
        9218868437227405312ull,
        "sub(-0.5, -INFINITY)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, -0.5, INFINITY)),
        18442240474082181120ull,
        "sub(-0.5, INFINITY)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, 0.5, -INFINITY)),
        9218868437227405312ull,
        "sub(0.5, -INFINITY)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, 0.5, INFINITY)),
        18442240474082181120ull,
        "sub(0.5, INFINITY)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, -0.5, f64_reinterpret_i64(0xfff8000000000000ull))) & 9223372036854775807ull),
        9221120237041090560ull,
        "sub(-0.5, f64_reinterpret_i64(0xfff8000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, -0.5, f64_reinterpret_i64(0xfff4000000000000ull))) & 9221120237041090560ull),
        9221120237041090560ull,
        "sub(-0.5, f64_reinterpret_i64(0xfff4000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, -0.5, f64_reinterpret_i64(0x7ff8000000000000ull))) & 9223372036854775807ull),
        9221120237041090560ull,
        "sub(-0.5, f64_reinterpret_i64(0x7ff8000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, -0.5, f64_reinterpret_i64(0x7ff4000000000000ull))) & 9221120237041090560ull),
        9221120237041090560ull,
        "sub(-0.5, f64_reinterpret_i64(0x7ff4000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, 0.5, f64_reinterpret_i64(0xfff8000000000000ull))) & 9223372036854775807ull),
        9221120237041090560ull,
        "sub(0.5, f64_reinterpret_i64(0xfff8000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, 0.5, f64_reinterpret_i64(0xfff4000000000000ull))) & 9221120237041090560ull),
        9221120237041090560ull,
        "sub(0.5, f64_reinterpret_i64(0xfff4000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, 0.5, f64_reinterpret_i64(0x7ff8000000000000ull))) & 9223372036854775807ull),
        9221120237041090560ull,
        "sub(0.5, f64_reinterpret_i64(0x7ff8000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, 0.5, f64_reinterpret_i64(0x7ff4000000000000ull))) & 9221120237041090560ull),
        9221120237041090560ull,
        "sub(0.5, f64_reinterpret_i64(0x7ff4000000000000ull))"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, -1.0, -0.0)),
        13830554455654793216ull,
        "sub(-1.0, -0.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, -1.0, 0.0)),
        13830554455654793216ull,
        "sub(-1.0, 0.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, 1.0, -0.0)),
        4607182418800017408ull,
        "sub(1.0, -0.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, 1.0, 0.0)),
        4607182418800017408ull,
        "sub(1.0, 0.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, -1.0, -5e-324)),
        13830554455654793216ull,
        "sub(-1.0, -5e-324)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, -1.0, 5e-324)),
        13830554455654793216ull,
        "sub(-1.0, 5e-324)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, 1.0, -5e-324)),
        4607182418800017408ull,
        "sub(1.0, -5e-324)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, 1.0, 5e-324)),
        4607182418800017408ull,
        "sub(1.0, 5e-324)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, -1.0, -2.2250738585072014e-308)),
        13830554455654793216ull,
        "sub(-1.0, -2.2250738585072014e-308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, -1.0, 2.2250738585072014e-308)),
        13830554455654793216ull,
        "sub(-1.0, 2.2250738585072014e-308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, 1.0, -2.2250738585072014e-308)),
        4607182418800017408ull,
        "sub(1.0, -2.2250738585072014e-308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, 1.0, 2.2250738585072014e-308)),
        4607182418800017408ull,
        "sub(1.0, 2.2250738585072014e-308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, -1.0, -0.5)),
        13826050856027422720ull,
        "sub(-1.0, -0.5)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, -1.0, 0.5)),
        13832806255468478464ull,
        "sub(-1.0, 0.5)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, 1.0, -0.5)),
        4609434218613702656ull,
        "sub(1.0, -0.5)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, 1.0, 0.5)),
        4602678819172646912ull,
        "sub(1.0, 0.5)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, -1.0, -1.0)),
        0ull,
        "sub(-1.0, -1.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, -1.0, 1.0)),
        13835058055282163712ull,
        "sub(-1.0, 1.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, 1.0, -1.0)),
        4611686018427387904ull,
        "sub(1.0, -1.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, 1.0, 1.0)),
        0ull,
        "sub(1.0, 1.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, -1.0, -6.283185307179586)),
        4617634356272573720ull,
        "sub(-1.0, -6.283185307179586)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, -1.0, 6.283185307179586)),
        13843258192941034776ull,
        "sub(-1.0, 6.283185307179586)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, 1.0, -6.283185307179586)),
        4619886156086258968ull,
        "sub(1.0, -6.283185307179586)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, 1.0, 6.283185307179586)),
        13841006393127349528ull,
        "sub(1.0, 6.283185307179586)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, -1.0, -1.7976931348623157e+308)),
        9218868437227405311ull,
        "sub(-1.0, -1.7976931348623157e+308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, -1.0, 1.7976931348623157e+308)),
        18442240474082181119ull,
        "sub(-1.0, 1.7976931348623157e+308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, 1.0, -1.7976931348623157e+308)),
        9218868437227405311ull,
        "sub(1.0, -1.7976931348623157e+308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, 1.0, 1.7976931348623157e+308)),
        18442240474082181119ull,
        "sub(1.0, 1.7976931348623157e+308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, -1.0, -INFINITY)),
        9218868437227405312ull,
        "sub(-1.0, -INFINITY)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, -1.0, INFINITY)),
        18442240474082181120ull,
        "sub(-1.0, INFINITY)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, 1.0, -INFINITY)),
        9218868437227405312ull,
        "sub(1.0, -INFINITY)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, 1.0, INFINITY)),
        18442240474082181120ull,
        "sub(1.0, INFINITY)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, -1.0, f64_reinterpret_i64(0xfff8000000000000ull))) & 9223372036854775807ull),
        9221120237041090560ull,
        "sub(-1.0, f64_reinterpret_i64(0xfff8000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, -1.0, f64_reinterpret_i64(0xfff4000000000000ull))) & 9221120237041090560ull),
        9221120237041090560ull,
        "sub(-1.0, f64_reinterpret_i64(0xfff4000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, -1.0, f64_reinterpret_i64(0x7ff8000000000000ull))) & 9223372036854775807ull),
        9221120237041090560ull,
        "sub(-1.0, f64_reinterpret_i64(0x7ff8000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, -1.0, f64_reinterpret_i64(0x7ff4000000000000ull))) & 9221120237041090560ull),
        9221120237041090560ull,
        "sub(-1.0, f64_reinterpret_i64(0x7ff4000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, 1.0, f64_reinterpret_i64(0xfff8000000000000ull))) & 9223372036854775807ull),
        9221120237041090560ull,
        "sub(1.0, f64_reinterpret_i64(0xfff8000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, 1.0, f64_reinterpret_i64(0xfff4000000000000ull))) & 9221120237041090560ull),
        9221120237041090560ull,
        "sub(1.0, f64_reinterpret_i64(0xfff4000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, 1.0, f64_reinterpret_i64(0x7ff8000000000000ull))) & 9223372036854775807ull),
        9221120237041090560ull,
        "sub(1.0, f64_reinterpret_i64(0x7ff8000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, 1.0, f64_reinterpret_i64(0x7ff4000000000000ull))) & 9221120237041090560ull),
        9221120237041090560ull,
        "sub(1.0, f64_reinterpret_i64(0x7ff4000000000000ull))"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, -6.283185307179586, -0.0)),
        13842132293034192152ull,
        "sub(-6.283185307179586, -0.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, -6.283185307179586, 0.0)),
        13842132293034192152ull,
        "sub(-6.283185307179586, 0.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, 6.283185307179586, -0.0)),
        4618760256179416344ull,
        "sub(6.283185307179586, -0.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, 6.283185307179586, 0.0)),
        4618760256179416344ull,
        "sub(6.283185307179586, 0.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, -6.283185307179586, -5e-324)),
        13842132293034192152ull,
        "sub(-6.283185307179586, -5e-324)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, -6.283185307179586, 5e-324)),
        13842132293034192152ull,
        "sub(-6.283185307179586, 5e-324)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, 6.283185307179586, -5e-324)),
        4618760256179416344ull,
        "sub(6.283185307179586, -5e-324)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, 6.283185307179586, 5e-324)),
        4618760256179416344ull,
        "sub(6.283185307179586, 5e-324)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, -6.283185307179586, -2.2250738585072014e-308)),
        13842132293034192152ull,
        "sub(-6.283185307179586, -2.2250738585072014e-308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, -6.283185307179586, 2.2250738585072014e-308)),
        13842132293034192152ull,
        "sub(-6.283185307179586, 2.2250738585072014e-308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, 6.283185307179586, -2.2250738585072014e-308)),
        4618760256179416344ull,
        "sub(6.283185307179586, -2.2250738585072014e-308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, 6.283185307179586, 2.2250738585072014e-308)),
        4618760256179416344ull,
        "sub(6.283185307179586, 2.2250738585072014e-308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, -6.283185307179586, -0.5)),
        13841569343080770840ull,
        "sub(-6.283185307179586, -0.5)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, -6.283185307179586, 0.5)),
        13842695242987613464ull,
        "sub(-6.283185307179586, 0.5)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, 6.283185307179586, -0.5)),
        4619323206132837656ull,
        "sub(6.283185307179586, -0.5)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, 6.283185307179586, 0.5)),
        4618197306225995032ull,
        "sub(6.283185307179586, 0.5)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, -6.283185307179586, -1.0)),
        13841006393127349528ull,
        "sub(-6.283185307179586, -1.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, -6.283185307179586, 1.0)),
        13843258192941034776ull,
        "sub(-6.283185307179586, 1.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, 6.283185307179586, -1.0)),
        4619886156086258968ull,
        "sub(6.283185307179586, -1.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, 6.283185307179586, 1.0)),
        4617634356272573720ull,
        "sub(6.283185307179586, 1.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, -6.283185307179586, -6.283185307179586)),
        0ull,
        "sub(-6.283185307179586, -6.283185307179586)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, -6.283185307179586, 6.283185307179586)),
        13846635892661562648ull,
        "sub(-6.283185307179586, 6.283185307179586)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, 6.283185307179586, -6.283185307179586)),
        4623263855806786840ull,
        "sub(6.283185307179586, -6.283185307179586)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, 6.283185307179586, 6.283185307179586)),
        0ull,
        "sub(6.283185307179586, 6.283185307179586)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, -6.283185307179586, -1.7976931348623157e+308)),
        9218868437227405311ull,
        "sub(-6.283185307179586, -1.7976931348623157e+308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, -6.283185307179586, 1.7976931348623157e+308)),
        18442240474082181119ull,
        "sub(-6.283185307179586, 1.7976931348623157e+308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, 6.283185307179586, -1.7976931348623157e+308)),
        9218868437227405311ull,
        "sub(6.283185307179586, -1.7976931348623157e+308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, 6.283185307179586, 1.7976931348623157e+308)),
        18442240474082181119ull,
        "sub(6.283185307179586, 1.7976931348623157e+308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, -6.283185307179586, -INFINITY)),
        9218868437227405312ull,
        "sub(-6.283185307179586, -INFINITY)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, -6.283185307179586, INFINITY)),
        18442240474082181120ull,
        "sub(-6.283185307179586, INFINITY)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, 6.283185307179586, -INFINITY)),
        9218868437227405312ull,
        "sub(6.283185307179586, -INFINITY)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, 6.283185307179586, INFINITY)),
        18442240474082181120ull,
        "sub(6.283185307179586, INFINITY)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, -6.283185307179586, f64_reinterpret_i64(0xfff8000000000000ull))) & 9223372036854775807ull),
        9221120237041090560ull,
        "sub(-6.283185307179586, f64_reinterpret_i64(0xfff8000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, -6.283185307179586, f64_reinterpret_i64(0xfff4000000000000ull))) & 9221120237041090560ull),
        9221120237041090560ull,
        "sub(-6.283185307179586, f64_reinterpret_i64(0xfff4000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, -6.283185307179586, f64_reinterpret_i64(0x7ff8000000000000ull))) & 9223372036854775807ull),
        9221120237041090560ull,
        "sub(-6.283185307179586, f64_reinterpret_i64(0x7ff8000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, -6.283185307179586, f64_reinterpret_i64(0x7ff4000000000000ull))) & 9221120237041090560ull),
        9221120237041090560ull,
        "sub(-6.283185307179586, f64_reinterpret_i64(0x7ff4000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, 6.283185307179586, f64_reinterpret_i64(0xfff8000000000000ull))) & 9223372036854775807ull),
        9221120237041090560ull,
        "sub(6.283185307179586, f64_reinterpret_i64(0xfff8000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, 6.283185307179586, f64_reinterpret_i64(0xfff4000000000000ull))) & 9221120237041090560ull),
        9221120237041090560ull,
        "sub(6.283185307179586, f64_reinterpret_i64(0xfff4000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, 6.283185307179586, f64_reinterpret_i64(0x7ff8000000000000ull))) & 9223372036854775807ull),
        9221120237041090560ull,
        "sub(6.283185307179586, f64_reinterpret_i64(0x7ff8000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, 6.283185307179586, f64_reinterpret_i64(0x7ff4000000000000ull))) & 9221120237041090560ull),
        9221120237041090560ull,
        "sub(6.283185307179586, f64_reinterpret_i64(0x7ff4000000000000ull))"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, -1.7976931348623157e+308, -0.0)),
        18442240474082181119ull,
        "sub(-1.7976931348623157e+308, -0.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, -1.7976931348623157e+308, 0.0)),
        18442240474082181119ull,
        "sub(-1.7976931348623157e+308, 0.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, 1.7976931348623157e+308, -0.0)),
        9218868437227405311ull,
        "sub(1.7976931348623157e+308, -0.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, 1.7976931348623157e+308, 0.0)),
        9218868437227405311ull,
        "sub(1.7976931348623157e+308, 0.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, -1.7976931348623157e+308, -5e-324)),
        18442240474082181119ull,
        "sub(-1.7976931348623157e+308, -5e-324)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, -1.7976931348623157e+308, 5e-324)),
        18442240474082181119ull,
        "sub(-1.7976931348623157e+308, 5e-324)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, 1.7976931348623157e+308, -5e-324)),
        9218868437227405311ull,
        "sub(1.7976931348623157e+308, -5e-324)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, 1.7976931348623157e+308, 5e-324)),
        9218868437227405311ull,
        "sub(1.7976931348623157e+308, 5e-324)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, -1.7976931348623157e+308, -2.2250738585072014e-308)),
        18442240474082181119ull,
        "sub(-1.7976931348623157e+308, -2.2250738585072014e-308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, -1.7976931348623157e+308, 2.2250738585072014e-308)),
        18442240474082181119ull,
        "sub(-1.7976931348623157e+308, 2.2250738585072014e-308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, 1.7976931348623157e+308, -2.2250738585072014e-308)),
        9218868437227405311ull,
        "sub(1.7976931348623157e+308, -2.2250738585072014e-308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, 1.7976931348623157e+308, 2.2250738585072014e-308)),
        9218868437227405311ull,
        "sub(1.7976931348623157e+308, 2.2250738585072014e-308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, -1.7976931348623157e+308, -0.5)),
        18442240474082181119ull,
        "sub(-1.7976931348623157e+308, -0.5)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, -1.7976931348623157e+308, 0.5)),
        18442240474082181119ull,
        "sub(-1.7976931348623157e+308, 0.5)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, 1.7976931348623157e+308, -0.5)),
        9218868437227405311ull,
        "sub(1.7976931348623157e+308, -0.5)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, 1.7976931348623157e+308, 0.5)),
        9218868437227405311ull,
        "sub(1.7976931348623157e+308, 0.5)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, -1.7976931348623157e+308, -1.0)),
        18442240474082181119ull,
        "sub(-1.7976931348623157e+308, -1.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, -1.7976931348623157e+308, 1.0)),
        18442240474082181119ull,
        "sub(-1.7976931348623157e+308, 1.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, 1.7976931348623157e+308, -1.0)),
        9218868437227405311ull,
        "sub(1.7976931348623157e+308, -1.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, 1.7976931348623157e+308, 1.0)),
        9218868437227405311ull,
        "sub(1.7976931348623157e+308, 1.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, -1.7976931348623157e+308, -6.283185307179586)),
        18442240474082181119ull,
        "sub(-1.7976931348623157e+308, -6.283185307179586)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, -1.7976931348623157e+308, 6.283185307179586)),
        18442240474082181119ull,
        "sub(-1.7976931348623157e+308, 6.283185307179586)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, 1.7976931348623157e+308, -6.283185307179586)),
        9218868437227405311ull,
        "sub(1.7976931348623157e+308, -6.283185307179586)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, 1.7976931348623157e+308, 6.283185307179586)),
        9218868437227405311ull,
        "sub(1.7976931348623157e+308, 6.283185307179586)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, -1.7976931348623157e+308, -1.7976931348623157e+308)),
        0ull,
        "sub(-1.7976931348623157e+308, -1.7976931348623157e+308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, -1.7976931348623157e+308, 1.7976931348623157e+308)),
        18442240474082181120ull,
        "sub(-1.7976931348623157e+308, 1.7976931348623157e+308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, 1.7976931348623157e+308, -1.7976931348623157e+308)),
        9218868437227405312ull,
        "sub(1.7976931348623157e+308, -1.7976931348623157e+308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, 1.7976931348623157e+308, 1.7976931348623157e+308)),
        0ull,
        "sub(1.7976931348623157e+308, 1.7976931348623157e+308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, -1.7976931348623157e+308, -INFINITY)),
        9218868437227405312ull,
        "sub(-1.7976931348623157e+308, -INFINITY)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, -1.7976931348623157e+308, INFINITY)),
        18442240474082181120ull,
        "sub(-1.7976931348623157e+308, INFINITY)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, 1.7976931348623157e+308, -INFINITY)),
        9218868437227405312ull,
        "sub(1.7976931348623157e+308, -INFINITY)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, 1.7976931348623157e+308, INFINITY)),
        18442240474082181120ull,
        "sub(1.7976931348623157e+308, INFINITY)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, -1.7976931348623157e+308, f64_reinterpret_i64(0xfff8000000000000ull))) & 9223372036854775807ull),
        9221120237041090560ull,
        "sub(-1.7976931348623157e+308, f64_reinterpret_i64(0xfff8000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, -1.7976931348623157e+308, f64_reinterpret_i64(0xfff4000000000000ull))) & 9221120237041090560ull),
        9221120237041090560ull,
        "sub(-1.7976931348623157e+308, f64_reinterpret_i64(0xfff4000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, -1.7976931348623157e+308, f64_reinterpret_i64(0x7ff8000000000000ull))) & 9223372036854775807ull),
        9221120237041090560ull,
        "sub(-1.7976931348623157e+308, f64_reinterpret_i64(0x7ff8000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, -1.7976931348623157e+308, f64_reinterpret_i64(0x7ff4000000000000ull))) & 9221120237041090560ull),
        9221120237041090560ull,
        "sub(-1.7976931348623157e+308, f64_reinterpret_i64(0x7ff4000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, 1.7976931348623157e+308, f64_reinterpret_i64(0xfff8000000000000ull))) & 9223372036854775807ull),
        9221120237041090560ull,
        "sub(1.7976931348623157e+308, f64_reinterpret_i64(0xfff8000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, 1.7976931348623157e+308, f64_reinterpret_i64(0xfff4000000000000ull))) & 9221120237041090560ull),
        9221120237041090560ull,
        "sub(1.7976931348623157e+308, f64_reinterpret_i64(0xfff4000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, 1.7976931348623157e+308, f64_reinterpret_i64(0x7ff8000000000000ull))) & 9223372036854775807ull),
        9221120237041090560ull,
        "sub(1.7976931348623157e+308, f64_reinterpret_i64(0x7ff8000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, 1.7976931348623157e+308, f64_reinterpret_i64(0x7ff4000000000000ull))) & 9221120237041090560ull),
        9221120237041090560ull,
        "sub(1.7976931348623157e+308, f64_reinterpret_i64(0x7ff4000000000000ull))"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, -INFINITY, -0.0)),
        18442240474082181120ull,
        "sub(-INFINITY, -0.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, -INFINITY, 0.0)),
        18442240474082181120ull,
        "sub(-INFINITY, 0.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, INFINITY, -0.0)),
        9218868437227405312ull,
        "sub(INFINITY, -0.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, INFINITY, 0.0)),
        9218868437227405312ull,
        "sub(INFINITY, 0.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, -INFINITY, -5e-324)),
        18442240474082181120ull,
        "sub(-INFINITY, -5e-324)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, -INFINITY, 5e-324)),
        18442240474082181120ull,
        "sub(-INFINITY, 5e-324)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, INFINITY, -5e-324)),
        9218868437227405312ull,
        "sub(INFINITY, -5e-324)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, INFINITY, 5e-324)),
        9218868437227405312ull,
        "sub(INFINITY, 5e-324)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, -INFINITY, -2.2250738585072014e-308)),
        18442240474082181120ull,
        "sub(-INFINITY, -2.2250738585072014e-308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, -INFINITY, 2.2250738585072014e-308)),
        18442240474082181120ull,
        "sub(-INFINITY, 2.2250738585072014e-308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, INFINITY, -2.2250738585072014e-308)),
        9218868437227405312ull,
        "sub(INFINITY, -2.2250738585072014e-308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, INFINITY, 2.2250738585072014e-308)),
        9218868437227405312ull,
        "sub(INFINITY, 2.2250738585072014e-308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, -INFINITY, -0.5)),
        18442240474082181120ull,
        "sub(-INFINITY, -0.5)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, -INFINITY, 0.5)),
        18442240474082181120ull,
        "sub(-INFINITY, 0.5)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, INFINITY, -0.5)),
        9218868437227405312ull,
        "sub(INFINITY, -0.5)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, INFINITY, 0.5)),
        9218868437227405312ull,
        "sub(INFINITY, 0.5)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, -INFINITY, -1.0)),
        18442240474082181120ull,
        "sub(-INFINITY, -1.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, -INFINITY, 1.0)),
        18442240474082181120ull,
        "sub(-INFINITY, 1.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, INFINITY, -1.0)),
        9218868437227405312ull,
        "sub(INFINITY, -1.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, INFINITY, 1.0)),
        9218868437227405312ull,
        "sub(INFINITY, 1.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, -INFINITY, -6.283185307179586)),
        18442240474082181120ull,
        "sub(-INFINITY, -6.283185307179586)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, -INFINITY, 6.283185307179586)),
        18442240474082181120ull,
        "sub(-INFINITY, 6.283185307179586)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, INFINITY, -6.283185307179586)),
        9218868437227405312ull,
        "sub(INFINITY, -6.283185307179586)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, INFINITY, 6.283185307179586)),
        9218868437227405312ull,
        "sub(INFINITY, 6.283185307179586)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, -INFINITY, -1.7976931348623157e+308)),
        18442240474082181120ull,
        "sub(-INFINITY, -1.7976931348623157e+308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, -INFINITY, 1.7976931348623157e+308)),
        18442240474082181120ull,
        "sub(-INFINITY, 1.7976931348623157e+308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, INFINITY, -1.7976931348623157e+308)),
        9218868437227405312ull,
        "sub(INFINITY, -1.7976931348623157e+308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, INFINITY, 1.7976931348623157e+308)),
        9218868437227405312ull,
        "sub(INFINITY, 1.7976931348623157e+308)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, -INFINITY, -INFINITY)) & 9223372036854775807ull),
        9221120237041090560ull,
        "sub(-INFINITY, -INFINITY)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, -INFINITY, INFINITY)),
        18442240474082181120ull,
        "sub(-INFINITY, INFINITY)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, INFINITY, -INFINITY)),
        9218868437227405312ull,
        "sub(INFINITY, -INFINITY)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, INFINITY, INFINITY)) & 9223372036854775807ull),
        9221120237041090560ull,
        "sub(INFINITY, INFINITY)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, -INFINITY, f64_reinterpret_i64(0xfff8000000000000ull))) & 9223372036854775807ull),
        9221120237041090560ull,
        "sub(-INFINITY, f64_reinterpret_i64(0xfff8000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, -INFINITY, f64_reinterpret_i64(0xfff4000000000000ull))) & 9221120237041090560ull),
        9221120237041090560ull,
        "sub(-INFINITY, f64_reinterpret_i64(0xfff4000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, -INFINITY, f64_reinterpret_i64(0x7ff8000000000000ull))) & 9223372036854775807ull),
        9221120237041090560ull,
        "sub(-INFINITY, f64_reinterpret_i64(0x7ff8000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, -INFINITY, f64_reinterpret_i64(0x7ff4000000000000ull))) & 9221120237041090560ull),
        9221120237041090560ull,
        "sub(-INFINITY, f64_reinterpret_i64(0x7ff4000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, INFINITY, f64_reinterpret_i64(0xfff8000000000000ull))) & 9223372036854775807ull),
        9221120237041090560ull,
        "sub(INFINITY, f64_reinterpret_i64(0xfff8000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, INFINITY, f64_reinterpret_i64(0xfff4000000000000ull))) & 9221120237041090560ull),
        9221120237041090560ull,
        "sub(INFINITY, f64_reinterpret_i64(0xfff4000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, INFINITY, f64_reinterpret_i64(0x7ff8000000000000ull))) & 9223372036854775807ull),
        9221120237041090560ull,
        "sub(INFINITY, f64_reinterpret_i64(0x7ff8000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, INFINITY, f64_reinterpret_i64(0x7ff4000000000000ull))) & 9221120237041090560ull),
        9221120237041090560ull,
        "sub(INFINITY, f64_reinterpret_i64(0x7ff4000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, f64_reinterpret_i64(0xfff8000000000000ull), -0.0)) & 9223372036854775807ull),
        9221120237041090560ull,
        "sub(f64_reinterpret_i64(0xfff8000000000000ull), -0.0)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, f64_reinterpret_i64(0xfff4000000000000ull), -0.0)) & 9221120237041090560ull),
        9221120237041090560ull,
        "sub(f64_reinterpret_i64(0xfff4000000000000ull), -0.0)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, f64_reinterpret_i64(0xfff8000000000000ull), 0.0)) & 9223372036854775807ull),
        9221120237041090560ull,
        "sub(f64_reinterpret_i64(0xfff8000000000000ull), 0.0)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, f64_reinterpret_i64(0xfff4000000000000ull), 0.0)) & 9221120237041090560ull),
        9221120237041090560ull,
        "sub(f64_reinterpret_i64(0xfff4000000000000ull), 0.0)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, f64_reinterpret_i64(0x7ff8000000000000ull), -0.0)) & 9223372036854775807ull),
        9221120237041090560ull,
        "sub(f64_reinterpret_i64(0x7ff8000000000000ull), -0.0)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, f64_reinterpret_i64(0x7ff4000000000000ull), -0.0)) & 9221120237041090560ull),
        9221120237041090560ull,
        "sub(f64_reinterpret_i64(0x7ff4000000000000ull), -0.0)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, f64_reinterpret_i64(0x7ff8000000000000ull), 0.0)) & 9223372036854775807ull),
        9221120237041090560ull,
        "sub(f64_reinterpret_i64(0x7ff8000000000000ull), 0.0)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, f64_reinterpret_i64(0x7ff4000000000000ull), 0.0)) & 9221120237041090560ull),
        9221120237041090560ull,
        "sub(f64_reinterpret_i64(0x7ff4000000000000ull), 0.0)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, f64_reinterpret_i64(0xfff8000000000000ull), -5e-324)) & 9223372036854775807ull),
        9221120237041090560ull,
        "sub(f64_reinterpret_i64(0xfff8000000000000ull), -5e-324)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, f64_reinterpret_i64(0xfff4000000000000ull), -5e-324)) & 9221120237041090560ull),
        9221120237041090560ull,
        "sub(f64_reinterpret_i64(0xfff4000000000000ull), -5e-324)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, f64_reinterpret_i64(0xfff8000000000000ull), 5e-324)) & 9223372036854775807ull),
        9221120237041090560ull,
        "sub(f64_reinterpret_i64(0xfff8000000000000ull), 5e-324)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, f64_reinterpret_i64(0xfff4000000000000ull), 5e-324)) & 9221120237041090560ull),
        9221120237041090560ull,
        "sub(f64_reinterpret_i64(0xfff4000000000000ull), 5e-324)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, f64_reinterpret_i64(0x7ff8000000000000ull), -5e-324)) & 9223372036854775807ull),
        9221120237041090560ull,
        "sub(f64_reinterpret_i64(0x7ff8000000000000ull), -5e-324)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, f64_reinterpret_i64(0x7ff4000000000000ull), -5e-324)) & 9221120237041090560ull),
        9221120237041090560ull,
        "sub(f64_reinterpret_i64(0x7ff4000000000000ull), -5e-324)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, f64_reinterpret_i64(0x7ff8000000000000ull), 5e-324)) & 9223372036854775807ull),
        9221120237041090560ull,
        "sub(f64_reinterpret_i64(0x7ff8000000000000ull), 5e-324)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, f64_reinterpret_i64(0x7ff4000000000000ull), 5e-324)) & 9221120237041090560ull),
        9221120237041090560ull,
        "sub(f64_reinterpret_i64(0x7ff4000000000000ull), 5e-324)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, f64_reinterpret_i64(0xfff8000000000000ull), -2.2250738585072014e-308)) & 9223372036854775807ull),
        9221120237041090560ull,
        "sub(f64_reinterpret_i64(0xfff8000000000000ull), -2.2250738585072014e-308)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, f64_reinterpret_i64(0xfff4000000000000ull), -2.2250738585072014e-308)) & 9221120237041090560ull),
        9221120237041090560ull,
        "sub(f64_reinterpret_i64(0xfff4000000000000ull), -2.2250738585072014e-308)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, f64_reinterpret_i64(0xfff8000000000000ull), 2.2250738585072014e-308)) & 9223372036854775807ull),
        9221120237041090560ull,
        "sub(f64_reinterpret_i64(0xfff8000000000000ull), 2.2250738585072014e-308)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, f64_reinterpret_i64(0xfff4000000000000ull), 2.2250738585072014e-308)) & 9221120237041090560ull),
        9221120237041090560ull,
        "sub(f64_reinterpret_i64(0xfff4000000000000ull), 2.2250738585072014e-308)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, f64_reinterpret_i64(0x7ff8000000000000ull), -2.2250738585072014e-308)) & 9223372036854775807ull),
        9221120237041090560ull,
        "sub(f64_reinterpret_i64(0x7ff8000000000000ull), -2.2250738585072014e-308)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, f64_reinterpret_i64(0x7ff4000000000000ull), -2.2250738585072014e-308)) & 9221120237041090560ull),
        9221120237041090560ull,
        "sub(f64_reinterpret_i64(0x7ff4000000000000ull), -2.2250738585072014e-308)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, f64_reinterpret_i64(0x7ff8000000000000ull), 2.2250738585072014e-308)) & 9223372036854775807ull),
        9221120237041090560ull,
        "sub(f64_reinterpret_i64(0x7ff8000000000000ull), 2.2250738585072014e-308)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, f64_reinterpret_i64(0x7ff4000000000000ull), 2.2250738585072014e-308)) & 9221120237041090560ull),
        9221120237041090560ull,
        "sub(f64_reinterpret_i64(0x7ff4000000000000ull), 2.2250738585072014e-308)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, f64_reinterpret_i64(0xfff8000000000000ull), -0.5)) & 9223372036854775807ull),
        9221120237041090560ull,
        "sub(f64_reinterpret_i64(0xfff8000000000000ull), -0.5)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, f64_reinterpret_i64(0xfff4000000000000ull), -0.5)) & 9221120237041090560ull),
        9221120237041090560ull,
        "sub(f64_reinterpret_i64(0xfff4000000000000ull), -0.5)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, f64_reinterpret_i64(0xfff8000000000000ull), 0.5)) & 9223372036854775807ull),
        9221120237041090560ull,
        "sub(f64_reinterpret_i64(0xfff8000000000000ull), 0.5)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, f64_reinterpret_i64(0xfff4000000000000ull), 0.5)) & 9221120237041090560ull),
        9221120237041090560ull,
        "sub(f64_reinterpret_i64(0xfff4000000000000ull), 0.5)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, f64_reinterpret_i64(0x7ff8000000000000ull), -0.5)) & 9223372036854775807ull),
        9221120237041090560ull,
        "sub(f64_reinterpret_i64(0x7ff8000000000000ull), -0.5)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, f64_reinterpret_i64(0x7ff4000000000000ull), -0.5)) & 9221120237041090560ull),
        9221120237041090560ull,
        "sub(f64_reinterpret_i64(0x7ff4000000000000ull), -0.5)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, f64_reinterpret_i64(0x7ff8000000000000ull), 0.5)) & 9223372036854775807ull),
        9221120237041090560ull,
        "sub(f64_reinterpret_i64(0x7ff8000000000000ull), 0.5)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, f64_reinterpret_i64(0x7ff4000000000000ull), 0.5)) & 9221120237041090560ull),
        9221120237041090560ull,
        "sub(f64_reinterpret_i64(0x7ff4000000000000ull), 0.5)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, f64_reinterpret_i64(0xfff8000000000000ull), -1.0)) & 9223372036854775807ull),
        9221120237041090560ull,
        "sub(f64_reinterpret_i64(0xfff8000000000000ull), -1.0)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, f64_reinterpret_i64(0xfff4000000000000ull), -1.0)) & 9221120237041090560ull),
        9221120237041090560ull,
        "sub(f64_reinterpret_i64(0xfff4000000000000ull), -1.0)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, f64_reinterpret_i64(0xfff8000000000000ull), 1.0)) & 9223372036854775807ull),
        9221120237041090560ull,
        "sub(f64_reinterpret_i64(0xfff8000000000000ull), 1.0)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, f64_reinterpret_i64(0xfff4000000000000ull), 1.0)) & 9221120237041090560ull),
        9221120237041090560ull,
        "sub(f64_reinterpret_i64(0xfff4000000000000ull), 1.0)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, f64_reinterpret_i64(0x7ff8000000000000ull), -1.0)) & 9223372036854775807ull),
        9221120237041090560ull,
        "sub(f64_reinterpret_i64(0x7ff8000000000000ull), -1.0)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, f64_reinterpret_i64(0x7ff4000000000000ull), -1.0)) & 9221120237041090560ull),
        9221120237041090560ull,
        "sub(f64_reinterpret_i64(0x7ff4000000000000ull), -1.0)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, f64_reinterpret_i64(0x7ff8000000000000ull), 1.0)) & 9223372036854775807ull),
        9221120237041090560ull,
        "sub(f64_reinterpret_i64(0x7ff8000000000000ull), 1.0)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, f64_reinterpret_i64(0x7ff4000000000000ull), 1.0)) & 9221120237041090560ull),
        9221120237041090560ull,
        "sub(f64_reinterpret_i64(0x7ff4000000000000ull), 1.0)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, f64_reinterpret_i64(0xfff8000000000000ull), -6.283185307179586)) & 9223372036854775807ull),
        9221120237041090560ull,
        "sub(f64_reinterpret_i64(0xfff8000000000000ull), -6.283185307179586)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, f64_reinterpret_i64(0xfff4000000000000ull), -6.283185307179586)) & 9221120237041090560ull),
        9221120237041090560ull,
        "sub(f64_reinterpret_i64(0xfff4000000000000ull), -6.283185307179586)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, f64_reinterpret_i64(0xfff8000000000000ull), 6.283185307179586)) & 9223372036854775807ull),
        9221120237041090560ull,
        "sub(f64_reinterpret_i64(0xfff8000000000000ull), 6.283185307179586)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, f64_reinterpret_i64(0xfff4000000000000ull), 6.283185307179586)) & 9221120237041090560ull),
        9221120237041090560ull,
        "sub(f64_reinterpret_i64(0xfff4000000000000ull), 6.283185307179586)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, f64_reinterpret_i64(0x7ff8000000000000ull), -6.283185307179586)) & 9223372036854775807ull),
        9221120237041090560ull,
        "sub(f64_reinterpret_i64(0x7ff8000000000000ull), -6.283185307179586)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, f64_reinterpret_i64(0x7ff4000000000000ull), -6.283185307179586)) & 9221120237041090560ull),
        9221120237041090560ull,
        "sub(f64_reinterpret_i64(0x7ff4000000000000ull), -6.283185307179586)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, f64_reinterpret_i64(0x7ff8000000000000ull), 6.283185307179586)) & 9223372036854775807ull),
        9221120237041090560ull,
        "sub(f64_reinterpret_i64(0x7ff8000000000000ull), 6.283185307179586)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, f64_reinterpret_i64(0x7ff4000000000000ull), 6.283185307179586)) & 9221120237041090560ull),
        9221120237041090560ull,
        "sub(f64_reinterpret_i64(0x7ff4000000000000ull), 6.283185307179586)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, f64_reinterpret_i64(0xfff8000000000000ull), -1.7976931348623157e+308)) & 9223372036854775807ull),
        9221120237041090560ull,
        "sub(f64_reinterpret_i64(0xfff8000000000000ull), -1.7976931348623157e+308)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, f64_reinterpret_i64(0xfff4000000000000ull), -1.7976931348623157e+308)) & 9221120237041090560ull),
        9221120237041090560ull,
        "sub(f64_reinterpret_i64(0xfff4000000000000ull), -1.7976931348623157e+308)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, f64_reinterpret_i64(0xfff8000000000000ull), 1.7976931348623157e+308)) & 9223372036854775807ull),
        9221120237041090560ull,
        "sub(f64_reinterpret_i64(0xfff8000000000000ull), 1.7976931348623157e+308)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, f64_reinterpret_i64(0xfff4000000000000ull), 1.7976931348623157e+308)) & 9221120237041090560ull),
        9221120237041090560ull,
        "sub(f64_reinterpret_i64(0xfff4000000000000ull), 1.7976931348623157e+308)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, f64_reinterpret_i64(0x7ff8000000000000ull), -1.7976931348623157e+308)) & 9223372036854775807ull),
        9221120237041090560ull,
        "sub(f64_reinterpret_i64(0x7ff8000000000000ull), -1.7976931348623157e+308)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, f64_reinterpret_i64(0x7ff4000000000000ull), -1.7976931348623157e+308)) & 9221120237041090560ull),
        9221120237041090560ull,
        "sub(f64_reinterpret_i64(0x7ff4000000000000ull), -1.7976931348623157e+308)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, f64_reinterpret_i64(0x7ff8000000000000ull), 1.7976931348623157e+308)) & 9223372036854775807ull),
        9221120237041090560ull,
        "sub(f64_reinterpret_i64(0x7ff8000000000000ull), 1.7976931348623157e+308)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, f64_reinterpret_i64(0x7ff4000000000000ull), 1.7976931348623157e+308)) & 9221120237041090560ull),
        9221120237041090560ull,
        "sub(f64_reinterpret_i64(0x7ff4000000000000ull), 1.7976931348623157e+308)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, f64_reinterpret_i64(0xfff8000000000000ull), -INFINITY)) & 9223372036854775807ull),
        9221120237041090560ull,
        "sub(f64_reinterpret_i64(0xfff8000000000000ull), -INFINITY)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, f64_reinterpret_i64(0xfff4000000000000ull), -INFINITY)) & 9221120237041090560ull),
        9221120237041090560ull,
        "sub(f64_reinterpret_i64(0xfff4000000000000ull), -INFINITY)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, f64_reinterpret_i64(0xfff8000000000000ull), INFINITY)) & 9223372036854775807ull),
        9221120237041090560ull,
        "sub(f64_reinterpret_i64(0xfff8000000000000ull), INFINITY)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, f64_reinterpret_i64(0xfff4000000000000ull), INFINITY)) & 9221120237041090560ull),
        9221120237041090560ull,
        "sub(f64_reinterpret_i64(0xfff4000000000000ull), INFINITY)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, f64_reinterpret_i64(0x7ff8000000000000ull), -INFINITY)) & 9223372036854775807ull),
        9221120237041090560ull,
        "sub(f64_reinterpret_i64(0x7ff8000000000000ull), -INFINITY)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, f64_reinterpret_i64(0x7ff4000000000000ull), -INFINITY)) & 9221120237041090560ull),
        9221120237041090560ull,
        "sub(f64_reinterpret_i64(0x7ff4000000000000ull), -INFINITY)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, f64_reinterpret_i64(0x7ff8000000000000ull), INFINITY)) & 9223372036854775807ull),
        9221120237041090560ull,
        "sub(f64_reinterpret_i64(0x7ff8000000000000ull), INFINITY)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, f64_reinterpret_i64(0x7ff4000000000000ull), INFINITY)) & 9221120237041090560ull),
        9221120237041090560ull,
        "sub(f64_reinterpret_i64(0x7ff4000000000000ull), INFINITY)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, f64_reinterpret_i64(0xfff8000000000000ull), f64_reinterpret_i64(0xfff8000000000000ull))) & 9223372036854775807ull),
        9221120237041090560ull,
        "sub(f64_reinterpret_i64(0xfff8000000000000ull), f64_reinterpret_i64(0xfff8000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, f64_reinterpret_i64(0xfff4000000000000ull), f64_reinterpret_i64(0xfff8000000000000ull))) & 9221120237041090560ull),
        9221120237041090560ull,
        "sub(f64_reinterpret_i64(0xfff4000000000000ull), f64_reinterpret_i64(0xfff8000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, f64_reinterpret_i64(0xfff8000000000000ull), f64_reinterpret_i64(0xfff4000000000000ull))) & 9221120237041090560ull),
        9221120237041090560ull,
        "sub(f64_reinterpret_i64(0xfff8000000000000ull), f64_reinterpret_i64(0xfff4000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, f64_reinterpret_i64(0xfff4000000000000ull), f64_reinterpret_i64(0xfff4000000000000ull))) & 9221120237041090560ull),
        9221120237041090560ull,
        "sub(f64_reinterpret_i64(0xfff4000000000000ull), f64_reinterpret_i64(0xfff4000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, f64_reinterpret_i64(0xfff8000000000000ull), f64_reinterpret_i64(0x7ff8000000000000ull))) & 9223372036854775807ull),
        9221120237041090560ull,
        "sub(f64_reinterpret_i64(0xfff8000000000000ull), f64_reinterpret_i64(0x7ff8000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, f64_reinterpret_i64(0xfff4000000000000ull), f64_reinterpret_i64(0x7ff8000000000000ull))) & 9221120237041090560ull),
        9221120237041090560ull,
        "sub(f64_reinterpret_i64(0xfff4000000000000ull), f64_reinterpret_i64(0x7ff8000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, f64_reinterpret_i64(0xfff8000000000000ull), f64_reinterpret_i64(0x7ff4000000000000ull))) & 9221120237041090560ull),
        9221120237041090560ull,
        "sub(f64_reinterpret_i64(0xfff8000000000000ull), f64_reinterpret_i64(0x7ff4000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, f64_reinterpret_i64(0xfff4000000000000ull), f64_reinterpret_i64(0x7ff4000000000000ull))) & 9221120237041090560ull),
        9221120237041090560ull,
        "sub(f64_reinterpret_i64(0xfff4000000000000ull), f64_reinterpret_i64(0x7ff4000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, f64_reinterpret_i64(0x7ff8000000000000ull), f64_reinterpret_i64(0xfff8000000000000ull))) & 9223372036854775807ull),
        9221120237041090560ull,
        "sub(f64_reinterpret_i64(0x7ff8000000000000ull), f64_reinterpret_i64(0xfff8000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, f64_reinterpret_i64(0x7ff4000000000000ull), f64_reinterpret_i64(0xfff8000000000000ull))) & 9221120237041090560ull),
        9221120237041090560ull,
        "sub(f64_reinterpret_i64(0x7ff4000000000000ull), f64_reinterpret_i64(0xfff8000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, f64_reinterpret_i64(0x7ff8000000000000ull), f64_reinterpret_i64(0xfff4000000000000ull))) & 9221120237041090560ull),
        9221120237041090560ull,
        "sub(f64_reinterpret_i64(0x7ff8000000000000ull), f64_reinterpret_i64(0xfff4000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, f64_reinterpret_i64(0x7ff4000000000000ull), f64_reinterpret_i64(0xfff4000000000000ull))) & 9221120237041090560ull),
        9221120237041090560ull,
        "sub(f64_reinterpret_i64(0x7ff4000000000000ull), f64_reinterpret_i64(0xfff4000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, f64_reinterpret_i64(0x7ff8000000000000ull), f64_reinterpret_i64(0x7ff8000000000000ull))) & 9223372036854775807ull),
        9221120237041090560ull,
        "sub(f64_reinterpret_i64(0x7ff8000000000000ull), f64_reinterpret_i64(0x7ff8000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, f64_reinterpret_i64(0x7ff4000000000000ull), f64_reinterpret_i64(0x7ff8000000000000ull))) & 9221120237041090560ull),
        9221120237041090560ull,
        "sub(f64_reinterpret_i64(0x7ff4000000000000ull), f64_reinterpret_i64(0x7ff8000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, f64_reinterpret_i64(0x7ff8000000000000ull), f64_reinterpret_i64(0x7ff4000000000000ull))) & 9221120237041090560ull),
        9221120237041090560ull,
        "sub(f64_reinterpret_i64(0x7ff8000000000000ull), f64_reinterpret_i64(0x7ff4000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_sub(&instance, f64_reinterpret_i64(0x7ff4000000000000ull), f64_reinterpret_i64(0x7ff4000000000000ull))) & 9221120237041090560ull),
        9221120237041090560ull,
        "sub(f64_reinterpret_i64(0x7ff4000000000000ull), f64_reinterpret_i64(0x7ff4000000000000ull))"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, -0.0, -0.0)),
        0ull,
        "mul(-0.0, -0.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, -0.0, 0.0)),
        9223372036854775808ull,
        "mul(-0.0, 0.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, 0.0, -0.0)),
        9223372036854775808ull,
        "mul(0.0, -0.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, 0.0, 0.0)),
        0ull,
        "mul(0.0, 0.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, -0.0, -5e-324)),
        0ull,
        "mul(-0.0, -5e-324)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, -0.0, 5e-324)),
        9223372036854775808ull,
        "mul(-0.0, 5e-324)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, 0.0, -5e-324)),
        9223372036854775808ull,
        "mul(0.0, -5e-324)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, 0.0, 5e-324)),
        0ull,
        "mul(0.0, 5e-324)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, -0.0, -2.2250738585072014e-308)),
        0ull,
        "mul(-0.0, -2.2250738585072014e-308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, -0.0, 2.2250738585072014e-308)),
        9223372036854775808ull,
        "mul(-0.0, 2.2250738585072014e-308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, 0.0, -2.2250738585072014e-308)),
        9223372036854775808ull,
        "mul(0.0, -2.2250738585072014e-308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, 0.0, 2.2250738585072014e-308)),
        0ull,
        "mul(0.0, 2.2250738585072014e-308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, -0.0, -0.5)),
        0ull,
        "mul(-0.0, -0.5)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, -0.0, 0.5)),
        9223372036854775808ull,
        "mul(-0.0, 0.5)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, 0.0, -0.5)),
        9223372036854775808ull,
        "mul(0.0, -0.5)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, 0.0, 0.5)),
        0ull,
        "mul(0.0, 0.5)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, -0.0, -1.0)),
        0ull,
        "mul(-0.0, -1.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, -0.0, 1.0)),
        9223372036854775808ull,
        "mul(-0.0, 1.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, 0.0, -1.0)),
        9223372036854775808ull,
        "mul(0.0, -1.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, 0.0, 1.0)),
        0ull,
        "mul(0.0, 1.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, -0.0, -6.283185307179586)),
        0ull,
        "mul(-0.0, -6.283185307179586)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, -0.0, 6.283185307179586)),
        9223372036854775808ull,
        "mul(-0.0, 6.283185307179586)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, 0.0, -6.283185307179586)),
        9223372036854775808ull,
        "mul(0.0, -6.283185307179586)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, 0.0, 6.283185307179586)),
        0ull,
        "mul(0.0, 6.283185307179586)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, -0.0, -1.7976931348623157e+308)),
        0ull,
        "mul(-0.0, -1.7976931348623157e+308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, -0.0, 1.7976931348623157e+308)),
        9223372036854775808ull,
        "mul(-0.0, 1.7976931348623157e+308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, 0.0, -1.7976931348623157e+308)),
        9223372036854775808ull,
        "mul(0.0, -1.7976931348623157e+308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, 0.0, 1.7976931348623157e+308)),
        0ull,
        "mul(0.0, 1.7976931348623157e+308)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, -0.0, -INFINITY)) & 9223372036854775807ull),
        9221120237041090560ull,
        "mul(-0.0, -INFINITY)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, -0.0, INFINITY)) & 9223372036854775807ull),
        9221120237041090560ull,
        "mul(-0.0, INFINITY)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, 0.0, -INFINITY)) & 9223372036854775807ull),
        9221120237041090560ull,
        "mul(0.0, -INFINITY)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, 0.0, INFINITY)) & 9223372036854775807ull),
        9221120237041090560ull,
        "mul(0.0, INFINITY)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, -0.0, f64_reinterpret_i64(0xfff8000000000000ull))) & 9223372036854775807ull),
        9221120237041090560ull,
        "mul(-0.0, f64_reinterpret_i64(0xfff8000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, -0.0, f64_reinterpret_i64(0xfff4000000000000ull))) & 9221120237041090560ull),
        9221120237041090560ull,
        "mul(-0.0, f64_reinterpret_i64(0xfff4000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, -0.0, f64_reinterpret_i64(0x7ff8000000000000ull))) & 9223372036854775807ull),
        9221120237041090560ull,
        "mul(-0.0, f64_reinterpret_i64(0x7ff8000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, -0.0, f64_reinterpret_i64(0x7ff4000000000000ull))) & 9221120237041090560ull),
        9221120237041090560ull,
        "mul(-0.0, f64_reinterpret_i64(0x7ff4000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, 0.0, f64_reinterpret_i64(0xfff8000000000000ull))) & 9223372036854775807ull),
        9221120237041090560ull,
        "mul(0.0, f64_reinterpret_i64(0xfff8000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, 0.0, f64_reinterpret_i64(0xfff4000000000000ull))) & 9221120237041090560ull),
        9221120237041090560ull,
        "mul(0.0, f64_reinterpret_i64(0xfff4000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, 0.0, f64_reinterpret_i64(0x7ff8000000000000ull))) & 9223372036854775807ull),
        9221120237041090560ull,
        "mul(0.0, f64_reinterpret_i64(0x7ff8000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, 0.0, f64_reinterpret_i64(0x7ff4000000000000ull))) & 9221120237041090560ull),
        9221120237041090560ull,
        "mul(0.0, f64_reinterpret_i64(0x7ff4000000000000ull))"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, -5e-324, -0.0)),
        0ull,
        "mul(-5e-324, -0.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, -5e-324, 0.0)),
        9223372036854775808ull,
        "mul(-5e-324, 0.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, 5e-324, -0.0)),
        9223372036854775808ull,
        "mul(5e-324, -0.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, 5e-324, 0.0)),
        0ull,
        "mul(5e-324, 0.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, -5e-324, -5e-324)),
        0ull,
        "mul(-5e-324, -5e-324)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, -5e-324, 5e-324)),
        9223372036854775808ull,
        "mul(-5e-324, 5e-324)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, 5e-324, -5e-324)),
        9223372036854775808ull,
        "mul(5e-324, -5e-324)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, 5e-324, 5e-324)),
        0ull,
        "mul(5e-324, 5e-324)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, -5e-324, -2.2250738585072014e-308)),
        0ull,
        "mul(-5e-324, -2.2250738585072014e-308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, -5e-324, 2.2250738585072014e-308)),
        9223372036854775808ull,
        "mul(-5e-324, 2.2250738585072014e-308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, 5e-324, -2.2250738585072014e-308)),
        9223372036854775808ull,
        "mul(5e-324, -2.2250738585072014e-308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, 5e-324, 2.2250738585072014e-308)),
        0ull,
        "mul(5e-324, 2.2250738585072014e-308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, -5e-324, -0.5)),
        0ull,
        "mul(-5e-324, -0.5)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, -5e-324, 0.5)),
        9223372036854775808ull,
        "mul(-5e-324, 0.5)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, 5e-324, -0.5)),
        9223372036854775808ull,
        "mul(5e-324, -0.5)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, 5e-324, 0.5)),
        0ull,
        "mul(5e-324, 0.5)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, -5e-324, -1.0)),
        1ull,
        "mul(-5e-324, -1.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, -5e-324, 1.0)),
        9223372036854775809ull,
        "mul(-5e-324, 1.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, 5e-324, -1.0)),
        9223372036854775809ull,
        "mul(5e-324, -1.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, 5e-324, 1.0)),
        1ull,
        "mul(5e-324, 1.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, -5e-324, -6.283185307179586)),
        6ull,
        "mul(-5e-324, -6.283185307179586)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, -5e-324, 6.283185307179586)),
        9223372036854775814ull,
        "mul(-5e-324, 6.283185307179586)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, 5e-324, -6.283185307179586)),
        9223372036854775814ull,
        "mul(5e-324, -6.283185307179586)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, 5e-324, 6.283185307179586)),
        6ull,
        "mul(5e-324, 6.283185307179586)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, -5e-324, -1.7976931348623157e+308)),
        4382002437431492607ull,
        "mul(-5e-324, -1.7976931348623157e+308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, -5e-324, 1.7976931348623157e+308)),
        13605374474286268415ull,
        "mul(-5e-324, 1.7976931348623157e+308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, 5e-324, -1.7976931348623157e+308)),
        13605374474286268415ull,
        "mul(5e-324, -1.7976931348623157e+308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, 5e-324, 1.7976931348623157e+308)),
        4382002437431492607ull,
        "mul(5e-324, 1.7976931348623157e+308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, -5e-324, -INFINITY)),
        9218868437227405312ull,
        "mul(-5e-324, -INFINITY)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, -5e-324, INFINITY)),
        18442240474082181120ull,
        "mul(-5e-324, INFINITY)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, 5e-324, -INFINITY)),
        18442240474082181120ull,
        "mul(5e-324, -INFINITY)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, 5e-324, INFINITY)),
        9218868437227405312ull,
        "mul(5e-324, INFINITY)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, -5e-324, f64_reinterpret_i64(0xfff8000000000000ull))) & 9223372036854775807ull),
        9221120237041090560ull,
        "mul(-5e-324, f64_reinterpret_i64(0xfff8000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, -5e-324, f64_reinterpret_i64(0xfff4000000000000ull))) & 9221120237041090560ull),
        9221120237041090560ull,
        "mul(-5e-324, f64_reinterpret_i64(0xfff4000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, -5e-324, f64_reinterpret_i64(0x7ff8000000000000ull))) & 9223372036854775807ull),
        9221120237041090560ull,
        "mul(-5e-324, f64_reinterpret_i64(0x7ff8000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, -5e-324, f64_reinterpret_i64(0x7ff4000000000000ull))) & 9221120237041090560ull),
        9221120237041090560ull,
        "mul(-5e-324, f64_reinterpret_i64(0x7ff4000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, 5e-324, f64_reinterpret_i64(0xfff8000000000000ull))) & 9223372036854775807ull),
        9221120237041090560ull,
        "mul(5e-324, f64_reinterpret_i64(0xfff8000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, 5e-324, f64_reinterpret_i64(0xfff4000000000000ull))) & 9221120237041090560ull),
        9221120237041090560ull,
        "mul(5e-324, f64_reinterpret_i64(0xfff4000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, 5e-324, f64_reinterpret_i64(0x7ff8000000000000ull))) & 9223372036854775807ull),
        9221120237041090560ull,
        "mul(5e-324, f64_reinterpret_i64(0x7ff8000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, 5e-324, f64_reinterpret_i64(0x7ff4000000000000ull))) & 9221120237041090560ull),
        9221120237041090560ull,
        "mul(5e-324, f64_reinterpret_i64(0x7ff4000000000000ull))"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, -2.2250738585072014e-308, -0.0)),
        0ull,
        "mul(-2.2250738585072014e-308, -0.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, -2.2250738585072014e-308, 0.0)),
        9223372036854775808ull,
        "mul(-2.2250738585072014e-308, 0.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, 2.2250738585072014e-308, -0.0)),
        9223372036854775808ull,
        "mul(2.2250738585072014e-308, -0.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, 2.2250738585072014e-308, 0.0)),
        0ull,
        "mul(2.2250738585072014e-308, 0.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, -2.2250738585072014e-308, -5e-324)),
        0ull,
        "mul(-2.2250738585072014e-308, -5e-324)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, -2.2250738585072014e-308, 5e-324)),
        9223372036854775808ull,
        "mul(-2.2250738585072014e-308, 5e-324)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, 2.2250738585072014e-308, -5e-324)),
        9223372036854775808ull,
        "mul(2.2250738585072014e-308, -5e-324)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, 2.2250738585072014e-308, 5e-324)),
        0ull,
        "mul(2.2250738585072014e-308, 5e-324)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, -2.2250738585072014e-308, -2.2250738585072014e-308)),
        0ull,
        "mul(-2.2250738585072014e-308, -2.2250738585072014e-308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, -2.2250738585072014e-308, 2.2250738585072014e-308)),
        9223372036854775808ull,
        "mul(-2.2250738585072014e-308, 2.2250738585072014e-308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, 2.2250738585072014e-308, -2.2250738585072014e-308)),
        9223372036854775808ull,
        "mul(2.2250738585072014e-308, -2.2250738585072014e-308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, 2.2250738585072014e-308, 2.2250738585072014e-308)),
        0ull,
        "mul(2.2250738585072014e-308, 2.2250738585072014e-308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, -2.2250738585072014e-308, -0.5)),
        2251799813685248ull,
        "mul(-2.2250738585072014e-308, -0.5)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, -2.2250738585072014e-308, 0.5)),
        9225623836668461056ull,
        "mul(-2.2250738585072014e-308, 0.5)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, 2.2250738585072014e-308, -0.5)),
        9225623836668461056ull,
        "mul(2.2250738585072014e-308, -0.5)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, 2.2250738585072014e-308, 0.5)),
        2251799813685248ull,
        "mul(2.2250738585072014e-308, 0.5)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, -2.2250738585072014e-308, -1.0)),
        4503599627370496ull,
        "mul(-2.2250738585072014e-308, -1.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, -2.2250738585072014e-308, 1.0)),
        9227875636482146304ull,
        "mul(-2.2250738585072014e-308, 1.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, 2.2250738585072014e-308, -1.0)),
        9227875636482146304ull,
        "mul(2.2250738585072014e-308, -1.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, 2.2250738585072014e-308, 1.0)),
        4503599627370496ull,
        "mul(2.2250738585072014e-308, 1.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, -2.2250738585072014e-308, -6.283185307179586)),
        16081437006769432ull,
        "mul(-2.2250738585072014e-308, -6.283185307179586)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, -2.2250738585072014e-308, 6.283185307179586)),
        9239453473861545240ull,
        "mul(-2.2250738585072014e-308, 6.283185307179586)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, 2.2250738585072014e-308, -6.283185307179586)),
        9239453473861545240ull,
        "mul(2.2250738585072014e-308, -6.283185307179586)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, 2.2250738585072014e-308, 6.283185307179586)),
        16081437006769432ull,
        "mul(2.2250738585072014e-308, 6.283185307179586)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, -2.2250738585072014e-308, -1.7976931348623157e+308)),
        4616189618054758399ull,
        "mul(-2.2250738585072014e-308, -1.7976931348623157e+308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, -2.2250738585072014e-308, 1.7976931348623157e+308)),
        13839561654909534207ull,
        "mul(-2.2250738585072014e-308, 1.7976931348623157e+308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, 2.2250738585072014e-308, -1.7976931348623157e+308)),
        13839561654909534207ull,
        "mul(2.2250738585072014e-308, -1.7976931348623157e+308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, 2.2250738585072014e-308, 1.7976931348623157e+308)),
        4616189618054758399ull,
        "mul(2.2250738585072014e-308, 1.7976931348623157e+308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, -2.2250738585072014e-308, -INFINITY)),
        9218868437227405312ull,
        "mul(-2.2250738585072014e-308, -INFINITY)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, -2.2250738585072014e-308, INFINITY)),
        18442240474082181120ull,
        "mul(-2.2250738585072014e-308, INFINITY)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, 2.2250738585072014e-308, -INFINITY)),
        18442240474082181120ull,
        "mul(2.2250738585072014e-308, -INFINITY)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, 2.2250738585072014e-308, INFINITY)),
        9218868437227405312ull,
        "mul(2.2250738585072014e-308, INFINITY)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, -2.2250738585072014e-308, f64_reinterpret_i64(0xfff8000000000000ull))) & 9223372036854775807ull),
        9221120237041090560ull,
        "mul(-2.2250738585072014e-308, f64_reinterpret_i64(0xfff8000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, -2.2250738585072014e-308, f64_reinterpret_i64(0xfff4000000000000ull))) & 9221120237041090560ull),
        9221120237041090560ull,
        "mul(-2.2250738585072014e-308, f64_reinterpret_i64(0xfff4000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, -2.2250738585072014e-308, f64_reinterpret_i64(0x7ff8000000000000ull))) & 9223372036854775807ull),
        9221120237041090560ull,
        "mul(-2.2250738585072014e-308, f64_reinterpret_i64(0x7ff8000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, -2.2250738585072014e-308, f64_reinterpret_i64(0x7ff4000000000000ull))) & 9221120237041090560ull),
        9221120237041090560ull,
        "mul(-2.2250738585072014e-308, f64_reinterpret_i64(0x7ff4000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, 2.2250738585072014e-308, f64_reinterpret_i64(0xfff8000000000000ull))) & 9223372036854775807ull),
        9221120237041090560ull,
        "mul(2.2250738585072014e-308, f64_reinterpret_i64(0xfff8000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, 2.2250738585072014e-308, f64_reinterpret_i64(0xfff4000000000000ull))) & 9221120237041090560ull),
        9221120237041090560ull,
        "mul(2.2250738585072014e-308, f64_reinterpret_i64(0xfff4000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, 2.2250738585072014e-308, f64_reinterpret_i64(0x7ff8000000000000ull))) & 9223372036854775807ull),
        9221120237041090560ull,
        "mul(2.2250738585072014e-308, f64_reinterpret_i64(0x7ff8000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, 2.2250738585072014e-308, f64_reinterpret_i64(0x7ff4000000000000ull))) & 9221120237041090560ull),
        9221120237041090560ull,
        "mul(2.2250738585072014e-308, f64_reinterpret_i64(0x7ff4000000000000ull))"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, -0.5, -0.0)),
        0ull,
        "mul(-0.5, -0.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, -0.5, 0.0)),
        9223372036854775808ull,
        "mul(-0.5, 0.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, 0.5, -0.0)),
        9223372036854775808ull,
        "mul(0.5, -0.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, 0.5, 0.0)),
        0ull,
        "mul(0.5, 0.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, -0.5, -5e-324)),
        0ull,
        "mul(-0.5, -5e-324)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, -0.5, 5e-324)),
        9223372036854775808ull,
        "mul(-0.5, 5e-324)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, 0.5, -5e-324)),
        9223372036854775808ull,
        "mul(0.5, -5e-324)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, 0.5, 5e-324)),
        0ull,
        "mul(0.5, 5e-324)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, -0.5, -2.2250738585072014e-308)),
        2251799813685248ull,
        "mul(-0.5, -2.2250738585072014e-308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, -0.5, 2.2250738585072014e-308)),
        9225623836668461056ull,
        "mul(-0.5, 2.2250738585072014e-308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, 0.5, -2.2250738585072014e-308)),
        9225623836668461056ull,
        "mul(0.5, -2.2250738585072014e-308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, 0.5, 2.2250738585072014e-308)),
        2251799813685248ull,
        "mul(0.5, 2.2250738585072014e-308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, -0.5, -0.5)),
        4598175219545276416ull,
        "mul(-0.5, -0.5)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, -0.5, 0.5)),
        13821547256400052224ull,
        "mul(-0.5, 0.5)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, 0.5, -0.5)),
        13821547256400052224ull,
        "mul(0.5, -0.5)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, 0.5, 0.5)),
        4598175219545276416ull,
        "mul(0.5, 0.5)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, -0.5, -1.0)),
        4602678819172646912ull,
        "mul(-0.5, -1.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, -0.5, 1.0)),
        13826050856027422720ull,
        "mul(-0.5, 1.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, 0.5, -1.0)),
        13826050856027422720ull,
        "mul(0.5, -1.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, 0.5, 1.0)),
        4602678819172646912ull,
        "mul(0.5, 1.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, -0.5, -6.283185307179586)),
        4614256656552045848ull,
        "mul(-0.5, -6.283185307179586)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, -0.5, 6.283185307179586)),
        13837628693406821656ull,
        "mul(-0.5, 6.283185307179586)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, 0.5, -6.283185307179586)),
        13837628693406821656ull,
        "mul(0.5, -6.283185307179586)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, 0.5, 6.283185307179586)),
        4614256656552045848ull,
        "mul(0.5, 6.283185307179586)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, -0.5, -1.7976931348623157e+308)),
        9214364837600034815ull,
        "mul(-0.5, -1.7976931348623157e+308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, -0.5, 1.7976931348623157e+308)),
        18437736874454810623ull,
        "mul(-0.5, 1.7976931348623157e+308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, 0.5, -1.7976931348623157e+308)),
        18437736874454810623ull,
        "mul(0.5, -1.7976931348623157e+308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, 0.5, 1.7976931348623157e+308)),
        9214364837600034815ull,
        "mul(0.5, 1.7976931348623157e+308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, -0.5, -INFINITY)),
        9218868437227405312ull,
        "mul(-0.5, -INFINITY)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, -0.5, INFINITY)),
        18442240474082181120ull,
        "mul(-0.5, INFINITY)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, 0.5, -INFINITY)),
        18442240474082181120ull,
        "mul(0.5, -INFINITY)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, 0.5, INFINITY)),
        9218868437227405312ull,
        "mul(0.5, INFINITY)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, -0.5, f64_reinterpret_i64(0xfff8000000000000ull))) & 9223372036854775807ull),
        9221120237041090560ull,
        "mul(-0.5, f64_reinterpret_i64(0xfff8000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, -0.5, f64_reinterpret_i64(0xfff4000000000000ull))) & 9221120237041090560ull),
        9221120237041090560ull,
        "mul(-0.5, f64_reinterpret_i64(0xfff4000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, -0.5, f64_reinterpret_i64(0x7ff8000000000000ull))) & 9223372036854775807ull),
        9221120237041090560ull,
        "mul(-0.5, f64_reinterpret_i64(0x7ff8000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, -0.5, f64_reinterpret_i64(0x7ff4000000000000ull))) & 9221120237041090560ull),
        9221120237041090560ull,
        "mul(-0.5, f64_reinterpret_i64(0x7ff4000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, 0.5, f64_reinterpret_i64(0xfff8000000000000ull))) & 9223372036854775807ull),
        9221120237041090560ull,
        "mul(0.5, f64_reinterpret_i64(0xfff8000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, 0.5, f64_reinterpret_i64(0xfff4000000000000ull))) & 9221120237041090560ull),
        9221120237041090560ull,
        "mul(0.5, f64_reinterpret_i64(0xfff4000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, 0.5, f64_reinterpret_i64(0x7ff8000000000000ull))) & 9223372036854775807ull),
        9221120237041090560ull,
        "mul(0.5, f64_reinterpret_i64(0x7ff8000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, 0.5, f64_reinterpret_i64(0x7ff4000000000000ull))) & 9221120237041090560ull),
        9221120237041090560ull,
        "mul(0.5, f64_reinterpret_i64(0x7ff4000000000000ull))"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, -1.0, -0.0)),
        0ull,
        "mul(-1.0, -0.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, -1.0, 0.0)),
        9223372036854775808ull,
        "mul(-1.0, 0.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, 1.0, -0.0)),
        9223372036854775808ull,
        "mul(1.0, -0.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, 1.0, 0.0)),
        0ull,
        "mul(1.0, 0.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, -1.0, -5e-324)),
        1ull,
        "mul(-1.0, -5e-324)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, -1.0, 5e-324)),
        9223372036854775809ull,
        "mul(-1.0, 5e-324)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, 1.0, -5e-324)),
        9223372036854775809ull,
        "mul(1.0, -5e-324)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, 1.0, 5e-324)),
        1ull,
        "mul(1.0, 5e-324)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, -1.0, -2.2250738585072014e-308)),
        4503599627370496ull,
        "mul(-1.0, -2.2250738585072014e-308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, -1.0, 2.2250738585072014e-308)),
        9227875636482146304ull,
        "mul(-1.0, 2.2250738585072014e-308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, 1.0, -2.2250738585072014e-308)),
        9227875636482146304ull,
        "mul(1.0, -2.2250738585072014e-308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, 1.0, 2.2250738585072014e-308)),
        4503599627370496ull,
        "mul(1.0, 2.2250738585072014e-308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, -1.0, -0.5)),
        4602678819172646912ull,
        "mul(-1.0, -0.5)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, -1.0, 0.5)),
        13826050856027422720ull,
        "mul(-1.0, 0.5)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, 1.0, -0.5)),
        13826050856027422720ull,
        "mul(1.0, -0.5)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, 1.0, 0.5)),
        4602678819172646912ull,
        "mul(1.0, 0.5)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, -1.0, -1.0)),
        4607182418800017408ull,
        "mul(-1.0, -1.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, -1.0, 1.0)),
        13830554455654793216ull,
        "mul(-1.0, 1.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, 1.0, -1.0)),
        13830554455654793216ull,
        "mul(1.0, -1.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, 1.0, 1.0)),
        4607182418800017408ull,
        "mul(1.0, 1.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, -1.0, -6.283185307179586)),
        4618760256179416344ull,
        "mul(-1.0, -6.283185307179586)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, -1.0, 6.283185307179586)),
        13842132293034192152ull,
        "mul(-1.0, 6.283185307179586)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, 1.0, -6.283185307179586)),
        13842132293034192152ull,
        "mul(1.0, -6.283185307179586)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, 1.0, 6.283185307179586)),
        4618760256179416344ull,
        "mul(1.0, 6.283185307179586)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, -1.0, -1.7976931348623157e+308)),
        9218868437227405311ull,
        "mul(-1.0, -1.7976931348623157e+308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, -1.0, 1.7976931348623157e+308)),
        18442240474082181119ull,
        "mul(-1.0, 1.7976931348623157e+308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, 1.0, -1.7976931348623157e+308)),
        18442240474082181119ull,
        "mul(1.0, -1.7976931348623157e+308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, 1.0, 1.7976931348623157e+308)),
        9218868437227405311ull,
        "mul(1.0, 1.7976931348623157e+308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, -1.0, -INFINITY)),
        9218868437227405312ull,
        "mul(-1.0, -INFINITY)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, -1.0, INFINITY)),
        18442240474082181120ull,
        "mul(-1.0, INFINITY)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, 1.0, -INFINITY)),
        18442240474082181120ull,
        "mul(1.0, -INFINITY)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, 1.0, INFINITY)),
        9218868437227405312ull,
        "mul(1.0, INFINITY)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, -1.0, f64_reinterpret_i64(0xfff8000000000000ull))) & 9223372036854775807ull),
        9221120237041090560ull,
        "mul(-1.0, f64_reinterpret_i64(0xfff8000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, -1.0, f64_reinterpret_i64(0xfff4000000000000ull))) & 9221120237041090560ull),
        9221120237041090560ull,
        "mul(-1.0, f64_reinterpret_i64(0xfff4000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, -1.0, f64_reinterpret_i64(0x7ff8000000000000ull))) & 9223372036854775807ull),
        9221120237041090560ull,
        "mul(-1.0, f64_reinterpret_i64(0x7ff8000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, -1.0, f64_reinterpret_i64(0x7ff4000000000000ull))) & 9221120237041090560ull),
        9221120237041090560ull,
        "mul(-1.0, f64_reinterpret_i64(0x7ff4000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, 1.0, f64_reinterpret_i64(0xfff8000000000000ull))) & 9223372036854775807ull),
        9221120237041090560ull,
        "mul(1.0, f64_reinterpret_i64(0xfff8000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, 1.0, f64_reinterpret_i64(0xfff4000000000000ull))) & 9221120237041090560ull),
        9221120237041090560ull,
        "mul(1.0, f64_reinterpret_i64(0xfff4000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, 1.0, f64_reinterpret_i64(0x7ff8000000000000ull))) & 9223372036854775807ull),
        9221120237041090560ull,
        "mul(1.0, f64_reinterpret_i64(0x7ff8000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, 1.0, f64_reinterpret_i64(0x7ff4000000000000ull))) & 9221120237041090560ull),
        9221120237041090560ull,
        "mul(1.0, f64_reinterpret_i64(0x7ff4000000000000ull))"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, -6.283185307179586, -0.0)),
        0ull,
        "mul(-6.283185307179586, -0.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, -6.283185307179586, 0.0)),
        9223372036854775808ull,
        "mul(-6.283185307179586, 0.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, 6.283185307179586, -0.0)),
        9223372036854775808ull,
        "mul(6.283185307179586, -0.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, 6.283185307179586, 0.0)),
        0ull,
        "mul(6.283185307179586, 0.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, -6.283185307179586, -5e-324)),
        6ull,
        "mul(-6.283185307179586, -5e-324)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, -6.283185307179586, 5e-324)),
        9223372036854775814ull,
        "mul(-6.283185307179586, 5e-324)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, 6.283185307179586, -5e-324)),
        9223372036854775814ull,
        "mul(6.283185307179586, -5e-324)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, 6.283185307179586, 5e-324)),
        6ull,
        "mul(6.283185307179586, 5e-324)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, -6.283185307179586, -2.2250738585072014e-308)),
        16081437006769432ull,
        "mul(-6.283185307179586, -2.2250738585072014e-308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, -6.283185307179586, 2.2250738585072014e-308)),
        9239453473861545240ull,
        "mul(-6.283185307179586, 2.2250738585072014e-308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, 6.283185307179586, -2.2250738585072014e-308)),
        9239453473861545240ull,
        "mul(6.283185307179586, -2.2250738585072014e-308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, 6.283185307179586, 2.2250738585072014e-308)),
        16081437006769432ull,
        "mul(6.283185307179586, 2.2250738585072014e-308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, -6.283185307179586, -0.5)),
        4614256656552045848ull,
        "mul(-6.283185307179586, -0.5)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, -6.283185307179586, 0.5)),
        13837628693406821656ull,
        "mul(-6.283185307179586, 0.5)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, 6.283185307179586, -0.5)),
        13837628693406821656ull,
        "mul(6.283185307179586, -0.5)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, 6.283185307179586, 0.5)),
        4614256656552045848ull,
        "mul(6.283185307179586, 0.5)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, -6.283185307179586, -1.0)),
        4618760256179416344ull,
        "mul(-6.283185307179586, -1.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, -6.283185307179586, 1.0)),
        13842132293034192152ull,
        "mul(-6.283185307179586, 1.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, 6.283185307179586, -1.0)),
        13842132293034192152ull,
        "mul(6.283185307179586, -1.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, 6.283185307179586, 1.0)),
        4618760256179416344ull,
        "mul(6.283185307179586, 1.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, -6.283185307179586, -6.283185307179586)),
        4630752910647379422ull,
        "mul(-6.283185307179586, -6.283185307179586)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, -6.283185307179586, 6.283185307179586)),
        13854124947502155230ull,
        "mul(-6.283185307179586, 6.283185307179586)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, 6.283185307179586, -6.283185307179586)),
        13854124947502155230ull,
        "mul(6.283185307179586, -6.283185307179586)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, 6.283185307179586, 6.283185307179586)),
        4630752910647379422ull,
        "mul(6.283185307179586, 6.283185307179586)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, -6.283185307179586, -1.7976931348623157e+308)),
        9218868437227405312ull,
        "mul(-6.283185307179586, -1.7976931348623157e+308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, -6.283185307179586, 1.7976931348623157e+308)),
        18442240474082181120ull,
        "mul(-6.283185307179586, 1.7976931348623157e+308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, 6.283185307179586, -1.7976931348623157e+308)),
        18442240474082181120ull,
        "mul(6.283185307179586, -1.7976931348623157e+308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, 6.283185307179586, 1.7976931348623157e+308)),
        9218868437227405312ull,
        "mul(6.283185307179586, 1.7976931348623157e+308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, -6.283185307179586, -INFINITY)),
        9218868437227405312ull,
        "mul(-6.283185307179586, -INFINITY)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, -6.283185307179586, INFINITY)),
        18442240474082181120ull,
        "mul(-6.283185307179586, INFINITY)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, 6.283185307179586, -INFINITY)),
        18442240474082181120ull,
        "mul(6.283185307179586, -INFINITY)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, 6.283185307179586, INFINITY)),
        9218868437227405312ull,
        "mul(6.283185307179586, INFINITY)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, -6.283185307179586, f64_reinterpret_i64(0xfff8000000000000ull))) & 9223372036854775807ull),
        9221120237041090560ull,
        "mul(-6.283185307179586, f64_reinterpret_i64(0xfff8000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, -6.283185307179586, f64_reinterpret_i64(0xfff4000000000000ull))) & 9221120237041090560ull),
        9221120237041090560ull,
        "mul(-6.283185307179586, f64_reinterpret_i64(0xfff4000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, -6.283185307179586, f64_reinterpret_i64(0x7ff8000000000000ull))) & 9223372036854775807ull),
        9221120237041090560ull,
        "mul(-6.283185307179586, f64_reinterpret_i64(0x7ff8000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, -6.283185307179586, f64_reinterpret_i64(0x7ff4000000000000ull))) & 9221120237041090560ull),
        9221120237041090560ull,
        "mul(-6.283185307179586, f64_reinterpret_i64(0x7ff4000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, 6.283185307179586, f64_reinterpret_i64(0xfff8000000000000ull))) & 9223372036854775807ull),
        9221120237041090560ull,
        "mul(6.283185307179586, f64_reinterpret_i64(0xfff8000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, 6.283185307179586, f64_reinterpret_i64(0xfff4000000000000ull))) & 9221120237041090560ull),
        9221120237041090560ull,
        "mul(6.283185307179586, f64_reinterpret_i64(0xfff4000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, 6.283185307179586, f64_reinterpret_i64(0x7ff8000000000000ull))) & 9223372036854775807ull),
        9221120237041090560ull,
        "mul(6.283185307179586, f64_reinterpret_i64(0x7ff8000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, 6.283185307179586, f64_reinterpret_i64(0x7ff4000000000000ull))) & 9221120237041090560ull),
        9221120237041090560ull,
        "mul(6.283185307179586, f64_reinterpret_i64(0x7ff4000000000000ull))"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, -1.7976931348623157e+308, -0.0)),
        0ull,
        "mul(-1.7976931348623157e+308, -0.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, -1.7976931348623157e+308, 0.0)),
        9223372036854775808ull,
        "mul(-1.7976931348623157e+308, 0.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, 1.7976931348623157e+308, -0.0)),
        9223372036854775808ull,
        "mul(1.7976931348623157e+308, -0.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, 1.7976931348623157e+308, 0.0)),
        0ull,
        "mul(1.7976931348623157e+308, 0.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, -1.7976931348623157e+308, -5e-324)),
        4382002437431492607ull,
        "mul(-1.7976931348623157e+308, -5e-324)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, -1.7976931348623157e+308, 5e-324)),
        13605374474286268415ull,
        "mul(-1.7976931348623157e+308, 5e-324)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, 1.7976931348623157e+308, -5e-324)),
        13605374474286268415ull,
        "mul(1.7976931348623157e+308, -5e-324)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, 1.7976931348623157e+308, 5e-324)),
        4382002437431492607ull,
        "mul(1.7976931348623157e+308, 5e-324)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, -1.7976931348623157e+308, -2.2250738585072014e-308)),
        4616189618054758399ull,
        "mul(-1.7976931348623157e+308, -2.2250738585072014e-308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, -1.7976931348623157e+308, 2.2250738585072014e-308)),
        13839561654909534207ull,
        "mul(-1.7976931348623157e+308, 2.2250738585072014e-308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, 1.7976931348623157e+308, -2.2250738585072014e-308)),
        13839561654909534207ull,
        "mul(1.7976931348623157e+308, -2.2250738585072014e-308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, 1.7976931348623157e+308, 2.2250738585072014e-308)),
        4616189618054758399ull,
        "mul(1.7976931348623157e+308, 2.2250738585072014e-308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, -1.7976931348623157e+308, -0.5)),
        9214364837600034815ull,
        "mul(-1.7976931348623157e+308, -0.5)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, -1.7976931348623157e+308, 0.5)),
        18437736874454810623ull,
        "mul(-1.7976931348623157e+308, 0.5)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, 1.7976931348623157e+308, -0.5)),
        18437736874454810623ull,
        "mul(1.7976931348623157e+308, -0.5)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, 1.7976931348623157e+308, 0.5)),
        9214364837600034815ull,
        "mul(1.7976931348623157e+308, 0.5)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, -1.7976931348623157e+308, -1.0)),
        9218868437227405311ull,
        "mul(-1.7976931348623157e+308, -1.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, -1.7976931348623157e+308, 1.0)),
        18442240474082181119ull,
        "mul(-1.7976931348623157e+308, 1.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, 1.7976931348623157e+308, -1.0)),
        18442240474082181119ull,
        "mul(1.7976931348623157e+308, -1.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, 1.7976931348623157e+308, 1.0)),
        9218868437227405311ull,
        "mul(1.7976931348623157e+308, 1.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, -1.7976931348623157e+308, -6.283185307179586)),
        9218868437227405312ull,
        "mul(-1.7976931348623157e+308, -6.283185307179586)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, -1.7976931348623157e+308, 6.283185307179586)),
        18442240474082181120ull,
        "mul(-1.7976931348623157e+308, 6.283185307179586)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, 1.7976931348623157e+308, -6.283185307179586)),
        18442240474082181120ull,
        "mul(1.7976931348623157e+308, -6.283185307179586)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, 1.7976931348623157e+308, 6.283185307179586)),
        9218868437227405312ull,
        "mul(1.7976931348623157e+308, 6.283185307179586)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, -1.7976931348623157e+308, -1.7976931348623157e+308)),
        9218868437227405312ull,
        "mul(-1.7976931348623157e+308, -1.7976931348623157e+308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, -1.7976931348623157e+308, 1.7976931348623157e+308)),
        18442240474082181120ull,
        "mul(-1.7976931348623157e+308, 1.7976931348623157e+308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, 1.7976931348623157e+308, -1.7976931348623157e+308)),
        18442240474082181120ull,
        "mul(1.7976931348623157e+308, -1.7976931348623157e+308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, 1.7976931348623157e+308, 1.7976931348623157e+308)),
        9218868437227405312ull,
        "mul(1.7976931348623157e+308, 1.7976931348623157e+308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, -1.7976931348623157e+308, -INFINITY)),
        9218868437227405312ull,
        "mul(-1.7976931348623157e+308, -INFINITY)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, -1.7976931348623157e+308, INFINITY)),
        18442240474082181120ull,
        "mul(-1.7976931348623157e+308, INFINITY)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, 1.7976931348623157e+308, -INFINITY)),
        18442240474082181120ull,
        "mul(1.7976931348623157e+308, -INFINITY)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, 1.7976931348623157e+308, INFINITY)),
        9218868437227405312ull,
        "mul(1.7976931348623157e+308, INFINITY)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, -1.7976931348623157e+308, f64_reinterpret_i64(0xfff8000000000000ull))) & 9223372036854775807ull),
        9221120237041090560ull,
        "mul(-1.7976931348623157e+308, f64_reinterpret_i64(0xfff8000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, -1.7976931348623157e+308, f64_reinterpret_i64(0xfff4000000000000ull))) & 9221120237041090560ull),
        9221120237041090560ull,
        "mul(-1.7976931348623157e+308, f64_reinterpret_i64(0xfff4000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, -1.7976931348623157e+308, f64_reinterpret_i64(0x7ff8000000000000ull))) & 9223372036854775807ull),
        9221120237041090560ull,
        "mul(-1.7976931348623157e+308, f64_reinterpret_i64(0x7ff8000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, -1.7976931348623157e+308, f64_reinterpret_i64(0x7ff4000000000000ull))) & 9221120237041090560ull),
        9221120237041090560ull,
        "mul(-1.7976931348623157e+308, f64_reinterpret_i64(0x7ff4000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, 1.7976931348623157e+308, f64_reinterpret_i64(0xfff8000000000000ull))) & 9223372036854775807ull),
        9221120237041090560ull,
        "mul(1.7976931348623157e+308, f64_reinterpret_i64(0xfff8000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, 1.7976931348623157e+308, f64_reinterpret_i64(0xfff4000000000000ull))) & 9221120237041090560ull),
        9221120237041090560ull,
        "mul(1.7976931348623157e+308, f64_reinterpret_i64(0xfff4000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, 1.7976931348623157e+308, f64_reinterpret_i64(0x7ff8000000000000ull))) & 9223372036854775807ull),
        9221120237041090560ull,
        "mul(1.7976931348623157e+308, f64_reinterpret_i64(0x7ff8000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, 1.7976931348623157e+308, f64_reinterpret_i64(0x7ff4000000000000ull))) & 9221120237041090560ull),
        9221120237041090560ull,
        "mul(1.7976931348623157e+308, f64_reinterpret_i64(0x7ff4000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, -INFINITY, -0.0)) & 9223372036854775807ull),
        9221120237041090560ull,
        "mul(-INFINITY, -0.0)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, -INFINITY, 0.0)) & 9223372036854775807ull),
        9221120237041090560ull,
        "mul(-INFINITY, 0.0)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, INFINITY, -0.0)) & 9223372036854775807ull),
        9221120237041090560ull,
        "mul(INFINITY, -0.0)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, INFINITY, 0.0)) & 9223372036854775807ull),
        9221120237041090560ull,
        "mul(INFINITY, 0.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, -INFINITY, -5e-324)),
        9218868437227405312ull,
        "mul(-INFINITY, -5e-324)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, -INFINITY, 5e-324)),
        18442240474082181120ull,
        "mul(-INFINITY, 5e-324)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, INFINITY, -5e-324)),
        18442240474082181120ull,
        "mul(INFINITY, -5e-324)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, INFINITY, 5e-324)),
        9218868437227405312ull,
        "mul(INFINITY, 5e-324)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, -INFINITY, -2.2250738585072014e-308)),
        9218868437227405312ull,
        "mul(-INFINITY, -2.2250738585072014e-308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, -INFINITY, 2.2250738585072014e-308)),
        18442240474082181120ull,
        "mul(-INFINITY, 2.2250738585072014e-308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, INFINITY, -2.2250738585072014e-308)),
        18442240474082181120ull,
        "mul(INFINITY, -2.2250738585072014e-308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, INFINITY, 2.2250738585072014e-308)),
        9218868437227405312ull,
        "mul(INFINITY, 2.2250738585072014e-308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, -INFINITY, -0.5)),
        9218868437227405312ull,
        "mul(-INFINITY, -0.5)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, -INFINITY, 0.5)),
        18442240474082181120ull,
        "mul(-INFINITY, 0.5)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, INFINITY, -0.5)),
        18442240474082181120ull,
        "mul(INFINITY, -0.5)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, INFINITY, 0.5)),
        9218868437227405312ull,
        "mul(INFINITY, 0.5)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, -INFINITY, -1.0)),
        9218868437227405312ull,
        "mul(-INFINITY, -1.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, -INFINITY, 1.0)),
        18442240474082181120ull,
        "mul(-INFINITY, 1.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, INFINITY, -1.0)),
        18442240474082181120ull,
        "mul(INFINITY, -1.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, INFINITY, 1.0)),
        9218868437227405312ull,
        "mul(INFINITY, 1.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, -INFINITY, -6.283185307179586)),
        9218868437227405312ull,
        "mul(-INFINITY, -6.283185307179586)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, -INFINITY, 6.283185307179586)),
        18442240474082181120ull,
        "mul(-INFINITY, 6.283185307179586)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, INFINITY, -6.283185307179586)),
        18442240474082181120ull,
        "mul(INFINITY, -6.283185307179586)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, INFINITY, 6.283185307179586)),
        9218868437227405312ull,
        "mul(INFINITY, 6.283185307179586)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, -INFINITY, -1.7976931348623157e+308)),
        9218868437227405312ull,
        "mul(-INFINITY, -1.7976931348623157e+308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, -INFINITY, 1.7976931348623157e+308)),
        18442240474082181120ull,
        "mul(-INFINITY, 1.7976931348623157e+308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, INFINITY, -1.7976931348623157e+308)),
        18442240474082181120ull,
        "mul(INFINITY, -1.7976931348623157e+308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, INFINITY, 1.7976931348623157e+308)),
        9218868437227405312ull,
        "mul(INFINITY, 1.7976931348623157e+308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, -INFINITY, -INFINITY)),
        9218868437227405312ull,
        "mul(-INFINITY, -INFINITY)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, -INFINITY, INFINITY)),
        18442240474082181120ull,
        "mul(-INFINITY, INFINITY)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, INFINITY, -INFINITY)),
        18442240474082181120ull,
        "mul(INFINITY, -INFINITY)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, INFINITY, INFINITY)),
        9218868437227405312ull,
        "mul(INFINITY, INFINITY)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, -INFINITY, f64_reinterpret_i64(0xfff8000000000000ull))) & 9223372036854775807ull),
        9221120237041090560ull,
        "mul(-INFINITY, f64_reinterpret_i64(0xfff8000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, -INFINITY, f64_reinterpret_i64(0xfff4000000000000ull))) & 9221120237041090560ull),
        9221120237041090560ull,
        "mul(-INFINITY, f64_reinterpret_i64(0xfff4000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, -INFINITY, f64_reinterpret_i64(0x7ff8000000000000ull))) & 9223372036854775807ull),
        9221120237041090560ull,
        "mul(-INFINITY, f64_reinterpret_i64(0x7ff8000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, -INFINITY, f64_reinterpret_i64(0x7ff4000000000000ull))) & 9221120237041090560ull),
        9221120237041090560ull,
        "mul(-INFINITY, f64_reinterpret_i64(0x7ff4000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, INFINITY, f64_reinterpret_i64(0xfff8000000000000ull))) & 9223372036854775807ull),
        9221120237041090560ull,
        "mul(INFINITY, f64_reinterpret_i64(0xfff8000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, INFINITY, f64_reinterpret_i64(0xfff4000000000000ull))) & 9221120237041090560ull),
        9221120237041090560ull,
        "mul(INFINITY, f64_reinterpret_i64(0xfff4000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, INFINITY, f64_reinterpret_i64(0x7ff8000000000000ull))) & 9223372036854775807ull),
        9221120237041090560ull,
        "mul(INFINITY, f64_reinterpret_i64(0x7ff8000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, INFINITY, f64_reinterpret_i64(0x7ff4000000000000ull))) & 9221120237041090560ull),
        9221120237041090560ull,
        "mul(INFINITY, f64_reinterpret_i64(0x7ff4000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, f64_reinterpret_i64(0xfff8000000000000ull), -0.0)) & 9223372036854775807ull),
        9221120237041090560ull,
        "mul(f64_reinterpret_i64(0xfff8000000000000ull), -0.0)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, f64_reinterpret_i64(0xfff4000000000000ull), -0.0)) & 9221120237041090560ull),
        9221120237041090560ull,
        "mul(f64_reinterpret_i64(0xfff4000000000000ull), -0.0)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, f64_reinterpret_i64(0xfff8000000000000ull), 0.0)) & 9223372036854775807ull),
        9221120237041090560ull,
        "mul(f64_reinterpret_i64(0xfff8000000000000ull), 0.0)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, f64_reinterpret_i64(0xfff4000000000000ull), 0.0)) & 9221120237041090560ull),
        9221120237041090560ull,
        "mul(f64_reinterpret_i64(0xfff4000000000000ull), 0.0)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, f64_reinterpret_i64(0x7ff8000000000000ull), -0.0)) & 9223372036854775807ull),
        9221120237041090560ull,
        "mul(f64_reinterpret_i64(0x7ff8000000000000ull), -0.0)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, f64_reinterpret_i64(0x7ff4000000000000ull), -0.0)) & 9221120237041090560ull),
        9221120237041090560ull,
        "mul(f64_reinterpret_i64(0x7ff4000000000000ull), -0.0)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, f64_reinterpret_i64(0x7ff8000000000000ull), 0.0)) & 9223372036854775807ull),
        9221120237041090560ull,
        "mul(f64_reinterpret_i64(0x7ff8000000000000ull), 0.0)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, f64_reinterpret_i64(0x7ff4000000000000ull), 0.0)) & 9221120237041090560ull),
        9221120237041090560ull,
        "mul(f64_reinterpret_i64(0x7ff4000000000000ull), 0.0)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, f64_reinterpret_i64(0xfff8000000000000ull), -5e-324)) & 9223372036854775807ull),
        9221120237041090560ull,
        "mul(f64_reinterpret_i64(0xfff8000000000000ull), -5e-324)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, f64_reinterpret_i64(0xfff4000000000000ull), -5e-324)) & 9221120237041090560ull),
        9221120237041090560ull,
        "mul(f64_reinterpret_i64(0xfff4000000000000ull), -5e-324)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, f64_reinterpret_i64(0xfff8000000000000ull), 5e-324)) & 9223372036854775807ull),
        9221120237041090560ull,
        "mul(f64_reinterpret_i64(0xfff8000000000000ull), 5e-324)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, f64_reinterpret_i64(0xfff4000000000000ull), 5e-324)) & 9221120237041090560ull),
        9221120237041090560ull,
        "mul(f64_reinterpret_i64(0xfff4000000000000ull), 5e-324)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, f64_reinterpret_i64(0x7ff8000000000000ull), -5e-324)) & 9223372036854775807ull),
        9221120237041090560ull,
        "mul(f64_reinterpret_i64(0x7ff8000000000000ull), -5e-324)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, f64_reinterpret_i64(0x7ff4000000000000ull), -5e-324)) & 9221120237041090560ull),
        9221120237041090560ull,
        "mul(f64_reinterpret_i64(0x7ff4000000000000ull), -5e-324)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, f64_reinterpret_i64(0x7ff8000000000000ull), 5e-324)) & 9223372036854775807ull),
        9221120237041090560ull,
        "mul(f64_reinterpret_i64(0x7ff8000000000000ull), 5e-324)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, f64_reinterpret_i64(0x7ff4000000000000ull), 5e-324)) & 9221120237041090560ull),
        9221120237041090560ull,
        "mul(f64_reinterpret_i64(0x7ff4000000000000ull), 5e-324)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, f64_reinterpret_i64(0xfff8000000000000ull), -2.2250738585072014e-308)) & 9223372036854775807ull),
        9221120237041090560ull,
        "mul(f64_reinterpret_i64(0xfff8000000000000ull), -2.2250738585072014e-308)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, f64_reinterpret_i64(0xfff4000000000000ull), -2.2250738585072014e-308)) & 9221120237041090560ull),
        9221120237041090560ull,
        "mul(f64_reinterpret_i64(0xfff4000000000000ull), -2.2250738585072014e-308)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, f64_reinterpret_i64(0xfff8000000000000ull), 2.2250738585072014e-308)) & 9223372036854775807ull),
        9221120237041090560ull,
        "mul(f64_reinterpret_i64(0xfff8000000000000ull), 2.2250738585072014e-308)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, f64_reinterpret_i64(0xfff4000000000000ull), 2.2250738585072014e-308)) & 9221120237041090560ull),
        9221120237041090560ull,
        "mul(f64_reinterpret_i64(0xfff4000000000000ull), 2.2250738585072014e-308)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, f64_reinterpret_i64(0x7ff8000000000000ull), -2.2250738585072014e-308)) & 9223372036854775807ull),
        9221120237041090560ull,
        "mul(f64_reinterpret_i64(0x7ff8000000000000ull), -2.2250738585072014e-308)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, f64_reinterpret_i64(0x7ff4000000000000ull), -2.2250738585072014e-308)) & 9221120237041090560ull),
        9221120237041090560ull,
        "mul(f64_reinterpret_i64(0x7ff4000000000000ull), -2.2250738585072014e-308)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, f64_reinterpret_i64(0x7ff8000000000000ull), 2.2250738585072014e-308)) & 9223372036854775807ull),
        9221120237041090560ull,
        "mul(f64_reinterpret_i64(0x7ff8000000000000ull), 2.2250738585072014e-308)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, f64_reinterpret_i64(0x7ff4000000000000ull), 2.2250738585072014e-308)) & 9221120237041090560ull),
        9221120237041090560ull,
        "mul(f64_reinterpret_i64(0x7ff4000000000000ull), 2.2250738585072014e-308)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, f64_reinterpret_i64(0xfff8000000000000ull), -0.5)) & 9223372036854775807ull),
        9221120237041090560ull,
        "mul(f64_reinterpret_i64(0xfff8000000000000ull), -0.5)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, f64_reinterpret_i64(0xfff4000000000000ull), -0.5)) & 9221120237041090560ull),
        9221120237041090560ull,
        "mul(f64_reinterpret_i64(0xfff4000000000000ull), -0.5)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, f64_reinterpret_i64(0xfff8000000000000ull), 0.5)) & 9223372036854775807ull),
        9221120237041090560ull,
        "mul(f64_reinterpret_i64(0xfff8000000000000ull), 0.5)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, f64_reinterpret_i64(0xfff4000000000000ull), 0.5)) & 9221120237041090560ull),
        9221120237041090560ull,
        "mul(f64_reinterpret_i64(0xfff4000000000000ull), 0.5)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, f64_reinterpret_i64(0x7ff8000000000000ull), -0.5)) & 9223372036854775807ull),
        9221120237041090560ull,
        "mul(f64_reinterpret_i64(0x7ff8000000000000ull), -0.5)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, f64_reinterpret_i64(0x7ff4000000000000ull), -0.5)) & 9221120237041090560ull),
        9221120237041090560ull,
        "mul(f64_reinterpret_i64(0x7ff4000000000000ull), -0.5)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, f64_reinterpret_i64(0x7ff8000000000000ull), 0.5)) & 9223372036854775807ull),
        9221120237041090560ull,
        "mul(f64_reinterpret_i64(0x7ff8000000000000ull), 0.5)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, f64_reinterpret_i64(0x7ff4000000000000ull), 0.5)) & 9221120237041090560ull),
        9221120237041090560ull,
        "mul(f64_reinterpret_i64(0x7ff4000000000000ull), 0.5)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, f64_reinterpret_i64(0xfff8000000000000ull), -1.0)) & 9223372036854775807ull),
        9221120237041090560ull,
        "mul(f64_reinterpret_i64(0xfff8000000000000ull), -1.0)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, f64_reinterpret_i64(0xfff4000000000000ull), -1.0)) & 9221120237041090560ull),
        9221120237041090560ull,
        "mul(f64_reinterpret_i64(0xfff4000000000000ull), -1.0)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, f64_reinterpret_i64(0xfff8000000000000ull), 1.0)) & 9223372036854775807ull),
        9221120237041090560ull,
        "mul(f64_reinterpret_i64(0xfff8000000000000ull), 1.0)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, f64_reinterpret_i64(0xfff4000000000000ull), 1.0)) & 9221120237041090560ull),
        9221120237041090560ull,
        "mul(f64_reinterpret_i64(0xfff4000000000000ull), 1.0)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, f64_reinterpret_i64(0x7ff8000000000000ull), -1.0)) & 9223372036854775807ull),
        9221120237041090560ull,
        "mul(f64_reinterpret_i64(0x7ff8000000000000ull), -1.0)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, f64_reinterpret_i64(0x7ff4000000000000ull), -1.0)) & 9221120237041090560ull),
        9221120237041090560ull,
        "mul(f64_reinterpret_i64(0x7ff4000000000000ull), -1.0)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, f64_reinterpret_i64(0x7ff8000000000000ull), 1.0)) & 9223372036854775807ull),
        9221120237041090560ull,
        "mul(f64_reinterpret_i64(0x7ff8000000000000ull), 1.0)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, f64_reinterpret_i64(0x7ff4000000000000ull), 1.0)) & 9221120237041090560ull),
        9221120237041090560ull,
        "mul(f64_reinterpret_i64(0x7ff4000000000000ull), 1.0)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, f64_reinterpret_i64(0xfff8000000000000ull), -6.283185307179586)) & 9223372036854775807ull),
        9221120237041090560ull,
        "mul(f64_reinterpret_i64(0xfff8000000000000ull), -6.283185307179586)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, f64_reinterpret_i64(0xfff4000000000000ull), -6.283185307179586)) & 9221120237041090560ull),
        9221120237041090560ull,
        "mul(f64_reinterpret_i64(0xfff4000000000000ull), -6.283185307179586)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, f64_reinterpret_i64(0xfff8000000000000ull), 6.283185307179586)) & 9223372036854775807ull),
        9221120237041090560ull,
        "mul(f64_reinterpret_i64(0xfff8000000000000ull), 6.283185307179586)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, f64_reinterpret_i64(0xfff4000000000000ull), 6.283185307179586)) & 9221120237041090560ull),
        9221120237041090560ull,
        "mul(f64_reinterpret_i64(0xfff4000000000000ull), 6.283185307179586)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, f64_reinterpret_i64(0x7ff8000000000000ull), -6.283185307179586)) & 9223372036854775807ull),
        9221120237041090560ull,
        "mul(f64_reinterpret_i64(0x7ff8000000000000ull), -6.283185307179586)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, f64_reinterpret_i64(0x7ff4000000000000ull), -6.283185307179586)) & 9221120237041090560ull),
        9221120237041090560ull,
        "mul(f64_reinterpret_i64(0x7ff4000000000000ull), -6.283185307179586)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, f64_reinterpret_i64(0x7ff8000000000000ull), 6.283185307179586)) & 9223372036854775807ull),
        9221120237041090560ull,
        "mul(f64_reinterpret_i64(0x7ff8000000000000ull), 6.283185307179586)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, f64_reinterpret_i64(0x7ff4000000000000ull), 6.283185307179586)) & 9221120237041090560ull),
        9221120237041090560ull,
        "mul(f64_reinterpret_i64(0x7ff4000000000000ull), 6.283185307179586)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, f64_reinterpret_i64(0xfff8000000000000ull), -1.7976931348623157e+308)) & 9223372036854775807ull),
        9221120237041090560ull,
        "mul(f64_reinterpret_i64(0xfff8000000000000ull), -1.7976931348623157e+308)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, f64_reinterpret_i64(0xfff4000000000000ull), -1.7976931348623157e+308)) & 9221120237041090560ull),
        9221120237041090560ull,
        "mul(f64_reinterpret_i64(0xfff4000000000000ull), -1.7976931348623157e+308)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, f64_reinterpret_i64(0xfff8000000000000ull), 1.7976931348623157e+308)) & 9223372036854775807ull),
        9221120237041090560ull,
        "mul(f64_reinterpret_i64(0xfff8000000000000ull), 1.7976931348623157e+308)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, f64_reinterpret_i64(0xfff4000000000000ull), 1.7976931348623157e+308)) & 9221120237041090560ull),
        9221120237041090560ull,
        "mul(f64_reinterpret_i64(0xfff4000000000000ull), 1.7976931348623157e+308)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, f64_reinterpret_i64(0x7ff8000000000000ull), -1.7976931348623157e+308)) & 9223372036854775807ull),
        9221120237041090560ull,
        "mul(f64_reinterpret_i64(0x7ff8000000000000ull), -1.7976931348623157e+308)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, f64_reinterpret_i64(0x7ff4000000000000ull), -1.7976931348623157e+308)) & 9221120237041090560ull),
        9221120237041090560ull,
        "mul(f64_reinterpret_i64(0x7ff4000000000000ull), -1.7976931348623157e+308)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, f64_reinterpret_i64(0x7ff8000000000000ull), 1.7976931348623157e+308)) & 9223372036854775807ull),
        9221120237041090560ull,
        "mul(f64_reinterpret_i64(0x7ff8000000000000ull), 1.7976931348623157e+308)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, f64_reinterpret_i64(0x7ff4000000000000ull), 1.7976931348623157e+308)) & 9221120237041090560ull),
        9221120237041090560ull,
        "mul(f64_reinterpret_i64(0x7ff4000000000000ull), 1.7976931348623157e+308)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, f64_reinterpret_i64(0xfff8000000000000ull), -INFINITY)) & 9223372036854775807ull),
        9221120237041090560ull,
        "mul(f64_reinterpret_i64(0xfff8000000000000ull), -INFINITY)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, f64_reinterpret_i64(0xfff4000000000000ull), -INFINITY)) & 9221120237041090560ull),
        9221120237041090560ull,
        "mul(f64_reinterpret_i64(0xfff4000000000000ull), -INFINITY)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, f64_reinterpret_i64(0xfff8000000000000ull), INFINITY)) & 9223372036854775807ull),
        9221120237041090560ull,
        "mul(f64_reinterpret_i64(0xfff8000000000000ull), INFINITY)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, f64_reinterpret_i64(0xfff4000000000000ull), INFINITY)) & 9221120237041090560ull),
        9221120237041090560ull,
        "mul(f64_reinterpret_i64(0xfff4000000000000ull), INFINITY)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, f64_reinterpret_i64(0x7ff8000000000000ull), -INFINITY)) & 9223372036854775807ull),
        9221120237041090560ull,
        "mul(f64_reinterpret_i64(0x7ff8000000000000ull), -INFINITY)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, f64_reinterpret_i64(0x7ff4000000000000ull), -INFINITY)) & 9221120237041090560ull),
        9221120237041090560ull,
        "mul(f64_reinterpret_i64(0x7ff4000000000000ull), -INFINITY)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, f64_reinterpret_i64(0x7ff8000000000000ull), INFINITY)) & 9223372036854775807ull),
        9221120237041090560ull,
        "mul(f64_reinterpret_i64(0x7ff8000000000000ull), INFINITY)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, f64_reinterpret_i64(0x7ff4000000000000ull), INFINITY)) & 9221120237041090560ull),
        9221120237041090560ull,
        "mul(f64_reinterpret_i64(0x7ff4000000000000ull), INFINITY)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, f64_reinterpret_i64(0xfff8000000000000ull), f64_reinterpret_i64(0xfff8000000000000ull))) & 9223372036854775807ull),
        9221120237041090560ull,
        "mul(f64_reinterpret_i64(0xfff8000000000000ull), f64_reinterpret_i64(0xfff8000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, f64_reinterpret_i64(0xfff4000000000000ull), f64_reinterpret_i64(0xfff8000000000000ull))) & 9221120237041090560ull),
        9221120237041090560ull,
        "mul(f64_reinterpret_i64(0xfff4000000000000ull), f64_reinterpret_i64(0xfff8000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, f64_reinterpret_i64(0xfff8000000000000ull), f64_reinterpret_i64(0xfff4000000000000ull))) & 9221120237041090560ull),
        9221120237041090560ull,
        "mul(f64_reinterpret_i64(0xfff8000000000000ull), f64_reinterpret_i64(0xfff4000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, f64_reinterpret_i64(0xfff4000000000000ull), f64_reinterpret_i64(0xfff4000000000000ull))) & 9221120237041090560ull),
        9221120237041090560ull,
        "mul(f64_reinterpret_i64(0xfff4000000000000ull), f64_reinterpret_i64(0xfff4000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, f64_reinterpret_i64(0xfff8000000000000ull), f64_reinterpret_i64(0x7ff8000000000000ull))) & 9223372036854775807ull),
        9221120237041090560ull,
        "mul(f64_reinterpret_i64(0xfff8000000000000ull), f64_reinterpret_i64(0x7ff8000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, f64_reinterpret_i64(0xfff4000000000000ull), f64_reinterpret_i64(0x7ff8000000000000ull))) & 9221120237041090560ull),
        9221120237041090560ull,
        "mul(f64_reinterpret_i64(0xfff4000000000000ull), f64_reinterpret_i64(0x7ff8000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, f64_reinterpret_i64(0xfff8000000000000ull), f64_reinterpret_i64(0x7ff4000000000000ull))) & 9221120237041090560ull),
        9221120237041090560ull,
        "mul(f64_reinterpret_i64(0xfff8000000000000ull), f64_reinterpret_i64(0x7ff4000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, f64_reinterpret_i64(0xfff4000000000000ull), f64_reinterpret_i64(0x7ff4000000000000ull))) & 9221120237041090560ull),
        9221120237041090560ull,
        "mul(f64_reinterpret_i64(0xfff4000000000000ull), f64_reinterpret_i64(0x7ff4000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, f64_reinterpret_i64(0x7ff8000000000000ull), f64_reinterpret_i64(0xfff8000000000000ull))) & 9223372036854775807ull),
        9221120237041090560ull,
        "mul(f64_reinterpret_i64(0x7ff8000000000000ull), f64_reinterpret_i64(0xfff8000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, f64_reinterpret_i64(0x7ff4000000000000ull), f64_reinterpret_i64(0xfff8000000000000ull))) & 9221120237041090560ull),
        9221120237041090560ull,
        "mul(f64_reinterpret_i64(0x7ff4000000000000ull), f64_reinterpret_i64(0xfff8000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, f64_reinterpret_i64(0x7ff8000000000000ull), f64_reinterpret_i64(0xfff4000000000000ull))) & 9221120237041090560ull),
        9221120237041090560ull,
        "mul(f64_reinterpret_i64(0x7ff8000000000000ull), f64_reinterpret_i64(0xfff4000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, f64_reinterpret_i64(0x7ff4000000000000ull), f64_reinterpret_i64(0xfff4000000000000ull))) & 9221120237041090560ull),
        9221120237041090560ull,
        "mul(f64_reinterpret_i64(0x7ff4000000000000ull), f64_reinterpret_i64(0xfff4000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, f64_reinterpret_i64(0x7ff8000000000000ull), f64_reinterpret_i64(0x7ff8000000000000ull))) & 9223372036854775807ull),
        9221120237041090560ull,
        "mul(f64_reinterpret_i64(0x7ff8000000000000ull), f64_reinterpret_i64(0x7ff8000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, f64_reinterpret_i64(0x7ff4000000000000ull), f64_reinterpret_i64(0x7ff8000000000000ull))) & 9221120237041090560ull),
        9221120237041090560ull,
        "mul(f64_reinterpret_i64(0x7ff4000000000000ull), f64_reinterpret_i64(0x7ff8000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, f64_reinterpret_i64(0x7ff8000000000000ull), f64_reinterpret_i64(0x7ff4000000000000ull))) & 9221120237041090560ull),
        9221120237041090560ull,
        "mul(f64_reinterpret_i64(0x7ff8000000000000ull), f64_reinterpret_i64(0x7ff4000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_mul(&instance, f64_reinterpret_i64(0x7ff4000000000000ull), f64_reinterpret_i64(0x7ff4000000000000ull))) & 9221120237041090560ull),
        9221120237041090560ull,
        "mul(f64_reinterpret_i64(0x7ff4000000000000ull), f64_reinterpret_i64(0x7ff4000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, -0.0, -0.0)) & 9223372036854775807ull),
        9221120237041090560ull,
        "div(-0.0, -0.0)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, -0.0, 0.0)) & 9223372036854775807ull),
        9221120237041090560ull,
        "div(-0.0, 0.0)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, 0.0, -0.0)) & 9223372036854775807ull),
        9221120237041090560ull,
        "div(0.0, -0.0)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, 0.0, 0.0)) & 9223372036854775807ull),
        9221120237041090560ull,
        "div(0.0, 0.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, -0.0, -5e-324)),
        0ull,
        "div(-0.0, -5e-324)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, -0.0, 5e-324)),
        9223372036854775808ull,
        "div(-0.0, 5e-324)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, 0.0, -5e-324)),
        9223372036854775808ull,
        "div(0.0, -5e-324)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, 0.0, 5e-324)),
        0ull,
        "div(0.0, 5e-324)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, -0.0, -2.2250738585072014e-308)),
        0ull,
        "div(-0.0, -2.2250738585072014e-308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, -0.0, 2.2250738585072014e-308)),
        9223372036854775808ull,
        "div(-0.0, 2.2250738585072014e-308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, 0.0, -2.2250738585072014e-308)),
        9223372036854775808ull,
        "div(0.0, -2.2250738585072014e-308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, 0.0, 2.2250738585072014e-308)),
        0ull,
        "div(0.0, 2.2250738585072014e-308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, -0.0, -0.5)),
        0ull,
        "div(-0.0, -0.5)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, -0.0, 0.5)),
        9223372036854775808ull,
        "div(-0.0, 0.5)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, 0.0, -0.5)),
        9223372036854775808ull,
        "div(0.0, -0.5)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, 0.0, 0.5)),
        0ull,
        "div(0.0, 0.5)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, -0.0, -1.0)),
        0ull,
        "div(-0.0, -1.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, -0.0, 1.0)),
        9223372036854775808ull,
        "div(-0.0, 1.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, 0.0, -1.0)),
        9223372036854775808ull,
        "div(0.0, -1.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, 0.0, 1.0)),
        0ull,
        "div(0.0, 1.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, -0.0, -6.283185307179586)),
        0ull,
        "div(-0.0, -6.283185307179586)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, -0.0, 6.283185307179586)),
        9223372036854775808ull,
        "div(-0.0, 6.283185307179586)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, 0.0, -6.283185307179586)),
        9223372036854775808ull,
        "div(0.0, -6.283185307179586)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, 0.0, 6.283185307179586)),
        0ull,
        "div(0.0, 6.283185307179586)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, -0.0, -1.7976931348623157e+308)),
        0ull,
        "div(-0.0, -1.7976931348623157e+308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, -0.0, 1.7976931348623157e+308)),
        9223372036854775808ull,
        "div(-0.0, 1.7976931348623157e+308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, 0.0, -1.7976931348623157e+308)),
        9223372036854775808ull,
        "div(0.0, -1.7976931348623157e+308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, 0.0, 1.7976931348623157e+308)),
        0ull,
        "div(0.0, 1.7976931348623157e+308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, -0.0, -INFINITY)),
        0ull,
        "div(-0.0, -INFINITY)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, -0.0, INFINITY)),
        9223372036854775808ull,
        "div(-0.0, INFINITY)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, 0.0, -INFINITY)),
        9223372036854775808ull,
        "div(0.0, -INFINITY)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, 0.0, INFINITY)),
        0ull,
        "div(0.0, INFINITY)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, -0.0, f64_reinterpret_i64(0xfff8000000000000ull))) & 9223372036854775807ull),
        9221120237041090560ull,
        "div(-0.0, f64_reinterpret_i64(0xfff8000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, -0.0, f64_reinterpret_i64(0xfff4000000000000ull))) & 9221120237041090560ull),
        9221120237041090560ull,
        "div(-0.0, f64_reinterpret_i64(0xfff4000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, -0.0, f64_reinterpret_i64(0x7ff8000000000000ull))) & 9223372036854775807ull),
        9221120237041090560ull,
        "div(-0.0, f64_reinterpret_i64(0x7ff8000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, -0.0, f64_reinterpret_i64(0x7ff4000000000000ull))) & 9221120237041090560ull),
        9221120237041090560ull,
        "div(-0.0, f64_reinterpret_i64(0x7ff4000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, 0.0, f64_reinterpret_i64(0xfff8000000000000ull))) & 9223372036854775807ull),
        9221120237041090560ull,
        "div(0.0, f64_reinterpret_i64(0xfff8000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, 0.0, f64_reinterpret_i64(0xfff4000000000000ull))) & 9221120237041090560ull),
        9221120237041090560ull,
        "div(0.0, f64_reinterpret_i64(0xfff4000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, 0.0, f64_reinterpret_i64(0x7ff8000000000000ull))) & 9223372036854775807ull),
        9221120237041090560ull,
        "div(0.0, f64_reinterpret_i64(0x7ff8000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, 0.0, f64_reinterpret_i64(0x7ff4000000000000ull))) & 9221120237041090560ull),
        9221120237041090560ull,
        "div(0.0, f64_reinterpret_i64(0x7ff4000000000000ull))"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, -5e-324, -0.0)),
        9218868437227405312ull,
        "div(-5e-324, -0.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, -5e-324, 0.0)),
        18442240474082181120ull,
        "div(-5e-324, 0.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, 5e-324, -0.0)),
        18442240474082181120ull,
        "div(5e-324, -0.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, 5e-324, 0.0)),
        9218868437227405312ull,
        "div(5e-324, 0.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, -5e-324, -5e-324)),
        4607182418800017408ull,
        "div(-5e-324, -5e-324)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, -5e-324, 5e-324)),
        13830554455654793216ull,
        "div(-5e-324, 5e-324)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, 5e-324, -5e-324)),
        13830554455654793216ull,
        "div(5e-324, -5e-324)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, 5e-324, 5e-324)),
        4607182418800017408ull,
        "div(5e-324, 5e-324)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, -5e-324, -2.2250738585072014e-308)),
        4372995238176751616ull,
        "div(-5e-324, -2.2250738585072014e-308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, -5e-324, 2.2250738585072014e-308)),
        13596367275031527424ull,
        "div(-5e-324, 2.2250738585072014e-308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, 5e-324, -2.2250738585072014e-308)),
        13596367275031527424ull,
        "div(5e-324, -2.2250738585072014e-308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, 5e-324, 2.2250738585072014e-308)),
        4372995238176751616ull,
        "div(5e-324, 2.2250738585072014e-308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, -5e-324, -0.5)),
        2ull,
        "div(-5e-324, -0.5)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, -5e-324, 0.5)),
        9223372036854775810ull,
        "div(-5e-324, 0.5)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, 5e-324, -0.5)),
        9223372036854775810ull,
        "div(5e-324, -0.5)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, 5e-324, 0.5)),
        2ull,
        "div(5e-324, 0.5)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, -5e-324, -1.0)),
        1ull,
        "div(-5e-324, -1.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, -5e-324, 1.0)),
        9223372036854775809ull,
        "div(-5e-324, 1.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, 5e-324, -1.0)),
        9223372036854775809ull,
        "div(5e-324, -1.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, 5e-324, 1.0)),
        1ull,
        "div(5e-324, 1.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, -5e-324, -6.283185307179586)),
        0ull,
        "div(-5e-324, -6.283185307179586)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, -5e-324, 6.283185307179586)),
        9223372036854775808ull,
        "div(-5e-324, 6.283185307179586)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, 5e-324, -6.283185307179586)),
        9223372036854775808ull,
        "div(5e-324, -6.283185307179586)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, 5e-324, 6.283185307179586)),
        0ull,
        "div(5e-324, 6.283185307179586)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, -5e-324, -1.7976931348623157e+308)),
        0ull,
        "div(-5e-324, -1.7976931348623157e+308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, -5e-324, 1.7976931348623157e+308)),
        9223372036854775808ull,
        "div(-5e-324, 1.7976931348623157e+308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, 5e-324, -1.7976931348623157e+308)),
        9223372036854775808ull,
        "div(5e-324, -1.7976931348623157e+308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, 5e-324, 1.7976931348623157e+308)),
        0ull,
        "div(5e-324, 1.7976931348623157e+308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, -5e-324, -INFINITY)),
        0ull,
        "div(-5e-324, -INFINITY)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, -5e-324, INFINITY)),
        9223372036854775808ull,
        "div(-5e-324, INFINITY)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, 5e-324, -INFINITY)),
        9223372036854775808ull,
        "div(5e-324, -INFINITY)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, 5e-324, INFINITY)),
        0ull,
        "div(5e-324, INFINITY)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, -5e-324, f64_reinterpret_i64(0xfff8000000000000ull))) & 9223372036854775807ull),
        9221120237041090560ull,
        "div(-5e-324, f64_reinterpret_i64(0xfff8000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, -5e-324, f64_reinterpret_i64(0xfff4000000000000ull))) & 9221120237041090560ull),
        9221120237041090560ull,
        "div(-5e-324, f64_reinterpret_i64(0xfff4000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, -5e-324, f64_reinterpret_i64(0x7ff8000000000000ull))) & 9223372036854775807ull),
        9221120237041090560ull,
        "div(-5e-324, f64_reinterpret_i64(0x7ff8000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, -5e-324, f64_reinterpret_i64(0x7ff4000000000000ull))) & 9221120237041090560ull),
        9221120237041090560ull,
        "div(-5e-324, f64_reinterpret_i64(0x7ff4000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, 5e-324, f64_reinterpret_i64(0xfff8000000000000ull))) & 9223372036854775807ull),
        9221120237041090560ull,
        "div(5e-324, f64_reinterpret_i64(0xfff8000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, 5e-324, f64_reinterpret_i64(0xfff4000000000000ull))) & 9221120237041090560ull),
        9221120237041090560ull,
        "div(5e-324, f64_reinterpret_i64(0xfff4000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, 5e-324, f64_reinterpret_i64(0x7ff8000000000000ull))) & 9223372036854775807ull),
        9221120237041090560ull,
        "div(5e-324, f64_reinterpret_i64(0x7ff8000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, 5e-324, f64_reinterpret_i64(0x7ff4000000000000ull))) & 9221120237041090560ull),
        9221120237041090560ull,
        "div(5e-324, f64_reinterpret_i64(0x7ff4000000000000ull))"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, -2.2250738585072014e-308, -0.0)),
        9218868437227405312ull,
        "div(-2.2250738585072014e-308, -0.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, -2.2250738585072014e-308, 0.0)),
        18442240474082181120ull,
        "div(-2.2250738585072014e-308, 0.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, 2.2250738585072014e-308, -0.0)),
        18442240474082181120ull,
        "div(2.2250738585072014e-308, -0.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, 2.2250738585072014e-308, 0.0)),
        9218868437227405312ull,
        "div(2.2250738585072014e-308, 0.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, -2.2250738585072014e-308, -5e-324)),
        4841369599423283200ull,
        "div(-2.2250738585072014e-308, -5e-324)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, -2.2250738585072014e-308, 5e-324)),
        14064741636278059008ull,
        "div(-2.2250738585072014e-308, 5e-324)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, 2.2250738585072014e-308, -5e-324)),
        14064741636278059008ull,
        "div(2.2250738585072014e-308, -5e-324)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, 2.2250738585072014e-308, 5e-324)),
        4841369599423283200ull,
        "div(2.2250738585072014e-308, 5e-324)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, -2.2250738585072014e-308, -2.2250738585072014e-308)),
        4607182418800017408ull,
        "div(-2.2250738585072014e-308, -2.2250738585072014e-308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, -2.2250738585072014e-308, 2.2250738585072014e-308)),
        13830554455654793216ull,
        "div(-2.2250738585072014e-308, 2.2250738585072014e-308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, 2.2250738585072014e-308, -2.2250738585072014e-308)),
        13830554455654793216ull,
        "div(2.2250738585072014e-308, -2.2250738585072014e-308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, 2.2250738585072014e-308, 2.2250738585072014e-308)),
        4607182418800017408ull,
        "div(2.2250738585072014e-308, 2.2250738585072014e-308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, -2.2250738585072014e-308, -0.5)),
        9007199254740992ull,
        "div(-2.2250738585072014e-308, -0.5)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, -2.2250738585072014e-308, 0.5)),
        9232379236109516800ull,
        "div(-2.2250738585072014e-308, 0.5)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, 2.2250738585072014e-308, -0.5)),
        9232379236109516800ull,
        "div(2.2250738585072014e-308, -0.5)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, 2.2250738585072014e-308, 0.5)),
        9007199254740992ull,
        "div(2.2250738585072014e-308, 0.5)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, -2.2250738585072014e-308, -1.0)),
        4503599627370496ull,
        "div(-2.2250738585072014e-308, -1.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, -2.2250738585072014e-308, 1.0)),
        9227875636482146304ull,
        "div(-2.2250738585072014e-308, 1.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, 2.2250738585072014e-308, -1.0)),
        9227875636482146304ull,
        "div(2.2250738585072014e-308, -1.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, 2.2250738585072014e-308, 1.0)),
        4503599627370496ull,
        "div(2.2250738585072014e-308, 1.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, -2.2250738585072014e-308, -6.283185307179586)),
        716770142402832ull,
        "div(-2.2250738585072014e-308, -6.283185307179586)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, -2.2250738585072014e-308, 6.283185307179586)),
        9224088806997178640ull,
        "div(-2.2250738585072014e-308, 6.283185307179586)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, 2.2250738585072014e-308, -6.283185307179586)),
        9224088806997178640ull,
        "div(2.2250738585072014e-308, -6.283185307179586)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, 2.2250738585072014e-308, 6.283185307179586)),
        716770142402832ull,
        "div(2.2250738585072014e-308, 6.283185307179586)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, -2.2250738585072014e-308, -1.7976931348623157e+308)),
        0ull,
        "div(-2.2250738585072014e-308, -1.7976931348623157e+308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, -2.2250738585072014e-308, 1.7976931348623157e+308)),
        9223372036854775808ull,
        "div(-2.2250738585072014e-308, 1.7976931348623157e+308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, 2.2250738585072014e-308, -1.7976931348623157e+308)),
        9223372036854775808ull,
        "div(2.2250738585072014e-308, -1.7976931348623157e+308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, 2.2250738585072014e-308, 1.7976931348623157e+308)),
        0ull,
        "div(2.2250738585072014e-308, 1.7976931348623157e+308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, -2.2250738585072014e-308, -INFINITY)),
        0ull,
        "div(-2.2250738585072014e-308, -INFINITY)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, -2.2250738585072014e-308, INFINITY)),
        9223372036854775808ull,
        "div(-2.2250738585072014e-308, INFINITY)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, 2.2250738585072014e-308, -INFINITY)),
        9223372036854775808ull,
        "div(2.2250738585072014e-308, -INFINITY)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, 2.2250738585072014e-308, INFINITY)),
        0ull,
        "div(2.2250738585072014e-308, INFINITY)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, -2.2250738585072014e-308, f64_reinterpret_i64(0xfff8000000000000ull))) & 9223372036854775807ull),
        9221120237041090560ull,
        "div(-2.2250738585072014e-308, f64_reinterpret_i64(0xfff8000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, -2.2250738585072014e-308, f64_reinterpret_i64(0xfff4000000000000ull))) & 9221120237041090560ull),
        9221120237041090560ull,
        "div(-2.2250738585072014e-308, f64_reinterpret_i64(0xfff4000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, -2.2250738585072014e-308, f64_reinterpret_i64(0x7ff8000000000000ull))) & 9223372036854775807ull),
        9221120237041090560ull,
        "div(-2.2250738585072014e-308, f64_reinterpret_i64(0x7ff8000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, -2.2250738585072014e-308, f64_reinterpret_i64(0x7ff4000000000000ull))) & 9221120237041090560ull),
        9221120237041090560ull,
        "div(-2.2250738585072014e-308, f64_reinterpret_i64(0x7ff4000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, 2.2250738585072014e-308, f64_reinterpret_i64(0xfff8000000000000ull))) & 9223372036854775807ull),
        9221120237041090560ull,
        "div(2.2250738585072014e-308, f64_reinterpret_i64(0xfff8000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, 2.2250738585072014e-308, f64_reinterpret_i64(0xfff4000000000000ull))) & 9221120237041090560ull),
        9221120237041090560ull,
        "div(2.2250738585072014e-308, f64_reinterpret_i64(0xfff4000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, 2.2250738585072014e-308, f64_reinterpret_i64(0x7ff8000000000000ull))) & 9223372036854775807ull),
        9221120237041090560ull,
        "div(2.2250738585072014e-308, f64_reinterpret_i64(0x7ff8000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, 2.2250738585072014e-308, f64_reinterpret_i64(0x7ff4000000000000ull))) & 9221120237041090560ull),
        9221120237041090560ull,
        "div(2.2250738585072014e-308, f64_reinterpret_i64(0x7ff4000000000000ull))"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, -0.5, -0.0)),
        9218868437227405312ull,
        "div(-0.5, -0.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, -0.5, 0.0)),
        18442240474082181120ull,
        "div(-0.5, 0.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, 0.5, -0.0)),
        18442240474082181120ull,
        "div(0.5, -0.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, 0.5, 0.0)),
        9218868437227405312ull,
        "div(0.5, 0.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, -0.5, -5e-324)),
        9218868437227405312ull,
        "div(-0.5, -5e-324)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, -0.5, 5e-324)),
        18442240474082181120ull,
        "div(-0.5, 5e-324)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, 0.5, -5e-324)),
        18442240474082181120ull,
        "div(0.5, -5e-324)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, 0.5, 5e-324)),
        9218868437227405312ull,
        "div(0.5, 5e-324)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, -0.5, -2.2250738585072014e-308)),
        9205357638345293824ull,
        "div(-0.5, -2.2250738585072014e-308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, -0.5, 2.2250738585072014e-308)),
        18428729675200069632ull,
        "div(-0.5, 2.2250738585072014e-308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, 0.5, -2.2250738585072014e-308)),
        18428729675200069632ull,
        "div(0.5, -2.2250738585072014e-308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, 0.5, 2.2250738585072014e-308)),
        9205357638345293824ull,
        "div(0.5, 2.2250738585072014e-308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, -0.5, -0.5)),
        4607182418800017408ull,
        "div(-0.5, -0.5)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, -0.5, 0.5)),
        13830554455654793216ull,
        "div(-0.5, 0.5)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, 0.5, -0.5)),
        13830554455654793216ull,
        "div(0.5, -0.5)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, 0.5, 0.5)),
        4607182418800017408ull,
        "div(0.5, 0.5)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, -0.5, -1.0)),
        4602678819172646912ull,
        "div(-0.5, -1.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, -0.5, 1.0)),
        13826050856027422720ull,
        "div(-0.5, 1.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, 0.5, -1.0)),
        13826050856027422720ull,
        "div(0.5, -1.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, 0.5, 1.0)),
        4602678819172646912ull,
        "div(0.5, 1.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, -0.5, -6.283185307179586)),
        4590398581802387587ull,
        "div(-0.5, -6.283185307179586)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, -0.5, 6.283185307179586)),
        13813770618657163395ull,
        "div(-0.5, 6.283185307179586)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, 0.5, -6.283185307179586)),
        13813770618657163395ull,
        "div(0.5, -6.283185307179586)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, 0.5, 6.283185307179586)),
        4590398581802387587ull,
        "div(0.5, 6.283185307179586)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, -0.5, -1.7976931348623157e+308)),
        562949953421312ull,
        "div(-0.5, -1.7976931348623157e+308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, -0.5, 1.7976931348623157e+308)),
        9223934986808197120ull,
        "div(-0.5, 1.7976931348623157e+308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, 0.5, -1.7976931348623157e+308)),
        9223934986808197120ull,
        "div(0.5, -1.7976931348623157e+308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, 0.5, 1.7976931348623157e+308)),
        562949953421312ull,
        "div(0.5, 1.7976931348623157e+308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, -0.5, -INFINITY)),
        0ull,
        "div(-0.5, -INFINITY)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, -0.5, INFINITY)),
        9223372036854775808ull,
        "div(-0.5, INFINITY)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, 0.5, -INFINITY)),
        9223372036854775808ull,
        "div(0.5, -INFINITY)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, 0.5, INFINITY)),
        0ull,
        "div(0.5, INFINITY)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, -0.5, f64_reinterpret_i64(0xfff8000000000000ull))) & 9223372036854775807ull),
        9221120237041090560ull,
        "div(-0.5, f64_reinterpret_i64(0xfff8000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, -0.5, f64_reinterpret_i64(0xfff4000000000000ull))) & 9221120237041090560ull),
        9221120237041090560ull,
        "div(-0.5, f64_reinterpret_i64(0xfff4000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, -0.5, f64_reinterpret_i64(0x7ff8000000000000ull))) & 9223372036854775807ull),
        9221120237041090560ull,
        "div(-0.5, f64_reinterpret_i64(0x7ff8000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, -0.5, f64_reinterpret_i64(0x7ff4000000000000ull))) & 9221120237041090560ull),
        9221120237041090560ull,
        "div(-0.5, f64_reinterpret_i64(0x7ff4000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, 0.5, f64_reinterpret_i64(0xfff8000000000000ull))) & 9223372036854775807ull),
        9221120237041090560ull,
        "div(0.5, f64_reinterpret_i64(0xfff8000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, 0.5, f64_reinterpret_i64(0xfff4000000000000ull))) & 9221120237041090560ull),
        9221120237041090560ull,
        "div(0.5, f64_reinterpret_i64(0xfff4000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, 0.5, f64_reinterpret_i64(0x7ff8000000000000ull))) & 9223372036854775807ull),
        9221120237041090560ull,
        "div(0.5, f64_reinterpret_i64(0x7ff8000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, 0.5, f64_reinterpret_i64(0x7ff4000000000000ull))) & 9221120237041090560ull),
        9221120237041090560ull,
        "div(0.5, f64_reinterpret_i64(0x7ff4000000000000ull))"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, -1.0, -0.0)),
        9218868437227405312ull,
        "div(-1.0, -0.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, -1.0, 0.0)),
        18442240474082181120ull,
        "div(-1.0, 0.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, 1.0, -0.0)),
        18442240474082181120ull,
        "div(1.0, -0.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, 1.0, 0.0)),
        9218868437227405312ull,
        "div(1.0, 0.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, -1.0, -5e-324)),
        9218868437227405312ull,
        "div(-1.0, -5e-324)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, -1.0, 5e-324)),
        18442240474082181120ull,
        "div(-1.0, 5e-324)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, 1.0, -5e-324)),
        18442240474082181120ull,
        "div(1.0, -5e-324)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, 1.0, 5e-324)),
        9218868437227405312ull,
        "div(1.0, 5e-324)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, -1.0, -2.2250738585072014e-308)),
        9209861237972664320ull,
        "div(-1.0, -2.2250738585072014e-308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, -1.0, 2.2250738585072014e-308)),
        18433233274827440128ull,
        "div(-1.0, 2.2250738585072014e-308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, 1.0, -2.2250738585072014e-308)),
        18433233274827440128ull,
        "div(1.0, -2.2250738585072014e-308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, 1.0, 2.2250738585072014e-308)),
        9209861237972664320ull,
        "div(1.0, 2.2250738585072014e-308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, -1.0, -0.5)),
        4611686018427387904ull,
        "div(-1.0, -0.5)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, -1.0, 0.5)),
        13835058055282163712ull,
        "div(-1.0, 0.5)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, 1.0, -0.5)),
        13835058055282163712ull,
        "div(1.0, -0.5)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, 1.0, 0.5)),
        4611686018427387904ull,
        "div(1.0, 0.5)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, -1.0, -1.0)),
        4607182418800017408ull,
        "div(-1.0, -1.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, -1.0, 1.0)),
        13830554455654793216ull,
        "div(-1.0, 1.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, 1.0, -1.0)),
        13830554455654793216ull,
        "div(1.0, -1.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, 1.0, 1.0)),
        4607182418800017408ull,
        "div(1.0, 1.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, -1.0, -6.283185307179586)),
        4594902181429758083ull,
        "div(-1.0, -6.283185307179586)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, -1.0, 6.283185307179586)),
        13818274218284533891ull,
        "div(-1.0, 6.283185307179586)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, 1.0, -6.283185307179586)),
        13818274218284533891ull,
        "div(1.0, -6.283185307179586)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, 1.0, 6.283185307179586)),
        4594902181429758083ull,
        "div(1.0, 6.283185307179586)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, -1.0, -1.7976931348623157e+308)),
        1125899906842624ull,
        "div(-1.0, -1.7976931348623157e+308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, -1.0, 1.7976931348623157e+308)),
        9224497936761618432ull,
        "div(-1.0, 1.7976931348623157e+308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, 1.0, -1.7976931348623157e+308)),
        9224497936761618432ull,
        "div(1.0, -1.7976931348623157e+308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, 1.0, 1.7976931348623157e+308)),
        1125899906842624ull,
        "div(1.0, 1.7976931348623157e+308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, -1.0, -INFINITY)),
        0ull,
        "div(-1.0, -INFINITY)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, -1.0, INFINITY)),
        9223372036854775808ull,
        "div(-1.0, INFINITY)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, 1.0, -INFINITY)),
        9223372036854775808ull,
        "div(1.0, -INFINITY)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, 1.0, INFINITY)),
        0ull,
        "div(1.0, INFINITY)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, -1.0, f64_reinterpret_i64(0xfff8000000000000ull))) & 9223372036854775807ull),
        9221120237041090560ull,
        "div(-1.0, f64_reinterpret_i64(0xfff8000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, -1.0, f64_reinterpret_i64(0xfff4000000000000ull))) & 9221120237041090560ull),
        9221120237041090560ull,
        "div(-1.0, f64_reinterpret_i64(0xfff4000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, -1.0, f64_reinterpret_i64(0x7ff8000000000000ull))) & 9223372036854775807ull),
        9221120237041090560ull,
        "div(-1.0, f64_reinterpret_i64(0x7ff8000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, -1.0, f64_reinterpret_i64(0x7ff4000000000000ull))) & 9221120237041090560ull),
        9221120237041090560ull,
        "div(-1.0, f64_reinterpret_i64(0x7ff4000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, 1.0, f64_reinterpret_i64(0xfff8000000000000ull))) & 9223372036854775807ull),
        9221120237041090560ull,
        "div(1.0, f64_reinterpret_i64(0xfff8000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, 1.0, f64_reinterpret_i64(0xfff4000000000000ull))) & 9221120237041090560ull),
        9221120237041090560ull,
        "div(1.0, f64_reinterpret_i64(0xfff4000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, 1.0, f64_reinterpret_i64(0x7ff8000000000000ull))) & 9223372036854775807ull),
        9221120237041090560ull,
        "div(1.0, f64_reinterpret_i64(0x7ff8000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, 1.0, f64_reinterpret_i64(0x7ff4000000000000ull))) & 9221120237041090560ull),
        9221120237041090560ull,
        "div(1.0, f64_reinterpret_i64(0x7ff4000000000000ull))"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, -6.283185307179586, -0.0)),
        9218868437227405312ull,
        "div(-6.283185307179586, -0.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, -6.283185307179586, 0.0)),
        18442240474082181120ull,
        "div(-6.283185307179586, 0.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, 6.283185307179586, -0.0)),
        18442240474082181120ull,
        "div(6.283185307179586, -0.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, 6.283185307179586, 0.0)),
        9218868437227405312ull,
        "div(6.283185307179586, 0.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, -6.283185307179586, -5e-324)),
        9218868437227405312ull,
        "div(-6.283185307179586, -5e-324)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, -6.283185307179586, 5e-324)),
        18442240474082181120ull,
        "div(-6.283185307179586, 5e-324)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, 6.283185307179586, -5e-324)),
        18442240474082181120ull,
        "div(6.283185307179586, -5e-324)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, 6.283185307179586, 5e-324)),
        9218868437227405312ull,
        "div(6.283185307179586, 5e-324)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, -6.283185307179586, -2.2250738585072014e-308)),
        9218868437227405312ull,
        "div(-6.283185307179586, -2.2250738585072014e-308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, -6.283185307179586, 2.2250738585072014e-308)),
        18442240474082181120ull,
        "div(-6.283185307179586, 2.2250738585072014e-308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, 6.283185307179586, -2.2250738585072014e-308)),
        18442240474082181120ull,
        "div(6.283185307179586, -2.2250738585072014e-308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, 6.283185307179586, 2.2250738585072014e-308)),
        9218868437227405312ull,
        "div(6.283185307179586, 2.2250738585072014e-308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, -6.283185307179586, -0.5)),
        4623263855806786840ull,
        "div(-6.283185307179586, -0.5)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, -6.283185307179586, 0.5)),
        13846635892661562648ull,
        "div(-6.283185307179586, 0.5)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, 6.283185307179586, -0.5)),
        13846635892661562648ull,
        "div(6.283185307179586, -0.5)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, 6.283185307179586, 0.5)),
        4623263855806786840ull,
        "div(6.283185307179586, 0.5)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, -6.283185307179586, -1.0)),
        4618760256179416344ull,
        "div(-6.283185307179586, -1.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, -6.283185307179586, 1.0)),
        13842132293034192152ull,
        "div(-6.283185307179586, 1.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, 6.283185307179586, -1.0)),
        13842132293034192152ull,
        "div(6.283185307179586, -1.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, 6.283185307179586, 1.0)),
        4618760256179416344ull,
        "div(6.283185307179586, 1.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, -6.283185307179586, -6.283185307179586)),
        4607182418800017408ull,
        "div(-6.283185307179586, -6.283185307179586)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, -6.283185307179586, 6.283185307179586)),
        13830554455654793216ull,
        "div(-6.283185307179586, 6.283185307179586)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, 6.283185307179586, -6.283185307179586)),
        13830554455654793216ull,
        "div(6.283185307179586, -6.283185307179586)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, 6.283185307179586, 6.283185307179586)),
        4607182418800017408ull,
        "div(6.283185307179586, 6.283185307179586)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, -6.283185307179586, -1.7976931348623157e+308)),
        7074237752028441ull,
        "div(-6.283185307179586, -1.7976931348623157e+308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, -6.283185307179586, 1.7976931348623157e+308)),
        9230446274606804249ull,
        "div(-6.283185307179586, 1.7976931348623157e+308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, 6.283185307179586, -1.7976931348623157e+308)),
        9230446274606804249ull,
        "div(6.283185307179586, -1.7976931348623157e+308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, 6.283185307179586, 1.7976931348623157e+308)),
        7074237752028441ull,
        "div(6.283185307179586, 1.7976931348623157e+308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, -6.283185307179586, -INFINITY)),
        0ull,
        "div(-6.283185307179586, -INFINITY)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, -6.283185307179586, INFINITY)),
        9223372036854775808ull,
        "div(-6.283185307179586, INFINITY)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, 6.283185307179586, -INFINITY)),
        9223372036854775808ull,
        "div(6.283185307179586, -INFINITY)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, 6.283185307179586, INFINITY)),
        0ull,
        "div(6.283185307179586, INFINITY)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, -6.283185307179586, f64_reinterpret_i64(0xfff8000000000000ull))) & 9223372036854775807ull),
        9221120237041090560ull,
        "div(-6.283185307179586, f64_reinterpret_i64(0xfff8000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, -6.283185307179586, f64_reinterpret_i64(0xfff4000000000000ull))) & 9221120237041090560ull),
        9221120237041090560ull,
        "div(-6.283185307179586, f64_reinterpret_i64(0xfff4000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, -6.283185307179586, f64_reinterpret_i64(0x7ff8000000000000ull))) & 9223372036854775807ull),
        9221120237041090560ull,
        "div(-6.283185307179586, f64_reinterpret_i64(0x7ff8000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, -6.283185307179586, f64_reinterpret_i64(0x7ff4000000000000ull))) & 9221120237041090560ull),
        9221120237041090560ull,
        "div(-6.283185307179586, f64_reinterpret_i64(0x7ff4000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, 6.283185307179586, f64_reinterpret_i64(0xfff8000000000000ull))) & 9223372036854775807ull),
        9221120237041090560ull,
        "div(6.283185307179586, f64_reinterpret_i64(0xfff8000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, 6.283185307179586, f64_reinterpret_i64(0xfff4000000000000ull))) & 9221120237041090560ull),
        9221120237041090560ull,
        "div(6.283185307179586, f64_reinterpret_i64(0xfff4000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, 6.283185307179586, f64_reinterpret_i64(0x7ff8000000000000ull))) & 9223372036854775807ull),
        9221120237041090560ull,
        "div(6.283185307179586, f64_reinterpret_i64(0x7ff8000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, 6.283185307179586, f64_reinterpret_i64(0x7ff4000000000000ull))) & 9221120237041090560ull),
        9221120237041090560ull,
        "div(6.283185307179586, f64_reinterpret_i64(0x7ff4000000000000ull))"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, -1.7976931348623157e+308, -0.0)),
        9218868437227405312ull,
        "div(-1.7976931348623157e+308, -0.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, -1.7976931348623157e+308, 0.0)),
        18442240474082181120ull,
        "div(-1.7976931348623157e+308, 0.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, 1.7976931348623157e+308, -0.0)),
        18442240474082181120ull,
        "div(1.7976931348623157e+308, -0.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, 1.7976931348623157e+308, 0.0)),
        9218868437227405312ull,
        "div(1.7976931348623157e+308, 0.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, -1.7976931348623157e+308, -5e-324)),
        9218868437227405312ull,
        "div(-1.7976931348623157e+308, -5e-324)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, -1.7976931348623157e+308, 5e-324)),
        18442240474082181120ull,
        "div(-1.7976931348623157e+308, 5e-324)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, 1.7976931348623157e+308, -5e-324)),
        18442240474082181120ull,
        "div(1.7976931348623157e+308, -5e-324)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, 1.7976931348623157e+308, 5e-324)),
        9218868437227405312ull,
        "div(1.7976931348623157e+308, 5e-324)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, -1.7976931348623157e+308, -2.2250738585072014e-308)),
        9218868437227405312ull,
        "div(-1.7976931348623157e+308, -2.2250738585072014e-308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, -1.7976931348623157e+308, 2.2250738585072014e-308)),
        18442240474082181120ull,
        "div(-1.7976931348623157e+308, 2.2250738585072014e-308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, 1.7976931348623157e+308, -2.2250738585072014e-308)),
        18442240474082181120ull,
        "div(1.7976931348623157e+308, -2.2250738585072014e-308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, 1.7976931348623157e+308, 2.2250738585072014e-308)),
        9218868437227405312ull,
        "div(1.7976931348623157e+308, 2.2250738585072014e-308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, -1.7976931348623157e+308, -0.5)),
        9218868437227405312ull,
        "div(-1.7976931348623157e+308, -0.5)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, -1.7976931348623157e+308, 0.5)),
        18442240474082181120ull,
        "div(-1.7976931348623157e+308, 0.5)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, 1.7976931348623157e+308, -0.5)),
        18442240474082181120ull,
        "div(1.7976931348623157e+308, -0.5)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, 1.7976931348623157e+308, 0.5)),
        9218868437227405312ull,
        "div(1.7976931348623157e+308, 0.5)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, -1.7976931348623157e+308, -1.0)),
        9218868437227405311ull,
        "div(-1.7976931348623157e+308, -1.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, -1.7976931348623157e+308, 1.0)),
        18442240474082181119ull,
        "div(-1.7976931348623157e+308, 1.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, 1.7976931348623157e+308, -1.0)),
        18442240474082181119ull,
        "div(1.7976931348623157e+308, -1.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, 1.7976931348623157e+308, 1.0)),
        9218868437227405311ull,
        "div(1.7976931348623157e+308, 1.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, -1.7976931348623157e+308, -6.283185307179586)),
        9206588199857145986ull,
        "div(-1.7976931348623157e+308, -6.283185307179586)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, -1.7976931348623157e+308, 6.283185307179586)),
        18429960236711921794ull,
        "div(-1.7976931348623157e+308, 6.283185307179586)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, 1.7976931348623157e+308, -6.283185307179586)),
        18429960236711921794ull,
        "div(1.7976931348623157e+308, -6.283185307179586)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, 1.7976931348623157e+308, 6.283185307179586)),
        9206588199857145986ull,
        "div(1.7976931348623157e+308, 6.283185307179586)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, -1.7976931348623157e+308, -1.7976931348623157e+308)),
        4607182418800017408ull,
        "div(-1.7976931348623157e+308, -1.7976931348623157e+308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, -1.7976931348623157e+308, 1.7976931348623157e+308)),
        13830554455654793216ull,
        "div(-1.7976931348623157e+308, 1.7976931348623157e+308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, 1.7976931348623157e+308, -1.7976931348623157e+308)),
        13830554455654793216ull,
        "div(1.7976931348623157e+308, -1.7976931348623157e+308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, 1.7976931348623157e+308, 1.7976931348623157e+308)),
        4607182418800017408ull,
        "div(1.7976931348623157e+308, 1.7976931348623157e+308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, -1.7976931348623157e+308, -INFINITY)),
        0ull,
        "div(-1.7976931348623157e+308, -INFINITY)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, -1.7976931348623157e+308, INFINITY)),
        9223372036854775808ull,
        "div(-1.7976931348623157e+308, INFINITY)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, 1.7976931348623157e+308, -INFINITY)),
        9223372036854775808ull,
        "div(1.7976931348623157e+308, -INFINITY)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, 1.7976931348623157e+308, INFINITY)),
        0ull,
        "div(1.7976931348623157e+308, INFINITY)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, -1.7976931348623157e+308, f64_reinterpret_i64(0xfff8000000000000ull))) & 9223372036854775807ull),
        9221120237041090560ull,
        "div(-1.7976931348623157e+308, f64_reinterpret_i64(0xfff8000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, -1.7976931348623157e+308, f64_reinterpret_i64(0xfff4000000000000ull))) & 9221120237041090560ull),
        9221120237041090560ull,
        "div(-1.7976931348623157e+308, f64_reinterpret_i64(0xfff4000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, -1.7976931348623157e+308, f64_reinterpret_i64(0x7ff8000000000000ull))) & 9223372036854775807ull),
        9221120237041090560ull,
        "div(-1.7976931348623157e+308, f64_reinterpret_i64(0x7ff8000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, -1.7976931348623157e+308, f64_reinterpret_i64(0x7ff4000000000000ull))) & 9221120237041090560ull),
        9221120237041090560ull,
        "div(-1.7976931348623157e+308, f64_reinterpret_i64(0x7ff4000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, 1.7976931348623157e+308, f64_reinterpret_i64(0xfff8000000000000ull))) & 9223372036854775807ull),
        9221120237041090560ull,
        "div(1.7976931348623157e+308, f64_reinterpret_i64(0xfff8000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, 1.7976931348623157e+308, f64_reinterpret_i64(0xfff4000000000000ull))) & 9221120237041090560ull),
        9221120237041090560ull,
        "div(1.7976931348623157e+308, f64_reinterpret_i64(0xfff4000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, 1.7976931348623157e+308, f64_reinterpret_i64(0x7ff8000000000000ull))) & 9223372036854775807ull),
        9221120237041090560ull,
        "div(1.7976931348623157e+308, f64_reinterpret_i64(0x7ff8000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, 1.7976931348623157e+308, f64_reinterpret_i64(0x7ff4000000000000ull))) & 9221120237041090560ull),
        9221120237041090560ull,
        "div(1.7976931348623157e+308, f64_reinterpret_i64(0x7ff4000000000000ull))"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, -INFINITY, -0.0)),
        9218868437227405312ull,
        "div(-INFINITY, -0.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, -INFINITY, 0.0)),
        18442240474082181120ull,
        "div(-INFINITY, 0.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, INFINITY, -0.0)),
        18442240474082181120ull,
        "div(INFINITY, -0.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, INFINITY, 0.0)),
        9218868437227405312ull,
        "div(INFINITY, 0.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, -INFINITY, -5e-324)),
        9218868437227405312ull,
        "div(-INFINITY, -5e-324)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, -INFINITY, 5e-324)),
        18442240474082181120ull,
        "div(-INFINITY, 5e-324)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, INFINITY, -5e-324)),
        18442240474082181120ull,
        "div(INFINITY, -5e-324)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, INFINITY, 5e-324)),
        9218868437227405312ull,
        "div(INFINITY, 5e-324)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, -INFINITY, -2.2250738585072014e-308)),
        9218868437227405312ull,
        "div(-INFINITY, -2.2250738585072014e-308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, -INFINITY, 2.2250738585072014e-308)),
        18442240474082181120ull,
        "div(-INFINITY, 2.2250738585072014e-308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, INFINITY, -2.2250738585072014e-308)),
        18442240474082181120ull,
        "div(INFINITY, -2.2250738585072014e-308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, INFINITY, 2.2250738585072014e-308)),
        9218868437227405312ull,
        "div(INFINITY, 2.2250738585072014e-308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, -INFINITY, -0.5)),
        9218868437227405312ull,
        "div(-INFINITY, -0.5)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, -INFINITY, 0.5)),
        18442240474082181120ull,
        "div(-INFINITY, 0.5)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, INFINITY, -0.5)),
        18442240474082181120ull,
        "div(INFINITY, -0.5)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, INFINITY, 0.5)),
        9218868437227405312ull,
        "div(INFINITY, 0.5)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, -INFINITY, -1.0)),
        9218868437227405312ull,
        "div(-INFINITY, -1.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, -INFINITY, 1.0)),
        18442240474082181120ull,
        "div(-INFINITY, 1.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, INFINITY, -1.0)),
        18442240474082181120ull,
        "div(INFINITY, -1.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, INFINITY, 1.0)),
        9218868437227405312ull,
        "div(INFINITY, 1.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, -INFINITY, -6.283185307179586)),
        9218868437227405312ull,
        "div(-INFINITY, -6.283185307179586)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, -INFINITY, 6.283185307179586)),
        18442240474082181120ull,
        "div(-INFINITY, 6.283185307179586)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, INFINITY, -6.283185307179586)),
        18442240474082181120ull,
        "div(INFINITY, -6.283185307179586)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, INFINITY, 6.283185307179586)),
        9218868437227405312ull,
        "div(INFINITY, 6.283185307179586)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, -INFINITY, -1.7976931348623157e+308)),
        9218868437227405312ull,
        "div(-INFINITY, -1.7976931348623157e+308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, -INFINITY, 1.7976931348623157e+308)),
        18442240474082181120ull,
        "div(-INFINITY, 1.7976931348623157e+308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, INFINITY, -1.7976931348623157e+308)),
        18442240474082181120ull,
        "div(INFINITY, -1.7976931348623157e+308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, INFINITY, 1.7976931348623157e+308)),
        9218868437227405312ull,
        "div(INFINITY, 1.7976931348623157e+308)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, -INFINITY, -INFINITY)) & 9223372036854775807ull),
        9221120237041090560ull,
        "div(-INFINITY, -INFINITY)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, -INFINITY, INFINITY)) & 9223372036854775807ull),
        9221120237041090560ull,
        "div(-INFINITY, INFINITY)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, INFINITY, -INFINITY)) & 9223372036854775807ull),
        9221120237041090560ull,
        "div(INFINITY, -INFINITY)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, INFINITY, INFINITY)) & 9223372036854775807ull),
        9221120237041090560ull,
        "div(INFINITY, INFINITY)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, -INFINITY, f64_reinterpret_i64(0xfff8000000000000ull))) & 9223372036854775807ull),
        9221120237041090560ull,
        "div(-INFINITY, f64_reinterpret_i64(0xfff8000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, -INFINITY, f64_reinterpret_i64(0xfff4000000000000ull))) & 9221120237041090560ull),
        9221120237041090560ull,
        "div(-INFINITY, f64_reinterpret_i64(0xfff4000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, -INFINITY, f64_reinterpret_i64(0x7ff8000000000000ull))) & 9223372036854775807ull),
        9221120237041090560ull,
        "div(-INFINITY, f64_reinterpret_i64(0x7ff8000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, -INFINITY, f64_reinterpret_i64(0x7ff4000000000000ull))) & 9221120237041090560ull),
        9221120237041090560ull,
        "div(-INFINITY, f64_reinterpret_i64(0x7ff4000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, INFINITY, f64_reinterpret_i64(0xfff8000000000000ull))) & 9223372036854775807ull),
        9221120237041090560ull,
        "div(INFINITY, f64_reinterpret_i64(0xfff8000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, INFINITY, f64_reinterpret_i64(0xfff4000000000000ull))) & 9221120237041090560ull),
        9221120237041090560ull,
        "div(INFINITY, f64_reinterpret_i64(0xfff4000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, INFINITY, f64_reinterpret_i64(0x7ff8000000000000ull))) & 9223372036854775807ull),
        9221120237041090560ull,
        "div(INFINITY, f64_reinterpret_i64(0x7ff8000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, INFINITY, f64_reinterpret_i64(0x7ff4000000000000ull))) & 9221120237041090560ull),
        9221120237041090560ull,
        "div(INFINITY, f64_reinterpret_i64(0x7ff4000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, f64_reinterpret_i64(0xfff8000000000000ull), -0.0)) & 9223372036854775807ull),
        9221120237041090560ull,
        "div(f64_reinterpret_i64(0xfff8000000000000ull), -0.0)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, f64_reinterpret_i64(0xfff4000000000000ull), -0.0)) & 9221120237041090560ull),
        9221120237041090560ull,
        "div(f64_reinterpret_i64(0xfff4000000000000ull), -0.0)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, f64_reinterpret_i64(0xfff8000000000000ull), 0.0)) & 9223372036854775807ull),
        9221120237041090560ull,
        "div(f64_reinterpret_i64(0xfff8000000000000ull), 0.0)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, f64_reinterpret_i64(0xfff4000000000000ull), 0.0)) & 9221120237041090560ull),
        9221120237041090560ull,
        "div(f64_reinterpret_i64(0xfff4000000000000ull), 0.0)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, f64_reinterpret_i64(0x7ff8000000000000ull), -0.0)) & 9223372036854775807ull),
        9221120237041090560ull,
        "div(f64_reinterpret_i64(0x7ff8000000000000ull), -0.0)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, f64_reinterpret_i64(0x7ff4000000000000ull), -0.0)) & 9221120237041090560ull),
        9221120237041090560ull,
        "div(f64_reinterpret_i64(0x7ff4000000000000ull), -0.0)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, f64_reinterpret_i64(0x7ff8000000000000ull), 0.0)) & 9223372036854775807ull),
        9221120237041090560ull,
        "div(f64_reinterpret_i64(0x7ff8000000000000ull), 0.0)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, f64_reinterpret_i64(0x7ff4000000000000ull), 0.0)) & 9221120237041090560ull),
        9221120237041090560ull,
        "div(f64_reinterpret_i64(0x7ff4000000000000ull), 0.0)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, f64_reinterpret_i64(0xfff8000000000000ull), -5e-324)) & 9223372036854775807ull),
        9221120237041090560ull,
        "div(f64_reinterpret_i64(0xfff8000000000000ull), -5e-324)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, f64_reinterpret_i64(0xfff4000000000000ull), -5e-324)) & 9221120237041090560ull),
        9221120237041090560ull,
        "div(f64_reinterpret_i64(0xfff4000000000000ull), -5e-324)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, f64_reinterpret_i64(0xfff8000000000000ull), 5e-324)) & 9223372036854775807ull),
        9221120237041090560ull,
        "div(f64_reinterpret_i64(0xfff8000000000000ull), 5e-324)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, f64_reinterpret_i64(0xfff4000000000000ull), 5e-324)) & 9221120237041090560ull),
        9221120237041090560ull,
        "div(f64_reinterpret_i64(0xfff4000000000000ull), 5e-324)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, f64_reinterpret_i64(0x7ff8000000000000ull), -5e-324)) & 9223372036854775807ull),
        9221120237041090560ull,
        "div(f64_reinterpret_i64(0x7ff8000000000000ull), -5e-324)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, f64_reinterpret_i64(0x7ff4000000000000ull), -5e-324)) & 9221120237041090560ull),
        9221120237041090560ull,
        "div(f64_reinterpret_i64(0x7ff4000000000000ull), -5e-324)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, f64_reinterpret_i64(0x7ff8000000000000ull), 5e-324)) & 9223372036854775807ull),
        9221120237041090560ull,
        "div(f64_reinterpret_i64(0x7ff8000000000000ull), 5e-324)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, f64_reinterpret_i64(0x7ff4000000000000ull), 5e-324)) & 9221120237041090560ull),
        9221120237041090560ull,
        "div(f64_reinterpret_i64(0x7ff4000000000000ull), 5e-324)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, f64_reinterpret_i64(0xfff8000000000000ull), -2.2250738585072014e-308)) & 9223372036854775807ull),
        9221120237041090560ull,
        "div(f64_reinterpret_i64(0xfff8000000000000ull), -2.2250738585072014e-308)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, f64_reinterpret_i64(0xfff4000000000000ull), -2.2250738585072014e-308)) & 9221120237041090560ull),
        9221120237041090560ull,
        "div(f64_reinterpret_i64(0xfff4000000000000ull), -2.2250738585072014e-308)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, f64_reinterpret_i64(0xfff8000000000000ull), 2.2250738585072014e-308)) & 9223372036854775807ull),
        9221120237041090560ull,
        "div(f64_reinterpret_i64(0xfff8000000000000ull), 2.2250738585072014e-308)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, f64_reinterpret_i64(0xfff4000000000000ull), 2.2250738585072014e-308)) & 9221120237041090560ull),
        9221120237041090560ull,
        "div(f64_reinterpret_i64(0xfff4000000000000ull), 2.2250738585072014e-308)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, f64_reinterpret_i64(0x7ff8000000000000ull), -2.2250738585072014e-308)) & 9223372036854775807ull),
        9221120237041090560ull,
        "div(f64_reinterpret_i64(0x7ff8000000000000ull), -2.2250738585072014e-308)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, f64_reinterpret_i64(0x7ff4000000000000ull), -2.2250738585072014e-308)) & 9221120237041090560ull),
        9221120237041090560ull,
        "div(f64_reinterpret_i64(0x7ff4000000000000ull), -2.2250738585072014e-308)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, f64_reinterpret_i64(0x7ff8000000000000ull), 2.2250738585072014e-308)) & 9223372036854775807ull),
        9221120237041090560ull,
        "div(f64_reinterpret_i64(0x7ff8000000000000ull), 2.2250738585072014e-308)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, f64_reinterpret_i64(0x7ff4000000000000ull), 2.2250738585072014e-308)) & 9221120237041090560ull),
        9221120237041090560ull,
        "div(f64_reinterpret_i64(0x7ff4000000000000ull), 2.2250738585072014e-308)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, f64_reinterpret_i64(0xfff8000000000000ull), -0.5)) & 9223372036854775807ull),
        9221120237041090560ull,
        "div(f64_reinterpret_i64(0xfff8000000000000ull), -0.5)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, f64_reinterpret_i64(0xfff4000000000000ull), -0.5)) & 9221120237041090560ull),
        9221120237041090560ull,
        "div(f64_reinterpret_i64(0xfff4000000000000ull), -0.5)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, f64_reinterpret_i64(0xfff8000000000000ull), 0.5)) & 9223372036854775807ull),
        9221120237041090560ull,
        "div(f64_reinterpret_i64(0xfff8000000000000ull), 0.5)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, f64_reinterpret_i64(0xfff4000000000000ull), 0.5)) & 9221120237041090560ull),
        9221120237041090560ull,
        "div(f64_reinterpret_i64(0xfff4000000000000ull), 0.5)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, f64_reinterpret_i64(0x7ff8000000000000ull), -0.5)) & 9223372036854775807ull),
        9221120237041090560ull,
        "div(f64_reinterpret_i64(0x7ff8000000000000ull), -0.5)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, f64_reinterpret_i64(0x7ff4000000000000ull), -0.5)) & 9221120237041090560ull),
        9221120237041090560ull,
        "div(f64_reinterpret_i64(0x7ff4000000000000ull), -0.5)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, f64_reinterpret_i64(0x7ff8000000000000ull), 0.5)) & 9223372036854775807ull),
        9221120237041090560ull,
        "div(f64_reinterpret_i64(0x7ff8000000000000ull), 0.5)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, f64_reinterpret_i64(0x7ff4000000000000ull), 0.5)) & 9221120237041090560ull),
        9221120237041090560ull,
        "div(f64_reinterpret_i64(0x7ff4000000000000ull), 0.5)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, f64_reinterpret_i64(0xfff8000000000000ull), -1.0)) & 9223372036854775807ull),
        9221120237041090560ull,
        "div(f64_reinterpret_i64(0xfff8000000000000ull), -1.0)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, f64_reinterpret_i64(0xfff4000000000000ull), -1.0)) & 9221120237041090560ull),
        9221120237041090560ull,
        "div(f64_reinterpret_i64(0xfff4000000000000ull), -1.0)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, f64_reinterpret_i64(0xfff8000000000000ull), 1.0)) & 9223372036854775807ull),
        9221120237041090560ull,
        "div(f64_reinterpret_i64(0xfff8000000000000ull), 1.0)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, f64_reinterpret_i64(0xfff4000000000000ull), 1.0)) & 9221120237041090560ull),
        9221120237041090560ull,
        "div(f64_reinterpret_i64(0xfff4000000000000ull), 1.0)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, f64_reinterpret_i64(0x7ff8000000000000ull), -1.0)) & 9223372036854775807ull),
        9221120237041090560ull,
        "div(f64_reinterpret_i64(0x7ff8000000000000ull), -1.0)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, f64_reinterpret_i64(0x7ff4000000000000ull), -1.0)) & 9221120237041090560ull),
        9221120237041090560ull,
        "div(f64_reinterpret_i64(0x7ff4000000000000ull), -1.0)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, f64_reinterpret_i64(0x7ff8000000000000ull), 1.0)) & 9223372036854775807ull),
        9221120237041090560ull,
        "div(f64_reinterpret_i64(0x7ff8000000000000ull), 1.0)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, f64_reinterpret_i64(0x7ff4000000000000ull), 1.0)) & 9221120237041090560ull),
        9221120237041090560ull,
        "div(f64_reinterpret_i64(0x7ff4000000000000ull), 1.0)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, f64_reinterpret_i64(0xfff8000000000000ull), -6.283185307179586)) & 9223372036854775807ull),
        9221120237041090560ull,
        "div(f64_reinterpret_i64(0xfff8000000000000ull), -6.283185307179586)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, f64_reinterpret_i64(0xfff4000000000000ull), -6.283185307179586)) & 9221120237041090560ull),
        9221120237041090560ull,
        "div(f64_reinterpret_i64(0xfff4000000000000ull), -6.283185307179586)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, f64_reinterpret_i64(0xfff8000000000000ull), 6.283185307179586)) & 9223372036854775807ull),
        9221120237041090560ull,
        "div(f64_reinterpret_i64(0xfff8000000000000ull), 6.283185307179586)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, f64_reinterpret_i64(0xfff4000000000000ull), 6.283185307179586)) & 9221120237041090560ull),
        9221120237041090560ull,
        "div(f64_reinterpret_i64(0xfff4000000000000ull), 6.283185307179586)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, f64_reinterpret_i64(0x7ff8000000000000ull), -6.283185307179586)) & 9223372036854775807ull),
        9221120237041090560ull,
        "div(f64_reinterpret_i64(0x7ff8000000000000ull), -6.283185307179586)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, f64_reinterpret_i64(0x7ff4000000000000ull), -6.283185307179586)) & 9221120237041090560ull),
        9221120237041090560ull,
        "div(f64_reinterpret_i64(0x7ff4000000000000ull), -6.283185307179586)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, f64_reinterpret_i64(0x7ff8000000000000ull), 6.283185307179586)) & 9223372036854775807ull),
        9221120237041090560ull,
        "div(f64_reinterpret_i64(0x7ff8000000000000ull), 6.283185307179586)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, f64_reinterpret_i64(0x7ff4000000000000ull), 6.283185307179586)) & 9221120237041090560ull),
        9221120237041090560ull,
        "div(f64_reinterpret_i64(0x7ff4000000000000ull), 6.283185307179586)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, f64_reinterpret_i64(0xfff8000000000000ull), -1.7976931348623157e+308)) & 9223372036854775807ull),
        9221120237041090560ull,
        "div(f64_reinterpret_i64(0xfff8000000000000ull), -1.7976931348623157e+308)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, f64_reinterpret_i64(0xfff4000000000000ull), -1.7976931348623157e+308)) & 9221120237041090560ull),
        9221120237041090560ull,
        "div(f64_reinterpret_i64(0xfff4000000000000ull), -1.7976931348623157e+308)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, f64_reinterpret_i64(0xfff8000000000000ull), 1.7976931348623157e+308)) & 9223372036854775807ull),
        9221120237041090560ull,
        "div(f64_reinterpret_i64(0xfff8000000000000ull), 1.7976931348623157e+308)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, f64_reinterpret_i64(0xfff4000000000000ull), 1.7976931348623157e+308)) & 9221120237041090560ull),
        9221120237041090560ull,
        "div(f64_reinterpret_i64(0xfff4000000000000ull), 1.7976931348623157e+308)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, f64_reinterpret_i64(0x7ff8000000000000ull), -1.7976931348623157e+308)) & 9223372036854775807ull),
        9221120237041090560ull,
        "div(f64_reinterpret_i64(0x7ff8000000000000ull), -1.7976931348623157e+308)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, f64_reinterpret_i64(0x7ff4000000000000ull), -1.7976931348623157e+308)) & 9221120237041090560ull),
        9221120237041090560ull,
        "div(f64_reinterpret_i64(0x7ff4000000000000ull), -1.7976931348623157e+308)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, f64_reinterpret_i64(0x7ff8000000000000ull), 1.7976931348623157e+308)) & 9223372036854775807ull),
        9221120237041090560ull,
        "div(f64_reinterpret_i64(0x7ff8000000000000ull), 1.7976931348623157e+308)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, f64_reinterpret_i64(0x7ff4000000000000ull), 1.7976931348623157e+308)) & 9221120237041090560ull),
        9221120237041090560ull,
        "div(f64_reinterpret_i64(0x7ff4000000000000ull), 1.7976931348623157e+308)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, f64_reinterpret_i64(0xfff8000000000000ull), -INFINITY)) & 9223372036854775807ull),
        9221120237041090560ull,
        "div(f64_reinterpret_i64(0xfff8000000000000ull), -INFINITY)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, f64_reinterpret_i64(0xfff4000000000000ull), -INFINITY)) & 9221120237041090560ull),
        9221120237041090560ull,
        "div(f64_reinterpret_i64(0xfff4000000000000ull), -INFINITY)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, f64_reinterpret_i64(0xfff8000000000000ull), INFINITY)) & 9223372036854775807ull),
        9221120237041090560ull,
        "div(f64_reinterpret_i64(0xfff8000000000000ull), INFINITY)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, f64_reinterpret_i64(0xfff4000000000000ull), INFINITY)) & 9221120237041090560ull),
        9221120237041090560ull,
        "div(f64_reinterpret_i64(0xfff4000000000000ull), INFINITY)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, f64_reinterpret_i64(0x7ff8000000000000ull), -INFINITY)) & 9223372036854775807ull),
        9221120237041090560ull,
        "div(f64_reinterpret_i64(0x7ff8000000000000ull), -INFINITY)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, f64_reinterpret_i64(0x7ff4000000000000ull), -INFINITY)) & 9221120237041090560ull),
        9221120237041090560ull,
        "div(f64_reinterpret_i64(0x7ff4000000000000ull), -INFINITY)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, f64_reinterpret_i64(0x7ff8000000000000ull), INFINITY)) & 9223372036854775807ull),
        9221120237041090560ull,
        "div(f64_reinterpret_i64(0x7ff8000000000000ull), INFINITY)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, f64_reinterpret_i64(0x7ff4000000000000ull), INFINITY)) & 9221120237041090560ull),
        9221120237041090560ull,
        "div(f64_reinterpret_i64(0x7ff4000000000000ull), INFINITY)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, f64_reinterpret_i64(0xfff8000000000000ull), f64_reinterpret_i64(0xfff8000000000000ull))) & 9223372036854775807ull),
        9221120237041090560ull,
        "div(f64_reinterpret_i64(0xfff8000000000000ull), f64_reinterpret_i64(0xfff8000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, f64_reinterpret_i64(0xfff4000000000000ull), f64_reinterpret_i64(0xfff8000000000000ull))) & 9221120237041090560ull),
        9221120237041090560ull,
        "div(f64_reinterpret_i64(0xfff4000000000000ull), f64_reinterpret_i64(0xfff8000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, f64_reinterpret_i64(0xfff8000000000000ull), f64_reinterpret_i64(0xfff4000000000000ull))) & 9221120237041090560ull),
        9221120237041090560ull,
        "div(f64_reinterpret_i64(0xfff8000000000000ull), f64_reinterpret_i64(0xfff4000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, f64_reinterpret_i64(0xfff4000000000000ull), f64_reinterpret_i64(0xfff4000000000000ull))) & 9221120237041090560ull),
        9221120237041090560ull,
        "div(f64_reinterpret_i64(0xfff4000000000000ull), f64_reinterpret_i64(0xfff4000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, f64_reinterpret_i64(0xfff8000000000000ull), f64_reinterpret_i64(0x7ff8000000000000ull))) & 9223372036854775807ull),
        9221120237041090560ull,
        "div(f64_reinterpret_i64(0xfff8000000000000ull), f64_reinterpret_i64(0x7ff8000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, f64_reinterpret_i64(0xfff4000000000000ull), f64_reinterpret_i64(0x7ff8000000000000ull))) & 9221120237041090560ull),
        9221120237041090560ull,
        "div(f64_reinterpret_i64(0xfff4000000000000ull), f64_reinterpret_i64(0x7ff8000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, f64_reinterpret_i64(0xfff8000000000000ull), f64_reinterpret_i64(0x7ff4000000000000ull))) & 9221120237041090560ull),
        9221120237041090560ull,
        "div(f64_reinterpret_i64(0xfff8000000000000ull), f64_reinterpret_i64(0x7ff4000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, f64_reinterpret_i64(0xfff4000000000000ull), f64_reinterpret_i64(0x7ff4000000000000ull))) & 9221120237041090560ull),
        9221120237041090560ull,
        "div(f64_reinterpret_i64(0xfff4000000000000ull), f64_reinterpret_i64(0x7ff4000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, f64_reinterpret_i64(0x7ff8000000000000ull), f64_reinterpret_i64(0xfff8000000000000ull))) & 9223372036854775807ull),
        9221120237041090560ull,
        "div(f64_reinterpret_i64(0x7ff8000000000000ull), f64_reinterpret_i64(0xfff8000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, f64_reinterpret_i64(0x7ff4000000000000ull), f64_reinterpret_i64(0xfff8000000000000ull))) & 9221120237041090560ull),
        9221120237041090560ull,
        "div(f64_reinterpret_i64(0x7ff4000000000000ull), f64_reinterpret_i64(0xfff8000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, f64_reinterpret_i64(0x7ff8000000000000ull), f64_reinterpret_i64(0xfff4000000000000ull))) & 9221120237041090560ull),
        9221120237041090560ull,
        "div(f64_reinterpret_i64(0x7ff8000000000000ull), f64_reinterpret_i64(0xfff4000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, f64_reinterpret_i64(0x7ff4000000000000ull), f64_reinterpret_i64(0xfff4000000000000ull))) & 9221120237041090560ull),
        9221120237041090560ull,
        "div(f64_reinterpret_i64(0x7ff4000000000000ull), f64_reinterpret_i64(0xfff4000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, f64_reinterpret_i64(0x7ff8000000000000ull), f64_reinterpret_i64(0x7ff8000000000000ull))) & 9223372036854775807ull),
        9221120237041090560ull,
        "div(f64_reinterpret_i64(0x7ff8000000000000ull), f64_reinterpret_i64(0x7ff8000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, f64_reinterpret_i64(0x7ff4000000000000ull), f64_reinterpret_i64(0x7ff8000000000000ull))) & 9221120237041090560ull),
        9221120237041090560ull,
        "div(f64_reinterpret_i64(0x7ff4000000000000ull), f64_reinterpret_i64(0x7ff8000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, f64_reinterpret_i64(0x7ff8000000000000ull), f64_reinterpret_i64(0x7ff4000000000000ull))) & 9221120237041090560ull),
        9221120237041090560ull,
        "div(f64_reinterpret_i64(0x7ff8000000000000ull), f64_reinterpret_i64(0x7ff4000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_div(&instance, f64_reinterpret_i64(0x7ff4000000000000ull), f64_reinterpret_i64(0x7ff4000000000000ull))) & 9221120237041090560ull),
        9221120237041090560ull,
        "div(f64_reinterpret_i64(0x7ff4000000000000ull), f64_reinterpret_i64(0x7ff4000000000000ull))"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, -0.0, -0.0)),
        9223372036854775808ull,
        "min(-0.0, -0.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, -0.0, 0.0)),
        9223372036854775808ull,
        "min(-0.0, 0.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, 0.0, -0.0)),
        9223372036854775808ull,
        "min(0.0, -0.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, 0.0, 0.0)),
        0ull,
        "min(0.0, 0.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, -0.0, -5e-324)),
        9223372036854775809ull,
        "min(-0.0, -5e-324)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, -0.0, 5e-324)),
        9223372036854775808ull,
        "min(-0.0, 5e-324)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, 0.0, -5e-324)),
        9223372036854775809ull,
        "min(0.0, -5e-324)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, 0.0, 5e-324)),
        0ull,
        "min(0.0, 5e-324)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, -0.0, -2.2250738585072014e-308)),
        9227875636482146304ull,
        "min(-0.0, -2.2250738585072014e-308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, -0.0, 2.2250738585072014e-308)),
        9223372036854775808ull,
        "min(-0.0, 2.2250738585072014e-308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, 0.0, -2.2250738585072014e-308)),
        9227875636482146304ull,
        "min(0.0, -2.2250738585072014e-308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, 0.0, 2.2250738585072014e-308)),
        0ull,
        "min(0.0, 2.2250738585072014e-308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, -0.0, -0.5)),
        13826050856027422720ull,
        "min(-0.0, -0.5)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, -0.0, 0.5)),
        9223372036854775808ull,
        "min(-0.0, 0.5)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, 0.0, -0.5)),
        13826050856027422720ull,
        "min(0.0, -0.5)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, 0.0, 0.5)),
        0ull,
        "min(0.0, 0.5)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, -0.0, -1.0)),
        13830554455654793216ull,
        "min(-0.0, -1.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, -0.0, 1.0)),
        9223372036854775808ull,
        "min(-0.0, 1.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, 0.0, -1.0)),
        13830554455654793216ull,
        "min(0.0, -1.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, 0.0, 1.0)),
        0ull,
        "min(0.0, 1.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, -0.0, -6.283185307179586)),
        13842132293034192152ull,
        "min(-0.0, -6.283185307179586)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, -0.0, 6.283185307179586)),
        9223372036854775808ull,
        "min(-0.0, 6.283185307179586)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, 0.0, -6.283185307179586)),
        13842132293034192152ull,
        "min(0.0, -6.283185307179586)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, 0.0, 6.283185307179586)),
        0ull,
        "min(0.0, 6.283185307179586)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, -0.0, -1.7976931348623157e+308)),
        18442240474082181119ull,
        "min(-0.0, -1.7976931348623157e+308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, -0.0, 1.7976931348623157e+308)),
        9223372036854775808ull,
        "min(-0.0, 1.7976931348623157e+308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, 0.0, -1.7976931348623157e+308)),
        18442240474082181119ull,
        "min(0.0, -1.7976931348623157e+308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, 0.0, 1.7976931348623157e+308)),
        0ull,
        "min(0.0, 1.7976931348623157e+308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, -0.0, -INFINITY)),
        18442240474082181120ull,
        "min(-0.0, -INFINITY)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, -0.0, INFINITY)),
        9223372036854775808ull,
        "min(-0.0, INFINITY)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, 0.0, -INFINITY)),
        18442240474082181120ull,
        "min(0.0, -INFINITY)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, 0.0, INFINITY)),
        0ull,
        "min(0.0, INFINITY)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, -0.0, f64_reinterpret_i64(0xfff8000000000000ull))) & 9223372036854775807ull),
        9221120237041090560ull,
        "min(-0.0, f64_reinterpret_i64(0xfff8000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, -0.0, f64_reinterpret_i64(0xfff4000000000000ull))) & 9221120237041090560ull),
        9221120237041090560ull,
        "min(-0.0, f64_reinterpret_i64(0xfff4000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, -0.0, f64_reinterpret_i64(0x7ff8000000000000ull))) & 9223372036854775807ull),
        9221120237041090560ull,
        "min(-0.0, f64_reinterpret_i64(0x7ff8000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, -0.0, f64_reinterpret_i64(0x7ff4000000000000ull))) & 9221120237041090560ull),
        9221120237041090560ull,
        "min(-0.0, f64_reinterpret_i64(0x7ff4000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, 0.0, f64_reinterpret_i64(0xfff8000000000000ull))) & 9223372036854775807ull),
        9221120237041090560ull,
        "min(0.0, f64_reinterpret_i64(0xfff8000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, 0.0, f64_reinterpret_i64(0xfff4000000000000ull))) & 9221120237041090560ull),
        9221120237041090560ull,
        "min(0.0, f64_reinterpret_i64(0xfff4000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, 0.0, f64_reinterpret_i64(0x7ff8000000000000ull))) & 9223372036854775807ull),
        9221120237041090560ull,
        "min(0.0, f64_reinterpret_i64(0x7ff8000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, 0.0, f64_reinterpret_i64(0x7ff4000000000000ull))) & 9221120237041090560ull),
        9221120237041090560ull,
        "min(0.0, f64_reinterpret_i64(0x7ff4000000000000ull))"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, -5e-324, -0.0)),
        9223372036854775809ull,
        "min(-5e-324, -0.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, -5e-324, 0.0)),
        9223372036854775809ull,
        "min(-5e-324, 0.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, 5e-324, -0.0)),
        9223372036854775808ull,
        "min(5e-324, -0.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, 5e-324, 0.0)),
        0ull,
        "min(5e-324, 0.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, -5e-324, -5e-324)),
        9223372036854775809ull,
        "min(-5e-324, -5e-324)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, -5e-324, 5e-324)),
        9223372036854775809ull,
        "min(-5e-324, 5e-324)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, 5e-324, -5e-324)),
        9223372036854775809ull,
        "min(5e-324, -5e-324)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, 5e-324, 5e-324)),
        1ull,
        "min(5e-324, 5e-324)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, -5e-324, -2.2250738585072014e-308)),
        9227875636482146304ull,
        "min(-5e-324, -2.2250738585072014e-308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, -5e-324, 2.2250738585072014e-308)),
        9223372036854775809ull,
        "min(-5e-324, 2.2250738585072014e-308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, 5e-324, -2.2250738585072014e-308)),
        9227875636482146304ull,
        "min(5e-324, -2.2250738585072014e-308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, 5e-324, 2.2250738585072014e-308)),
        1ull,
        "min(5e-324, 2.2250738585072014e-308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, -5e-324, -0.5)),
        13826050856027422720ull,
        "min(-5e-324, -0.5)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, -5e-324, 0.5)),
        9223372036854775809ull,
        "min(-5e-324, 0.5)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, 5e-324, -0.5)),
        13826050856027422720ull,
        "min(5e-324, -0.5)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, 5e-324, 0.5)),
        1ull,
        "min(5e-324, 0.5)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, -5e-324, -1.0)),
        13830554455654793216ull,
        "min(-5e-324, -1.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, -5e-324, 1.0)),
        9223372036854775809ull,
        "min(-5e-324, 1.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, 5e-324, -1.0)),
        13830554455654793216ull,
        "min(5e-324, -1.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, 5e-324, 1.0)),
        1ull,
        "min(5e-324, 1.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, -5e-324, -6.283185307179586)),
        13842132293034192152ull,
        "min(-5e-324, -6.283185307179586)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, -5e-324, 6.283185307179586)),
        9223372036854775809ull,
        "min(-5e-324, 6.283185307179586)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, 5e-324, -6.283185307179586)),
        13842132293034192152ull,
        "min(5e-324, -6.283185307179586)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, 5e-324, 6.283185307179586)),
        1ull,
        "min(5e-324, 6.283185307179586)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, -5e-324, -1.7976931348623157e+308)),
        18442240474082181119ull,
        "min(-5e-324, -1.7976931348623157e+308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, -5e-324, 1.7976931348623157e+308)),
        9223372036854775809ull,
        "min(-5e-324, 1.7976931348623157e+308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, 5e-324, -1.7976931348623157e+308)),
        18442240474082181119ull,
        "min(5e-324, -1.7976931348623157e+308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, 5e-324, 1.7976931348623157e+308)),
        1ull,
        "min(5e-324, 1.7976931348623157e+308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, -5e-324, -INFINITY)),
        18442240474082181120ull,
        "min(-5e-324, -INFINITY)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, -5e-324, INFINITY)),
        9223372036854775809ull,
        "min(-5e-324, INFINITY)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, 5e-324, -INFINITY)),
        18442240474082181120ull,
        "min(5e-324, -INFINITY)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, 5e-324, INFINITY)),
        1ull,
        "min(5e-324, INFINITY)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, -5e-324, f64_reinterpret_i64(0xfff8000000000000ull))) & 9223372036854775807ull),
        9221120237041090560ull,
        "min(-5e-324, f64_reinterpret_i64(0xfff8000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, -5e-324, f64_reinterpret_i64(0xfff4000000000000ull))) & 9221120237041090560ull),
        9221120237041090560ull,
        "min(-5e-324, f64_reinterpret_i64(0xfff4000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, -5e-324, f64_reinterpret_i64(0x7ff8000000000000ull))) & 9223372036854775807ull),
        9221120237041090560ull,
        "min(-5e-324, f64_reinterpret_i64(0x7ff8000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, -5e-324, f64_reinterpret_i64(0x7ff4000000000000ull))) & 9221120237041090560ull),
        9221120237041090560ull,
        "min(-5e-324, f64_reinterpret_i64(0x7ff4000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, 5e-324, f64_reinterpret_i64(0xfff8000000000000ull))) & 9223372036854775807ull),
        9221120237041090560ull,
        "min(5e-324, f64_reinterpret_i64(0xfff8000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, 5e-324, f64_reinterpret_i64(0xfff4000000000000ull))) & 9221120237041090560ull),
        9221120237041090560ull,
        "min(5e-324, f64_reinterpret_i64(0xfff4000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, 5e-324, f64_reinterpret_i64(0x7ff8000000000000ull))) & 9223372036854775807ull),
        9221120237041090560ull,
        "min(5e-324, f64_reinterpret_i64(0x7ff8000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, 5e-324, f64_reinterpret_i64(0x7ff4000000000000ull))) & 9221120237041090560ull),
        9221120237041090560ull,
        "min(5e-324, f64_reinterpret_i64(0x7ff4000000000000ull))"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, -2.2250738585072014e-308, -0.0)),
        9227875636482146304ull,
        "min(-2.2250738585072014e-308, -0.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, -2.2250738585072014e-308, 0.0)),
        9227875636482146304ull,
        "min(-2.2250738585072014e-308, 0.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, 2.2250738585072014e-308, -0.0)),
        9223372036854775808ull,
        "min(2.2250738585072014e-308, -0.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, 2.2250738585072014e-308, 0.0)),
        0ull,
        "min(2.2250738585072014e-308, 0.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, -2.2250738585072014e-308, -5e-324)),
        9227875636482146304ull,
        "min(-2.2250738585072014e-308, -5e-324)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, -2.2250738585072014e-308, 5e-324)),
        9227875636482146304ull,
        "min(-2.2250738585072014e-308, 5e-324)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, 2.2250738585072014e-308, -5e-324)),
        9223372036854775809ull,
        "min(2.2250738585072014e-308, -5e-324)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, 2.2250738585072014e-308, 5e-324)),
        1ull,
        "min(2.2250738585072014e-308, 5e-324)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, -2.2250738585072014e-308, -2.2250738585072014e-308)),
        9227875636482146304ull,
        "min(-2.2250738585072014e-308, -2.2250738585072014e-308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, -2.2250738585072014e-308, 2.2250738585072014e-308)),
        9227875636482146304ull,
        "min(-2.2250738585072014e-308, 2.2250738585072014e-308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, 2.2250738585072014e-308, -2.2250738585072014e-308)),
        9227875636482146304ull,
        "min(2.2250738585072014e-308, -2.2250738585072014e-308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, 2.2250738585072014e-308, 2.2250738585072014e-308)),
        4503599627370496ull,
        "min(2.2250738585072014e-308, 2.2250738585072014e-308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, -2.2250738585072014e-308, -0.5)),
        13826050856027422720ull,
        "min(-2.2250738585072014e-308, -0.5)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, -2.2250738585072014e-308, 0.5)),
        9227875636482146304ull,
        "min(-2.2250738585072014e-308, 0.5)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, 2.2250738585072014e-308, -0.5)),
        13826050856027422720ull,
        "min(2.2250738585072014e-308, -0.5)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, 2.2250738585072014e-308, 0.5)),
        4503599627370496ull,
        "min(2.2250738585072014e-308, 0.5)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, -2.2250738585072014e-308, -1.0)),
        13830554455654793216ull,
        "min(-2.2250738585072014e-308, -1.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, -2.2250738585072014e-308, 1.0)),
        9227875636482146304ull,
        "min(-2.2250738585072014e-308, 1.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, 2.2250738585072014e-308, -1.0)),
        13830554455654793216ull,
        "min(2.2250738585072014e-308, -1.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, 2.2250738585072014e-308, 1.0)),
        4503599627370496ull,
        "min(2.2250738585072014e-308, 1.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, -2.2250738585072014e-308, -6.283185307179586)),
        13842132293034192152ull,
        "min(-2.2250738585072014e-308, -6.283185307179586)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, -2.2250738585072014e-308, 6.283185307179586)),
        9227875636482146304ull,
        "min(-2.2250738585072014e-308, 6.283185307179586)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, 2.2250738585072014e-308, -6.283185307179586)),
        13842132293034192152ull,
        "min(2.2250738585072014e-308, -6.283185307179586)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, 2.2250738585072014e-308, 6.283185307179586)),
        4503599627370496ull,
        "min(2.2250738585072014e-308, 6.283185307179586)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, -2.2250738585072014e-308, -1.7976931348623157e+308)),
        18442240474082181119ull,
        "min(-2.2250738585072014e-308, -1.7976931348623157e+308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, -2.2250738585072014e-308, 1.7976931348623157e+308)),
        9227875636482146304ull,
        "min(-2.2250738585072014e-308, 1.7976931348623157e+308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, 2.2250738585072014e-308, -1.7976931348623157e+308)),
        18442240474082181119ull,
        "min(2.2250738585072014e-308, -1.7976931348623157e+308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, 2.2250738585072014e-308, 1.7976931348623157e+308)),
        4503599627370496ull,
        "min(2.2250738585072014e-308, 1.7976931348623157e+308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, -2.2250738585072014e-308, -INFINITY)),
        18442240474082181120ull,
        "min(-2.2250738585072014e-308, -INFINITY)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, -2.2250738585072014e-308, INFINITY)),
        9227875636482146304ull,
        "min(-2.2250738585072014e-308, INFINITY)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, 2.2250738585072014e-308, -INFINITY)),
        18442240474082181120ull,
        "min(2.2250738585072014e-308, -INFINITY)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, 2.2250738585072014e-308, INFINITY)),
        4503599627370496ull,
        "min(2.2250738585072014e-308, INFINITY)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, -2.2250738585072014e-308, f64_reinterpret_i64(0xfff8000000000000ull))) & 9223372036854775807ull),
        9221120237041090560ull,
        "min(-2.2250738585072014e-308, f64_reinterpret_i64(0xfff8000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, -2.2250738585072014e-308, f64_reinterpret_i64(0xfff4000000000000ull))) & 9221120237041090560ull),
        9221120237041090560ull,
        "min(-2.2250738585072014e-308, f64_reinterpret_i64(0xfff4000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, -2.2250738585072014e-308, f64_reinterpret_i64(0x7ff8000000000000ull))) & 9223372036854775807ull),
        9221120237041090560ull,
        "min(-2.2250738585072014e-308, f64_reinterpret_i64(0x7ff8000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, -2.2250738585072014e-308, f64_reinterpret_i64(0x7ff4000000000000ull))) & 9221120237041090560ull),
        9221120237041090560ull,
        "min(-2.2250738585072014e-308, f64_reinterpret_i64(0x7ff4000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, 2.2250738585072014e-308, f64_reinterpret_i64(0xfff8000000000000ull))) & 9223372036854775807ull),
        9221120237041090560ull,
        "min(2.2250738585072014e-308, f64_reinterpret_i64(0xfff8000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, 2.2250738585072014e-308, f64_reinterpret_i64(0xfff4000000000000ull))) & 9221120237041090560ull),
        9221120237041090560ull,
        "min(2.2250738585072014e-308, f64_reinterpret_i64(0xfff4000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, 2.2250738585072014e-308, f64_reinterpret_i64(0x7ff8000000000000ull))) & 9223372036854775807ull),
        9221120237041090560ull,
        "min(2.2250738585072014e-308, f64_reinterpret_i64(0x7ff8000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, 2.2250738585072014e-308, f64_reinterpret_i64(0x7ff4000000000000ull))) & 9221120237041090560ull),
        9221120237041090560ull,
        "min(2.2250738585072014e-308, f64_reinterpret_i64(0x7ff4000000000000ull))"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, -0.5, -0.0)),
        13826050856027422720ull,
        "min(-0.5, -0.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, -0.5, 0.0)),
        13826050856027422720ull,
        "min(-0.5, 0.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, 0.5, -0.0)),
        9223372036854775808ull,
        "min(0.5, -0.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, 0.5, 0.0)),
        0ull,
        "min(0.5, 0.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, -0.5, -5e-324)),
        13826050856027422720ull,
        "min(-0.5, -5e-324)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, -0.5, 5e-324)),
        13826050856027422720ull,
        "min(-0.5, 5e-324)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, 0.5, -5e-324)),
        9223372036854775809ull,
        "min(0.5, -5e-324)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, 0.5, 5e-324)),
        1ull,
        "min(0.5, 5e-324)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, -0.5, -2.2250738585072014e-308)),
        13826050856027422720ull,
        "min(-0.5, -2.2250738585072014e-308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, -0.5, 2.2250738585072014e-308)),
        13826050856027422720ull,
        "min(-0.5, 2.2250738585072014e-308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, 0.5, -2.2250738585072014e-308)),
        9227875636482146304ull,
        "min(0.5, -2.2250738585072014e-308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, 0.5, 2.2250738585072014e-308)),
        4503599627370496ull,
        "min(0.5, 2.2250738585072014e-308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, -0.5, -0.5)),
        13826050856027422720ull,
        "min(-0.5, -0.5)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, -0.5, 0.5)),
        13826050856027422720ull,
        "min(-0.5, 0.5)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, 0.5, -0.5)),
        13826050856027422720ull,
        "min(0.5, -0.5)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, 0.5, 0.5)),
        4602678819172646912ull,
        "min(0.5, 0.5)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, -0.5, -1.0)),
        13830554455654793216ull,
        "min(-0.5, -1.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, -0.5, 1.0)),
        13826050856027422720ull,
        "min(-0.5, 1.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, 0.5, -1.0)),
        13830554455654793216ull,
        "min(0.5, -1.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, 0.5, 1.0)),
        4602678819172646912ull,
        "min(0.5, 1.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, -0.5, -6.283185307179586)),
        13842132293034192152ull,
        "min(-0.5, -6.283185307179586)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, -0.5, 6.283185307179586)),
        13826050856027422720ull,
        "min(-0.5, 6.283185307179586)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, 0.5, -6.283185307179586)),
        13842132293034192152ull,
        "min(0.5, -6.283185307179586)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, 0.5, 6.283185307179586)),
        4602678819172646912ull,
        "min(0.5, 6.283185307179586)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, -0.5, -1.7976931348623157e+308)),
        18442240474082181119ull,
        "min(-0.5, -1.7976931348623157e+308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, -0.5, 1.7976931348623157e+308)),
        13826050856027422720ull,
        "min(-0.5, 1.7976931348623157e+308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, 0.5, -1.7976931348623157e+308)),
        18442240474082181119ull,
        "min(0.5, -1.7976931348623157e+308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, 0.5, 1.7976931348623157e+308)),
        4602678819172646912ull,
        "min(0.5, 1.7976931348623157e+308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, -0.5, -INFINITY)),
        18442240474082181120ull,
        "min(-0.5, -INFINITY)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, -0.5, INFINITY)),
        13826050856027422720ull,
        "min(-0.5, INFINITY)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, 0.5, -INFINITY)),
        18442240474082181120ull,
        "min(0.5, -INFINITY)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, 0.5, INFINITY)),
        4602678819172646912ull,
        "min(0.5, INFINITY)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, -0.5, f64_reinterpret_i64(0xfff8000000000000ull))) & 9223372036854775807ull),
        9221120237041090560ull,
        "min(-0.5, f64_reinterpret_i64(0xfff8000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, -0.5, f64_reinterpret_i64(0xfff4000000000000ull))) & 9221120237041090560ull),
        9221120237041090560ull,
        "min(-0.5, f64_reinterpret_i64(0xfff4000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, -0.5, f64_reinterpret_i64(0x7ff8000000000000ull))) & 9223372036854775807ull),
        9221120237041090560ull,
        "min(-0.5, f64_reinterpret_i64(0x7ff8000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, -0.5, f64_reinterpret_i64(0x7ff4000000000000ull))) & 9221120237041090560ull),
        9221120237041090560ull,
        "min(-0.5, f64_reinterpret_i64(0x7ff4000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, 0.5, f64_reinterpret_i64(0xfff8000000000000ull))) & 9223372036854775807ull),
        9221120237041090560ull,
        "min(0.5, f64_reinterpret_i64(0xfff8000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, 0.5, f64_reinterpret_i64(0xfff4000000000000ull))) & 9221120237041090560ull),
        9221120237041090560ull,
        "min(0.5, f64_reinterpret_i64(0xfff4000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, 0.5, f64_reinterpret_i64(0x7ff8000000000000ull))) & 9223372036854775807ull),
        9221120237041090560ull,
        "min(0.5, f64_reinterpret_i64(0x7ff8000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, 0.5, f64_reinterpret_i64(0x7ff4000000000000ull))) & 9221120237041090560ull),
        9221120237041090560ull,
        "min(0.5, f64_reinterpret_i64(0x7ff4000000000000ull))"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, -1.0, -0.0)),
        13830554455654793216ull,
        "min(-1.0, -0.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, -1.0, 0.0)),
        13830554455654793216ull,
        "min(-1.0, 0.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, 1.0, -0.0)),
        9223372036854775808ull,
        "min(1.0, -0.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, 1.0, 0.0)),
        0ull,
        "min(1.0, 0.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, -1.0, -5e-324)),
        13830554455654793216ull,
        "min(-1.0, -5e-324)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, -1.0, 5e-324)),
        13830554455654793216ull,
        "min(-1.0, 5e-324)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, 1.0, -5e-324)),
        9223372036854775809ull,
        "min(1.0, -5e-324)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, 1.0, 5e-324)),
        1ull,
        "min(1.0, 5e-324)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, -1.0, -2.2250738585072014e-308)),
        13830554455654793216ull,
        "min(-1.0, -2.2250738585072014e-308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, -1.0, 2.2250738585072014e-308)),
        13830554455654793216ull,
        "min(-1.0, 2.2250738585072014e-308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, 1.0, -2.2250738585072014e-308)),
        9227875636482146304ull,
        "min(1.0, -2.2250738585072014e-308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, 1.0, 2.2250738585072014e-308)),
        4503599627370496ull,
        "min(1.0, 2.2250738585072014e-308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, -1.0, -0.5)),
        13830554455654793216ull,
        "min(-1.0, -0.5)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, -1.0, 0.5)),
        13830554455654793216ull,
        "min(-1.0, 0.5)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, 1.0, -0.5)),
        13826050856027422720ull,
        "min(1.0, -0.5)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, 1.0, 0.5)),
        4602678819172646912ull,
        "min(1.0, 0.5)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, -1.0, -1.0)),
        13830554455654793216ull,
        "min(-1.0, -1.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, -1.0, 1.0)),
        13830554455654793216ull,
        "min(-1.0, 1.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, 1.0, -1.0)),
        13830554455654793216ull,
        "min(1.0, -1.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, 1.0, 1.0)),
        4607182418800017408ull,
        "min(1.0, 1.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, -1.0, -6.283185307179586)),
        13842132293034192152ull,
        "min(-1.0, -6.283185307179586)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, -1.0, 6.283185307179586)),
        13830554455654793216ull,
        "min(-1.0, 6.283185307179586)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, 1.0, -6.283185307179586)),
        13842132293034192152ull,
        "min(1.0, -6.283185307179586)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, 1.0, 6.283185307179586)),
        4607182418800017408ull,
        "min(1.0, 6.283185307179586)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, -1.0, -1.7976931348623157e+308)),
        18442240474082181119ull,
        "min(-1.0, -1.7976931348623157e+308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, -1.0, 1.7976931348623157e+308)),
        13830554455654793216ull,
        "min(-1.0, 1.7976931348623157e+308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, 1.0, -1.7976931348623157e+308)),
        18442240474082181119ull,
        "min(1.0, -1.7976931348623157e+308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, 1.0, 1.7976931348623157e+308)),
        4607182418800017408ull,
        "min(1.0, 1.7976931348623157e+308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, -1.0, -INFINITY)),
        18442240474082181120ull,
        "min(-1.0, -INFINITY)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, -1.0, INFINITY)),
        13830554455654793216ull,
        "min(-1.0, INFINITY)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, 1.0, -INFINITY)),
        18442240474082181120ull,
        "min(1.0, -INFINITY)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, 1.0, INFINITY)),
        4607182418800017408ull,
        "min(1.0, INFINITY)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, -1.0, f64_reinterpret_i64(0xfff8000000000000ull))) & 9223372036854775807ull),
        9221120237041090560ull,
        "min(-1.0, f64_reinterpret_i64(0xfff8000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, -1.0, f64_reinterpret_i64(0xfff4000000000000ull))) & 9221120237041090560ull),
        9221120237041090560ull,
        "min(-1.0, f64_reinterpret_i64(0xfff4000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, -1.0, f64_reinterpret_i64(0x7ff8000000000000ull))) & 9223372036854775807ull),
        9221120237041090560ull,
        "min(-1.0, f64_reinterpret_i64(0x7ff8000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, -1.0, f64_reinterpret_i64(0x7ff4000000000000ull))) & 9221120237041090560ull),
        9221120237041090560ull,
        "min(-1.0, f64_reinterpret_i64(0x7ff4000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, 1.0, f64_reinterpret_i64(0xfff8000000000000ull))) & 9223372036854775807ull),
        9221120237041090560ull,
        "min(1.0, f64_reinterpret_i64(0xfff8000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, 1.0, f64_reinterpret_i64(0xfff4000000000000ull))) & 9221120237041090560ull),
        9221120237041090560ull,
        "min(1.0, f64_reinterpret_i64(0xfff4000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, 1.0, f64_reinterpret_i64(0x7ff8000000000000ull))) & 9223372036854775807ull),
        9221120237041090560ull,
        "min(1.0, f64_reinterpret_i64(0x7ff8000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, 1.0, f64_reinterpret_i64(0x7ff4000000000000ull))) & 9221120237041090560ull),
        9221120237041090560ull,
        "min(1.0, f64_reinterpret_i64(0x7ff4000000000000ull))"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, -6.283185307179586, -0.0)),
        13842132293034192152ull,
        "min(-6.283185307179586, -0.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, -6.283185307179586, 0.0)),
        13842132293034192152ull,
        "min(-6.283185307179586, 0.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, 6.283185307179586, -0.0)),
        9223372036854775808ull,
        "min(6.283185307179586, -0.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, 6.283185307179586, 0.0)),
        0ull,
        "min(6.283185307179586, 0.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, -6.283185307179586, -5e-324)),
        13842132293034192152ull,
        "min(-6.283185307179586, -5e-324)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, -6.283185307179586, 5e-324)),
        13842132293034192152ull,
        "min(-6.283185307179586, 5e-324)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, 6.283185307179586, -5e-324)),
        9223372036854775809ull,
        "min(6.283185307179586, -5e-324)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, 6.283185307179586, 5e-324)),
        1ull,
        "min(6.283185307179586, 5e-324)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, -6.283185307179586, -2.2250738585072014e-308)),
        13842132293034192152ull,
        "min(-6.283185307179586, -2.2250738585072014e-308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, -6.283185307179586, 2.2250738585072014e-308)),
        13842132293034192152ull,
        "min(-6.283185307179586, 2.2250738585072014e-308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, 6.283185307179586, -2.2250738585072014e-308)),
        9227875636482146304ull,
        "min(6.283185307179586, -2.2250738585072014e-308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, 6.283185307179586, 2.2250738585072014e-308)),
        4503599627370496ull,
        "min(6.283185307179586, 2.2250738585072014e-308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, -6.283185307179586, -0.5)),
        13842132293034192152ull,
        "min(-6.283185307179586, -0.5)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, -6.283185307179586, 0.5)),
        13842132293034192152ull,
        "min(-6.283185307179586, 0.5)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, 6.283185307179586, -0.5)),
        13826050856027422720ull,
        "min(6.283185307179586, -0.5)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, 6.283185307179586, 0.5)),
        4602678819172646912ull,
        "min(6.283185307179586, 0.5)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, -6.283185307179586, -1.0)),
        13842132293034192152ull,
        "min(-6.283185307179586, -1.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, -6.283185307179586, 1.0)),
        13842132293034192152ull,
        "min(-6.283185307179586, 1.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, 6.283185307179586, -1.0)),
        13830554455654793216ull,
        "min(6.283185307179586, -1.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, 6.283185307179586, 1.0)),
        4607182418800017408ull,
        "min(6.283185307179586, 1.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, -6.283185307179586, -6.283185307179586)),
        13842132293034192152ull,
        "min(-6.283185307179586, -6.283185307179586)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, -6.283185307179586, 6.283185307179586)),
        13842132293034192152ull,
        "min(-6.283185307179586, 6.283185307179586)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, 6.283185307179586, -6.283185307179586)),
        13842132293034192152ull,
        "min(6.283185307179586, -6.283185307179586)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, 6.283185307179586, 6.283185307179586)),
        4618760256179416344ull,
        "min(6.283185307179586, 6.283185307179586)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, -6.283185307179586, -1.7976931348623157e+308)),
        18442240474082181119ull,
        "min(-6.283185307179586, -1.7976931348623157e+308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, -6.283185307179586, 1.7976931348623157e+308)),
        13842132293034192152ull,
        "min(-6.283185307179586, 1.7976931348623157e+308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, 6.283185307179586, -1.7976931348623157e+308)),
        18442240474082181119ull,
        "min(6.283185307179586, -1.7976931348623157e+308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, 6.283185307179586, 1.7976931348623157e+308)),
        4618760256179416344ull,
        "min(6.283185307179586, 1.7976931348623157e+308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, -6.283185307179586, -INFINITY)),
        18442240474082181120ull,
        "min(-6.283185307179586, -INFINITY)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, -6.283185307179586, INFINITY)),
        13842132293034192152ull,
        "min(-6.283185307179586, INFINITY)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, 6.283185307179586, -INFINITY)),
        18442240474082181120ull,
        "min(6.283185307179586, -INFINITY)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, 6.283185307179586, INFINITY)),
        4618760256179416344ull,
        "min(6.283185307179586, INFINITY)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, -6.283185307179586, f64_reinterpret_i64(0xfff8000000000000ull))) & 9223372036854775807ull),
        9221120237041090560ull,
        "min(-6.283185307179586, f64_reinterpret_i64(0xfff8000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, -6.283185307179586, f64_reinterpret_i64(0xfff4000000000000ull))) & 9221120237041090560ull),
        9221120237041090560ull,
        "min(-6.283185307179586, f64_reinterpret_i64(0xfff4000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, -6.283185307179586, f64_reinterpret_i64(0x7ff8000000000000ull))) & 9223372036854775807ull),
        9221120237041090560ull,
        "min(-6.283185307179586, f64_reinterpret_i64(0x7ff8000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, -6.283185307179586, f64_reinterpret_i64(0x7ff4000000000000ull))) & 9221120237041090560ull),
        9221120237041090560ull,
        "min(-6.283185307179586, f64_reinterpret_i64(0x7ff4000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, 6.283185307179586, f64_reinterpret_i64(0xfff8000000000000ull))) & 9223372036854775807ull),
        9221120237041090560ull,
        "min(6.283185307179586, f64_reinterpret_i64(0xfff8000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, 6.283185307179586, f64_reinterpret_i64(0xfff4000000000000ull))) & 9221120237041090560ull),
        9221120237041090560ull,
        "min(6.283185307179586, f64_reinterpret_i64(0xfff4000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, 6.283185307179586, f64_reinterpret_i64(0x7ff8000000000000ull))) & 9223372036854775807ull),
        9221120237041090560ull,
        "min(6.283185307179586, f64_reinterpret_i64(0x7ff8000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, 6.283185307179586, f64_reinterpret_i64(0x7ff4000000000000ull))) & 9221120237041090560ull),
        9221120237041090560ull,
        "min(6.283185307179586, f64_reinterpret_i64(0x7ff4000000000000ull))"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, -1.7976931348623157e+308, -0.0)),
        18442240474082181119ull,
        "min(-1.7976931348623157e+308, -0.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, -1.7976931348623157e+308, 0.0)),
        18442240474082181119ull,
        "min(-1.7976931348623157e+308, 0.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, 1.7976931348623157e+308, -0.0)),
        9223372036854775808ull,
        "min(1.7976931348623157e+308, -0.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, 1.7976931348623157e+308, 0.0)),
        0ull,
        "min(1.7976931348623157e+308, 0.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, -1.7976931348623157e+308, -5e-324)),
        18442240474082181119ull,
        "min(-1.7976931348623157e+308, -5e-324)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, -1.7976931348623157e+308, 5e-324)),
        18442240474082181119ull,
        "min(-1.7976931348623157e+308, 5e-324)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, 1.7976931348623157e+308, -5e-324)),
        9223372036854775809ull,
        "min(1.7976931348623157e+308, -5e-324)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, 1.7976931348623157e+308, 5e-324)),
        1ull,
        "min(1.7976931348623157e+308, 5e-324)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, -1.7976931348623157e+308, -2.2250738585072014e-308)),
        18442240474082181119ull,
        "min(-1.7976931348623157e+308, -2.2250738585072014e-308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, -1.7976931348623157e+308, 2.2250738585072014e-308)),
        18442240474082181119ull,
        "min(-1.7976931348623157e+308, 2.2250738585072014e-308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, 1.7976931348623157e+308, -2.2250738585072014e-308)),
        9227875636482146304ull,
        "min(1.7976931348623157e+308, -2.2250738585072014e-308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, 1.7976931348623157e+308, 2.2250738585072014e-308)),
        4503599627370496ull,
        "min(1.7976931348623157e+308, 2.2250738585072014e-308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, -1.7976931348623157e+308, -0.5)),
        18442240474082181119ull,
        "min(-1.7976931348623157e+308, -0.5)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, -1.7976931348623157e+308, 0.5)),
        18442240474082181119ull,
        "min(-1.7976931348623157e+308, 0.5)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, 1.7976931348623157e+308, -0.5)),
        13826050856027422720ull,
        "min(1.7976931348623157e+308, -0.5)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, 1.7976931348623157e+308, 0.5)),
        4602678819172646912ull,
        "min(1.7976931348623157e+308, 0.5)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, -1.7976931348623157e+308, -1.0)),
        18442240474082181119ull,
        "min(-1.7976931348623157e+308, -1.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, -1.7976931348623157e+308, 1.0)),
        18442240474082181119ull,
        "min(-1.7976931348623157e+308, 1.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, 1.7976931348623157e+308, -1.0)),
        13830554455654793216ull,
        "min(1.7976931348623157e+308, -1.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, 1.7976931348623157e+308, 1.0)),
        4607182418800017408ull,
        "min(1.7976931348623157e+308, 1.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, -1.7976931348623157e+308, -6.283185307179586)),
        18442240474082181119ull,
        "min(-1.7976931348623157e+308, -6.283185307179586)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, -1.7976931348623157e+308, 6.283185307179586)),
        18442240474082181119ull,
        "min(-1.7976931348623157e+308, 6.283185307179586)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, 1.7976931348623157e+308, -6.283185307179586)),
        13842132293034192152ull,
        "min(1.7976931348623157e+308, -6.283185307179586)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, 1.7976931348623157e+308, 6.283185307179586)),
        4618760256179416344ull,
        "min(1.7976931348623157e+308, 6.283185307179586)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, -1.7976931348623157e+308, -1.7976931348623157e+308)),
        18442240474082181119ull,
        "min(-1.7976931348623157e+308, -1.7976931348623157e+308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, -1.7976931348623157e+308, 1.7976931348623157e+308)),
        18442240474082181119ull,
        "min(-1.7976931348623157e+308, 1.7976931348623157e+308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, 1.7976931348623157e+308, -1.7976931348623157e+308)),
        18442240474082181119ull,
        "min(1.7976931348623157e+308, -1.7976931348623157e+308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, 1.7976931348623157e+308, 1.7976931348623157e+308)),
        9218868437227405311ull,
        "min(1.7976931348623157e+308, 1.7976931348623157e+308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, -1.7976931348623157e+308, -INFINITY)),
        18442240474082181120ull,
        "min(-1.7976931348623157e+308, -INFINITY)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, -1.7976931348623157e+308, INFINITY)),
        18442240474082181119ull,
        "min(-1.7976931348623157e+308, INFINITY)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, 1.7976931348623157e+308, -INFINITY)),
        18442240474082181120ull,
        "min(1.7976931348623157e+308, -INFINITY)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, 1.7976931348623157e+308, INFINITY)),
        9218868437227405311ull,
        "min(1.7976931348623157e+308, INFINITY)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, -1.7976931348623157e+308, f64_reinterpret_i64(0xfff8000000000000ull))) & 9223372036854775807ull),
        9221120237041090560ull,
        "min(-1.7976931348623157e+308, f64_reinterpret_i64(0xfff8000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, -1.7976931348623157e+308, f64_reinterpret_i64(0xfff4000000000000ull))) & 9221120237041090560ull),
        9221120237041090560ull,
        "min(-1.7976931348623157e+308, f64_reinterpret_i64(0xfff4000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, -1.7976931348623157e+308, f64_reinterpret_i64(0x7ff8000000000000ull))) & 9223372036854775807ull),
        9221120237041090560ull,
        "min(-1.7976931348623157e+308, f64_reinterpret_i64(0x7ff8000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, -1.7976931348623157e+308, f64_reinterpret_i64(0x7ff4000000000000ull))) & 9221120237041090560ull),
        9221120237041090560ull,
        "min(-1.7976931348623157e+308, f64_reinterpret_i64(0x7ff4000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, 1.7976931348623157e+308, f64_reinterpret_i64(0xfff8000000000000ull))) & 9223372036854775807ull),
        9221120237041090560ull,
        "min(1.7976931348623157e+308, f64_reinterpret_i64(0xfff8000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, 1.7976931348623157e+308, f64_reinterpret_i64(0xfff4000000000000ull))) & 9221120237041090560ull),
        9221120237041090560ull,
        "min(1.7976931348623157e+308, f64_reinterpret_i64(0xfff4000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, 1.7976931348623157e+308, f64_reinterpret_i64(0x7ff8000000000000ull))) & 9223372036854775807ull),
        9221120237041090560ull,
        "min(1.7976931348623157e+308, f64_reinterpret_i64(0x7ff8000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, 1.7976931348623157e+308, f64_reinterpret_i64(0x7ff4000000000000ull))) & 9221120237041090560ull),
        9221120237041090560ull,
        "min(1.7976931348623157e+308, f64_reinterpret_i64(0x7ff4000000000000ull))"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, -INFINITY, -0.0)),
        18442240474082181120ull,
        "min(-INFINITY, -0.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, -INFINITY, 0.0)),
        18442240474082181120ull,
        "min(-INFINITY, 0.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, INFINITY, -0.0)),
        9223372036854775808ull,
        "min(INFINITY, -0.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, INFINITY, 0.0)),
        0ull,
        "min(INFINITY, 0.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, -INFINITY, -5e-324)),
        18442240474082181120ull,
        "min(-INFINITY, -5e-324)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, -INFINITY, 5e-324)),
        18442240474082181120ull,
        "min(-INFINITY, 5e-324)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, INFINITY, -5e-324)),
        9223372036854775809ull,
        "min(INFINITY, -5e-324)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, INFINITY, 5e-324)),
        1ull,
        "min(INFINITY, 5e-324)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, -INFINITY, -2.2250738585072014e-308)),
        18442240474082181120ull,
        "min(-INFINITY, -2.2250738585072014e-308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, -INFINITY, 2.2250738585072014e-308)),
        18442240474082181120ull,
        "min(-INFINITY, 2.2250738585072014e-308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, INFINITY, -2.2250738585072014e-308)),
        9227875636482146304ull,
        "min(INFINITY, -2.2250738585072014e-308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, INFINITY, 2.2250738585072014e-308)),
        4503599627370496ull,
        "min(INFINITY, 2.2250738585072014e-308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, -INFINITY, -0.5)),
        18442240474082181120ull,
        "min(-INFINITY, -0.5)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, -INFINITY, 0.5)),
        18442240474082181120ull,
        "min(-INFINITY, 0.5)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, INFINITY, -0.5)),
        13826050856027422720ull,
        "min(INFINITY, -0.5)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, INFINITY, 0.5)),
        4602678819172646912ull,
        "min(INFINITY, 0.5)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, -INFINITY, -1.0)),
        18442240474082181120ull,
        "min(-INFINITY, -1.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, -INFINITY, 1.0)),
        18442240474082181120ull,
        "min(-INFINITY, 1.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, INFINITY, -1.0)),
        13830554455654793216ull,
        "min(INFINITY, -1.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, INFINITY, 1.0)),
        4607182418800017408ull,
        "min(INFINITY, 1.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, -INFINITY, -6.283185307179586)),
        18442240474082181120ull,
        "min(-INFINITY, -6.283185307179586)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, -INFINITY, 6.283185307179586)),
        18442240474082181120ull,
        "min(-INFINITY, 6.283185307179586)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, INFINITY, -6.283185307179586)),
        13842132293034192152ull,
        "min(INFINITY, -6.283185307179586)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, INFINITY, 6.283185307179586)),
        4618760256179416344ull,
        "min(INFINITY, 6.283185307179586)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, -INFINITY, -1.7976931348623157e+308)),
        18442240474082181120ull,
        "min(-INFINITY, -1.7976931348623157e+308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, -INFINITY, 1.7976931348623157e+308)),
        18442240474082181120ull,
        "min(-INFINITY, 1.7976931348623157e+308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, INFINITY, -1.7976931348623157e+308)),
        18442240474082181119ull,
        "min(INFINITY, -1.7976931348623157e+308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, INFINITY, 1.7976931348623157e+308)),
        9218868437227405311ull,
        "min(INFINITY, 1.7976931348623157e+308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, -INFINITY, -INFINITY)),
        18442240474082181120ull,
        "min(-INFINITY, -INFINITY)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, -INFINITY, INFINITY)),
        18442240474082181120ull,
        "min(-INFINITY, INFINITY)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, INFINITY, -INFINITY)),
        18442240474082181120ull,
        "min(INFINITY, -INFINITY)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, INFINITY, INFINITY)),
        9218868437227405312ull,
        "min(INFINITY, INFINITY)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, -INFINITY, f64_reinterpret_i64(0xfff8000000000000ull))) & 9223372036854775807ull),
        9221120237041090560ull,
        "min(-INFINITY, f64_reinterpret_i64(0xfff8000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, -INFINITY, f64_reinterpret_i64(0xfff4000000000000ull))) & 9221120237041090560ull),
        9221120237041090560ull,
        "min(-INFINITY, f64_reinterpret_i64(0xfff4000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, -INFINITY, f64_reinterpret_i64(0x7ff8000000000000ull))) & 9223372036854775807ull),
        9221120237041090560ull,
        "min(-INFINITY, f64_reinterpret_i64(0x7ff8000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, -INFINITY, f64_reinterpret_i64(0x7ff4000000000000ull))) & 9221120237041090560ull),
        9221120237041090560ull,
        "min(-INFINITY, f64_reinterpret_i64(0x7ff4000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, INFINITY, f64_reinterpret_i64(0xfff8000000000000ull))) & 9223372036854775807ull),
        9221120237041090560ull,
        "min(INFINITY, f64_reinterpret_i64(0xfff8000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, INFINITY, f64_reinterpret_i64(0xfff4000000000000ull))) & 9221120237041090560ull),
        9221120237041090560ull,
        "min(INFINITY, f64_reinterpret_i64(0xfff4000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, INFINITY, f64_reinterpret_i64(0x7ff8000000000000ull))) & 9223372036854775807ull),
        9221120237041090560ull,
        "min(INFINITY, f64_reinterpret_i64(0x7ff8000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, INFINITY, f64_reinterpret_i64(0x7ff4000000000000ull))) & 9221120237041090560ull),
        9221120237041090560ull,
        "min(INFINITY, f64_reinterpret_i64(0x7ff4000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, f64_reinterpret_i64(0xfff8000000000000ull), -0.0)) & 9223372036854775807ull),
        9221120237041090560ull,
        "min(f64_reinterpret_i64(0xfff8000000000000ull), -0.0)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, f64_reinterpret_i64(0xfff4000000000000ull), -0.0)) & 9221120237041090560ull),
        9221120237041090560ull,
        "min(f64_reinterpret_i64(0xfff4000000000000ull), -0.0)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, f64_reinterpret_i64(0xfff8000000000000ull), 0.0)) & 9223372036854775807ull),
        9221120237041090560ull,
        "min(f64_reinterpret_i64(0xfff8000000000000ull), 0.0)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, f64_reinterpret_i64(0xfff4000000000000ull), 0.0)) & 9221120237041090560ull),
        9221120237041090560ull,
        "min(f64_reinterpret_i64(0xfff4000000000000ull), 0.0)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, f64_reinterpret_i64(0x7ff8000000000000ull), -0.0)) & 9223372036854775807ull),
        9221120237041090560ull,
        "min(f64_reinterpret_i64(0x7ff8000000000000ull), -0.0)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, f64_reinterpret_i64(0x7ff4000000000000ull), -0.0)) & 9221120237041090560ull),
        9221120237041090560ull,
        "min(f64_reinterpret_i64(0x7ff4000000000000ull), -0.0)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, f64_reinterpret_i64(0x7ff8000000000000ull), 0.0)) & 9223372036854775807ull),
        9221120237041090560ull,
        "min(f64_reinterpret_i64(0x7ff8000000000000ull), 0.0)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, f64_reinterpret_i64(0x7ff4000000000000ull), 0.0)) & 9221120237041090560ull),
        9221120237041090560ull,
        "min(f64_reinterpret_i64(0x7ff4000000000000ull), 0.0)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, f64_reinterpret_i64(0xfff8000000000000ull), -5e-324)) & 9223372036854775807ull),
        9221120237041090560ull,
        "min(f64_reinterpret_i64(0xfff8000000000000ull), -5e-324)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, f64_reinterpret_i64(0xfff4000000000000ull), -5e-324)) & 9221120237041090560ull),
        9221120237041090560ull,
        "min(f64_reinterpret_i64(0xfff4000000000000ull), -5e-324)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, f64_reinterpret_i64(0xfff8000000000000ull), 5e-324)) & 9223372036854775807ull),
        9221120237041090560ull,
        "min(f64_reinterpret_i64(0xfff8000000000000ull), 5e-324)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, f64_reinterpret_i64(0xfff4000000000000ull), 5e-324)) & 9221120237041090560ull),
        9221120237041090560ull,
        "min(f64_reinterpret_i64(0xfff4000000000000ull), 5e-324)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, f64_reinterpret_i64(0x7ff8000000000000ull), -5e-324)) & 9223372036854775807ull),
        9221120237041090560ull,
        "min(f64_reinterpret_i64(0x7ff8000000000000ull), -5e-324)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, f64_reinterpret_i64(0x7ff4000000000000ull), -5e-324)) & 9221120237041090560ull),
        9221120237041090560ull,
        "min(f64_reinterpret_i64(0x7ff4000000000000ull), -5e-324)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, f64_reinterpret_i64(0x7ff8000000000000ull), 5e-324)) & 9223372036854775807ull),
        9221120237041090560ull,
        "min(f64_reinterpret_i64(0x7ff8000000000000ull), 5e-324)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, f64_reinterpret_i64(0x7ff4000000000000ull), 5e-324)) & 9221120237041090560ull),
        9221120237041090560ull,
        "min(f64_reinterpret_i64(0x7ff4000000000000ull), 5e-324)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, f64_reinterpret_i64(0xfff8000000000000ull), -2.2250738585072014e-308)) & 9223372036854775807ull),
        9221120237041090560ull,
        "min(f64_reinterpret_i64(0xfff8000000000000ull), -2.2250738585072014e-308)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, f64_reinterpret_i64(0xfff4000000000000ull), -2.2250738585072014e-308)) & 9221120237041090560ull),
        9221120237041090560ull,
        "min(f64_reinterpret_i64(0xfff4000000000000ull), -2.2250738585072014e-308)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, f64_reinterpret_i64(0xfff8000000000000ull), 2.2250738585072014e-308)) & 9223372036854775807ull),
        9221120237041090560ull,
        "min(f64_reinterpret_i64(0xfff8000000000000ull), 2.2250738585072014e-308)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, f64_reinterpret_i64(0xfff4000000000000ull), 2.2250738585072014e-308)) & 9221120237041090560ull),
        9221120237041090560ull,
        "min(f64_reinterpret_i64(0xfff4000000000000ull), 2.2250738585072014e-308)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, f64_reinterpret_i64(0x7ff8000000000000ull), -2.2250738585072014e-308)) & 9223372036854775807ull),
        9221120237041090560ull,
        "min(f64_reinterpret_i64(0x7ff8000000000000ull), -2.2250738585072014e-308)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, f64_reinterpret_i64(0x7ff4000000000000ull), -2.2250738585072014e-308)) & 9221120237041090560ull),
        9221120237041090560ull,
        "min(f64_reinterpret_i64(0x7ff4000000000000ull), -2.2250738585072014e-308)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, f64_reinterpret_i64(0x7ff8000000000000ull), 2.2250738585072014e-308)) & 9223372036854775807ull),
        9221120237041090560ull,
        "min(f64_reinterpret_i64(0x7ff8000000000000ull), 2.2250738585072014e-308)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, f64_reinterpret_i64(0x7ff4000000000000ull), 2.2250738585072014e-308)) & 9221120237041090560ull),
        9221120237041090560ull,
        "min(f64_reinterpret_i64(0x7ff4000000000000ull), 2.2250738585072014e-308)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, f64_reinterpret_i64(0xfff8000000000000ull), -0.5)) & 9223372036854775807ull),
        9221120237041090560ull,
        "min(f64_reinterpret_i64(0xfff8000000000000ull), -0.5)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, f64_reinterpret_i64(0xfff4000000000000ull), -0.5)) & 9221120237041090560ull),
        9221120237041090560ull,
        "min(f64_reinterpret_i64(0xfff4000000000000ull), -0.5)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, f64_reinterpret_i64(0xfff8000000000000ull), 0.5)) & 9223372036854775807ull),
        9221120237041090560ull,
        "min(f64_reinterpret_i64(0xfff8000000000000ull), 0.5)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, f64_reinterpret_i64(0xfff4000000000000ull), 0.5)) & 9221120237041090560ull),
        9221120237041090560ull,
        "min(f64_reinterpret_i64(0xfff4000000000000ull), 0.5)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, f64_reinterpret_i64(0x7ff8000000000000ull), -0.5)) & 9223372036854775807ull),
        9221120237041090560ull,
        "min(f64_reinterpret_i64(0x7ff8000000000000ull), -0.5)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, f64_reinterpret_i64(0x7ff4000000000000ull), -0.5)) & 9221120237041090560ull),
        9221120237041090560ull,
        "min(f64_reinterpret_i64(0x7ff4000000000000ull), -0.5)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, f64_reinterpret_i64(0x7ff8000000000000ull), 0.5)) & 9223372036854775807ull),
        9221120237041090560ull,
        "min(f64_reinterpret_i64(0x7ff8000000000000ull), 0.5)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, f64_reinterpret_i64(0x7ff4000000000000ull), 0.5)) & 9221120237041090560ull),
        9221120237041090560ull,
        "min(f64_reinterpret_i64(0x7ff4000000000000ull), 0.5)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, f64_reinterpret_i64(0xfff8000000000000ull), -1.0)) & 9223372036854775807ull),
        9221120237041090560ull,
        "min(f64_reinterpret_i64(0xfff8000000000000ull), -1.0)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, f64_reinterpret_i64(0xfff4000000000000ull), -1.0)) & 9221120237041090560ull),
        9221120237041090560ull,
        "min(f64_reinterpret_i64(0xfff4000000000000ull), -1.0)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, f64_reinterpret_i64(0xfff8000000000000ull), 1.0)) & 9223372036854775807ull),
        9221120237041090560ull,
        "min(f64_reinterpret_i64(0xfff8000000000000ull), 1.0)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, f64_reinterpret_i64(0xfff4000000000000ull), 1.0)) & 9221120237041090560ull),
        9221120237041090560ull,
        "min(f64_reinterpret_i64(0xfff4000000000000ull), 1.0)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, f64_reinterpret_i64(0x7ff8000000000000ull), -1.0)) & 9223372036854775807ull),
        9221120237041090560ull,
        "min(f64_reinterpret_i64(0x7ff8000000000000ull), -1.0)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, f64_reinterpret_i64(0x7ff4000000000000ull), -1.0)) & 9221120237041090560ull),
        9221120237041090560ull,
        "min(f64_reinterpret_i64(0x7ff4000000000000ull), -1.0)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, f64_reinterpret_i64(0x7ff8000000000000ull), 1.0)) & 9223372036854775807ull),
        9221120237041090560ull,
        "min(f64_reinterpret_i64(0x7ff8000000000000ull), 1.0)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, f64_reinterpret_i64(0x7ff4000000000000ull), 1.0)) & 9221120237041090560ull),
        9221120237041090560ull,
        "min(f64_reinterpret_i64(0x7ff4000000000000ull), 1.0)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, f64_reinterpret_i64(0xfff8000000000000ull), -6.283185307179586)) & 9223372036854775807ull),
        9221120237041090560ull,
        "min(f64_reinterpret_i64(0xfff8000000000000ull), -6.283185307179586)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, f64_reinterpret_i64(0xfff4000000000000ull), -6.283185307179586)) & 9221120237041090560ull),
        9221120237041090560ull,
        "min(f64_reinterpret_i64(0xfff4000000000000ull), -6.283185307179586)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, f64_reinterpret_i64(0xfff8000000000000ull), 6.283185307179586)) & 9223372036854775807ull),
        9221120237041090560ull,
        "min(f64_reinterpret_i64(0xfff8000000000000ull), 6.283185307179586)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, f64_reinterpret_i64(0xfff4000000000000ull), 6.283185307179586)) & 9221120237041090560ull),
        9221120237041090560ull,
        "min(f64_reinterpret_i64(0xfff4000000000000ull), 6.283185307179586)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, f64_reinterpret_i64(0x7ff8000000000000ull), -6.283185307179586)) & 9223372036854775807ull),
        9221120237041090560ull,
        "min(f64_reinterpret_i64(0x7ff8000000000000ull), -6.283185307179586)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, f64_reinterpret_i64(0x7ff4000000000000ull), -6.283185307179586)) & 9221120237041090560ull),
        9221120237041090560ull,
        "min(f64_reinterpret_i64(0x7ff4000000000000ull), -6.283185307179586)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, f64_reinterpret_i64(0x7ff8000000000000ull), 6.283185307179586)) & 9223372036854775807ull),
        9221120237041090560ull,
        "min(f64_reinterpret_i64(0x7ff8000000000000ull), 6.283185307179586)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, f64_reinterpret_i64(0x7ff4000000000000ull), 6.283185307179586)) & 9221120237041090560ull),
        9221120237041090560ull,
        "min(f64_reinterpret_i64(0x7ff4000000000000ull), 6.283185307179586)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, f64_reinterpret_i64(0xfff8000000000000ull), -1.7976931348623157e+308)) & 9223372036854775807ull),
        9221120237041090560ull,
        "min(f64_reinterpret_i64(0xfff8000000000000ull), -1.7976931348623157e+308)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, f64_reinterpret_i64(0xfff4000000000000ull), -1.7976931348623157e+308)) & 9221120237041090560ull),
        9221120237041090560ull,
        "min(f64_reinterpret_i64(0xfff4000000000000ull), -1.7976931348623157e+308)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, f64_reinterpret_i64(0xfff8000000000000ull), 1.7976931348623157e+308)) & 9223372036854775807ull),
        9221120237041090560ull,
        "min(f64_reinterpret_i64(0xfff8000000000000ull), 1.7976931348623157e+308)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, f64_reinterpret_i64(0xfff4000000000000ull), 1.7976931348623157e+308)) & 9221120237041090560ull),
        9221120237041090560ull,
        "min(f64_reinterpret_i64(0xfff4000000000000ull), 1.7976931348623157e+308)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, f64_reinterpret_i64(0x7ff8000000000000ull), -1.7976931348623157e+308)) & 9223372036854775807ull),
        9221120237041090560ull,
        "min(f64_reinterpret_i64(0x7ff8000000000000ull), -1.7976931348623157e+308)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, f64_reinterpret_i64(0x7ff4000000000000ull), -1.7976931348623157e+308)) & 9221120237041090560ull),
        9221120237041090560ull,
        "min(f64_reinterpret_i64(0x7ff4000000000000ull), -1.7976931348623157e+308)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, f64_reinterpret_i64(0x7ff8000000000000ull), 1.7976931348623157e+308)) & 9223372036854775807ull),
        9221120237041090560ull,
        "min(f64_reinterpret_i64(0x7ff8000000000000ull), 1.7976931348623157e+308)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, f64_reinterpret_i64(0x7ff4000000000000ull), 1.7976931348623157e+308)) & 9221120237041090560ull),
        9221120237041090560ull,
        "min(f64_reinterpret_i64(0x7ff4000000000000ull), 1.7976931348623157e+308)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, f64_reinterpret_i64(0xfff8000000000000ull), -INFINITY)) & 9223372036854775807ull),
        9221120237041090560ull,
        "min(f64_reinterpret_i64(0xfff8000000000000ull), -INFINITY)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, f64_reinterpret_i64(0xfff4000000000000ull), -INFINITY)) & 9221120237041090560ull),
        9221120237041090560ull,
        "min(f64_reinterpret_i64(0xfff4000000000000ull), -INFINITY)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, f64_reinterpret_i64(0xfff8000000000000ull), INFINITY)) & 9223372036854775807ull),
        9221120237041090560ull,
        "min(f64_reinterpret_i64(0xfff8000000000000ull), INFINITY)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, f64_reinterpret_i64(0xfff4000000000000ull), INFINITY)) & 9221120237041090560ull),
        9221120237041090560ull,
        "min(f64_reinterpret_i64(0xfff4000000000000ull), INFINITY)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, f64_reinterpret_i64(0x7ff8000000000000ull), -INFINITY)) & 9223372036854775807ull),
        9221120237041090560ull,
        "min(f64_reinterpret_i64(0x7ff8000000000000ull), -INFINITY)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, f64_reinterpret_i64(0x7ff4000000000000ull), -INFINITY)) & 9221120237041090560ull),
        9221120237041090560ull,
        "min(f64_reinterpret_i64(0x7ff4000000000000ull), -INFINITY)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, f64_reinterpret_i64(0x7ff8000000000000ull), INFINITY)) & 9223372036854775807ull),
        9221120237041090560ull,
        "min(f64_reinterpret_i64(0x7ff8000000000000ull), INFINITY)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, f64_reinterpret_i64(0x7ff4000000000000ull), INFINITY)) & 9221120237041090560ull),
        9221120237041090560ull,
        "min(f64_reinterpret_i64(0x7ff4000000000000ull), INFINITY)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, f64_reinterpret_i64(0xfff8000000000000ull), f64_reinterpret_i64(0xfff8000000000000ull))) & 9223372036854775807ull),
        9221120237041090560ull,
        "min(f64_reinterpret_i64(0xfff8000000000000ull), f64_reinterpret_i64(0xfff8000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, f64_reinterpret_i64(0xfff4000000000000ull), f64_reinterpret_i64(0xfff8000000000000ull))) & 9221120237041090560ull),
        9221120237041090560ull,
        "min(f64_reinterpret_i64(0xfff4000000000000ull), f64_reinterpret_i64(0xfff8000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, f64_reinterpret_i64(0xfff8000000000000ull), f64_reinterpret_i64(0xfff4000000000000ull))) & 9221120237041090560ull),
        9221120237041090560ull,
        "min(f64_reinterpret_i64(0xfff8000000000000ull), f64_reinterpret_i64(0xfff4000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, f64_reinterpret_i64(0xfff4000000000000ull), f64_reinterpret_i64(0xfff4000000000000ull))) & 9221120237041090560ull),
        9221120237041090560ull,
        "min(f64_reinterpret_i64(0xfff4000000000000ull), f64_reinterpret_i64(0xfff4000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, f64_reinterpret_i64(0xfff8000000000000ull), f64_reinterpret_i64(0x7ff8000000000000ull))) & 9223372036854775807ull),
        9221120237041090560ull,
        "min(f64_reinterpret_i64(0xfff8000000000000ull), f64_reinterpret_i64(0x7ff8000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, f64_reinterpret_i64(0xfff4000000000000ull), f64_reinterpret_i64(0x7ff8000000000000ull))) & 9221120237041090560ull),
        9221120237041090560ull,
        "min(f64_reinterpret_i64(0xfff4000000000000ull), f64_reinterpret_i64(0x7ff8000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, f64_reinterpret_i64(0xfff8000000000000ull), f64_reinterpret_i64(0x7ff4000000000000ull))) & 9221120237041090560ull),
        9221120237041090560ull,
        "min(f64_reinterpret_i64(0xfff8000000000000ull), f64_reinterpret_i64(0x7ff4000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, f64_reinterpret_i64(0xfff4000000000000ull), f64_reinterpret_i64(0x7ff4000000000000ull))) & 9221120237041090560ull),
        9221120237041090560ull,
        "min(f64_reinterpret_i64(0xfff4000000000000ull), f64_reinterpret_i64(0x7ff4000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, f64_reinterpret_i64(0x7ff8000000000000ull), f64_reinterpret_i64(0xfff8000000000000ull))) & 9223372036854775807ull),
        9221120237041090560ull,
        "min(f64_reinterpret_i64(0x7ff8000000000000ull), f64_reinterpret_i64(0xfff8000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, f64_reinterpret_i64(0x7ff4000000000000ull), f64_reinterpret_i64(0xfff8000000000000ull))) & 9221120237041090560ull),
        9221120237041090560ull,
        "min(f64_reinterpret_i64(0x7ff4000000000000ull), f64_reinterpret_i64(0xfff8000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, f64_reinterpret_i64(0x7ff8000000000000ull), f64_reinterpret_i64(0xfff4000000000000ull))) & 9221120237041090560ull),
        9221120237041090560ull,
        "min(f64_reinterpret_i64(0x7ff8000000000000ull), f64_reinterpret_i64(0xfff4000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, f64_reinterpret_i64(0x7ff4000000000000ull), f64_reinterpret_i64(0xfff4000000000000ull))) & 9221120237041090560ull),
        9221120237041090560ull,
        "min(f64_reinterpret_i64(0x7ff4000000000000ull), f64_reinterpret_i64(0xfff4000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, f64_reinterpret_i64(0x7ff8000000000000ull), f64_reinterpret_i64(0x7ff8000000000000ull))) & 9223372036854775807ull),
        9221120237041090560ull,
        "min(f64_reinterpret_i64(0x7ff8000000000000ull), f64_reinterpret_i64(0x7ff8000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, f64_reinterpret_i64(0x7ff4000000000000ull), f64_reinterpret_i64(0x7ff8000000000000ull))) & 9221120237041090560ull),
        9221120237041090560ull,
        "min(f64_reinterpret_i64(0x7ff4000000000000ull), f64_reinterpret_i64(0x7ff8000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, f64_reinterpret_i64(0x7ff8000000000000ull), f64_reinterpret_i64(0x7ff4000000000000ull))) & 9221120237041090560ull),
        9221120237041090560ull,
        "min(f64_reinterpret_i64(0x7ff8000000000000ull), f64_reinterpret_i64(0x7ff4000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_min(&instance, f64_reinterpret_i64(0x7ff4000000000000ull), f64_reinterpret_i64(0x7ff4000000000000ull))) & 9221120237041090560ull),
        9221120237041090560ull,
        "min(f64_reinterpret_i64(0x7ff4000000000000ull), f64_reinterpret_i64(0x7ff4000000000000ull))"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, -0.0, -0.0)),
        9223372036854775808ull,
        "max(-0.0, -0.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, -0.0, 0.0)),
        0ull,
        "max(-0.0, 0.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, 0.0, -0.0)),
        0ull,
        "max(0.0, -0.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, 0.0, 0.0)),
        0ull,
        "max(0.0, 0.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, -0.0, -5e-324)),
        9223372036854775808ull,
        "max(-0.0, -5e-324)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, -0.0, 5e-324)),
        1ull,
        "max(-0.0, 5e-324)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, 0.0, -5e-324)),
        0ull,
        "max(0.0, -5e-324)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, 0.0, 5e-324)),
        1ull,
        "max(0.0, 5e-324)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, -0.0, -2.2250738585072014e-308)),
        9223372036854775808ull,
        "max(-0.0, -2.2250738585072014e-308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, -0.0, 2.2250738585072014e-308)),
        4503599627370496ull,
        "max(-0.0, 2.2250738585072014e-308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, 0.0, -2.2250738585072014e-308)),
        0ull,
        "max(0.0, -2.2250738585072014e-308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, 0.0, 2.2250738585072014e-308)),
        4503599627370496ull,
        "max(0.0, 2.2250738585072014e-308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, -0.0, -0.5)),
        9223372036854775808ull,
        "max(-0.0, -0.5)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, -0.0, 0.5)),
        4602678819172646912ull,
        "max(-0.0, 0.5)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, 0.0, -0.5)),
        0ull,
        "max(0.0, -0.5)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, 0.0, 0.5)),
        4602678819172646912ull,
        "max(0.0, 0.5)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, -0.0, -1.0)),
        9223372036854775808ull,
        "max(-0.0, -1.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, -0.0, 1.0)),
        4607182418800017408ull,
        "max(-0.0, 1.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, 0.0, -1.0)),
        0ull,
        "max(0.0, -1.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, 0.0, 1.0)),
        4607182418800017408ull,
        "max(0.0, 1.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, -0.0, -6.283185307179586)),
        9223372036854775808ull,
        "max(-0.0, -6.283185307179586)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, -0.0, 6.283185307179586)),
        4618760256179416344ull,
        "max(-0.0, 6.283185307179586)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, 0.0, -6.283185307179586)),
        0ull,
        "max(0.0, -6.283185307179586)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, 0.0, 6.283185307179586)),
        4618760256179416344ull,
        "max(0.0, 6.283185307179586)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, -0.0, -1.7976931348623157e+308)),
        9223372036854775808ull,
        "max(-0.0, -1.7976931348623157e+308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, -0.0, 1.7976931348623157e+308)),
        9218868437227405311ull,
        "max(-0.0, 1.7976931348623157e+308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, 0.0, -1.7976931348623157e+308)),
        0ull,
        "max(0.0, -1.7976931348623157e+308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, 0.0, 1.7976931348623157e+308)),
        9218868437227405311ull,
        "max(0.0, 1.7976931348623157e+308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, -0.0, -INFINITY)),
        9223372036854775808ull,
        "max(-0.0, -INFINITY)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, -0.0, INFINITY)),
        9218868437227405312ull,
        "max(-0.0, INFINITY)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, 0.0, -INFINITY)),
        0ull,
        "max(0.0, -INFINITY)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, 0.0, INFINITY)),
        9218868437227405312ull,
        "max(0.0, INFINITY)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, -0.0, f64_reinterpret_i64(0xfff8000000000000ull))) & 9223372036854775807ull),
        9221120237041090560ull,
        "max(-0.0, f64_reinterpret_i64(0xfff8000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, -0.0, f64_reinterpret_i64(0xfff4000000000000ull))) & 9221120237041090560ull),
        9221120237041090560ull,
        "max(-0.0, f64_reinterpret_i64(0xfff4000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, -0.0, f64_reinterpret_i64(0x7ff8000000000000ull))) & 9223372036854775807ull),
        9221120237041090560ull,
        "max(-0.0, f64_reinterpret_i64(0x7ff8000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, -0.0, f64_reinterpret_i64(0x7ff4000000000000ull))) & 9221120237041090560ull),
        9221120237041090560ull,
        "max(-0.0, f64_reinterpret_i64(0x7ff4000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, 0.0, f64_reinterpret_i64(0xfff8000000000000ull))) & 9223372036854775807ull),
        9221120237041090560ull,
        "max(0.0, f64_reinterpret_i64(0xfff8000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, 0.0, f64_reinterpret_i64(0xfff4000000000000ull))) & 9221120237041090560ull),
        9221120237041090560ull,
        "max(0.0, f64_reinterpret_i64(0xfff4000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, 0.0, f64_reinterpret_i64(0x7ff8000000000000ull))) & 9223372036854775807ull),
        9221120237041090560ull,
        "max(0.0, f64_reinterpret_i64(0x7ff8000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, 0.0, f64_reinterpret_i64(0x7ff4000000000000ull))) & 9221120237041090560ull),
        9221120237041090560ull,
        "max(0.0, f64_reinterpret_i64(0x7ff4000000000000ull))"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, -5e-324, -0.0)),
        9223372036854775808ull,
        "max(-5e-324, -0.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, -5e-324, 0.0)),
        0ull,
        "max(-5e-324, 0.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, 5e-324, -0.0)),
        1ull,
        "max(5e-324, -0.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, 5e-324, 0.0)),
        1ull,
        "max(5e-324, 0.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, -5e-324, -5e-324)),
        9223372036854775809ull,
        "max(-5e-324, -5e-324)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, -5e-324, 5e-324)),
        1ull,
        "max(-5e-324, 5e-324)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, 5e-324, -5e-324)),
        1ull,
        "max(5e-324, -5e-324)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, 5e-324, 5e-324)),
        1ull,
        "max(5e-324, 5e-324)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, -5e-324, -2.2250738585072014e-308)),
        9223372036854775809ull,
        "max(-5e-324, -2.2250738585072014e-308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, -5e-324, 2.2250738585072014e-308)),
        4503599627370496ull,
        "max(-5e-324, 2.2250738585072014e-308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, 5e-324, -2.2250738585072014e-308)),
        1ull,
        "max(5e-324, -2.2250738585072014e-308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, 5e-324, 2.2250738585072014e-308)),
        4503599627370496ull,
        "max(5e-324, 2.2250738585072014e-308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, -5e-324, -0.5)),
        9223372036854775809ull,
        "max(-5e-324, -0.5)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, -5e-324, 0.5)),
        4602678819172646912ull,
        "max(-5e-324, 0.5)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, 5e-324, -0.5)),
        1ull,
        "max(5e-324, -0.5)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, 5e-324, 0.5)),
        4602678819172646912ull,
        "max(5e-324, 0.5)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, -5e-324, -1.0)),
        9223372036854775809ull,
        "max(-5e-324, -1.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, -5e-324, 1.0)),
        4607182418800017408ull,
        "max(-5e-324, 1.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, 5e-324, -1.0)),
        1ull,
        "max(5e-324, -1.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, 5e-324, 1.0)),
        4607182418800017408ull,
        "max(5e-324, 1.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, -5e-324, -6.283185307179586)),
        9223372036854775809ull,
        "max(-5e-324, -6.283185307179586)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, -5e-324, 6.283185307179586)),
        4618760256179416344ull,
        "max(-5e-324, 6.283185307179586)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, 5e-324, -6.283185307179586)),
        1ull,
        "max(5e-324, -6.283185307179586)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, 5e-324, 6.283185307179586)),
        4618760256179416344ull,
        "max(5e-324, 6.283185307179586)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, -5e-324, -1.7976931348623157e+308)),
        9223372036854775809ull,
        "max(-5e-324, -1.7976931348623157e+308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, -5e-324, 1.7976931348623157e+308)),
        9218868437227405311ull,
        "max(-5e-324, 1.7976931348623157e+308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, 5e-324, -1.7976931348623157e+308)),
        1ull,
        "max(5e-324, -1.7976931348623157e+308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, 5e-324, 1.7976931348623157e+308)),
        9218868437227405311ull,
        "max(5e-324, 1.7976931348623157e+308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, -5e-324, -INFINITY)),
        9223372036854775809ull,
        "max(-5e-324, -INFINITY)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, -5e-324, INFINITY)),
        9218868437227405312ull,
        "max(-5e-324, INFINITY)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, 5e-324, -INFINITY)),
        1ull,
        "max(5e-324, -INFINITY)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, 5e-324, INFINITY)),
        9218868437227405312ull,
        "max(5e-324, INFINITY)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, -5e-324, f64_reinterpret_i64(0xfff8000000000000ull))) & 9223372036854775807ull),
        9221120237041090560ull,
        "max(-5e-324, f64_reinterpret_i64(0xfff8000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, -5e-324, f64_reinterpret_i64(0xfff4000000000000ull))) & 9221120237041090560ull),
        9221120237041090560ull,
        "max(-5e-324, f64_reinterpret_i64(0xfff4000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, -5e-324, f64_reinterpret_i64(0x7ff8000000000000ull))) & 9223372036854775807ull),
        9221120237041090560ull,
        "max(-5e-324, f64_reinterpret_i64(0x7ff8000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, -5e-324, f64_reinterpret_i64(0x7ff4000000000000ull))) & 9221120237041090560ull),
        9221120237041090560ull,
        "max(-5e-324, f64_reinterpret_i64(0x7ff4000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, 5e-324, f64_reinterpret_i64(0xfff8000000000000ull))) & 9223372036854775807ull),
        9221120237041090560ull,
        "max(5e-324, f64_reinterpret_i64(0xfff8000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, 5e-324, f64_reinterpret_i64(0xfff4000000000000ull))) & 9221120237041090560ull),
        9221120237041090560ull,
        "max(5e-324, f64_reinterpret_i64(0xfff4000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, 5e-324, f64_reinterpret_i64(0x7ff8000000000000ull))) & 9223372036854775807ull),
        9221120237041090560ull,
        "max(5e-324, f64_reinterpret_i64(0x7ff8000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, 5e-324, f64_reinterpret_i64(0x7ff4000000000000ull))) & 9221120237041090560ull),
        9221120237041090560ull,
        "max(5e-324, f64_reinterpret_i64(0x7ff4000000000000ull))"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, -2.2250738585072014e-308, -0.0)),
        9223372036854775808ull,
        "max(-2.2250738585072014e-308, -0.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, -2.2250738585072014e-308, 0.0)),
        0ull,
        "max(-2.2250738585072014e-308, 0.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, 2.2250738585072014e-308, -0.0)),
        4503599627370496ull,
        "max(2.2250738585072014e-308, -0.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, 2.2250738585072014e-308, 0.0)),
        4503599627370496ull,
        "max(2.2250738585072014e-308, 0.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, -2.2250738585072014e-308, -5e-324)),
        9223372036854775809ull,
        "max(-2.2250738585072014e-308, -5e-324)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, -2.2250738585072014e-308, 5e-324)),
        1ull,
        "max(-2.2250738585072014e-308, 5e-324)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, 2.2250738585072014e-308, -5e-324)),
        4503599627370496ull,
        "max(2.2250738585072014e-308, -5e-324)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, 2.2250738585072014e-308, 5e-324)),
        4503599627370496ull,
        "max(2.2250738585072014e-308, 5e-324)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, -2.2250738585072014e-308, -2.2250738585072014e-308)),
        9227875636482146304ull,
        "max(-2.2250738585072014e-308, -2.2250738585072014e-308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, -2.2250738585072014e-308, 2.2250738585072014e-308)),
        4503599627370496ull,
        "max(-2.2250738585072014e-308, 2.2250738585072014e-308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, 2.2250738585072014e-308, -2.2250738585072014e-308)),
        4503599627370496ull,
        "max(2.2250738585072014e-308, -2.2250738585072014e-308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, 2.2250738585072014e-308, 2.2250738585072014e-308)),
        4503599627370496ull,
        "max(2.2250738585072014e-308, 2.2250738585072014e-308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, -2.2250738585072014e-308, -0.5)),
        9227875636482146304ull,
        "max(-2.2250738585072014e-308, -0.5)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, -2.2250738585072014e-308, 0.5)),
        4602678819172646912ull,
        "max(-2.2250738585072014e-308, 0.5)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, 2.2250738585072014e-308, -0.5)),
        4503599627370496ull,
        "max(2.2250738585072014e-308, -0.5)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, 2.2250738585072014e-308, 0.5)),
        4602678819172646912ull,
        "max(2.2250738585072014e-308, 0.5)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, -2.2250738585072014e-308, -1.0)),
        9227875636482146304ull,
        "max(-2.2250738585072014e-308, -1.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, -2.2250738585072014e-308, 1.0)),
        4607182418800017408ull,
        "max(-2.2250738585072014e-308, 1.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, 2.2250738585072014e-308, -1.0)),
        4503599627370496ull,
        "max(2.2250738585072014e-308, -1.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, 2.2250738585072014e-308, 1.0)),
        4607182418800017408ull,
        "max(2.2250738585072014e-308, 1.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, -2.2250738585072014e-308, -6.283185307179586)),
        9227875636482146304ull,
        "max(-2.2250738585072014e-308, -6.283185307179586)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, -2.2250738585072014e-308, 6.283185307179586)),
        4618760256179416344ull,
        "max(-2.2250738585072014e-308, 6.283185307179586)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, 2.2250738585072014e-308, -6.283185307179586)),
        4503599627370496ull,
        "max(2.2250738585072014e-308, -6.283185307179586)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, 2.2250738585072014e-308, 6.283185307179586)),
        4618760256179416344ull,
        "max(2.2250738585072014e-308, 6.283185307179586)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, -2.2250738585072014e-308, -1.7976931348623157e+308)),
        9227875636482146304ull,
        "max(-2.2250738585072014e-308, -1.7976931348623157e+308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, -2.2250738585072014e-308, 1.7976931348623157e+308)),
        9218868437227405311ull,
        "max(-2.2250738585072014e-308, 1.7976931348623157e+308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, 2.2250738585072014e-308, -1.7976931348623157e+308)),
        4503599627370496ull,
        "max(2.2250738585072014e-308, -1.7976931348623157e+308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, 2.2250738585072014e-308, 1.7976931348623157e+308)),
        9218868437227405311ull,
        "max(2.2250738585072014e-308, 1.7976931348623157e+308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, -2.2250738585072014e-308, -INFINITY)),
        9227875636482146304ull,
        "max(-2.2250738585072014e-308, -INFINITY)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, -2.2250738585072014e-308, INFINITY)),
        9218868437227405312ull,
        "max(-2.2250738585072014e-308, INFINITY)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, 2.2250738585072014e-308, -INFINITY)),
        4503599627370496ull,
        "max(2.2250738585072014e-308, -INFINITY)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, 2.2250738585072014e-308, INFINITY)),
        9218868437227405312ull,
        "max(2.2250738585072014e-308, INFINITY)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, -2.2250738585072014e-308, f64_reinterpret_i64(0xfff8000000000000ull))) & 9223372036854775807ull),
        9221120237041090560ull,
        "max(-2.2250738585072014e-308, f64_reinterpret_i64(0xfff8000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, -2.2250738585072014e-308, f64_reinterpret_i64(0xfff4000000000000ull))) & 9221120237041090560ull),
        9221120237041090560ull,
        "max(-2.2250738585072014e-308, f64_reinterpret_i64(0xfff4000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, -2.2250738585072014e-308, f64_reinterpret_i64(0x7ff8000000000000ull))) & 9223372036854775807ull),
        9221120237041090560ull,
        "max(-2.2250738585072014e-308, f64_reinterpret_i64(0x7ff8000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, -2.2250738585072014e-308, f64_reinterpret_i64(0x7ff4000000000000ull))) & 9221120237041090560ull),
        9221120237041090560ull,
        "max(-2.2250738585072014e-308, f64_reinterpret_i64(0x7ff4000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, 2.2250738585072014e-308, f64_reinterpret_i64(0xfff8000000000000ull))) & 9223372036854775807ull),
        9221120237041090560ull,
        "max(2.2250738585072014e-308, f64_reinterpret_i64(0xfff8000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, 2.2250738585072014e-308, f64_reinterpret_i64(0xfff4000000000000ull))) & 9221120237041090560ull),
        9221120237041090560ull,
        "max(2.2250738585072014e-308, f64_reinterpret_i64(0xfff4000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, 2.2250738585072014e-308, f64_reinterpret_i64(0x7ff8000000000000ull))) & 9223372036854775807ull),
        9221120237041090560ull,
        "max(2.2250738585072014e-308, f64_reinterpret_i64(0x7ff8000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, 2.2250738585072014e-308, f64_reinterpret_i64(0x7ff4000000000000ull))) & 9221120237041090560ull),
        9221120237041090560ull,
        "max(2.2250738585072014e-308, f64_reinterpret_i64(0x7ff4000000000000ull))"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, -0.5, -0.0)),
        9223372036854775808ull,
        "max(-0.5, -0.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, -0.5, 0.0)),
        0ull,
        "max(-0.5, 0.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, 0.5, -0.0)),
        4602678819172646912ull,
        "max(0.5, -0.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, 0.5, 0.0)),
        4602678819172646912ull,
        "max(0.5, 0.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, -0.5, -5e-324)),
        9223372036854775809ull,
        "max(-0.5, -5e-324)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, -0.5, 5e-324)),
        1ull,
        "max(-0.5, 5e-324)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, 0.5, -5e-324)),
        4602678819172646912ull,
        "max(0.5, -5e-324)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, 0.5, 5e-324)),
        4602678819172646912ull,
        "max(0.5, 5e-324)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, -0.5, -2.2250738585072014e-308)),
        9227875636482146304ull,
        "max(-0.5, -2.2250738585072014e-308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, -0.5, 2.2250738585072014e-308)),
        4503599627370496ull,
        "max(-0.5, 2.2250738585072014e-308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, 0.5, -2.2250738585072014e-308)),
        4602678819172646912ull,
        "max(0.5, -2.2250738585072014e-308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, 0.5, 2.2250738585072014e-308)),
        4602678819172646912ull,
        "max(0.5, 2.2250738585072014e-308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, -0.5, -0.5)),
        13826050856027422720ull,
        "max(-0.5, -0.5)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, -0.5, 0.5)),
        4602678819172646912ull,
        "max(-0.5, 0.5)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, 0.5, -0.5)),
        4602678819172646912ull,
        "max(0.5, -0.5)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, 0.5, 0.5)),
        4602678819172646912ull,
        "max(0.5, 0.5)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, -0.5, -1.0)),
        13826050856027422720ull,
        "max(-0.5, -1.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, -0.5, 1.0)),
        4607182418800017408ull,
        "max(-0.5, 1.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, 0.5, -1.0)),
        4602678819172646912ull,
        "max(0.5, -1.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, 0.5, 1.0)),
        4607182418800017408ull,
        "max(0.5, 1.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, -0.5, -6.283185307179586)),
        13826050856027422720ull,
        "max(-0.5, -6.283185307179586)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, -0.5, 6.283185307179586)),
        4618760256179416344ull,
        "max(-0.5, 6.283185307179586)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, 0.5, -6.283185307179586)),
        4602678819172646912ull,
        "max(0.5, -6.283185307179586)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, 0.5, 6.283185307179586)),
        4618760256179416344ull,
        "max(0.5, 6.283185307179586)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, -0.5, -1.7976931348623157e+308)),
        13826050856027422720ull,
        "max(-0.5, -1.7976931348623157e+308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, -0.5, 1.7976931348623157e+308)),
        9218868437227405311ull,
        "max(-0.5, 1.7976931348623157e+308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, 0.5, -1.7976931348623157e+308)),
        4602678819172646912ull,
        "max(0.5, -1.7976931348623157e+308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, 0.5, 1.7976931348623157e+308)),
        9218868437227405311ull,
        "max(0.5, 1.7976931348623157e+308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, -0.5, -INFINITY)),
        13826050856027422720ull,
        "max(-0.5, -INFINITY)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, -0.5, INFINITY)),
        9218868437227405312ull,
        "max(-0.5, INFINITY)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, 0.5, -INFINITY)),
        4602678819172646912ull,
        "max(0.5, -INFINITY)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, 0.5, INFINITY)),
        9218868437227405312ull,
        "max(0.5, INFINITY)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, -0.5, f64_reinterpret_i64(0xfff8000000000000ull))) & 9223372036854775807ull),
        9221120237041090560ull,
        "max(-0.5, f64_reinterpret_i64(0xfff8000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, -0.5, f64_reinterpret_i64(0xfff4000000000000ull))) & 9221120237041090560ull),
        9221120237041090560ull,
        "max(-0.5, f64_reinterpret_i64(0xfff4000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, -0.5, f64_reinterpret_i64(0x7ff8000000000000ull))) & 9223372036854775807ull),
        9221120237041090560ull,
        "max(-0.5, f64_reinterpret_i64(0x7ff8000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, -0.5, f64_reinterpret_i64(0x7ff4000000000000ull))) & 9221120237041090560ull),
        9221120237041090560ull,
        "max(-0.5, f64_reinterpret_i64(0x7ff4000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, 0.5, f64_reinterpret_i64(0xfff8000000000000ull))) & 9223372036854775807ull),
        9221120237041090560ull,
        "max(0.5, f64_reinterpret_i64(0xfff8000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, 0.5, f64_reinterpret_i64(0xfff4000000000000ull))) & 9221120237041090560ull),
        9221120237041090560ull,
        "max(0.5, f64_reinterpret_i64(0xfff4000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, 0.5, f64_reinterpret_i64(0x7ff8000000000000ull))) & 9223372036854775807ull),
        9221120237041090560ull,
        "max(0.5, f64_reinterpret_i64(0x7ff8000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, 0.5, f64_reinterpret_i64(0x7ff4000000000000ull))) & 9221120237041090560ull),
        9221120237041090560ull,
        "max(0.5, f64_reinterpret_i64(0x7ff4000000000000ull))"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, -1.0, -0.0)),
        9223372036854775808ull,
        "max(-1.0, -0.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, -1.0, 0.0)),
        0ull,
        "max(-1.0, 0.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, 1.0, -0.0)),
        4607182418800017408ull,
        "max(1.0, -0.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, 1.0, 0.0)),
        4607182418800017408ull,
        "max(1.0, 0.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, -1.0, -5e-324)),
        9223372036854775809ull,
        "max(-1.0, -5e-324)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, -1.0, 5e-324)),
        1ull,
        "max(-1.0, 5e-324)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, 1.0, -5e-324)),
        4607182418800017408ull,
        "max(1.0, -5e-324)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, 1.0, 5e-324)),
        4607182418800017408ull,
        "max(1.0, 5e-324)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, -1.0, -2.2250738585072014e-308)),
        9227875636482146304ull,
        "max(-1.0, -2.2250738585072014e-308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, -1.0, 2.2250738585072014e-308)),
        4503599627370496ull,
        "max(-1.0, 2.2250738585072014e-308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, 1.0, -2.2250738585072014e-308)),
        4607182418800017408ull,
        "max(1.0, -2.2250738585072014e-308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, 1.0, 2.2250738585072014e-308)),
        4607182418800017408ull,
        "max(1.0, 2.2250738585072014e-308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, -1.0, -0.5)),
        13826050856027422720ull,
        "max(-1.0, -0.5)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, -1.0, 0.5)),
        4602678819172646912ull,
        "max(-1.0, 0.5)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, 1.0, -0.5)),
        4607182418800017408ull,
        "max(1.0, -0.5)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, 1.0, 0.5)),
        4607182418800017408ull,
        "max(1.0, 0.5)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, -1.0, -1.0)),
        13830554455654793216ull,
        "max(-1.0, -1.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, -1.0, 1.0)),
        4607182418800017408ull,
        "max(-1.0, 1.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, 1.0, -1.0)),
        4607182418800017408ull,
        "max(1.0, -1.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, 1.0, 1.0)),
        4607182418800017408ull,
        "max(1.0, 1.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, -1.0, -6.283185307179586)),
        13830554455654793216ull,
        "max(-1.0, -6.283185307179586)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, -1.0, 6.283185307179586)),
        4618760256179416344ull,
        "max(-1.0, 6.283185307179586)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, 1.0, -6.283185307179586)),
        4607182418800017408ull,
        "max(1.0, -6.283185307179586)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, 1.0, 6.283185307179586)),
        4618760256179416344ull,
        "max(1.0, 6.283185307179586)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, -1.0, -1.7976931348623157e+308)),
        13830554455654793216ull,
        "max(-1.0, -1.7976931348623157e+308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, -1.0, 1.7976931348623157e+308)),
        9218868437227405311ull,
        "max(-1.0, 1.7976931348623157e+308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, 1.0, -1.7976931348623157e+308)),
        4607182418800017408ull,
        "max(1.0, -1.7976931348623157e+308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, 1.0, 1.7976931348623157e+308)),
        9218868437227405311ull,
        "max(1.0, 1.7976931348623157e+308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, -1.0, -INFINITY)),
        13830554455654793216ull,
        "max(-1.0, -INFINITY)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, -1.0, INFINITY)),
        9218868437227405312ull,
        "max(-1.0, INFINITY)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, 1.0, -INFINITY)),
        4607182418800017408ull,
        "max(1.0, -INFINITY)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, 1.0, INFINITY)),
        9218868437227405312ull,
        "max(1.0, INFINITY)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, -1.0, f64_reinterpret_i64(0xfff8000000000000ull))) & 9223372036854775807ull),
        9221120237041090560ull,
        "max(-1.0, f64_reinterpret_i64(0xfff8000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, -1.0, f64_reinterpret_i64(0xfff4000000000000ull))) & 9221120237041090560ull),
        9221120237041090560ull,
        "max(-1.0, f64_reinterpret_i64(0xfff4000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, -1.0, f64_reinterpret_i64(0x7ff8000000000000ull))) & 9223372036854775807ull),
        9221120237041090560ull,
        "max(-1.0, f64_reinterpret_i64(0x7ff8000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, -1.0, f64_reinterpret_i64(0x7ff4000000000000ull))) & 9221120237041090560ull),
        9221120237041090560ull,
        "max(-1.0, f64_reinterpret_i64(0x7ff4000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, 1.0, f64_reinterpret_i64(0xfff8000000000000ull))) & 9223372036854775807ull),
        9221120237041090560ull,
        "max(1.0, f64_reinterpret_i64(0xfff8000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, 1.0, f64_reinterpret_i64(0xfff4000000000000ull))) & 9221120237041090560ull),
        9221120237041090560ull,
        "max(1.0, f64_reinterpret_i64(0xfff4000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, 1.0, f64_reinterpret_i64(0x7ff8000000000000ull))) & 9223372036854775807ull),
        9221120237041090560ull,
        "max(1.0, f64_reinterpret_i64(0x7ff8000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, 1.0, f64_reinterpret_i64(0x7ff4000000000000ull))) & 9221120237041090560ull),
        9221120237041090560ull,
        "max(1.0, f64_reinterpret_i64(0x7ff4000000000000ull))"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, -6.283185307179586, -0.0)),
        9223372036854775808ull,
        "max(-6.283185307179586, -0.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, -6.283185307179586, 0.0)),
        0ull,
        "max(-6.283185307179586, 0.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, 6.283185307179586, -0.0)),
        4618760256179416344ull,
        "max(6.283185307179586, -0.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, 6.283185307179586, 0.0)),
        4618760256179416344ull,
        "max(6.283185307179586, 0.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, -6.283185307179586, -5e-324)),
        9223372036854775809ull,
        "max(-6.283185307179586, -5e-324)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, -6.283185307179586, 5e-324)),
        1ull,
        "max(-6.283185307179586, 5e-324)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, 6.283185307179586, -5e-324)),
        4618760256179416344ull,
        "max(6.283185307179586, -5e-324)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, 6.283185307179586, 5e-324)),
        4618760256179416344ull,
        "max(6.283185307179586, 5e-324)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, -6.283185307179586, -2.2250738585072014e-308)),
        9227875636482146304ull,
        "max(-6.283185307179586, -2.2250738585072014e-308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, -6.283185307179586, 2.2250738585072014e-308)),
        4503599627370496ull,
        "max(-6.283185307179586, 2.2250738585072014e-308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, 6.283185307179586, -2.2250738585072014e-308)),
        4618760256179416344ull,
        "max(6.283185307179586, -2.2250738585072014e-308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, 6.283185307179586, 2.2250738585072014e-308)),
        4618760256179416344ull,
        "max(6.283185307179586, 2.2250738585072014e-308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, -6.283185307179586, -0.5)),
        13826050856027422720ull,
        "max(-6.283185307179586, -0.5)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, -6.283185307179586, 0.5)),
        4602678819172646912ull,
        "max(-6.283185307179586, 0.5)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, 6.283185307179586, -0.5)),
        4618760256179416344ull,
        "max(6.283185307179586, -0.5)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, 6.283185307179586, 0.5)),
        4618760256179416344ull,
        "max(6.283185307179586, 0.5)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, -6.283185307179586, -1.0)),
        13830554455654793216ull,
        "max(-6.283185307179586, -1.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, -6.283185307179586, 1.0)),
        4607182418800017408ull,
        "max(-6.283185307179586, 1.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, 6.283185307179586, -1.0)),
        4618760256179416344ull,
        "max(6.283185307179586, -1.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, 6.283185307179586, 1.0)),
        4618760256179416344ull,
        "max(6.283185307179586, 1.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, -6.283185307179586, -6.283185307179586)),
        13842132293034192152ull,
        "max(-6.283185307179586, -6.283185307179586)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, -6.283185307179586, 6.283185307179586)),
        4618760256179416344ull,
        "max(-6.283185307179586, 6.283185307179586)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, 6.283185307179586, -6.283185307179586)),
        4618760256179416344ull,
        "max(6.283185307179586, -6.283185307179586)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, 6.283185307179586, 6.283185307179586)),
        4618760256179416344ull,
        "max(6.283185307179586, 6.283185307179586)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, -6.283185307179586, -1.7976931348623157e+308)),
        13842132293034192152ull,
        "max(-6.283185307179586, -1.7976931348623157e+308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, -6.283185307179586, 1.7976931348623157e+308)),
        9218868437227405311ull,
        "max(-6.283185307179586, 1.7976931348623157e+308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, 6.283185307179586, -1.7976931348623157e+308)),
        4618760256179416344ull,
        "max(6.283185307179586, -1.7976931348623157e+308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, 6.283185307179586, 1.7976931348623157e+308)),
        9218868437227405311ull,
        "max(6.283185307179586, 1.7976931348623157e+308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, -6.283185307179586, -INFINITY)),
        13842132293034192152ull,
        "max(-6.283185307179586, -INFINITY)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, -6.283185307179586, INFINITY)),
        9218868437227405312ull,
        "max(-6.283185307179586, INFINITY)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, 6.283185307179586, -INFINITY)),
        4618760256179416344ull,
        "max(6.283185307179586, -INFINITY)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, 6.283185307179586, INFINITY)),
        9218868437227405312ull,
        "max(6.283185307179586, INFINITY)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, -6.283185307179586, f64_reinterpret_i64(0xfff8000000000000ull))) & 9223372036854775807ull),
        9221120237041090560ull,
        "max(-6.283185307179586, f64_reinterpret_i64(0xfff8000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, -6.283185307179586, f64_reinterpret_i64(0xfff4000000000000ull))) & 9221120237041090560ull),
        9221120237041090560ull,
        "max(-6.283185307179586, f64_reinterpret_i64(0xfff4000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, -6.283185307179586, f64_reinterpret_i64(0x7ff8000000000000ull))) & 9223372036854775807ull),
        9221120237041090560ull,
        "max(-6.283185307179586, f64_reinterpret_i64(0x7ff8000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, -6.283185307179586, f64_reinterpret_i64(0x7ff4000000000000ull))) & 9221120237041090560ull),
        9221120237041090560ull,
        "max(-6.283185307179586, f64_reinterpret_i64(0x7ff4000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, 6.283185307179586, f64_reinterpret_i64(0xfff8000000000000ull))) & 9223372036854775807ull),
        9221120237041090560ull,
        "max(6.283185307179586, f64_reinterpret_i64(0xfff8000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, 6.283185307179586, f64_reinterpret_i64(0xfff4000000000000ull))) & 9221120237041090560ull),
        9221120237041090560ull,
        "max(6.283185307179586, f64_reinterpret_i64(0xfff4000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, 6.283185307179586, f64_reinterpret_i64(0x7ff8000000000000ull))) & 9223372036854775807ull),
        9221120237041090560ull,
        "max(6.283185307179586, f64_reinterpret_i64(0x7ff8000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, 6.283185307179586, f64_reinterpret_i64(0x7ff4000000000000ull))) & 9221120237041090560ull),
        9221120237041090560ull,
        "max(6.283185307179586, f64_reinterpret_i64(0x7ff4000000000000ull))"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, -1.7976931348623157e+308, -0.0)),
        9223372036854775808ull,
        "max(-1.7976931348623157e+308, -0.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, -1.7976931348623157e+308, 0.0)),
        0ull,
        "max(-1.7976931348623157e+308, 0.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, 1.7976931348623157e+308, -0.0)),
        9218868437227405311ull,
        "max(1.7976931348623157e+308, -0.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, 1.7976931348623157e+308, 0.0)),
        9218868437227405311ull,
        "max(1.7976931348623157e+308, 0.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, -1.7976931348623157e+308, -5e-324)),
        9223372036854775809ull,
        "max(-1.7976931348623157e+308, -5e-324)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, -1.7976931348623157e+308, 5e-324)),
        1ull,
        "max(-1.7976931348623157e+308, 5e-324)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, 1.7976931348623157e+308, -5e-324)),
        9218868437227405311ull,
        "max(1.7976931348623157e+308, -5e-324)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, 1.7976931348623157e+308, 5e-324)),
        9218868437227405311ull,
        "max(1.7976931348623157e+308, 5e-324)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, -1.7976931348623157e+308, -2.2250738585072014e-308)),
        9227875636482146304ull,
        "max(-1.7976931348623157e+308, -2.2250738585072014e-308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, -1.7976931348623157e+308, 2.2250738585072014e-308)),
        4503599627370496ull,
        "max(-1.7976931348623157e+308, 2.2250738585072014e-308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, 1.7976931348623157e+308, -2.2250738585072014e-308)),
        9218868437227405311ull,
        "max(1.7976931348623157e+308, -2.2250738585072014e-308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, 1.7976931348623157e+308, 2.2250738585072014e-308)),
        9218868437227405311ull,
        "max(1.7976931348623157e+308, 2.2250738585072014e-308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, -1.7976931348623157e+308, -0.5)),
        13826050856027422720ull,
        "max(-1.7976931348623157e+308, -0.5)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, -1.7976931348623157e+308, 0.5)),
        4602678819172646912ull,
        "max(-1.7976931348623157e+308, 0.5)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, 1.7976931348623157e+308, -0.5)),
        9218868437227405311ull,
        "max(1.7976931348623157e+308, -0.5)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, 1.7976931348623157e+308, 0.5)),
        9218868437227405311ull,
        "max(1.7976931348623157e+308, 0.5)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, -1.7976931348623157e+308, -1.0)),
        13830554455654793216ull,
        "max(-1.7976931348623157e+308, -1.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, -1.7976931348623157e+308, 1.0)),
        4607182418800017408ull,
        "max(-1.7976931348623157e+308, 1.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, 1.7976931348623157e+308, -1.0)),
        9218868437227405311ull,
        "max(1.7976931348623157e+308, -1.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, 1.7976931348623157e+308, 1.0)),
        9218868437227405311ull,
        "max(1.7976931348623157e+308, 1.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, -1.7976931348623157e+308, -6.283185307179586)),
        13842132293034192152ull,
        "max(-1.7976931348623157e+308, -6.283185307179586)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, -1.7976931348623157e+308, 6.283185307179586)),
        4618760256179416344ull,
        "max(-1.7976931348623157e+308, 6.283185307179586)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, 1.7976931348623157e+308, -6.283185307179586)),
        9218868437227405311ull,
        "max(1.7976931348623157e+308, -6.283185307179586)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, 1.7976931348623157e+308, 6.283185307179586)),
        9218868437227405311ull,
        "max(1.7976931348623157e+308, 6.283185307179586)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, -1.7976931348623157e+308, -1.7976931348623157e+308)),
        18442240474082181119ull,
        "max(-1.7976931348623157e+308, -1.7976931348623157e+308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, -1.7976931348623157e+308, 1.7976931348623157e+308)),
        9218868437227405311ull,
        "max(-1.7976931348623157e+308, 1.7976931348623157e+308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, 1.7976931348623157e+308, -1.7976931348623157e+308)),
        9218868437227405311ull,
        "max(1.7976931348623157e+308, -1.7976931348623157e+308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, 1.7976931348623157e+308, 1.7976931348623157e+308)),
        9218868437227405311ull,
        "max(1.7976931348623157e+308, 1.7976931348623157e+308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, -1.7976931348623157e+308, -INFINITY)),
        18442240474082181119ull,
        "max(-1.7976931348623157e+308, -INFINITY)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, -1.7976931348623157e+308, INFINITY)),
        9218868437227405312ull,
        "max(-1.7976931348623157e+308, INFINITY)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, 1.7976931348623157e+308, -INFINITY)),
        9218868437227405311ull,
        "max(1.7976931348623157e+308, -INFINITY)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, 1.7976931348623157e+308, INFINITY)),
        9218868437227405312ull,
        "max(1.7976931348623157e+308, INFINITY)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, -1.7976931348623157e+308, f64_reinterpret_i64(0xfff8000000000000ull))) & 9223372036854775807ull),
        9221120237041090560ull,
        "max(-1.7976931348623157e+308, f64_reinterpret_i64(0xfff8000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, -1.7976931348623157e+308, f64_reinterpret_i64(0xfff4000000000000ull))) & 9221120237041090560ull),
        9221120237041090560ull,
        "max(-1.7976931348623157e+308, f64_reinterpret_i64(0xfff4000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, -1.7976931348623157e+308, f64_reinterpret_i64(0x7ff8000000000000ull))) & 9223372036854775807ull),
        9221120237041090560ull,
        "max(-1.7976931348623157e+308, f64_reinterpret_i64(0x7ff8000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, -1.7976931348623157e+308, f64_reinterpret_i64(0x7ff4000000000000ull))) & 9221120237041090560ull),
        9221120237041090560ull,
        "max(-1.7976931348623157e+308, f64_reinterpret_i64(0x7ff4000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, 1.7976931348623157e+308, f64_reinterpret_i64(0xfff8000000000000ull))) & 9223372036854775807ull),
        9221120237041090560ull,
        "max(1.7976931348623157e+308, f64_reinterpret_i64(0xfff8000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, 1.7976931348623157e+308, f64_reinterpret_i64(0xfff4000000000000ull))) & 9221120237041090560ull),
        9221120237041090560ull,
        "max(1.7976931348623157e+308, f64_reinterpret_i64(0xfff4000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, 1.7976931348623157e+308, f64_reinterpret_i64(0x7ff8000000000000ull))) & 9223372036854775807ull),
        9221120237041090560ull,
        "max(1.7976931348623157e+308, f64_reinterpret_i64(0x7ff8000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, 1.7976931348623157e+308, f64_reinterpret_i64(0x7ff4000000000000ull))) & 9221120237041090560ull),
        9221120237041090560ull,
        "max(1.7976931348623157e+308, f64_reinterpret_i64(0x7ff4000000000000ull))"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, -INFINITY, -0.0)),
        9223372036854775808ull,
        "max(-INFINITY, -0.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, -INFINITY, 0.0)),
        0ull,
        "max(-INFINITY, 0.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, INFINITY, -0.0)),
        9218868437227405312ull,
        "max(INFINITY, -0.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, INFINITY, 0.0)),
        9218868437227405312ull,
        "max(INFINITY, 0.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, -INFINITY, -5e-324)),
        9223372036854775809ull,
        "max(-INFINITY, -5e-324)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, -INFINITY, 5e-324)),
        1ull,
        "max(-INFINITY, 5e-324)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, INFINITY, -5e-324)),
        9218868437227405312ull,
        "max(INFINITY, -5e-324)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, INFINITY, 5e-324)),
        9218868437227405312ull,
        "max(INFINITY, 5e-324)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, -INFINITY, -2.2250738585072014e-308)),
        9227875636482146304ull,
        "max(-INFINITY, -2.2250738585072014e-308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, -INFINITY, 2.2250738585072014e-308)),
        4503599627370496ull,
        "max(-INFINITY, 2.2250738585072014e-308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, INFINITY, -2.2250738585072014e-308)),
        9218868437227405312ull,
        "max(INFINITY, -2.2250738585072014e-308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, INFINITY, 2.2250738585072014e-308)),
        9218868437227405312ull,
        "max(INFINITY, 2.2250738585072014e-308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, -INFINITY, -0.5)),
        13826050856027422720ull,
        "max(-INFINITY, -0.5)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, -INFINITY, 0.5)),
        4602678819172646912ull,
        "max(-INFINITY, 0.5)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, INFINITY, -0.5)),
        9218868437227405312ull,
        "max(INFINITY, -0.5)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, INFINITY, 0.5)),
        9218868437227405312ull,
        "max(INFINITY, 0.5)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, -INFINITY, -1.0)),
        13830554455654793216ull,
        "max(-INFINITY, -1.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, -INFINITY, 1.0)),
        4607182418800017408ull,
        "max(-INFINITY, 1.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, INFINITY, -1.0)),
        9218868437227405312ull,
        "max(INFINITY, -1.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, INFINITY, 1.0)),
        9218868437227405312ull,
        "max(INFINITY, 1.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, -INFINITY, -6.283185307179586)),
        13842132293034192152ull,
        "max(-INFINITY, -6.283185307179586)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, -INFINITY, 6.283185307179586)),
        4618760256179416344ull,
        "max(-INFINITY, 6.283185307179586)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, INFINITY, -6.283185307179586)),
        9218868437227405312ull,
        "max(INFINITY, -6.283185307179586)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, INFINITY, 6.283185307179586)),
        9218868437227405312ull,
        "max(INFINITY, 6.283185307179586)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, -INFINITY, -1.7976931348623157e+308)),
        18442240474082181119ull,
        "max(-INFINITY, -1.7976931348623157e+308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, -INFINITY, 1.7976931348623157e+308)),
        9218868437227405311ull,
        "max(-INFINITY, 1.7976931348623157e+308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, INFINITY, -1.7976931348623157e+308)),
        9218868437227405312ull,
        "max(INFINITY, -1.7976931348623157e+308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, INFINITY, 1.7976931348623157e+308)),
        9218868437227405312ull,
        "max(INFINITY, 1.7976931348623157e+308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, -INFINITY, -INFINITY)),
        18442240474082181120ull,
        "max(-INFINITY, -INFINITY)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, -INFINITY, INFINITY)),
        9218868437227405312ull,
        "max(-INFINITY, INFINITY)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, INFINITY, -INFINITY)),
        9218868437227405312ull,
        "max(INFINITY, -INFINITY)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, INFINITY, INFINITY)),
        9218868437227405312ull,
        "max(INFINITY, INFINITY)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, -INFINITY, f64_reinterpret_i64(0xfff8000000000000ull))) & 9223372036854775807ull),
        9221120237041090560ull,
        "max(-INFINITY, f64_reinterpret_i64(0xfff8000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, -INFINITY, f64_reinterpret_i64(0xfff4000000000000ull))) & 9221120237041090560ull),
        9221120237041090560ull,
        "max(-INFINITY, f64_reinterpret_i64(0xfff4000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, -INFINITY, f64_reinterpret_i64(0x7ff8000000000000ull))) & 9223372036854775807ull),
        9221120237041090560ull,
        "max(-INFINITY, f64_reinterpret_i64(0x7ff8000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, -INFINITY, f64_reinterpret_i64(0x7ff4000000000000ull))) & 9221120237041090560ull),
        9221120237041090560ull,
        "max(-INFINITY, f64_reinterpret_i64(0x7ff4000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, INFINITY, f64_reinterpret_i64(0xfff8000000000000ull))) & 9223372036854775807ull),
        9221120237041090560ull,
        "max(INFINITY, f64_reinterpret_i64(0xfff8000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, INFINITY, f64_reinterpret_i64(0xfff4000000000000ull))) & 9221120237041090560ull),
        9221120237041090560ull,
        "max(INFINITY, f64_reinterpret_i64(0xfff4000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, INFINITY, f64_reinterpret_i64(0x7ff8000000000000ull))) & 9223372036854775807ull),
        9221120237041090560ull,
        "max(INFINITY, f64_reinterpret_i64(0x7ff8000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, INFINITY, f64_reinterpret_i64(0x7ff4000000000000ull))) & 9221120237041090560ull),
        9221120237041090560ull,
        "max(INFINITY, f64_reinterpret_i64(0x7ff4000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, f64_reinterpret_i64(0xfff8000000000000ull), -0.0)) & 9223372036854775807ull),
        9221120237041090560ull,
        "max(f64_reinterpret_i64(0xfff8000000000000ull), -0.0)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, f64_reinterpret_i64(0xfff4000000000000ull), -0.0)) & 9221120237041090560ull),
        9221120237041090560ull,
        "max(f64_reinterpret_i64(0xfff4000000000000ull), -0.0)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, f64_reinterpret_i64(0xfff8000000000000ull), 0.0)) & 9223372036854775807ull),
        9221120237041090560ull,
        "max(f64_reinterpret_i64(0xfff8000000000000ull), 0.0)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, f64_reinterpret_i64(0xfff4000000000000ull), 0.0)) & 9221120237041090560ull),
        9221120237041090560ull,
        "max(f64_reinterpret_i64(0xfff4000000000000ull), 0.0)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, f64_reinterpret_i64(0x7ff8000000000000ull), -0.0)) & 9223372036854775807ull),
        9221120237041090560ull,
        "max(f64_reinterpret_i64(0x7ff8000000000000ull), -0.0)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, f64_reinterpret_i64(0x7ff4000000000000ull), -0.0)) & 9221120237041090560ull),
        9221120237041090560ull,
        "max(f64_reinterpret_i64(0x7ff4000000000000ull), -0.0)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, f64_reinterpret_i64(0x7ff8000000000000ull), 0.0)) & 9223372036854775807ull),
        9221120237041090560ull,
        "max(f64_reinterpret_i64(0x7ff8000000000000ull), 0.0)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, f64_reinterpret_i64(0x7ff4000000000000ull), 0.0)) & 9221120237041090560ull),
        9221120237041090560ull,
        "max(f64_reinterpret_i64(0x7ff4000000000000ull), 0.0)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, f64_reinterpret_i64(0xfff8000000000000ull), -5e-324)) & 9223372036854775807ull),
        9221120237041090560ull,
        "max(f64_reinterpret_i64(0xfff8000000000000ull), -5e-324)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, f64_reinterpret_i64(0xfff4000000000000ull), -5e-324)) & 9221120237041090560ull),
        9221120237041090560ull,
        "max(f64_reinterpret_i64(0xfff4000000000000ull), -5e-324)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, f64_reinterpret_i64(0xfff8000000000000ull), 5e-324)) & 9223372036854775807ull),
        9221120237041090560ull,
        "max(f64_reinterpret_i64(0xfff8000000000000ull), 5e-324)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, f64_reinterpret_i64(0xfff4000000000000ull), 5e-324)) & 9221120237041090560ull),
        9221120237041090560ull,
        "max(f64_reinterpret_i64(0xfff4000000000000ull), 5e-324)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, f64_reinterpret_i64(0x7ff8000000000000ull), -5e-324)) & 9223372036854775807ull),
        9221120237041090560ull,
        "max(f64_reinterpret_i64(0x7ff8000000000000ull), -5e-324)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, f64_reinterpret_i64(0x7ff4000000000000ull), -5e-324)) & 9221120237041090560ull),
        9221120237041090560ull,
        "max(f64_reinterpret_i64(0x7ff4000000000000ull), -5e-324)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, f64_reinterpret_i64(0x7ff8000000000000ull), 5e-324)) & 9223372036854775807ull),
        9221120237041090560ull,
        "max(f64_reinterpret_i64(0x7ff8000000000000ull), 5e-324)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, f64_reinterpret_i64(0x7ff4000000000000ull), 5e-324)) & 9221120237041090560ull),
        9221120237041090560ull,
        "max(f64_reinterpret_i64(0x7ff4000000000000ull), 5e-324)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, f64_reinterpret_i64(0xfff8000000000000ull), -2.2250738585072014e-308)) & 9223372036854775807ull),
        9221120237041090560ull,
        "max(f64_reinterpret_i64(0xfff8000000000000ull), -2.2250738585072014e-308)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, f64_reinterpret_i64(0xfff4000000000000ull), -2.2250738585072014e-308)) & 9221120237041090560ull),
        9221120237041090560ull,
        "max(f64_reinterpret_i64(0xfff4000000000000ull), -2.2250738585072014e-308)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, f64_reinterpret_i64(0xfff8000000000000ull), 2.2250738585072014e-308)) & 9223372036854775807ull),
        9221120237041090560ull,
        "max(f64_reinterpret_i64(0xfff8000000000000ull), 2.2250738585072014e-308)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, f64_reinterpret_i64(0xfff4000000000000ull), 2.2250738585072014e-308)) & 9221120237041090560ull),
        9221120237041090560ull,
        "max(f64_reinterpret_i64(0xfff4000000000000ull), 2.2250738585072014e-308)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, f64_reinterpret_i64(0x7ff8000000000000ull), -2.2250738585072014e-308)) & 9223372036854775807ull),
        9221120237041090560ull,
        "max(f64_reinterpret_i64(0x7ff8000000000000ull), -2.2250738585072014e-308)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, f64_reinterpret_i64(0x7ff4000000000000ull), -2.2250738585072014e-308)) & 9221120237041090560ull),
        9221120237041090560ull,
        "max(f64_reinterpret_i64(0x7ff4000000000000ull), -2.2250738585072014e-308)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, f64_reinterpret_i64(0x7ff8000000000000ull), 2.2250738585072014e-308)) & 9223372036854775807ull),
        9221120237041090560ull,
        "max(f64_reinterpret_i64(0x7ff8000000000000ull), 2.2250738585072014e-308)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, f64_reinterpret_i64(0x7ff4000000000000ull), 2.2250738585072014e-308)) & 9221120237041090560ull),
        9221120237041090560ull,
        "max(f64_reinterpret_i64(0x7ff4000000000000ull), 2.2250738585072014e-308)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, f64_reinterpret_i64(0xfff8000000000000ull), -0.5)) & 9223372036854775807ull),
        9221120237041090560ull,
        "max(f64_reinterpret_i64(0xfff8000000000000ull), -0.5)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, f64_reinterpret_i64(0xfff4000000000000ull), -0.5)) & 9221120237041090560ull),
        9221120237041090560ull,
        "max(f64_reinterpret_i64(0xfff4000000000000ull), -0.5)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, f64_reinterpret_i64(0xfff8000000000000ull), 0.5)) & 9223372036854775807ull),
        9221120237041090560ull,
        "max(f64_reinterpret_i64(0xfff8000000000000ull), 0.5)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, f64_reinterpret_i64(0xfff4000000000000ull), 0.5)) & 9221120237041090560ull),
        9221120237041090560ull,
        "max(f64_reinterpret_i64(0xfff4000000000000ull), 0.5)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, f64_reinterpret_i64(0x7ff8000000000000ull), -0.5)) & 9223372036854775807ull),
        9221120237041090560ull,
        "max(f64_reinterpret_i64(0x7ff8000000000000ull), -0.5)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, f64_reinterpret_i64(0x7ff4000000000000ull), -0.5)) & 9221120237041090560ull),
        9221120237041090560ull,
        "max(f64_reinterpret_i64(0x7ff4000000000000ull), -0.5)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, f64_reinterpret_i64(0x7ff8000000000000ull), 0.5)) & 9223372036854775807ull),
        9221120237041090560ull,
        "max(f64_reinterpret_i64(0x7ff8000000000000ull), 0.5)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, f64_reinterpret_i64(0x7ff4000000000000ull), 0.5)) & 9221120237041090560ull),
        9221120237041090560ull,
        "max(f64_reinterpret_i64(0x7ff4000000000000ull), 0.5)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, f64_reinterpret_i64(0xfff8000000000000ull), -1.0)) & 9223372036854775807ull),
        9221120237041090560ull,
        "max(f64_reinterpret_i64(0xfff8000000000000ull), -1.0)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, f64_reinterpret_i64(0xfff4000000000000ull), -1.0)) & 9221120237041090560ull),
        9221120237041090560ull,
        "max(f64_reinterpret_i64(0xfff4000000000000ull), -1.0)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, f64_reinterpret_i64(0xfff8000000000000ull), 1.0)) & 9223372036854775807ull),
        9221120237041090560ull,
        "max(f64_reinterpret_i64(0xfff8000000000000ull), 1.0)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, f64_reinterpret_i64(0xfff4000000000000ull), 1.0)) & 9221120237041090560ull),
        9221120237041090560ull,
        "max(f64_reinterpret_i64(0xfff4000000000000ull), 1.0)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, f64_reinterpret_i64(0x7ff8000000000000ull), -1.0)) & 9223372036854775807ull),
        9221120237041090560ull,
        "max(f64_reinterpret_i64(0x7ff8000000000000ull), -1.0)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, f64_reinterpret_i64(0x7ff4000000000000ull), -1.0)) & 9221120237041090560ull),
        9221120237041090560ull,
        "max(f64_reinterpret_i64(0x7ff4000000000000ull), -1.0)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, f64_reinterpret_i64(0x7ff8000000000000ull), 1.0)) & 9223372036854775807ull),
        9221120237041090560ull,
        "max(f64_reinterpret_i64(0x7ff8000000000000ull), 1.0)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, f64_reinterpret_i64(0x7ff4000000000000ull), 1.0)) & 9221120237041090560ull),
        9221120237041090560ull,
        "max(f64_reinterpret_i64(0x7ff4000000000000ull), 1.0)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, f64_reinterpret_i64(0xfff8000000000000ull), -6.283185307179586)) & 9223372036854775807ull),
        9221120237041090560ull,
        "max(f64_reinterpret_i64(0xfff8000000000000ull), -6.283185307179586)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, f64_reinterpret_i64(0xfff4000000000000ull), -6.283185307179586)) & 9221120237041090560ull),
        9221120237041090560ull,
        "max(f64_reinterpret_i64(0xfff4000000000000ull), -6.283185307179586)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, f64_reinterpret_i64(0xfff8000000000000ull), 6.283185307179586)) & 9223372036854775807ull),
        9221120237041090560ull,
        "max(f64_reinterpret_i64(0xfff8000000000000ull), 6.283185307179586)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, f64_reinterpret_i64(0xfff4000000000000ull), 6.283185307179586)) & 9221120237041090560ull),
        9221120237041090560ull,
        "max(f64_reinterpret_i64(0xfff4000000000000ull), 6.283185307179586)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, f64_reinterpret_i64(0x7ff8000000000000ull), -6.283185307179586)) & 9223372036854775807ull),
        9221120237041090560ull,
        "max(f64_reinterpret_i64(0x7ff8000000000000ull), -6.283185307179586)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, f64_reinterpret_i64(0x7ff4000000000000ull), -6.283185307179586)) & 9221120237041090560ull),
        9221120237041090560ull,
        "max(f64_reinterpret_i64(0x7ff4000000000000ull), -6.283185307179586)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, f64_reinterpret_i64(0x7ff8000000000000ull), 6.283185307179586)) & 9223372036854775807ull),
        9221120237041090560ull,
        "max(f64_reinterpret_i64(0x7ff8000000000000ull), 6.283185307179586)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, f64_reinterpret_i64(0x7ff4000000000000ull), 6.283185307179586)) & 9221120237041090560ull),
        9221120237041090560ull,
        "max(f64_reinterpret_i64(0x7ff4000000000000ull), 6.283185307179586)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, f64_reinterpret_i64(0xfff8000000000000ull), -1.7976931348623157e+308)) & 9223372036854775807ull),
        9221120237041090560ull,
        "max(f64_reinterpret_i64(0xfff8000000000000ull), -1.7976931348623157e+308)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, f64_reinterpret_i64(0xfff4000000000000ull), -1.7976931348623157e+308)) & 9221120237041090560ull),
        9221120237041090560ull,
        "max(f64_reinterpret_i64(0xfff4000000000000ull), -1.7976931348623157e+308)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, f64_reinterpret_i64(0xfff8000000000000ull), 1.7976931348623157e+308)) & 9223372036854775807ull),
        9221120237041090560ull,
        "max(f64_reinterpret_i64(0xfff8000000000000ull), 1.7976931348623157e+308)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, f64_reinterpret_i64(0xfff4000000000000ull), 1.7976931348623157e+308)) & 9221120237041090560ull),
        9221120237041090560ull,
        "max(f64_reinterpret_i64(0xfff4000000000000ull), 1.7976931348623157e+308)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, f64_reinterpret_i64(0x7ff8000000000000ull), -1.7976931348623157e+308)) & 9223372036854775807ull),
        9221120237041090560ull,
        "max(f64_reinterpret_i64(0x7ff8000000000000ull), -1.7976931348623157e+308)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, f64_reinterpret_i64(0x7ff4000000000000ull), -1.7976931348623157e+308)) & 9221120237041090560ull),
        9221120237041090560ull,
        "max(f64_reinterpret_i64(0x7ff4000000000000ull), -1.7976931348623157e+308)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, f64_reinterpret_i64(0x7ff8000000000000ull), 1.7976931348623157e+308)) & 9223372036854775807ull),
        9221120237041090560ull,
        "max(f64_reinterpret_i64(0x7ff8000000000000ull), 1.7976931348623157e+308)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, f64_reinterpret_i64(0x7ff4000000000000ull), 1.7976931348623157e+308)) & 9221120237041090560ull),
        9221120237041090560ull,
        "max(f64_reinterpret_i64(0x7ff4000000000000ull), 1.7976931348623157e+308)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, f64_reinterpret_i64(0xfff8000000000000ull), -INFINITY)) & 9223372036854775807ull),
        9221120237041090560ull,
        "max(f64_reinterpret_i64(0xfff8000000000000ull), -INFINITY)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, f64_reinterpret_i64(0xfff4000000000000ull), -INFINITY)) & 9221120237041090560ull),
        9221120237041090560ull,
        "max(f64_reinterpret_i64(0xfff4000000000000ull), -INFINITY)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, f64_reinterpret_i64(0xfff8000000000000ull), INFINITY)) & 9223372036854775807ull),
        9221120237041090560ull,
        "max(f64_reinterpret_i64(0xfff8000000000000ull), INFINITY)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, f64_reinterpret_i64(0xfff4000000000000ull), INFINITY)) & 9221120237041090560ull),
        9221120237041090560ull,
        "max(f64_reinterpret_i64(0xfff4000000000000ull), INFINITY)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, f64_reinterpret_i64(0x7ff8000000000000ull), -INFINITY)) & 9223372036854775807ull),
        9221120237041090560ull,
        "max(f64_reinterpret_i64(0x7ff8000000000000ull), -INFINITY)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, f64_reinterpret_i64(0x7ff4000000000000ull), -INFINITY)) & 9221120237041090560ull),
        9221120237041090560ull,
        "max(f64_reinterpret_i64(0x7ff4000000000000ull), -INFINITY)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, f64_reinterpret_i64(0x7ff8000000000000ull), INFINITY)) & 9223372036854775807ull),
        9221120237041090560ull,
        "max(f64_reinterpret_i64(0x7ff8000000000000ull), INFINITY)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, f64_reinterpret_i64(0x7ff4000000000000ull), INFINITY)) & 9221120237041090560ull),
        9221120237041090560ull,
        "max(f64_reinterpret_i64(0x7ff4000000000000ull), INFINITY)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, f64_reinterpret_i64(0xfff8000000000000ull), f64_reinterpret_i64(0xfff8000000000000ull))) & 9223372036854775807ull),
        9221120237041090560ull,
        "max(f64_reinterpret_i64(0xfff8000000000000ull), f64_reinterpret_i64(0xfff8000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, f64_reinterpret_i64(0xfff4000000000000ull), f64_reinterpret_i64(0xfff8000000000000ull))) & 9221120237041090560ull),
        9221120237041090560ull,
        "max(f64_reinterpret_i64(0xfff4000000000000ull), f64_reinterpret_i64(0xfff8000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, f64_reinterpret_i64(0xfff8000000000000ull), f64_reinterpret_i64(0xfff4000000000000ull))) & 9221120237041090560ull),
        9221120237041090560ull,
        "max(f64_reinterpret_i64(0xfff8000000000000ull), f64_reinterpret_i64(0xfff4000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, f64_reinterpret_i64(0xfff4000000000000ull), f64_reinterpret_i64(0xfff4000000000000ull))) & 9221120237041090560ull),
        9221120237041090560ull,
        "max(f64_reinterpret_i64(0xfff4000000000000ull), f64_reinterpret_i64(0xfff4000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, f64_reinterpret_i64(0xfff8000000000000ull), f64_reinterpret_i64(0x7ff8000000000000ull))) & 9223372036854775807ull),
        9221120237041090560ull,
        "max(f64_reinterpret_i64(0xfff8000000000000ull), f64_reinterpret_i64(0x7ff8000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, f64_reinterpret_i64(0xfff4000000000000ull), f64_reinterpret_i64(0x7ff8000000000000ull))) & 9221120237041090560ull),
        9221120237041090560ull,
        "max(f64_reinterpret_i64(0xfff4000000000000ull), f64_reinterpret_i64(0x7ff8000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, f64_reinterpret_i64(0xfff8000000000000ull), f64_reinterpret_i64(0x7ff4000000000000ull))) & 9221120237041090560ull),
        9221120237041090560ull,
        "max(f64_reinterpret_i64(0xfff8000000000000ull), f64_reinterpret_i64(0x7ff4000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, f64_reinterpret_i64(0xfff4000000000000ull), f64_reinterpret_i64(0x7ff4000000000000ull))) & 9221120237041090560ull),
        9221120237041090560ull,
        "max(f64_reinterpret_i64(0xfff4000000000000ull), f64_reinterpret_i64(0x7ff4000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, f64_reinterpret_i64(0x7ff8000000000000ull), f64_reinterpret_i64(0xfff8000000000000ull))) & 9223372036854775807ull),
        9221120237041090560ull,
        "max(f64_reinterpret_i64(0x7ff8000000000000ull), f64_reinterpret_i64(0xfff8000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, f64_reinterpret_i64(0x7ff4000000000000ull), f64_reinterpret_i64(0xfff8000000000000ull))) & 9221120237041090560ull),
        9221120237041090560ull,
        "max(f64_reinterpret_i64(0x7ff4000000000000ull), f64_reinterpret_i64(0xfff8000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, f64_reinterpret_i64(0x7ff8000000000000ull), f64_reinterpret_i64(0xfff4000000000000ull))) & 9221120237041090560ull),
        9221120237041090560ull,
        "max(f64_reinterpret_i64(0x7ff8000000000000ull), f64_reinterpret_i64(0xfff4000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, f64_reinterpret_i64(0x7ff4000000000000ull), f64_reinterpret_i64(0xfff4000000000000ull))) & 9221120237041090560ull),
        9221120237041090560ull,
        "max(f64_reinterpret_i64(0x7ff4000000000000ull), f64_reinterpret_i64(0xfff4000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, f64_reinterpret_i64(0x7ff8000000000000ull), f64_reinterpret_i64(0x7ff8000000000000ull))) & 9223372036854775807ull),
        9221120237041090560ull,
        "max(f64_reinterpret_i64(0x7ff8000000000000ull), f64_reinterpret_i64(0x7ff8000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, f64_reinterpret_i64(0x7ff4000000000000ull), f64_reinterpret_i64(0x7ff8000000000000ull))) & 9221120237041090560ull),
        9221120237041090560ull,
        "max(f64_reinterpret_i64(0x7ff4000000000000ull), f64_reinterpret_i64(0x7ff8000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, f64_reinterpret_i64(0x7ff8000000000000ull), f64_reinterpret_i64(0x7ff4000000000000ull))) & 9221120237041090560ull),
        9221120237041090560ull,
        "max(f64_reinterpret_i64(0x7ff8000000000000ull), f64_reinterpret_i64(0x7ff4000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export3_max(&instance, f64_reinterpret_i64(0x7ff4000000000000ull), f64_reinterpret_i64(0x7ff4000000000000ull))) & 9221120237041090560ull),
        9221120237041090560ull,
        "max(f64_reinterpret_i64(0x7ff4000000000000ull), f64_reinterpret_i64(0x7ff4000000000000ull))"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export4_sqrt(&instance, -0.0)),
        9223372036854775808ull,
        "sqrt(-0.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export4_sqrt(&instance, 0.0)),
        0ull,
        "sqrt(0.0)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export4_sqrt(&instance, -5e-324)) & 9223372036854775807ull),
        9221120237041090560ull,
        "sqrt(-5e-324)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export4_sqrt(&instance, 5e-324)),
        2188749418902061056ull,
        "sqrt(5e-324)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export4_sqrt(&instance, -2.2250738585072014e-308)) & 9223372036854775807ull),
        9221120237041090560ull,
        "sqrt(-2.2250738585072014e-308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export4_sqrt(&instance, 2.2250738585072014e-308)),
        2305843009213693952ull,
        "sqrt(2.2250738585072014e-308)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export4_sqrt(&instance, -0.5)) & 9223372036854775807ull),
        9221120237041090560ull,
        "sqrt(-0.5)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export4_sqrt(&instance, 0.5)),
        4604544271217802189ull,
        "sqrt(0.5)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export4_sqrt(&instance, -1.0)) & 9223372036854775807ull),
        9221120237041090560ull,
        "sqrt(-1.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export4_sqrt(&instance, 1.0)),
        4607182418800017408ull,
        "sqrt(1.0)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export4_sqrt(&instance, -6.283185307179586)) & 9223372036854775807ull),
        9221120237041090560ull,
        "sqrt(-6.283185307179586)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export4_sqrt(&instance, 6.283185307179586)),
        4612826843881809669ull,
        "sqrt(6.283185307179586)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export4_sqrt(&instance, -1.7976931348623157e+308)) & 9223372036854775807ull),
        9221120237041090560ull,
        "sqrt(-1.7976931348623157e+308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export4_sqrt(&instance, 1.7976931348623157e+308)),
        6913025428013711359ull,
        "sqrt(1.7976931348623157e+308)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export4_sqrt(&instance, -INFINITY)) & 9223372036854775807ull),
        9221120237041090560ull,
        "sqrt(-INFINITY)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export4_sqrt(&instance, INFINITY)),
        9218868437227405312ull,
        "sqrt(INFINITY)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export4_sqrt(&instance, f64_reinterpret_i64(0xfff8000000000000ull))) & 9223372036854775807ull),
        9221120237041090560ull,
        "sqrt(f64_reinterpret_i64(0xfff8000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export4_sqrt(&instance, f64_reinterpret_i64(0xfff4000000000000ull))) & 9221120237041090560ull),
        9221120237041090560ull,
        "sqrt(f64_reinterpret_i64(0xfff4000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export4_sqrt(&instance, f64_reinterpret_i64(0x7ff8000000000000ull))) & 9223372036854775807ull),
        9221120237041090560ull,
        "sqrt(f64_reinterpret_i64(0x7ff8000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export4_sqrt(&instance, f64_reinterpret_i64(0x7ff4000000000000ull))) & 9221120237041090560ull),
        9221120237041090560ull,
        "sqrt(f64_reinterpret_i64(0x7ff4000000000000ull))"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export5_floor(&instance, -0.0)),
        9223372036854775808ull,
        "floor(-0.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export5_floor(&instance, 0.0)),
        0ull,
        "floor(0.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export5_floor(&instance, -5e-324)),
        13830554455654793216ull,
        "floor(-5e-324)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export5_floor(&instance, 5e-324)),
        0ull,
        "floor(5e-324)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export5_floor(&instance, -2.2250738585072014e-308)),
        13830554455654793216ull,
        "floor(-2.2250738585072014e-308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export5_floor(&instance, 2.2250738585072014e-308)),
        0ull,
        "floor(2.2250738585072014e-308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export5_floor(&instance, -0.5)),
        13830554455654793216ull,
        "floor(-0.5)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export5_floor(&instance, 0.5)),
        0ull,
        "floor(0.5)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export5_floor(&instance, -1.0)),
        13830554455654793216ull,
        "floor(-1.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export5_floor(&instance, 1.0)),
        4607182418800017408ull,
        "floor(1.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export5_floor(&instance, -6.283185307179586)),
        13842939354630062080ull,
        "floor(-6.283185307179586)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export5_floor(&instance, 6.283185307179586)),
        4618441417868443648ull,
        "floor(6.283185307179586)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export5_floor(&instance, -1.7976931348623157e+308)),
        18442240474082181119ull,
        "floor(-1.7976931348623157e+308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export5_floor(&instance, 1.7976931348623157e+308)),
        9218868437227405311ull,
        "floor(1.7976931348623157e+308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export5_floor(&instance, -INFINITY)),
        18442240474082181120ull,
        "floor(-INFINITY)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export5_floor(&instance, INFINITY)),
        9218868437227405312ull,
        "floor(INFINITY)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export5_floor(&instance, f64_reinterpret_i64(0xfff8000000000000ull))) & 9223372036854775807ull),
        9221120237041090560ull,
        "floor(f64_reinterpret_i64(0xfff8000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export5_floor(&instance, f64_reinterpret_i64(0xfff4000000000000ull))) & 9221120237041090560ull),
        9221120237041090560ull,
        "floor(f64_reinterpret_i64(0xfff4000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export5_floor(&instance, f64_reinterpret_i64(0x7ff8000000000000ull))) & 9223372036854775807ull),
        9221120237041090560ull,
        "floor(f64_reinterpret_i64(0x7ff8000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export5_floor(&instance, f64_reinterpret_i64(0x7ff4000000000000ull))) & 9221120237041090560ull),
        9221120237041090560ull,
        "floor(f64_reinterpret_i64(0x7ff4000000000000ull))"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export4_ceil(&instance, -0.0)),
        9223372036854775808ull,
        "ceil(-0.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export4_ceil(&instance, 0.0)),
        0ull,
        "ceil(0.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export4_ceil(&instance, -5e-324)),
        9223372036854775808ull,
        "ceil(-5e-324)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export4_ceil(&instance, 5e-324)),
        4607182418800017408ull,
        "ceil(5e-324)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export4_ceil(&instance, -2.2250738585072014e-308)),
        9223372036854775808ull,
        "ceil(-2.2250738585072014e-308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export4_ceil(&instance, 2.2250738585072014e-308)),
        4607182418800017408ull,
        "ceil(2.2250738585072014e-308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export4_ceil(&instance, -0.5)),
        9223372036854775808ull,
        "ceil(-0.5)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export4_ceil(&instance, 0.5)),
        4607182418800017408ull,
        "ceil(0.5)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export4_ceil(&instance, -1.0)),
        13830554455654793216ull,
        "ceil(-1.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export4_ceil(&instance, 1.0)),
        4607182418800017408ull,
        "ceil(1.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export4_ceil(&instance, -6.283185307179586)),
        13841813454723219456ull,
        "ceil(-6.283185307179586)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export4_ceil(&instance, 6.283185307179586)),
        4619567317775286272ull,
        "ceil(6.283185307179586)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export4_ceil(&instance, -1.7976931348623157e+308)),
        18442240474082181119ull,
        "ceil(-1.7976931348623157e+308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export4_ceil(&instance, 1.7976931348623157e+308)),
        9218868437227405311ull,
        "ceil(1.7976931348623157e+308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export4_ceil(&instance, -INFINITY)),
        18442240474082181120ull,
        "ceil(-INFINITY)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export4_ceil(&instance, INFINITY)),
        9218868437227405312ull,
        "ceil(INFINITY)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export4_ceil(&instance, f64_reinterpret_i64(0xfff8000000000000ull))) & 9223372036854775807ull),
        9221120237041090560ull,
        "ceil(f64_reinterpret_i64(0xfff8000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export4_ceil(&instance, f64_reinterpret_i64(0xfff4000000000000ull))) & 9221120237041090560ull),
        9221120237041090560ull,
        "ceil(f64_reinterpret_i64(0xfff4000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export4_ceil(&instance, f64_reinterpret_i64(0x7ff8000000000000ull))) & 9223372036854775807ull),
        9221120237041090560ull,
        "ceil(f64_reinterpret_i64(0x7ff8000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export4_ceil(&instance, f64_reinterpret_i64(0x7ff4000000000000ull))) & 9221120237041090560ull),
        9221120237041090560ull,
        "ceil(f64_reinterpret_i64(0x7ff4000000000000ull))"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export5_trunc(&instance, -0.0)),
        9223372036854775808ull,
        "trunc(-0.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export5_trunc(&instance, 0.0)),
        0ull,
        "trunc(0.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export5_trunc(&instance, -5e-324)),
        9223372036854775808ull,
        "trunc(-5e-324)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export5_trunc(&instance, 5e-324)),
        0ull,
        "trunc(5e-324)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export5_trunc(&instance, -2.2250738585072014e-308)),
        9223372036854775808ull,
        "trunc(-2.2250738585072014e-308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export5_trunc(&instance, 2.2250738585072014e-308)),
        0ull,
        "trunc(2.2250738585072014e-308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export5_trunc(&instance, -0.5)),
        9223372036854775808ull,
        "trunc(-0.5)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export5_trunc(&instance, 0.5)),
        0ull,
        "trunc(0.5)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export5_trunc(&instance, -1.0)),
        13830554455654793216ull,
        "trunc(-1.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export5_trunc(&instance, 1.0)),
        4607182418800017408ull,
        "trunc(1.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export5_trunc(&instance, -6.283185307179586)),
        13841813454723219456ull,
        "trunc(-6.283185307179586)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export5_trunc(&instance, 6.283185307179586)),
        4618441417868443648ull,
        "trunc(6.283185307179586)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export5_trunc(&instance, -1.7976931348623157e+308)),
        18442240474082181119ull,
        "trunc(-1.7976931348623157e+308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export5_trunc(&instance, 1.7976931348623157e+308)),
        9218868437227405311ull,
        "trunc(1.7976931348623157e+308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export5_trunc(&instance, -INFINITY)),
        18442240474082181120ull,
        "trunc(-INFINITY)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export5_trunc(&instance, INFINITY)),
        9218868437227405312ull,
        "trunc(INFINITY)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export5_trunc(&instance, f64_reinterpret_i64(0xfff8000000000000ull))) & 9223372036854775807ull),
        9221120237041090560ull,
        "trunc(f64_reinterpret_i64(0xfff8000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export5_trunc(&instance, f64_reinterpret_i64(0xfff4000000000000ull))) & 9221120237041090560ull),
        9221120237041090560ull,
        "trunc(f64_reinterpret_i64(0xfff4000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export5_trunc(&instance, f64_reinterpret_i64(0x7ff8000000000000ull))) & 9223372036854775807ull),
        9221120237041090560ull,
        "trunc(f64_reinterpret_i64(0x7ff8000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export5_trunc(&instance, f64_reinterpret_i64(0x7ff4000000000000ull))) & 9221120237041090560ull),
        9221120237041090560ull,
        "trunc(f64_reinterpret_i64(0x7ff4000000000000ull))"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export7_nearest(&instance, -0.0)),
        9223372036854775808ull,
        "nearest(-0.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export7_nearest(&instance, 0.0)),
        0ull,
        "nearest(0.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export7_nearest(&instance, -5e-324)),
        9223372036854775808ull,
        "nearest(-5e-324)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export7_nearest(&instance, 5e-324)),
        0ull,
        "nearest(5e-324)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export7_nearest(&instance, -2.2250738585072014e-308)),
        9223372036854775808ull,
        "nearest(-2.2250738585072014e-308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export7_nearest(&instance, 2.2250738585072014e-308)),
        0ull,
        "nearest(2.2250738585072014e-308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export7_nearest(&instance, -0.5)),
        9223372036854775808ull,
        "nearest(-0.5)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export7_nearest(&instance, 0.5)),
        0ull,
        "nearest(0.5)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export7_nearest(&instance, -1.0)),
        13830554455654793216ull,
        "nearest(-1.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export7_nearest(&instance, 1.0)),
        4607182418800017408ull,
        "nearest(1.0)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export7_nearest(&instance, -6.283185307179586)),
        13841813454723219456ull,
        "nearest(-6.283185307179586)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export7_nearest(&instance, 6.283185307179586)),
        4618441417868443648ull,
        "nearest(6.283185307179586)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export7_nearest(&instance, -1.7976931348623157e+308)),
        18442240474082181119ull,
        "nearest(-1.7976931348623157e+308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export7_nearest(&instance, 1.7976931348623157e+308)),
        9218868437227405311ull,
        "nearest(1.7976931348623157e+308)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export7_nearest(&instance, -INFINITY)),
        18442240474082181120ull,
        "nearest(-INFINITY)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m5_f64X2E0Export7_nearest(&instance, INFINITY)),
        9218868437227405312ull,
        "nearest(INFINITY)"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export7_nearest(&instance, f64_reinterpret_i64(0xfff8000000000000ull))) & 9223372036854775807ull),
        9221120237041090560ull,
        "nearest(f64_reinterpret_i64(0xfff8000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export7_nearest(&instance, f64_reinterpret_i64(0xfff4000000000000ull))) & 9221120237041090560ull),
        9221120237041090560ull,
        "nearest(f64_reinterpret_i64(0xfff4000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export7_nearest(&instance, f64_reinterpret_i64(0x7ff8000000000000ull))) & 9223372036854775807ull),
        9221120237041090560ull,
        "nearest(f64_reinterpret_i64(0x7ff8000000000000ull))"
    );
    assertEqualU64(
        (i64_reinterpret_f64(m5_f64X2E0Export7_nearest(&instance, f64_reinterpret_i64(0x7ff4000000000000ull))) & 9221120237041090560ull),
        9221120237041090560ull,
        "nearest(f64_reinterpret_i64(0x7ff4000000000000ull))"
    );
}
