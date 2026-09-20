
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_select.0.h"

void test() {
    m8_selectX2E0Instance instance;
    m8_selectX2E0Instantiate(&instance, resolveTestImports);
    printStart("select.0.wasm");
    assertEqualU32(
        m8_selectX2E0Export10_selectX2Di32(&instance, 1u, 2u, 1u),
        1u,
        "select-i32(1u, 2u, 1u)"
    );
    assertEqualU64(
        m8_selectX2E0Export10_selectX2Di64(&instance, 2ull, 1ull, 1u),
        2ull,
        "select-i64(2ull, 1ull, 1u)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m8_selectX2E0Export10_selectX2Df32(&instance, 1.0, 2.0, 1u)),
        1065353216u,
        "select-f32(1.0, 2.0, 1u)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m8_selectX2E0Export10_selectX2Df64(&instance, 1.0, 2.0, 1u)),
        4607182418800017408ull,
        "select-f64(1.0, 2.0, 1u)"
    );
    assertEqualU32(
        m8_selectX2E0Export10_selectX2Di32(&instance, 1u, 2u, 0u),
        2u,
        "select-i32(1u, 2u, 0u)"
    );
    assertEqualU32(
        m8_selectX2E0Export10_selectX2Di32(&instance, 2u, 1u, 0u),
        1u,
        "select-i32(2u, 1u, 0u)"
    );
    assertEqualU64(
        m8_selectX2E0Export10_selectX2Di64(&instance, 2ull, 1ull, 4294967295u),
        2ull,
        "select-i64(2ull, 1ull, 4294967295u)"
    );
    assertEqualU64(
        m8_selectX2E0Export10_selectX2Di64(&instance, 2ull, 1ull, 4042322160u),
        2ull,
        "select-i64(2ull, 1ull, 4042322160u)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m8_selectX2E0Export10_selectX2Df32(&instance, f32_reinterpret_i32(0x7fc00000u), 1.0, 1u)),
        2143289344u,
        "select-f32(f32_reinterpret_i32(0x7fc00000u), 1.0, 1u)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m8_selectX2E0Export10_selectX2Df32(&instance, f32_reinterpret_i32(0x7f820304u), 1.0, 1u)),
        2139226884u,
        "select-f32(f32_reinterpret_i32(0x7f820304u), 1.0, 1u)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m8_selectX2E0Export10_selectX2Df32(&instance, f32_reinterpret_i32(0x7fc00000u), 1.0, 0u)),
        1065353216u,
        "select-f32(f32_reinterpret_i32(0x7fc00000u), 1.0, 0u)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m8_selectX2E0Export10_selectX2Df32(&instance, f32_reinterpret_i32(0x7f820304u), 1.0, 0u)),
        1065353216u,
        "select-f32(f32_reinterpret_i32(0x7f820304u), 1.0, 0u)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m8_selectX2E0Export10_selectX2Df32(&instance, 2.0, f32_reinterpret_i32(0x7fc00000u), 1u)),
        1073741824u,
        "select-f32(2.0, f32_reinterpret_i32(0x7fc00000u), 1u)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m8_selectX2E0Export10_selectX2Df32(&instance, 2.0, f32_reinterpret_i32(0x7f820304u), 1u)),
        1073741824u,
        "select-f32(2.0, f32_reinterpret_i32(0x7f820304u), 1u)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m8_selectX2E0Export10_selectX2Df32(&instance, 2.0, f32_reinterpret_i32(0x7fc00000u), 0u)),
        2143289344u,
        "select-f32(2.0, f32_reinterpret_i32(0x7fc00000u), 0u)"
    );
    assertEqualU32(
        i32_reinterpret_f32(m8_selectX2E0Export10_selectX2Df32(&instance, 2.0, f32_reinterpret_i32(0x7f820304u), 0u)),
        2139226884u,
        "select-f32(2.0, f32_reinterpret_i32(0x7f820304u), 0u)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m8_selectX2E0Export10_selectX2Df64(&instance, f64_reinterpret_i64(0x7ff8000000000000ull), 1.0, 1u)),
        9221120237041090560ull,
        "select-f64(f64_reinterpret_i64(0x7ff8000000000000ull), 1.0, 1u)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m8_selectX2E0Export10_selectX2Df64(&instance, f64_reinterpret_i64(0x7ff0000000020304ull), 1.0, 1u)),
        9218868437227537156ull,
        "select-f64(f64_reinterpret_i64(0x7ff0000000020304ull), 1.0, 1u)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m8_selectX2E0Export10_selectX2Df64(&instance, f64_reinterpret_i64(0x7ff8000000000000ull), 1.0, 0u)),
        4607182418800017408ull,
        "select-f64(f64_reinterpret_i64(0x7ff8000000000000ull), 1.0, 0u)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m8_selectX2E0Export10_selectX2Df64(&instance, f64_reinterpret_i64(0x7ff0000000020304ull), 1.0, 0u)),
        4607182418800017408ull,
        "select-f64(f64_reinterpret_i64(0x7ff0000000020304ull), 1.0, 0u)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m8_selectX2E0Export10_selectX2Df64(&instance, 2.0, f64_reinterpret_i64(0x7ff8000000000000ull), 1u)),
        4611686018427387904ull,
        "select-f64(2.0, f64_reinterpret_i64(0x7ff8000000000000ull), 1u)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m8_selectX2E0Export10_selectX2Df64(&instance, 2.0, f64_reinterpret_i64(0x7ff0000000020304ull), 1u)),
        4611686018427387904ull,
        "select-f64(2.0, f64_reinterpret_i64(0x7ff0000000020304ull), 1u)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m8_selectX2E0Export10_selectX2Df64(&instance, 2.0, f64_reinterpret_i64(0x7ff8000000000000ull), 0u)),
        9221120237041090560ull,
        "select-f64(2.0, f64_reinterpret_i64(0x7ff8000000000000ull), 0u)"
    );
    assertEqualU64(
        i64_reinterpret_f64(m8_selectX2E0Export10_selectX2Df64(&instance, 2.0, f64_reinterpret_i64(0x7ff0000000020304ull), 0u)),
        9218868437227537156ull,
        "select-f64(2.0, f64_reinterpret_i64(0x7ff0000000020304ull), 0u)"
    );
    assertEqualU32(
        m8_selectX2E0Export15_asX2DselectX2Dfirst(&instance, 0u),
        1u,
        "as-select-first(0u)"
    );
    assertEqualU32(
        m8_selectX2E0Export15_asX2DselectX2Dfirst(&instance, 1u),
        0u,
        "as-select-first(1u)"
    );
    assertEqualU32(
        m8_selectX2E0Export13_asX2DselectX2Dmid(&instance, 0u),
        2u,
        "as-select-mid(0u)"
    );
    assertEqualU32(
        m8_selectX2E0Export13_asX2DselectX2Dmid(&instance, 1u),
        2u,
        "as-select-mid(1u)"
    );
    assertEqualU32(
        m8_selectX2E0Export14_asX2DselectX2Dlast(&instance, 0u),
        2u,
        "as-select-last(0u)"
    );
    assertEqualU32(
        m8_selectX2E0Export14_asX2DselectX2Dlast(&instance, 1u),
        3u,
        "as-select-last(1u)"
    );
    assertEqualU32(
        m8_selectX2E0Export13_asX2DloopX2Dfirst(&instance, 0u),
        3u,
        "as-loop-first(0u)"
    );
    assertEqualU32(
        m8_selectX2E0Export13_asX2DloopX2Dfirst(&instance, 1u),
        2u,
        "as-loop-first(1u)"
    );
    assertEqualU32(
        m8_selectX2E0Export11_asX2DloopX2Dmid(&instance, 0u),
        3u,
        "as-loop-mid(0u)"
    );
    assertEqualU32(
        m8_selectX2E0Export11_asX2DloopX2Dmid(&instance, 1u),
        2u,
        "as-loop-mid(1u)"
    );
    assertEqualU32(
        m8_selectX2E0Export12_asX2DloopX2Dlast(&instance, 0u),
        3u,
        "as-loop-last(0u)"
    );
    assertEqualU32(
        m8_selectX2E0Export12_asX2DloopX2Dlast(&instance, 1u),
        2u,
        "as-loop-last(1u)"
    );
    m8_selectX2E0Export15_asX2DifX2Dcondition(&instance, 0u);
    m8_selectX2E0Export15_asX2DifX2Dcondition(&instance, 1u);
    assertEqualU32(
        m8_selectX2E0Export10_asX2DifX2Dthen(&instance, 0u),
        3u,
        "as-if-then(0u)"
    );
    assertEqualU32(
        m8_selectX2E0Export10_asX2DifX2Dthen(&instance, 1u),
        2u,
        "as-if-then(1u)"
    );
    assertEqualU32(
        m8_selectX2E0Export10_asX2DifX2Delse(&instance, 0u),
        3u,
        "as-if-else(0u)"
    );
    assertEqualU32(
        m8_selectX2E0Export10_asX2DifX2Delse(&instance, 1u),
        2u,
        "as-if-else(1u)"
    );
    assertEqualU32(
        m8_selectX2E0Export14_asX2DbrX5FifX2Dfirst(&instance, 0u),
        3u,
        "as-br_if-first(0u)"
    );
    assertEqualU32(
        m8_selectX2E0Export14_asX2DbrX5FifX2Dfirst(&instance, 1u),
        2u,
        "as-br_if-first(1u)"
    );
    assertEqualU32(
        m8_selectX2E0Export13_asX2DbrX5FifX2Dlast(&instance, 0u),
        2u,
        "as-br_if-last(0u)"
    );
    assertEqualU32(
        m8_selectX2E0Export13_asX2DbrX5FifX2Dlast(&instance, 1u),
        2u,
        "as-br_if-last(1u)"
    );
    assertEqualU32(
        m8_selectX2E0Export17_asX2DbrX5FtableX2Dfirst(&instance, 0u),
        3u,
        "as-br_table-first(0u)"
    );
    assertEqualU32(
        m8_selectX2E0Export17_asX2DbrX5FtableX2Dfirst(&instance, 1u),
        2u,
        "as-br_table-first(1u)"
    );
    assertEqualU32(
        m8_selectX2E0Export16_asX2DbrX5FtableX2Dlast(&instance, 0u),
        2u,
        "as-br_table-last(0u)"
    );
    assertEqualU32(
        m8_selectX2E0Export16_asX2DbrX5FtableX2Dlast(&instance, 1u),
        2u,
        "as-br_table-last(1u)"
    );
    m8_selectX2E0Export14_asX2DstoreX2Dfirst(&instance, 0u);
    m8_selectX2E0Export14_asX2DstoreX2Dfirst(&instance, 1u);
    m8_selectX2E0Export13_asX2DstoreX2Dlast(&instance, 0u);
    m8_selectX2E0Export13_asX2DstoreX2Dlast(&instance, 1u);
    assertEqualU32(
        m8_selectX2E0Export20_asX2DmemoryX2EgrowX2Dvalue(&instance, 0u),
        1u,
        "as-memory.grow-value(0u)"
    );
    assertEqualU32(
        m8_selectX2E0Export20_asX2DmemoryX2EgrowX2Dvalue(&instance, 1u),
        3u,
        "as-memory.grow-value(1u)"
    );
    assertEqualU32(
        m8_selectX2E0Export13_asX2DcallX2Dvalue(&instance, 0u),
        2u,
        "as-call-value(0u)"
    );
    assertEqualU32(
        m8_selectX2E0Export13_asX2DcallX2Dvalue(&instance, 1u),
        1u,
        "as-call-value(1u)"
    );
    assertEqualU32(
        m8_selectX2E0Export15_asX2DreturnX2Dvalue(&instance, 0u),
        2u,
        "as-return-value(0u)"
    );
    assertEqualU32(
        m8_selectX2E0Export15_asX2DreturnX2Dvalue(&instance, 1u),
        1u,
        "as-return-value(1u)"
    );
    m8_selectX2E0Export15_asX2DdropX2Doperand(&instance, 0u);
    m8_selectX2E0Export15_asX2DdropX2Doperand(&instance, 1u);
    assertEqualU32(
        m8_selectX2E0Export11_asX2DbrX2Dvalue(&instance, 0u),
        2u,
        "as-br-value(0u)"
    );
    assertEqualU32(
        m8_selectX2E0Export11_asX2DbrX2Dvalue(&instance, 1u),
        1u,
        "as-br-value(1u)"
    );
    assertEqualU32(
        m8_selectX2E0Export18_asX2DlocalX2EsetX2Dvalue(&instance, 0u),
        2u,
        "as-local.set-value(0u)"
    );
    assertEqualU32(
        m8_selectX2E0Export18_asX2DlocalX2EsetX2Dvalue(&instance, 1u),
        1u,
        "as-local.set-value(1u)"
    );
    assertEqualU32(
        m8_selectX2E0Export18_asX2DlocalX2EteeX2Dvalue(&instance, 0u),
        2u,
        "as-local.tee-value(0u)"
    );
    assertEqualU32(
        m8_selectX2E0Export18_asX2DlocalX2EteeX2Dvalue(&instance, 1u),
        1u,
        "as-local.tee-value(1u)"
    );
    assertEqualU32(
        m8_selectX2E0Export19_asX2DglobalX2EsetX2Dvalue(&instance, 0u),
        2u,
        "as-global.set-value(0u)"
    );
    assertEqualU32(
        m8_selectX2E0Export19_asX2DglobalX2EsetX2Dvalue(&instance, 1u),
        1u,
        "as-global.set-value(1u)"
    );
    assertEqualU32(
        m8_selectX2E0Export15_asX2DloadX2Doperand(&instance, 0u),
        1u,
        "as-load-operand(0u)"
    );
    assertEqualU32(
        m8_selectX2E0Export15_asX2DloadX2Doperand(&instance, 1u),
        1u,
        "as-load-operand(1u)"
    );
    assertEqualU32(
        m8_selectX2E0Export16_asX2DunaryX2Doperand(&instance, 0u),
        0u,
        "as-unary-operand(0u)"
    );
    assertEqualU32(
        m8_selectX2E0Export16_asX2DunaryX2Doperand(&instance, 1u),
        1u,
        "as-unary-operand(1u)"
    );
    assertEqualU32(
        m8_selectX2E0Export17_asX2DbinaryX2Doperand(&instance, 0u),
        4u,
        "as-binary-operand(0u)"
    );
    assertEqualU32(
        m8_selectX2E0Export17_asX2DbinaryX2Doperand(&instance, 1u),
        1u,
        "as-binary-operand(1u)"
    );
    assertEqualU32(
        m8_selectX2E0Export15_asX2DtestX2Doperand(&instance, 0u),
        0u,
        "as-test-operand(0u)"
    );
    assertEqualU32(
        m8_selectX2E0Export15_asX2DtestX2Doperand(&instance, 1u),
        1u,
        "as-test-operand(1u)"
    );
    assertEqualU32(
        m8_selectX2E0Export15_asX2DcompareX2Dleft(&instance, 0u),
        0u,
        "as-compare-left(0u)"
    );
    assertEqualU32(
        m8_selectX2E0Export15_asX2DcompareX2Dleft(&instance, 1u),
        1u,
        "as-compare-left(1u)"
    );
    assertEqualU32(
        m8_selectX2E0Export16_asX2DcompareX2Dright(&instance, 0u),
        0u,
        "as-compare-right(0u)"
    );
    assertEqualU32(
        m8_selectX2E0Export16_asX2DcompareX2Dright(&instance, 1u),
        1u,
        "as-compare-right(1u)"
    );
    assertEqualU32(
        m8_selectX2E0Export18_asX2DconvertX2Doperand(&instance, 0u),
        0u,
        "as-convert-operand(0u)"
    );
    assertEqualU32(
        m8_selectX2E0Export18_asX2DconvertX2Doperand(&instance, 1u),
        1u,
        "as-convert-operand(1u)"
    );
}
