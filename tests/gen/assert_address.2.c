#include "test.h"
#include "test_address.2.h"

void test(void) {
    static m9_addressX2E2Instance instance;
    m9_addressX2E2Instantiate(&instance, resolveTestImports);
    printStart("address.2.wasm");
    assertEqualU64(
        m9_addressX2E2Export8_8uX5Fgood1(&instance, 0u),
        97ull,
        "8u_good1(0u)"
    );
    assertEqualU64(
        m9_addressX2E2Export8_8uX5Fgood2(&instance, 0u),
        97ull,
        "8u_good2(0u)"
    );
    assertEqualU64(
        m9_addressX2E2Export8_8uX5Fgood3(&instance, 0u),
        98ull,
        "8u_good3(0u)"
    );
    assertEqualU64(
        m9_addressX2E2Export8_8uX5Fgood4(&instance, 0u),
        99ull,
        "8u_good4(0u)"
    );
    assertEqualU64(
        m9_addressX2E2Export8_8uX5Fgood5(&instance, 0u),
        122ull,
        "8u_good5(0u)"
    );
    assertEqualU64(
        m9_addressX2E2Export8_8sX5Fgood1(&instance, 0u),
        97ull,
        "8s_good1(0u)"
    );
    assertEqualU64(
        m9_addressX2E2Export8_8sX5Fgood2(&instance, 0u),
        97ull,
        "8s_good2(0u)"
    );
    assertEqualU64(
        m9_addressX2E2Export8_8sX5Fgood3(&instance, 0u),
        98ull,
        "8s_good3(0u)"
    );
    assertEqualU64(
        m9_addressX2E2Export8_8sX5Fgood4(&instance, 0u),
        99ull,
        "8s_good4(0u)"
    );
    assertEqualU64(
        m9_addressX2E2Export8_8sX5Fgood5(&instance, 0u),
        122ull,
        "8s_good5(0u)"
    );
    assertEqualU64(
        m9_addressX2E2Export9_16uX5Fgood1(&instance, 0u),
        25185ull,
        "16u_good1(0u)"
    );
    assertEqualU64(
        m9_addressX2E2Export9_16uX5Fgood2(&instance, 0u),
        25185ull,
        "16u_good2(0u)"
    );
    assertEqualU64(
        m9_addressX2E2Export9_16uX5Fgood3(&instance, 0u),
        25442ull,
        "16u_good3(0u)"
    );
    assertEqualU64(
        m9_addressX2E2Export9_16uX5Fgood4(&instance, 0u),
        25699ull,
        "16u_good4(0u)"
    );
    assertEqualU64(
        m9_addressX2E2Export9_16uX5Fgood5(&instance, 0u),
        122ull,
        "16u_good5(0u)"
    );
    assertEqualU64(
        m9_addressX2E2Export9_16sX5Fgood1(&instance, 0u),
        25185ull,
        "16s_good1(0u)"
    );
    assertEqualU64(
        m9_addressX2E2Export9_16sX5Fgood2(&instance, 0u),
        25185ull,
        "16s_good2(0u)"
    );
    assertEqualU64(
        m9_addressX2E2Export9_16sX5Fgood3(&instance, 0u),
        25442ull,
        "16s_good3(0u)"
    );
    assertEqualU64(
        m9_addressX2E2Export9_16sX5Fgood4(&instance, 0u),
        25699ull,
        "16s_good4(0u)"
    );
    assertEqualU64(
        m9_addressX2E2Export9_16sX5Fgood5(&instance, 0u),
        122ull,
        "16s_good5(0u)"
    );
    assertEqualU64(
        m9_addressX2E2Export9_32uX5Fgood1(&instance, 0u),
        1684234849ull,
        "32u_good1(0u)"
    );
    assertEqualU64(
        m9_addressX2E2Export9_32uX5Fgood2(&instance, 0u),
        1684234849ull,
        "32u_good2(0u)"
    );
    assertEqualU64(
        m9_addressX2E2Export9_32uX5Fgood3(&instance, 0u),
        1701077858ull,
        "32u_good3(0u)"
    );
    assertEqualU64(
        m9_addressX2E2Export9_32uX5Fgood4(&instance, 0u),
        1717920867ull,
        "32u_good4(0u)"
    );
    assertEqualU64(
        m9_addressX2E2Export9_32uX5Fgood5(&instance, 0u),
        122ull,
        "32u_good5(0u)"
    );
    assertEqualU64(
        m9_addressX2E2Export9_32sX5Fgood1(&instance, 0u),
        1684234849ull,
        "32s_good1(0u)"
    );
    assertEqualU64(
        m9_addressX2E2Export9_32sX5Fgood2(&instance, 0u),
        1684234849ull,
        "32s_good2(0u)"
    );
    assertEqualU64(
        m9_addressX2E2Export9_32sX5Fgood3(&instance, 0u),
        1701077858ull,
        "32s_good3(0u)"
    );
    assertEqualU64(
        m9_addressX2E2Export9_32sX5Fgood4(&instance, 0u),
        1717920867ull,
        "32s_good4(0u)"
    );
    assertEqualU64(
        m9_addressX2E2Export9_32sX5Fgood5(&instance, 0u),
        122ull,
        "32s_good5(0u)"
    );
    assertEqualU64(
        m9_addressX2E2Export8_64X5Fgood1(&instance, 0u),
        7523094288207667809ull,
        "64_good1(0u)"
    );
    assertEqualU64(
        m9_addressX2E2Export8_64X5Fgood2(&instance, 0u),
        7523094288207667809ull,
        "64_good2(0u)"
    );
    assertEqualU64(
        m9_addressX2E2Export8_64X5Fgood3(&instance, 0u),
        7595434461045744482ull,
        "64_good3(0u)"
    );
    assertEqualU64(
        m9_addressX2E2Export8_64X5Fgood4(&instance, 0u),
        7667774633883821155ull,
        "64_good4(0u)"
    );
    assertEqualU64(
        m9_addressX2E2Export8_64X5Fgood5(&instance, 0u),
        122ull,
        "64_good5(0u)"
    );
    assertEqualU64(
        m9_addressX2E2Export8_8uX5Fgood1(&instance, 65503u),
        0ull,
        "8u_good1(65503u)"
    );
    assertEqualU64(
        m9_addressX2E2Export8_8uX5Fgood2(&instance, 65503u),
        0ull,
        "8u_good2(65503u)"
    );
    assertEqualU64(
        m9_addressX2E2Export8_8uX5Fgood3(&instance, 65503u),
        0ull,
        "8u_good3(65503u)"
    );
    assertEqualU64(
        m9_addressX2E2Export8_8uX5Fgood4(&instance, 65503u),
        0ull,
        "8u_good4(65503u)"
    );
    assertEqualU64(
        m9_addressX2E2Export8_8uX5Fgood5(&instance, 65503u),
        0ull,
        "8u_good5(65503u)"
    );
    assertEqualU64(
        m9_addressX2E2Export8_8sX5Fgood1(&instance, 65503u),
        0ull,
        "8s_good1(65503u)"
    );
    assertEqualU64(
        m9_addressX2E2Export8_8sX5Fgood2(&instance, 65503u),
        0ull,
        "8s_good2(65503u)"
    );
    assertEqualU64(
        m9_addressX2E2Export8_8sX5Fgood3(&instance, 65503u),
        0ull,
        "8s_good3(65503u)"
    );
    assertEqualU64(
        m9_addressX2E2Export8_8sX5Fgood4(&instance, 65503u),
        0ull,
        "8s_good4(65503u)"
    );
    assertEqualU64(
        m9_addressX2E2Export8_8sX5Fgood5(&instance, 65503u),
        0ull,
        "8s_good5(65503u)"
    );
    assertEqualU64(
        m9_addressX2E2Export9_16uX5Fgood1(&instance, 65503u),
        0ull,
        "16u_good1(65503u)"
    );
    assertEqualU64(
        m9_addressX2E2Export9_16uX5Fgood2(&instance, 65503u),
        0ull,
        "16u_good2(65503u)"
    );
    assertEqualU64(
        m9_addressX2E2Export9_16uX5Fgood3(&instance, 65503u),
        0ull,
        "16u_good3(65503u)"
    );
    assertEqualU64(
        m9_addressX2E2Export9_16uX5Fgood4(&instance, 65503u),
        0ull,
        "16u_good4(65503u)"
    );
    assertEqualU64(
        m9_addressX2E2Export9_16uX5Fgood5(&instance, 65503u),
        0ull,
        "16u_good5(65503u)"
    );
    assertEqualU64(
        m9_addressX2E2Export9_16sX5Fgood1(&instance, 65503u),
        0ull,
        "16s_good1(65503u)"
    );
    assertEqualU64(
        m9_addressX2E2Export9_16sX5Fgood2(&instance, 65503u),
        0ull,
        "16s_good2(65503u)"
    );
    assertEqualU64(
        m9_addressX2E2Export9_16sX5Fgood3(&instance, 65503u),
        0ull,
        "16s_good3(65503u)"
    );
    assertEqualU64(
        m9_addressX2E2Export9_16sX5Fgood4(&instance, 65503u),
        0ull,
        "16s_good4(65503u)"
    );
    assertEqualU64(
        m9_addressX2E2Export9_16sX5Fgood5(&instance, 65503u),
        0ull,
        "16s_good5(65503u)"
    );
    assertEqualU64(
        m9_addressX2E2Export9_32uX5Fgood1(&instance, 65503u),
        0ull,
        "32u_good1(65503u)"
    );
    assertEqualU64(
        m9_addressX2E2Export9_32uX5Fgood2(&instance, 65503u),
        0ull,
        "32u_good2(65503u)"
    );
    assertEqualU64(
        m9_addressX2E2Export9_32uX5Fgood3(&instance, 65503u),
        0ull,
        "32u_good3(65503u)"
    );
    assertEqualU64(
        m9_addressX2E2Export9_32uX5Fgood4(&instance, 65503u),
        0ull,
        "32u_good4(65503u)"
    );
    assertEqualU64(
        m9_addressX2E2Export9_32uX5Fgood5(&instance, 65503u),
        0ull,
        "32u_good5(65503u)"
    );
    assertEqualU64(
        m9_addressX2E2Export9_32sX5Fgood1(&instance, 65503u),
        0ull,
        "32s_good1(65503u)"
    );
    assertEqualU64(
        m9_addressX2E2Export9_32sX5Fgood2(&instance, 65503u),
        0ull,
        "32s_good2(65503u)"
    );
    assertEqualU64(
        m9_addressX2E2Export9_32sX5Fgood3(&instance, 65503u),
        0ull,
        "32s_good3(65503u)"
    );
    assertEqualU64(
        m9_addressX2E2Export9_32sX5Fgood4(&instance, 65503u),
        0ull,
        "32s_good4(65503u)"
    );
    assertEqualU64(
        m9_addressX2E2Export9_32sX5Fgood5(&instance, 65503u),
        0ull,
        "32s_good5(65503u)"
    );
    assertEqualU64(
        m9_addressX2E2Export8_64X5Fgood1(&instance, 65503u),
        0ull,
        "64_good1(65503u)"
    );
    assertEqualU64(
        m9_addressX2E2Export8_64X5Fgood2(&instance, 65503u),
        0ull,
        "64_good2(65503u)"
    );
    assertEqualU64(
        m9_addressX2E2Export8_64X5Fgood3(&instance, 65503u),
        0ull,
        "64_good3(65503u)"
    );
    assertEqualU64(
        m9_addressX2E2Export8_64X5Fgood4(&instance, 65503u),
        0ull,
        "64_good4(65503u)"
    );
    assertEqualU64(
        m9_addressX2E2Export8_64X5Fgood5(&instance, 65503u),
        0ull,
        "64_good5(65503u)"
    );
    assertEqualU64(
        m9_addressX2E2Export8_8uX5Fgood1(&instance, 65504u),
        0ull,
        "8u_good1(65504u)"
    );
    assertEqualU64(
        m9_addressX2E2Export8_8uX5Fgood2(&instance, 65504u),
        0ull,
        "8u_good2(65504u)"
    );
    assertEqualU64(
        m9_addressX2E2Export8_8uX5Fgood3(&instance, 65504u),
        0ull,
        "8u_good3(65504u)"
    );
    assertEqualU64(
        m9_addressX2E2Export8_8uX5Fgood4(&instance, 65504u),
        0ull,
        "8u_good4(65504u)"
    );
    assertEqualU64(
        m9_addressX2E2Export8_8uX5Fgood5(&instance, 65504u),
        0ull,
        "8u_good5(65504u)"
    );
    assertEqualU64(
        m9_addressX2E2Export8_8sX5Fgood1(&instance, 65504u),
        0ull,
        "8s_good1(65504u)"
    );
    assertEqualU64(
        m9_addressX2E2Export8_8sX5Fgood2(&instance, 65504u),
        0ull,
        "8s_good2(65504u)"
    );
    assertEqualU64(
        m9_addressX2E2Export8_8sX5Fgood3(&instance, 65504u),
        0ull,
        "8s_good3(65504u)"
    );
    assertEqualU64(
        m9_addressX2E2Export8_8sX5Fgood4(&instance, 65504u),
        0ull,
        "8s_good4(65504u)"
    );
    assertEqualU64(
        m9_addressX2E2Export8_8sX5Fgood5(&instance, 65504u),
        0ull,
        "8s_good5(65504u)"
    );
    assertEqualU64(
        m9_addressX2E2Export9_16uX5Fgood1(&instance, 65504u),
        0ull,
        "16u_good1(65504u)"
    );
    assertEqualU64(
        m9_addressX2E2Export9_16uX5Fgood2(&instance, 65504u),
        0ull,
        "16u_good2(65504u)"
    );
    assertEqualU64(
        m9_addressX2E2Export9_16uX5Fgood3(&instance, 65504u),
        0ull,
        "16u_good3(65504u)"
    );
    assertEqualU64(
        m9_addressX2E2Export9_16uX5Fgood4(&instance, 65504u),
        0ull,
        "16u_good4(65504u)"
    );
    assertEqualU64(
        m9_addressX2E2Export9_16uX5Fgood5(&instance, 65504u),
        0ull,
        "16u_good5(65504u)"
    );
    assertEqualU64(
        m9_addressX2E2Export9_16sX5Fgood1(&instance, 65504u),
        0ull,
        "16s_good1(65504u)"
    );
    assertEqualU64(
        m9_addressX2E2Export9_16sX5Fgood2(&instance, 65504u),
        0ull,
        "16s_good2(65504u)"
    );
    assertEqualU64(
        m9_addressX2E2Export9_16sX5Fgood3(&instance, 65504u),
        0ull,
        "16s_good3(65504u)"
    );
    assertEqualU64(
        m9_addressX2E2Export9_16sX5Fgood4(&instance, 65504u),
        0ull,
        "16s_good4(65504u)"
    );
    assertEqualU64(
        m9_addressX2E2Export9_16sX5Fgood5(&instance, 65504u),
        0ull,
        "16s_good5(65504u)"
    );
    assertEqualU64(
        m9_addressX2E2Export9_32uX5Fgood1(&instance, 65504u),
        0ull,
        "32u_good1(65504u)"
    );
    assertEqualU64(
        m9_addressX2E2Export9_32uX5Fgood2(&instance, 65504u),
        0ull,
        "32u_good2(65504u)"
    );
    assertEqualU64(
        m9_addressX2E2Export9_32uX5Fgood3(&instance, 65504u),
        0ull,
        "32u_good3(65504u)"
    );
    assertEqualU64(
        m9_addressX2E2Export9_32uX5Fgood4(&instance, 65504u),
        0ull,
        "32u_good4(65504u)"
    );
    assertEqualU64(
        m9_addressX2E2Export9_32uX5Fgood5(&instance, 65504u),
        0ull,
        "32u_good5(65504u)"
    );
    assertEqualU64(
        m9_addressX2E2Export9_32sX5Fgood1(&instance, 65504u),
        0ull,
        "32s_good1(65504u)"
    );
    assertEqualU64(
        m9_addressX2E2Export9_32sX5Fgood2(&instance, 65504u),
        0ull,
        "32s_good2(65504u)"
    );
    assertEqualU64(
        m9_addressX2E2Export9_32sX5Fgood3(&instance, 65504u),
        0ull,
        "32s_good3(65504u)"
    );
    assertEqualU64(
        m9_addressX2E2Export9_32sX5Fgood4(&instance, 65504u),
        0ull,
        "32s_good4(65504u)"
    );
    assertEqualU64(
        m9_addressX2E2Export9_32sX5Fgood5(&instance, 65504u),
        0ull,
        "32s_good5(65504u)"
    );
    assertEqualU64(
        m9_addressX2E2Export8_64X5Fgood1(&instance, 65504u),
        0ull,
        "64_good1(65504u)"
    );
    assertEqualU64(
        m9_addressX2E2Export8_64X5Fgood2(&instance, 65504u),
        0ull,
        "64_good2(65504u)"
    );
    assertEqualU64(
        m9_addressX2E2Export8_64X5Fgood3(&instance, 65504u),
        0ull,
        "64_good3(65504u)"
    );
    assertEqualU64(
        m9_addressX2E2Export8_64X5Fgood4(&instance, 65504u),
        0ull,
        "64_good4(65504u)"
    );
#if W2C2_RUNTIME_CHECKS
    assertTrap(m9_addressX2E2Export8_64X5Fgood5(&instance, 65504u), trapMemoryOutOfBounds, "64_good5(65504u)");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m9_addressX2E2Export8_8uX5Fgood3(&instance, 4294967295u), trapMemoryOutOfBounds, "8u_good3(4294967295u)");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m9_addressX2E2Export8_8sX5Fgood3(&instance, 4294967295u), trapMemoryOutOfBounds, "8s_good3(4294967295u)");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m9_addressX2E2Export9_16uX5Fgood3(&instance, 4294967295u), trapMemoryOutOfBounds, "16u_good3(4294967295u)");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m9_addressX2E2Export9_16sX5Fgood3(&instance, 4294967295u), trapMemoryOutOfBounds, "16s_good3(4294967295u)");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m9_addressX2E2Export9_32uX5Fgood3(&instance, 4294967295u), trapMemoryOutOfBounds, "32u_good3(4294967295u)");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m9_addressX2E2Export9_32sX5Fgood3(&instance, 4294967295u), trapMemoryOutOfBounds, "32s_good3(4294967295u)");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m9_addressX2E2Export8_64X5Fgood3(&instance, 4294967295u), trapMemoryOutOfBounds, "64_good3(4294967295u)");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m9_addressX2E2Export6_8uX5Fbad(&instance, 0u), trapMemoryOutOfBounds, "8u_bad(0u)");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m9_addressX2E2Export6_8sX5Fbad(&instance, 0u), trapMemoryOutOfBounds, "8s_bad(0u)");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m9_addressX2E2Export7_16uX5Fbad(&instance, 0u), trapMemoryOutOfBounds, "16u_bad(0u)");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m9_addressX2E2Export7_16sX5Fbad(&instance, 0u), trapMemoryOutOfBounds, "16s_bad(0u)");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m9_addressX2E2Export7_32uX5Fbad(&instance, 0u), trapMemoryOutOfBounds, "32u_bad(0u)");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m9_addressX2E2Export7_32sX5Fbad(&instance, 0u), trapMemoryOutOfBounds, "32s_bad(0u)");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m9_addressX2E2Export6_64X5Fbad(&instance, 0u), trapMemoryOutOfBounds, "64_bad(0u)");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m9_addressX2E2Export6_8uX5Fbad(&instance, 1u), trapMemoryOutOfBounds, "8u_bad(1u)");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m9_addressX2E2Export6_8sX5Fbad(&instance, 1u), trapMemoryOutOfBounds, "8s_bad(1u)");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m9_addressX2E2Export7_16uX5Fbad(&instance, 1u), trapMemoryOutOfBounds, "16u_bad(1u)");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m9_addressX2E2Export7_16sX5Fbad(&instance, 1u), trapMemoryOutOfBounds, "16s_bad(1u)");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m9_addressX2E2Export7_32uX5Fbad(&instance, 0u), trapMemoryOutOfBounds, "32u_bad(0u)");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m9_addressX2E2Export7_32sX5Fbad(&instance, 0u), trapMemoryOutOfBounds, "32s_bad(0u)");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m9_addressX2E2Export6_64X5Fbad(&instance, 1u), trapMemoryOutOfBounds, "64_bad(1u)");
#endif
    m9_addressX2E2FreeInstance(&instance);
}
