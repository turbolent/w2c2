#include "test.h"
#include "test_table_size.0.h"

void test(void) {
    static m12_tableX5FsizeX2E0Instance instance;
    m12_tableX5FsizeX2E0Instantiate(&instance, resolveTestImports);
    printStart("table_size.0.wasm");
    assertEqualU32(
        m12_tableX5FsizeX2E0Export7_sizeX2Dt0(&instance),
        0u,
        "size-t0()"
    );
    (void)(m12_tableX5FsizeX2E0Export7_growX2Dt0(&instance, 1u));
    assertEqualU32(
        m12_tableX5FsizeX2E0Export7_sizeX2Dt0(&instance),
        1u,
        "size-t0()"
    );
    (void)(m12_tableX5FsizeX2E0Export7_growX2Dt0(&instance, 4u));
    assertEqualU32(
        m12_tableX5FsizeX2E0Export7_sizeX2Dt0(&instance),
        5u,
        "size-t0()"
    );
    (void)(m12_tableX5FsizeX2E0Export7_growX2Dt0(&instance, 0u));
    assertEqualU32(
        m12_tableX5FsizeX2E0Export7_sizeX2Dt0(&instance),
        5u,
        "size-t0()"
    );
    assertEqualU32(
        m12_tableX5FsizeX2E0Export7_sizeX2Dt1(&instance),
        1u,
        "size-t1()"
    );
    (void)(m12_tableX5FsizeX2E0Export7_growX2Dt1(&instance, 1u));
    assertEqualU32(
        m12_tableX5FsizeX2E0Export7_sizeX2Dt1(&instance),
        2u,
        "size-t1()"
    );
    (void)(m12_tableX5FsizeX2E0Export7_growX2Dt1(&instance, 4u));
    assertEqualU32(
        m12_tableX5FsizeX2E0Export7_sizeX2Dt1(&instance),
        6u,
        "size-t1()"
    );
    (void)(m12_tableX5FsizeX2E0Export7_growX2Dt1(&instance, 0u));
    assertEqualU32(
        m12_tableX5FsizeX2E0Export7_sizeX2Dt1(&instance),
        6u,
        "size-t1()"
    );
    assertEqualU32(
        m12_tableX5FsizeX2E0Export7_sizeX2Dt2(&instance),
        0u,
        "size-t2()"
    );
    (void)(m12_tableX5FsizeX2E0Export7_growX2Dt2(&instance, 3u));
    assertEqualU32(
        m12_tableX5FsizeX2E0Export7_sizeX2Dt2(&instance),
        0u,
        "size-t2()"
    );
    (void)(m12_tableX5FsizeX2E0Export7_growX2Dt2(&instance, 1u));
    assertEqualU32(
        m12_tableX5FsizeX2E0Export7_sizeX2Dt2(&instance),
        1u,
        "size-t2()"
    );
    (void)(m12_tableX5FsizeX2E0Export7_growX2Dt2(&instance, 0u));
    assertEqualU32(
        m12_tableX5FsizeX2E0Export7_sizeX2Dt2(&instance),
        1u,
        "size-t2()"
    );
    (void)(m12_tableX5FsizeX2E0Export7_growX2Dt2(&instance, 4u));
    assertEqualU32(
        m12_tableX5FsizeX2E0Export7_sizeX2Dt2(&instance),
        1u,
        "size-t2()"
    );
    (void)(m12_tableX5FsizeX2E0Export7_growX2Dt2(&instance, 1u));
    assertEqualU32(
        m12_tableX5FsizeX2E0Export7_sizeX2Dt2(&instance),
        2u,
        "size-t2()"
    );
    assertEqualU32(
        m12_tableX5FsizeX2E0Export7_sizeX2Dt3(&instance),
        3u,
        "size-t3()"
    );
    (void)(m12_tableX5FsizeX2E0Export7_growX2Dt3(&instance, 1u));
    assertEqualU32(
        m12_tableX5FsizeX2E0Export7_sizeX2Dt3(&instance),
        4u,
        "size-t3()"
    );
    (void)(m12_tableX5FsizeX2E0Export7_growX2Dt3(&instance, 3u));
    assertEqualU32(
        m12_tableX5FsizeX2E0Export7_sizeX2Dt3(&instance),
        7u,
        "size-t3()"
    );
    (void)(m12_tableX5FsizeX2E0Export7_growX2Dt3(&instance, 0u));
    assertEqualU32(
        m12_tableX5FsizeX2E0Export7_sizeX2Dt3(&instance),
        7u,
        "size-t3()"
    );
    (void)(m12_tableX5FsizeX2E0Export7_growX2Dt3(&instance, 2u));
    assertEqualU32(
        m12_tableX5FsizeX2E0Export7_sizeX2Dt3(&instance),
        7u,
        "size-t3()"
    );
    (void)(m12_tableX5FsizeX2E0Export7_growX2Dt3(&instance, 1u));
    assertEqualU32(
        m12_tableX5FsizeX2E0Export7_sizeX2Dt3(&instance),
        8u,
        "size-t3()"
    );
    m12_tableX5FsizeX2E0FreeInstance(&instance);
}
