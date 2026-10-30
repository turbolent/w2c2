#include "test.h"
#include "test_bulk.9.h"

void test(void) {
    static m6_bulkX2E9Instance instance;
    m6_bulkX2E9Instantiate(&instance, resolveTestImports);
    printStart("bulk.9.wasm");
    (void)(m6_bulkX2E9Export12_initX5Fpassive(&instance, 1u));
    printOK("init_passive(1u)");
    (void)(m6_bulkX2E9Export12_dropX5Fpassive(&instance));
    printOK("drop_passive()");
    (void)(m6_bulkX2E9Export12_dropX5Fpassive(&instance));
    printOK("drop_passive()");
    (void)(m6_bulkX2E9Export12_initX5Fpassive(&instance, 0u));
    (void)(m6_bulkX2E9Export12_initX5Fpassive(&instance, 0u));
    printOK("init_passive(0u)");
    (void)(m6_bulkX2E9Export11_dropX5Factive(&instance));
    printOK("drop_active()");
    (void)(m6_bulkX2E9Export11_initX5Factive(&instance, 0u));
    (void)(m6_bulkX2E9Export11_initX5Factive(&instance, 0u));
    printOK("init_active(0u)");
    m6_bulkX2E9FreeInstance(&instance);
}
