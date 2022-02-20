#include <stdio.h>
#include <ctype.h>
#ifdef HAS_GETOPT
  #include <getopt.h>
#else
  #include "getopt_impl.h"
#endif

#include "buffer.h"
#include "file.h"
#include "reader.h"
#include "c.h"

static
bool
readWasmBinary(
    const char* path,
    WasmModuleReader* wasmModuleReaderResult,
    bool debug
) {
    WasmModuleReaderError* error = NULL;
    Buffer buffer = readFile(path);
    if (buffer.data == NULL) {
        fprintf(stderr, "w2c2: failed to read file %s\n", path);
        return false;
    }

    wasmModuleReaderResult->buffer = buffer;

    wasmModuleRead(wasmModuleReaderResult, debug, &error);
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
    bool debug = false;
    WasmDataSegmentMode dataSegmentMode = wasmDataSegmentModeArrays;

    int index = 0;
    int c = -1;

    opterr = 0;

    while ((c = getopt(argc, argv, "j:o:f:d:pgh")) != -1) {
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
            case 'g': {
                debug = true;
                break;
            }
            case 'd': {
                if (strcmp(optarg, "arrays") == 0) {
                    dataSegmentMode = wasmDataSegmentModeArrays;
                } else if (strcmp(optarg, "gnu-ld") == 0) {
                    dataSegmentMode = wasmDataSegmentModeGNULD;
                } else if (strcmp(optarg, "sectcreate1") == 0) {
                    dataSegmentMode = wasmDataSegmentModeSectcreate1;
                } else if (strcmp(optarg, "sectcreate2") == 0) {
                    dataSegmentMode = wasmDataSegmentModeSectcreate2;
                } else if (strcmp(optarg, "help") == 0) {
                    fprintf(
                        stderr,
                        "Supported data segment modes are:\n"
                        "arrays         Writes each data segment as a C array\n"
                        "gnu-ld         All data segments are embedded into a data section using GNU LD\n"
                        "sectcreate1    All data segments are embedded into a data section using sectcreate\n"
                        "               and accessed using asm (modern Mach-O LD)\n"
                        "sectcreate2    All data segments are embedded into a data section using sectcreate\n"
                        "               and accessed using Mach-O getsectdata (older Mach-O LD)\n"
                    );
                    return EXIT_SUCCESS;
                } else {
                    fprintf(
                        stderr,
                        "w2c2: unsupported data segment mode '%s'. Use 'help' to print available modes\n",
                        optarg
                    );
                    return EXIT_FAILURE;
                }
                break;
            }
            case 'h': {
                fprintf(stderr, "usage: w2c2 [options] filename\n\n");
                fprintf(stderr, "options:\n");
                fprintf(stderr, "  -h         Print this help message\n");
                fprintf(stderr, "  -j N       Number of jobs (>1 enables parallel compilation and requires -o)\n");
                fprintf(stderr, "  -f N       Number of functions per file when parallel compilation is enabled\n");
                fprintf(stderr, "  -o PATH    Path for the output file(s). Default: use stdout. Required for parallel compilation\n");
                fprintf(stderr, "  -d MODE    Data segment mode. Default: arrays. Use 'help' to print available modes\n");
                fprintf(stderr, "  -g         Generate debug information (#line directives) based on DWARF\n");
                fprintf(stderr, "  -p         Generate pretty code\n");
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
        WasmModuleReader reader = emptyWasmModuleReader;
        WasmCWriteModuleOptions writeOptions = emptyWasmCWriteModuleOptions;

        if (!readWasmBinary(modulePath, &reader, debug)) {
            return 1;
        }

        if (jobCount == 1) {
            functionsPerFile = reader.module->functions.count;
        }

        writeOptions.outputPath = outputPath;
        writeOptions.jobCount = jobCount;
        writeOptions.functionsPerFile = functionsPerFile;
        writeOptions.pretty = pretty;
        writeOptions.debug = debug;
        writeOptions.dataSegmentMode = dataSegmentMode;

        if (!wasmCWriteModule(reader.module, writeOptions)) {
            fprintf(stderr, "w2c2: failed to compile\n");
            return 1;
        }
    }

    return 0;
}
