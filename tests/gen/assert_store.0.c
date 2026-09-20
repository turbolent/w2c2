
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_store.0.h"

void test() {
    m7_storeX2E0Instance instance;
    m7_storeX2E0Instantiate(&instance, resolveTestImports);
    printStart("store.0.wasm");
    m7_storeX2E0Export14_asX2DblockX2Dvalue(&instance);
    m7_storeX2E0Export13_asX2DloopX2Dvalue(&instance);
    m7_storeX2E0Export11_asX2DbrX2Dvalue(&instance);
    m7_storeX2E0Export14_asX2DbrX5FifX2Dvalue(&instance);
    m7_storeX2E0Export19_asX2DbrX5FifX2DvalueX2Dcond(&instance);
    m7_storeX2E0Export17_asX2DbrX5FtableX2Dvalue(&instance);
    m7_storeX2E0Export15_asX2DreturnX2Dvalue(&instance);
    m7_storeX2E0Export10_asX2DifX2Dthen(&instance);
    m7_storeX2E0Export10_asX2DifX2Delse(&instance);
}
