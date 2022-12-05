
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_float_memory.3.h"

void test() {
    floatmemory3Instance instance;
    floatmemory3Instantiate(&instance, resolveTestImports);
    printStart("float_memory.3.wasm");
    assertEqualU64(
        floatmemory3_i64X2Eload(&instance),
        9219994337134247936ull,
        "i64.load()"
    );
    floatmemory3_reset(&instance);
    printOK("reset()");
    assertEqualU64(
        floatmemory3_i64X2Eload(&instance),
        0ull,
        "i64.load()"
    );
    assertEqualF64(
        floatmemory3_f64X2Eload(&instance),
        0.0,
        "f64.load()"
    );
    floatmemory3_f64X2Estore(&instance);
    printOK("f64.store()");
    floatmemory3_reset(&instance);
    printOK("reset()");
    assertEqualU64(
        floatmemory3_i64X2Eload(&instance),
        0ull,
        "i64.load()"
    );
    assertEqualF64(
        floatmemory3_f64X2Eload(&instance),
        0.0,
        "f64.load()"
    );
    floatmemory3_i64X2Estore(&instance);
    printOK("i64.store()");
    assertEqualU64(
        floatmemory3_i64X2Eload(&instance),
        9219994337134247936ull,
        "i64.load()"
    );
}
