
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_i32.0.h"

void test() {
    i320Instance instance;
    i320Instantiate(&instance, resolveTestImports);
    printStart("i32.0.wasm");
    assertEqualU32(
        i320_add(&instance, 1u, 1u),
        2u,
        "add(1u, 1u)"
    );
    assertEqualU32(
        i320_add(&instance, 1u, 0u),
        1u,
        "add(1u, 0u)"
    );
    assertEqualU32(
        i320_add(&instance, 4294967295u, 4294967295u),
        4294967294u,
        "add(4294967295u, 4294967295u)"
    );
    assertEqualU32(
        i320_add(&instance, 4294967295u, 1u),
        0u,
        "add(4294967295u, 1u)"
    );
    assertEqualU32(
        i320_add(&instance, 2147483647u, 1u),
        2147483648u,
        "add(2147483647u, 1u)"
    );
    assertEqualU32(
        i320_add(&instance, 2147483648u, 4294967295u),
        2147483647u,
        "add(2147483648u, 4294967295u)"
    );
    assertEqualU32(
        i320_add(&instance, 2147483648u, 2147483648u),
        0u,
        "add(2147483648u, 2147483648u)"
    );
    assertEqualU32(
        i320_add(&instance, 1073741823u, 1u),
        1073741824u,
        "add(1073741823u, 1u)"
    );
    assertEqualU32(
        i320_sub(&instance, 1u, 1u),
        0u,
        "sub(1u, 1u)"
    );
    assertEqualU32(
        i320_sub(&instance, 1u, 0u),
        1u,
        "sub(1u, 0u)"
    );
    assertEqualU32(
        i320_sub(&instance, 4294967295u, 4294967295u),
        0u,
        "sub(4294967295u, 4294967295u)"
    );
    assertEqualU32(
        i320_sub(&instance, 2147483647u, 4294967295u),
        2147483648u,
        "sub(2147483647u, 4294967295u)"
    );
    assertEqualU32(
        i320_sub(&instance, 2147483648u, 1u),
        2147483647u,
        "sub(2147483648u, 1u)"
    );
    assertEqualU32(
        i320_sub(&instance, 2147483648u, 2147483648u),
        0u,
        "sub(2147483648u, 2147483648u)"
    );
    assertEqualU32(
        i320_sub(&instance, 1073741823u, 4294967295u),
        1073741824u,
        "sub(1073741823u, 4294967295u)"
    );
    assertEqualU32(
        i320_mul(&instance, 1u, 1u),
        1u,
        "mul(1u, 1u)"
    );
    assertEqualU32(
        i320_mul(&instance, 1u, 0u),
        0u,
        "mul(1u, 0u)"
    );
    assertEqualU32(
        i320_mul(&instance, 4294967295u, 4294967295u),
        1u,
        "mul(4294967295u, 4294967295u)"
    );
    assertEqualU32(
        i320_mul(&instance, 268435456u, 4096u),
        0u,
        "mul(268435456u, 4096u)"
    );
    assertEqualU32(
        i320_mul(&instance, 2147483648u, 0u),
        0u,
        "mul(2147483648u, 0u)"
    );
    assertEqualU32(
        i320_mul(&instance, 2147483648u, 4294967295u),
        2147483648u,
        "mul(2147483648u, 4294967295u)"
    );
    assertEqualU32(
        i320_mul(&instance, 2147483647u, 4294967295u),
        2147483649u,
        "mul(2147483647u, 4294967295u)"
    );
    assertEqualU32(
        i320_mul(&instance, 19088743u, 1985229328u),
        898528368u,
        "mul(19088743u, 1985229328u)"
    );
    assertEqualU32(
        i320_mul(&instance, 2147483647u, 2147483647u),
        1u,
        "mul(2147483647u, 2147483647u)"
    );
    assertEqualU32(
        i320_divX5Fs(&instance, 1u, 1u),
        1u,
        "div_s(1u, 1u)"
    );
    assertEqualU32(
        i320_divX5Fs(&instance, 0u, 1u),
        0u,
        "div_s(0u, 1u)"
    );
    assertEqualU32(
        i320_divX5Fs(&instance, 0u, 4294967295u),
        0u,
        "div_s(0u, 4294967295u)"
    );
    assertEqualU32(
        i320_divX5Fs(&instance, 4294967295u, 4294967295u),
        1u,
        "div_s(4294967295u, 4294967295u)"
    );
    assertEqualU32(
        i320_divX5Fs(&instance, 2147483648u, 2u),
        3221225472u,
        "div_s(2147483648u, 2u)"
    );
    assertEqualU32(
        i320_divX5Fs(&instance, 2147483649u, 1000u),
        4292819813u,
        "div_s(2147483649u, 1000u)"
    );
    assertEqualU32(
        i320_divX5Fs(&instance, 5u, 2u),
        2u,
        "div_s(5u, 2u)"
    );
    assertEqualU32(
        i320_divX5Fs(&instance, 4294967291u, 2u),
        4294967294u,
        "div_s(4294967291u, 2u)"
    );
    assertEqualU32(
        i320_divX5Fs(&instance, 5u, 4294967294u),
        4294967294u,
        "div_s(5u, 4294967294u)"
    );
    assertEqualU32(
        i320_divX5Fs(&instance, 4294967291u, 4294967294u),
        2u,
        "div_s(4294967291u, 4294967294u)"
    );
    assertEqualU32(
        i320_divX5Fs(&instance, 7u, 3u),
        2u,
        "div_s(7u, 3u)"
    );
    assertEqualU32(
        i320_divX5Fs(&instance, 4294967289u, 3u),
        4294967294u,
        "div_s(4294967289u, 3u)"
    );
    assertEqualU32(
        i320_divX5Fs(&instance, 7u, 4294967293u),
        4294967294u,
        "div_s(7u, 4294967293u)"
    );
    assertEqualU32(
        i320_divX5Fs(&instance, 4294967289u, 4294967293u),
        2u,
        "div_s(4294967289u, 4294967293u)"
    );
    assertEqualU32(
        i320_divX5Fs(&instance, 11u, 5u),
        2u,
        "div_s(11u, 5u)"
    );
    assertEqualU32(
        i320_divX5Fs(&instance, 17u, 7u),
        2u,
        "div_s(17u, 7u)"
    );
    assertEqualU32(
        i320_divX5Fu(&instance, 1u, 1u),
        1u,
        "div_u(1u, 1u)"
    );
    assertEqualU32(
        i320_divX5Fu(&instance, 0u, 1u),
        0u,
        "div_u(0u, 1u)"
    );
    assertEqualU32(
        i320_divX5Fu(&instance, 4294967295u, 4294967295u),
        1u,
        "div_u(4294967295u, 4294967295u)"
    );
    assertEqualU32(
        i320_divX5Fu(&instance, 2147483648u, 4294967295u),
        0u,
        "div_u(2147483648u, 4294967295u)"
    );
    assertEqualU32(
        i320_divX5Fu(&instance, 2147483648u, 2u),
        1073741824u,
        "div_u(2147483648u, 2u)"
    );
    assertEqualU32(
        i320_divX5Fu(&instance, 2414874608u, 65537u),
        36847u,
        "div_u(2414874608u, 65537u)"
    );
    assertEqualU32(
        i320_divX5Fu(&instance, 2147483649u, 1000u),
        2147483u,
        "div_u(2147483649u, 1000u)"
    );
    assertEqualU32(
        i320_divX5Fu(&instance, 5u, 2u),
        2u,
        "div_u(5u, 2u)"
    );
    assertEqualU32(
        i320_divX5Fu(&instance, 4294967291u, 2u),
        2147483645u,
        "div_u(4294967291u, 2u)"
    );
    assertEqualU32(
        i320_divX5Fu(&instance, 5u, 4294967294u),
        0u,
        "div_u(5u, 4294967294u)"
    );
    assertEqualU32(
        i320_divX5Fu(&instance, 4294967291u, 4294967294u),
        0u,
        "div_u(4294967291u, 4294967294u)"
    );
    assertEqualU32(
        i320_divX5Fu(&instance, 7u, 3u),
        2u,
        "div_u(7u, 3u)"
    );
    assertEqualU32(
        i320_divX5Fu(&instance, 11u, 5u),
        2u,
        "div_u(11u, 5u)"
    );
    assertEqualU32(
        i320_divX5Fu(&instance, 17u, 7u),
        2u,
        "div_u(17u, 7u)"
    );
    assertEqualU32(
        i320_remX5Fs(&instance, 2147483647u, 4294967295u),
        0u,
        "rem_s(2147483647u, 4294967295u)"
    );
    assertEqualU32(
        i320_remX5Fs(&instance, 1u, 1u),
        0u,
        "rem_s(1u, 1u)"
    );
    assertEqualU32(
        i320_remX5Fs(&instance, 0u, 1u),
        0u,
        "rem_s(0u, 1u)"
    );
    assertEqualU32(
        i320_remX5Fs(&instance, 0u, 4294967295u),
        0u,
        "rem_s(0u, 4294967295u)"
    );
    assertEqualU32(
        i320_remX5Fs(&instance, 4294967295u, 4294967295u),
        0u,
        "rem_s(4294967295u, 4294967295u)"
    );
    assertEqualU32(
        i320_remX5Fs(&instance, 2147483648u, 4294967295u),
        0u,
        "rem_s(2147483648u, 4294967295u)"
    );
    assertEqualU32(
        i320_remX5Fs(&instance, 2147483648u, 2u),
        0u,
        "rem_s(2147483648u, 2u)"
    );
    assertEqualU32(
        i320_remX5Fs(&instance, 2147483649u, 1000u),
        4294966649u,
        "rem_s(2147483649u, 1000u)"
    );
    assertEqualU32(
        i320_remX5Fs(&instance, 5u, 2u),
        1u,
        "rem_s(5u, 2u)"
    );
    assertEqualU32(
        i320_remX5Fs(&instance, 4294967291u, 2u),
        4294967295u,
        "rem_s(4294967291u, 2u)"
    );
    assertEqualU32(
        i320_remX5Fs(&instance, 5u, 4294967294u),
        1u,
        "rem_s(5u, 4294967294u)"
    );
    assertEqualU32(
        i320_remX5Fs(&instance, 4294967291u, 4294967294u),
        4294967295u,
        "rem_s(4294967291u, 4294967294u)"
    );
    assertEqualU32(
        i320_remX5Fs(&instance, 7u, 3u),
        1u,
        "rem_s(7u, 3u)"
    );
    assertEqualU32(
        i320_remX5Fs(&instance, 4294967289u, 3u),
        4294967295u,
        "rem_s(4294967289u, 3u)"
    );
    assertEqualU32(
        i320_remX5Fs(&instance, 7u, 4294967293u),
        1u,
        "rem_s(7u, 4294967293u)"
    );
    assertEqualU32(
        i320_remX5Fs(&instance, 4294967289u, 4294967293u),
        4294967295u,
        "rem_s(4294967289u, 4294967293u)"
    );
    assertEqualU32(
        i320_remX5Fs(&instance, 11u, 5u),
        1u,
        "rem_s(11u, 5u)"
    );
    assertEqualU32(
        i320_remX5Fs(&instance, 17u, 7u),
        3u,
        "rem_s(17u, 7u)"
    );
    assertEqualU32(
        i320_remX5Fu(&instance, 1u, 1u),
        0u,
        "rem_u(1u, 1u)"
    );
    assertEqualU32(
        i320_remX5Fu(&instance, 0u, 1u),
        0u,
        "rem_u(0u, 1u)"
    );
    assertEqualU32(
        i320_remX5Fu(&instance, 4294967295u, 4294967295u),
        0u,
        "rem_u(4294967295u, 4294967295u)"
    );
    assertEqualU32(
        i320_remX5Fu(&instance, 2147483648u, 4294967295u),
        2147483648u,
        "rem_u(2147483648u, 4294967295u)"
    );
    assertEqualU32(
        i320_remX5Fu(&instance, 2147483648u, 2u),
        0u,
        "rem_u(2147483648u, 2u)"
    );
    assertEqualU32(
        i320_remX5Fu(&instance, 2414874608u, 65537u),
        32769u,
        "rem_u(2414874608u, 65537u)"
    );
    assertEqualU32(
        i320_remX5Fu(&instance, 2147483649u, 1000u),
        649u,
        "rem_u(2147483649u, 1000u)"
    );
    assertEqualU32(
        i320_remX5Fu(&instance, 5u, 2u),
        1u,
        "rem_u(5u, 2u)"
    );
    assertEqualU32(
        i320_remX5Fu(&instance, 4294967291u, 2u),
        1u,
        "rem_u(4294967291u, 2u)"
    );
    assertEqualU32(
        i320_remX5Fu(&instance, 5u, 4294967294u),
        5u,
        "rem_u(5u, 4294967294u)"
    );
    assertEqualU32(
        i320_remX5Fu(&instance, 4294967291u, 4294967294u),
        4294967291u,
        "rem_u(4294967291u, 4294967294u)"
    );
    assertEqualU32(
        i320_remX5Fu(&instance, 7u, 3u),
        1u,
        "rem_u(7u, 3u)"
    );
    assertEqualU32(
        i320_remX5Fu(&instance, 11u, 5u),
        1u,
        "rem_u(11u, 5u)"
    );
    assertEqualU32(
        i320_remX5Fu(&instance, 17u, 7u),
        3u,
        "rem_u(17u, 7u)"
    );
    assertEqualU32(
        i320_and(&instance, 1u, 0u),
        0u,
        "and(1u, 0u)"
    );
    assertEqualU32(
        i320_and(&instance, 0u, 1u),
        0u,
        "and(0u, 1u)"
    );
    assertEqualU32(
        i320_and(&instance, 1u, 1u),
        1u,
        "and(1u, 1u)"
    );
    assertEqualU32(
        i320_and(&instance, 0u, 0u),
        0u,
        "and(0u, 0u)"
    );
    assertEqualU32(
        i320_and(&instance, 2147483647u, 2147483648u),
        0u,
        "and(2147483647u, 2147483648u)"
    );
    assertEqualU32(
        i320_and(&instance, 2147483647u, 4294967295u),
        2147483647u,
        "and(2147483647u, 4294967295u)"
    );
    assertEqualU32(
        i320_and(&instance, 4042326015u, 4294963440u),
        4042322160u,
        "and(4042326015u, 4294963440u)"
    );
    assertEqualU32(
        i320_and(&instance, 4294967295u, 4294967295u),
        4294967295u,
        "and(4294967295u, 4294967295u)"
    );
    assertEqualU32(
        i320_or(&instance, 1u, 0u),
        1u,
        "or(1u, 0u)"
    );
    assertEqualU32(
        i320_or(&instance, 0u, 1u),
        1u,
        "or(0u, 1u)"
    );
    assertEqualU32(
        i320_or(&instance, 1u, 1u),
        1u,
        "or(1u, 1u)"
    );
    assertEqualU32(
        i320_or(&instance, 0u, 0u),
        0u,
        "or(0u, 0u)"
    );
    assertEqualU32(
        i320_or(&instance, 2147483647u, 2147483648u),
        4294967295u,
        "or(2147483647u, 2147483648u)"
    );
    assertEqualU32(
        i320_or(&instance, 2147483648u, 0u),
        2147483648u,
        "or(2147483648u, 0u)"
    );
    assertEqualU32(
        i320_or(&instance, 4042326015u, 4294963440u),
        4294967295u,
        "or(4042326015u, 4294963440u)"
    );
    assertEqualU32(
        i320_or(&instance, 4294967295u, 4294967295u),
        4294967295u,
        "or(4294967295u, 4294967295u)"
    );
    assertEqualU32(
        i320_xor(&instance, 1u, 0u),
        1u,
        "xor(1u, 0u)"
    );
    assertEqualU32(
        i320_xor(&instance, 0u, 1u),
        1u,
        "xor(0u, 1u)"
    );
    assertEqualU32(
        i320_xor(&instance, 1u, 1u),
        0u,
        "xor(1u, 1u)"
    );
    assertEqualU32(
        i320_xor(&instance, 0u, 0u),
        0u,
        "xor(0u, 0u)"
    );
    assertEqualU32(
        i320_xor(&instance, 2147483647u, 2147483648u),
        4294967295u,
        "xor(2147483647u, 2147483648u)"
    );
    assertEqualU32(
        i320_xor(&instance, 2147483648u, 0u),
        2147483648u,
        "xor(2147483648u, 0u)"
    );
    assertEqualU32(
        i320_xor(&instance, 4294967295u, 2147483648u),
        2147483647u,
        "xor(4294967295u, 2147483648u)"
    );
    assertEqualU32(
        i320_xor(&instance, 4294967295u, 2147483647u),
        2147483648u,
        "xor(4294967295u, 2147483647u)"
    );
    assertEqualU32(
        i320_xor(&instance, 4042326015u, 4294963440u),
        252645135u,
        "xor(4042326015u, 4294963440u)"
    );
    assertEqualU32(
        i320_xor(&instance, 4294967295u, 4294967295u),
        0u,
        "xor(4294967295u, 4294967295u)"
    );
    assertEqualU32(
        i320_shl(&instance, 1u, 1u),
        2u,
        "shl(1u, 1u)"
    );
    assertEqualU32(
        i320_shl(&instance, 1u, 0u),
        1u,
        "shl(1u, 0u)"
    );
    assertEqualU32(
        i320_shl(&instance, 2147483647u, 1u),
        4294967294u,
        "shl(2147483647u, 1u)"
    );
    assertEqualU32(
        i320_shl(&instance, 4294967295u, 1u),
        4294967294u,
        "shl(4294967295u, 1u)"
    );
    assertEqualU32(
        i320_shl(&instance, 2147483648u, 1u),
        0u,
        "shl(2147483648u, 1u)"
    );
    assertEqualU32(
        i320_shl(&instance, 1073741824u, 1u),
        2147483648u,
        "shl(1073741824u, 1u)"
    );
    assertEqualU32(
        i320_shl(&instance, 1u, 31u),
        2147483648u,
        "shl(1u, 31u)"
    );
    assertEqualU32(
        i320_shl(&instance, 1u, 32u),
        1u,
        "shl(1u, 32u)"
    );
    assertEqualU32(
        i320_shl(&instance, 1u, 33u),
        2u,
        "shl(1u, 33u)"
    );
    assertEqualU32(
        i320_shl(&instance, 1u, 4294967295u),
        2147483648u,
        "shl(1u, 4294967295u)"
    );
    assertEqualU32(
        i320_shl(&instance, 1u, 2147483647u),
        2147483648u,
        "shl(1u, 2147483647u)"
    );
    assertEqualU32(
        i320_shrX5Fs(&instance, 1u, 1u),
        0u,
        "shr_s(1u, 1u)"
    );
    assertEqualU32(
        i320_shrX5Fs(&instance, 1u, 0u),
        1u,
        "shr_s(1u, 0u)"
    );
    assertEqualU32(
        i320_shrX5Fs(&instance, 4294967295u, 1u),
        4294967295u,
        "shr_s(4294967295u, 1u)"
    );
    assertEqualU32(
        i320_shrX5Fs(&instance, 2147483647u, 1u),
        1073741823u,
        "shr_s(2147483647u, 1u)"
    );
    assertEqualU32(
        i320_shrX5Fs(&instance, 2147483648u, 1u),
        3221225472u,
        "shr_s(2147483648u, 1u)"
    );
    assertEqualU32(
        i320_shrX5Fs(&instance, 1073741824u, 1u),
        536870912u,
        "shr_s(1073741824u, 1u)"
    );
    assertEqualU32(
        i320_shrX5Fs(&instance, 1u, 32u),
        1u,
        "shr_s(1u, 32u)"
    );
    assertEqualU32(
        i320_shrX5Fs(&instance, 1u, 33u),
        0u,
        "shr_s(1u, 33u)"
    );
    assertEqualU32(
        i320_shrX5Fs(&instance, 1u, 4294967295u),
        0u,
        "shr_s(1u, 4294967295u)"
    );
    assertEqualU32(
        i320_shrX5Fs(&instance, 1u, 2147483647u),
        0u,
        "shr_s(1u, 2147483647u)"
    );
    assertEqualU32(
        i320_shrX5Fs(&instance, 1u, 2147483648u),
        1u,
        "shr_s(1u, 2147483648u)"
    );
    assertEqualU32(
        i320_shrX5Fs(&instance, 2147483648u, 31u),
        4294967295u,
        "shr_s(2147483648u, 31u)"
    );
    assertEqualU32(
        i320_shrX5Fs(&instance, 4294967295u, 32u),
        4294967295u,
        "shr_s(4294967295u, 32u)"
    );
    assertEqualU32(
        i320_shrX5Fs(&instance, 4294967295u, 33u),
        4294967295u,
        "shr_s(4294967295u, 33u)"
    );
    assertEqualU32(
        i320_shrX5Fs(&instance, 4294967295u, 4294967295u),
        4294967295u,
        "shr_s(4294967295u, 4294967295u)"
    );
    assertEqualU32(
        i320_shrX5Fs(&instance, 4294967295u, 2147483647u),
        4294967295u,
        "shr_s(4294967295u, 2147483647u)"
    );
    assertEqualU32(
        i320_shrX5Fs(&instance, 4294967295u, 2147483648u),
        4294967295u,
        "shr_s(4294967295u, 2147483648u)"
    );
    assertEqualU32(
        i320_shrX5Fu(&instance, 1u, 1u),
        0u,
        "shr_u(1u, 1u)"
    );
    assertEqualU32(
        i320_shrX5Fu(&instance, 1u, 0u),
        1u,
        "shr_u(1u, 0u)"
    );
    assertEqualU32(
        i320_shrX5Fu(&instance, 4294967295u, 1u),
        2147483647u,
        "shr_u(4294967295u, 1u)"
    );
    assertEqualU32(
        i320_shrX5Fu(&instance, 2147483647u, 1u),
        1073741823u,
        "shr_u(2147483647u, 1u)"
    );
    assertEqualU32(
        i320_shrX5Fu(&instance, 2147483648u, 1u),
        1073741824u,
        "shr_u(2147483648u, 1u)"
    );
    assertEqualU32(
        i320_shrX5Fu(&instance, 1073741824u, 1u),
        536870912u,
        "shr_u(1073741824u, 1u)"
    );
    assertEqualU32(
        i320_shrX5Fu(&instance, 1u, 32u),
        1u,
        "shr_u(1u, 32u)"
    );
    assertEqualU32(
        i320_shrX5Fu(&instance, 1u, 33u),
        0u,
        "shr_u(1u, 33u)"
    );
    assertEqualU32(
        i320_shrX5Fu(&instance, 1u, 4294967295u),
        0u,
        "shr_u(1u, 4294967295u)"
    );
    assertEqualU32(
        i320_shrX5Fu(&instance, 1u, 2147483647u),
        0u,
        "shr_u(1u, 2147483647u)"
    );
    assertEqualU32(
        i320_shrX5Fu(&instance, 1u, 2147483648u),
        1u,
        "shr_u(1u, 2147483648u)"
    );
    assertEqualU32(
        i320_shrX5Fu(&instance, 2147483648u, 31u),
        1u,
        "shr_u(2147483648u, 31u)"
    );
    assertEqualU32(
        i320_shrX5Fu(&instance, 4294967295u, 32u),
        4294967295u,
        "shr_u(4294967295u, 32u)"
    );
    assertEqualU32(
        i320_shrX5Fu(&instance, 4294967295u, 33u),
        2147483647u,
        "shr_u(4294967295u, 33u)"
    );
    assertEqualU32(
        i320_shrX5Fu(&instance, 4294967295u, 4294967295u),
        1u,
        "shr_u(4294967295u, 4294967295u)"
    );
    assertEqualU32(
        i320_shrX5Fu(&instance, 4294967295u, 2147483647u),
        1u,
        "shr_u(4294967295u, 2147483647u)"
    );
    assertEqualU32(
        i320_shrX5Fu(&instance, 4294967295u, 2147483648u),
        4294967295u,
        "shr_u(4294967295u, 2147483648u)"
    );
    assertEqualU32(
        i320_rotl(&instance, 1u, 1u),
        2u,
        "rotl(1u, 1u)"
    );
    assertEqualU32(
        i320_rotl(&instance, 1u, 0u),
        1u,
        "rotl(1u, 0u)"
    );
    assertEqualU32(
        i320_rotl(&instance, 4294967295u, 1u),
        4294967295u,
        "rotl(4294967295u, 1u)"
    );
    assertEqualU32(
        i320_rotl(&instance, 1u, 32u),
        1u,
        "rotl(1u, 32u)"
    );
    assertEqualU32(
        i320_rotl(&instance, 2882377846u, 1u),
        1469788397u,
        "rotl(2882377846u, 1u)"
    );
    assertEqualU32(
        i320_rotl(&instance, 4261469184u, 4u),
        3758997519u,
        "rotl(4261469184u, 4u)"
    );
    assertEqualU32(
        i320_rotl(&instance, 2965492451u, 5u),
        406477942u,
        "rotl(2965492451u, 5u)"
    );
    assertEqualU32(
        i320_rotl(&instance, 32768u, 37u),
        1048576u,
        "rotl(32768u, 37u)"
    );
    assertEqualU32(
        i320_rotl(&instance, 2965492451u, 65285u),
        406477942u,
        "rotl(2965492451u, 65285u)"
    );
    assertEqualU32(
        i320_rotl(&instance, 1989852383u, 4294967277u),
        1469837011u,
        "rotl(1989852383u, 4294967277u)"
    );
    assertEqualU32(
        i320_rotl(&instance, 1989852383u, 2147483661u),
        1469837011u,
        "rotl(1989852383u, 2147483661u)"
    );
    assertEqualU32(
        i320_rotl(&instance, 1u, 31u),
        2147483648u,
        "rotl(1u, 31u)"
    );
    assertEqualU32(
        i320_rotl(&instance, 2147483648u, 1u),
        1u,
        "rotl(2147483648u, 1u)"
    );
    assertEqualU32(
        i320_rotr(&instance, 1u, 1u),
        2147483648u,
        "rotr(1u, 1u)"
    );
    assertEqualU32(
        i320_rotr(&instance, 1u, 0u),
        1u,
        "rotr(1u, 0u)"
    );
    assertEqualU32(
        i320_rotr(&instance, 4294967295u, 1u),
        4294967295u,
        "rotr(4294967295u, 1u)"
    );
    assertEqualU32(
        i320_rotr(&instance, 1u, 32u),
        1u,
        "rotr(1u, 32u)"
    );
    assertEqualU32(
        i320_rotr(&instance, 4278242304u, 1u),
        2139121152u,
        "rotr(4278242304u, 1u)"
    );
    assertEqualU32(
        i320_rotr(&instance, 524288u, 4u),
        32768u,
        "rotr(524288u, 4u)"
    );
    assertEqualU32(
        i320_rotr(&instance, 2965492451u, 5u),
        495324823u,
        "rotr(2965492451u, 5u)"
    );
    assertEqualU32(
        i320_rotr(&instance, 32768u, 37u),
        1024u,
        "rotr(32768u, 37u)"
    );
    assertEqualU32(
        i320_rotr(&instance, 2965492451u, 65285u),
        495324823u,
        "rotr(2965492451u, 65285u)"
    );
    assertEqualU32(
        i320_rotr(&instance, 1989852383u, 4294967277u),
        3875255509u,
        "rotr(1989852383u, 4294967277u)"
    );
    assertEqualU32(
        i320_rotr(&instance, 1989852383u, 2147483661u),
        3875255509u,
        "rotr(1989852383u, 2147483661u)"
    );
    assertEqualU32(
        i320_rotr(&instance, 1u, 31u),
        2u,
        "rotr(1u, 31u)"
    );
    assertEqualU32(
        i320_rotr(&instance, 2147483648u, 31u),
        1u,
        "rotr(2147483648u, 31u)"
    );
    assertEqualU32(
        i320_clz(&instance, 4294967295u),
        0u,
        "clz(4294967295u)"
    );
    assertEqualU32(
        i320_clz(&instance, 0u),
        32u,
        "clz(0u)"
    );
    assertEqualU32(
        i320_clz(&instance, 32768u),
        16u,
        "clz(32768u)"
    );
    assertEqualU32(
        i320_clz(&instance, 255u),
        24u,
        "clz(255u)"
    );
    assertEqualU32(
        i320_clz(&instance, 2147483648u),
        0u,
        "clz(2147483648u)"
    );
    assertEqualU32(
        i320_clz(&instance, 1u),
        31u,
        "clz(1u)"
    );
    assertEqualU32(
        i320_clz(&instance, 2u),
        30u,
        "clz(2u)"
    );
    assertEqualU32(
        i320_clz(&instance, 2147483647u),
        1u,
        "clz(2147483647u)"
    );
    assertEqualU32(
        i320_ctz(&instance, 4294967295u),
        0u,
        "ctz(4294967295u)"
    );
    assertEqualU32(
        i320_ctz(&instance, 0u),
        32u,
        "ctz(0u)"
    );
    assertEqualU32(
        i320_ctz(&instance, 32768u),
        15u,
        "ctz(32768u)"
    );
    assertEqualU32(
        i320_ctz(&instance, 65536u),
        16u,
        "ctz(65536u)"
    );
    assertEqualU32(
        i320_ctz(&instance, 2147483648u),
        31u,
        "ctz(2147483648u)"
    );
    assertEqualU32(
        i320_ctz(&instance, 2147483647u),
        0u,
        "ctz(2147483647u)"
    );
    assertEqualU32(
        i320_popcnt(&instance, 4294967295u),
        32u,
        "popcnt(4294967295u)"
    );
    assertEqualU32(
        i320_popcnt(&instance, 0u),
        0u,
        "popcnt(0u)"
    );
    assertEqualU32(
        i320_popcnt(&instance, 32768u),
        1u,
        "popcnt(32768u)"
    );
    assertEqualU32(
        i320_popcnt(&instance, 2147516416u),
        2u,
        "popcnt(2147516416u)"
    );
    assertEqualU32(
        i320_popcnt(&instance, 2147483647u),
        31u,
        "popcnt(2147483647u)"
    );
    assertEqualU32(
        i320_popcnt(&instance, 2863311530u),
        16u,
        "popcnt(2863311530u)"
    );
    assertEqualU32(
        i320_popcnt(&instance, 1431655765u),
        16u,
        "popcnt(1431655765u)"
    );
    assertEqualU32(
        i320_popcnt(&instance, 3735928559u),
        24u,
        "popcnt(3735928559u)"
    );
    assertEqualU32(
        i320_eqz(&instance, 0u),
        1u,
        "eqz(0u)"
    );
    assertEqualU32(
        i320_eqz(&instance, 1u),
        0u,
        "eqz(1u)"
    );
    assertEqualU32(
        i320_eqz(&instance, 2147483648u),
        0u,
        "eqz(2147483648u)"
    );
    assertEqualU32(
        i320_eqz(&instance, 2147483647u),
        0u,
        "eqz(2147483647u)"
    );
    assertEqualU32(
        i320_eqz(&instance, 4294967295u),
        0u,
        "eqz(4294967295u)"
    );
    assertEqualU32(
        i320_eq(&instance, 0u, 0u),
        1u,
        "eq(0u, 0u)"
    );
    assertEqualU32(
        i320_eq(&instance, 1u, 1u),
        1u,
        "eq(1u, 1u)"
    );
    assertEqualU32(
        i320_eq(&instance, 4294967295u, 1u),
        0u,
        "eq(4294967295u, 1u)"
    );
    assertEqualU32(
        i320_eq(&instance, 2147483648u, 2147483648u),
        1u,
        "eq(2147483648u, 2147483648u)"
    );
    assertEqualU32(
        i320_eq(&instance, 2147483647u, 2147483647u),
        1u,
        "eq(2147483647u, 2147483647u)"
    );
    assertEqualU32(
        i320_eq(&instance, 4294967295u, 4294967295u),
        1u,
        "eq(4294967295u, 4294967295u)"
    );
    assertEqualU32(
        i320_eq(&instance, 1u, 0u),
        0u,
        "eq(1u, 0u)"
    );
    assertEqualU32(
        i320_eq(&instance, 0u, 1u),
        0u,
        "eq(0u, 1u)"
    );
    assertEqualU32(
        i320_eq(&instance, 2147483648u, 0u),
        0u,
        "eq(2147483648u, 0u)"
    );
    assertEqualU32(
        i320_eq(&instance, 0u, 2147483648u),
        0u,
        "eq(0u, 2147483648u)"
    );
    assertEqualU32(
        i320_eq(&instance, 2147483648u, 4294967295u),
        0u,
        "eq(2147483648u, 4294967295u)"
    );
    assertEqualU32(
        i320_eq(&instance, 4294967295u, 2147483648u),
        0u,
        "eq(4294967295u, 2147483648u)"
    );
    assertEqualU32(
        i320_eq(&instance, 2147483648u, 2147483647u),
        0u,
        "eq(2147483648u, 2147483647u)"
    );
    assertEqualU32(
        i320_eq(&instance, 2147483647u, 2147483648u),
        0u,
        "eq(2147483647u, 2147483648u)"
    );
    assertEqualU32(
        i320_ne(&instance, 0u, 0u),
        0u,
        "ne(0u, 0u)"
    );
    assertEqualU32(
        i320_ne(&instance, 1u, 1u),
        0u,
        "ne(1u, 1u)"
    );
    assertEqualU32(
        i320_ne(&instance, 4294967295u, 1u),
        1u,
        "ne(4294967295u, 1u)"
    );
    assertEqualU32(
        i320_ne(&instance, 2147483648u, 2147483648u),
        0u,
        "ne(2147483648u, 2147483648u)"
    );
    assertEqualU32(
        i320_ne(&instance, 2147483647u, 2147483647u),
        0u,
        "ne(2147483647u, 2147483647u)"
    );
    assertEqualU32(
        i320_ne(&instance, 4294967295u, 4294967295u),
        0u,
        "ne(4294967295u, 4294967295u)"
    );
    assertEqualU32(
        i320_ne(&instance, 1u, 0u),
        1u,
        "ne(1u, 0u)"
    );
    assertEqualU32(
        i320_ne(&instance, 0u, 1u),
        1u,
        "ne(0u, 1u)"
    );
    assertEqualU32(
        i320_ne(&instance, 2147483648u, 0u),
        1u,
        "ne(2147483648u, 0u)"
    );
    assertEqualU32(
        i320_ne(&instance, 0u, 2147483648u),
        1u,
        "ne(0u, 2147483648u)"
    );
    assertEqualU32(
        i320_ne(&instance, 2147483648u, 4294967295u),
        1u,
        "ne(2147483648u, 4294967295u)"
    );
    assertEqualU32(
        i320_ne(&instance, 4294967295u, 2147483648u),
        1u,
        "ne(4294967295u, 2147483648u)"
    );
    assertEqualU32(
        i320_ne(&instance, 2147483648u, 2147483647u),
        1u,
        "ne(2147483648u, 2147483647u)"
    );
    assertEqualU32(
        i320_ne(&instance, 2147483647u, 2147483648u),
        1u,
        "ne(2147483647u, 2147483648u)"
    );
    assertEqualU32(
        i320_ltX5Fs(&instance, 0u, 0u),
        0u,
        "lt_s(0u, 0u)"
    );
    assertEqualU32(
        i320_ltX5Fs(&instance, 1u, 1u),
        0u,
        "lt_s(1u, 1u)"
    );
    assertEqualU32(
        i320_ltX5Fs(&instance, 4294967295u, 1u),
        1u,
        "lt_s(4294967295u, 1u)"
    );
    assertEqualU32(
        i320_ltX5Fs(&instance, 2147483648u, 2147483648u),
        0u,
        "lt_s(2147483648u, 2147483648u)"
    );
    assertEqualU32(
        i320_ltX5Fs(&instance, 2147483647u, 2147483647u),
        0u,
        "lt_s(2147483647u, 2147483647u)"
    );
    assertEqualU32(
        i320_ltX5Fs(&instance, 4294967295u, 4294967295u),
        0u,
        "lt_s(4294967295u, 4294967295u)"
    );
    assertEqualU32(
        i320_ltX5Fs(&instance, 1u, 0u),
        0u,
        "lt_s(1u, 0u)"
    );
    assertEqualU32(
        i320_ltX5Fs(&instance, 0u, 1u),
        1u,
        "lt_s(0u, 1u)"
    );
    assertEqualU32(
        i320_ltX5Fs(&instance, 2147483648u, 0u),
        1u,
        "lt_s(2147483648u, 0u)"
    );
    assertEqualU32(
        i320_ltX5Fs(&instance, 0u, 2147483648u),
        0u,
        "lt_s(0u, 2147483648u)"
    );
    assertEqualU32(
        i320_ltX5Fs(&instance, 2147483648u, 4294967295u),
        1u,
        "lt_s(2147483648u, 4294967295u)"
    );
    assertEqualU32(
        i320_ltX5Fs(&instance, 4294967295u, 2147483648u),
        0u,
        "lt_s(4294967295u, 2147483648u)"
    );
    assertEqualU32(
        i320_ltX5Fs(&instance, 2147483648u, 2147483647u),
        1u,
        "lt_s(2147483648u, 2147483647u)"
    );
    assertEqualU32(
        i320_ltX5Fs(&instance, 2147483647u, 2147483648u),
        0u,
        "lt_s(2147483647u, 2147483648u)"
    );
    assertEqualU32(
        i320_ltX5Fu(&instance, 0u, 0u),
        0u,
        "lt_u(0u, 0u)"
    );
    assertEqualU32(
        i320_ltX5Fu(&instance, 1u, 1u),
        0u,
        "lt_u(1u, 1u)"
    );
    assertEqualU32(
        i320_ltX5Fu(&instance, 4294967295u, 1u),
        0u,
        "lt_u(4294967295u, 1u)"
    );
    assertEqualU32(
        i320_ltX5Fu(&instance, 2147483648u, 2147483648u),
        0u,
        "lt_u(2147483648u, 2147483648u)"
    );
    assertEqualU32(
        i320_ltX5Fu(&instance, 2147483647u, 2147483647u),
        0u,
        "lt_u(2147483647u, 2147483647u)"
    );
    assertEqualU32(
        i320_ltX5Fu(&instance, 4294967295u, 4294967295u),
        0u,
        "lt_u(4294967295u, 4294967295u)"
    );
    assertEqualU32(
        i320_ltX5Fu(&instance, 1u, 0u),
        0u,
        "lt_u(1u, 0u)"
    );
    assertEqualU32(
        i320_ltX5Fu(&instance, 0u, 1u),
        1u,
        "lt_u(0u, 1u)"
    );
    assertEqualU32(
        i320_ltX5Fu(&instance, 2147483648u, 0u),
        0u,
        "lt_u(2147483648u, 0u)"
    );
    assertEqualU32(
        i320_ltX5Fu(&instance, 0u, 2147483648u),
        1u,
        "lt_u(0u, 2147483648u)"
    );
    assertEqualU32(
        i320_ltX5Fu(&instance, 2147483648u, 4294967295u),
        1u,
        "lt_u(2147483648u, 4294967295u)"
    );
    assertEqualU32(
        i320_ltX5Fu(&instance, 4294967295u, 2147483648u),
        0u,
        "lt_u(4294967295u, 2147483648u)"
    );
    assertEqualU32(
        i320_ltX5Fu(&instance, 2147483648u, 2147483647u),
        0u,
        "lt_u(2147483648u, 2147483647u)"
    );
    assertEqualU32(
        i320_ltX5Fu(&instance, 2147483647u, 2147483648u),
        1u,
        "lt_u(2147483647u, 2147483648u)"
    );
    assertEqualU32(
        i320_leX5Fs(&instance, 0u, 0u),
        1u,
        "le_s(0u, 0u)"
    );
    assertEqualU32(
        i320_leX5Fs(&instance, 1u, 1u),
        1u,
        "le_s(1u, 1u)"
    );
    assertEqualU32(
        i320_leX5Fs(&instance, 4294967295u, 1u),
        1u,
        "le_s(4294967295u, 1u)"
    );
    assertEqualU32(
        i320_leX5Fs(&instance, 2147483648u, 2147483648u),
        1u,
        "le_s(2147483648u, 2147483648u)"
    );
    assertEqualU32(
        i320_leX5Fs(&instance, 2147483647u, 2147483647u),
        1u,
        "le_s(2147483647u, 2147483647u)"
    );
    assertEqualU32(
        i320_leX5Fs(&instance, 4294967295u, 4294967295u),
        1u,
        "le_s(4294967295u, 4294967295u)"
    );
    assertEqualU32(
        i320_leX5Fs(&instance, 1u, 0u),
        0u,
        "le_s(1u, 0u)"
    );
    assertEqualU32(
        i320_leX5Fs(&instance, 0u, 1u),
        1u,
        "le_s(0u, 1u)"
    );
    assertEqualU32(
        i320_leX5Fs(&instance, 2147483648u, 0u),
        1u,
        "le_s(2147483648u, 0u)"
    );
    assertEqualU32(
        i320_leX5Fs(&instance, 0u, 2147483648u),
        0u,
        "le_s(0u, 2147483648u)"
    );
    assertEqualU32(
        i320_leX5Fs(&instance, 2147483648u, 4294967295u),
        1u,
        "le_s(2147483648u, 4294967295u)"
    );
    assertEqualU32(
        i320_leX5Fs(&instance, 4294967295u, 2147483648u),
        0u,
        "le_s(4294967295u, 2147483648u)"
    );
    assertEqualU32(
        i320_leX5Fs(&instance, 2147483648u, 2147483647u),
        1u,
        "le_s(2147483648u, 2147483647u)"
    );
    assertEqualU32(
        i320_leX5Fs(&instance, 2147483647u, 2147483648u),
        0u,
        "le_s(2147483647u, 2147483648u)"
    );
    assertEqualU32(
        i320_leX5Fu(&instance, 0u, 0u),
        1u,
        "le_u(0u, 0u)"
    );
    assertEqualU32(
        i320_leX5Fu(&instance, 1u, 1u),
        1u,
        "le_u(1u, 1u)"
    );
    assertEqualU32(
        i320_leX5Fu(&instance, 4294967295u, 1u),
        0u,
        "le_u(4294967295u, 1u)"
    );
    assertEqualU32(
        i320_leX5Fu(&instance, 2147483648u, 2147483648u),
        1u,
        "le_u(2147483648u, 2147483648u)"
    );
    assertEqualU32(
        i320_leX5Fu(&instance, 2147483647u, 2147483647u),
        1u,
        "le_u(2147483647u, 2147483647u)"
    );
    assertEqualU32(
        i320_leX5Fu(&instance, 4294967295u, 4294967295u),
        1u,
        "le_u(4294967295u, 4294967295u)"
    );
    assertEqualU32(
        i320_leX5Fu(&instance, 1u, 0u),
        0u,
        "le_u(1u, 0u)"
    );
    assertEqualU32(
        i320_leX5Fu(&instance, 0u, 1u),
        1u,
        "le_u(0u, 1u)"
    );
    assertEqualU32(
        i320_leX5Fu(&instance, 2147483648u, 0u),
        0u,
        "le_u(2147483648u, 0u)"
    );
    assertEqualU32(
        i320_leX5Fu(&instance, 0u, 2147483648u),
        1u,
        "le_u(0u, 2147483648u)"
    );
    assertEqualU32(
        i320_leX5Fu(&instance, 2147483648u, 4294967295u),
        1u,
        "le_u(2147483648u, 4294967295u)"
    );
    assertEqualU32(
        i320_leX5Fu(&instance, 4294967295u, 2147483648u),
        0u,
        "le_u(4294967295u, 2147483648u)"
    );
    assertEqualU32(
        i320_leX5Fu(&instance, 2147483648u, 2147483647u),
        0u,
        "le_u(2147483648u, 2147483647u)"
    );
    assertEqualU32(
        i320_leX5Fu(&instance, 2147483647u, 2147483648u),
        1u,
        "le_u(2147483647u, 2147483648u)"
    );
    assertEqualU32(
        i320_gtX5Fs(&instance, 0u, 0u),
        0u,
        "gt_s(0u, 0u)"
    );
    assertEqualU32(
        i320_gtX5Fs(&instance, 1u, 1u),
        0u,
        "gt_s(1u, 1u)"
    );
    assertEqualU32(
        i320_gtX5Fs(&instance, 4294967295u, 1u),
        0u,
        "gt_s(4294967295u, 1u)"
    );
    assertEqualU32(
        i320_gtX5Fs(&instance, 2147483648u, 2147483648u),
        0u,
        "gt_s(2147483648u, 2147483648u)"
    );
    assertEqualU32(
        i320_gtX5Fs(&instance, 2147483647u, 2147483647u),
        0u,
        "gt_s(2147483647u, 2147483647u)"
    );
    assertEqualU32(
        i320_gtX5Fs(&instance, 4294967295u, 4294967295u),
        0u,
        "gt_s(4294967295u, 4294967295u)"
    );
    assertEqualU32(
        i320_gtX5Fs(&instance, 1u, 0u),
        1u,
        "gt_s(1u, 0u)"
    );
    assertEqualU32(
        i320_gtX5Fs(&instance, 0u, 1u),
        0u,
        "gt_s(0u, 1u)"
    );
    assertEqualU32(
        i320_gtX5Fs(&instance, 2147483648u, 0u),
        0u,
        "gt_s(2147483648u, 0u)"
    );
    assertEqualU32(
        i320_gtX5Fs(&instance, 0u, 2147483648u),
        1u,
        "gt_s(0u, 2147483648u)"
    );
    assertEqualU32(
        i320_gtX5Fs(&instance, 2147483648u, 4294967295u),
        0u,
        "gt_s(2147483648u, 4294967295u)"
    );
    assertEqualU32(
        i320_gtX5Fs(&instance, 4294967295u, 2147483648u),
        1u,
        "gt_s(4294967295u, 2147483648u)"
    );
    assertEqualU32(
        i320_gtX5Fs(&instance, 2147483648u, 2147483647u),
        0u,
        "gt_s(2147483648u, 2147483647u)"
    );
    assertEqualU32(
        i320_gtX5Fs(&instance, 2147483647u, 2147483648u),
        1u,
        "gt_s(2147483647u, 2147483648u)"
    );
    assertEqualU32(
        i320_gtX5Fu(&instance, 0u, 0u),
        0u,
        "gt_u(0u, 0u)"
    );
    assertEqualU32(
        i320_gtX5Fu(&instance, 1u, 1u),
        0u,
        "gt_u(1u, 1u)"
    );
    assertEqualU32(
        i320_gtX5Fu(&instance, 4294967295u, 1u),
        1u,
        "gt_u(4294967295u, 1u)"
    );
    assertEqualU32(
        i320_gtX5Fu(&instance, 2147483648u, 2147483648u),
        0u,
        "gt_u(2147483648u, 2147483648u)"
    );
    assertEqualU32(
        i320_gtX5Fu(&instance, 2147483647u, 2147483647u),
        0u,
        "gt_u(2147483647u, 2147483647u)"
    );
    assertEqualU32(
        i320_gtX5Fu(&instance, 4294967295u, 4294967295u),
        0u,
        "gt_u(4294967295u, 4294967295u)"
    );
    assertEqualU32(
        i320_gtX5Fu(&instance, 1u, 0u),
        1u,
        "gt_u(1u, 0u)"
    );
    assertEqualU32(
        i320_gtX5Fu(&instance, 0u, 1u),
        0u,
        "gt_u(0u, 1u)"
    );
    assertEqualU32(
        i320_gtX5Fu(&instance, 2147483648u, 0u),
        1u,
        "gt_u(2147483648u, 0u)"
    );
    assertEqualU32(
        i320_gtX5Fu(&instance, 0u, 2147483648u),
        0u,
        "gt_u(0u, 2147483648u)"
    );
    assertEqualU32(
        i320_gtX5Fu(&instance, 2147483648u, 4294967295u),
        0u,
        "gt_u(2147483648u, 4294967295u)"
    );
    assertEqualU32(
        i320_gtX5Fu(&instance, 4294967295u, 2147483648u),
        1u,
        "gt_u(4294967295u, 2147483648u)"
    );
    assertEqualU32(
        i320_gtX5Fu(&instance, 2147483648u, 2147483647u),
        1u,
        "gt_u(2147483648u, 2147483647u)"
    );
    assertEqualU32(
        i320_gtX5Fu(&instance, 2147483647u, 2147483648u),
        0u,
        "gt_u(2147483647u, 2147483648u)"
    );
    assertEqualU32(
        i320_geX5Fs(&instance, 0u, 0u),
        1u,
        "ge_s(0u, 0u)"
    );
    assertEqualU32(
        i320_geX5Fs(&instance, 1u, 1u),
        1u,
        "ge_s(1u, 1u)"
    );
    assertEqualU32(
        i320_geX5Fs(&instance, 4294967295u, 1u),
        0u,
        "ge_s(4294967295u, 1u)"
    );
    assertEqualU32(
        i320_geX5Fs(&instance, 2147483648u, 2147483648u),
        1u,
        "ge_s(2147483648u, 2147483648u)"
    );
    assertEqualU32(
        i320_geX5Fs(&instance, 2147483647u, 2147483647u),
        1u,
        "ge_s(2147483647u, 2147483647u)"
    );
    assertEqualU32(
        i320_geX5Fs(&instance, 4294967295u, 4294967295u),
        1u,
        "ge_s(4294967295u, 4294967295u)"
    );
    assertEqualU32(
        i320_geX5Fs(&instance, 1u, 0u),
        1u,
        "ge_s(1u, 0u)"
    );
    assertEqualU32(
        i320_geX5Fs(&instance, 0u, 1u),
        0u,
        "ge_s(0u, 1u)"
    );
    assertEqualU32(
        i320_geX5Fs(&instance, 2147483648u, 0u),
        0u,
        "ge_s(2147483648u, 0u)"
    );
    assertEqualU32(
        i320_geX5Fs(&instance, 0u, 2147483648u),
        1u,
        "ge_s(0u, 2147483648u)"
    );
    assertEqualU32(
        i320_geX5Fs(&instance, 2147483648u, 4294967295u),
        0u,
        "ge_s(2147483648u, 4294967295u)"
    );
    assertEqualU32(
        i320_geX5Fs(&instance, 4294967295u, 2147483648u),
        1u,
        "ge_s(4294967295u, 2147483648u)"
    );
    assertEqualU32(
        i320_geX5Fs(&instance, 2147483648u, 2147483647u),
        0u,
        "ge_s(2147483648u, 2147483647u)"
    );
    assertEqualU32(
        i320_geX5Fs(&instance, 2147483647u, 2147483648u),
        1u,
        "ge_s(2147483647u, 2147483648u)"
    );
    assertEqualU32(
        i320_geX5Fu(&instance, 0u, 0u),
        1u,
        "ge_u(0u, 0u)"
    );
    assertEqualU32(
        i320_geX5Fu(&instance, 1u, 1u),
        1u,
        "ge_u(1u, 1u)"
    );
    assertEqualU32(
        i320_geX5Fu(&instance, 4294967295u, 1u),
        1u,
        "ge_u(4294967295u, 1u)"
    );
    assertEqualU32(
        i320_geX5Fu(&instance, 2147483648u, 2147483648u),
        1u,
        "ge_u(2147483648u, 2147483648u)"
    );
    assertEqualU32(
        i320_geX5Fu(&instance, 2147483647u, 2147483647u),
        1u,
        "ge_u(2147483647u, 2147483647u)"
    );
    assertEqualU32(
        i320_geX5Fu(&instance, 4294967295u, 4294967295u),
        1u,
        "ge_u(4294967295u, 4294967295u)"
    );
    assertEqualU32(
        i320_geX5Fu(&instance, 1u, 0u),
        1u,
        "ge_u(1u, 0u)"
    );
    assertEqualU32(
        i320_geX5Fu(&instance, 0u, 1u),
        0u,
        "ge_u(0u, 1u)"
    );
    assertEqualU32(
        i320_geX5Fu(&instance, 2147483648u, 0u),
        1u,
        "ge_u(2147483648u, 0u)"
    );
    assertEqualU32(
        i320_geX5Fu(&instance, 0u, 2147483648u),
        0u,
        "ge_u(0u, 2147483648u)"
    );
    assertEqualU32(
        i320_geX5Fu(&instance, 2147483648u, 4294967295u),
        0u,
        "ge_u(2147483648u, 4294967295u)"
    );
    assertEqualU32(
        i320_geX5Fu(&instance, 4294967295u, 2147483648u),
        1u,
        "ge_u(4294967295u, 2147483648u)"
    );
    assertEqualU32(
        i320_geX5Fu(&instance, 2147483648u, 2147483647u),
        1u,
        "ge_u(2147483648u, 2147483647u)"
    );
    assertEqualU32(
        i320_geX5Fu(&instance, 2147483647u, 2147483648u),
        0u,
        "ge_u(2147483647u, 2147483648u)"
    );
}
