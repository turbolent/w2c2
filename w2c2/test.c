#include "leb128_test.h"
#include "stringbuilder_test.h"
#include "typestack_test.h"

int
main() {
    testReadU32LEB128();
    testReadI32LEB128();
    testStringBuilder();
    testTypeStack();
    return 0;
}
