
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_switch.0.h"

void test() {
    switch0Instance instance;
    switch0Instantiate(&instance, resolveTestImports);
    printStart("switch.0.wasm");
    assertEqualU32(
        switch0_stmt(&instance, 0u),
        0u,
        "stmt(0u)"
    );
    assertEqualU32(
        switch0_stmt(&instance, 1u),
        4294967295u,
        "stmt(1u)"
    );
    assertEqualU32(
        switch0_stmt(&instance, 2u),
        4294967294u,
        "stmt(2u)"
    );
    assertEqualU32(
        switch0_stmt(&instance, 3u),
        4294967293u,
        "stmt(3u)"
    );
    assertEqualU32(
        switch0_stmt(&instance, 4u),
        100u,
        "stmt(4u)"
    );
    assertEqualU32(
        switch0_stmt(&instance, 5u),
        101u,
        "stmt(5u)"
    );
    assertEqualU32(
        switch0_stmt(&instance, 6u),
        102u,
        "stmt(6u)"
    );
    assertEqualU32(
        switch0_stmt(&instance, 7u),
        100u,
        "stmt(7u)"
    );
    assertEqualU32(
        switch0_stmt(&instance, 4294967286u),
        102u,
        "stmt(4294967286u)"
    );
    assertEqualU64(
        switch0_expr(&instance, 0ull),
        0ull,
        "expr(0ull)"
    );
    assertEqualU64(
        switch0_expr(&instance, 1ull),
        18446744073709551615ull,
        "expr(1ull)"
    );
    assertEqualU64(
        switch0_expr(&instance, 2ull),
        18446744073709551614ull,
        "expr(2ull)"
    );
    assertEqualU64(
        switch0_expr(&instance, 3ull),
        18446744073709551613ull,
        "expr(3ull)"
    );
    assertEqualU64(
        switch0_expr(&instance, 6ull),
        101ull,
        "expr(6ull)"
    );
    assertEqualU64(
        switch0_expr(&instance, 7ull),
        18446744073709551611ull,
        "expr(7ull)"
    );
    assertEqualU64(
        switch0_expr(&instance, 18446744073709551606ull),
        100ull,
        "expr(18446744073709551606ull)"
    );
    assertEqualU32(
        switch0_arg(&instance, 0u),
        110u,
        "arg(0u)"
    );
    assertEqualU32(
        switch0_arg(&instance, 1u),
        12u,
        "arg(1u)"
    );
    assertEqualU32(
        switch0_arg(&instance, 2u),
        4u,
        "arg(2u)"
    );
    assertEqualU32(
        switch0_arg(&instance, 3u),
        1116u,
        "arg(3u)"
    );
    assertEqualU32(
        switch0_arg(&instance, 4u),
        118u,
        "arg(4u)"
    );
    assertEqualU32(
        switch0_arg(&instance, 5u),
        20u,
        "arg(5u)"
    );
    assertEqualU32(
        switch0_arg(&instance, 6u),
        12u,
        "arg(6u)"
    );
    assertEqualU32(
        switch0_arg(&instance, 7u),
        1124u,
        "arg(7u)"
    );
    assertEqualU32(
        switch0_arg(&instance, 8u),
        126u,
        "arg(8u)"
    );
    assertEqualU32(
        switch0_corner(&instance),
        1u,
        "corner()"
    );
}
