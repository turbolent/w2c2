
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_store.0.h"

void test() {
    store0Instance instance;
    store0Instantiate(&instance, resolveTestImports);
    printStart("store.0.wasm");
    store0_asX2DblockX2Dvalue(&instance);
    store0_asX2DloopX2Dvalue(&instance);
    store0_asX2DbrX2Dvalue(&instance);
    store0_asX2Dbr_ifX2Dvalue(&instance);
    store0_asX2Dbr_ifX2DvalueX2Dcond(&instance);
    store0_asX2Dbr_tableX2Dvalue(&instance);
    store0_asX2DreturnX2Dvalue(&instance);
    store0_asX2DifX2Dthen(&instance);
    store0_asX2DifX2Delse(&instance);
}
