#include <stdio.h>
#include <mach-o/dyld.h>
#include "sectcreate.h"

#define CHECK(condition) \
    do { \
        if (!(condition)) { \
            fprintf(stderr, "FAIL sectcreate: line %d: %s\n", __LINE__, #condition); \
            abort(); \
        } \
    } while (0)

void
trap(Trap value) {
    (void)value;
    abort();
}

int
main(void) {
    static const U8 expected[] = {0, 0, 3, 1, 4, 1, 0, 2, 7, 1, 8, 0, 7, 5, 2, 3, 6};
    unsigned int iteration;
    CHECK(_dyld_get_image_vmaddr_slide(0) != 0);
    for (iteration = 0; iteration < 2; iteration++) {
        m4_dataInstance instance;
        m4_dataInstantiate(&instance, NULL);
        CHECK(memcmp(instance.m0->data + 2, expected + 2, 4) == 0);
        CHECK(memcmp(instance.m0->data + 12, expected + 12, 5) == 0);
        m4_dataExport4_test(&instance);
        CHECK(memcmp(instance.m0->data, expected, sizeof(expected)) == 0);
        m4_dataFreeInstance(&instance);
    }
    fprintf(stderr, "PASS sectcreate\n");
    return 0;
}
