
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_int_exprs.12.h"

void test() {
    m12_intX5FexprsX2E12Instance instance;
    m12_intX5FexprsX2E12Instantiate(&instance, resolveTestImports);
    printStart("int_exprs.12.wasm");
    assertEqualU32(
        m12_intX5FexprsX2E12Export11_i32X2EdivX5FsX5F3(&instance, 71u),
        23u,
        "i32.div_s_3(71u)"
    );
    assertEqualU32(
        m12_intX5FexprsX2E12Export11_i32X2EdivX5FsX5F3(&instance, 1610612736u),
        536870912u,
        "i32.div_s_3(1610612736u)"
    );
    assertEqualU32(
        m12_intX5FexprsX2E12Export11_i32X2EdivX5FuX5F3(&instance, 71u),
        23u,
        "i32.div_u_3(71u)"
    );
    assertEqualU32(
        m12_intX5FexprsX2E12Export11_i32X2EdivX5FuX5F3(&instance, 3221225472u),
        1073741824u,
        "i32.div_u_3(3221225472u)"
    );
    assertEqualU64(
        m12_intX5FexprsX2E12Export11_i64X2EdivX5FsX5F3(&instance, 71ull),
        23ull,
        "i64.div_s_3(71ull)"
    );
    assertEqualU64(
        m12_intX5FexprsX2E12Export11_i64X2EdivX5FsX5F3(&instance, 3458764513820540928ull),
        1152921504606846976ull,
        "i64.div_s_3(3458764513820540928ull)"
    );
    assertEqualU64(
        m12_intX5FexprsX2E12Export11_i64X2EdivX5FuX5F3(&instance, 71ull),
        23ull,
        "i64.div_u_3(71ull)"
    );
    assertEqualU64(
        m12_intX5FexprsX2E12Export11_i64X2EdivX5FuX5F3(&instance, 13835058055282163712ull),
        4611686018427387904ull,
        "i64.div_u_3(13835058055282163712ull)"
    );
}
