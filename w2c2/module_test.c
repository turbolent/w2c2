#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "c.h"
#include "file.h"
#include "instruction.h"
#include "module_test.h"
#include "reader.h"

static
void*
testAllocate(
    const size_t count,
    const size_t size
) {
    void* result = calloc(count, size);
    if (result == NULL) {
        fprintf(stderr, "FAIL testModuleLifecycle: allocation failed\n");
        exit(1);
    }
    return result;
}

static
char*
testStringDuplicate(
    const char* string
) {
    const size_t length = strlen(string) + 1;
    char* result = testAllocate(length, sizeof(char));
    memcpy(result, string, length);
    return result;
}

static
WasmName
testNameDuplicate(const char* string) {
    WasmName result;
    result.data = testStringDuplicate(string);
    result.length = strlen(string);
    return result;
}

static
bool
testBufferContains(
    const Buffer buffer,
    const char* expected
) {
    const size_t expectedLength = strlen(expected);
    size_t index = 0;

    if (expectedLength > buffer.length) {
        return false;
    }

    for (; index <= buffer.length - expectedLength; index++) {
        if (memcmp(buffer.data + index, expected, expectedLength) == 0) {
            return true;
        }
    }

    return false;
}

static
void
testModuleFree(void) {
    static U8 borrowedBytes[] = {0x0B};
    WasmModule* module = testAllocate(1, sizeof(WasmModule));

    module->functionTypes.count = 1;
    module->functionTypes.functionTypes =
        testAllocate(1, sizeof(WasmFunctionType));
    module->functionTypes.functionTypes[0].parameterCount = 1;
    module->functionTypes.functionTypes[0].parameterTypes =
        testAllocate(1, sizeof(WasmValueType));
    module->functionTypes.functionTypes[0].resultCount = 1;
    module->functionTypes.functionTypes[0].resultTypes =
        testAllocate(1, sizeof(WasmValueType));

    module->functionImports.length = 1;
    module->functionImports.capacity = 1;
    module->functionImports.imports =
        testAllocate(1, sizeof(WasmFunctionImport));
    module->functionImports.imports[0].module = testNameDuplicate("env");
    module->functionImports.imports[0].name = testNameDuplicate("function");

    module->globalImports.length = 1;
    module->globalImports.capacity = 1;
    module->globalImports.imports =
        testAllocate(1, sizeof(WasmGlobalImport));
    module->globalImports.imports[0].module = testNameDuplicate("env");
    module->globalImports.imports[0].name = testNameDuplicate("global");

    module->memoryImports.length = 1;
    module->memoryImports.capacity = 1;
    module->memoryImports.imports =
        testAllocate(1, sizeof(WasmMemoryImport));
    module->memoryImports.imports[0].module = testNameDuplicate("env");
    module->memoryImports.imports[0].name = testNameDuplicate("memory");

    module->tableImports.length = 1;
    module->tableImports.capacity = 1;
    module->tableImports.imports =
        testAllocate(1, sizeof(WasmTableImport));
    module->tableImports.imports[0].module = testNameDuplicate("env");
    module->tableImports.imports[0].name = testNameDuplicate("table");

    module->functions.count = 1;
    module->functions.functions = testAllocate(1, sizeof(WasmFunction));
    module->functions.functions[0].localsDeclarations.declarationCount = 1;
    module->functions.functions[0].localsDeclarations.declarations =
        testAllocate(1, sizeof(WasmLocalsDeclaration));
    module->functions.functions[0].code.data = borrowedBytes;
    module->functions.functions[0].code.length = sizeof borrowedBytes;

    module->exports.count = 1;
    module->exports.exports = testAllocate(1, sizeof(WasmExport));
    module->exports.exports[0].name = testNameDuplicate("export");
    module->functions.functions[0].exportName =
        module->exports.exports[0].name;

    module->globals.count = 1;
    module->globals.globals = testAllocate(1, sizeof(WasmGlobal));
    module->globals.globals[0].init.data = borrowedBytes;
    module->globals.globals[0].init.length = sizeof borrowedBytes;

    module->memories.count = 1;
    module->memories.memories = testAllocate(1, sizeof(WasmMemory));
    module->tables.count = 1;
    module->tables.tables = testAllocate(1, sizeof(WasmTable));

    module->dataSegments.count = 1;
    module->dataSegments.dataSegments =
        testAllocate(1, sizeof(WasmDataSegment));
    module->dataSegments.dataSegments[0].offset.data = borrowedBytes;
    module->dataSegments.dataSegments[0].offset.length = sizeof borrowedBytes;
    module->dataSegments.dataSegments[0].bytes.data =
        testAllocate(1, sizeof(U8));
    module->dataSegments.dataSegments[0].bytes.length = 1;

    module->elementSegments.count = 1;
    module->elementSegments.elementSegments =
        testAllocate(1, sizeof(WasmElementSegment));
    module->elementSegments.elementSegments[0].offset.data = borrowedBytes;
    module->elementSegments.elementSegments[0].offset.length =
        sizeof borrowedBytes;
    module->elementSegments.elementSegments[0].functionIndexCount = 1;
    module->elementSegments.elementSegments[0].functionIndices =
        testAllocate(1, sizeof(U32));

    module->debugSections.length = 1;
    module->debugSections.capacity = 1;
    module->debugSections.debugSections =
        testAllocate(1, sizeof(WasmDebugSection));
    module->debugSections.debugSections[0].name =
        testNameDuplicate(".debug_info");
    module->debugSections.debugSections[0].buffer.data = borrowedBytes;
    module->debugSections.debugSections[0].buffer.length =
        sizeof borrowedBytes;

    module->debugLines.length = 1;
    module->debugLines.capacity = 1;
    module->debugLines.debugLines = testAllocate(1, sizeof(WasmDebugLine));
    module->debugLines.debugLines[0].path = testStringDuplicate("module.c");

    module->functionNames.length = 1;
    module->functionNames.capacity = 1;
    module->functionNames.names = testAllocate(1, sizeof(WasmName));
    module->functionNames.names[0] = testNameDuplicate("function");

    wasmModuleFree(module);
    wasmModuleFree(NULL);

    if (borrowedBytes[0] != 0x0B) {
        fprintf(stderr, "FAIL testModuleLifecycle: borrowed bytes changed\n");
        exit(1);
    }
}

