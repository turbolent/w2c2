
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_i64.0.h"

void test() {
    i640Instance instance;
    i640Instantiate(&instance, resolveTestImports);
    printStart("i64.0.wasm");
    assertEqualU64(
        i640_add(&instance, 1ull, 1ull),
        2ull,
        "add(1ull, 1ull)"
    );
    assertEqualU64(
        i640_add(&instance, 1ull, 0ull),
        1ull,
        "add(1ull, 0ull)"
    );
    assertEqualU64(
        i640_add(&instance, 18446744073709551615ull, 18446744073709551615ull),
        18446744073709551614ull,
        "add(18446744073709551615ull, 18446744073709551615ull)"
    );
    assertEqualU64(
        i640_add(&instance, 18446744073709551615ull, 1ull),
        0ull,
        "add(18446744073709551615ull, 1ull)"
    );
    assertEqualU64(
        i640_add(&instance, 9223372036854775807ull, 1ull),
        9223372036854775808ull,
        "add(9223372036854775807ull, 1ull)"
    );
    assertEqualU64(
        i640_add(&instance, 9223372036854775808ull, 18446744073709551615ull),
        9223372036854775807ull,
        "add(9223372036854775808ull, 18446744073709551615ull)"
    );
    assertEqualU64(
        i640_add(&instance, 9223372036854775808ull, 9223372036854775808ull),
        0ull,
        "add(9223372036854775808ull, 9223372036854775808ull)"
    );
    assertEqualU64(
        i640_add(&instance, 1073741823ull, 1ull),
        1073741824ull,
        "add(1073741823ull, 1ull)"
    );
    assertEqualU64(
        i640_sub(&instance, 1ull, 1ull),
        0ull,
        "sub(1ull, 1ull)"
    );
    assertEqualU64(
        i640_sub(&instance, 1ull, 0ull),
        1ull,
        "sub(1ull, 0ull)"
    );
    assertEqualU64(
        i640_sub(&instance, 18446744073709551615ull, 18446744073709551615ull),
        0ull,
        "sub(18446744073709551615ull, 18446744073709551615ull)"
    );
    assertEqualU64(
        i640_sub(&instance, 9223372036854775807ull, 18446744073709551615ull),
        9223372036854775808ull,
        "sub(9223372036854775807ull, 18446744073709551615ull)"
    );
    assertEqualU64(
        i640_sub(&instance, 9223372036854775808ull, 1ull),
        9223372036854775807ull,
        "sub(9223372036854775808ull, 1ull)"
    );
    assertEqualU64(
        i640_sub(&instance, 9223372036854775808ull, 9223372036854775808ull),
        0ull,
        "sub(9223372036854775808ull, 9223372036854775808ull)"
    );
    assertEqualU64(
        i640_sub(&instance, 1073741823ull, 18446744073709551615ull),
        1073741824ull,
        "sub(1073741823ull, 18446744073709551615ull)"
    );
    assertEqualU64(
        i640_mul(&instance, 1ull, 1ull),
        1ull,
        "mul(1ull, 1ull)"
    );
    assertEqualU64(
        i640_mul(&instance, 1ull, 0ull),
        0ull,
        "mul(1ull, 0ull)"
    );
    assertEqualU64(
        i640_mul(&instance, 18446744073709551615ull, 18446744073709551615ull),
        1ull,
        "mul(18446744073709551615ull, 18446744073709551615ull)"
    );
    assertEqualU64(
        i640_mul(&instance, 1152921504606846976ull, 4096ull),
        0ull,
        "mul(1152921504606846976ull, 4096ull)"
    );
    assertEqualU64(
        i640_mul(&instance, 9223372036854775808ull, 0ull),
        0ull,
        "mul(9223372036854775808ull, 0ull)"
    );
    assertEqualU64(
        i640_mul(&instance, 9223372036854775808ull, 18446744073709551615ull),
        9223372036854775808ull,
        "mul(9223372036854775808ull, 18446744073709551615ull)"
    );
    assertEqualU64(
        i640_mul(&instance, 9223372036854775807ull, 18446744073709551615ull),
        9223372036854775809ull,
        "mul(9223372036854775807ull, 18446744073709551615ull)"
    );
    assertEqualU64(
        i640_mul(&instance, 81985529216486895ull, 18364758544493064720ull),
        2465395958572223728ull,
        "mul(81985529216486895ull, 18364758544493064720ull)"
    );
    assertEqualU64(
        i640_mul(&instance, 9223372036854775807ull, 9223372036854775807ull),
        1ull,
        "mul(9223372036854775807ull, 9223372036854775807ull)"
    );
    assertEqualU64(
        i640_div_s(&instance, 1ull, 1ull),
        1ull,
        "div_s(1ull, 1ull)"
    );
    assertEqualU64(
        i640_div_s(&instance, 0ull, 1ull),
        0ull,
        "div_s(0ull, 1ull)"
    );
    assertEqualU64(
        i640_div_s(&instance, 0ull, 18446744073709551615ull),
        0ull,
        "div_s(0ull, 18446744073709551615ull)"
    );
    assertEqualU64(
        i640_div_s(&instance, 18446744073709551615ull, 18446744073709551615ull),
        1ull,
        "div_s(18446744073709551615ull, 18446744073709551615ull)"
    );
    assertEqualU64(
        i640_div_s(&instance, 9223372036854775808ull, 2ull),
        13835058055282163712ull,
        "div_s(9223372036854775808ull, 2ull)"
    );
    assertEqualU64(
        i640_div_s(&instance, 9223372036854775809ull, 1000ull),
        18437520701672696841ull,
        "div_s(9223372036854775809ull, 1000ull)"
    );
    assertEqualU64(
        i640_div_s(&instance, 5ull, 2ull),
        2ull,
        "div_s(5ull, 2ull)"
    );
    assertEqualU64(
        i640_div_s(&instance, 18446744073709551611ull, 2ull),
        18446744073709551614ull,
        "div_s(18446744073709551611ull, 2ull)"
    );
    assertEqualU64(
        i640_div_s(&instance, 5ull, 18446744073709551614ull),
        18446744073709551614ull,
        "div_s(5ull, 18446744073709551614ull)"
    );
    assertEqualU64(
        i640_div_s(&instance, 18446744073709551611ull, 18446744073709551614ull),
        2ull,
        "div_s(18446744073709551611ull, 18446744073709551614ull)"
    );
    assertEqualU64(
        i640_div_s(&instance, 7ull, 3ull),
        2ull,
        "div_s(7ull, 3ull)"
    );
    assertEqualU64(
        i640_div_s(&instance, 18446744073709551609ull, 3ull),
        18446744073709551614ull,
        "div_s(18446744073709551609ull, 3ull)"
    );
    assertEqualU64(
        i640_div_s(&instance, 7ull, 18446744073709551613ull),
        18446744073709551614ull,
        "div_s(7ull, 18446744073709551613ull)"
    );
    assertEqualU64(
        i640_div_s(&instance, 18446744073709551609ull, 18446744073709551613ull),
        2ull,
        "div_s(18446744073709551609ull, 18446744073709551613ull)"
    );
    assertEqualU64(
        i640_div_s(&instance, 11ull, 5ull),
        2ull,
        "div_s(11ull, 5ull)"
    );
    assertEqualU64(
        i640_div_s(&instance, 17ull, 7ull),
        2ull,
        "div_s(17ull, 7ull)"
    );
    assertEqualU64(
        i640_div_u(&instance, 1ull, 1ull),
        1ull,
        "div_u(1ull, 1ull)"
    );
    assertEqualU64(
        i640_div_u(&instance, 0ull, 1ull),
        0ull,
        "div_u(0ull, 1ull)"
    );
    assertEqualU64(
        i640_div_u(&instance, 18446744073709551615ull, 18446744073709551615ull),
        1ull,
        "div_u(18446744073709551615ull, 18446744073709551615ull)"
    );
    assertEqualU64(
        i640_div_u(&instance, 9223372036854775808ull, 18446744073709551615ull),
        0ull,
        "div_u(9223372036854775808ull, 18446744073709551615ull)"
    );
    assertEqualU64(
        i640_div_u(&instance, 9223372036854775808ull, 2ull),
        4611686018427387904ull,
        "div_u(9223372036854775808ull, 2ull)"
    );
    assertEqualU64(
        i640_div_u(&instance, 10371807465568210928ull, 4294967297ull),
        2414874607ull,
        "div_u(10371807465568210928ull, 4294967297ull)"
    );
    assertEqualU64(
        i640_div_u(&instance, 9223372036854775809ull, 1000ull),
        9223372036854775ull,
        "div_u(9223372036854775809ull, 1000ull)"
    );
    assertEqualU64(
        i640_div_u(&instance, 5ull, 2ull),
        2ull,
        "div_u(5ull, 2ull)"
    );
    assertEqualU64(
        i640_div_u(&instance, 18446744073709551611ull, 2ull),
        9223372036854775805ull,
        "div_u(18446744073709551611ull, 2ull)"
    );
    assertEqualU64(
        i640_div_u(&instance, 5ull, 18446744073709551614ull),
        0ull,
        "div_u(5ull, 18446744073709551614ull)"
    );
    assertEqualU64(
        i640_div_u(&instance, 18446744073709551611ull, 18446744073709551614ull),
        0ull,
        "div_u(18446744073709551611ull, 18446744073709551614ull)"
    );
    assertEqualU64(
        i640_div_u(&instance, 7ull, 3ull),
        2ull,
        "div_u(7ull, 3ull)"
    );
    assertEqualU64(
        i640_div_u(&instance, 11ull, 5ull),
        2ull,
        "div_u(11ull, 5ull)"
    );
    assertEqualU64(
        i640_div_u(&instance, 17ull, 7ull),
        2ull,
        "div_u(17ull, 7ull)"
    );
    assertEqualU64(
        i640_rem_s(&instance, 9223372036854775807ull, 18446744073709551615ull),
        0ull,
        "rem_s(9223372036854775807ull, 18446744073709551615ull)"
    );
    assertEqualU64(
        i640_rem_s(&instance, 1ull, 1ull),
        0ull,
        "rem_s(1ull, 1ull)"
    );
    assertEqualU64(
        i640_rem_s(&instance, 0ull, 1ull),
        0ull,
        "rem_s(0ull, 1ull)"
    );
    assertEqualU64(
        i640_rem_s(&instance, 0ull, 18446744073709551615ull),
        0ull,
        "rem_s(0ull, 18446744073709551615ull)"
    );
    assertEqualU64(
        i640_rem_s(&instance, 18446744073709551615ull, 18446744073709551615ull),
        0ull,
        "rem_s(18446744073709551615ull, 18446744073709551615ull)"
    );
    assertEqualU64(
        i640_rem_s(&instance, 9223372036854775808ull, 18446744073709551615ull),
        0ull,
        "rem_s(9223372036854775808ull, 18446744073709551615ull)"
    );
    assertEqualU64(
        i640_rem_s(&instance, 9223372036854775808ull, 2ull),
        0ull,
        "rem_s(9223372036854775808ull, 2ull)"
    );
    assertEqualU64(
        i640_rem_s(&instance, 9223372036854775809ull, 1000ull),
        18446744073709550809ull,
        "rem_s(9223372036854775809ull, 1000ull)"
    );
    assertEqualU64(
        i640_rem_s(&instance, 5ull, 2ull),
        1ull,
        "rem_s(5ull, 2ull)"
    );
    assertEqualU64(
        i640_rem_s(&instance, 18446744073709551611ull, 2ull),
        18446744073709551615ull,
        "rem_s(18446744073709551611ull, 2ull)"
    );
    assertEqualU64(
        i640_rem_s(&instance, 5ull, 18446744073709551614ull),
        1ull,
        "rem_s(5ull, 18446744073709551614ull)"
    );
    assertEqualU64(
        i640_rem_s(&instance, 18446744073709551611ull, 18446744073709551614ull),
        18446744073709551615ull,
        "rem_s(18446744073709551611ull, 18446744073709551614ull)"
    );
    assertEqualU64(
        i640_rem_s(&instance, 7ull, 3ull),
        1ull,
        "rem_s(7ull, 3ull)"
    );
    assertEqualU64(
        i640_rem_s(&instance, 18446744073709551609ull, 3ull),
        18446744073709551615ull,
        "rem_s(18446744073709551609ull, 3ull)"
    );
    assertEqualU64(
        i640_rem_s(&instance, 7ull, 18446744073709551613ull),
        1ull,
        "rem_s(7ull, 18446744073709551613ull)"
    );
    assertEqualU64(
        i640_rem_s(&instance, 18446744073709551609ull, 18446744073709551613ull),
        18446744073709551615ull,
        "rem_s(18446744073709551609ull, 18446744073709551613ull)"
    );
    assertEqualU64(
        i640_rem_s(&instance, 11ull, 5ull),
        1ull,
        "rem_s(11ull, 5ull)"
    );
    assertEqualU64(
        i640_rem_s(&instance, 17ull, 7ull),
        3ull,
        "rem_s(17ull, 7ull)"
    );
    assertEqualU64(
        i640_rem_u(&instance, 1ull, 1ull),
        0ull,
        "rem_u(1ull, 1ull)"
    );
    assertEqualU64(
        i640_rem_u(&instance, 0ull, 1ull),
        0ull,
        "rem_u(0ull, 1ull)"
    );
    assertEqualU64(
        i640_rem_u(&instance, 18446744073709551615ull, 18446744073709551615ull),
        0ull,
        "rem_u(18446744073709551615ull, 18446744073709551615ull)"
    );
    assertEqualU64(
        i640_rem_u(&instance, 9223372036854775808ull, 18446744073709551615ull),
        9223372036854775808ull,
        "rem_u(9223372036854775808ull, 18446744073709551615ull)"
    );
    assertEqualU64(
        i640_rem_u(&instance, 9223372036854775808ull, 2ull),
        0ull,
        "rem_u(9223372036854775808ull, 2ull)"
    );
    assertEqualU64(
        i640_rem_u(&instance, 10371807465568210928ull, 4294967297ull),
        2147483649ull,
        "rem_u(10371807465568210928ull, 4294967297ull)"
    );
    assertEqualU64(
        i640_rem_u(&instance, 9223372036854775809ull, 1000ull),
        809ull,
        "rem_u(9223372036854775809ull, 1000ull)"
    );
    assertEqualU64(
        i640_rem_u(&instance, 5ull, 2ull),
        1ull,
        "rem_u(5ull, 2ull)"
    );
    assertEqualU64(
        i640_rem_u(&instance, 18446744073709551611ull, 2ull),
        1ull,
        "rem_u(18446744073709551611ull, 2ull)"
    );
    assertEqualU64(
        i640_rem_u(&instance, 5ull, 18446744073709551614ull),
        5ull,
        "rem_u(5ull, 18446744073709551614ull)"
    );
    assertEqualU64(
        i640_rem_u(&instance, 18446744073709551611ull, 18446744073709551614ull),
        18446744073709551611ull,
        "rem_u(18446744073709551611ull, 18446744073709551614ull)"
    );
    assertEqualU64(
        i640_rem_u(&instance, 7ull, 3ull),
        1ull,
        "rem_u(7ull, 3ull)"
    );
    assertEqualU64(
        i640_rem_u(&instance, 11ull, 5ull),
        1ull,
        "rem_u(11ull, 5ull)"
    );
    assertEqualU64(
        i640_rem_u(&instance, 17ull, 7ull),
        3ull,
        "rem_u(17ull, 7ull)"
    );
    assertEqualU64(
        i640_and(&instance, 1ull, 0ull),
        0ull,
        "and(1ull, 0ull)"
    );
    assertEqualU64(
        i640_and(&instance, 0ull, 1ull),
        0ull,
        "and(0ull, 1ull)"
    );
    assertEqualU64(
        i640_and(&instance, 1ull, 1ull),
        1ull,
        "and(1ull, 1ull)"
    );
    assertEqualU64(
        i640_and(&instance, 0ull, 0ull),
        0ull,
        "and(0ull, 0ull)"
    );
    assertEqualU64(
        i640_and(&instance, 9223372036854775807ull, 9223372036854775808ull),
        0ull,
        "and(9223372036854775807ull, 9223372036854775808ull)"
    );
    assertEqualU64(
        i640_and(&instance, 9223372036854775807ull, 18446744073709551615ull),
        9223372036854775807ull,
        "and(9223372036854775807ull, 18446744073709551615ull)"
    );
    assertEqualU64(
        i640_and(&instance, 4042326015ull, 4294963440ull),
        4042322160ull,
        "and(4042326015ull, 4294963440ull)"
    );
    assertEqualU64(
        i640_and(&instance, 18446744073709551615ull, 18446744073709551615ull),
        18446744073709551615ull,
        "and(18446744073709551615ull, 18446744073709551615ull)"
    );
    assertEqualU64(
        i640_or(&instance, 1ull, 0ull),
        1ull,
        "or(1ull, 0ull)"
    );
    assertEqualU64(
        i640_or(&instance, 0ull, 1ull),
        1ull,
        "or(0ull, 1ull)"
    );
    assertEqualU64(
        i640_or(&instance, 1ull, 1ull),
        1ull,
        "or(1ull, 1ull)"
    );
    assertEqualU64(
        i640_or(&instance, 0ull, 0ull),
        0ull,
        "or(0ull, 0ull)"
    );
    assertEqualU64(
        i640_or(&instance, 9223372036854775807ull, 9223372036854775808ull),
        18446744073709551615ull,
        "or(9223372036854775807ull, 9223372036854775808ull)"
    );
    assertEqualU64(
        i640_or(&instance, 9223372036854775808ull, 0ull),
        9223372036854775808ull,
        "or(9223372036854775808ull, 0ull)"
    );
    assertEqualU64(
        i640_or(&instance, 4042326015ull, 4294963440ull),
        4294967295ull,
        "or(4042326015ull, 4294963440ull)"
    );
    assertEqualU64(
        i640_or(&instance, 18446744073709551615ull, 18446744073709551615ull),
        18446744073709551615ull,
        "or(18446744073709551615ull, 18446744073709551615ull)"
    );
    assertEqualU64(
        i640_xor(&instance, 1ull, 0ull),
        1ull,
        "xor(1ull, 0ull)"
    );
    assertEqualU64(
        i640_xor(&instance, 0ull, 1ull),
        1ull,
        "xor(0ull, 1ull)"
    );
    assertEqualU64(
        i640_xor(&instance, 1ull, 1ull),
        0ull,
        "xor(1ull, 1ull)"
    );
    assertEqualU64(
        i640_xor(&instance, 0ull, 0ull),
        0ull,
        "xor(0ull, 0ull)"
    );
    assertEqualU64(
        i640_xor(&instance, 9223372036854775807ull, 9223372036854775808ull),
        18446744073709551615ull,
        "xor(9223372036854775807ull, 9223372036854775808ull)"
    );
    assertEqualU64(
        i640_xor(&instance, 9223372036854775808ull, 0ull),
        9223372036854775808ull,
        "xor(9223372036854775808ull, 0ull)"
    );
    assertEqualU64(
        i640_xor(&instance, 18446744073709551615ull, 9223372036854775808ull),
        9223372036854775807ull,
        "xor(18446744073709551615ull, 9223372036854775808ull)"
    );
    assertEqualU64(
        i640_xor(&instance, 18446744073709551615ull, 9223372036854775807ull),
        9223372036854775808ull,
        "xor(18446744073709551615ull, 9223372036854775807ull)"
    );
    assertEqualU64(
        i640_xor(&instance, 4042326015ull, 4294963440ull),
        252645135ull,
        "xor(4042326015ull, 4294963440ull)"
    );
    assertEqualU64(
        i640_xor(&instance, 18446744073709551615ull, 18446744073709551615ull),
        0ull,
        "xor(18446744073709551615ull, 18446744073709551615ull)"
    );
    assertEqualU64(
        i640_shl(&instance, 1ull, 1ull),
        2ull,
        "shl(1ull, 1ull)"
    );
    assertEqualU64(
        i640_shl(&instance, 1ull, 0ull),
        1ull,
        "shl(1ull, 0ull)"
    );
    assertEqualU64(
        i640_shl(&instance, 9223372036854775807ull, 1ull),
        18446744073709551614ull,
        "shl(9223372036854775807ull, 1ull)"
    );
    assertEqualU64(
        i640_shl(&instance, 18446744073709551615ull, 1ull),
        18446744073709551614ull,
        "shl(18446744073709551615ull, 1ull)"
    );
    assertEqualU64(
        i640_shl(&instance, 9223372036854775808ull, 1ull),
        0ull,
        "shl(9223372036854775808ull, 1ull)"
    );
    assertEqualU64(
        i640_shl(&instance, 4611686018427387904ull, 1ull),
        9223372036854775808ull,
        "shl(4611686018427387904ull, 1ull)"
    );
    assertEqualU64(
        i640_shl(&instance, 1ull, 63ull),
        9223372036854775808ull,
        "shl(1ull, 63ull)"
    );
    assertEqualU64(
        i640_shl(&instance, 1ull, 64ull),
        1ull,
        "shl(1ull, 64ull)"
    );
    assertEqualU64(
        i640_shl(&instance, 1ull, 65ull),
        2ull,
        "shl(1ull, 65ull)"
    );
    assertEqualU64(
        i640_shl(&instance, 1ull, 18446744073709551615ull),
        9223372036854775808ull,
        "shl(1ull, 18446744073709551615ull)"
    );
    assertEqualU64(
        i640_shl(&instance, 1ull, 9223372036854775807ull),
        9223372036854775808ull,
        "shl(1ull, 9223372036854775807ull)"
    );
    assertEqualU64(
        i640_shr_s(&instance, 1ull, 1ull),
        0ull,
        "shr_s(1ull, 1ull)"
    );
    assertEqualU64(
        i640_shr_s(&instance, 1ull, 0ull),
        1ull,
        "shr_s(1ull, 0ull)"
    );
    assertEqualU64(
        i640_shr_s(&instance, 18446744073709551615ull, 1ull),
        18446744073709551615ull,
        "shr_s(18446744073709551615ull, 1ull)"
    );
    assertEqualU64(
        i640_shr_s(&instance, 9223372036854775807ull, 1ull),
        4611686018427387903ull,
        "shr_s(9223372036854775807ull, 1ull)"
    );
    assertEqualU64(
        i640_shr_s(&instance, 9223372036854775808ull, 1ull),
        13835058055282163712ull,
        "shr_s(9223372036854775808ull, 1ull)"
    );
    assertEqualU64(
        i640_shr_s(&instance, 4611686018427387904ull, 1ull),
        2305843009213693952ull,
        "shr_s(4611686018427387904ull, 1ull)"
    );
    assertEqualU64(
        i640_shr_s(&instance, 1ull, 64ull),
        1ull,
        "shr_s(1ull, 64ull)"
    );
    assertEqualU64(
        i640_shr_s(&instance, 1ull, 65ull),
        0ull,
        "shr_s(1ull, 65ull)"
    );
    assertEqualU64(
        i640_shr_s(&instance, 1ull, 18446744073709551615ull),
        0ull,
        "shr_s(1ull, 18446744073709551615ull)"
    );
    assertEqualU64(
        i640_shr_s(&instance, 1ull, 9223372036854775807ull),
        0ull,
        "shr_s(1ull, 9223372036854775807ull)"
    );
    assertEqualU64(
        i640_shr_s(&instance, 1ull, 9223372036854775808ull),
        1ull,
        "shr_s(1ull, 9223372036854775808ull)"
    );
    assertEqualU64(
        i640_shr_s(&instance, 9223372036854775808ull, 63ull),
        18446744073709551615ull,
        "shr_s(9223372036854775808ull, 63ull)"
    );
    assertEqualU64(
        i640_shr_s(&instance, 18446744073709551615ull, 64ull),
        18446744073709551615ull,
        "shr_s(18446744073709551615ull, 64ull)"
    );
    assertEqualU64(
        i640_shr_s(&instance, 18446744073709551615ull, 65ull),
        18446744073709551615ull,
        "shr_s(18446744073709551615ull, 65ull)"
    );
    assertEqualU64(
        i640_shr_s(&instance, 18446744073709551615ull, 18446744073709551615ull),
        18446744073709551615ull,
        "shr_s(18446744073709551615ull, 18446744073709551615ull)"
    );
    assertEqualU64(
        i640_shr_s(&instance, 18446744073709551615ull, 9223372036854775807ull),
        18446744073709551615ull,
        "shr_s(18446744073709551615ull, 9223372036854775807ull)"
    );
    assertEqualU64(
        i640_shr_s(&instance, 18446744073709551615ull, 9223372036854775808ull),
        18446744073709551615ull,
        "shr_s(18446744073709551615ull, 9223372036854775808ull)"
    );
    assertEqualU64(
        i640_shr_u(&instance, 1ull, 1ull),
        0ull,
        "shr_u(1ull, 1ull)"
    );
    assertEqualU64(
        i640_shr_u(&instance, 1ull, 0ull),
        1ull,
        "shr_u(1ull, 0ull)"
    );
    assertEqualU64(
        i640_shr_u(&instance, 18446744073709551615ull, 1ull),
        9223372036854775807ull,
        "shr_u(18446744073709551615ull, 1ull)"
    );
    assertEqualU64(
        i640_shr_u(&instance, 9223372036854775807ull, 1ull),
        4611686018427387903ull,
        "shr_u(9223372036854775807ull, 1ull)"
    );
    assertEqualU64(
        i640_shr_u(&instance, 9223372036854775808ull, 1ull),
        4611686018427387904ull,
        "shr_u(9223372036854775808ull, 1ull)"
    );
    assertEqualU64(
        i640_shr_u(&instance, 4611686018427387904ull, 1ull),
        2305843009213693952ull,
        "shr_u(4611686018427387904ull, 1ull)"
    );
    assertEqualU64(
        i640_shr_u(&instance, 1ull, 64ull),
        1ull,
        "shr_u(1ull, 64ull)"
    );
    assertEqualU64(
        i640_shr_u(&instance, 1ull, 65ull),
        0ull,
        "shr_u(1ull, 65ull)"
    );
    assertEqualU64(
        i640_shr_u(&instance, 1ull, 18446744073709551615ull),
        0ull,
        "shr_u(1ull, 18446744073709551615ull)"
    );
    assertEqualU64(
        i640_shr_u(&instance, 1ull, 9223372036854775807ull),
        0ull,
        "shr_u(1ull, 9223372036854775807ull)"
    );
    assertEqualU64(
        i640_shr_u(&instance, 1ull, 9223372036854775808ull),
        1ull,
        "shr_u(1ull, 9223372036854775808ull)"
    );
    assertEqualU64(
        i640_shr_u(&instance, 9223372036854775808ull, 63ull),
        1ull,
        "shr_u(9223372036854775808ull, 63ull)"
    );
    assertEqualU64(
        i640_shr_u(&instance, 18446744073709551615ull, 64ull),
        18446744073709551615ull,
        "shr_u(18446744073709551615ull, 64ull)"
    );
    assertEqualU64(
        i640_shr_u(&instance, 18446744073709551615ull, 65ull),
        9223372036854775807ull,
        "shr_u(18446744073709551615ull, 65ull)"
    );
    assertEqualU64(
        i640_shr_u(&instance, 18446744073709551615ull, 18446744073709551615ull),
        1ull,
        "shr_u(18446744073709551615ull, 18446744073709551615ull)"
    );
    assertEqualU64(
        i640_shr_u(&instance, 18446744073709551615ull, 9223372036854775807ull),
        1ull,
        "shr_u(18446744073709551615ull, 9223372036854775807ull)"
    );
    assertEqualU64(
        i640_shr_u(&instance, 18446744073709551615ull, 9223372036854775808ull),
        18446744073709551615ull,
        "shr_u(18446744073709551615ull, 9223372036854775808ull)"
    );
    assertEqualU64(
        i640_rotl(&instance, 1ull, 1ull),
        2ull,
        "rotl(1ull, 1ull)"
    );
    assertEqualU64(
        i640_rotl(&instance, 1ull, 0ull),
        1ull,
        "rotl(1ull, 0ull)"
    );
    assertEqualU64(
        i640_rotl(&instance, 18446744073709551615ull, 1ull),
        18446744073709551615ull,
        "rotl(18446744073709551615ull, 1ull)"
    );
    assertEqualU64(
        i640_rotl(&instance, 1ull, 64ull),
        1ull,
        "rotl(1ull, 64ull)"
    );
    assertEqualU64(
        i640_rotl(&instance, 12379718583323101902ull, 1ull),
        6312693092936652189ull,
        "rotl(12379718583323101902ull, 1ull)"
    );
    assertEqualU64(
        i640_rotl(&instance, 18302628889324683264ull, 4ull),
        16140901123551657999ull,
        "rotl(18302628889324683264ull, 4ull)"
    );
    assertEqualU64(
        i640_rotl(&instance, 12379570969274382345ull, 53ull),
        87109505680009935ull,
        "rotl(12379570969274382345ull, 53ull)"
    );
    assertEqualU64(
        i640_rotl(&instance, 12380715672649826460ull, 63ull),
        6190357836324913230ull,
        "rotl(12380715672649826460ull, 63ull)"
    );
    assertEqualU64(
        i640_rotl(&instance, 12379570969274382345ull, 245ull),
        87109505680009935ull,
        "rotl(12379570969274382345ull, 245ull)"
    );
    assertEqualU64(
        i640_rotl(&instance, 12379676934707509257ull, 18446744073709551597ull),
        14916262237559758314ull,
        "rotl(12379676934707509257ull, 18446744073709551597ull)"
    );
    assertEqualU64(
        i640_rotl(&instance, 12380715672649826460ull, 9223372036854775871ull),
        6190357836324913230ull,
        "rotl(12380715672649826460ull, 9223372036854775871ull)"
    );
    assertEqualU64(
        i640_rotl(&instance, 1ull, 63ull),
        9223372036854775808ull,
        "rotl(1ull, 63ull)"
    );
    assertEqualU64(
        i640_rotl(&instance, 9223372036854775808ull, 1ull),
        1ull,
        "rotl(9223372036854775808ull, 1ull)"
    );
    assertEqualU64(
        i640_rotr(&instance, 1ull, 1ull),
        9223372036854775808ull,
        "rotr(1ull, 1ull)"
    );
    assertEqualU64(
        i640_rotr(&instance, 1ull, 0ull),
        1ull,
        "rotr(1ull, 0ull)"
    );
    assertEqualU64(
        i640_rotr(&instance, 18446744073709551615ull, 1ull),
        18446744073709551615ull,
        "rotr(18446744073709551615ull, 1ull)"
    );
    assertEqualU64(
        i640_rotr(&instance, 1ull, 64ull),
        1ull,
        "rotr(1ull, 64ull)"
    );
    assertEqualU64(
        i640_rotr(&instance, 12379718583323101902ull, 1ull),
        6189859291661550951ull,
        "rotr(12379718583323101902ull, 1ull)"
    );
    assertEqualU64(
        i640_rotr(&instance, 18302628889324683264ull, 4ull),
        1143914305582792704ull,
        "rotr(18302628889324683264ull, 4ull)"
    );
    assertEqualU64(
        i640_rotr(&instance, 12379570969274382345ull, 53ull),
        7534987797011123550ull,
        "rotr(12379570969274382345ull, 53ull)"
    );
    assertEqualU64(
        i640_rotr(&instance, 12380715672649826460ull, 63ull),
        6314687271590101305ull,
        "rotr(12380715672649826460ull, 63ull)"
    );
    assertEqualU64(
        i640_rotr(&instance, 12379570969274382345ull, 245ull),
        7534987797011123550ull,
        "rotr(12379570969274382345ull, 245ull)"
    );
    assertEqualU64(
        i640_rotr(&instance, 12379676934707509257ull, 18446744073709551597ull),
        10711665151168044651ull,
        "rotr(12379676934707509257ull, 18446744073709551597ull)"
    );
    assertEqualU64(
        i640_rotr(&instance, 12380715672649826460ull, 9223372036854775871ull),
        6314687271590101305ull,
        "rotr(12380715672649826460ull, 9223372036854775871ull)"
    );
    assertEqualU64(
        i640_rotr(&instance, 1ull, 63ull),
        2ull,
        "rotr(1ull, 63ull)"
    );
    assertEqualU64(
        i640_rotr(&instance, 9223372036854775808ull, 63ull),
        1ull,
        "rotr(9223372036854775808ull, 63ull)"
    );
    assertEqualU64(
        i640_clz(&instance, 18446744073709551615ull),
        0ull,
        "clz(18446744073709551615ull)"
    );
    assertEqualU64(
        i640_clz(&instance, 0ull),
        64ull,
        "clz(0ull)"
    );
    assertEqualU64(
        i640_clz(&instance, 32768ull),
        48ull,
        "clz(32768ull)"
    );
    assertEqualU64(
        i640_clz(&instance, 255ull),
        56ull,
        "clz(255ull)"
    );
    assertEqualU64(
        i640_clz(&instance, 9223372036854775808ull),
        0ull,
        "clz(9223372036854775808ull)"
    );
    assertEqualU64(
        i640_clz(&instance, 1ull),
        63ull,
        "clz(1ull)"
    );
    assertEqualU64(
        i640_clz(&instance, 2ull),
        62ull,
        "clz(2ull)"
    );
    assertEqualU64(
        i640_clz(&instance, 9223372036854775807ull),
        1ull,
        "clz(9223372036854775807ull)"
    );
    assertEqualU64(
        i640_ctz(&instance, 18446744073709551615ull),
        0ull,
        "ctz(18446744073709551615ull)"
    );
    assertEqualU64(
        i640_ctz(&instance, 0ull),
        64ull,
        "ctz(0ull)"
    );
    assertEqualU64(
        i640_ctz(&instance, 32768ull),
        15ull,
        "ctz(32768ull)"
    );
    assertEqualU64(
        i640_ctz(&instance, 65536ull),
        16ull,
        "ctz(65536ull)"
    );
    assertEqualU64(
        i640_ctz(&instance, 9223372036854775808ull),
        63ull,
        "ctz(9223372036854775808ull)"
    );
    assertEqualU64(
        i640_ctz(&instance, 9223372036854775807ull),
        0ull,
        "ctz(9223372036854775807ull)"
    );
    assertEqualU64(
        i640_popcnt(&instance, 18446744073709551615ull),
        64ull,
        "popcnt(18446744073709551615ull)"
    );
    assertEqualU64(
        i640_popcnt(&instance, 0ull),
        0ull,
        "popcnt(0ull)"
    );
    assertEqualU64(
        i640_popcnt(&instance, 32768ull),
        1ull,
        "popcnt(32768ull)"
    );
    assertEqualU64(
        i640_popcnt(&instance, 9223512776490647552ull),
        4ull,
        "popcnt(9223512776490647552ull)"
    );
    assertEqualU64(
        i640_popcnt(&instance, 9223372036854775807ull),
        63ull,
        "popcnt(9223372036854775807ull)"
    );
    assertEqualU64(
        i640_popcnt(&instance, 12297829381041378645ull),
        32ull,
        "popcnt(12297829381041378645ull)"
    );
    assertEqualU64(
        i640_popcnt(&instance, 11068046444512062122ull),
        32ull,
        "popcnt(11068046444512062122ull)"
    );
    assertEqualU64(
        i640_popcnt(&instance, 16045690984833335023ull),
        48ull,
        "popcnt(16045690984833335023ull)"
    );
    assertEqualU64(
        i640_extend8_s(&instance, 0ull),
        0ull,
        "extend8_s(0ull)"
    );
    assertEqualU64(
        i640_extend8_s(&instance, 127ull),
        127ull,
        "extend8_s(127ull)"
    );
    assertEqualU64(
        i640_extend8_s(&instance, 128ull),
        18446744073709551488ull,
        "extend8_s(128ull)"
    );
    assertEqualU64(
        i640_extend8_s(&instance, 255ull),
        18446744073709551615ull,
        "extend8_s(255ull)"
    );
    assertEqualU64(
        i640_extend8_s(&instance, 81985529216486656ull),
        0ull,
        "extend8_s(81985529216486656ull)"
    );
    assertEqualU64(
        i640_extend8_s(&instance, 18364758544493064832ull),
        18446744073709551488ull,
        "extend8_s(18364758544493064832ull)"
    );
    assertEqualU64(
        i640_extend8_s(&instance, 18446744073709551615ull),
        18446744073709551615ull,
        "extend8_s(18446744073709551615ull)"
    );
    assertEqualU64(
        i640_extend16_s(&instance, 0ull),
        0ull,
        "extend16_s(0ull)"
    );
    assertEqualU64(
        i640_extend16_s(&instance, 32767ull),
        32767ull,
        "extend16_s(32767ull)"
    );
    assertEqualU64(
        i640_extend16_s(&instance, 32768ull),
        18446744073709518848ull,
        "extend16_s(32768ull)"
    );
    assertEqualU64(
        i640_extend16_s(&instance, 65535ull),
        18446744073709551615ull,
        "extend16_s(65535ull)"
    );
    assertEqualU64(
        i640_extend16_s(&instance, 1311768467463733248ull),
        0ull,
        "extend16_s(1311768467463733248ull)"
    );
    assertEqualU64(
        i640_extend16_s(&instance, 18364758544493084672ull),
        18446744073709518848ull,
        "extend16_s(18364758544493084672ull)"
    );
    assertEqualU64(
        i640_extend16_s(&instance, 18446744073709551615ull),
        18446744073709551615ull,
        "extend16_s(18446744073709551615ull)"
    );
    assertEqualU64(
        i640_extend32_s(&instance, 0ull),
        0ull,
        "extend32_s(0ull)"
    );
    assertEqualU64(
        i640_extend32_s(&instance, 32767ull),
        32767ull,
        "extend32_s(32767ull)"
    );
    assertEqualU64(
        i640_extend32_s(&instance, 32768ull),
        32768ull,
        "extend32_s(32768ull)"
    );
    assertEqualU64(
        i640_extend32_s(&instance, 65535ull),
        65535ull,
        "extend32_s(65535ull)"
    );
    assertEqualU64(
        i640_extend32_s(&instance, 2147483647ull),
        2147483647ull,
        "extend32_s(2147483647ull)"
    );
    assertEqualU64(
        i640_extend32_s(&instance, 2147483648ull),
        18446744071562067968ull,
        "extend32_s(2147483648ull)"
    );
    assertEqualU64(
        i640_extend32_s(&instance, 4294967295ull),
        18446744073709551615ull,
        "extend32_s(4294967295ull)"
    );
    assertEqualU64(
        i640_extend32_s(&instance, 81985526906748928ull),
        0ull,
        "extend32_s(81985526906748928ull)"
    );
    assertEqualU64(
        i640_extend32_s(&instance, 18364758544655319040ull),
        18446744071562067968ull,
        "extend32_s(18364758544655319040ull)"
    );
    assertEqualU64(
        i640_extend32_s(&instance, 18446744073709551615ull),
        18446744073709551615ull,
        "extend32_s(18446744073709551615ull)"
    );
    assertEqualU32(
        i640_eqz(&instance, 0ull),
        1u,
        "eqz(0ull)"
    );
    assertEqualU32(
        i640_eqz(&instance, 1ull),
        0u,
        "eqz(1ull)"
    );
    assertEqualU32(
        i640_eqz(&instance, 9223372036854775808ull),
        0u,
        "eqz(9223372036854775808ull)"
    );
    assertEqualU32(
        i640_eqz(&instance, 9223372036854775807ull),
        0u,
        "eqz(9223372036854775807ull)"
    );
    assertEqualU32(
        i640_eqz(&instance, 18446744073709551615ull),
        0u,
        "eqz(18446744073709551615ull)"
    );
    assertEqualU32(
        i640_eq(&instance, 0ull, 0ull),
        1u,
        "eq(0ull, 0ull)"
    );
    assertEqualU32(
        i640_eq(&instance, 1ull, 1ull),
        1u,
        "eq(1ull, 1ull)"
    );
    assertEqualU32(
        i640_eq(&instance, 18446744073709551615ull, 1ull),
        0u,
        "eq(18446744073709551615ull, 1ull)"
    );
    assertEqualU32(
        i640_eq(&instance, 9223372036854775808ull, 9223372036854775808ull),
        1u,
        "eq(9223372036854775808ull, 9223372036854775808ull)"
    );
    assertEqualU32(
        i640_eq(&instance, 9223372036854775807ull, 9223372036854775807ull),
        1u,
        "eq(9223372036854775807ull, 9223372036854775807ull)"
    );
    assertEqualU32(
        i640_eq(&instance, 18446744073709551615ull, 18446744073709551615ull),
        1u,
        "eq(18446744073709551615ull, 18446744073709551615ull)"
    );
    assertEqualU32(
        i640_eq(&instance, 1ull, 0ull),
        0u,
        "eq(1ull, 0ull)"
    );
    assertEqualU32(
        i640_eq(&instance, 0ull, 1ull),
        0u,
        "eq(0ull, 1ull)"
    );
    assertEqualU32(
        i640_eq(&instance, 9223372036854775808ull, 0ull),
        0u,
        "eq(9223372036854775808ull, 0ull)"
    );
    assertEqualU32(
        i640_eq(&instance, 0ull, 9223372036854775808ull),
        0u,
        "eq(0ull, 9223372036854775808ull)"
    );
    assertEqualU32(
        i640_eq(&instance, 9223372036854775808ull, 18446744073709551615ull),
        0u,
        "eq(9223372036854775808ull, 18446744073709551615ull)"
    );
    assertEqualU32(
        i640_eq(&instance, 18446744073709551615ull, 9223372036854775808ull),
        0u,
        "eq(18446744073709551615ull, 9223372036854775808ull)"
    );
    assertEqualU32(
        i640_eq(&instance, 9223372036854775808ull, 9223372036854775807ull),
        0u,
        "eq(9223372036854775808ull, 9223372036854775807ull)"
    );
    assertEqualU32(
        i640_eq(&instance, 9223372036854775807ull, 9223372036854775808ull),
        0u,
        "eq(9223372036854775807ull, 9223372036854775808ull)"
    );
    assertEqualU32(
        i640_ne(&instance, 0ull, 0ull),
        0u,
        "ne(0ull, 0ull)"
    );
    assertEqualU32(
        i640_ne(&instance, 1ull, 1ull),
        0u,
        "ne(1ull, 1ull)"
    );
    assertEqualU32(
        i640_ne(&instance, 18446744073709551615ull, 1ull),
        1u,
        "ne(18446744073709551615ull, 1ull)"
    );
    assertEqualU32(
        i640_ne(&instance, 9223372036854775808ull, 9223372036854775808ull),
        0u,
        "ne(9223372036854775808ull, 9223372036854775808ull)"
    );
    assertEqualU32(
        i640_ne(&instance, 9223372036854775807ull, 9223372036854775807ull),
        0u,
        "ne(9223372036854775807ull, 9223372036854775807ull)"
    );
    assertEqualU32(
        i640_ne(&instance, 18446744073709551615ull, 18446744073709551615ull),
        0u,
        "ne(18446744073709551615ull, 18446744073709551615ull)"
    );
    assertEqualU32(
        i640_ne(&instance, 1ull, 0ull),
        1u,
        "ne(1ull, 0ull)"
    );
    assertEqualU32(
        i640_ne(&instance, 0ull, 1ull),
        1u,
        "ne(0ull, 1ull)"
    );
    assertEqualU32(
        i640_ne(&instance, 9223372036854775808ull, 0ull),
        1u,
        "ne(9223372036854775808ull, 0ull)"
    );
    assertEqualU32(
        i640_ne(&instance, 0ull, 9223372036854775808ull),
        1u,
        "ne(0ull, 9223372036854775808ull)"
    );
    assertEqualU32(
        i640_ne(&instance, 9223372036854775808ull, 18446744073709551615ull),
        1u,
        "ne(9223372036854775808ull, 18446744073709551615ull)"
    );
    assertEqualU32(
        i640_ne(&instance, 18446744073709551615ull, 9223372036854775808ull),
        1u,
        "ne(18446744073709551615ull, 9223372036854775808ull)"
    );
    assertEqualU32(
        i640_ne(&instance, 9223372036854775808ull, 9223372036854775807ull),
        1u,
        "ne(9223372036854775808ull, 9223372036854775807ull)"
    );
    assertEqualU32(
        i640_ne(&instance, 9223372036854775807ull, 9223372036854775808ull),
        1u,
        "ne(9223372036854775807ull, 9223372036854775808ull)"
    );
    assertEqualU32(
        i640_lt_s(&instance, 0ull, 0ull),
        0u,
        "lt_s(0ull, 0ull)"
    );
    assertEqualU32(
        i640_lt_s(&instance, 1ull, 1ull),
        0u,
        "lt_s(1ull, 1ull)"
    );
    assertEqualU32(
        i640_lt_s(&instance, 18446744073709551615ull, 1ull),
        1u,
        "lt_s(18446744073709551615ull, 1ull)"
    );
    assertEqualU32(
        i640_lt_s(&instance, 9223372036854775808ull, 9223372036854775808ull),
        0u,
        "lt_s(9223372036854775808ull, 9223372036854775808ull)"
    );
    assertEqualU32(
        i640_lt_s(&instance, 9223372036854775807ull, 9223372036854775807ull),
        0u,
        "lt_s(9223372036854775807ull, 9223372036854775807ull)"
    );
    assertEqualU32(
        i640_lt_s(&instance, 18446744073709551615ull, 18446744073709551615ull),
        0u,
        "lt_s(18446744073709551615ull, 18446744073709551615ull)"
    );
    assertEqualU32(
        i640_lt_s(&instance, 1ull, 0ull),
        0u,
        "lt_s(1ull, 0ull)"
    );
    assertEqualU32(
        i640_lt_s(&instance, 0ull, 1ull),
        1u,
        "lt_s(0ull, 1ull)"
    );
    assertEqualU32(
        i640_lt_s(&instance, 9223372036854775808ull, 0ull),
        1u,
        "lt_s(9223372036854775808ull, 0ull)"
    );
    assertEqualU32(
        i640_lt_s(&instance, 0ull, 9223372036854775808ull),
        0u,
        "lt_s(0ull, 9223372036854775808ull)"
    );
    assertEqualU32(
        i640_lt_s(&instance, 9223372036854775808ull, 18446744073709551615ull),
        1u,
        "lt_s(9223372036854775808ull, 18446744073709551615ull)"
    );
    assertEqualU32(
        i640_lt_s(&instance, 18446744073709551615ull, 9223372036854775808ull),
        0u,
        "lt_s(18446744073709551615ull, 9223372036854775808ull)"
    );
    assertEqualU32(
        i640_lt_s(&instance, 9223372036854775808ull, 9223372036854775807ull),
        1u,
        "lt_s(9223372036854775808ull, 9223372036854775807ull)"
    );
    assertEqualU32(
        i640_lt_s(&instance, 9223372036854775807ull, 9223372036854775808ull),
        0u,
        "lt_s(9223372036854775807ull, 9223372036854775808ull)"
    );
    assertEqualU32(
        i640_lt_u(&instance, 0ull, 0ull),
        0u,
        "lt_u(0ull, 0ull)"
    );
    assertEqualU32(
        i640_lt_u(&instance, 1ull, 1ull),
        0u,
        "lt_u(1ull, 1ull)"
    );
    assertEqualU32(
        i640_lt_u(&instance, 18446744073709551615ull, 1ull),
        0u,
        "lt_u(18446744073709551615ull, 1ull)"
    );
    assertEqualU32(
        i640_lt_u(&instance, 9223372036854775808ull, 9223372036854775808ull),
        0u,
        "lt_u(9223372036854775808ull, 9223372036854775808ull)"
    );
    assertEqualU32(
        i640_lt_u(&instance, 9223372036854775807ull, 9223372036854775807ull),
        0u,
        "lt_u(9223372036854775807ull, 9223372036854775807ull)"
    );
    assertEqualU32(
        i640_lt_u(&instance, 18446744073709551615ull, 18446744073709551615ull),
        0u,
        "lt_u(18446744073709551615ull, 18446744073709551615ull)"
    );
    assertEqualU32(
        i640_lt_u(&instance, 1ull, 0ull),
        0u,
        "lt_u(1ull, 0ull)"
    );
    assertEqualU32(
        i640_lt_u(&instance, 0ull, 1ull),
        1u,
        "lt_u(0ull, 1ull)"
    );
    assertEqualU32(
        i640_lt_u(&instance, 9223372036854775808ull, 0ull),
        0u,
        "lt_u(9223372036854775808ull, 0ull)"
    );
    assertEqualU32(
        i640_lt_u(&instance, 0ull, 9223372036854775808ull),
        1u,
        "lt_u(0ull, 9223372036854775808ull)"
    );
    assertEqualU32(
        i640_lt_u(&instance, 9223372036854775808ull, 18446744073709551615ull),
        1u,
        "lt_u(9223372036854775808ull, 18446744073709551615ull)"
    );
    assertEqualU32(
        i640_lt_u(&instance, 18446744073709551615ull, 9223372036854775808ull),
        0u,
        "lt_u(18446744073709551615ull, 9223372036854775808ull)"
    );
    assertEqualU32(
        i640_lt_u(&instance, 9223372036854775808ull, 9223372036854775807ull),
        0u,
        "lt_u(9223372036854775808ull, 9223372036854775807ull)"
    );
    assertEqualU32(
        i640_lt_u(&instance, 9223372036854775807ull, 9223372036854775808ull),
        1u,
        "lt_u(9223372036854775807ull, 9223372036854775808ull)"
    );
    assertEqualU32(
        i640_le_s(&instance, 0ull, 0ull),
        1u,
        "le_s(0ull, 0ull)"
    );
    assertEqualU32(
        i640_le_s(&instance, 1ull, 1ull),
        1u,
        "le_s(1ull, 1ull)"
    );
    assertEqualU32(
        i640_le_s(&instance, 18446744073709551615ull, 1ull),
        1u,
        "le_s(18446744073709551615ull, 1ull)"
    );
    assertEqualU32(
        i640_le_s(&instance, 9223372036854775808ull, 9223372036854775808ull),
        1u,
        "le_s(9223372036854775808ull, 9223372036854775808ull)"
    );
    assertEqualU32(
        i640_le_s(&instance, 9223372036854775807ull, 9223372036854775807ull),
        1u,
        "le_s(9223372036854775807ull, 9223372036854775807ull)"
    );
    assertEqualU32(
        i640_le_s(&instance, 18446744073709551615ull, 18446744073709551615ull),
        1u,
        "le_s(18446744073709551615ull, 18446744073709551615ull)"
    );
    assertEqualU32(
        i640_le_s(&instance, 1ull, 0ull),
        0u,
        "le_s(1ull, 0ull)"
    );
    assertEqualU32(
        i640_le_s(&instance, 0ull, 1ull),
        1u,
        "le_s(0ull, 1ull)"
    );
    assertEqualU32(
        i640_le_s(&instance, 9223372036854775808ull, 0ull),
        1u,
        "le_s(9223372036854775808ull, 0ull)"
    );
    assertEqualU32(
        i640_le_s(&instance, 0ull, 9223372036854775808ull),
        0u,
        "le_s(0ull, 9223372036854775808ull)"
    );
    assertEqualU32(
        i640_le_s(&instance, 9223372036854775808ull, 18446744073709551615ull),
        1u,
        "le_s(9223372036854775808ull, 18446744073709551615ull)"
    );
    assertEqualU32(
        i640_le_s(&instance, 18446744073709551615ull, 9223372036854775808ull),
        0u,
        "le_s(18446744073709551615ull, 9223372036854775808ull)"
    );
    assertEqualU32(
        i640_le_s(&instance, 9223372036854775808ull, 9223372036854775807ull),
        1u,
        "le_s(9223372036854775808ull, 9223372036854775807ull)"
    );
    assertEqualU32(
        i640_le_s(&instance, 9223372036854775807ull, 9223372036854775808ull),
        0u,
        "le_s(9223372036854775807ull, 9223372036854775808ull)"
    );
    assertEqualU32(
        i640_le_u(&instance, 0ull, 0ull),
        1u,
        "le_u(0ull, 0ull)"
    );
    assertEqualU32(
        i640_le_u(&instance, 1ull, 1ull),
        1u,
        "le_u(1ull, 1ull)"
    );
    assertEqualU32(
        i640_le_u(&instance, 18446744073709551615ull, 1ull),
        0u,
        "le_u(18446744073709551615ull, 1ull)"
    );
    assertEqualU32(
        i640_le_u(&instance, 9223372036854775808ull, 9223372036854775808ull),
        1u,
        "le_u(9223372036854775808ull, 9223372036854775808ull)"
    );
    assertEqualU32(
        i640_le_u(&instance, 9223372036854775807ull, 9223372036854775807ull),
        1u,
        "le_u(9223372036854775807ull, 9223372036854775807ull)"
    );
    assertEqualU32(
        i640_le_u(&instance, 18446744073709551615ull, 18446744073709551615ull),
        1u,
        "le_u(18446744073709551615ull, 18446744073709551615ull)"
    );
    assertEqualU32(
        i640_le_u(&instance, 1ull, 0ull),
        0u,
        "le_u(1ull, 0ull)"
    );
    assertEqualU32(
        i640_le_u(&instance, 0ull, 1ull),
        1u,
        "le_u(0ull, 1ull)"
    );
    assertEqualU32(
        i640_le_u(&instance, 9223372036854775808ull, 0ull),
        0u,
        "le_u(9223372036854775808ull, 0ull)"
    );
    assertEqualU32(
        i640_le_u(&instance, 0ull, 9223372036854775808ull),
        1u,
        "le_u(0ull, 9223372036854775808ull)"
    );
    assertEqualU32(
        i640_le_u(&instance, 9223372036854775808ull, 18446744073709551615ull),
        1u,
        "le_u(9223372036854775808ull, 18446744073709551615ull)"
    );
    assertEqualU32(
        i640_le_u(&instance, 18446744073709551615ull, 9223372036854775808ull),
        0u,
        "le_u(18446744073709551615ull, 9223372036854775808ull)"
    );
    assertEqualU32(
        i640_le_u(&instance, 9223372036854775808ull, 9223372036854775807ull),
        0u,
        "le_u(9223372036854775808ull, 9223372036854775807ull)"
    );
    assertEqualU32(
        i640_le_u(&instance, 9223372036854775807ull, 9223372036854775808ull),
        1u,
        "le_u(9223372036854775807ull, 9223372036854775808ull)"
    );
    assertEqualU32(
        i640_gt_s(&instance, 0ull, 0ull),
        0u,
        "gt_s(0ull, 0ull)"
    );
    assertEqualU32(
        i640_gt_s(&instance, 1ull, 1ull),
        0u,
        "gt_s(1ull, 1ull)"
    );
    assertEqualU32(
        i640_gt_s(&instance, 18446744073709551615ull, 1ull),
        0u,
        "gt_s(18446744073709551615ull, 1ull)"
    );
    assertEqualU32(
        i640_gt_s(&instance, 9223372036854775808ull, 9223372036854775808ull),
        0u,
        "gt_s(9223372036854775808ull, 9223372036854775808ull)"
    );
    assertEqualU32(
        i640_gt_s(&instance, 9223372036854775807ull, 9223372036854775807ull),
        0u,
        "gt_s(9223372036854775807ull, 9223372036854775807ull)"
    );
    assertEqualU32(
        i640_gt_s(&instance, 18446744073709551615ull, 18446744073709551615ull),
        0u,
        "gt_s(18446744073709551615ull, 18446744073709551615ull)"
    );
    assertEqualU32(
        i640_gt_s(&instance, 1ull, 0ull),
        1u,
        "gt_s(1ull, 0ull)"
    );
    assertEqualU32(
        i640_gt_s(&instance, 0ull, 1ull),
        0u,
        "gt_s(0ull, 1ull)"
    );
    assertEqualU32(
        i640_gt_s(&instance, 9223372036854775808ull, 0ull),
        0u,
        "gt_s(9223372036854775808ull, 0ull)"
    );
    assertEqualU32(
        i640_gt_s(&instance, 0ull, 9223372036854775808ull),
        1u,
        "gt_s(0ull, 9223372036854775808ull)"
    );
    assertEqualU32(
        i640_gt_s(&instance, 9223372036854775808ull, 18446744073709551615ull),
        0u,
        "gt_s(9223372036854775808ull, 18446744073709551615ull)"
    );
    assertEqualU32(
        i640_gt_s(&instance, 18446744073709551615ull, 9223372036854775808ull),
        1u,
        "gt_s(18446744073709551615ull, 9223372036854775808ull)"
    );
    assertEqualU32(
        i640_gt_s(&instance, 9223372036854775808ull, 9223372036854775807ull),
        0u,
        "gt_s(9223372036854775808ull, 9223372036854775807ull)"
    );
    assertEqualU32(
        i640_gt_s(&instance, 9223372036854775807ull, 9223372036854775808ull),
        1u,
        "gt_s(9223372036854775807ull, 9223372036854775808ull)"
    );
    assertEqualU32(
        i640_gt_u(&instance, 0ull, 0ull),
        0u,
        "gt_u(0ull, 0ull)"
    );
    assertEqualU32(
        i640_gt_u(&instance, 1ull, 1ull),
        0u,
        "gt_u(1ull, 1ull)"
    );
    assertEqualU32(
        i640_gt_u(&instance, 18446744073709551615ull, 1ull),
        1u,
        "gt_u(18446744073709551615ull, 1ull)"
    );
    assertEqualU32(
        i640_gt_u(&instance, 9223372036854775808ull, 9223372036854775808ull),
        0u,
        "gt_u(9223372036854775808ull, 9223372036854775808ull)"
    );
    assertEqualU32(
        i640_gt_u(&instance, 9223372036854775807ull, 9223372036854775807ull),
        0u,
        "gt_u(9223372036854775807ull, 9223372036854775807ull)"
    );
    assertEqualU32(
        i640_gt_u(&instance, 18446744073709551615ull, 18446744073709551615ull),
        0u,
        "gt_u(18446744073709551615ull, 18446744073709551615ull)"
    );
    assertEqualU32(
        i640_gt_u(&instance, 1ull, 0ull),
        1u,
        "gt_u(1ull, 0ull)"
    );
    assertEqualU32(
        i640_gt_u(&instance, 0ull, 1ull),
        0u,
        "gt_u(0ull, 1ull)"
    );
    assertEqualU32(
        i640_gt_u(&instance, 9223372036854775808ull, 0ull),
        1u,
        "gt_u(9223372036854775808ull, 0ull)"
    );
    assertEqualU32(
        i640_gt_u(&instance, 0ull, 9223372036854775808ull),
        0u,
        "gt_u(0ull, 9223372036854775808ull)"
    );
    assertEqualU32(
        i640_gt_u(&instance, 9223372036854775808ull, 18446744073709551615ull),
        0u,
        "gt_u(9223372036854775808ull, 18446744073709551615ull)"
    );
    assertEqualU32(
        i640_gt_u(&instance, 18446744073709551615ull, 9223372036854775808ull),
        1u,
        "gt_u(18446744073709551615ull, 9223372036854775808ull)"
    );
    assertEqualU32(
        i640_gt_u(&instance, 9223372036854775808ull, 9223372036854775807ull),
        1u,
        "gt_u(9223372036854775808ull, 9223372036854775807ull)"
    );
    assertEqualU32(
        i640_gt_u(&instance, 9223372036854775807ull, 9223372036854775808ull),
        0u,
        "gt_u(9223372036854775807ull, 9223372036854775808ull)"
    );
    assertEqualU32(
        i640_ge_s(&instance, 0ull, 0ull),
        1u,
        "ge_s(0ull, 0ull)"
    );
    assertEqualU32(
        i640_ge_s(&instance, 1ull, 1ull),
        1u,
        "ge_s(1ull, 1ull)"
    );
    assertEqualU32(
        i640_ge_s(&instance, 18446744073709551615ull, 1ull),
        0u,
        "ge_s(18446744073709551615ull, 1ull)"
    );
    assertEqualU32(
        i640_ge_s(&instance, 9223372036854775808ull, 9223372036854775808ull),
        1u,
        "ge_s(9223372036854775808ull, 9223372036854775808ull)"
    );
    assertEqualU32(
        i640_ge_s(&instance, 9223372036854775807ull, 9223372036854775807ull),
        1u,
        "ge_s(9223372036854775807ull, 9223372036854775807ull)"
    );
    assertEqualU32(
        i640_ge_s(&instance, 18446744073709551615ull, 18446744073709551615ull),
        1u,
        "ge_s(18446744073709551615ull, 18446744073709551615ull)"
    );
    assertEqualU32(
        i640_ge_s(&instance, 1ull, 0ull),
        1u,
        "ge_s(1ull, 0ull)"
    );
    assertEqualU32(
        i640_ge_s(&instance, 0ull, 1ull),
        0u,
        "ge_s(0ull, 1ull)"
    );
    assertEqualU32(
        i640_ge_s(&instance, 9223372036854775808ull, 0ull),
        0u,
        "ge_s(9223372036854775808ull, 0ull)"
    );
    assertEqualU32(
        i640_ge_s(&instance, 0ull, 9223372036854775808ull),
        1u,
        "ge_s(0ull, 9223372036854775808ull)"
    );
    assertEqualU32(
        i640_ge_s(&instance, 9223372036854775808ull, 18446744073709551615ull),
        0u,
        "ge_s(9223372036854775808ull, 18446744073709551615ull)"
    );
    assertEqualU32(
        i640_ge_s(&instance, 18446744073709551615ull, 9223372036854775808ull),
        1u,
        "ge_s(18446744073709551615ull, 9223372036854775808ull)"
    );
    assertEqualU32(
        i640_ge_s(&instance, 9223372036854775808ull, 9223372036854775807ull),
        0u,
        "ge_s(9223372036854775808ull, 9223372036854775807ull)"
    );
    assertEqualU32(
        i640_ge_s(&instance, 9223372036854775807ull, 9223372036854775808ull),
        1u,
        "ge_s(9223372036854775807ull, 9223372036854775808ull)"
    );
    assertEqualU32(
        i640_ge_u(&instance, 0ull, 0ull),
        1u,
        "ge_u(0ull, 0ull)"
    );
    assertEqualU32(
        i640_ge_u(&instance, 1ull, 1ull),
        1u,
        "ge_u(1ull, 1ull)"
    );
    assertEqualU32(
        i640_ge_u(&instance, 18446744073709551615ull, 1ull),
        1u,
        "ge_u(18446744073709551615ull, 1ull)"
    );
    assertEqualU32(
        i640_ge_u(&instance, 9223372036854775808ull, 9223372036854775808ull),
        1u,
        "ge_u(9223372036854775808ull, 9223372036854775808ull)"
    );
    assertEqualU32(
        i640_ge_u(&instance, 9223372036854775807ull, 9223372036854775807ull),
        1u,
        "ge_u(9223372036854775807ull, 9223372036854775807ull)"
    );
    assertEqualU32(
        i640_ge_u(&instance, 18446744073709551615ull, 18446744073709551615ull),
        1u,
        "ge_u(18446744073709551615ull, 18446744073709551615ull)"
    );
    assertEqualU32(
        i640_ge_u(&instance, 1ull, 0ull),
        1u,
        "ge_u(1ull, 0ull)"
    );
    assertEqualU32(
        i640_ge_u(&instance, 0ull, 1ull),
        0u,
        "ge_u(0ull, 1ull)"
    );
    assertEqualU32(
        i640_ge_u(&instance, 9223372036854775808ull, 0ull),
        1u,
        "ge_u(9223372036854775808ull, 0ull)"
    );
    assertEqualU32(
        i640_ge_u(&instance, 0ull, 9223372036854775808ull),
        0u,
        "ge_u(0ull, 9223372036854775808ull)"
    );
    assertEqualU32(
        i640_ge_u(&instance, 9223372036854775808ull, 18446744073709551615ull),
        0u,
        "ge_u(9223372036854775808ull, 18446744073709551615ull)"
    );
    assertEqualU32(
        i640_ge_u(&instance, 18446744073709551615ull, 9223372036854775808ull),
        1u,
        "ge_u(18446744073709551615ull, 9223372036854775808ull)"
    );
    assertEqualU32(
        i640_ge_u(&instance, 9223372036854775808ull, 9223372036854775807ull),
        1u,
        "ge_u(9223372036854775808ull, 9223372036854775807ull)"
    );
    assertEqualU32(
        i640_ge_u(&instance, 9223372036854775807ull, 9223372036854775808ull),
        0u,
        "ge_u(9223372036854775807ull, 9223372036854775808ull)"
    );
}
