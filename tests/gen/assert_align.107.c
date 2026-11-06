#include "test.h"
#include "test_align.107.h"

void test(void) {
    static m9_alignX2E107Instance instance;
    m9_alignX2E107Instantiate(&instance, resolveTestImports);
    printStart("align.107.wasm");
#if W2C2_RUNTIME_CHECKS
    assertTrap(m9_alignX2E107Export5_store(&instance, 65532u, 18446744073709551615ull), trapMemoryOutOfBounds, "store(65532u, 18446744073709551615ull)");
#endif
    assertEqualU32(
        m9_alignX2E107Export4_load(&instance, 65532u),
        0u,
        "load(65532u)"
    );
    m9_alignX2E107FreeInstance(&instance);
}
