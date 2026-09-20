#include "leb128_test.h"
#include "allocation_test.h"
#include "runtime_memory_test.h"
#include "runtime_shared_memory_test.h"
#include "typestack_test.h"
#include "stackdeclarations_test.h"
#include "labelstack_test.h"
#include "opcode_test.h"
#include "sha1_test.h"
#include "module_test.h"
#include "reader_test.h"
#include "diagnostic_test.h"
#include "output_test.h"
#include "output_file_test.h"
#include "c_name_test.h"
#include "c_file_test.h"

int
main(void) {
    testReadU32LEB128();
    testReadI32LEB128();
    testAllocations();
    testRuntimeMemory();
    testRuntimeSharedMemory();
    testTypeStack();
    testStackDeclarations();
    testLabelStack();
    testOpcodes();
    testSHA1();
    testModuleLifecycle();
    testReadLimits();
    testReadNames();
    testDiagnostics();
    testOutputs();
    testFileOutputs();
    testCNames();
    testCFileNames();
    return 0;
}
