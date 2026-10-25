#ifndef W2C2_DIAGNOSTIC_PRINT_H
#define W2C2_DIAGNOSTIC_PRINT_H

#include <stdio.h>

#include "diagnostic.h"

#ifdef __cplusplus
extern "C" {
#endif

void
wasmDiagnosticPrint(
    FILE* file,
    const WasmDiagnostic* diagnostic,
    const char* inputName
);

#ifdef __cplusplus
}
#endif

#endif /* W2C2_DIAGNOSTIC_PRINT_H */
