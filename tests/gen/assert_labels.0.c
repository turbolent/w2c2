
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_labels.0.h"

void test() {
    m8_labelsX2E0Instance instance;
    m8_labelsX2E0Instantiate(&instance, resolveTestImports);
    printStart("labels.0.wasm");
    assertEqualU32(
        m8_labelsX2E0Export5_block(&instance),
        1u,
        "block()"
    );
    assertEqualU32(
        m8_labelsX2E0Export5_loop1(&instance),
        5u,
        "loop1()"
    );
    assertEqualU32(
        m8_labelsX2E0Export5_loop2(&instance),
        8u,
        "loop2()"
    );
    assertEqualU32(
        m8_labelsX2E0Export5_loop3(&instance),
        1u,
        "loop3()"
    );
    assertEqualU32(
        m8_labelsX2E0Export5_loop4(&instance, 8u),
        16u,
        "loop4(8u)"
    );
    assertEqualU32(
        m8_labelsX2E0Export5_loop5(&instance),
        2u,
        "loop5()"
    );
    assertEqualU32(
        m8_labelsX2E0Export5_loop6(&instance),
        3u,
        "loop6()"
    );
    assertEqualU32(
        m8_labelsX2E0Export2_if(&instance),
        5u,
        "if()"
    );
    assertEqualU32(
        m8_labelsX2E0Export3_if2(&instance),
        5u,
        "if2()"
    );
    assertEqualU32(
        m8_labelsX2E0Export6_switch(&instance, 0u),
        50u,
        "switch(0u)"
    );
    assertEqualU32(
        m8_labelsX2E0Export6_switch(&instance, 1u),
        20u,
        "switch(1u)"
    );
    assertEqualU32(
        m8_labelsX2E0Export6_switch(&instance, 2u),
        20u,
        "switch(2u)"
    );
    assertEqualU32(
        m8_labelsX2E0Export6_switch(&instance, 3u),
        3u,
        "switch(3u)"
    );
    assertEqualU32(
        m8_labelsX2E0Export6_switch(&instance, 4u),
        50u,
        "switch(4u)"
    );
    assertEqualU32(
        m8_labelsX2E0Export6_switch(&instance, 5u),
        50u,
        "switch(5u)"
    );
    assertEqualU32(
        m8_labelsX2E0Export6_return(&instance, 0u),
        0u,
        "return(0u)"
    );
    assertEqualU32(
        m8_labelsX2E0Export6_return(&instance, 1u),
        2u,
        "return(1u)"
    );
    assertEqualU32(
        m8_labelsX2E0Export6_return(&instance, 2u),
        2u,
        "return(2u)"
    );
    assertEqualU32(
        m8_labelsX2E0Export6_brX5Fif0(&instance),
        29u,
        "br_if0()"
    );
    assertEqualU32(
        m8_labelsX2E0Export6_brX5Fif1(&instance),
        1u,
        "br_if1()"
    );
    assertEqualU32(
        m8_labelsX2E0Export6_brX5Fif2(&instance),
        1u,
        "br_if2()"
    );
    assertEqualU32(
        m8_labelsX2E0Export6_brX5Fif3(&instance),
        2u,
        "br_if3()"
    );
    assertEqualU32(
        m8_labelsX2E0Export2_br(&instance),
        1u,
        "br()"
    );
    assertEqualU32(
        m8_labelsX2E0Export9_shadowing(&instance),
        1u,
        "shadowing()"
    );
    assertEqualU32(
        m8_labelsX2E0Export12_redefinition(&instance),
        5u,
        "redefinition()"
    );
}
