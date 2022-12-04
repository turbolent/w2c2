
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_memory_copy.96.h"

void test() {
    memorycopy96Instance instance;
    memorycopy96Instantiate(&instance, resolveTestImports);
    printStart("memory_copy.96.wasm");
    memorycopy96_test(&instance);
    printOK("test()");
    assertEqualU32(
        memorycopy96_checkRange(&instance, 0u, 124u, 0u),
        4294967295u,
        "checkRange(0u, 124u, 0u)"
    );
    assertEqualU32(
        memorycopy96_checkRange(&instance, 124u, 1517u, 9u),
        4294967295u,
        "checkRange(124u, 1517u, 9u)"
    );
    assertEqualU32(
        memorycopy96_checkRange(&instance, 1517u, 2132u, 0u),
        4294967295u,
        "checkRange(1517u, 2132u, 0u)"
    );
    assertEqualU32(
        memorycopy96_checkRange(&instance, 2132u, 2827u, 10u),
        4294967295u,
        "checkRange(2132u, 2827u, 10u)"
    );
    assertEqualU32(
        memorycopy96_checkRange(&instance, 2827u, 2921u, 92u),
        4294967295u,
        "checkRange(2827u, 2921u, 92u)"
    );
    assertEqualU32(
        memorycopy96_checkRange(&instance, 2921u, 3538u, 83u),
        4294967295u,
        "checkRange(2921u, 3538u, 83u)"
    );
    assertEqualU32(
        memorycopy96_checkRange(&instance, 3538u, 3786u, 77u),
        4294967295u,
        "checkRange(3538u, 3786u, 77u)"
    );
    assertEqualU32(
        memorycopy96_checkRange(&instance, 3786u, 4042u, 97u),
        4294967295u,
        "checkRange(3786u, 4042u, 97u)"
    );
    assertEqualU32(
        memorycopy96_checkRange(&instance, 4042u, 4651u, 99u),
        4294967295u,
        "checkRange(4042u, 4651u, 99u)"
    );
    assertEqualU32(
        memorycopy96_checkRange(&instance, 4651u, 5057u, 0u),
        4294967295u,
        "checkRange(4651u, 5057u, 0u)"
    );
    assertEqualU32(
        memorycopy96_checkRange(&instance, 5057u, 5109u, 99u),
        4294967295u,
        "checkRange(5057u, 5109u, 99u)"
    );
    assertEqualU32(
        memorycopy96_checkRange(&instance, 5109u, 5291u, 0u),
        4294967295u,
        "checkRange(5109u, 5291u, 0u)"
    );
    assertEqualU32(
        memorycopy96_checkRange(&instance, 5291u, 5524u, 72u),
        4294967295u,
        "checkRange(5291u, 5524u, 72u)"
    );
    assertEqualU32(
        memorycopy96_checkRange(&instance, 5524u, 5691u, 92u),
        4294967295u,
        "checkRange(5524u, 5691u, 92u)"
    );
    assertEqualU32(
        memorycopy96_checkRange(&instance, 5691u, 6552u, 83u),
        4294967295u,
        "checkRange(5691u, 6552u, 83u)"
    );
    assertEqualU32(
        memorycopy96_checkRange(&instance, 6552u, 7133u, 77u),
        4294967295u,
        "checkRange(6552u, 7133u, 77u)"
    );
    assertEqualU32(
        memorycopy96_checkRange(&instance, 7133u, 7665u, 99u),
        4294967295u,
        "checkRange(7133u, 7665u, 99u)"
    );
    assertEqualU32(
        memorycopy96_checkRange(&instance, 7665u, 8314u, 0u),
        4294967295u,
        "checkRange(7665u, 8314u, 0u)"
    );
    assertEqualU32(
        memorycopy96_checkRange(&instance, 8314u, 8360u, 62u),
        4294967295u,
        "checkRange(8314u, 8360u, 62u)"
    );
    assertEqualU32(
        memorycopy96_checkRange(&instance, 8360u, 8793u, 86u),
        4294967295u,
        "checkRange(8360u, 8793u, 86u)"
    );
    assertEqualU32(
        memorycopy96_checkRange(&instance, 8793u, 8979u, 83u),
        4294967295u,
        "checkRange(8793u, 8979u, 83u)"
    );
    assertEqualU32(
        memorycopy96_checkRange(&instance, 8979u, 9373u, 79u),
        4294967295u,
        "checkRange(8979u, 9373u, 79u)"
    );
    assertEqualU32(
        memorycopy96_checkRange(&instance, 9373u, 9518u, 95u),
        4294967295u,
        "checkRange(9373u, 9518u, 95u)"
    );
    assertEqualU32(
        memorycopy96_checkRange(&instance, 9518u, 9934u, 59u),
        4294967295u,
        "checkRange(9518u, 9934u, 59u)"
    );
    assertEqualU32(
        memorycopy96_checkRange(&instance, 9934u, 10087u, 77u),
        4294967295u,
        "checkRange(9934u, 10087u, 77u)"
    );
    assertEqualU32(
        memorycopy96_checkRange(&instance, 10087u, 10206u, 5u),
        4294967295u,
        "checkRange(10087u, 10206u, 5u)"
    );
    assertEqualU32(
        memorycopy96_checkRange(&instance, 10206u, 10230u, 77u),
        4294967295u,
        "checkRange(10206u, 10230u, 77u)"
    );
    assertEqualU32(
        memorycopy96_checkRange(&instance, 10230u, 10249u, 41u),
        4294967295u,
        "checkRange(10230u, 10249u, 41u)"
    );
    assertEqualU32(
        memorycopy96_checkRange(&instance, 10249u, 11148u, 83u),
        4294967295u,
        "checkRange(10249u, 11148u, 83u)"
    );
    assertEqualU32(
        memorycopy96_checkRange(&instance, 11148u, 11356u, 74u),
        4294967295u,
        "checkRange(11148u, 11356u, 74u)"
    );
    assertEqualU32(
        memorycopy96_checkRange(&instance, 11356u, 11380u, 93u),
        4294967295u,
        "checkRange(11356u, 11380u, 93u)"
    );
    assertEqualU32(
        memorycopy96_checkRange(&instance, 11380u, 11939u, 74u),
        4294967295u,
        "checkRange(11380u, 11939u, 74u)"
    );
    assertEqualU32(
        memorycopy96_checkRange(&instance, 11939u, 12159u, 68u),
        4294967295u,
        "checkRange(11939u, 12159u, 68u)"
    );
    assertEqualU32(
        memorycopy96_checkRange(&instance, 12159u, 12575u, 83u),
        4294967295u,
        "checkRange(12159u, 12575u, 83u)"
    );
    assertEqualU32(
        memorycopy96_checkRange(&instance, 12575u, 12969u, 79u),
        4294967295u,
        "checkRange(12575u, 12969u, 79u)"
    );
    assertEqualU32(
        memorycopy96_checkRange(&instance, 12969u, 13114u, 95u),
        4294967295u,
        "checkRange(12969u, 13114u, 95u)"
    );
    assertEqualU32(
        memorycopy96_checkRange(&instance, 13114u, 14133u, 59u),
        4294967295u,
        "checkRange(13114u, 14133u, 59u)"
    );
    assertEqualU32(
        memorycopy96_checkRange(&instance, 14133u, 14404u, 76u),
        4294967295u,
        "checkRange(14133u, 14404u, 76u)"
    );
    assertEqualU32(
        memorycopy96_checkRange(&instance, 14404u, 14428u, 57u),
        4294967295u,
        "checkRange(14404u, 14428u, 57u)"
    );
    assertEqualU32(
        memorycopy96_checkRange(&instance, 14428u, 14458u, 59u),
        4294967295u,
        "checkRange(14428u, 14458u, 59u)"
    );
    assertEqualU32(
        memorycopy96_checkRange(&instance, 14458u, 14580u, 32u),
        4294967295u,
        "checkRange(14458u, 14580u, 32u)"
    );
    assertEqualU32(
        memorycopy96_checkRange(&instance, 14580u, 14777u, 89u),
        4294967295u,
        "checkRange(14580u, 14777u, 89u)"
    );
    assertEqualU32(
        memorycopy96_checkRange(&instance, 14777u, 15124u, 59u),
        4294967295u,
        "checkRange(14777u, 15124u, 59u)"
    );
    assertEqualU32(
        memorycopy96_checkRange(&instance, 15124u, 15126u, 36u),
        4294967295u,
        "checkRange(15124u, 15126u, 36u)"
    );
    assertEqualU32(
        memorycopy96_checkRange(&instance, 15126u, 15192u, 100u),
        4294967295u,
        "checkRange(15126u, 15192u, 100u)"
    );
    assertEqualU32(
        memorycopy96_checkRange(&instance, 15192u, 15871u, 96u),
        4294967295u,
        "checkRange(15192u, 15871u, 96u)"
    );
    assertEqualU32(
        memorycopy96_checkRange(&instance, 15871u, 15998u, 95u),
        4294967295u,
        "checkRange(15871u, 15998u, 95u)"
    );
    assertEqualU32(
        memorycopy96_checkRange(&instance, 15998u, 17017u, 59u),
        4294967295u,
        "checkRange(15998u, 17017u, 59u)"
    );
    assertEqualU32(
        memorycopy96_checkRange(&instance, 17017u, 17288u, 76u),
        4294967295u,
        "checkRange(17017u, 17288u, 76u)"
    );
    assertEqualU32(
        memorycopy96_checkRange(&instance, 17288u, 17312u, 57u),
        4294967295u,
        "checkRange(17288u, 17312u, 57u)"
    );
    assertEqualU32(
        memorycopy96_checkRange(&instance, 17312u, 17342u, 59u),
        4294967295u,
        "checkRange(17312u, 17342u, 59u)"
    );
    assertEqualU32(
        memorycopy96_checkRange(&instance, 17342u, 17464u, 32u),
        4294967295u,
        "checkRange(17342u, 17464u, 32u)"
    );
    assertEqualU32(
        memorycopy96_checkRange(&instance, 17464u, 17661u, 89u),
        4294967295u,
        "checkRange(17464u, 17661u, 89u)"
    );
    assertEqualU32(
        memorycopy96_checkRange(&instance, 17661u, 17727u, 59u),
        4294967295u,
        "checkRange(17661u, 17727u, 59u)"
    );
    assertEqualU32(
        memorycopy96_checkRange(&instance, 17727u, 17733u, 5u),
        4294967295u,
        "checkRange(17727u, 17733u, 5u)"
    );
    assertEqualU32(
        memorycopy96_checkRange(&instance, 17733u, 17893u, 96u),
        4294967295u,
        "checkRange(17733u, 17893u, 96u)"
    );
    assertEqualU32(
        memorycopy96_checkRange(&instance, 17893u, 18553u, 77u),
        4294967295u,
        "checkRange(17893u, 18553u, 77u)"
    );
    assertEqualU32(
        memorycopy96_checkRange(&instance, 18553u, 18744u, 42u),
        4294967295u,
        "checkRange(18553u, 18744u, 42u)"
    );
    assertEqualU32(
        memorycopy96_checkRange(&instance, 18744u, 18801u, 76u),
        4294967295u,
        "checkRange(18744u, 18801u, 76u)"
    );
    assertEqualU32(
        memorycopy96_checkRange(&instance, 18801u, 18825u, 57u),
        4294967295u,
        "checkRange(18801u, 18825u, 57u)"
    );
    assertEqualU32(
        memorycopy96_checkRange(&instance, 18825u, 18876u, 59u),
        4294967295u,
        "checkRange(18825u, 18876u, 59u)"
    );
    assertEqualU32(
        memorycopy96_checkRange(&instance, 18876u, 18885u, 77u),
        4294967295u,
        "checkRange(18876u, 18885u, 77u)"
    );
    assertEqualU32(
        memorycopy96_checkRange(&instance, 18885u, 18904u, 41u),
        4294967295u,
        "checkRange(18885u, 18904u, 41u)"
    );
    assertEqualU32(
        memorycopy96_checkRange(&instance, 18904u, 19567u, 83u),
        4294967295u,
        "checkRange(18904u, 19567u, 83u)"
    );
    assertEqualU32(
        memorycopy96_checkRange(&instance, 19567u, 20403u, 96u),
        4294967295u,
        "checkRange(19567u, 20403u, 96u)"
    );
    assertEqualU32(
        memorycopy96_checkRange(&instance, 20403u, 21274u, 77u),
        4294967295u,
        "checkRange(20403u, 21274u, 77u)"
    );
    assertEqualU32(
        memorycopy96_checkRange(&instance, 21274u, 21364u, 100u),
        4294967295u,
        "checkRange(21274u, 21364u, 100u)"
    );
    assertEqualU32(
        memorycopy96_checkRange(&instance, 21364u, 21468u, 74u),
        4294967295u,
        "checkRange(21364u, 21468u, 74u)"
    );
    assertEqualU32(
        memorycopy96_checkRange(&instance, 21468u, 21492u, 93u),
        4294967295u,
        "checkRange(21468u, 21492u, 93u)"
    );
    assertEqualU32(
        memorycopy96_checkRange(&instance, 21492u, 22051u, 74u),
        4294967295u,
        "checkRange(21492u, 22051u, 74u)"
    );
    assertEqualU32(
        memorycopy96_checkRange(&instance, 22051u, 22480u, 68u),
        4294967295u,
        "checkRange(22051u, 22480u, 68u)"
    );
    assertEqualU32(
        memorycopy96_checkRange(&instance, 22480u, 22685u, 100u),
        4294967295u,
        "checkRange(22480u, 22685u, 100u)"
    );
    assertEqualU32(
        memorycopy96_checkRange(&instance, 22685u, 22694u, 68u),
        4294967295u,
        "checkRange(22685u, 22694u, 68u)"
    );
    assertEqualU32(
        memorycopy96_checkRange(&instance, 22694u, 22821u, 10u),
        4294967295u,
        "checkRange(22694u, 22821u, 10u)"
    );
    assertEqualU32(
        memorycopy96_checkRange(&instance, 22821u, 22869u, 100u),
        4294967295u,
        "checkRange(22821u, 22869u, 100u)"
    );
    assertEqualU32(
        memorycopy96_checkRange(&instance, 22869u, 24107u, 97u),
        4294967295u,
        "checkRange(22869u, 24107u, 97u)"
    );
    assertEqualU32(
        memorycopy96_checkRange(&instance, 24107u, 24111u, 37u),
        4294967295u,
        "checkRange(24107u, 24111u, 37u)"
    );
    assertEqualU32(
        memorycopy96_checkRange(&instance, 24111u, 24236u, 77u),
        4294967295u,
        "checkRange(24111u, 24236u, 77u)"
    );
    assertEqualU32(
        memorycopy96_checkRange(&instance, 24236u, 24348u, 72u),
        4294967295u,
        "checkRange(24236u, 24348u, 72u)"
    );
    assertEqualU32(
        memorycopy96_checkRange(&instance, 24348u, 24515u, 92u),
        4294967295u,
        "checkRange(24348u, 24515u, 92u)"
    );
    assertEqualU32(
        memorycopy96_checkRange(&instance, 24515u, 24900u, 83u),
        4294967295u,
        "checkRange(24515u, 24900u, 83u)"
    );
    assertEqualU32(
        memorycopy96_checkRange(&instance, 24900u, 25136u, 95u),
        4294967295u,
        "checkRange(24900u, 25136u, 95u)"
    );
    assertEqualU32(
        memorycopy96_checkRange(&instance, 25136u, 25182u, 85u),
        4294967295u,
        "checkRange(25136u, 25182u, 85u)"
    );
    assertEqualU32(
        memorycopy96_checkRange(&instance, 25182u, 25426u, 68u),
        4294967295u,
        "checkRange(25182u, 25426u, 68u)"
    );
    assertEqualU32(
        memorycopy96_checkRange(&instance, 25426u, 25613u, 89u),
        4294967295u,
        "checkRange(25426u, 25613u, 89u)"
    );
    assertEqualU32(
        memorycopy96_checkRange(&instance, 25613u, 25830u, 96u),
        4294967295u,
        "checkRange(25613u, 25830u, 96u)"
    );
    assertEqualU32(
        memorycopy96_checkRange(&instance, 25830u, 26446u, 100u),
        4294967295u,
        "checkRange(25830u, 26446u, 100u)"
    );
    assertEqualU32(
        memorycopy96_checkRange(&instance, 26446u, 26517u, 10u),
        4294967295u,
        "checkRange(26446u, 26517u, 10u)"
    );
    assertEqualU32(
        memorycopy96_checkRange(&instance, 26517u, 27468u, 92u),
        4294967295u,
        "checkRange(26517u, 27468u, 92u)"
    );
    assertEqualU32(
        memorycopy96_checkRange(&instance, 27468u, 27503u, 95u),
        4294967295u,
        "checkRange(27468u, 27503u, 95u)"
    );
    assertEqualU32(
        memorycopy96_checkRange(&instance, 27503u, 27573u, 77u),
        4294967295u,
        "checkRange(27503u, 27573u, 77u)"
    );
    assertEqualU32(
        memorycopy96_checkRange(&instance, 27573u, 28245u, 92u),
        4294967295u,
        "checkRange(27573u, 28245u, 92u)"
    );
    assertEqualU32(
        memorycopy96_checkRange(&instance, 28245u, 28280u, 95u),
        4294967295u,
        "checkRange(28245u, 28280u, 95u)"
    );
    assertEqualU32(
        memorycopy96_checkRange(&instance, 28280u, 29502u, 77u),
        4294967295u,
        "checkRange(28280u, 29502u, 77u)"
    );
    assertEqualU32(
        memorycopy96_checkRange(&instance, 29502u, 29629u, 42u),
        4294967295u,
        "checkRange(29502u, 29629u, 42u)"
    );
    assertEqualU32(
        memorycopy96_checkRange(&instance, 29629u, 30387u, 83u),
        4294967295u,
        "checkRange(29629u, 30387u, 83u)"
    );
    assertEqualU32(
        memorycopy96_checkRange(&instance, 30387u, 30646u, 77u),
        4294967295u,
        "checkRange(30387u, 30646u, 77u)"
    );
    assertEqualU32(
        memorycopy96_checkRange(&instance, 30646u, 31066u, 92u),
        4294967295u,
        "checkRange(30646u, 31066u, 92u)"
    );
    assertEqualU32(
        memorycopy96_checkRange(&instance, 31066u, 31131u, 77u),
        4294967295u,
        "checkRange(31066u, 31131u, 77u)"
    );
    assertEqualU32(
        memorycopy96_checkRange(&instance, 31131u, 31322u, 42u),
        4294967295u,
        "checkRange(31131u, 31322u, 42u)"
    );
    assertEqualU32(
        memorycopy96_checkRange(&instance, 31322u, 31379u, 76u),
        4294967295u,
        "checkRange(31322u, 31379u, 76u)"
    );
    assertEqualU32(
        memorycopy96_checkRange(&instance, 31379u, 31403u, 57u),
        4294967295u,
        "checkRange(31379u, 31403u, 57u)"
    );
    assertEqualU32(
        memorycopy96_checkRange(&instance, 31403u, 31454u, 59u),
        4294967295u,
        "checkRange(31403u, 31454u, 59u)"
    );
    assertEqualU32(
        memorycopy96_checkRange(&instance, 31454u, 31463u, 77u),
        4294967295u,
        "checkRange(31454u, 31463u, 77u)"
    );
    assertEqualU32(
        memorycopy96_checkRange(&instance, 31463u, 31482u, 41u),
        4294967295u,
        "checkRange(31463u, 31482u, 41u)"
    );
    assertEqualU32(
        memorycopy96_checkRange(&instance, 31482u, 31649u, 83u),
        4294967295u,
        "checkRange(31482u, 31649u, 83u)"
    );
    assertEqualU32(
        memorycopy96_checkRange(&instance, 31649u, 31978u, 72u),
        4294967295u,
        "checkRange(31649u, 31978u, 72u)"
    );
    assertEqualU32(
        memorycopy96_checkRange(&instance, 31978u, 32145u, 92u),
        4294967295u,
        "checkRange(31978u, 32145u, 92u)"
    );
    assertEqualU32(
        memorycopy96_checkRange(&instance, 32145u, 32530u, 83u),
        4294967295u,
        "checkRange(32145u, 32530u, 83u)"
    );
    assertEqualU32(
        memorycopy96_checkRange(&instance, 32530u, 32766u, 95u),
        4294967295u,
        "checkRange(32530u, 32766u, 95u)"
    );
    assertEqualU32(
        memorycopy96_checkRange(&instance, 32766u, 32812u, 85u),
        4294967295u,
        "checkRange(32766u, 32812u, 85u)"
    );
    assertEqualU32(
        memorycopy96_checkRange(&instance, 32812u, 33056u, 68u),
        4294967295u,
        "checkRange(32812u, 33056u, 68u)"
    );
    assertEqualU32(
        memorycopy96_checkRange(&instance, 33056u, 33660u, 89u),
        4294967295u,
        "checkRange(33056u, 33660u, 89u)"
    );
    assertEqualU32(
        memorycopy96_checkRange(&instance, 33660u, 33752u, 59u),
        4294967295u,
        "checkRange(33660u, 33752u, 59u)"
    );
    assertEqualU32(
        memorycopy96_checkRange(&instance, 33752u, 33775u, 36u),
        4294967295u,
        "checkRange(33752u, 33775u, 36u)"
    );
    assertEqualU32(
        memorycopy96_checkRange(&instance, 33775u, 33778u, 32u),
        4294967295u,
        "checkRange(33775u, 33778u, 32u)"
    );
    assertEqualU32(
        memorycopy96_checkRange(&instance, 33778u, 34603u, 9u),
        4294967295u,
        "checkRange(33778u, 34603u, 9u)"
    );
    assertEqualU32(
        memorycopy96_checkRange(&instance, 34603u, 35218u, 0u),
        4294967295u,
        "checkRange(34603u, 35218u, 0u)"
    );
    assertEqualU32(
        memorycopy96_checkRange(&instance, 35218u, 35372u, 10u),
        4294967295u,
        "checkRange(35218u, 35372u, 10u)"
    );
    assertEqualU32(
        memorycopy96_checkRange(&instance, 35372u, 35486u, 77u),
        4294967295u,
        "checkRange(35372u, 35486u, 77u)"
    );
    assertEqualU32(
        memorycopy96_checkRange(&instance, 35486u, 35605u, 5u),
        4294967295u,
        "checkRange(35486u, 35605u, 5u)"
    );
    assertEqualU32(
        memorycopy96_checkRange(&instance, 35605u, 35629u, 77u),
        4294967295u,
        "checkRange(35605u, 35629u, 77u)"
    );
    assertEqualU32(
        memorycopy96_checkRange(&instance, 35629u, 35648u, 41u),
        4294967295u,
        "checkRange(35629u, 35648u, 41u)"
    );
    assertEqualU32(
        memorycopy96_checkRange(&instance, 35648u, 36547u, 83u),
        4294967295u,
        "checkRange(35648u, 36547u, 83u)"
    );
    assertEqualU32(
        memorycopy96_checkRange(&instance, 36547u, 36755u, 74u),
        4294967295u,
        "checkRange(36547u, 36755u, 74u)"
    );
    assertEqualU32(
        memorycopy96_checkRange(&instance, 36755u, 36767u, 93u),
        4294967295u,
        "checkRange(36755u, 36767u, 93u)"
    );
    assertEqualU32(
        memorycopy96_checkRange(&instance, 36767u, 36810u, 83u),
        4294967295u,
        "checkRange(36767u, 36810u, 83u)"
    );
    assertEqualU32(
        memorycopy96_checkRange(&instance, 36810u, 36839u, 100u),
        4294967295u,
        "checkRange(36810u, 36839u, 100u)"
    );
    assertEqualU32(
        memorycopy96_checkRange(&instance, 36839u, 37444u, 96u),
        4294967295u,
        "checkRange(36839u, 37444u, 96u)"
    );
    assertEqualU32(
        memorycopy96_checkRange(&instance, 37444u, 38060u, 100u),
        4294967295u,
        "checkRange(37444u, 38060u, 100u)"
    );
    assertEqualU32(
        memorycopy96_checkRange(&instance, 38060u, 38131u, 10u),
        4294967295u,
        "checkRange(38060u, 38131u, 10u)"
    );
    assertEqualU32(
        memorycopy96_checkRange(&instance, 38131u, 39082u, 92u),
        4294967295u,
        "checkRange(38131u, 39082u, 92u)"
    );
    assertEqualU32(
        memorycopy96_checkRange(&instance, 39082u, 39117u, 95u),
        4294967295u,
        "checkRange(39082u, 39117u, 95u)"
    );
    assertEqualU32(
        memorycopy96_checkRange(&instance, 39117u, 39187u, 77u),
        4294967295u,
        "checkRange(39117u, 39187u, 77u)"
    );
    assertEqualU32(
        memorycopy96_checkRange(&instance, 39187u, 39859u, 92u),
        4294967295u,
        "checkRange(39187u, 39859u, 92u)"
    );
    assertEqualU32(
        memorycopy96_checkRange(&instance, 39859u, 39894u, 95u),
        4294967295u,
        "checkRange(39859u, 39894u, 95u)"
    );
    assertEqualU32(
        memorycopy96_checkRange(&instance, 39894u, 40257u, 77u),
        4294967295u,
        "checkRange(39894u, 40257u, 77u)"
    );
    assertEqualU32(
        memorycopy96_checkRange(&instance, 40257u, 40344u, 89u),
        4294967295u,
        "checkRange(40257u, 40344u, 89u)"
    );
    assertEqualU32(
        memorycopy96_checkRange(&instance, 40344u, 40371u, 59u),
        4294967295u,
        "checkRange(40344u, 40371u, 59u)"
    );
    assertEqualU32(
        memorycopy96_checkRange(&instance, 40371u, 40804u, 77u),
        4294967295u,
        "checkRange(40371u, 40804u, 77u)"
    );
    assertEqualU32(
        memorycopy96_checkRange(&instance, 40804u, 40909u, 5u),
        4294967295u,
        "checkRange(40804u, 40909u, 5u)"
    );
    assertEqualU32(
        memorycopy96_checkRange(&instance, 40909u, 42259u, 92u),
        4294967295u,
        "checkRange(40909u, 42259u, 92u)"
    );
    assertEqualU32(
        memorycopy96_checkRange(&instance, 42259u, 42511u, 77u),
        4294967295u,
        "checkRange(42259u, 42511u, 77u)"
    );
    assertEqualU32(
        memorycopy96_checkRange(&instance, 42511u, 42945u, 83u),
        4294967295u,
        "checkRange(42511u, 42945u, 83u)"
    );
    assertEqualU32(
        memorycopy96_checkRange(&instance, 42945u, 43115u, 77u),
        4294967295u,
        "checkRange(42945u, 43115u, 77u)"
    );
    assertEqualU32(
        memorycopy96_checkRange(&instance, 43115u, 43306u, 42u),
        4294967295u,
        "checkRange(43115u, 43306u, 42u)"
    );
    assertEqualU32(
        memorycopy96_checkRange(&instance, 43306u, 43363u, 76u),
        4294967295u,
        "checkRange(43306u, 43363u, 76u)"
    );
    assertEqualU32(
        memorycopy96_checkRange(&instance, 43363u, 43387u, 57u),
        4294967295u,
        "checkRange(43363u, 43387u, 57u)"
    );
    assertEqualU32(
        memorycopy96_checkRange(&instance, 43387u, 43438u, 59u),
        4294967295u,
        "checkRange(43387u, 43438u, 59u)"
    );
    assertEqualU32(
        memorycopy96_checkRange(&instance, 43438u, 43447u, 77u),
        4294967295u,
        "checkRange(43438u, 43447u, 77u)"
    );
    assertEqualU32(
        memorycopy96_checkRange(&instance, 43447u, 43466u, 41u),
        4294967295u,
        "checkRange(43447u, 43466u, 41u)"
    );
    assertEqualU32(
        memorycopy96_checkRange(&instance, 43466u, 44129u, 83u),
        4294967295u,
        "checkRange(43466u, 44129u, 83u)"
    );
    assertEqualU32(
        memorycopy96_checkRange(&instance, 44129u, 44958u, 96u),
        4294967295u,
        "checkRange(44129u, 44958u, 96u)"
    );
    assertEqualU32(
        memorycopy96_checkRange(&instance, 44958u, 45570u, 77u),
        4294967295u,
        "checkRange(44958u, 45570u, 77u)"
    );
    assertEqualU32(
        memorycopy96_checkRange(&instance, 45570u, 45575u, 92u),
        4294967295u,
        "checkRange(45570u, 45575u, 92u)"
    );
    assertEqualU32(
        memorycopy96_checkRange(&instance, 45575u, 45640u, 77u),
        4294967295u,
        "checkRange(45575u, 45640u, 77u)"
    );
    assertEqualU32(
        memorycopy96_checkRange(&instance, 45640u, 45742u, 42u),
        4294967295u,
        "checkRange(45640u, 45742u, 42u)"
    );
    assertEqualU32(
        memorycopy96_checkRange(&instance, 45742u, 45832u, 72u),
        4294967295u,
        "checkRange(45742u, 45832u, 72u)"
    );
    assertEqualU32(
        memorycopy96_checkRange(&instance, 45832u, 45999u, 92u),
        4294967295u,
        "checkRange(45832u, 45999u, 92u)"
    );
    assertEqualU32(
        memorycopy96_checkRange(&instance, 45999u, 46384u, 83u),
        4294967295u,
        "checkRange(45999u, 46384u, 83u)"
    );
    assertEqualU32(
        memorycopy96_checkRange(&instance, 46384u, 46596u, 95u),
        4294967295u,
        "checkRange(46384u, 46596u, 95u)"
    );
    assertEqualU32(
        memorycopy96_checkRange(&instance, 46596u, 46654u, 92u),
        4294967295u,
        "checkRange(46596u, 46654u, 92u)"
    );
    assertEqualU32(
        memorycopy96_checkRange(&instance, 46654u, 47515u, 83u),
        4294967295u,
        "checkRange(46654u, 47515u, 83u)"
    );
    assertEqualU32(
        memorycopy96_checkRange(&instance, 47515u, 47620u, 77u),
        4294967295u,
        "checkRange(47515u, 47620u, 77u)"
    );
    assertEqualU32(
        memorycopy96_checkRange(&instance, 47620u, 47817u, 79u),
        4294967295u,
        "checkRange(47620u, 47817u, 79u)"
    );
    assertEqualU32(
        memorycopy96_checkRange(&instance, 47817u, 47951u, 95u),
        4294967295u,
        "checkRange(47817u, 47951u, 95u)"
    );
    assertEqualU32(
        memorycopy96_checkRange(&instance, 47951u, 48632u, 100u),
        4294967295u,
        "checkRange(47951u, 48632u, 100u)"
    );
    assertEqualU32(
        memorycopy96_checkRange(&instance, 48632u, 48699u, 97u),
        4294967295u,
        "checkRange(48632u, 48699u, 97u)"
    );
    assertEqualU32(
        memorycopy96_checkRange(&instance, 48699u, 48703u, 37u),
        4294967295u,
        "checkRange(48699u, 48703u, 37u)"
    );
    assertEqualU32(
        memorycopy96_checkRange(&instance, 48703u, 49764u, 77u),
        4294967295u,
        "checkRange(48703u, 49764u, 77u)"
    );
    assertEqualU32(
        memorycopy96_checkRange(&instance, 49764u, 49955u, 42u),
        4294967295u,
        "checkRange(49764u, 49955u, 42u)"
    );
    assertEqualU32(
        memorycopy96_checkRange(&instance, 49955u, 50012u, 76u),
        4294967295u,
        "checkRange(49955u, 50012u, 76u)"
    );
    assertEqualU32(
        memorycopy96_checkRange(&instance, 50012u, 50036u, 57u),
        4294967295u,
        "checkRange(50012u, 50036u, 57u)"
    );
    assertEqualU32(
        memorycopy96_checkRange(&instance, 50036u, 50087u, 59u),
        4294967295u,
        "checkRange(50036u, 50087u, 59u)"
    );
    assertEqualU32(
        memorycopy96_checkRange(&instance, 50087u, 50096u, 77u),
        4294967295u,
        "checkRange(50087u, 50096u, 77u)"
    );
    assertEqualU32(
        memorycopy96_checkRange(&instance, 50096u, 50115u, 41u),
        4294967295u,
        "checkRange(50096u, 50115u, 41u)"
    );
    assertEqualU32(
        memorycopy96_checkRange(&instance, 50115u, 50370u, 83u),
        4294967295u,
        "checkRange(50115u, 50370u, 83u)"
    );
    assertEqualU32(
        memorycopy96_checkRange(&instance, 50370u, 51358u, 92u),
        4294967295u,
        "checkRange(50370u, 51358u, 92u)"
    );
    assertEqualU32(
        memorycopy96_checkRange(&instance, 51358u, 51610u, 77u),
        4294967295u,
        "checkRange(51358u, 51610u, 77u)"
    );
    assertEqualU32(
        memorycopy96_checkRange(&instance, 51610u, 51776u, 83u),
        4294967295u,
        "checkRange(51610u, 51776u, 83u)"
    );
    assertEqualU32(
        memorycopy96_checkRange(&instance, 51776u, 51833u, 89u),
        4294967295u,
        "checkRange(51776u, 51833u, 89u)"
    );
    assertEqualU32(
        memorycopy96_checkRange(&instance, 51833u, 52895u, 100u),
        4294967295u,
        "checkRange(51833u, 52895u, 100u)"
    );
    assertEqualU32(
        memorycopy96_checkRange(&instance, 52895u, 53029u, 97u),
        4294967295u,
        "checkRange(52895u, 53029u, 97u)"
    );
    assertEqualU32(
        memorycopy96_checkRange(&instance, 53029u, 53244u, 68u),
        4294967295u,
        "checkRange(53029u, 53244u, 68u)"
    );
    assertEqualU32(
        memorycopy96_checkRange(&instance, 53244u, 54066u, 100u),
        4294967295u,
        "checkRange(53244u, 54066u, 100u)"
    );
    assertEqualU32(
        memorycopy96_checkRange(&instance, 54066u, 54133u, 97u),
        4294967295u,
        "checkRange(54066u, 54133u, 97u)"
    );
    assertEqualU32(
        memorycopy96_checkRange(&instance, 54133u, 54137u, 37u),
        4294967295u,
        "checkRange(54133u, 54137u, 37u)"
    );
    assertEqualU32(
        memorycopy96_checkRange(&instance, 54137u, 55198u, 77u),
        4294967295u,
        "checkRange(54137u, 55198u, 77u)"
    );
    assertEqualU32(
        memorycopy96_checkRange(&instance, 55198u, 55389u, 42u),
        4294967295u,
        "checkRange(55198u, 55389u, 42u)"
    );
    assertEqualU32(
        memorycopy96_checkRange(&instance, 55389u, 55446u, 76u),
        4294967295u,
        "checkRange(55389u, 55446u, 76u)"
    );
    assertEqualU32(
        memorycopy96_checkRange(&instance, 55446u, 55470u, 57u),
        4294967295u,
        "checkRange(55446u, 55470u, 57u)"
    );
    assertEqualU32(
        memorycopy96_checkRange(&instance, 55470u, 55521u, 59u),
        4294967295u,
        "checkRange(55470u, 55521u, 59u)"
    );
    assertEqualU32(
        memorycopy96_checkRange(&instance, 55521u, 55530u, 77u),
        4294967295u,
        "checkRange(55521u, 55530u, 77u)"
    );
    assertEqualU32(
        memorycopy96_checkRange(&instance, 55530u, 55549u, 41u),
        4294967295u,
        "checkRange(55530u, 55549u, 41u)"
    );
    assertEqualU32(
        memorycopy96_checkRange(&instance, 55549u, 56212u, 83u),
        4294967295u,
        "checkRange(55549u, 56212u, 83u)"
    );
    assertEqualU32(
        memorycopy96_checkRange(&instance, 56212u, 57048u, 96u),
        4294967295u,
        "checkRange(56212u, 57048u, 96u)"
    );
    assertEqualU32(
        memorycopy96_checkRange(&instance, 57048u, 58183u, 77u),
        4294967295u,
        "checkRange(57048u, 58183u, 77u)"
    );
    assertEqualU32(
        memorycopy96_checkRange(&instance, 58183u, 58202u, 41u),
        4294967295u,
        "checkRange(58183u, 58202u, 41u)"
    );
    assertEqualU32(
        memorycopy96_checkRange(&instance, 58202u, 58516u, 83u),
        4294967295u,
        "checkRange(58202u, 58516u, 83u)"
    );
    assertEqualU32(
        memorycopy96_checkRange(&instance, 58516u, 58835u, 95u),
        4294967295u,
        "checkRange(58516u, 58835u, 95u)"
    );
    assertEqualU32(
        memorycopy96_checkRange(&instance, 58835u, 58855u, 77u),
        4294967295u,
        "checkRange(58835u, 58855u, 77u)"
    );
    assertEqualU32(
        memorycopy96_checkRange(&instance, 58855u, 59089u, 95u),
        4294967295u,
        "checkRange(58855u, 59089u, 95u)"
    );
    assertEqualU32(
        memorycopy96_checkRange(&instance, 59089u, 59145u, 77u),
        4294967295u,
        "checkRange(59089u, 59145u, 77u)"
    );
    assertEqualU32(
        memorycopy96_checkRange(&instance, 59145u, 59677u, 99u),
        4294967295u,
        "checkRange(59145u, 59677u, 99u)"
    );
    assertEqualU32(
        memorycopy96_checkRange(&instance, 59677u, 60134u, 0u),
        4294967295u,
        "checkRange(59677u, 60134u, 0u)"
    );
    assertEqualU32(
        memorycopy96_checkRange(&instance, 60134u, 60502u, 89u),
        4294967295u,
        "checkRange(60134u, 60502u, 89u)"
    );
    assertEqualU32(
        memorycopy96_checkRange(&instance, 60502u, 60594u, 59u),
        4294967295u,
        "checkRange(60502u, 60594u, 59u)"
    );
    assertEqualU32(
        memorycopy96_checkRange(&instance, 60594u, 60617u, 36u),
        4294967295u,
        "checkRange(60594u, 60617u, 36u)"
    );
    assertEqualU32(
        memorycopy96_checkRange(&instance, 60617u, 60618u, 32u),
        4294967295u,
        "checkRange(60617u, 60618u, 32u)"
    );
    assertEqualU32(
        memorycopy96_checkRange(&instance, 60618u, 60777u, 42u),
        4294967295u,
        "checkRange(60618u, 60777u, 42u)"
    );
    assertEqualU32(
        memorycopy96_checkRange(&instance, 60777u, 60834u, 76u),
        4294967295u,
        "checkRange(60777u, 60834u, 76u)"
    );
    assertEqualU32(
        memorycopy96_checkRange(&instance, 60834u, 60858u, 57u),
        4294967295u,
        "checkRange(60834u, 60858u, 57u)"
    );
    assertEqualU32(
        memorycopy96_checkRange(&instance, 60858u, 60909u, 59u),
        4294967295u,
        "checkRange(60858u, 60909u, 59u)"
    );
    assertEqualU32(
        memorycopy96_checkRange(&instance, 60909u, 60918u, 77u),
        4294967295u,
        "checkRange(60909u, 60918u, 77u)"
    );
    assertEqualU32(
        memorycopy96_checkRange(&instance, 60918u, 60937u, 41u),
        4294967295u,
        "checkRange(60918u, 60937u, 41u)"
    );
    assertEqualU32(
        memorycopy96_checkRange(&instance, 60937u, 61600u, 83u),
        4294967295u,
        "checkRange(60937u, 61600u, 83u)"
    );
    assertEqualU32(
        memorycopy96_checkRange(&instance, 61600u, 62436u, 96u),
        4294967295u,
        "checkRange(61600u, 62436u, 96u)"
    );
    assertEqualU32(
        memorycopy96_checkRange(&instance, 62436u, 63307u, 77u),
        4294967295u,
        "checkRange(62436u, 63307u, 77u)"
    );
    assertEqualU32(
        memorycopy96_checkRange(&instance, 63307u, 63397u, 100u),
        4294967295u,
        "checkRange(63307u, 63397u, 100u)"
    );
    assertEqualU32(
        memorycopy96_checkRange(&instance, 63397u, 63501u, 74u),
        4294967295u,
        "checkRange(63397u, 63501u, 74u)"
    );
    assertEqualU32(
        memorycopy96_checkRange(&instance, 63501u, 63525u, 93u),
        4294967295u,
        "checkRange(63501u, 63525u, 93u)"
    );
    assertEqualU32(
        memorycopy96_checkRange(&instance, 63525u, 63605u, 74u),
        4294967295u,
        "checkRange(63525u, 63605u, 74u)"
    );
    assertEqualU32(
        memorycopy96_checkRange(&instance, 63605u, 63704u, 100u),
        4294967295u,
        "checkRange(63605u, 63704u, 100u)"
    );
    assertEqualU32(
        memorycopy96_checkRange(&instance, 63704u, 63771u, 97u),
        4294967295u,
        "checkRange(63704u, 63771u, 97u)"
    );
    assertEqualU32(
        memorycopy96_checkRange(&instance, 63771u, 63775u, 37u),
        4294967295u,
        "checkRange(63771u, 63775u, 37u)"
    );
    assertEqualU32(
        memorycopy96_checkRange(&instance, 63775u, 64311u, 77u),
        4294967295u,
        "checkRange(63775u, 64311u, 77u)"
    );
    assertEqualU32(
        memorycopy96_checkRange(&instance, 64311u, 64331u, 26u),
        4294967295u,
        "checkRange(64311u, 64331u, 26u)"
    );
    assertEqualU32(
        memorycopy96_checkRange(&instance, 64331u, 64518u, 92u),
        4294967295u,
        "checkRange(64331u, 64518u, 92u)"
    );
    assertEqualU32(
        memorycopy96_checkRange(&instance, 64518u, 64827u, 11u),
        4294967295u,
        "checkRange(64518u, 64827u, 11u)"
    );
    assertEqualU32(
        memorycopy96_checkRange(&instance, 64827u, 64834u, 26u),
        4294967295u,
        "checkRange(64827u, 64834u, 26u)"
    );
    assertEqualU32(
        memorycopy96_checkRange(&instance, 64834u, 65536u, 0u),
        4294967295u,
        "checkRange(64834u, 65536u, 0u)"
    );
}
