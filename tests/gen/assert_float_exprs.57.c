
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_float_exprs.57.h"

void test() {
    floatexprs57Instance instance;
    floatexprs57Instantiate(&instance, resolveTestImports);
    printStart("float_exprs.57.wasm");
    assertEqualF32(
        floatexprs57_f32X2Eno_algebraic_factoring(&instance, -5.371186465411003e-17, 9.744327905706555e-17),
        -6.610228647323988e-33,
        "f32.no_algebraic_factoring(-5.371186465411003e-17, 9.744327905706555e-17)"
    );
    assertEqualF32(
        floatexprs57_f32X2Eno_algebraic_factoring(&instance, -19756732.0, 32770204.0),
        -683557802475520.0,
        "f32.no_algebraic_factoring(-19756732.0, 32770204.0)"
    );
    assertEqualF32(
        floatexprs57_f32X2Eno_algebraic_factoring(&instance, 52314148700160.0, -145309984358400.0),
        -1.8378221355451492e+28,
        "f32.no_algebraic_factoring(52314148700160.0, -145309984358400.0)"
    );
    assertEqualF32(
        floatexprs57_f32X2Eno_algebraic_factoring(&instance, 195260.375, -227.75723266601562),
        38126563328.0,
        "f32.no_algebraic_factoring(195260.375, -227.75723266601562)"
    );
    assertEqualF32(
        floatexprs57_f32X2Eno_algebraic_factoring(&instance, -237.487060546875, -972341.5),
        -945447960576.0,
        "f32.no_algebraic_factoring(-237.487060546875, -972341.5)"
    );
    assertEqualF64(
        floatexprs57_f64X2Eno_algebraic_factoring(&instance, 9.639720335949767e-144, 8.019175443606207e-140),
        -6.430717386609473e-279,
        "f64.no_algebraic_factoring(9.639720335949767e-144, 8.019175443606207e-140)"
    );
    assertEqualF64(
        floatexprs57_f64X2Eno_algebraic_factoring(&instance, 5.166066590392027e-114, 1.494333315888213e-120),
        2.6688244016362468e-227,
        "f64.no_algebraic_factoring(5.166066590392027e-114, 1.494333315888213e-120)"
    );
    assertEqualF64(
        floatexprs57_f64X2Eno_algebraic_factoring(&instance, -2.866135870517635e-114, -1.2114355254268516e-111),
        -1.4675678175314036e-222,
        "f64.no_algebraic_factoring(-2.866135870517635e-114, -1.2114355254268516e-111)"
    );
    assertEqualF64(
        floatexprs57_f64X2Eno_algebraic_factoring(&instance, -1.2920992810078149e+54, 6.62717187728034e+56),
        -4.391924013896023e+113,
        "f64.no_algebraic_factoring(-1.2920992810078149e+54, 6.62717187728034e+56)"
    );
    assertEqualF64(
        floatexprs57_f64X2Eno_algebraic_factoring(&instance, 2.624279568901057e+34, -1.6250233986050802e+27),
        6.886843255751491e+68,
        "f64.no_algebraic_factoring(2.624279568901057e+34, -1.6250233986050802e+27)"
    );
}
