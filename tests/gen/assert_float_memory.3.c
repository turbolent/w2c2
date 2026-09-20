
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_float_memory.3.h"

void test() {
    m14_floatX5FmemoryX2E3Instance instance;
    m14_floatX5FmemoryX2E3Instantiate(&instance, resolveTestImports);
    printStart("float_memory.3.wasm");
    assertEqualU64(
        m14_floatX5FmemoryX2E3Export8_i64X2Eload(&instance),
        9219994337134247936ull,
        "i64.load()"
    );
    m14_floatX5FmemoryX2E3Export5_reset(&instance);
    printOK("reset()");
    assertEqualU64(
        m14_floatX5FmemoryX2E3Export8_i64X2Eload(&instance),
        0ull,
        "i64.load()"
    );
    assertEqualF64(
        m14_floatX5FmemoryX2E3Export8_f64X2Eload(&instance),
        0.0,
        "f64.load()"
    );
    m14_floatX5FmemoryX2E3Export9_f64X2Estore(&instance);
    printOK("f64.store()");
    m14_floatX5FmemoryX2E3Export5_reset(&instance);
    printOK("reset()");
    assertEqualU64(
        m14_floatX5FmemoryX2E3Export8_i64X2Eload(&instance),
        0ull,
        "i64.load()"
    );
    assertEqualF64(
        m14_floatX5FmemoryX2E3Export8_f64X2Eload(&instance),
        0.0,
        "f64.load()"
    );
    m14_floatX5FmemoryX2E3Export9_i64X2Estore(&instance);
    printOK("i64.store()");
    assertEqualU64(
        m14_floatX5FmemoryX2E3Export8_i64X2Eload(&instance),
        9219994337134247936ull,
        "i64.load()"
    );
}
