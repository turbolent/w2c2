
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_local_get.0.h"

void test() {
    m11_localX5FgetX2E0Instance instance;
    m11_localX5FgetX2E0Instantiate(&instance, resolveTestImports);
    printStart("local_get.0.wasm");
    assertEqualU32(
        m11_localX5FgetX2E0Export14_typeX2DlocalX2Di32(&instance),
        0u,
        "type-local-i32()"
    );
    assertEqualU64(
        m11_localX5FgetX2E0Export14_typeX2DlocalX2Di64(&instance),
        0ull,
        "type-local-i64()"
    );
    assertEqualF32(
        m11_localX5FgetX2E0Export14_typeX2DlocalX2Df32(&instance),
        0.0,
        "type-local-f32()"
    );
    assertEqualF64(
        m11_localX5FgetX2E0Export14_typeX2DlocalX2Df64(&instance),
        0.0,
        "type-local-f64()"
    );
    assertEqualU32(
        m11_localX5FgetX2E0Export14_typeX2DparamX2Di32(&instance, 2u),
        2u,
        "type-param-i32(2u)"
    );
    assertEqualU64(
        m11_localX5FgetX2E0Export14_typeX2DparamX2Di64(&instance, 3ull),
        3ull,
        "type-param-i64(3ull)"
    );
    assertEqualF32(
        m11_localX5FgetX2E0Export14_typeX2DparamX2Df32(&instance, 4.400000095367432),
        4.400000095367432,
        "type-param-f32(4.400000095367432)"
    );
    assertEqualF64(
        m11_localX5FgetX2E0Export14_typeX2DparamX2Df64(&instance, 5.5),
        5.5,
        "type-param-f64(5.5)"
    );
    assertEqualU32(
        m11_localX5FgetX2E0Export14_asX2DblockX2Dvalue(&instance, 6u),
        6u,
        "as-block-value(6u)"
    );
    assertEqualU32(
        m11_localX5FgetX2E0Export13_asX2DloopX2Dvalue(&instance, 7u),
        7u,
        "as-loop-value(7u)"
    );
    assertEqualU32(
        m11_localX5FgetX2E0Export11_asX2DbrX2Dvalue(&instance, 8u),
        8u,
        "as-br-value(8u)"
    );
    assertEqualU32(
        m11_localX5FgetX2E0Export14_asX2DbrX5FifX2Dvalue(&instance, 9u),
        9u,
        "as-br_if-value(9u)"
    );
    assertEqualU32(
        m11_localX5FgetX2E0Export19_asX2DbrX5FifX2DvalueX2Dcond(&instance, 10u),
        10u,
        "as-br_if-value-cond(10u)"
    );
    assertEqualU32(
        m11_localX5FgetX2E0Export17_asX2DbrX5FtableX2Dvalue(&instance, 1u),
        2u,
        "as-br_table-value(1u)"
    );
    assertEqualU32(
        m11_localX5FgetX2E0Export15_asX2DreturnX2Dvalue(&instance, 0u),
        0u,
        "as-return-value(0u)"
    );
    assertEqualU32(
        m11_localX5FgetX2E0Export10_asX2DifX2Dthen(&instance, 1u),
        1u,
        "as-if-then(1u)"
    );
    assertEqualU32(
        m11_localX5FgetX2E0Export10_asX2DifX2Delse(&instance, 0u),
        0u,
        "as-if-else(0u)"
    );
    m11_localX5FgetX2E0Export10_typeX2Dmixed(&instance, 1ull, 2.200000047683716, 3.3, 4u, 5u);
    assertEqualF64(
        m11_localX5FgetX2E0Export4_read(&instance, 1ull, 2.0, 3.3, 4u, 5u),
        34.8,
        "read(1ull, 2.0, 3.3, 4u, 5u)"
    );
}
