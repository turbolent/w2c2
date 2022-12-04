
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_local_set.0.h"

void test() {
    localset0Instance instance;
    localset0Instantiate(&instance, resolveTestImports);
    printStart("local_set.0.wasm");
    localset0_typeX2DlocalX2Di32(&instance);
    localset0_typeX2DlocalX2Di64(&instance);
    localset0_typeX2DlocalX2Df32(&instance);
    localset0_typeX2DlocalX2Df64(&instance);
    localset0_typeX2DparamX2Di32(&instance, 2u);
    localset0_typeX2DparamX2Di64(&instance, 3ull);
    localset0_typeX2DparamX2Df32(&instance, 4.400000095367432);
    localset0_typeX2DparamX2Df64(&instance, 5.5);
    localset0_asX2DblockX2Dvalue(&instance, 0u);
    localset0_asX2DloopX2Dvalue(&instance, 0u);
    localset0_asX2DbrX2Dvalue(&instance, 0u);
    localset0_asX2DbrX5FifX2Dvalue(&instance, 0u);
    localset0_asX2DbrX5FifX2DvalueX2Dcond(&instance, 0u);
    localset0_asX2DbrX5FtableX2Dvalue(&instance, 0u);
    localset0_asX2DreturnX2Dvalue(&instance, 0u);
    localset0_asX2DifX2Dthen(&instance, 1u);
    localset0_asX2DifX2Delse(&instance, 0u);
    localset0_typeX2Dmixed(&instance, 1ull, 2.200000047683716, 3.3, 4u, 5u);
    assertEqualU64(
        localset0_write(&instance, 1ull, 2.0, 3.3, 4u, 5u),
        56ull,
        "write(1ull, 2.0, 3.3, 4u, 5u)"
    );
}
