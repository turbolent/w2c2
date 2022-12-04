
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_address.0.h"

void test() {
    address0Instance instance;
    address0Instantiate(&instance, resolveTestImports);
    printStart("address.0.wasm");
    assertEqualU32(
        address0_8uX5Fgood1(&instance, 0u),
        97u,
        "8u_good1(0u)"
    );
    assertEqualU32(
        address0_8uX5Fgood2(&instance, 0u),
        97u,
        "8u_good2(0u)"
    );
    assertEqualU32(
        address0_8uX5Fgood3(&instance, 0u),
        98u,
        "8u_good3(0u)"
    );
    assertEqualU32(
        address0_8uX5Fgood4(&instance, 0u),
        99u,
        "8u_good4(0u)"
    );
    assertEqualU32(
        address0_8uX5Fgood5(&instance, 0u),
        122u,
        "8u_good5(0u)"
    );
    assertEqualU32(
        address0_8sX5Fgood1(&instance, 0u),
        97u,
        "8s_good1(0u)"
    );
    assertEqualU32(
        address0_8sX5Fgood2(&instance, 0u),
        97u,
        "8s_good2(0u)"
    );
    assertEqualU32(
        address0_8sX5Fgood3(&instance, 0u),
        98u,
        "8s_good3(0u)"
    );
    assertEqualU32(
        address0_8sX5Fgood4(&instance, 0u),
        99u,
        "8s_good4(0u)"
    );
    assertEqualU32(
        address0_8sX5Fgood5(&instance, 0u),
        122u,
        "8s_good5(0u)"
    );
    assertEqualU32(
        address0_16uX5Fgood1(&instance, 0u),
        25185u,
        "16u_good1(0u)"
    );
    assertEqualU32(
        address0_16uX5Fgood2(&instance, 0u),
        25185u,
        "16u_good2(0u)"
    );
    assertEqualU32(
        address0_16uX5Fgood3(&instance, 0u),
        25442u,
        "16u_good3(0u)"
    );
    assertEqualU32(
        address0_16uX5Fgood4(&instance, 0u),
        25699u,
        "16u_good4(0u)"
    );
    assertEqualU32(
        address0_16uX5Fgood5(&instance, 0u),
        122u,
        "16u_good5(0u)"
    );
    assertEqualU32(
        address0_16sX5Fgood1(&instance, 0u),
        25185u,
        "16s_good1(0u)"
    );
    assertEqualU32(
        address0_16sX5Fgood2(&instance, 0u),
        25185u,
        "16s_good2(0u)"
    );
    assertEqualU32(
        address0_16sX5Fgood3(&instance, 0u),
        25442u,
        "16s_good3(0u)"
    );
    assertEqualU32(
        address0_16sX5Fgood4(&instance, 0u),
        25699u,
        "16s_good4(0u)"
    );
    assertEqualU32(
        address0_16sX5Fgood5(&instance, 0u),
        122u,
        "16s_good5(0u)"
    );
    assertEqualU32(
        address0_32X5Fgood1(&instance, 0u),
        1684234849u,
        "32_good1(0u)"
    );
    assertEqualU32(
        address0_32X5Fgood2(&instance, 0u),
        1684234849u,
        "32_good2(0u)"
    );
    assertEqualU32(
        address0_32X5Fgood3(&instance, 0u),
        1701077858u,
        "32_good3(0u)"
    );
    assertEqualU32(
        address0_32X5Fgood4(&instance, 0u),
        1717920867u,
        "32_good4(0u)"
    );
    assertEqualU32(
        address0_32X5Fgood5(&instance, 0u),
        122u,
        "32_good5(0u)"
    );
    assertEqualU32(
        address0_8uX5Fgood1(&instance, 65507u),
        0u,
        "8u_good1(65507u)"
    );
    assertEqualU32(
        address0_8uX5Fgood2(&instance, 65507u),
        0u,
        "8u_good2(65507u)"
    );
    assertEqualU32(
        address0_8uX5Fgood3(&instance, 65507u),
        0u,
        "8u_good3(65507u)"
    );
    assertEqualU32(
        address0_8uX5Fgood4(&instance, 65507u),
        0u,
        "8u_good4(65507u)"
    );
    assertEqualU32(
        address0_8uX5Fgood5(&instance, 65507u),
        0u,
        "8u_good5(65507u)"
    );
    assertEqualU32(
        address0_8sX5Fgood1(&instance, 65507u),
        0u,
        "8s_good1(65507u)"
    );
    assertEqualU32(
        address0_8sX5Fgood2(&instance, 65507u),
        0u,
        "8s_good2(65507u)"
    );
    assertEqualU32(
        address0_8sX5Fgood3(&instance, 65507u),
        0u,
        "8s_good3(65507u)"
    );
    assertEqualU32(
        address0_8sX5Fgood4(&instance, 65507u),
        0u,
        "8s_good4(65507u)"
    );
    assertEqualU32(
        address0_8sX5Fgood5(&instance, 65507u),
        0u,
        "8s_good5(65507u)"
    );
    assertEqualU32(
        address0_16uX5Fgood1(&instance, 65507u),
        0u,
        "16u_good1(65507u)"
    );
    assertEqualU32(
        address0_16uX5Fgood2(&instance, 65507u),
        0u,
        "16u_good2(65507u)"
    );
    assertEqualU32(
        address0_16uX5Fgood3(&instance, 65507u),
        0u,
        "16u_good3(65507u)"
    );
    assertEqualU32(
        address0_16uX5Fgood4(&instance, 65507u),
        0u,
        "16u_good4(65507u)"
    );
    assertEqualU32(
        address0_16uX5Fgood5(&instance, 65507u),
        0u,
        "16u_good5(65507u)"
    );
    assertEqualU32(
        address0_16sX5Fgood1(&instance, 65507u),
        0u,
        "16s_good1(65507u)"
    );
    assertEqualU32(
        address0_16sX5Fgood2(&instance, 65507u),
        0u,
        "16s_good2(65507u)"
    );
    assertEqualU32(
        address0_16sX5Fgood3(&instance, 65507u),
        0u,
        "16s_good3(65507u)"
    );
    assertEqualU32(
        address0_16sX5Fgood4(&instance, 65507u),
        0u,
        "16s_good4(65507u)"
    );
    assertEqualU32(
        address0_16sX5Fgood5(&instance, 65507u),
        0u,
        "16s_good5(65507u)"
    );
    assertEqualU32(
        address0_32X5Fgood1(&instance, 65507u),
        0u,
        "32_good1(65507u)"
    );
    assertEqualU32(
        address0_32X5Fgood2(&instance, 65507u),
        0u,
        "32_good2(65507u)"
    );
    assertEqualU32(
        address0_32X5Fgood3(&instance, 65507u),
        0u,
        "32_good3(65507u)"
    );
    assertEqualU32(
        address0_32X5Fgood4(&instance, 65507u),
        0u,
        "32_good4(65507u)"
    );
    assertEqualU32(
        address0_32X5Fgood5(&instance, 65507u),
        0u,
        "32_good5(65507u)"
    );
    assertEqualU32(
        address0_8uX5Fgood1(&instance, 65508u),
        0u,
        "8u_good1(65508u)"
    );
    assertEqualU32(
        address0_8uX5Fgood2(&instance, 65508u),
        0u,
        "8u_good2(65508u)"
    );
    assertEqualU32(
        address0_8uX5Fgood3(&instance, 65508u),
        0u,
        "8u_good3(65508u)"
    );
    assertEqualU32(
        address0_8uX5Fgood4(&instance, 65508u),
        0u,
        "8u_good4(65508u)"
    );
    assertEqualU32(
        address0_8uX5Fgood5(&instance, 65508u),
        0u,
        "8u_good5(65508u)"
    );
    assertEqualU32(
        address0_8sX5Fgood1(&instance, 65508u),
        0u,
        "8s_good1(65508u)"
    );
    assertEqualU32(
        address0_8sX5Fgood2(&instance, 65508u),
        0u,
        "8s_good2(65508u)"
    );
    assertEqualU32(
        address0_8sX5Fgood3(&instance, 65508u),
        0u,
        "8s_good3(65508u)"
    );
    assertEqualU32(
        address0_8sX5Fgood4(&instance, 65508u),
        0u,
        "8s_good4(65508u)"
    );
    assertEqualU32(
        address0_8sX5Fgood5(&instance, 65508u),
        0u,
        "8s_good5(65508u)"
    );
    assertEqualU32(
        address0_16uX5Fgood1(&instance, 65508u),
        0u,
        "16u_good1(65508u)"
    );
    assertEqualU32(
        address0_16uX5Fgood2(&instance, 65508u),
        0u,
        "16u_good2(65508u)"
    );
    assertEqualU32(
        address0_16uX5Fgood3(&instance, 65508u),
        0u,
        "16u_good3(65508u)"
    );
    assertEqualU32(
        address0_16uX5Fgood4(&instance, 65508u),
        0u,
        "16u_good4(65508u)"
    );
    assertEqualU32(
        address0_16uX5Fgood5(&instance, 65508u),
        0u,
        "16u_good5(65508u)"
    );
    assertEqualU32(
        address0_16sX5Fgood1(&instance, 65508u),
        0u,
        "16s_good1(65508u)"
    );
    assertEqualU32(
        address0_16sX5Fgood2(&instance, 65508u),
        0u,
        "16s_good2(65508u)"
    );
    assertEqualU32(
        address0_16sX5Fgood3(&instance, 65508u),
        0u,
        "16s_good3(65508u)"
    );
    assertEqualU32(
        address0_16sX5Fgood4(&instance, 65508u),
        0u,
        "16s_good4(65508u)"
    );
    assertEqualU32(
        address0_16sX5Fgood5(&instance, 65508u),
        0u,
        "16s_good5(65508u)"
    );
    assertEqualU32(
        address0_32X5Fgood1(&instance, 65508u),
        0u,
        "32_good1(65508u)"
    );
    assertEqualU32(
        address0_32X5Fgood2(&instance, 65508u),
        0u,
        "32_good2(65508u)"
    );
    assertEqualU32(
        address0_32X5Fgood3(&instance, 65508u),
        0u,
        "32_good3(65508u)"
    );
    assertEqualU32(
        address0_32X5Fgood4(&instance, 65508u),
        0u,
        "32_good4(65508u)"
    );
}
