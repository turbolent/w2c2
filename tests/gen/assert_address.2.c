
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_address.2.h"

void test() {
    address2Instance instance;
    address2Instantiate(&instance, resolveTestImports);
    printStart("address.2.wasm");
    assertEqualU64(
        address2_8uX5Fgood1(&instance, 0u),
        97ull,
        "8u_good1(0u)"
    );
    assertEqualU64(
        address2_8uX5Fgood2(&instance, 0u),
        97ull,
        "8u_good2(0u)"
    );
    assertEqualU64(
        address2_8uX5Fgood3(&instance, 0u),
        98ull,
        "8u_good3(0u)"
    );
    assertEqualU64(
        address2_8uX5Fgood4(&instance, 0u),
        99ull,
        "8u_good4(0u)"
    );
    assertEqualU64(
        address2_8uX5Fgood5(&instance, 0u),
        122ull,
        "8u_good5(0u)"
    );
    assertEqualU64(
        address2_8sX5Fgood1(&instance, 0u),
        97ull,
        "8s_good1(0u)"
    );
    assertEqualU64(
        address2_8sX5Fgood2(&instance, 0u),
        97ull,
        "8s_good2(0u)"
    );
    assertEqualU64(
        address2_8sX5Fgood3(&instance, 0u),
        98ull,
        "8s_good3(0u)"
    );
    assertEqualU64(
        address2_8sX5Fgood4(&instance, 0u),
        99ull,
        "8s_good4(0u)"
    );
    assertEqualU64(
        address2_8sX5Fgood5(&instance, 0u),
        122ull,
        "8s_good5(0u)"
    );
    assertEqualU64(
        address2_16uX5Fgood1(&instance, 0u),
        25185ull,
        "16u_good1(0u)"
    );
    assertEqualU64(
        address2_16uX5Fgood2(&instance, 0u),
        25185ull,
        "16u_good2(0u)"
    );
    assertEqualU64(
        address2_16uX5Fgood3(&instance, 0u),
        25442ull,
        "16u_good3(0u)"
    );
    assertEqualU64(
        address2_16uX5Fgood4(&instance, 0u),
        25699ull,
        "16u_good4(0u)"
    );
    assertEqualU64(
        address2_16uX5Fgood5(&instance, 0u),
        122ull,
        "16u_good5(0u)"
    );
    assertEqualU64(
        address2_16sX5Fgood1(&instance, 0u),
        25185ull,
        "16s_good1(0u)"
    );
    assertEqualU64(
        address2_16sX5Fgood2(&instance, 0u),
        25185ull,
        "16s_good2(0u)"
    );
    assertEqualU64(
        address2_16sX5Fgood3(&instance, 0u),
        25442ull,
        "16s_good3(0u)"
    );
    assertEqualU64(
        address2_16sX5Fgood4(&instance, 0u),
        25699ull,
        "16s_good4(0u)"
    );
    assertEqualU64(
        address2_16sX5Fgood5(&instance, 0u),
        122ull,
        "16s_good5(0u)"
    );
    assertEqualU64(
        address2_32uX5Fgood1(&instance, 0u),
        1684234849ull,
        "32u_good1(0u)"
    );
    assertEqualU64(
        address2_32uX5Fgood2(&instance, 0u),
        1684234849ull,
        "32u_good2(0u)"
    );
    assertEqualU64(
        address2_32uX5Fgood3(&instance, 0u),
        1701077858ull,
        "32u_good3(0u)"
    );
    assertEqualU64(
        address2_32uX5Fgood4(&instance, 0u),
        1717920867ull,
        "32u_good4(0u)"
    );
    assertEqualU64(
        address2_32uX5Fgood5(&instance, 0u),
        122ull,
        "32u_good5(0u)"
    );
    assertEqualU64(
        address2_32sX5Fgood1(&instance, 0u),
        1684234849ull,
        "32s_good1(0u)"
    );
    assertEqualU64(
        address2_32sX5Fgood2(&instance, 0u),
        1684234849ull,
        "32s_good2(0u)"
    );
    assertEqualU64(
        address2_32sX5Fgood3(&instance, 0u),
        1701077858ull,
        "32s_good3(0u)"
    );
    assertEqualU64(
        address2_32sX5Fgood4(&instance, 0u),
        1717920867ull,
        "32s_good4(0u)"
    );
    assertEqualU64(
        address2_32sX5Fgood5(&instance, 0u),
        122ull,
        "32s_good5(0u)"
    );
    assertEqualU64(
        address2_64X5Fgood1(&instance, 0u),
        7523094288207667809ull,
        "64_good1(0u)"
    );
    assertEqualU64(
        address2_64X5Fgood2(&instance, 0u),
        7523094288207667809ull,
        "64_good2(0u)"
    );
    assertEqualU64(
        address2_64X5Fgood3(&instance, 0u),
        7595434461045744482ull,
        "64_good3(0u)"
    );
    assertEqualU64(
        address2_64X5Fgood4(&instance, 0u),
        7667774633883821155ull,
        "64_good4(0u)"
    );
    assertEqualU64(
        address2_64X5Fgood5(&instance, 0u),
        122ull,
        "64_good5(0u)"
    );
    assertEqualU64(
        address2_8uX5Fgood1(&instance, 65503u),
        0ull,
        "8u_good1(65503u)"
    );
    assertEqualU64(
        address2_8uX5Fgood2(&instance, 65503u),
        0ull,
        "8u_good2(65503u)"
    );
    assertEqualU64(
        address2_8uX5Fgood3(&instance, 65503u),
        0ull,
        "8u_good3(65503u)"
    );
    assertEqualU64(
        address2_8uX5Fgood4(&instance, 65503u),
        0ull,
        "8u_good4(65503u)"
    );
    assertEqualU64(
        address2_8uX5Fgood5(&instance, 65503u),
        0ull,
        "8u_good5(65503u)"
    );
    assertEqualU64(
        address2_8sX5Fgood1(&instance, 65503u),
        0ull,
        "8s_good1(65503u)"
    );
    assertEqualU64(
        address2_8sX5Fgood2(&instance, 65503u),
        0ull,
        "8s_good2(65503u)"
    );
    assertEqualU64(
        address2_8sX5Fgood3(&instance, 65503u),
        0ull,
        "8s_good3(65503u)"
    );
    assertEqualU64(
        address2_8sX5Fgood4(&instance, 65503u),
        0ull,
        "8s_good4(65503u)"
    );
    assertEqualU64(
        address2_8sX5Fgood5(&instance, 65503u),
        0ull,
        "8s_good5(65503u)"
    );
    assertEqualU64(
        address2_16uX5Fgood1(&instance, 65503u),
        0ull,
        "16u_good1(65503u)"
    );
    assertEqualU64(
        address2_16uX5Fgood2(&instance, 65503u),
        0ull,
        "16u_good2(65503u)"
    );
    assertEqualU64(
        address2_16uX5Fgood3(&instance, 65503u),
        0ull,
        "16u_good3(65503u)"
    );
    assertEqualU64(
        address2_16uX5Fgood4(&instance, 65503u),
        0ull,
        "16u_good4(65503u)"
    );
    assertEqualU64(
        address2_16uX5Fgood5(&instance, 65503u),
        0ull,
        "16u_good5(65503u)"
    );
    assertEqualU64(
        address2_16sX5Fgood1(&instance, 65503u),
        0ull,
        "16s_good1(65503u)"
    );
    assertEqualU64(
        address2_16sX5Fgood2(&instance, 65503u),
        0ull,
        "16s_good2(65503u)"
    );
    assertEqualU64(
        address2_16sX5Fgood3(&instance, 65503u),
        0ull,
        "16s_good3(65503u)"
    );
    assertEqualU64(
        address2_16sX5Fgood4(&instance, 65503u),
        0ull,
        "16s_good4(65503u)"
    );
    assertEqualU64(
        address2_16sX5Fgood5(&instance, 65503u),
        0ull,
        "16s_good5(65503u)"
    );
    assertEqualU64(
        address2_32uX5Fgood1(&instance, 65503u),
        0ull,
        "32u_good1(65503u)"
    );
    assertEqualU64(
        address2_32uX5Fgood2(&instance, 65503u),
        0ull,
        "32u_good2(65503u)"
    );
    assertEqualU64(
        address2_32uX5Fgood3(&instance, 65503u),
        0ull,
        "32u_good3(65503u)"
    );
    assertEqualU64(
        address2_32uX5Fgood4(&instance, 65503u),
        0ull,
        "32u_good4(65503u)"
    );
    assertEqualU64(
        address2_32uX5Fgood5(&instance, 65503u),
        0ull,
        "32u_good5(65503u)"
    );
    assertEqualU64(
        address2_32sX5Fgood1(&instance, 65503u),
        0ull,
        "32s_good1(65503u)"
    );
    assertEqualU64(
        address2_32sX5Fgood2(&instance, 65503u),
        0ull,
        "32s_good2(65503u)"
    );
    assertEqualU64(
        address2_32sX5Fgood3(&instance, 65503u),
        0ull,
        "32s_good3(65503u)"
    );
    assertEqualU64(
        address2_32sX5Fgood4(&instance, 65503u),
        0ull,
        "32s_good4(65503u)"
    );
    assertEqualU64(
        address2_32sX5Fgood5(&instance, 65503u),
        0ull,
        "32s_good5(65503u)"
    );
    assertEqualU64(
        address2_64X5Fgood1(&instance, 65503u),
        0ull,
        "64_good1(65503u)"
    );
    assertEqualU64(
        address2_64X5Fgood2(&instance, 65503u),
        0ull,
        "64_good2(65503u)"
    );
    assertEqualU64(
        address2_64X5Fgood3(&instance, 65503u),
        0ull,
        "64_good3(65503u)"
    );
    assertEqualU64(
        address2_64X5Fgood4(&instance, 65503u),
        0ull,
        "64_good4(65503u)"
    );
    assertEqualU64(
        address2_64X5Fgood5(&instance, 65503u),
        0ull,
        "64_good5(65503u)"
    );
    assertEqualU64(
        address2_8uX5Fgood1(&instance, 65504u),
        0ull,
        "8u_good1(65504u)"
    );
    assertEqualU64(
        address2_8uX5Fgood2(&instance, 65504u),
        0ull,
        "8u_good2(65504u)"
    );
    assertEqualU64(
        address2_8uX5Fgood3(&instance, 65504u),
        0ull,
        "8u_good3(65504u)"
    );
    assertEqualU64(
        address2_8uX5Fgood4(&instance, 65504u),
        0ull,
        "8u_good4(65504u)"
    );
    assertEqualU64(
        address2_8uX5Fgood5(&instance, 65504u),
        0ull,
        "8u_good5(65504u)"
    );
    assertEqualU64(
        address2_8sX5Fgood1(&instance, 65504u),
        0ull,
        "8s_good1(65504u)"
    );
    assertEqualU64(
        address2_8sX5Fgood2(&instance, 65504u),
        0ull,
        "8s_good2(65504u)"
    );
    assertEqualU64(
        address2_8sX5Fgood3(&instance, 65504u),
        0ull,
        "8s_good3(65504u)"
    );
    assertEqualU64(
        address2_8sX5Fgood4(&instance, 65504u),
        0ull,
        "8s_good4(65504u)"
    );
    assertEqualU64(
        address2_8sX5Fgood5(&instance, 65504u),
        0ull,
        "8s_good5(65504u)"
    );
    assertEqualU64(
        address2_16uX5Fgood1(&instance, 65504u),
        0ull,
        "16u_good1(65504u)"
    );
    assertEqualU64(
        address2_16uX5Fgood2(&instance, 65504u),
        0ull,
        "16u_good2(65504u)"
    );
    assertEqualU64(
        address2_16uX5Fgood3(&instance, 65504u),
        0ull,
        "16u_good3(65504u)"
    );
    assertEqualU64(
        address2_16uX5Fgood4(&instance, 65504u),
        0ull,
        "16u_good4(65504u)"
    );
    assertEqualU64(
        address2_16uX5Fgood5(&instance, 65504u),
        0ull,
        "16u_good5(65504u)"
    );
    assertEqualU64(
        address2_16sX5Fgood1(&instance, 65504u),
        0ull,
        "16s_good1(65504u)"
    );
    assertEqualU64(
        address2_16sX5Fgood2(&instance, 65504u),
        0ull,
        "16s_good2(65504u)"
    );
    assertEqualU64(
        address2_16sX5Fgood3(&instance, 65504u),
        0ull,
        "16s_good3(65504u)"
    );
    assertEqualU64(
        address2_16sX5Fgood4(&instance, 65504u),
        0ull,
        "16s_good4(65504u)"
    );
    assertEqualU64(
        address2_16sX5Fgood5(&instance, 65504u),
        0ull,
        "16s_good5(65504u)"
    );
    assertEqualU64(
        address2_32uX5Fgood1(&instance, 65504u),
        0ull,
        "32u_good1(65504u)"
    );
    assertEqualU64(
        address2_32uX5Fgood2(&instance, 65504u),
        0ull,
        "32u_good2(65504u)"
    );
    assertEqualU64(
        address2_32uX5Fgood3(&instance, 65504u),
        0ull,
        "32u_good3(65504u)"
    );
    assertEqualU64(
        address2_32uX5Fgood4(&instance, 65504u),
        0ull,
        "32u_good4(65504u)"
    );
    assertEqualU64(
        address2_32uX5Fgood5(&instance, 65504u),
        0ull,
        "32u_good5(65504u)"
    );
    assertEqualU64(
        address2_32sX5Fgood1(&instance, 65504u),
        0ull,
        "32s_good1(65504u)"
    );
    assertEqualU64(
        address2_32sX5Fgood2(&instance, 65504u),
        0ull,
        "32s_good2(65504u)"
    );
    assertEqualU64(
        address2_32sX5Fgood3(&instance, 65504u),
        0ull,
        "32s_good3(65504u)"
    );
    assertEqualU64(
        address2_32sX5Fgood4(&instance, 65504u),
        0ull,
        "32s_good4(65504u)"
    );
    assertEqualU64(
        address2_32sX5Fgood5(&instance, 65504u),
        0ull,
        "32s_good5(65504u)"
    );
    assertEqualU64(
        address2_64X5Fgood1(&instance, 65504u),
        0ull,
        "64_good1(65504u)"
    );
    assertEqualU64(
        address2_64X5Fgood2(&instance, 65504u),
        0ull,
        "64_good2(65504u)"
    );
    assertEqualU64(
        address2_64X5Fgood3(&instance, 65504u),
        0ull,
        "64_good3(65504u)"
    );
    assertEqualU64(
        address2_64X5Fgood4(&instance, 65504u),
        0ull,
        "64_good4(65504u)"
    );
}
