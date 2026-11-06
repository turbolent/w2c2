#include "test.h"
#include "test_memory_trap.1.h"

void test(void) {
    static m13_memoryX5FtrapX2E1Instance instance;
    m13_memoryX5FtrapX2E1Instantiate(&instance, resolveTestImports);
    printStart("memory_trap.1.wasm");
#if W2C2_RUNTIME_CHECKS
    assertTrap(m13_memoryX5FtrapX2E1Export9_i32X2Estore(&instance, 65536u, 0u), trapMemoryOutOfBounds, "i32.store(65536u, 0u)");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m13_memoryX5FtrapX2E1Export9_i32X2Estore(&instance, 65535u, 0u), trapMemoryOutOfBounds, "i32.store(65535u, 0u)");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m13_memoryX5FtrapX2E1Export9_i32X2Estore(&instance, 65534u, 0u), trapMemoryOutOfBounds, "i32.store(65534u, 0u)");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m13_memoryX5FtrapX2E1Export9_i32X2Estore(&instance, 65533u, 0u), trapMemoryOutOfBounds, "i32.store(65533u, 0u)");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m13_memoryX5FtrapX2E1Export9_i32X2Estore(&instance, 4294967295u, 0u), trapMemoryOutOfBounds, "i32.store(4294967295u, 0u)");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m13_memoryX5FtrapX2E1Export9_i32X2Estore(&instance, 4294967294u, 0u), trapMemoryOutOfBounds, "i32.store(4294967294u, 0u)");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m13_memoryX5FtrapX2E1Export9_i32X2Estore(&instance, 4294967293u, 0u), trapMemoryOutOfBounds, "i32.store(4294967293u, 0u)");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m13_memoryX5FtrapX2E1Export9_i32X2Estore(&instance, 4294967292u, 0u), trapMemoryOutOfBounds, "i32.store(4294967292u, 0u)");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m13_memoryX5FtrapX2E1Export9_i64X2Estore(&instance, 65536u, 0ull), trapMemoryOutOfBounds, "i64.store(65536u, 0ull)");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m13_memoryX5FtrapX2E1Export9_i64X2Estore(&instance, 65535u, 0ull), trapMemoryOutOfBounds, "i64.store(65535u, 0ull)");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m13_memoryX5FtrapX2E1Export9_i64X2Estore(&instance, 65534u, 0ull), trapMemoryOutOfBounds, "i64.store(65534u, 0ull)");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m13_memoryX5FtrapX2E1Export9_i64X2Estore(&instance, 65533u, 0ull), trapMemoryOutOfBounds, "i64.store(65533u, 0ull)");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m13_memoryX5FtrapX2E1Export9_i64X2Estore(&instance, 65532u, 0ull), trapMemoryOutOfBounds, "i64.store(65532u, 0ull)");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m13_memoryX5FtrapX2E1Export9_i64X2Estore(&instance, 65531u, 0ull), trapMemoryOutOfBounds, "i64.store(65531u, 0ull)");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m13_memoryX5FtrapX2E1Export9_i64X2Estore(&instance, 65530u, 0ull), trapMemoryOutOfBounds, "i64.store(65530u, 0ull)");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m13_memoryX5FtrapX2E1Export9_i64X2Estore(&instance, 65529u, 0ull), trapMemoryOutOfBounds, "i64.store(65529u, 0ull)");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m13_memoryX5FtrapX2E1Export9_i64X2Estore(&instance, 4294967295u, 0ull), trapMemoryOutOfBounds, "i64.store(4294967295u, 0ull)");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m13_memoryX5FtrapX2E1Export9_i64X2Estore(&instance, 4294967294u, 0ull), trapMemoryOutOfBounds, "i64.store(4294967294u, 0ull)");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m13_memoryX5FtrapX2E1Export9_i64X2Estore(&instance, 4294967293u, 0ull), trapMemoryOutOfBounds, "i64.store(4294967293u, 0ull)");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m13_memoryX5FtrapX2E1Export9_i64X2Estore(&instance, 4294967292u, 0ull), trapMemoryOutOfBounds, "i64.store(4294967292u, 0ull)");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m13_memoryX5FtrapX2E1Export9_i64X2Estore(&instance, 4294967291u, 0ull), trapMemoryOutOfBounds, "i64.store(4294967291u, 0ull)");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m13_memoryX5FtrapX2E1Export9_i64X2Estore(&instance, 4294967290u, 0ull), trapMemoryOutOfBounds, "i64.store(4294967290u, 0ull)");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m13_memoryX5FtrapX2E1Export9_i64X2Estore(&instance, 4294967289u, 0ull), trapMemoryOutOfBounds, "i64.store(4294967289u, 0ull)");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m13_memoryX5FtrapX2E1Export9_i64X2Estore(&instance, 4294967288u, 0ull), trapMemoryOutOfBounds, "i64.store(4294967288u, 0ull)");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m13_memoryX5FtrapX2E1Export9_f32X2Estore(&instance, 65536u, f32_reinterpret_i32(0x00000000u)), trapMemoryOutOfBounds, "f32.store(65536u, 0.0)");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m13_memoryX5FtrapX2E1Export9_f32X2Estore(&instance, 65535u, f32_reinterpret_i32(0x00000000u)), trapMemoryOutOfBounds, "f32.store(65535u, 0.0)");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m13_memoryX5FtrapX2E1Export9_f32X2Estore(&instance, 65534u, f32_reinterpret_i32(0x00000000u)), trapMemoryOutOfBounds, "f32.store(65534u, 0.0)");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m13_memoryX5FtrapX2E1Export9_f32X2Estore(&instance, 65533u, f32_reinterpret_i32(0x00000000u)), trapMemoryOutOfBounds, "f32.store(65533u, 0.0)");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m13_memoryX5FtrapX2E1Export9_f32X2Estore(&instance, 4294967295u, f32_reinterpret_i32(0x00000000u)), trapMemoryOutOfBounds, "f32.store(4294967295u, 0.0)");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m13_memoryX5FtrapX2E1Export9_f32X2Estore(&instance, 4294967294u, f32_reinterpret_i32(0x00000000u)), trapMemoryOutOfBounds, "f32.store(4294967294u, 0.0)");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m13_memoryX5FtrapX2E1Export9_f32X2Estore(&instance, 4294967293u, f32_reinterpret_i32(0x00000000u)), trapMemoryOutOfBounds, "f32.store(4294967293u, 0.0)");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m13_memoryX5FtrapX2E1Export9_f32X2Estore(&instance, 4294967292u, f32_reinterpret_i32(0x00000000u)), trapMemoryOutOfBounds, "f32.store(4294967292u, 0.0)");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m13_memoryX5FtrapX2E1Export9_f64X2Estore(&instance, 65536u, f64_reinterpret_i64(0x0000000000000000ull)), trapMemoryOutOfBounds, "f64.store(65536u, 0.0)");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m13_memoryX5FtrapX2E1Export9_f64X2Estore(&instance, 65535u, f64_reinterpret_i64(0x0000000000000000ull)), trapMemoryOutOfBounds, "f64.store(65535u, 0.0)");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m13_memoryX5FtrapX2E1Export9_f64X2Estore(&instance, 65534u, f64_reinterpret_i64(0x0000000000000000ull)), trapMemoryOutOfBounds, "f64.store(65534u, 0.0)");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m13_memoryX5FtrapX2E1Export9_f64X2Estore(&instance, 65533u, f64_reinterpret_i64(0x0000000000000000ull)), trapMemoryOutOfBounds, "f64.store(65533u, 0.0)");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m13_memoryX5FtrapX2E1Export9_f64X2Estore(&instance, 65532u, f64_reinterpret_i64(0x0000000000000000ull)), trapMemoryOutOfBounds, "f64.store(65532u, 0.0)");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m13_memoryX5FtrapX2E1Export9_f64X2Estore(&instance, 65531u, f64_reinterpret_i64(0x0000000000000000ull)), trapMemoryOutOfBounds, "f64.store(65531u, 0.0)");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m13_memoryX5FtrapX2E1Export9_f64X2Estore(&instance, 65530u, f64_reinterpret_i64(0x0000000000000000ull)), trapMemoryOutOfBounds, "f64.store(65530u, 0.0)");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m13_memoryX5FtrapX2E1Export9_f64X2Estore(&instance, 65529u, f64_reinterpret_i64(0x0000000000000000ull)), trapMemoryOutOfBounds, "f64.store(65529u, 0.0)");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m13_memoryX5FtrapX2E1Export9_f64X2Estore(&instance, 4294967295u, f64_reinterpret_i64(0x0000000000000000ull)), trapMemoryOutOfBounds, "f64.store(4294967295u, 0.0)");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m13_memoryX5FtrapX2E1Export9_f64X2Estore(&instance, 4294967294u, f64_reinterpret_i64(0x0000000000000000ull)), trapMemoryOutOfBounds, "f64.store(4294967294u, 0.0)");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m13_memoryX5FtrapX2E1Export9_f64X2Estore(&instance, 4294967293u, f64_reinterpret_i64(0x0000000000000000ull)), trapMemoryOutOfBounds, "f64.store(4294967293u, 0.0)");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m13_memoryX5FtrapX2E1Export9_f64X2Estore(&instance, 4294967292u, f64_reinterpret_i64(0x0000000000000000ull)), trapMemoryOutOfBounds, "f64.store(4294967292u, 0.0)");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m13_memoryX5FtrapX2E1Export9_f64X2Estore(&instance, 4294967291u, f64_reinterpret_i64(0x0000000000000000ull)), trapMemoryOutOfBounds, "f64.store(4294967291u, 0.0)");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m13_memoryX5FtrapX2E1Export9_f64X2Estore(&instance, 4294967290u, f64_reinterpret_i64(0x0000000000000000ull)), trapMemoryOutOfBounds, "f64.store(4294967290u, 0.0)");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m13_memoryX5FtrapX2E1Export9_f64X2Estore(&instance, 4294967289u, f64_reinterpret_i64(0x0000000000000000ull)), trapMemoryOutOfBounds, "f64.store(4294967289u, 0.0)");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m13_memoryX5FtrapX2E1Export9_f64X2Estore(&instance, 4294967288u, f64_reinterpret_i64(0x0000000000000000ull)), trapMemoryOutOfBounds, "f64.store(4294967288u, 0.0)");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m13_memoryX5FtrapX2E1Export10_i32X2Estore8(&instance, 65536u, 0u), trapMemoryOutOfBounds, "i32.store8(65536u, 0u)");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m13_memoryX5FtrapX2E1Export10_i32X2Estore8(&instance, 4294967295u, 0u), trapMemoryOutOfBounds, "i32.store8(4294967295u, 0u)");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m13_memoryX5FtrapX2E1Export11_i32X2Estore16(&instance, 65536u, 0u), trapMemoryOutOfBounds, "i32.store16(65536u, 0u)");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m13_memoryX5FtrapX2E1Export11_i32X2Estore16(&instance, 65535u, 0u), trapMemoryOutOfBounds, "i32.store16(65535u, 0u)");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m13_memoryX5FtrapX2E1Export11_i32X2Estore16(&instance, 4294967295u, 0u), trapMemoryOutOfBounds, "i32.store16(4294967295u, 0u)");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m13_memoryX5FtrapX2E1Export11_i32X2Estore16(&instance, 4294967294u, 0u), trapMemoryOutOfBounds, "i32.store16(4294967294u, 0u)");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m13_memoryX5FtrapX2E1Export10_i64X2Estore8(&instance, 65536u, 0ull), trapMemoryOutOfBounds, "i64.store8(65536u, 0ull)");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m13_memoryX5FtrapX2E1Export10_i64X2Estore8(&instance, 4294967295u, 0ull), trapMemoryOutOfBounds, "i64.store8(4294967295u, 0ull)");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m13_memoryX5FtrapX2E1Export11_i64X2Estore16(&instance, 65536u, 0ull), trapMemoryOutOfBounds, "i64.store16(65536u, 0ull)");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m13_memoryX5FtrapX2E1Export11_i64X2Estore16(&instance, 65535u, 0ull), trapMemoryOutOfBounds, "i64.store16(65535u, 0ull)");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m13_memoryX5FtrapX2E1Export11_i64X2Estore16(&instance, 4294967295u, 0ull), trapMemoryOutOfBounds, "i64.store16(4294967295u, 0ull)");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m13_memoryX5FtrapX2E1Export11_i64X2Estore16(&instance, 4294967294u, 0ull), trapMemoryOutOfBounds, "i64.store16(4294967294u, 0ull)");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m13_memoryX5FtrapX2E1Export11_i64X2Estore32(&instance, 65536u, 0ull), trapMemoryOutOfBounds, "i64.store32(65536u, 0ull)");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m13_memoryX5FtrapX2E1Export11_i64X2Estore32(&instance, 65535u, 0ull), trapMemoryOutOfBounds, "i64.store32(65535u, 0ull)");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m13_memoryX5FtrapX2E1Export11_i64X2Estore32(&instance, 65534u, 0ull), trapMemoryOutOfBounds, "i64.store32(65534u, 0ull)");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m13_memoryX5FtrapX2E1Export11_i64X2Estore32(&instance, 65533u, 0ull), trapMemoryOutOfBounds, "i64.store32(65533u, 0ull)");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m13_memoryX5FtrapX2E1Export11_i64X2Estore32(&instance, 4294967295u, 0ull), trapMemoryOutOfBounds, "i64.store32(4294967295u, 0ull)");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m13_memoryX5FtrapX2E1Export11_i64X2Estore32(&instance, 4294967294u, 0ull), trapMemoryOutOfBounds, "i64.store32(4294967294u, 0ull)");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m13_memoryX5FtrapX2E1Export11_i64X2Estore32(&instance, 4294967293u, 0ull), trapMemoryOutOfBounds, "i64.store32(4294967293u, 0ull)");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m13_memoryX5FtrapX2E1Export11_i64X2Estore32(&instance, 4294967292u, 0ull), trapMemoryOutOfBounds, "i64.store32(4294967292u, 0ull)");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m13_memoryX5FtrapX2E1Export8_i32X2Eload(&instance, 65536u), trapMemoryOutOfBounds, "i32.load(65536u)");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m13_memoryX5FtrapX2E1Export8_i32X2Eload(&instance, 65535u), trapMemoryOutOfBounds, "i32.load(65535u)");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m13_memoryX5FtrapX2E1Export8_i32X2Eload(&instance, 65534u), trapMemoryOutOfBounds, "i32.load(65534u)");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m13_memoryX5FtrapX2E1Export8_i32X2Eload(&instance, 65533u), trapMemoryOutOfBounds, "i32.load(65533u)");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m13_memoryX5FtrapX2E1Export8_i32X2Eload(&instance, 4294967295u), trapMemoryOutOfBounds, "i32.load(4294967295u)");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m13_memoryX5FtrapX2E1Export8_i32X2Eload(&instance, 4294967294u), trapMemoryOutOfBounds, "i32.load(4294967294u)");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m13_memoryX5FtrapX2E1Export8_i32X2Eload(&instance, 4294967293u), trapMemoryOutOfBounds, "i32.load(4294967293u)");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m13_memoryX5FtrapX2E1Export8_i32X2Eload(&instance, 4294967292u), trapMemoryOutOfBounds, "i32.load(4294967292u)");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m13_memoryX5FtrapX2E1Export8_i64X2Eload(&instance, 65536u), trapMemoryOutOfBounds, "i64.load(65536u)");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m13_memoryX5FtrapX2E1Export8_i64X2Eload(&instance, 65535u), trapMemoryOutOfBounds, "i64.load(65535u)");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m13_memoryX5FtrapX2E1Export8_i64X2Eload(&instance, 65534u), trapMemoryOutOfBounds, "i64.load(65534u)");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m13_memoryX5FtrapX2E1Export8_i64X2Eload(&instance, 65533u), trapMemoryOutOfBounds, "i64.load(65533u)");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m13_memoryX5FtrapX2E1Export8_i64X2Eload(&instance, 65532u), trapMemoryOutOfBounds, "i64.load(65532u)");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m13_memoryX5FtrapX2E1Export8_i64X2Eload(&instance, 65531u), trapMemoryOutOfBounds, "i64.load(65531u)");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m13_memoryX5FtrapX2E1Export8_i64X2Eload(&instance, 65530u), trapMemoryOutOfBounds, "i64.load(65530u)");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m13_memoryX5FtrapX2E1Export8_i64X2Eload(&instance, 65529u), trapMemoryOutOfBounds, "i64.load(65529u)");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m13_memoryX5FtrapX2E1Export8_i64X2Eload(&instance, 4294967295u), trapMemoryOutOfBounds, "i64.load(4294967295u)");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m13_memoryX5FtrapX2E1Export8_i64X2Eload(&instance, 4294967294u), trapMemoryOutOfBounds, "i64.load(4294967294u)");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m13_memoryX5FtrapX2E1Export8_i64X2Eload(&instance, 4294967293u), trapMemoryOutOfBounds, "i64.load(4294967293u)");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m13_memoryX5FtrapX2E1Export8_i64X2Eload(&instance, 4294967292u), trapMemoryOutOfBounds, "i64.load(4294967292u)");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m13_memoryX5FtrapX2E1Export8_i64X2Eload(&instance, 4294967291u), trapMemoryOutOfBounds, "i64.load(4294967291u)");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m13_memoryX5FtrapX2E1Export8_i64X2Eload(&instance, 4294967290u), trapMemoryOutOfBounds, "i64.load(4294967290u)");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m13_memoryX5FtrapX2E1Export8_i64X2Eload(&instance, 4294967289u), trapMemoryOutOfBounds, "i64.load(4294967289u)");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m13_memoryX5FtrapX2E1Export8_i64X2Eload(&instance, 4294967288u), trapMemoryOutOfBounds, "i64.load(4294967288u)");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m13_memoryX5FtrapX2E1Export8_f32X2Eload(&instance, 65536u), trapMemoryOutOfBounds, "f32.load(65536u)");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m13_memoryX5FtrapX2E1Export8_f32X2Eload(&instance, 65535u), trapMemoryOutOfBounds, "f32.load(65535u)");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m13_memoryX5FtrapX2E1Export8_f32X2Eload(&instance, 65534u), trapMemoryOutOfBounds, "f32.load(65534u)");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m13_memoryX5FtrapX2E1Export8_f32X2Eload(&instance, 65533u), trapMemoryOutOfBounds, "f32.load(65533u)");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m13_memoryX5FtrapX2E1Export8_f32X2Eload(&instance, 4294967295u), trapMemoryOutOfBounds, "f32.load(4294967295u)");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m13_memoryX5FtrapX2E1Export8_f32X2Eload(&instance, 4294967294u), trapMemoryOutOfBounds, "f32.load(4294967294u)");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m13_memoryX5FtrapX2E1Export8_f32X2Eload(&instance, 4294967293u), trapMemoryOutOfBounds, "f32.load(4294967293u)");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m13_memoryX5FtrapX2E1Export8_f32X2Eload(&instance, 4294967292u), trapMemoryOutOfBounds, "f32.load(4294967292u)");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m13_memoryX5FtrapX2E1Export8_f64X2Eload(&instance, 65536u), trapMemoryOutOfBounds, "f64.load(65536u)");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m13_memoryX5FtrapX2E1Export8_f64X2Eload(&instance, 65535u), trapMemoryOutOfBounds, "f64.load(65535u)");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m13_memoryX5FtrapX2E1Export8_f64X2Eload(&instance, 65534u), trapMemoryOutOfBounds, "f64.load(65534u)");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m13_memoryX5FtrapX2E1Export8_f64X2Eload(&instance, 65533u), trapMemoryOutOfBounds, "f64.load(65533u)");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m13_memoryX5FtrapX2E1Export8_f64X2Eload(&instance, 65532u), trapMemoryOutOfBounds, "f64.load(65532u)");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m13_memoryX5FtrapX2E1Export8_f64X2Eload(&instance, 65531u), trapMemoryOutOfBounds, "f64.load(65531u)");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m13_memoryX5FtrapX2E1Export8_f64X2Eload(&instance, 65530u), trapMemoryOutOfBounds, "f64.load(65530u)");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m13_memoryX5FtrapX2E1Export8_f64X2Eload(&instance, 65529u), trapMemoryOutOfBounds, "f64.load(65529u)");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m13_memoryX5FtrapX2E1Export8_f64X2Eload(&instance, 4294967295u), trapMemoryOutOfBounds, "f64.load(4294967295u)");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m13_memoryX5FtrapX2E1Export8_f64X2Eload(&instance, 4294967294u), trapMemoryOutOfBounds, "f64.load(4294967294u)");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m13_memoryX5FtrapX2E1Export8_f64X2Eload(&instance, 4294967293u), trapMemoryOutOfBounds, "f64.load(4294967293u)");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m13_memoryX5FtrapX2E1Export8_f64X2Eload(&instance, 4294967292u), trapMemoryOutOfBounds, "f64.load(4294967292u)");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m13_memoryX5FtrapX2E1Export8_f64X2Eload(&instance, 4294967291u), trapMemoryOutOfBounds, "f64.load(4294967291u)");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m13_memoryX5FtrapX2E1Export8_f64X2Eload(&instance, 4294967290u), trapMemoryOutOfBounds, "f64.load(4294967290u)");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m13_memoryX5FtrapX2E1Export8_f64X2Eload(&instance, 4294967289u), trapMemoryOutOfBounds, "f64.load(4294967289u)");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m13_memoryX5FtrapX2E1Export8_f64X2Eload(&instance, 4294967288u), trapMemoryOutOfBounds, "f64.load(4294967288u)");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m13_memoryX5FtrapX2E1Export11_i32X2Eload8X5Fs(&instance, 65536u), trapMemoryOutOfBounds, "i32.load8_s(65536u)");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m13_memoryX5FtrapX2E1Export11_i32X2Eload8X5Fs(&instance, 4294967295u), trapMemoryOutOfBounds, "i32.load8_s(4294967295u)");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m13_memoryX5FtrapX2E1Export11_i32X2Eload8X5Fu(&instance, 65536u), trapMemoryOutOfBounds, "i32.load8_u(65536u)");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m13_memoryX5FtrapX2E1Export11_i32X2Eload8X5Fu(&instance, 4294967295u), trapMemoryOutOfBounds, "i32.load8_u(4294967295u)");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m13_memoryX5FtrapX2E1Export12_i32X2Eload16X5Fs(&instance, 65536u), trapMemoryOutOfBounds, "i32.load16_s(65536u)");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m13_memoryX5FtrapX2E1Export12_i32X2Eload16X5Fs(&instance, 65535u), trapMemoryOutOfBounds, "i32.load16_s(65535u)");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m13_memoryX5FtrapX2E1Export12_i32X2Eload16X5Fs(&instance, 4294967295u), trapMemoryOutOfBounds, "i32.load16_s(4294967295u)");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m13_memoryX5FtrapX2E1Export12_i32X2Eload16X5Fs(&instance, 4294967294u), trapMemoryOutOfBounds, "i32.load16_s(4294967294u)");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m13_memoryX5FtrapX2E1Export12_i32X2Eload16X5Fu(&instance, 65536u), trapMemoryOutOfBounds, "i32.load16_u(65536u)");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m13_memoryX5FtrapX2E1Export12_i32X2Eload16X5Fu(&instance, 65535u), trapMemoryOutOfBounds, "i32.load16_u(65535u)");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m13_memoryX5FtrapX2E1Export12_i32X2Eload16X5Fu(&instance, 4294967295u), trapMemoryOutOfBounds, "i32.load16_u(4294967295u)");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m13_memoryX5FtrapX2E1Export12_i32X2Eload16X5Fu(&instance, 4294967294u), trapMemoryOutOfBounds, "i32.load16_u(4294967294u)");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m13_memoryX5FtrapX2E1Export11_i64X2Eload8X5Fs(&instance, 65536u), trapMemoryOutOfBounds, "i64.load8_s(65536u)");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m13_memoryX5FtrapX2E1Export11_i64X2Eload8X5Fs(&instance, 4294967295u), trapMemoryOutOfBounds, "i64.load8_s(4294967295u)");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m13_memoryX5FtrapX2E1Export11_i64X2Eload8X5Fu(&instance, 65536u), trapMemoryOutOfBounds, "i64.load8_u(65536u)");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m13_memoryX5FtrapX2E1Export11_i64X2Eload8X5Fu(&instance, 4294967295u), trapMemoryOutOfBounds, "i64.load8_u(4294967295u)");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m13_memoryX5FtrapX2E1Export12_i64X2Eload16X5Fs(&instance, 65536u), trapMemoryOutOfBounds, "i64.load16_s(65536u)");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m13_memoryX5FtrapX2E1Export12_i64X2Eload16X5Fs(&instance, 65535u), trapMemoryOutOfBounds, "i64.load16_s(65535u)");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m13_memoryX5FtrapX2E1Export12_i64X2Eload16X5Fs(&instance, 4294967295u), trapMemoryOutOfBounds, "i64.load16_s(4294967295u)");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m13_memoryX5FtrapX2E1Export12_i64X2Eload16X5Fs(&instance, 4294967294u), trapMemoryOutOfBounds, "i64.load16_s(4294967294u)");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m13_memoryX5FtrapX2E1Export12_i64X2Eload16X5Fu(&instance, 65536u), trapMemoryOutOfBounds, "i64.load16_u(65536u)");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m13_memoryX5FtrapX2E1Export12_i64X2Eload16X5Fu(&instance, 65535u), trapMemoryOutOfBounds, "i64.load16_u(65535u)");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m13_memoryX5FtrapX2E1Export12_i64X2Eload16X5Fu(&instance, 4294967295u), trapMemoryOutOfBounds, "i64.load16_u(4294967295u)");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m13_memoryX5FtrapX2E1Export12_i64X2Eload16X5Fu(&instance, 4294967294u), trapMemoryOutOfBounds, "i64.load16_u(4294967294u)");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m13_memoryX5FtrapX2E1Export12_i64X2Eload32X5Fs(&instance, 65536u), trapMemoryOutOfBounds, "i64.load32_s(65536u)");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m13_memoryX5FtrapX2E1Export12_i64X2Eload32X5Fs(&instance, 65535u), trapMemoryOutOfBounds, "i64.load32_s(65535u)");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m13_memoryX5FtrapX2E1Export12_i64X2Eload32X5Fs(&instance, 65534u), trapMemoryOutOfBounds, "i64.load32_s(65534u)");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m13_memoryX5FtrapX2E1Export12_i64X2Eload32X5Fs(&instance, 65533u), trapMemoryOutOfBounds, "i64.load32_s(65533u)");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m13_memoryX5FtrapX2E1Export12_i64X2Eload32X5Fs(&instance, 4294967295u), trapMemoryOutOfBounds, "i64.load32_s(4294967295u)");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m13_memoryX5FtrapX2E1Export12_i64X2Eload32X5Fs(&instance, 4294967294u), trapMemoryOutOfBounds, "i64.load32_s(4294967294u)");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m13_memoryX5FtrapX2E1Export12_i64X2Eload32X5Fs(&instance, 4294967293u), trapMemoryOutOfBounds, "i64.load32_s(4294967293u)");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m13_memoryX5FtrapX2E1Export12_i64X2Eload32X5Fs(&instance, 4294967292u), trapMemoryOutOfBounds, "i64.load32_s(4294967292u)");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m13_memoryX5FtrapX2E1Export12_i64X2Eload32X5Fu(&instance, 65536u), trapMemoryOutOfBounds, "i64.load32_u(65536u)");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m13_memoryX5FtrapX2E1Export12_i64X2Eload32X5Fu(&instance, 65535u), trapMemoryOutOfBounds, "i64.load32_u(65535u)");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m13_memoryX5FtrapX2E1Export12_i64X2Eload32X5Fu(&instance, 65534u), trapMemoryOutOfBounds, "i64.load32_u(65534u)");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m13_memoryX5FtrapX2E1Export12_i64X2Eload32X5Fu(&instance, 65533u), trapMemoryOutOfBounds, "i64.load32_u(65533u)");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m13_memoryX5FtrapX2E1Export12_i64X2Eload32X5Fu(&instance, 4294967295u), trapMemoryOutOfBounds, "i64.load32_u(4294967295u)");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m13_memoryX5FtrapX2E1Export12_i64X2Eload32X5Fu(&instance, 4294967294u), trapMemoryOutOfBounds, "i64.load32_u(4294967294u)");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m13_memoryX5FtrapX2E1Export12_i64X2Eload32X5Fu(&instance, 4294967293u), trapMemoryOutOfBounds, "i64.load32_u(4294967293u)");
