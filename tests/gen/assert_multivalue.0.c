#include "test.h"
#include "test_multivalue.0.h"

void test(void) {
    static m12_multivalueX2E0Instance instance;
    m12_multivalueX2E0Instantiate(&instance, resolveTestImports);
    printStart("multivalue.0.wasm");
    {
        struct w2c2_result_ij result;
        result = m12_multivalueX2E0Export4_pair(&instance);
        assertEqualU32(
            result.v0,
            17u,
            "pair() result 0"
        );
        assertEqualU64(
            result.v1,
            29ull,
            "pair() result 1"
        );
    }
    assertEqualU32(
        m12_multivalueX2E0Export5_calls(&instance),
        1u,
        "calls()"
    );
    {
        struct w2c2_result_ij result;
        result = m12_multivalueX2E0Export6_direct(&instance);
        assertEqualU32(
            result.v0,
            17u,
            "direct() result 0"
        );
        assertEqualU64(
            result.v1,
            29ull,
            "direct() result 1"
        );
    }
    assertEqualU32(
        m12_multivalueX2E0Export5_calls(&instance),
        2u,
        "calls()"
    );
    {
        struct w2c2_result_ij result;
        result = m12_multivalueX2E0Export9_recursive(&instance, 0u);
        assertEqualU32(
            result.v0,
            0u,
            "recursive(0u) result 0"
        );
        assertEqualU64(
            result.v1,
            1ull,
            "recursive(0u) result 1"
        );
    }
    {
        struct w2c2_result_ij result;
        result = m12_multivalueX2E0Export9_recursive(&instance, 1u);
        assertEqualU32(
            result.v0,
            1u,
            "recursive(1u) result 0"
        );
        assertEqualU64(
            result.v1,
            1ull,
            "recursive(1u) result 1"
        );
    }
    {
        struct w2c2_result_ij result;
        result = m12_multivalueX2E0Export9_recursive(&instance, 5u);
        assertEqualU32(
            result.v0,
            5u,
            "recursive(5u) result 0"
        );
        assertEqualU64(
            result.v1,
            120ull,
            "recursive(5u) result 1"
        );
    }
    {
        struct w2c2_result_iii result;
        result = m12_multivalueX2E0Export7_overlap(&instance, 1u);
        assertEqualU32(
            result.v0,
            1u,
            "overlap(1u) result 0"
        );
        assertEqualU32(
            result.v1,
            2u,
            "overlap(1u) result 1"
        );
        assertEqualU32(
            result.v2,
            3u,
            "overlap(1u) result 2"
        );
    }
    {
        struct w2c2_result_iii result;
        result = m12_multivalueX2E0Export7_overlap(&instance, 0u);
        assertEqualU32(
            result.v0,
            105u,
            "overlap(0u) result 0"
        );
        assertEqualU32(
            result.v1,
            5u,
            "overlap(0u) result 1"
        );
        assertEqualU32(
            result.v2,
            6u,
            "overlap(0u) result 2"
        );
    }
    {
        struct w2c2_result_ij result;
        result = m12_multivalueX2E0Export10_loopX2Dtable(&instance);
        assertEqualU32(
            result.v0,
            0u,
            "loop-table() result 0"
        );
        assertEqualU64(
            result.v1,
            3ull,
            "loop-table() result 1"
        );
    }
    {
        struct w2c2_result_ij result;
        result = m12_multivalueX2E0Export11_nestedX2Ddead(&instance);
        assertEqualU32(
            result.v0,
            1u,
            "nested-dead() result 0"
        );
        assertEqualU64(
            result.v1,
            2ull,
            "nested-dead() result 1"
        );
    }
    m12_multivalueX2E0FreeInstance(&instance);
}
