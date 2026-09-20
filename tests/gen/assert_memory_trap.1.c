
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_memory_trap.1.h"

void test() {
    m13_memoryX5FtrapX2E1Instance instance;
    m13_memoryX5FtrapX2E1Instantiate(&instance, resolveTestImports);
    printStart("memory_trap.1.wasm");
    assertEqualU64(
        m13_memoryX5FtrapX2E1Export8_i64X2Eload(&instance, 65528u),
        7523094288207667809ull,
        "i64.load(65528u)"
    );
    assertEqualU64(
        m13_memoryX5FtrapX2E1Export8_i64X2Eload(&instance, 0u),
        7523094288207667809ull,
        "i64.load(0u)"
    );
    m13_memoryX5FtrapX2E1Export9_i64X2Estore(&instance, 65528u, 0ull);
    assertEqualU32(
        m13_memoryX5FtrapX2E1Export8_i32X2Eload(&instance, 65532u),
        0u,
        "i32.load(65532u)"
    );
    assertEqualU64(
        m13_memoryX5FtrapX2E1Export8_i64X2Eload(&instance, 65528u),
        0ull,
        "i64.load(65528u)"
    );
    assertEqualF32(
        m13_memoryX5FtrapX2E1Export8_f32X2Eload(&instance, 65532u),
        0.0,
        "f32.load(65532u)"
    );
    assertEqualF64(
        m13_memoryX5FtrapX2E1Export8_f64X2Eload(&instance, 65528u),
        0.0,
        "f64.load(65528u)"
    );
}