#endif
#if W2C2_RUNTIME_CHECKS
    assertTrap(m13_memoryX5FtrapX2E1Export12_i64X2Eload32X5Fu(&instance, 4294967292u), trapMemoryOutOfBounds, "i64.load32_u(4294967292u)");
#endif
    assertEqualU64(
        m13_memoryX5FtrapX2E1Export8_i64X2Eload(&instance, 65528u),
        7523094288207667809ull,
        "i64.load(65528u)"
    );
    assertEqualU64(
        m13_memoryX5FtrapX2E1Export8_i64X2Eload(&instance, 0u),
        7523094288207667809ull,
        "i64.load(0u)"
    );
    (void)(m13_memoryX5FtrapX2E1Export9_i64X2Estore(&instance, 65528u, 0ull));
#if W2C2_RUNTIME_CHECKS
    assertTrap(m13_memoryX5FtrapX2E1Export9_i32X2Estore(&instance, 65533u, 305419896u), trapMemoryOutOfBounds, "i32.store(65533u, 305419896u)");
#endif
    assertEqualU32(
        m13_memoryX5FtrapX2E1Export8_i32X2Eload(&instance, 65532u),
        0u,
        "i32.load(65532u)"
    );
#if W2C2_RUNTIME_CHECKS
    assertTrap(m13_memoryX5FtrapX2E1Export9_i64X2Estore(&instance, 65529u, 1311768467294899695ull), trapMemoryOutOfBounds, "i64.store(65529u, 1311768467294899695ull)");
