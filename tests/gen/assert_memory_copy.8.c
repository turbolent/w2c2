
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_memory_copy.8.h"

void test() {
    memorycopy8Instance instance;
    memorycopy8Instantiate(&instance, resolveTestImports);
    printStart("memory_copy.8.wasm");
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 0u),
        0u,
        "load8_u(0u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 1u),
        1u,
        "load8_u(1u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 2u),
        2u,
        "load8_u(2u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 3u),
        3u,
        "load8_u(3u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 4u),
        4u,
        "load8_u(4u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 5u),
        5u,
        "load8_u(5u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 6u),
        6u,
        "load8_u(6u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 7u),
        7u,
        "load8_u(7u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 8u),
        8u,
        "load8_u(8u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 9u),
        9u,
        "load8_u(9u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 10u),
        10u,
        "load8_u(10u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 11u),
        11u,
        "load8_u(11u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 12u),
        12u,
        "load8_u(12u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 13u),
        13u,
        "load8_u(13u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 14u),
        14u,
        "load8_u(14u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 15u),
        15u,
        "load8_u(15u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 16u),
        16u,
        "load8_u(16u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 17u),
        17u,
        "load8_u(17u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 18u),
        18u,
        "load8_u(18u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 19u),
        19u,
        "load8_u(19u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 218u),
        0u,
        "load8_u(218u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 417u),
        0u,
        "load8_u(417u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 616u),
        0u,
        "load8_u(616u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 815u),
        0u,
        "load8_u(815u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 1014u),
        0u,
        "load8_u(1014u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 1213u),
        0u,
        "load8_u(1213u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 1412u),
        0u,
        "load8_u(1412u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 1611u),
        0u,
        "load8_u(1611u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 1810u),
        0u,
        "load8_u(1810u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 2009u),
        0u,
        "load8_u(2009u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 2208u),
        0u,
        "load8_u(2208u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 2407u),
        0u,
        "load8_u(2407u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 2606u),
        0u,
        "load8_u(2606u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 2805u),
        0u,
        "load8_u(2805u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 3004u),
        0u,
        "load8_u(3004u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 3203u),
        0u,
        "load8_u(3203u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 3402u),
        0u,
        "load8_u(3402u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 3601u),
        0u,
        "load8_u(3601u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 3800u),
        0u,
        "load8_u(3800u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 3999u),
        0u,
        "load8_u(3999u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 4198u),
        0u,
        "load8_u(4198u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 4397u),
        0u,
        "load8_u(4397u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 4596u),
        0u,
        "load8_u(4596u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 4795u),
        0u,
        "load8_u(4795u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 4994u),
        0u,
        "load8_u(4994u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 5193u),
        0u,
        "load8_u(5193u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 5392u),
        0u,
        "load8_u(5392u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 5591u),
        0u,
        "load8_u(5591u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 5790u),
        0u,
        "load8_u(5790u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 5989u),
        0u,
        "load8_u(5989u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 6188u),
        0u,
        "load8_u(6188u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 6387u),
        0u,
        "load8_u(6387u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 6586u),
        0u,
        "load8_u(6586u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 6785u),
        0u,
        "load8_u(6785u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 6984u),
        0u,
        "load8_u(6984u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 7183u),
        0u,
        "load8_u(7183u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 7382u),
        0u,
        "load8_u(7382u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 7581u),
        0u,
        "load8_u(7581u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 7780u),
        0u,
        "load8_u(7780u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 7979u),
        0u,
        "load8_u(7979u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 8178u),
        0u,
        "load8_u(8178u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 8377u),
        0u,
        "load8_u(8377u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 8576u),
        0u,
        "load8_u(8576u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 8775u),
        0u,
        "load8_u(8775u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 8974u),
        0u,
        "load8_u(8974u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 9173u),
        0u,
        "load8_u(9173u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 9372u),
        0u,
        "load8_u(9372u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 9571u),
        0u,
        "load8_u(9571u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 9770u),
        0u,
        "load8_u(9770u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 9969u),
        0u,
        "load8_u(9969u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 10168u),
        0u,
        "load8_u(10168u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 10367u),
        0u,
        "load8_u(10367u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 10566u),
        0u,
        "load8_u(10566u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 10765u),
        0u,
        "load8_u(10765u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 10964u),
        0u,
        "load8_u(10964u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 11163u),
        0u,
        "load8_u(11163u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 11362u),
        0u,
        "load8_u(11362u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 11561u),
        0u,
        "load8_u(11561u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 11760u),
        0u,
        "load8_u(11760u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 11959u),
        0u,
        "load8_u(11959u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 12158u),
        0u,
        "load8_u(12158u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 12357u),
        0u,
        "load8_u(12357u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 12556u),
        0u,
        "load8_u(12556u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 12755u),
        0u,
        "load8_u(12755u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 12954u),
        0u,
        "load8_u(12954u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 13153u),
        0u,
        "load8_u(13153u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 13352u),
        0u,
        "load8_u(13352u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 13551u),
        0u,
        "load8_u(13551u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 13750u),
        0u,
        "load8_u(13750u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 13949u),
        0u,
        "load8_u(13949u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 14148u),
        0u,
        "load8_u(14148u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 14347u),
        0u,
        "load8_u(14347u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 14546u),
        0u,
        "load8_u(14546u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 14745u),
        0u,
        "load8_u(14745u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 14944u),
        0u,
        "load8_u(14944u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 15143u),
        0u,
        "load8_u(15143u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 15342u),
        0u,
        "load8_u(15342u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 15541u),
        0u,
        "load8_u(15541u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 15740u),
        0u,
        "load8_u(15740u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 15939u),
        0u,
        "load8_u(15939u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 16138u),
        0u,
        "load8_u(16138u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 16337u),
        0u,
        "load8_u(16337u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 16536u),
        0u,
        "load8_u(16536u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 16735u),
        0u,
        "load8_u(16735u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 16934u),
        0u,
        "load8_u(16934u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 17133u),
        0u,
        "load8_u(17133u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 17332u),
        0u,
        "load8_u(17332u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 17531u),
        0u,
        "load8_u(17531u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 17730u),
        0u,
        "load8_u(17730u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 17929u),
        0u,
        "load8_u(17929u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 18128u),
        0u,
        "load8_u(18128u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 18327u),
        0u,
        "load8_u(18327u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 18526u),
        0u,
        "load8_u(18526u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 18725u),
        0u,
        "load8_u(18725u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 18924u),
        0u,
        "load8_u(18924u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 19123u),
        0u,
        "load8_u(19123u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 19322u),
        0u,
        "load8_u(19322u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 19521u),
        0u,
        "load8_u(19521u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 19720u),
        0u,
        "load8_u(19720u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 19919u),
        0u,
        "load8_u(19919u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 20118u),
        0u,
        "load8_u(20118u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 20317u),
        0u,
        "load8_u(20317u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 20516u),
        0u,
        "load8_u(20516u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 20715u),
        0u,
        "load8_u(20715u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 20914u),
        0u,
        "load8_u(20914u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 21113u),
        0u,
        "load8_u(21113u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 21312u),
        0u,
        "load8_u(21312u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 21511u),
        0u,
        "load8_u(21511u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 21710u),
        0u,
        "load8_u(21710u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 21909u),
        0u,
        "load8_u(21909u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 22108u),
        0u,
        "load8_u(22108u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 22307u),
        0u,
        "load8_u(22307u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 22506u),
        0u,
        "load8_u(22506u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 22705u),
        0u,
        "load8_u(22705u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 22904u),
        0u,
        "load8_u(22904u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 23103u),
        0u,
        "load8_u(23103u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 23302u),
        0u,
        "load8_u(23302u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 23501u),
        0u,
        "load8_u(23501u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 23700u),
        0u,
        "load8_u(23700u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 23899u),
        0u,
        "load8_u(23899u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 24098u),
        0u,
        "load8_u(24098u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 24297u),
        0u,
        "load8_u(24297u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 24496u),
        0u,
        "load8_u(24496u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 24695u),
        0u,
        "load8_u(24695u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 24894u),
        0u,
        "load8_u(24894u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 25093u),
        0u,
        "load8_u(25093u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 25292u),
        0u,
        "load8_u(25292u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 25491u),
        0u,
        "load8_u(25491u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 25690u),
        0u,
        "load8_u(25690u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 25889u),
        0u,
        "load8_u(25889u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 26088u),
        0u,
        "load8_u(26088u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 26287u),
        0u,
        "load8_u(26287u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 26486u),
        0u,
        "load8_u(26486u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 26685u),
        0u,
        "load8_u(26685u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 26884u),
        0u,
        "load8_u(26884u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 27083u),
        0u,
        "load8_u(27083u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 27282u),
        0u,
        "load8_u(27282u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 27481u),
        0u,
        "load8_u(27481u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 27680u),
        0u,
        "load8_u(27680u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 27879u),
        0u,
        "load8_u(27879u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 28078u),
        0u,
        "load8_u(28078u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 28277u),
        0u,
        "load8_u(28277u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 28476u),
        0u,
        "load8_u(28476u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 28675u),
        0u,
        "load8_u(28675u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 28874u),
        0u,
        "load8_u(28874u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 29073u),
        0u,
        "load8_u(29073u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 29272u),
        0u,
        "load8_u(29272u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 29471u),
        0u,
        "load8_u(29471u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 29670u),
        0u,
        "load8_u(29670u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 29869u),
        0u,
        "load8_u(29869u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 30068u),
        0u,
        "load8_u(30068u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 30267u),
        0u,
        "load8_u(30267u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 30466u),
        0u,
        "load8_u(30466u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 30665u),
        0u,
        "load8_u(30665u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 30864u),
        0u,
        "load8_u(30864u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 31063u),
        0u,
        "load8_u(31063u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 31262u),
        0u,
        "load8_u(31262u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 31461u),
        0u,
        "load8_u(31461u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 31660u),
        0u,
        "load8_u(31660u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 31859u),
        0u,
        "load8_u(31859u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 32058u),
        0u,
        "load8_u(32058u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 32257u),
        0u,
        "load8_u(32257u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 32456u),
        0u,
        "load8_u(32456u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 32655u),
        0u,
        "load8_u(32655u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 32854u),
        0u,
        "load8_u(32854u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 33053u),
        0u,
        "load8_u(33053u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 33252u),
        0u,
        "load8_u(33252u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 33451u),
        0u,
        "load8_u(33451u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 33650u),
        0u,
        "load8_u(33650u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 33849u),
        0u,
        "load8_u(33849u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 34048u),
        0u,
        "load8_u(34048u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 34247u),
        0u,
        "load8_u(34247u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 34446u),
        0u,
        "load8_u(34446u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 34645u),
        0u,
        "load8_u(34645u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 34844u),
        0u,
        "load8_u(34844u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 35043u),
        0u,
        "load8_u(35043u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 35242u),
        0u,
        "load8_u(35242u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 35441u),
        0u,
        "load8_u(35441u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 35640u),
        0u,
        "load8_u(35640u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 35839u),
        0u,
        "load8_u(35839u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 36038u),
        0u,
        "load8_u(36038u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 36237u),
        0u,
        "load8_u(36237u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 36436u),
        0u,
        "load8_u(36436u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 36635u),
        0u,
        "load8_u(36635u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 36834u),
        0u,
        "load8_u(36834u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 37033u),
        0u,
        "load8_u(37033u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 37232u),
        0u,
        "load8_u(37232u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 37431u),
        0u,
        "load8_u(37431u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 37630u),
        0u,
        "load8_u(37630u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 37829u),
        0u,
        "load8_u(37829u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 38028u),
        0u,
        "load8_u(38028u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 38227u),
        0u,
        "load8_u(38227u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 38426u),
        0u,
        "load8_u(38426u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 38625u),
        0u,
        "load8_u(38625u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 38824u),
        0u,
        "load8_u(38824u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 39023u),
        0u,
        "load8_u(39023u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 39222u),
        0u,
        "load8_u(39222u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 39421u),
        0u,
        "load8_u(39421u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 39620u),
        0u,
        "load8_u(39620u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 39819u),
        0u,
        "load8_u(39819u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 40018u),
        0u,
        "load8_u(40018u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 40217u),
        0u,
        "load8_u(40217u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 40416u),
        0u,
        "load8_u(40416u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 40615u),
        0u,
        "load8_u(40615u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 40814u),
        0u,
        "load8_u(40814u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 41013u),
        0u,
        "load8_u(41013u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 41212u),
        0u,
        "load8_u(41212u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 41411u),
        0u,
        "load8_u(41411u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 41610u),
        0u,
        "load8_u(41610u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 41809u),
        0u,
        "load8_u(41809u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 42008u),
        0u,
        "load8_u(42008u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 42207u),
        0u,
        "load8_u(42207u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 42406u),
        0u,
        "load8_u(42406u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 42605u),
        0u,
        "load8_u(42605u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 42804u),
        0u,
        "load8_u(42804u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 43003u),
        0u,
        "load8_u(43003u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 43202u),
        0u,
        "load8_u(43202u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 43401u),
        0u,
        "load8_u(43401u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 43600u),
        0u,
        "load8_u(43600u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 43799u),
        0u,
        "load8_u(43799u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 43998u),
        0u,
        "load8_u(43998u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 44197u),
        0u,
        "load8_u(44197u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 44396u),
        0u,
        "load8_u(44396u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 44595u),
        0u,
        "load8_u(44595u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 44794u),
        0u,
        "load8_u(44794u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 44993u),
        0u,
        "load8_u(44993u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 45192u),
        0u,
        "load8_u(45192u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 45391u),
        0u,
        "load8_u(45391u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 45590u),
        0u,
        "load8_u(45590u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 45789u),
        0u,
        "load8_u(45789u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 45988u),
        0u,
        "load8_u(45988u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 46187u),
        0u,
        "load8_u(46187u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 46386u),
        0u,
        "load8_u(46386u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 46585u),
        0u,
        "load8_u(46585u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 46784u),
        0u,
        "load8_u(46784u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 46983u),
        0u,
        "load8_u(46983u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 47182u),
        0u,
        "load8_u(47182u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 47381u),
        0u,
        "load8_u(47381u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 47580u),
        0u,
        "load8_u(47580u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 47779u),
        0u,
        "load8_u(47779u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 47978u),
        0u,
        "load8_u(47978u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 48177u),
        0u,
        "load8_u(48177u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 48376u),
        0u,
        "load8_u(48376u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 48575u),
        0u,
        "load8_u(48575u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 48774u),
        0u,
        "load8_u(48774u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 48973u),
        0u,
        "load8_u(48973u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 49172u),
        0u,
        "load8_u(49172u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 49371u),
        0u,
        "load8_u(49371u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 49570u),
        0u,
        "load8_u(49570u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 49769u),
        0u,
        "load8_u(49769u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 49968u),
        0u,
        "load8_u(49968u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 50167u),
        0u,
        "load8_u(50167u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 50366u),
        0u,
        "load8_u(50366u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 50565u),
        0u,
        "load8_u(50565u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 50764u),
        0u,
        "load8_u(50764u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 50963u),
        0u,
        "load8_u(50963u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 51162u),
        0u,
        "load8_u(51162u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 51361u),
        0u,
        "load8_u(51361u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 51560u),
        0u,
        "load8_u(51560u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 51759u),
        0u,
        "load8_u(51759u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 51958u),
        0u,
        "load8_u(51958u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 52157u),
        0u,
        "load8_u(52157u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 52356u),
        0u,
        "load8_u(52356u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 52555u),
        0u,
        "load8_u(52555u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 52754u),
        0u,
        "load8_u(52754u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 52953u),
        0u,
        "load8_u(52953u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 53152u),
        0u,
        "load8_u(53152u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 53351u),
        0u,
        "load8_u(53351u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 53550u),
        0u,
        "load8_u(53550u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 53749u),
        0u,
        "load8_u(53749u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 53948u),
        0u,
        "load8_u(53948u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 54147u),
        0u,
        "load8_u(54147u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 54346u),
        0u,
        "load8_u(54346u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 54545u),
        0u,
        "load8_u(54545u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 54744u),
        0u,
        "load8_u(54744u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 54943u),
        0u,
        "load8_u(54943u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 55142u),
        0u,
        "load8_u(55142u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 55341u),
        0u,
        "load8_u(55341u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 55540u),
        0u,
        "load8_u(55540u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 55739u),
        0u,
        "load8_u(55739u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 55938u),
        0u,
        "load8_u(55938u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 56137u),
        0u,
        "load8_u(56137u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 56336u),
        0u,
        "load8_u(56336u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 56535u),
        0u,
        "load8_u(56535u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 56734u),
        0u,
        "load8_u(56734u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 56933u),
        0u,
        "load8_u(56933u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 57132u),
        0u,
        "load8_u(57132u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 57331u),
        0u,
        "load8_u(57331u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 57530u),
        0u,
        "load8_u(57530u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 57729u),
        0u,
        "load8_u(57729u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 57928u),
        0u,
        "load8_u(57928u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 58127u),
        0u,
        "load8_u(58127u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 58326u),
        0u,
        "load8_u(58326u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 58525u),
        0u,
        "load8_u(58525u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 58724u),
        0u,
        "load8_u(58724u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 58923u),
        0u,
        "load8_u(58923u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 59122u),
        0u,
        "load8_u(59122u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 59321u),
        0u,
        "load8_u(59321u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 59520u),
        0u,
        "load8_u(59520u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 59719u),
        0u,
        "load8_u(59719u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 59918u),
        0u,
        "load8_u(59918u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 60117u),
        0u,
        "load8_u(60117u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 60316u),
        0u,
        "load8_u(60316u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 60515u),
        0u,
        "load8_u(60515u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 60714u),
        0u,
        "load8_u(60714u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 60913u),
        0u,
        "load8_u(60913u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 61112u),
        0u,
        "load8_u(61112u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 61311u),
        0u,
        "load8_u(61311u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 61510u),
        0u,
        "load8_u(61510u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 61709u),
        0u,
        "load8_u(61709u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 61908u),
        0u,
        "load8_u(61908u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 62107u),
        0u,
        "load8_u(62107u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 62306u),
        0u,
        "load8_u(62306u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 62505u),
        0u,
        "load8_u(62505u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 62704u),
        0u,
        "load8_u(62704u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 62903u),
        0u,
        "load8_u(62903u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 63102u),
        0u,
        "load8_u(63102u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 63301u),
        0u,
        "load8_u(63301u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 63500u),
        0u,
        "load8_u(63500u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 63699u),
        0u,
        "load8_u(63699u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 63898u),
        0u,
        "load8_u(63898u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 64097u),
        0u,
        "load8_u(64097u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 64296u),
        0u,
        "load8_u(64296u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 64495u),
        0u,
        "load8_u(64495u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 64694u),
        0u,
        "load8_u(64694u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 64893u),
        0u,
        "load8_u(64893u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 65092u),
        0u,
        "load8_u(65092u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 65291u),
        0u,
        "load8_u(65291u)"
    );
    assertEqualU32(
        memorycopy8_load8X5Fu(&instance, 65490u),
        0u,
        "load8_u(65490u)"
    );
}
