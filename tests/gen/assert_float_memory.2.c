
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_float_memory.2.h"

void test() {
    floatmemory2Instance instance;
    floatmemory2Instantiate(&instance, resolveTestImports);
    printStart("float_memory.2.wasm");
    assertEqualU32(
        floatmemory2_i32X2Eload(&instance),
        2141192192u,
        "i32.load()"
    );
    floatmemory2_reset(&instance);
    printOK("reset()");
    assertEqualU32(
        floatmemory2_i32X2Eload(&instance),
        0u,
        "i32.load()"
    );
    assertEqualF32(
        floatmemory2_f32X2Eload(&instance),
        0.0,
        "f32.load()"
    );
    floatmemory2_f32X2Estore(&instance);
    printOK("f32.store()");
    assertEqualU32(
        floatmemory2_i32X2Eload(&instance),
        2141192192u,
        "i32.load()"
    );
    floatmemory2_reset(&instance);
    printOK("reset()");
    assertEqualU32(
        floatmemory2_i32X2Eload(&instance),
        0u,
        "i32.load()"
    );
    assertEqualF32(
        floatmemory2_f32X2Eload(&instance),
        0.0,
        "f32.load()"
    );
    floatmemory2_i32X2Estore(&instance);
    printOK("i32.store()");
    assertEqualU32(
        floatmemory2_i32X2Eload(&instance),
        2141192192u,
        "i32.load()"
    );
}