#endif
    assertEqualU64(
        m13_memoryX5FtrapX2E1Export8_i64X2Eload(&instance, 65528u),
        0ull,
        "i64.load(65528u)"
    );
#if W2C2_RUNTIME_CHECKS
    assertTrap(m13_memoryX5FtrapX2E1Export9_f32X2Estore(&instance, 65533u, f32_reinterpret_i32(0x4d91a2b4u)), trapMemoryOutOfBounds, "f32.store(65533u, 305419904.0)");
#endif
    assertEqualU32(
        i32_reinterpret_f32(m13_memoryX5FtrapX2E1Export8_f32X2Eload(&instance, 65532u)),
        0u,
        "f32.load(65532u)"
    );
#if W2C2_RUNTIME_CHECKS
    assertTrap(m13_memoryX5FtrapX2E1Export9_f64X2Estore(&instance, 65529u, f64_reinterpret_i64(0x43b234567890abceull)), trapMemoryOutOfBounds, "f64.store(65529u, 1.3117684672948997e+18)");
#endif
    assertEqualU64(
        i64_reinterpret_f64(m13_memoryX5FtrapX2E1Export8_f64X2Eload(&instance, 65528u)),
        0ull,
        "f64.load(65528u)"
    );
    m13_memoryX5FtrapX2E1FreeInstance(&instance);
}
