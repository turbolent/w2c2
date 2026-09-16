#ifndef W2C2_DIAGNOSTIC_PRINT_H
#define W2C2_DIAGNOSTIC_PRINT_H

#include <stdio.h>

#include "diagnostic.h"

void
wasmDiagnosticPrint(
    FILE* file,
    const WasmDiagnostic* diagnostic,
    const char* inputName
);

#endif /* W2C2_DIAGNOSTIC_PRINT_H */
