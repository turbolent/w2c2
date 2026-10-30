#include "test.h"
#include "test_func.5.h"

void test(void) {
    static m6_funcX2E5Instance instance;
    m6_funcX2E5Instantiate(&instance, resolveTestImports);
    printStart("func.5.wasm");
    (void)(m6_funcX2E5Export25_signatureX2DexplicitX2Dreused(&instance));
    (void)(m6_funcX2E5Export25_signatureX2DimplicitX2Dreused(&instance));
    (void)(m6_funcX2E5Export28_signatureX2DexplicitX2Dduplicate(&instance));
    (void)(m6_funcX2E5Export28_signatureX2DimplicitX2Dduplicate(&instance));
    m6_funcX2E5FreeInstance(&instance);
}
