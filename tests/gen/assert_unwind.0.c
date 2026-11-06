#include "test.h"
#include "test_unwind.0.h"

void test(void) {
    static m8_unwindX2E0Instance instance;
    m8_unwindX2E0Instantiate(&instance, resolveTestImports);
    printStart("unwind.0.wasm");
#if W2C2_RUNTIME_CHECKS
    assertTrap(m8_unwindX2E0Export26_funcX2DunwindX2DbyX2Dunreachable(&instance), trapUnreachable, "func-unwind-by-unreachable()");
#endif
    (void)(m8_unwindX2E0Export17_funcX2DunwindX2DbyX2Dbr(&instance));
    assertEqualU32(
        m8_unwindX2E0Export23_funcX2DunwindX2DbyX2DbrX2Dvalue(&instance),
        9u,
        "func-unwind-by-br-value()"
    );
    (void)(m8_unwindX2E0Export20_funcX2DunwindX2DbyX2DbrX5Fif(&instance));
    assertEqualU32(
        m8_unwindX2E0Export26_funcX2DunwindX2DbyX2DbrX5FifX2Dvalue(&instance),
        9u,
        "func-unwind-by-br_if-value()"
    );
    (void)(m8_unwindX2E0Export23_funcX2DunwindX2DbyX2DbrX5Ftable(&instance));
    assertEqualU32(
        m8_unwindX2E0Export29_funcX2DunwindX2DbyX2DbrX5FtableX2Dvalue(&instance),
        9u,
        "func-unwind-by-br_table-value()"
    );
    assertEqualU32(
        m8_unwindX2E0Export21_funcX2DunwindX2DbyX2Dreturn(&instance),
        9u,
        "func-unwind-by-return()"
    );
#if W2C2_RUNTIME_CHECKS
    assertTrap(m8_unwindX2E0Export27_blockX2DunwindX2DbyX2Dunreachable(&instance), trapUnreachable, "block-unwind-by-unreachable()");
#endif
    assertEqualU32(
        m8_unwindX2E0Export18_blockX2DunwindX2DbyX2Dbr(&instance),
        9u,
        "block-unwind-by-br()"
    );
    assertEqualU32(
        m8_unwindX2E0Export24_blockX2DunwindX2DbyX2DbrX2Dvalue(&instance),
        9u,
        "block-unwind-by-br-value()"
    );
    assertEqualU32(
        m8_unwindX2E0Export21_blockX2DunwindX2DbyX2DbrX5Fif(&instance),
        9u,
        "block-unwind-by-br_if()"
    );
    assertEqualU32(
        m8_unwindX2E0Export27_blockX2DunwindX2DbyX2DbrX5FifX2Dvalue(&instance),
        9u,
        "block-unwind-by-br_if-value()"
    );
    assertEqualU32(
        m8_unwindX2E0Export24_blockX2DunwindX2DbyX2DbrX5Ftable(&instance),
        9u,
        "block-unwind-by-br_table()"
    );
    assertEqualU32(
        m8_unwindX2E0Export30_blockX2DunwindX2DbyX2DbrX5FtableX2Dvalue(&instance),
        9u,
        "block-unwind-by-br_table-value()"
    );
    assertEqualU32(
        m8_unwindX2E0Export22_blockX2DunwindX2DbyX2Dreturn(&instance),
        9u,
        "block-unwind-by-return()"
    );
#if W2C2_RUNTIME_CHECKS
    assertTrap(m8_unwindX2E0Export34_blockX2DnestedX2DunwindX2DbyX2Dunreachable(&instance), trapUnreachable, "block-nested-unwind-by-unreachable()");
#endif
    assertEqualU32(
        m8_unwindX2E0Export25_blockX2DnestedX2DunwindX2DbyX2Dbr(&instance),
        9u,
        "block-nested-unwind-by-br()"
    );
    assertEqualU32(
        m8_unwindX2E0Export31_blockX2DnestedX2DunwindX2DbyX2DbrX2Dvalue(&instance),
        9u,
        "block-nested-unwind-by-br-value()"
    );
    assertEqualU32(
        m8_unwindX2E0Export28_blockX2DnestedX2DunwindX2DbyX2DbrX5Fif(&instance),
        9u,
        "block-nested-unwind-by-br_if()"
    );
    assertEqualU32(
        m8_unwindX2E0Export34_blockX2DnestedX2DunwindX2DbyX2DbrX5FifX2Dvalue(&instance),
        9u,
        "block-nested-unwind-by-br_if-value()"
    );
    assertEqualU32(
        m8_unwindX2E0Export31_blockX2DnestedX2DunwindX2DbyX2DbrX5Ftable(&instance),
        9u,
        "block-nested-unwind-by-br_table()"
    );
    assertEqualU32(
        m8_unwindX2E0Export37_blockX2DnestedX2DunwindX2DbyX2DbrX5FtableX2Dvalue(&instance),
        9u,
        "block-nested-unwind-by-br_table-value()"
    );
    assertEqualU32(
        m8_unwindX2E0Export29_blockX2DnestedX2DunwindX2DbyX2Dreturn(&instance),
        9u,
        "block-nested-unwind-by-return()"
    );
#if W2C2_RUNTIME_CHECKS
    assertTrap(m8_unwindX2E0Export23_unaryX2DafterX2Dunreachable(&instance), trapUnreachable, "unary-after-unreachable()");
#endif
    assertEqualU32(
        m8_unwindX2E0Export14_unaryX2DafterX2Dbr(&instance),
        9u,
        "unary-after-br()"
    );
    assertEqualU32(
        m8_unwindX2E0Export17_unaryX2DafterX2DbrX5Fif(&instance),
        9u,
        "unary-after-br_if()"
    );
    assertEqualU32(
        m8_unwindX2E0Export20_unaryX2DafterX2DbrX5Ftable(&instance),
        9u,
        "unary-after-br_table()"
    );
    assertEqualU32(
        m8_unwindX2E0Export18_unaryX2DafterX2Dreturn(&instance),
        9u,
        "unary-after-return()"
    );
#if W2C2_RUNTIME_CHECKS
    assertTrap(m8_unwindX2E0Export24_binaryX2DafterX2Dunreachable(&instance), trapUnreachable, "binary-after-unreachable()");
#endif
    assertEqualU32(
        m8_unwindX2E0Export15_binaryX2DafterX2Dbr(&instance),
        9u,
        "binary-after-br()"
    );
    assertEqualU32(
        m8_unwindX2E0Export18_binaryX2DafterX2DbrX5Fif(&instance),
        9u,
        "binary-after-br_if()"
    );
    assertEqualU32(
        m8_unwindX2E0Export21_binaryX2DafterX2DbrX5Ftable(&instance),
        9u,
        "binary-after-br_table()"
    );
    assertEqualU32(
        m8_unwindX2E0Export19_binaryX2DafterX2Dreturn(&instance),
        9u,
        "binary-after-return()"
    );
#if W2C2_RUNTIME_CHECKS
    assertTrap(m8_unwindX2E0Export24_selectX2DafterX2Dunreachable(&instance), trapUnreachable, "select-after-unreachable()");
#endif
    assertEqualU32(
        m8_unwindX2E0Export15_selectX2DafterX2Dbr(&instance),
        9u,
        "select-after-br()"
    );
    assertEqualU32(
        m8_unwindX2E0Export18_selectX2DafterX2DbrX5Fif(&instance),
        9u,
        "select-after-br_if()"
    );
    assertEqualU32(
        m8_unwindX2E0Export21_selectX2DafterX2DbrX5Ftable(&instance),
        9u,
        "select-after-br_table()"
    );
    assertEqualU32(
        m8_unwindX2E0Export19_selectX2DafterX2Dreturn(&instance),
        9u,
        "select-after-return()"
    );
#if W2C2_RUNTIME_CHECKS
    assertTrap(m8_unwindX2E0Export29_blockX2DvalueX2DafterX2Dunreachable(&instance), trapUnreachable, "block-value-after-unreachable()");
#endif
    assertEqualU32(
        m8_unwindX2E0Export20_blockX2DvalueX2DafterX2Dbr(&instance),
        9u,
        "block-value-after-br()"
    );
    assertEqualU32(
        m8_unwindX2E0Export23_blockX2DvalueX2DafterX2DbrX5Fif(&instance),
        9u,
        "block-value-after-br_if()"
    );
    assertEqualU32(
        m8_unwindX2E0Export26_blockX2DvalueX2DafterX2DbrX5Ftable(&instance),
        9u,
        "block-value-after-br_table()"
    );
    assertEqualU32(
        m8_unwindX2E0Export24_blockX2DvalueX2DafterX2Dreturn(&instance),
        9u,
        "block-value-after-return()"
    );
#if W2C2_RUNTIME_CHECKS
    assertTrap(m8_unwindX2E0Export28_loopX2DvalueX2DafterX2Dunreachable(&instance), trapUnreachable, "loop-value-after-unreachable()");
#endif
    assertEqualU32(
        m8_unwindX2E0Export19_loopX2DvalueX2DafterX2Dbr(&instance),
        9u,
        "loop-value-after-br()"
    );
    assertEqualU32(
        m8_unwindX2E0Export22_loopX2DvalueX2DafterX2DbrX5Fif(&instance),
        9u,
        "loop-value-after-br_if()"
    );
    assertEqualU32(
        m8_unwindX2E0Export25_loopX2DvalueX2DafterX2DbrX5Ftable(&instance),
        9u,
        "loop-value-after-br_table()"
    );
    assertEqualU32(
        m8_unwindX2E0Export23_loopX2DvalueX2DafterX2Dreturn(&instance),
        9u,
        "loop-value-after-return()"
    );
    m8_unwindX2E0FreeInstance(&instance);
}
