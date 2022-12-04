
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_memory_copy.9.h"

void test() {
    memorycopy9Instance instance;
    memorycopy9Instantiate(&instance, resolveTestImports);
    printStart("memory_copy.9.wasm");
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 0u),
        0u,
        "load8_u(0u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 1u),
        1u,
        "load8_u(1u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 2u),
        2u,
        "load8_u(2u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 3u),
        3u,
        "load8_u(3u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 4u),
        4u,
        "load8_u(4u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 5u),
        5u,
        "load8_u(5u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 6u),
        6u,
        "load8_u(6u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 7u),
        7u,
        "load8_u(7u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 8u),
        8u,
        "load8_u(8u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 9u),
        9u,
        "load8_u(9u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 10u),
        10u,
        "load8_u(10u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 11u),
        11u,
        "load8_u(11u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 12u),
        12u,
        "load8_u(12u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 13u),
        13u,
        "load8_u(13u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 14u),
        14u,
        "load8_u(14u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 15u),
        15u,
        "load8_u(15u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 16u),
        16u,
        "load8_u(16u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 17u),
        17u,
        "load8_u(17u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 18u),
        18u,
        "load8_u(18u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 19u),
        19u,
        "load8_u(19u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 20u),
        20u,
        "load8_u(20u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 219u),
        0u,
        "load8_u(219u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 418u),
        0u,
        "load8_u(418u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 617u),
        0u,
        "load8_u(617u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 816u),
        0u,
        "load8_u(816u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 1015u),
        0u,
        "load8_u(1015u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 1214u),
        0u,
        "load8_u(1214u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 1413u),
        0u,
        "load8_u(1413u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 1612u),
        0u,
        "load8_u(1612u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 1811u),
        0u,
        "load8_u(1811u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 2010u),
        0u,
        "load8_u(2010u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 2209u),
        0u,
        "load8_u(2209u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 2408u),
        0u,
        "load8_u(2408u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 2607u),
        0u,
        "load8_u(2607u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 2806u),
        0u,
        "load8_u(2806u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 3005u),
        0u,
        "load8_u(3005u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 3204u),
        0u,
        "load8_u(3204u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 3403u),
        0u,
        "load8_u(3403u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 3602u),
        0u,
        "load8_u(3602u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 3801u),
        0u,
        "load8_u(3801u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 4000u),
        0u,
        "load8_u(4000u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 4199u),
        0u,
        "load8_u(4199u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 4398u),
        0u,
        "load8_u(4398u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 4597u),
        0u,
        "load8_u(4597u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 4796u),
        0u,
        "load8_u(4796u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 4995u),
        0u,
        "load8_u(4995u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 5194u),
        0u,
        "load8_u(5194u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 5393u),
        0u,
        "load8_u(5393u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 5592u),
        0u,
        "load8_u(5592u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 5791u),
        0u,
        "load8_u(5791u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 5990u),
        0u,
        "load8_u(5990u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 6189u),
        0u,
        "load8_u(6189u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 6388u),
        0u,
        "load8_u(6388u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 6587u),
        0u,
        "load8_u(6587u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 6786u),
        0u,
        "load8_u(6786u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 6985u),
        0u,
        "load8_u(6985u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 7184u),
        0u,
        "load8_u(7184u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 7383u),
        0u,
        "load8_u(7383u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 7582u),
        0u,
        "load8_u(7582u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 7781u),
        0u,
        "load8_u(7781u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 7980u),
        0u,
        "load8_u(7980u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 8179u),
        0u,
        "load8_u(8179u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 8378u),
        0u,
        "load8_u(8378u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 8577u),
        0u,
        "load8_u(8577u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 8776u),
        0u,
        "load8_u(8776u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 8975u),
        0u,
        "load8_u(8975u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 9174u),
        0u,
        "load8_u(9174u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 9373u),
        0u,
        "load8_u(9373u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 9572u),
        0u,
        "load8_u(9572u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 9771u),
        0u,
        "load8_u(9771u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 9970u),
        0u,
        "load8_u(9970u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 10169u),
        0u,
        "load8_u(10169u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 10368u),
        0u,
        "load8_u(10368u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 10567u),
        0u,
        "load8_u(10567u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 10766u),
        0u,
        "load8_u(10766u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 10965u),
        0u,
        "load8_u(10965u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 11164u),
        0u,
        "load8_u(11164u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 11363u),
        0u,
        "load8_u(11363u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 11562u),
        0u,
        "load8_u(11562u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 11761u),
        0u,
        "load8_u(11761u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 11960u),
        0u,
        "load8_u(11960u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 12159u),
        0u,
        "load8_u(12159u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 12358u),
        0u,
        "load8_u(12358u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 12557u),
        0u,
        "load8_u(12557u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 12756u),
        0u,
        "load8_u(12756u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 12955u),
        0u,
        "load8_u(12955u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 13154u),
        0u,
        "load8_u(13154u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 13353u),
        0u,
        "load8_u(13353u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 13552u),
        0u,
        "load8_u(13552u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 13751u),
        0u,
        "load8_u(13751u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 13950u),
        0u,
        "load8_u(13950u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 14149u),
        0u,
        "load8_u(14149u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 14348u),
        0u,
        "load8_u(14348u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 14547u),
        0u,
        "load8_u(14547u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 14746u),
        0u,
        "load8_u(14746u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 14945u),
        0u,
        "load8_u(14945u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 15144u),
        0u,
        "load8_u(15144u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 15343u),
        0u,
        "load8_u(15343u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 15542u),
        0u,
        "load8_u(15542u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 15741u),
        0u,
        "load8_u(15741u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 15940u),
        0u,
        "load8_u(15940u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 16139u),
        0u,
        "load8_u(16139u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 16338u),
        0u,
        "load8_u(16338u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 16537u),
        0u,
        "load8_u(16537u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 16736u),
        0u,
        "load8_u(16736u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 16935u),
        0u,
        "load8_u(16935u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 17134u),
        0u,
        "load8_u(17134u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 17333u),
        0u,
        "load8_u(17333u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 17532u),
        0u,
        "load8_u(17532u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 17731u),
        0u,
        "load8_u(17731u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 17930u),
        0u,
        "load8_u(17930u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 18129u),
        0u,
        "load8_u(18129u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 18328u),
        0u,
        "load8_u(18328u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 18527u),
        0u,
        "load8_u(18527u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 18726u),
        0u,
        "load8_u(18726u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 18925u),
        0u,
        "load8_u(18925u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 19124u),
        0u,
        "load8_u(19124u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 19323u),
        0u,
        "load8_u(19323u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 19522u),
        0u,
        "load8_u(19522u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 19721u),
        0u,
        "load8_u(19721u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 19920u),
        0u,
        "load8_u(19920u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 20119u),
        0u,
        "load8_u(20119u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 20318u),
        0u,
        "load8_u(20318u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 20517u),
        0u,
        "load8_u(20517u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 20716u),
        0u,
        "load8_u(20716u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 20915u),
        0u,
        "load8_u(20915u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 21114u),
        0u,
        "load8_u(21114u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 21313u),
        0u,
        "load8_u(21313u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 21512u),
        0u,
        "load8_u(21512u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 21711u),
        0u,
        "load8_u(21711u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 21910u),
        0u,
        "load8_u(21910u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 22109u),
        0u,
        "load8_u(22109u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 22308u),
        0u,
        "load8_u(22308u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 22507u),
        0u,
        "load8_u(22507u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 22706u),
        0u,
        "load8_u(22706u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 22905u),
        0u,
        "load8_u(22905u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 23104u),
        0u,
        "load8_u(23104u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 23303u),
        0u,
        "load8_u(23303u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 23502u),
        0u,
        "load8_u(23502u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 23701u),
        0u,
        "load8_u(23701u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 23900u),
        0u,
        "load8_u(23900u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 24099u),
        0u,
        "load8_u(24099u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 24298u),
        0u,
        "load8_u(24298u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 24497u),
        0u,
        "load8_u(24497u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 24696u),
        0u,
        "load8_u(24696u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 24895u),
        0u,
        "load8_u(24895u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 25094u),
        0u,
        "load8_u(25094u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 25293u),
        0u,
        "load8_u(25293u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 25492u),
        0u,
        "load8_u(25492u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 25691u),
        0u,
        "load8_u(25691u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 25890u),
        0u,
        "load8_u(25890u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 26089u),
        0u,
        "load8_u(26089u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 26288u),
        0u,
        "load8_u(26288u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 26487u),
        0u,
        "load8_u(26487u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 26686u),
        0u,
        "load8_u(26686u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 26885u),
        0u,
        "load8_u(26885u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 27084u),
        0u,
        "load8_u(27084u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 27283u),
        0u,
        "load8_u(27283u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 27482u),
        0u,
        "load8_u(27482u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 27681u),
        0u,
        "load8_u(27681u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 27880u),
        0u,
        "load8_u(27880u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 28079u),
        0u,
        "load8_u(28079u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 28278u),
        0u,
        "load8_u(28278u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 28477u),
        0u,
        "load8_u(28477u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 28676u),
        0u,
        "load8_u(28676u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 28875u),
        0u,
        "load8_u(28875u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 29074u),
        0u,
        "load8_u(29074u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 29273u),
        0u,
        "load8_u(29273u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 29472u),
        0u,
        "load8_u(29472u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 29671u),
        0u,
        "load8_u(29671u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 29870u),
        0u,
        "load8_u(29870u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 30069u),
        0u,
        "load8_u(30069u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 30268u),
        0u,
        "load8_u(30268u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 30467u),
        0u,
        "load8_u(30467u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 30666u),
        0u,
        "load8_u(30666u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 30865u),
        0u,
        "load8_u(30865u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 31064u),
        0u,
        "load8_u(31064u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 31263u),
        0u,
        "load8_u(31263u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 31462u),
        0u,
        "load8_u(31462u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 31661u),
        0u,
        "load8_u(31661u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 31860u),
        0u,
        "load8_u(31860u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 32059u),
        0u,
        "load8_u(32059u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 32258u),
        0u,
        "load8_u(32258u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 32457u),
        0u,
        "load8_u(32457u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 32656u),
        0u,
        "load8_u(32656u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 32855u),
        0u,
        "load8_u(32855u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 33054u),
        0u,
        "load8_u(33054u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 33253u),
        0u,
        "load8_u(33253u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 33452u),
        0u,
        "load8_u(33452u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 33651u),
        0u,
        "load8_u(33651u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 33850u),
        0u,
        "load8_u(33850u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 34049u),
        0u,
        "load8_u(34049u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 34248u),
        0u,
        "load8_u(34248u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 34447u),
        0u,
        "load8_u(34447u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 34646u),
        0u,
        "load8_u(34646u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 34845u),
        0u,
        "load8_u(34845u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 35044u),
        0u,
        "load8_u(35044u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 35243u),
        0u,
        "load8_u(35243u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 35442u),
        0u,
        "load8_u(35442u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 35641u),
        0u,
        "load8_u(35641u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 35840u),
        0u,
        "load8_u(35840u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 36039u),
        0u,
        "load8_u(36039u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 36238u),
        0u,
        "load8_u(36238u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 36437u),
        0u,
        "load8_u(36437u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 36636u),
        0u,
        "load8_u(36636u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 36835u),
        0u,
        "load8_u(36835u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 37034u),
        0u,
        "load8_u(37034u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 37233u),
        0u,
        "load8_u(37233u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 37432u),
        0u,
        "load8_u(37432u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 37631u),
        0u,
        "load8_u(37631u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 37830u),
        0u,
        "load8_u(37830u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 38029u),
        0u,
        "load8_u(38029u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 38228u),
        0u,
        "load8_u(38228u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 38427u),
        0u,
        "load8_u(38427u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 38626u),
        0u,
        "load8_u(38626u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 38825u),
        0u,
        "load8_u(38825u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 39024u),
        0u,
        "load8_u(39024u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 39223u),
        0u,
        "load8_u(39223u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 39422u),
        0u,
        "load8_u(39422u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 39621u),
        0u,
        "load8_u(39621u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 39820u),
        0u,
        "load8_u(39820u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 40019u),
        0u,
        "load8_u(40019u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 40218u),
        0u,
        "load8_u(40218u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 40417u),
        0u,
        "load8_u(40417u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 40616u),
        0u,
        "load8_u(40616u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 40815u),
        0u,
        "load8_u(40815u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 41014u),
        0u,
        "load8_u(41014u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 41213u),
        0u,
        "load8_u(41213u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 41412u),
        0u,
        "load8_u(41412u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 41611u),
        0u,
        "load8_u(41611u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 41810u),
        0u,
        "load8_u(41810u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 42009u),
        0u,
        "load8_u(42009u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 42208u),
        0u,
        "load8_u(42208u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 42407u),
        0u,
        "load8_u(42407u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 42606u),
        0u,
        "load8_u(42606u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 42805u),
        0u,
        "load8_u(42805u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 43004u),
        0u,
        "load8_u(43004u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 43203u),
        0u,
        "load8_u(43203u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 43402u),
        0u,
        "load8_u(43402u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 43601u),
        0u,
        "load8_u(43601u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 43800u),
        0u,
        "load8_u(43800u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 43999u),
        0u,
        "load8_u(43999u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 44198u),
        0u,
        "load8_u(44198u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 44397u),
        0u,
        "load8_u(44397u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 44596u),
        0u,
        "load8_u(44596u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 44795u),
        0u,
        "load8_u(44795u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 44994u),
        0u,
        "load8_u(44994u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 45193u),
        0u,
        "load8_u(45193u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 45392u),
        0u,
        "load8_u(45392u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 45591u),
        0u,
        "load8_u(45591u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 45790u),
        0u,
        "load8_u(45790u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 45989u),
        0u,
        "load8_u(45989u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 46188u),
        0u,
        "load8_u(46188u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 46387u),
        0u,
        "load8_u(46387u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 46586u),
        0u,
        "load8_u(46586u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 46785u),
        0u,
        "load8_u(46785u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 46984u),
        0u,
        "load8_u(46984u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 47183u),
        0u,
        "load8_u(47183u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 47382u),
        0u,
        "load8_u(47382u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 47581u),
        0u,
        "load8_u(47581u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 47780u),
        0u,
        "load8_u(47780u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 47979u),
        0u,
        "load8_u(47979u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 48178u),
        0u,
        "load8_u(48178u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 48377u),
        0u,
        "load8_u(48377u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 48576u),
        0u,
        "load8_u(48576u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 48775u),
        0u,
        "load8_u(48775u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 48974u),
        0u,
        "load8_u(48974u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 49173u),
        0u,
        "load8_u(49173u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 49372u),
        0u,
        "load8_u(49372u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 49571u),
        0u,
        "load8_u(49571u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 49770u),
        0u,
        "load8_u(49770u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 49969u),
        0u,
        "load8_u(49969u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 50168u),
        0u,
        "load8_u(50168u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 50367u),
        0u,
        "load8_u(50367u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 50566u),
        0u,
        "load8_u(50566u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 50765u),
        0u,
        "load8_u(50765u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 50964u),
        0u,
        "load8_u(50964u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 51163u),
        0u,
        "load8_u(51163u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 51362u),
        0u,
        "load8_u(51362u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 51561u),
        0u,
        "load8_u(51561u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 51760u),
        0u,
        "load8_u(51760u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 51959u),
        0u,
        "load8_u(51959u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 52158u),
        0u,
        "load8_u(52158u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 52357u),
        0u,
        "load8_u(52357u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 52556u),
        0u,
        "load8_u(52556u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 52755u),
        0u,
        "load8_u(52755u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 52954u),
        0u,
        "load8_u(52954u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 53153u),
        0u,
        "load8_u(53153u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 53352u),
        0u,
        "load8_u(53352u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 53551u),
        0u,
        "load8_u(53551u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 53750u),
        0u,
        "load8_u(53750u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 53949u),
        0u,
        "load8_u(53949u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 54148u),
        0u,
        "load8_u(54148u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 54347u),
        0u,
        "load8_u(54347u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 54546u),
        0u,
        "load8_u(54546u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 54745u),
        0u,
        "load8_u(54745u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 54944u),
        0u,
        "load8_u(54944u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 55143u),
        0u,
        "load8_u(55143u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 55342u),
        0u,
        "load8_u(55342u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 55541u),
        0u,
        "load8_u(55541u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 55740u),
        0u,
        "load8_u(55740u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 55939u),
        0u,
        "load8_u(55939u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 56138u),
        0u,
        "load8_u(56138u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 56337u),
        0u,
        "load8_u(56337u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 56536u),
        0u,
        "load8_u(56536u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 56735u),
        0u,
        "load8_u(56735u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 56934u),
        0u,
        "load8_u(56934u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 57133u),
        0u,
        "load8_u(57133u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 57332u),
        0u,
        "load8_u(57332u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 57531u),
        0u,
        "load8_u(57531u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 57730u),
        0u,
        "load8_u(57730u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 57929u),
        0u,
        "load8_u(57929u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 58128u),
        0u,
        "load8_u(58128u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 58327u),
        0u,
        "load8_u(58327u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 58526u),
        0u,
        "load8_u(58526u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 58725u),
        0u,
        "load8_u(58725u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 58924u),
        0u,
        "load8_u(58924u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 59123u),
        0u,
        "load8_u(59123u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 59322u),
        0u,
        "load8_u(59322u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 59521u),
        0u,
        "load8_u(59521u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 59720u),
        0u,
        "load8_u(59720u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 59919u),
        0u,
        "load8_u(59919u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 60118u),
        0u,
        "load8_u(60118u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 60317u),
        0u,
        "load8_u(60317u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 60516u),
        0u,
        "load8_u(60516u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 60715u),
        0u,
        "load8_u(60715u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 60914u),
        0u,
        "load8_u(60914u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 61113u),
        0u,
        "load8_u(61113u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 61312u),
        0u,
        "load8_u(61312u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 61511u),
        0u,
        "load8_u(61511u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 61710u),
        0u,
        "load8_u(61710u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 61909u),
        0u,
        "load8_u(61909u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 62108u),
        0u,
        "load8_u(62108u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 62307u),
        0u,
        "load8_u(62307u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 62506u),
        0u,
        "load8_u(62506u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 62705u),
        0u,
        "load8_u(62705u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 62904u),
        0u,
        "load8_u(62904u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 63103u),
        0u,
        "load8_u(63103u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 63302u),
        0u,
        "load8_u(63302u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 63501u),
        0u,
        "load8_u(63501u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 63700u),
        0u,
        "load8_u(63700u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 63899u),
        0u,
        "load8_u(63899u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 64098u),
        0u,
        "load8_u(64098u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 64297u),
        0u,
        "load8_u(64297u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 64496u),
        0u,
        "load8_u(64496u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 64695u),
        0u,
        "load8_u(64695u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 64894u),
        0u,
        "load8_u(64894u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 65093u),
        0u,
        "load8_u(65093u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 65292u),
        0u,
        "load8_u(65292u)"
    );
    assertEqualU32(
        memorycopy9_load8X5Fu(&instance, 65491u),
        0u,
        "load8_u(65491u)"
    );
}
