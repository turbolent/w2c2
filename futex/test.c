#include "list_test.h"
#include "map_test.h"
#include "futex_test.h"
#include "atomic_test.h"
#include "../w2c2/w2c2_base.h"

int
main(void) {
    testListOperations();
    testListFree();
    testMapOperations();
    testMapFree();
    testAtomics();
    testFutex();
    return 0;
}
