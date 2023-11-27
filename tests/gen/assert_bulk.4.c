
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_bulk.4.h"

void test() {
    bulk4Instance instance;
    bulk4Instantiate(&instance, resolveTestImports);
    printStart("bulk.4.wasm");
    bulk4_init_passive(&instance, 1u);
    printOK("init_passive(1u)");
    bulk4_drop_passive(&instance);
    printOK("drop_passive()");
    bulk4_drop_passive(&instance);
    printOK("drop_passive()");
    bulk4_init_passive(&instance, 0u);
    bulk4_init_passive(&instance, 0u);
    printOK("init_passive(0u)");
    bulk4_drop_active(&instance);
    printOK("drop_active()");
    bulk4_init_active(&instance, 0u);
    bulk4_init_active(&instance, 0u);
    printOK("init_active(0u)");
}