static
void
testModuleReadCleanup(void) {
    static U8 validModule[] = {
        0x00, 0x61, 0x73, 0x6D,
        0x01, 0x00, 0x00, 0x00
    };
    static U8 invalidModule[] = {
        0x00, 0x61, 0x73, 0x6D,
        0x01, 0x00, 0x00, 0x00,
        0x01, 0x06,
        0x02,
        0x60, 0x01, 0x7F, 0x00,
        0x61
    };
    static U8 duplicateNamesModule[] = {
        0x00, 0x61, 0x73, 0x6D,
        0x01, 0x00, 0x00, 0x00,
        0x01, 0x04, 0x01, 0x60, 0x00, 0x00,
        0x03, 0x04, 0x03, 0x00, 0x00, 0x00,
        0x0A, 0x0A, 0x03,
        0x02, 0x00, 0x0B,
        0x02, 0x00, 0x0B,
        0x02, 0x00, 0x0B,
        0x00, 0x12,
        0x04, 0x6E, 0x61, 0x6D, 0x65,
        0x01, 0x0B, 0x02,
        0x00, 0x03, 0x66, 0x6F, 0x6F,
        0x01, 0x03, 0x66, 0x6F, 0x6F
    };
    static U8 duplicateSectionModule[] = {
        0x00, 0x61, 0x73, 0x6D,
        0x01, 0x00, 0x00, 0x00,
        0x01, 0x04, 0x01, 0x60, 0x00, 0x00,
        0x01, 0x04, 0x01, 0x60, 0x00, 0x00
    };
    static U8 outOfOrderSectionModule[] = {
        0x00, 0x61, 0x73, 0x6D,
        0x01, 0x00, 0x00, 0x00,
        0x05, 0x03, 0x01, 0x00, 0x00,
        0x01, 0x04, 0x01, 0x60, 0x00, 0x00
    };
    static U8 truncatedSectionModule[] = {
        0x00, 0x61, 0x73, 0x6D,
        0x01, 0x00, 0x00, 0x00,
        0x01, 0x7F
    };
    static U8 impossibleTypeCountModule[] = {
        0x00, 0x61, 0x73, 0x6D,
        0x01, 0x00, 0x00, 0x00,
        0x01, 0x05,
        0xFF, 0xFF, 0xFF, 0xFF, 0x0F
    };
    static U8 truncatedCodeBodyModule[] = {
        0x00, 0x61, 0x73, 0x6D,
        0x01, 0x00, 0x00, 0x00,
        0x01, 0x04, 0x01, 0x60, 0x00, 0x00,
        0x03, 0x02, 0x01, 0x00,
        0x0A, 0x03, 0x01, 0x01, 0x01,
        0x00, 0x7F
    };
    static U8 truncatedNameSubsectionModule[] = {
        0x00, 0x61, 0x73, 0x6D,
        0x01, 0x00, 0x00, 0x00,
        0x01, 0x04, 0x01, 0x60, 0x00, 0x00,
        0x03, 0x02, 0x01, 0x00,
        0x0A, 0x04, 0x01, 0x02, 0x00, 0x0B,
        0x00, 0x08,
        0x04, 0x6E, 0x61, 0x6D, 0x65,
        0x01, 0x01, 0x01,
        0x00, 0x00
    };
    WasmModuleReader reader = emptyWasmModuleReader;
    WasmModuleReaderError* error = NULL;
    U32 iteration = 0;

    for (; iteration < 16; iteration++) {
        reader = emptyWasmModuleReader;
        reader.buffer.data = validModule;
        reader.buffer.length = sizeof validModule;
        wasmModuleRead(&reader, &error);
        if (error != NULL
            || reader.module == NULL
            || reader.buffer.data != validModule
            || reader.buffer.length != sizeof validModule) {

            fprintf(stderr, "FAIL testModuleLifecycle: valid module failed\n");
            exit(1);
        }
        wasmModuleFree(reader.module);
    }

    reader = emptyWasmModuleReader;
    reader.buffer.data = invalidModule;
    reader.buffer.length = sizeof invalidModule;
    wasmModuleRead(&reader, &error);
    if (error == NULL || reader.module != NULL) {
        fprintf(stderr, "FAIL testModuleLifecycle: invalid module survived\n");
        exit(1);
    }

    reader = emptyWasmModuleReader;
    reader.buffer.data = duplicateNamesModule;
    reader.buffer.length = sizeof duplicateNamesModule;
    reader.debug = true;
    wasmModuleRead(&reader, &error);
    if (error != NULL
        || reader.module == NULL
        || reader.module->functionNames.length != 3
        || reader.module->functionNames.names[0].data != NULL
        || reader.module->functionNames.names[1].data != NULL
        || reader.module->functionNames.names[2].data != NULL) {

        fprintf(stderr, "FAIL testModuleLifecycle: duplicate names survived\n");
        exit(1);
    }
    wasmModuleFree(reader.module);

    reader = emptyWasmModuleReader;
    reader.buffer.data = duplicateSectionModule;
    reader.buffer.length = sizeof duplicateSectionModule;
    wasmModuleRead(&reader, &error);
    if (error == NULL
        || error->code != wasmModuleReaderInvalidSectionOrder
        || reader.module != NULL) {

        fprintf(stderr, "FAIL testModuleLifecycle: duplicate section survived\n");
        exit(1);
    }

    reader = emptyWasmModuleReader;
    reader.buffer.data = outOfOrderSectionModule;
    reader.buffer.length = sizeof outOfOrderSectionModule;
    wasmModuleRead(&reader, &error);
    if (error == NULL
        || error->code != wasmModuleReaderInvalidSectionOrder
        || reader.module != NULL) {

        fprintf(
            stderr,
            "FAIL testModuleLifecycle: out-of-order section survived\n"
        );
        exit(1);
    }

    reader = emptyWasmModuleReader;
    reader.buffer.data = truncatedSectionModule;
    reader.buffer.length = sizeof truncatedSectionModule;
    wasmModuleRead(&reader, &error);
    if (error == NULL
        || error->code != wasmModuleReaderInvalidSectionSize
        || reader.module != NULL
        || reader.buffer.data != truncatedSectionModule
        || reader.buffer.length != sizeof truncatedSectionModule) {

        fprintf(stderr, "FAIL testModuleLifecycle: truncated section survived\n");
        exit(1);
    }

    reader = emptyWasmModuleReader;
    reader.buffer.data = impossibleTypeCountModule;
    reader.buffer.length = sizeof impossibleTypeCountModule;
    wasmModuleRead(&reader, &error);
    if (error == NULL
        || error->code != wasmModuleReaderInvalidTypeSectionTypeCount
        || reader.module != NULL) {

        fprintf(stderr, "FAIL testModuleLifecycle: impossible type count survived\n");
        exit(1);
    }

    reader = emptyWasmModuleReader;
    reader.buffer.data = truncatedCodeBodyModule;
    reader.buffer.length = sizeof truncatedCodeBodyModule;
    wasmModuleRead(&reader, &error);
    if (error == NULL
        || error->code != wasmModuleReaderInvalidCodeSectionLocalsDeclarations
        || reader.module != NULL
        || reader.buffer.data != truncatedCodeBodyModule
        || reader.buffer.length != sizeof truncatedCodeBodyModule) {

        fprintf(stderr, "FAIL testModuleLifecycle: truncated code body survived\n");
        exit(1);
    }

    reader = emptyWasmModuleReader;
    reader.buffer.data = truncatedNameSubsectionModule;
    reader.buffer.length = sizeof truncatedNameSubsectionModule;
    reader.debug = true;
    wasmModuleRead(&reader, &error);
    if (error == NULL
        || error->code != wasmModuleReaderInvalidNameSectionFunctionNameCount
        || reader.module != NULL) {

        fprintf(
            stderr,
            "FAIL testModuleLifecycle: truncated name subsection survived\n"
        );
        exit(1);
    }

    reader = emptyWasmModuleReader;
    reader.buffer.data = validModule;
    reader.buffer.length = sizeof validModule;
    wasmModuleRead(&reader, &error);
    if (error != NULL || reader.module == NULL) {
        fprintf(stderr, "FAIL testModuleLifecycle: replacement setup failed\n");
        exit(1);
    }
    {
        WasmModule* module = reader.module;
        reader.buffer.data = invalidModule;
        reader.buffer.length = sizeof invalidModule;
        wasmModuleRead(&reader, &error);
        if (error == NULL || reader.module != module) {
            fprintf(
                stderr,
                "FAIL testModuleLifecycle: failed read replaced module\n"
            );
            exit(1);
        }

        reader.buffer.data = validModule;
        reader.buffer.length = sizeof validModule;
        wasmModuleRead(&reader, &error);
        if (error != NULL
            || reader.module == NULL
            || reader.module == module) {

            fprintf(
                stderr,
                "FAIL testModuleLifecycle: successful read kept prior module\n"
            );
            exit(1);
        }
    }
    wasmModuleFree(reader.module);
}

