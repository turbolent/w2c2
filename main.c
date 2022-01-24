#include <stdio.h>
#include <stdint.h>
#include <ctype.h>
#ifdef _WIN32
  #include "getopt_impl.h"
#else 
  #include <getopt.h>
#endif

#include "buffer.h"
#include "file.h"
#include "reader.h"
#include "c.h"

static
bool
readWasmBinary(
    const char* path,
    WasmModuleReader* wasmModuleReaderResult
) {
    WasmModuleReaderError* error = NULL;

    wasmModuleReaderResult->buffer = readFile(path);
    if (wasmModuleReaderResult->buffer.data == NULL) {
        fprintf(stderr, "w2c2: failed to read file %s\n", path);
        return false;
    }

    wasmModuleRead(wasmModuleReaderResult, &error);
    if (error != NULL) {
        fprintf(stderr, "w2c2: failed to read module: %s\n", wasmModuleReaderErrorMessage(error));
        return false;
    }

    return true;
}

int
main(
    int argc,
    char* argv[]
) {
    U32 jobCount = 1;
    char* modulePath = NULL;
    char* outputPath = NULL;
    U32 functionsPerFile = 10;
    bool pretty = false;

    int index;
    int c;

    opterr = 0;

    while ((c = getopt(argc, argv, "j:o:f:ph")) != -1) {
        switch (c) {
            case 'j': {
                jobCount = strtoul(optarg, NULL, 0);
                break;
            }
            case 'o': {
                outputPath = optarg;
                break;
            }
            case 'f': {
                functionsPerFile = strtoul(optarg, NULL, 0);
                break;
            }
            case 'p': {
                pretty = true;
                break;
            }
            case 'h': {
                fprintf(
                    stderr,
                    "usage: w2c2 [options] filename\n\n"
                    "options:\n"
                    "  -h         Print this help message\n"
                    "  -j         Number of jobCount (>1 enables parallel compilation and requires -o)\n"
                    "  -f         Number of functions per file when parallel compilation is enabled\n"
                    "  -o PATH    Path for the output file(s), by default use stdout. Required for parallel compilation\n"
                    "  -p         Generate pretty code\n"
                );
                return 0;
            }
            case '?': {
                if (optopt == 'o') {
                    fprintf(stderr, "w2c2: option -%c requires an argument.\n", optopt);
                }
                else if (isprint(optopt)) {
                    fprintf(stderr, "w2c2: unknown option `-%c'.\n", optopt);
                } else {
                    fprintf(
                        stderr,
                        "w2c2: unknown option character `\\x%x'.\n",
                        optopt
                    );
                }
                return 1;
            }
            default:
                abort();
        }
    }

    index = optind;

    if (index >= argc) {
        fprintf(stderr, "w2c2: expected filename argument.\nTry '-h' for more information.\n");
        return 1;
    }

    if (jobCount < 1) {
        fprintf(stderr, "w2c2: expected jobCount >= 1, got %d\n", jobCount);
        return 1;
    }

    if (jobCount > 1 && outputPath == NULL) {
        fprintf(
            stderr,
            "w2c2: expected output path argument for parallel compilation.\n"
            "Try '-h' for more information.\n"
        );
        return 1;
    }

    modulePath = argv[index];

    {
        WasmModuleReader wasmModuleReader;
        if (!readWasmBinary(modulePath, &wasmModuleReader)) {
            return 1;
        }

        if (jobCount == 1) {
            functionsPerFile = wasmModuleReader.module->functions.count;
        }

        if (!wasmCWriteModule(outputPath, wasmModuleReader.module, jobCount, functionsPerFile, pretty)) {
            fprintf(stderr, "w2c2: failed to compile\n");
            return 1;
        }
    }

    return 0;
}
