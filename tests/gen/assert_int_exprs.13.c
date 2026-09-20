
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_int_exprs.13.h"

void test() {
    m12_intX5FexprsX2E13Instance instance;
    m12_intX5FexprsX2E13Instantiate(&instance, resolveTestImports);
    printStart("int_exprs.13.wasm");
    assertEqualU32(
        m12_intX5FexprsX2E13Export11_i32X2EdivX5FsX5F5(&instance, 71u),
        14u,
        "i32.div_s_5(71u)"
    );
    assertEqualU32(
        m12_intX5FexprsX2E13Export11_i32X2EdivX5FsX5F5(&instance, 1342177280u),
        268435456u,
        "i32.div_s_5(1342177280u)"
    );
    assertEqualU32(
        m12_intX5FexprsX2E13Export11_i32X2EdivX5FuX5F5(&instance, 71u),
        14u,
        "i32.div_u_5(71u)"
    );
    assertEqualU32(
        m12_intX5FexprsX2E13Export11_i32X2EdivX5FuX5F5(&instance, 2684354560u),
        536870912u,
        "i32.div_u_5(2684354560u)"
    );
    assertEqualU64(
        m12_intX5FexprsX2E13Export11_i64X2EdivX5FsX5F5(&instance, 71ull),
        14ull,
        "i64.div_s_5(71ull)"
    );
    assertEqualU64(
        m12_intX5FexprsX2E13Export11_i64X2EdivX5FsX5F5(&instance, 5764607523034234880ull),
        1152921504606846976ull,
        "i64.div_s_5(5764607523034234880ull)"
    );
    assertEqualU64(
        m12_intX5FexprsX2E13Export11_i64X2EdivX5FuX5F5(&instance, 71ull),
        14ull,
        "i64.div_u_5(71ull)"
    );
    assertEqualU64(
        m12_intX5FexprsX2E13Export11_i64X2EdivX5FuX5F5(&instance, 11529215046068469760ull),
        2305843009213693952ull,
        "i64.div_u_5(11529215046068469760ull)"
    );
}