static
void
testBranchTableReadCleanup(void) {
    static U8 truncatedInstruction[] = {0x01};
    Buffer buffer = {
        truncatedInstruction,
        sizeof truncatedInstruction
    };
    WasmBranchTableInstruction instruction;

    if (wasmBranchTableInstructionRead(&buffer, &instruction)) {
        fprintf(
            stderr,
            "FAIL testModuleLifecycle: truncated branch table survived\n"
        );
        exit(1);
    }
}

static
void
testModuleWriteCleanup(void) {
    static U8 moduleBytes[] = {
        0x00, 0x61, 0x73, 0x6D,
        0x01, 0x00, 0x00, 0x00,
        0x01, 0x09, 0x02,
        0x60, 0x00, 0x00,
        0x60, 0x00, 0x02, 0x7F, 0x7F,
        0x03, 0x03, 0x02, 0x00, 0x00,
        0x0A, 0x07, 0x02,
        0x02, 0x00, 0x0B,
        0x02, 0x00, 0x0B
    };
    static const char* outputPath = "w2c2_library_test.c";
    static const char* headerPath = "w2c2_library_test.h";
    static const char* debugOutputPath = "w2c2_library_debug_test.c";
    static const char* debugHeaderPath = "w2c2_library_debug_test.h";
    static const char* implementationPath = "m11_librarytest.s0000000000.c";
    static const char* secondImplementationPath = "m16_librarydebugtest.s0000000001.c";
    WasmModuleReader reader = emptyWasmModuleReader;
    WasmModuleReaderError* error = NULL;
    WasmCWriteModuleOptions options = emptyWasmCWriteModuleOptions;
    WasmFunctionIDs functionIDs = emptyWasmFunctionIDs;
    U32 functionIndex = 0;

    reader.buffer.data = moduleBytes;
    reader.buffer.length = sizeof moduleBytes;
    wasmModuleRead(&reader, &error);
    if (error != NULL || reader.module == NULL) {
        fprintf(stderr, "FAIL testModuleLifecycle: writer module failed\n");
        exit(1);
    }

    for (; functionIndex < reader.module->functions.count; functionIndex++) {
        WasmFunctionID functionID = emptyWasmFunctionID;
        memcpy(
            functionID.hash,
            reader.module->functions.functions[functionIndex].hash,
            SHA1_DIGEST_LENGTH
        );
        functionID.functionIndex = functionIndex;
        if (!wasmFunctionIDsAppend(&functionIDs, functionID)) {
            fprintf(
                stderr,
                "FAIL testModuleLifecycle: function ID allocation failed\n"
            );
            exit(1);
        }
    }

    options.outputName = outputPath;
    options.output = wasmFileOutputProvider(".");
    options.functionsPerFile = 0;
    options.threadCount = 0;
    if (!wasmCWriteModule(
        reader.module,
        "librarytest",
        options,
        functionIDs,
        emptyWasmFunctionIDs
    )) {
        fprintf(stderr, "FAIL testModuleLifecycle: zero-thread write failed\n");
        exit(1);
    }

    if (remove(outputPath) != 0
        || remove(headerPath) != 0
        || remove(implementationPath) != 0) {

        fprintf(stderr, "FAIL testModuleLifecycle: output cleanup failed\n");
        exit(1);
    }

    reader.module->debugLines.length = 3;
    reader.module->debugLines.capacity = 3;
    reader.module->debugLines.debugLines =
        testAllocate(3, sizeof(WasmDebugLine));
    reader.module->debugLines.debugLines[0].address = 0;
    reader.module->debugLines.debugLines[0].path =
        testStringDuplicate("module-0.c");
    reader.module->debugLines.debugLines[0].number = 10;
    reader.module->debugLines.debugLines[1].address =
        reader.module->functions.functions[0].start;
    reader.module->debugLines.debugLines[1].path =
        testStringDuplicate("module-1.c");
    reader.module->debugLines.debugLines[1].number = 20;
    reader.module->debugLines.debugLines[2].address =
        reader.module->functions.functions[1].start;
    reader.module->debugLines.debugLines[2].path =
        testStringDuplicate("module-2.c");
    reader.module->debugLines.debugLines[2].number = 30;

    implementationPath = "m16_librarydebugtest.s0000000000.c";
    options.outputName = debugOutputPath;
    options.functionsPerFile = 1;
    options.threadCount = 2;
    options.debug = true;
    if (!wasmCWriteModule(
        reader.module,
        "librarydebugtest",
        options,
        functionIDs,
        emptyWasmFunctionIDs
    )) {
        fprintf(stderr, "FAIL testModuleLifecycle: debug write failed\n");
        exit(1);
    }

    {
        Buffer implementation = readFile(secondImplementationPath);
        if (!testBufferContains(
            implementation,
            "#line 30 \"module-2.c\""
        )) {
            fprintf(
                stderr,
                "FAIL testModuleLifecycle: split debug cursor was reset\n"
            );
            bufferFree(&implementation);
            exit(1);
        }
        bufferFree(&implementation);
    }

    wasmFunctionIDsFree(&functionIDs);
    wasmModuleFree(reader.module);

    if (remove(debugOutputPath) != 0
        || remove(debugHeaderPath) != 0
        || remove(implementationPath) != 0
        || remove(secondImplementationPath) != 0) {

        fprintf(stderr, "FAIL testModuleLifecycle: debug output cleanup failed\n");
        exit(1);
    }
}

void
testModuleLifecycle(void) {
    testModuleFree();
    testModuleReadCleanup();
    testBranchTableReadCleanup();
    testModuleWriteCleanup();
    fprintf(stderr, "PASS testModuleLifecycle\n");
}
