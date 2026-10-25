
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_float_memory.4.h"

void test() {
    m14_floatX5FmemoryX2E4Instance instance;
    m14_floatX5FmemoryX2E4Instantiate(&instance, resolveTestImports);
    printStart("float_memory.4.wasm");
    assertEqualU32(
        m14_floatX5FmemoryX2E4Export8_i32X2Eload(&instance),
        2144337921u,
        "i32.load()"
    );
    assertEqualU32(
        i32_reinterpret_f32(m14_floatX5FmemoryX2E4Export8_f32X2Eload(&instance)),
        2144337921u,
        "f32.load()"
    );
    m14_floatX5FmemoryX2E4Export5_reset(&instance);
    printOK("reset()");
    assertEqualU32(
        m14_floatX5FmemoryX2E4Export8_i32X2Eload(&instance),
        0u,
        "i32.load()"
    );
    assertEqualU32(
        i32_reinterpret_f32(m14_floatX5FmemoryX2E4Export8_f32X2Eload(&instance)),
        0u,
        "f32.load()"
    );
    m14_floatX5FmemoryX2E4Export9_f32X2Estore(&instance);
    printOK("f32.store()");
    assertEqualU32(
        m14_floatX5FmemoryX2E4Export8_i32X2Eload(&instance),
        2144337921u,
        "i32.load()"
    );
    assertEqualU32(
        i32_reinterpret_f32(m14_floatX5FmemoryX2E4Export8_f32X2Eload(&instance)),
        2144337921u,
        "f32.load()"
    );
    m14_floatX5FmemoryX2E4Export5_reset(&instance);
    printOK("reset()");
    assertEqualU32(
        m14_floatX5FmemoryX2E4Export8_i32X2Eload(&instance),
        0u,
        "i32.load()"
    );
    assertEqualU32(
        i32_reinterpret_f32(m14_floatX5FmemoryX2E4Export8_f32X2Eload(&instance)),
        0u,
        "f32.load()"
    );
    m14_floatX5FmemoryX2E4Export9_i32X2Estore(&instance);
    printOK("i32.store()");
    assertEqualU32(
        m14_floatX5FmemoryX2E4Export8_i32X2Eload(&instance),
        2144337921u,
        "i32.load()"
    );
    assertEqualU32(
        i32_reinterpret_f32(m14_floatX5FmemoryX2E4Export8_f32X2Eload(&instance)),
        2144337921u,
        "f32.load()"
    );
}
