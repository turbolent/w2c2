#include "test.h"
#include "test_bulk.5.h"

void test(void) {
    static m6_bulkX2E5Instance instance;
    m6_bulkX2E5Instantiate(&instance, resolveTestImports);
    printStart("bulk.5.wasm");
    (void)(m6_bulkX2E5Export12_initX5Fpassive(&instance, 1u));
    printOK("init_passive(1u)");
    (void)(m6_bulkX2E5Export12_dropX5Fpassive(&instance));
    printOK("drop_passive()");
    (void)(m6_bulkX2E5Export12_dropX5Fpassive(&instance));
    printOK("drop_passive()");
    (void)(m6_bulkX2E5Export12_initX5Fpassive(&instance, 0u));
    (void)(m6_bulkX2E5Export12_initX5Fpassive(&instance, 0u));
    printOK("init_passive(0u)");
    (void)(m6_bulkX2E5Export11_dropX5Factive(&instance));
    printOK("drop_active()");
    (void)(m6_bulkX2E5Export11_initX5Factive(&instance, 0u));
    (void)(m6_bulkX2E5Export11_initX5Factive(&instance, 0u));
    printOK("init_active(0u)");
    m6_bulkX2E5FreeInstance(&instance);
}
