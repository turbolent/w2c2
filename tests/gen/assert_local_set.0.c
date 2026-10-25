
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_local_set.0.h"

void test() {
    m11_localX5FsetX2E0Instance instance;
    m11_localX5FsetX2E0Instantiate(&instance, resolveTestImports);
    printStart("local_set.0.wasm");
    m11_localX5FsetX2E0Export14_typeX2DlocalX2Di32(&instance);
    m11_localX5FsetX2E0Export14_typeX2DlocalX2Di64(&instance);
    m11_localX5FsetX2E0Export14_typeX2DlocalX2Df32(&instance);
    m11_localX5FsetX2E0Export14_typeX2DlocalX2Df64(&instance);
    m11_localX5FsetX2E0Export14_typeX2DparamX2Di32(&instance, 2u);
    m11_localX5FsetX2E0Export14_typeX2DparamX2Di64(&instance, 3ull);
    m11_localX5FsetX2E0Export14_typeX2DparamX2Df32(&instance, 4.400000095367432);
    m11_localX5FsetX2E0Export14_typeX2DparamX2Df64(&instance, 5.5);
    m11_localX5FsetX2E0Export14_asX2DblockX2Dvalue(&instance, 0u);
    m11_localX5FsetX2E0Export13_asX2DloopX2Dvalue(&instance, 0u);
    m11_localX5FsetX2E0Export11_asX2DbrX2Dvalue(&instance, 0u);
    m11_localX5FsetX2E0Export14_asX2DbrX5FifX2Dvalue(&instance, 0u);
    m11_localX5FsetX2E0Export19_asX2DbrX5FifX2DvalueX2Dcond(&instance, 0u);
    m11_localX5FsetX2E0Export17_asX2DbrX5FtableX2Dvalue(&instance, 0u);
    m11_localX5FsetX2E0Export15_asX2DreturnX2Dvalue(&instance, 0u);
    m11_localX5FsetX2E0Export10_asX2DifX2Dthen(&instance, 1u);
    m11_localX5FsetX2E0Export10_asX2DifX2Delse(&instance, 0u);
    m11_localX5FsetX2E0Export10_typeX2Dmixed(&instance, 1ull, 2.200000047683716, 3.3, 4u, 5u);
    assertEqualU64(
        m11_localX5FsetX2E0Export5_write(&instance, 1ull, 2.0, 3.3, 4u, 5u),
        56ull,
        "write(1ull, 2.0, 3.3, 4u, 5u)"
    );
}
