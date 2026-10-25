
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_float_memory.0.h"

void test() {
    m14_floatX5FmemoryX2E0Instance instance;
    m14_floatX5FmemoryX2E0Instantiate(&instance, resolveTestImports);
    printStart("float_memory.0.wasm");
    assertEqualU32(
        m14_floatX5FmemoryX2E0Export8_i32X2Eload(&instance),
        2141192192u,
        "i32.load()"
    );
    assertEqualU32(
        i32_reinterpret_f32(m14_floatX5FmemoryX2E0Export8_f32X2Eload(&instance)),
        2141192192u,
        "f32.load()"
    );
    m14_floatX5FmemoryX2E0Export5_reset(&instance);
    printOK("reset()");
    assertEqualU32(
        m14_floatX5FmemoryX2E0Export8_i32X2Eload(&instance),
        0u,
        "i32.load()"
    );
    assertEqualU32(
        i32_reinterpret_f32(m14_floatX5FmemoryX2E0Export8_f32X2Eload(&instance)),
        0u,
        "f32.load()"
    );
    m14_floatX5FmemoryX2E0Export9_f32X2Estore(&instance);
    printOK("f32.store()");
    assertEqualU32(
        m14_floatX5FmemoryX2E0Export8_i32X2Eload(&instance),
        2141192192u,
        "i32.load()"
    );
    assertEqualU32(
        i32_reinterpret_f32(m14_floatX5FmemoryX2E0Export8_f32X2Eload(&instance)),
        2141192192u,
        "f32.load()"
    );
    m14_floatX5FmemoryX2E0Export5_reset(&instance);
    printOK("reset()");
    assertEqualU32(
        m14_floatX5FmemoryX2E0Export8_i32X2Eload(&instance),
        0u,
        "i32.load()"
    );
    assertEqualU32(
        i32_reinterpret_f32(m14_floatX5FmemoryX2E0Export8_f32X2Eload(&instance)),
        0u,
        "f32.load()"
    );
    m14_floatX5FmemoryX2E0Export9_i32X2Estore(&instance);
    printOK("i32.store()");
    assertEqualU32(
        m14_floatX5FmemoryX2E0Export8_i32X2Eload(&instance),
        2141192192u,
        "i32.load()"
    );
    assertEqualU32(
        i32_reinterpret_f32(m14_floatX5FmemoryX2E0Export8_f32X2Eload(&instance)),
        2141192192u,
        "f32.load()"
    );
}
