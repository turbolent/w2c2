#ifndef W2C2_TEST_OS_BYTE_ORDER_H
#define W2C2_TEST_OS_BYTE_ORDER_H

#include <stdint.h>

/*
 * Compile-only regression for #192: Apple's PowerPC API takes uintptr_t offsets.
 * https://github.com/apple-oss-distributions/xnu/blob/xnu-1228.15.4/libkern/libkern/ppc/OSByteOrder.h
 */
typedef char require32BitOffset[sizeof(uintptr_t) == 4 ? 1 : -1];
uint16_t OSReadSwapInt16(const volatile void* base, uintptr_t byteOffset);
uint32_t OSReadSwapInt32(const volatile void* base, uintptr_t byteOffset);
uint64_t OSReadSwapInt64(const volatile void* base, uintptr_t byteOffset);
void OSWriteSwapInt16(volatile void* base, uintptr_t byteOffset, uint16_t data);
void OSWriteSwapInt32(volatile void* base, uintptr_t byteOffset, uint32_t data);
void OSWriteSwapInt64(volatile void* base, uintptr_t byteOffset, uint64_t data);

#endif /* W2C2_TEST_OS_BYTE_ORDER_H */
