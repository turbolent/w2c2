#include "list_test.h"
#include "map_test.h"
#include "futex_test.h"
#include "../w2c2/w2c2_base.h"

void
trap(Trap trap) {
    abort();
}

int
main(void) {
    testListOperations();
    testListFree();
    testMapOperations();
    testMapFree();
    testFutex();
    return 0;
}
