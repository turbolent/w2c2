
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_float_memory.0.h"

void test() {
    floatmemory0Instance instance;
    floatmemory0Instantiate(&instance, resolveTestImports);
    printStart("float_memory.0.wasm");
    assertEqualU32(
        floatmemory0_i32X2Eload(&instance),
        2141192192u,
        "i32.load()"
    );
    floatmemory0_reset(&instance);
    printOK("reset()");
    assertEqualU32(
        floatmemory0_i32X2Eload(&instance),
        0u,
        "i32.load()"
    );
    assertEqualF32(
        floatmemory0_f32X2Eload(&instance),
        0.0,
        "f32.load()"
    );
    floatmemory0_f32X2Estore(&instance);
    printOK("f32.store()");
    assertEqualU32(
        floatmemory0_i32X2Eload(&instance),
        2141192192u,
        "i32.load()"
    );
    floatmemory0_reset(&instance);
    printOK("reset()");
    assertEqualU32(
        floatmemory0_i32X2Eload(&instance),
        0u,
        "i32.load()"
    );
    assertEqualF32(
        floatmemory0_f32X2Eload(&instance),
        0.0,
        "f32.load()"
    );
    floatmemory0_i32X2Estore(&instance);
    printOK("i32.store()");
    assertEqualU32(
        floatmemory0_i32X2Eload(&instance),
        2141192192u,
        "i32.load()"
    );
}
