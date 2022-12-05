
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_float_memory.5.h"

void test() {
    floatmemory5Instance instance;
    floatmemory5Instantiate(&instance, resolveTestImports);
    printStart("float_memory.5.wasm");
    assertEqualU64(
        floatmemory5_i64X2Eload(&instance),
        9222246136947933185ull,
        "i64.load()"
    );
    floatmemory5_reset(&instance);
    printOK("reset()");
    assertEqualU64(
        floatmemory5_i64X2Eload(&instance),
        0ull,
        "i64.load()"
    );
    assertEqualF64(
        floatmemory5_f64X2Eload(&instance),
        0.0,
        "f64.load()"
    );
    floatmemory5_f64X2Estore(&instance);
    printOK("f64.store()");
    assertEqualU64(
        floatmemory5_i64X2Eload(&instance),
        9222246136947933185ull,
        "i64.load()"
    );
    floatmemory5_reset(&instance);
    printOK("reset()");
    assertEqualU64(
        floatmemory5_i64X2Eload(&instance),
        0ull,
        "i64.load()"
    );
    assertEqualF64(
        floatmemory5_f64X2Eload(&instance),
        0.0,
        "f64.load()"
    );
    floatmemory5_i64X2Estore(&instance);
    printOK("i64.store()");
    assertEqualU64(
        floatmemory5_i64X2Eload(&instance),
        9222246136947933185ull,
        "i64.load()"
    );
}
