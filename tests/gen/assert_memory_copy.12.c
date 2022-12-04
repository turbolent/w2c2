
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_memory_copy.12.h"

void test() {
    memorycopy12Instance instance;
    memorycopy12Instantiate(&instance, resolveTestImports);
    printStart("memory_copy.12.wasm");
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 198u),
        0u,
        "load8_u(198u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 397u),
        0u,
        "load8_u(397u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 596u),
        0u,
        "load8_u(596u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 795u),
        0u,
        "load8_u(795u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 994u),
        0u,
        "load8_u(994u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 1193u),
        0u,
        "load8_u(1193u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 1392u),
        0u,
        "load8_u(1392u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 1591u),
        0u,
        "load8_u(1591u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 1790u),
        0u,
        "load8_u(1790u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 1989u),
        0u,
        "load8_u(1989u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 2188u),
        0u,
        "load8_u(2188u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 2387u),
        0u,
        "load8_u(2387u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 2586u),
        0u,
        "load8_u(2586u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 2785u),
        0u,
        "load8_u(2785u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 2984u),
        0u,
        "load8_u(2984u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 3183u),
        0u,
        "load8_u(3183u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 3382u),
        0u,
        "load8_u(3382u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 3581u),
        0u,
        "load8_u(3581u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 3780u),
        0u,
        "load8_u(3780u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 3979u),
        0u,
        "load8_u(3979u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 4178u),
        0u,
        "load8_u(4178u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 4377u),
        0u,
        "load8_u(4377u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 4576u),
        0u,
        "load8_u(4576u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 4775u),
        0u,
        "load8_u(4775u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 4974u),
        0u,
        "load8_u(4974u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 5173u),
        0u,
        "load8_u(5173u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 5372u),
        0u,
        "load8_u(5372u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 5571u),
        0u,
        "load8_u(5571u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 5770u),
        0u,
        "load8_u(5770u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 5969u),
        0u,
        "load8_u(5969u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 6168u),
        0u,
        "load8_u(6168u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 6367u),
        0u,
        "load8_u(6367u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 6566u),
        0u,
        "load8_u(6566u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 6765u),
        0u,
        "load8_u(6765u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 6964u),
        0u,
        "load8_u(6964u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 7163u),
        0u,
        "load8_u(7163u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 7362u),
        0u,
        "load8_u(7362u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 7561u),
        0u,
        "load8_u(7561u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 7760u),
        0u,
        "load8_u(7760u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 7959u),
        0u,
        "load8_u(7959u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 8158u),
        0u,
        "load8_u(8158u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 8357u),
        0u,
        "load8_u(8357u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 8556u),
        0u,
        "load8_u(8556u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 8755u),
        0u,
        "load8_u(8755u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 8954u),
        0u,
        "load8_u(8954u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 9153u),
        0u,
        "load8_u(9153u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 9352u),
        0u,
        "load8_u(9352u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 9551u),
        0u,
        "load8_u(9551u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 9750u),
        0u,
        "load8_u(9750u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 9949u),
        0u,
        "load8_u(9949u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 10148u),
        0u,
        "load8_u(10148u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 10347u),
        0u,
        "load8_u(10347u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 10546u),
        0u,
        "load8_u(10546u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 10745u),
        0u,
        "load8_u(10745u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 10944u),
        0u,
        "load8_u(10944u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 11143u),
        0u,
        "load8_u(11143u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 11342u),
        0u,
        "load8_u(11342u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 11541u),
        0u,
        "load8_u(11541u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 11740u),
        0u,
        "load8_u(11740u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 11939u),
        0u,
        "load8_u(11939u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 12138u),
        0u,
        "load8_u(12138u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 12337u),
        0u,
        "load8_u(12337u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 12536u),
        0u,
        "load8_u(12536u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 12735u),
        0u,
        "load8_u(12735u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 12934u),
        0u,
        "load8_u(12934u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 13133u),
        0u,
        "load8_u(13133u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 13332u),
        0u,
        "load8_u(13332u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 13531u),
        0u,
        "load8_u(13531u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 13730u),
        0u,
        "load8_u(13730u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 13929u),
        0u,
        "load8_u(13929u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 14128u),
        0u,
        "load8_u(14128u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 14327u),
        0u,
        "load8_u(14327u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 14526u),
        0u,
        "load8_u(14526u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 14725u),
        0u,
        "load8_u(14725u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 14924u),
        0u,
        "load8_u(14924u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 15123u),
        0u,
        "load8_u(15123u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 15322u),
        0u,
        "load8_u(15322u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 15521u),
        0u,
        "load8_u(15521u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 15720u),
        0u,
        "load8_u(15720u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 15919u),
        0u,
        "load8_u(15919u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 16118u),
        0u,
        "load8_u(16118u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 16317u),
        0u,
        "load8_u(16317u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 16516u),
        0u,
        "load8_u(16516u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 16715u),
        0u,
        "load8_u(16715u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 16914u),
        0u,
        "load8_u(16914u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 17113u),
        0u,
        "load8_u(17113u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 17312u),
        0u,
        "load8_u(17312u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 17511u),
        0u,
        "load8_u(17511u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 17710u),
        0u,
        "load8_u(17710u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 17909u),
        0u,
        "load8_u(17909u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 18108u),
        0u,
        "load8_u(18108u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 18307u),
        0u,
        "load8_u(18307u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 18506u),
        0u,
        "load8_u(18506u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 18705u),
        0u,
        "load8_u(18705u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 18904u),
        0u,
        "load8_u(18904u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 19103u),
        0u,
        "load8_u(19103u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 19302u),
        0u,
        "load8_u(19302u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 19501u),
        0u,
        "load8_u(19501u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 19700u),
        0u,
        "load8_u(19700u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 19899u),
        0u,
        "load8_u(19899u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 20098u),
        0u,
        "load8_u(20098u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 20297u),
        0u,
        "load8_u(20297u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 20496u),
        0u,
        "load8_u(20496u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 20695u),
        0u,
        "load8_u(20695u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 20894u),
        0u,
        "load8_u(20894u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 21093u),
        0u,
        "load8_u(21093u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 21292u),
        0u,
        "load8_u(21292u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 21491u),
        0u,
        "load8_u(21491u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 21690u),
        0u,
        "load8_u(21690u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 21889u),
        0u,
        "load8_u(21889u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 22088u),
        0u,
        "load8_u(22088u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 22287u),
        0u,
        "load8_u(22287u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 22486u),
        0u,
        "load8_u(22486u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 22685u),
        0u,
        "load8_u(22685u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 22884u),
        0u,
        "load8_u(22884u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 23083u),
        0u,
        "load8_u(23083u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 23282u),
        0u,
        "load8_u(23282u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 23481u),
        0u,
        "load8_u(23481u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 23680u),
        0u,
        "load8_u(23680u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 23879u),
        0u,
        "load8_u(23879u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 24078u),
        0u,
        "load8_u(24078u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 24277u),
        0u,
        "load8_u(24277u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 24476u),
        0u,
        "load8_u(24476u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 24675u),
        0u,
        "load8_u(24675u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 24874u),
        0u,
        "load8_u(24874u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 25073u),
        0u,
        "load8_u(25073u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 25272u),
        0u,
        "load8_u(25272u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 25471u),
        0u,
        "load8_u(25471u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 25670u),
        0u,
        "load8_u(25670u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 25869u),
        0u,
        "load8_u(25869u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 26068u),
        0u,
        "load8_u(26068u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 26267u),
        0u,
        "load8_u(26267u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 26466u),
        0u,
        "load8_u(26466u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 26665u),
        0u,
        "load8_u(26665u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 26864u),
        0u,
        "load8_u(26864u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 27063u),
        0u,
        "load8_u(27063u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 27262u),
        0u,
        "load8_u(27262u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 27461u),
        0u,
        "load8_u(27461u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 27660u),
        0u,
        "load8_u(27660u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 27859u),
        0u,
        "load8_u(27859u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 28058u),
        0u,
        "load8_u(28058u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 28257u),
        0u,
        "load8_u(28257u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 28456u),
        0u,
        "load8_u(28456u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 28655u),
        0u,
        "load8_u(28655u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 28854u),
        0u,
        "load8_u(28854u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 29053u),
        0u,
        "load8_u(29053u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 29252u),
        0u,
        "load8_u(29252u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 29451u),
        0u,
        "load8_u(29451u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 29650u),
        0u,
        "load8_u(29650u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 29849u),
        0u,
        "load8_u(29849u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 30048u),
        0u,
        "load8_u(30048u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 30247u),
        0u,
        "load8_u(30247u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 30446u),
        0u,
        "load8_u(30446u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 30645u),
        0u,
        "load8_u(30645u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 30844u),
        0u,
        "load8_u(30844u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 31043u),
        0u,
        "load8_u(31043u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 31242u),
        0u,
        "load8_u(31242u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 31441u),
        0u,
        "load8_u(31441u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 31640u),
        0u,
        "load8_u(31640u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 31839u),
        0u,
        "load8_u(31839u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 32038u),
        0u,
        "load8_u(32038u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 32237u),
        0u,
        "load8_u(32237u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 32436u),
        0u,
        "load8_u(32436u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 32635u),
        0u,
        "load8_u(32635u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 32834u),
        0u,
        "load8_u(32834u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 33033u),
        0u,
        "load8_u(33033u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 33232u),
        0u,
        "load8_u(33232u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 33431u),
        0u,
        "load8_u(33431u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 33630u),
        0u,
        "load8_u(33630u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 33829u),
        0u,
        "load8_u(33829u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 34028u),
        0u,
        "load8_u(34028u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 34227u),
        0u,
        "load8_u(34227u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 34426u),
        0u,
        "load8_u(34426u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 34625u),
        0u,
        "load8_u(34625u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 34824u),
        0u,
        "load8_u(34824u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 35023u),
        0u,
        "load8_u(35023u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 35222u),
        0u,
        "load8_u(35222u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 35421u),
        0u,
        "load8_u(35421u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 35620u),
        0u,
        "load8_u(35620u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 35819u),
        0u,
        "load8_u(35819u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 36018u),
        0u,
        "load8_u(36018u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 36217u),
        0u,
        "load8_u(36217u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 36416u),
        0u,
        "load8_u(36416u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 36615u),
        0u,
        "load8_u(36615u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 36814u),
        0u,
        "load8_u(36814u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 37013u),
        0u,
        "load8_u(37013u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 37212u),
        0u,
        "load8_u(37212u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 37411u),
        0u,
        "load8_u(37411u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 37610u),
        0u,
        "load8_u(37610u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 37809u),
        0u,
        "load8_u(37809u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 38008u),
        0u,
        "load8_u(38008u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 38207u),
        0u,
        "load8_u(38207u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 38406u),
        0u,
        "load8_u(38406u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 38605u),
        0u,
        "load8_u(38605u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 38804u),
        0u,
        "load8_u(38804u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 39003u),
        0u,
        "load8_u(39003u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 39202u),
        0u,
        "load8_u(39202u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 39401u),
        0u,
        "load8_u(39401u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 39600u),
        0u,
        "load8_u(39600u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 39799u),
        0u,
        "load8_u(39799u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 39998u),
        0u,
        "load8_u(39998u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 40197u),
        0u,
        "load8_u(40197u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 40396u),
        0u,
        "load8_u(40396u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 40595u),
        0u,
        "load8_u(40595u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 40794u),
        0u,
        "load8_u(40794u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 40993u),
        0u,
        "load8_u(40993u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 41192u),
        0u,
        "load8_u(41192u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 41391u),
        0u,
        "load8_u(41391u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 41590u),
        0u,
        "load8_u(41590u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 41789u),
        0u,
        "load8_u(41789u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 41988u),
        0u,
        "load8_u(41988u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 42187u),
        0u,
        "load8_u(42187u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 42386u),
        0u,
        "load8_u(42386u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 42585u),
        0u,
        "load8_u(42585u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 42784u),
        0u,
        "load8_u(42784u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 42983u),
        0u,
        "load8_u(42983u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 43182u),
        0u,
        "load8_u(43182u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 43381u),
        0u,
        "load8_u(43381u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 43580u),
        0u,
        "load8_u(43580u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 43779u),
        0u,
        "load8_u(43779u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 43978u),
        0u,
        "load8_u(43978u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 44177u),
        0u,
        "load8_u(44177u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 44376u),
        0u,
        "load8_u(44376u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 44575u),
        0u,
        "load8_u(44575u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 44774u),
        0u,
        "load8_u(44774u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 44973u),
        0u,
        "load8_u(44973u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 45172u),
        0u,
        "load8_u(45172u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 45371u),
        0u,
        "load8_u(45371u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 45570u),
        0u,
        "load8_u(45570u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 45769u),
        0u,
        "load8_u(45769u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 45968u),
        0u,
        "load8_u(45968u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 46167u),
        0u,
        "load8_u(46167u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 46366u),
        0u,
        "load8_u(46366u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 46565u),
        0u,
        "load8_u(46565u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 46764u),
        0u,
        "load8_u(46764u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 46963u),
        0u,
        "load8_u(46963u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 47162u),
        0u,
        "load8_u(47162u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 47361u),
        0u,
        "load8_u(47361u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 47560u),
        0u,
        "load8_u(47560u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 47759u),
        0u,
        "load8_u(47759u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 47958u),
        0u,
        "load8_u(47958u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 48157u),
        0u,
        "load8_u(48157u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 48356u),
        0u,
        "load8_u(48356u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 48555u),
        0u,
        "load8_u(48555u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 48754u),
        0u,
        "load8_u(48754u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 48953u),
        0u,
        "load8_u(48953u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 49152u),
        0u,
        "load8_u(49152u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 49351u),
        0u,
        "load8_u(49351u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 49550u),
        0u,
        "load8_u(49550u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 49749u),
        0u,
        "load8_u(49749u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 49948u),
        0u,
        "load8_u(49948u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 50147u),
        0u,
        "load8_u(50147u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 50346u),
        0u,
        "load8_u(50346u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 50545u),
        0u,
        "load8_u(50545u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 50744u),
        0u,
        "load8_u(50744u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 50943u),
        0u,
        "load8_u(50943u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 51142u),
        0u,
        "load8_u(51142u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 51341u),
        0u,
        "load8_u(51341u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 51540u),
        0u,
        "load8_u(51540u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 51739u),
        0u,
        "load8_u(51739u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 51938u),
        0u,
        "load8_u(51938u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 52137u),
        0u,
        "load8_u(52137u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 52336u),
        0u,
        "load8_u(52336u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 52535u),
        0u,
        "load8_u(52535u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 52734u),
        0u,
        "load8_u(52734u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 52933u),
        0u,
        "load8_u(52933u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 53132u),
        0u,
        "load8_u(53132u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 53331u),
        0u,
        "load8_u(53331u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 53530u),
        0u,
        "load8_u(53530u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 53729u),
        0u,
        "load8_u(53729u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 53928u),
        0u,
        "load8_u(53928u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 54127u),
        0u,
        "load8_u(54127u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 54326u),
        0u,
        "load8_u(54326u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 54525u),
        0u,
        "load8_u(54525u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 54724u),
        0u,
        "load8_u(54724u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 54923u),
        0u,
        "load8_u(54923u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 55122u),
        0u,
        "load8_u(55122u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 55321u),
        0u,
        "load8_u(55321u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 55520u),
        0u,
        "load8_u(55520u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 55719u),
        0u,
        "load8_u(55719u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 55918u),
        0u,
        "load8_u(55918u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 56117u),
        0u,
        "load8_u(56117u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 56316u),
        0u,
        "load8_u(56316u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 56515u),
        0u,
        "load8_u(56515u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 56714u),
        0u,
        "load8_u(56714u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 56913u),
        0u,
        "load8_u(56913u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 57112u),
        0u,
        "load8_u(57112u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 57311u),
        0u,
        "load8_u(57311u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 57510u),
        0u,
        "load8_u(57510u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 57709u),
        0u,
        "load8_u(57709u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 57908u),
        0u,
        "load8_u(57908u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 58107u),
        0u,
        "load8_u(58107u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 58306u),
        0u,
        "load8_u(58306u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 58505u),
        0u,
        "load8_u(58505u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 58704u),
        0u,
        "load8_u(58704u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 58903u),
        0u,
        "load8_u(58903u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 59102u),
        0u,
        "load8_u(59102u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 59301u),
        0u,
        "load8_u(59301u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 59500u),
        0u,
        "load8_u(59500u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 59699u),
        0u,
        "load8_u(59699u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 59898u),
        0u,
        "load8_u(59898u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 60097u),
        0u,
        "load8_u(60097u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 60296u),
        0u,
        "load8_u(60296u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 60495u),
        0u,
        "load8_u(60495u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 60694u),
        0u,
        "load8_u(60694u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 60893u),
        0u,
        "load8_u(60893u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 61092u),
        0u,
        "load8_u(61092u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 61291u),
        0u,
        "load8_u(61291u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 61490u),
        0u,
        "load8_u(61490u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 61689u),
        0u,
        "load8_u(61689u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 61888u),
        0u,
        "load8_u(61888u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 62087u),
        0u,
        "load8_u(62087u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 62286u),
        0u,
        "load8_u(62286u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 62485u),
        0u,
        "load8_u(62485u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 62684u),
        0u,
        "load8_u(62684u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 62883u),
        0u,
        "load8_u(62883u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 63082u),
        0u,
        "load8_u(63082u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 63281u),
        0u,
        "load8_u(63281u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 63480u),
        0u,
        "load8_u(63480u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 63679u),
        0u,
        "load8_u(63679u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 63878u),
        0u,
        "load8_u(63878u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 64077u),
        0u,
        "load8_u(64077u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 64276u),
        0u,
        "load8_u(64276u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 64475u),
        0u,
        "load8_u(64475u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 64674u),
        0u,
        "load8_u(64674u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 64873u),
        0u,
        "load8_u(64873u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 65072u),
        0u,
        "load8_u(65072u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 65271u),
        0u,
        "load8_u(65271u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 65470u),
        0u,
        "load8_u(65470u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 65486u),
        0u,
        "load8_u(65486u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 65487u),
        1u,
        "load8_u(65487u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 65488u),
        2u,
        "load8_u(65488u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 65489u),
        3u,
        "load8_u(65489u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 65490u),
        4u,
        "load8_u(65490u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 65491u),
        5u,
        "load8_u(65491u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 65492u),
        6u,
        "load8_u(65492u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 65493u),
        7u,
        "load8_u(65493u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 65494u),
        8u,
        "load8_u(65494u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 65495u),
        9u,
        "load8_u(65495u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 65496u),
        10u,
        "load8_u(65496u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 65497u),
        11u,
        "load8_u(65497u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 65498u),
        12u,
        "load8_u(65498u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 65499u),
        13u,
        "load8_u(65499u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 65500u),
        14u,
        "load8_u(65500u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 65501u),
        15u,
        "load8_u(65501u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 65502u),
        16u,
        "load8_u(65502u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 65503u),
        17u,
        "load8_u(65503u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 65504u),
        18u,
        "load8_u(65504u)"
    );
    assertEqualU32(
        memorycopy12_load8X5Fu(&instance, 65505u),
        19u,
        "load8_u(65505u)"
    );
}
