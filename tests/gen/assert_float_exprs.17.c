
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_float_exprs.17.h"

void test() {
    m14_floatX5FexprsX2E17Instance instance;
    m14_floatX5FexprsX2E17Instantiate(&instance, resolveTestImports);
    printStart("float_exprs.17.wasm");
    assertEqualU32(
        i32_reinterpret_f32(m14_floatX5FexprsX2E17Export13_f32X2EnoX5Ffactor(&instance, -1435111653376.0, -853617636540416.0, 1.1138493281216758e+18)),
        4131116008u,
        "f32.no_factor(-1435111653376.0, -853617636540416.0, 1.1138493281216758e+18)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m14_floatX5FexprsX2E17Export13_f32X2EnoX5Ffactor(&instance, -0.026666631922125816, 0.04841282218694687, -0.0028136970940977335)),
        3095417249u,
        "f32.no_factor(-0.026666631922125816, 0.04841282218694687, -0.0028136970940977335)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m14_floatX5FexprsX2E17Export13_f32X2EnoX5Ffactor(&instance, -4.661977726604094e-13, 1.0478376971705394e-19, 1.4469202269317853e+37)),
        3904015703u,
        "f32.no_factor(-4.661977726604094e-13, 1.0478376971705394e-19, 1.4469202269317853e+37)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m14_floatX5FexprsX2E17Export13_f32X2EnoX5Ffactor(&instance, -1.0689046302790726e-19, 1.0694433217685706e-25, 5.683070165258062e+35)),
        3679965352u,
        "f32.no_factor(-1.0689046302790726e-19, 1.0694433217685706e-25, 5.683070165258062e+35)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m14_floatX5FexprsX2E17Export13_f32X2EnoX5Ffactor(&instance, -6.354599380381072e-26, 7.524624844008798e-22, 1626770.25)),
        649094375u,
        "f32.no_factor(-6.354599380381072e-26, 7.524624844008798e-22, 1626770.25)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m14_floatX5FexprsX2E17Export13_f64X2EnoX5Ffactor(&instance, 2.8390554709988774e-128, 1.473981250649641e-139, -2.9001229846550766e-68)),
        10911876679403600666ull,
        "f64.no_factor(2.8390554709988774e-128, 1.473981250649641e-139, -2.9001229846550766e-68)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m14_floatX5FexprsX2E17Export13_f64X2EnoX5Ffactor(&instance, 6.461015505916123e-200, -2.3923242802975938e-304, -1.5300738798561604e-288)),
        0ull,
        "f64.no_factor(6.461015505916123e-200, -2.3923242802975938e-304, -1.5300738798561604e-288)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m14_floatX5FexprsX2E17Export13_f64X2EnoX5Ffactor(&instance, -2.939056292080733e-101, -2.146156743463356e-85, -2.5109672231302416e+144)),
        5500432744005058080ull,
        "f64.no_factor(-2.939056292080733e-101, -2.146156743463356e-85, -2.5109672231302416e+144)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m14_floatX5FexprsX2E17Export13_f64X2EnoX5Ffactor(&instance, -1.7785466771708878e-87, 9.328516775403213e-79, -1.2121009044876735e-76)),
        11527035460272583044ull,
        "f64.no_factor(-1.7785466771708878e-87, 9.328516775403213e-79, -1.2121009044876735e-76)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m14_floatX5FexprsX2E17Export13_f64X2EnoX5Ffactor(&instance, 1.5194859063177362e-183, 8.83589921438065e-175, -1.7358300194691958e+147)),
        13429277897969282899ull,
        "f64.no_factor(1.5194859063177362e-183, 8.83589921438065e-175, -1.7358300194691958e+147)"
    );
}
