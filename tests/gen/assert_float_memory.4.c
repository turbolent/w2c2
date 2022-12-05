
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_float_memory.4.h"

void test() {
    floatmemory4Instance instance;
    floatmemory4Instantiate(&instance, resolveTestImports);
    printStart("float_memory.4.wasm");
    assertEqualU32(
        floatmemory4_i32X2Eload(&instance),
        2144337921u,
        "i32.load()"
    );
    floatmemory4_reset(&instance);
    printOK("reset()");
    assertEqualU32(
        floatmemory4_i32X2Eload(&instance),
        0u,
        "i32.load()"
    );
    assertEqualF32(
        floatmemory4_f32X2Eload(&instance),
        0.0,
        "f32.load()"
    );
    floatmemory4_f32X2Estore(&instance);
    printOK("f32.store()");
    assertEqualU32(
        floatmemory4_i32X2Eload(&instance),
        2144337921u,
        "i32.load()"
    );
    floatmemory4_reset(&instance);
    printOK("reset()");
    assertEqualU32(
        floatmemory4_i32X2Eload(&instance),
        0u,
        "i32.load()"
    );
    assertEqualF32(
        floatmemory4_f32X2Eload(&instance),
        0.0,
        "f32.load()"
    );
    floatmemory4_i32X2Estore(&instance);
    printOK("i32.store()");
    assertEqualU32(
        floatmemory4_i32X2Eload(&instance),
        2144337921u,
        "i32.load()"
    );
}
