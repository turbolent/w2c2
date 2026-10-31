#include "test.h"
#include "test_table_size.3.h"

void test(void) {
    static m12_tableX5FsizeX2E3Instance instance;
    m12_tableX5FsizeX2E3Instantiate(&instance, resolveTestImports);
    printStart("table_size.3.wasm");
    assertEqualU32(
        m12_tableX5FsizeX2E3Export4_zero(&instance),
        0u,
        "zero()"
    );
    assertEqualU32(
        m12_tableX5FsizeX2E3Export4_size(&instance),
        1u,
        "size()"
    );
    assertEqualU32(
        m12_tableX5FsizeX2E3Export4_grow(&instance, 0u),
        1u,
        "grow(0u)"
    );
    assertEqualU32(
        m12_tableX5FsizeX2E3Export4_grow(&instance, 2u),
        1u,
        "grow(2u)"
    );
    assertEqualU32(
        m12_tableX5FsizeX2E3Export4_size(&instance),
        3u,
        "size()"
    );
    assertEqualU32(
        m12_tableX5FsizeX2E3Export4_grow(&instance, 1u),
        4294967295u,
        "grow(1u)"
    );
    assertEqualU32(
        m12_tableX5FsizeX2E3Export4_size(&instance),
        3u,
        "size()"
    );
    m12_tableX5FsizeX2E3FreeInstance(&instance);
}
