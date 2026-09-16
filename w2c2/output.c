#include <errno.h>

#include "diagnostic_internal.h"

bool
WARN_UNUSED_RESULT
wasmDiagnosticCloseOutput(
    WasmDiagnosticContext* context,
    FILE* file
) {
    const bool writeFailed = ferror(file) != 0;
    const int closeResult = fclose(file);
    const int closeError = closeResult == 0 ? 0 : errno;

    if (!writeFailed && closeResult == 0) {
        return true;
    }
    if (!context->hasError) {
        wasmDiagnosticReportOutputFailed(
            context,
            writeFailed ? wasmDiagnosticOutputWriteFailed : wasmDiagnosticOutputCloseFailed,
            context->location.outputName,
            writeFailed ? 0 : closeError
        );
    }
    return false;
}
