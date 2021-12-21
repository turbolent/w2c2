#include "w2c2_base.h"

extern F32 (*f_Math_random)();

static void f1(U32 l0, U32 l1, U32 l2);

static void f2();

static U32 f3(U32 l0, U32 l1, U32 l2, U32 l3);

static void f4();

static const U8 d0[] = {
    0x7, 0x0, 0x0, 0x86, 0x42, 0x0, 0x0, 0x0, 0x0, 0x7, 0x0, 0x0, 0x86, 0x42, 0x0, 0x0, 0x80, 0x42, 0x7, 0x0, 0x0, 0x86, 0x42, 0x0, 0x0, 0x0, 0x43, 0x7, 0x0, 0x0, 0x86, 0x42, 0x0, 0x0, 0x40, 0x43, 0x7, 0x0, 0x0, 0x86, 0x42, 0x0, 0x0, 0x80, 0x43, 0x7, 0x0, 0x0, 0x86, 0x42, 0x0, 0x0, 0xa0, 0x43, 0x6, 0x0, 0x0, 0x20, 0x42, 0x0, 0x0, 0x0, 0x0, 0x6, 0x0, 0x0, 0x20, 0x42, 0x0, 0x0, 0x0, 0x43, 0x6, 0x0, 0x0, 0x20, 0x42, 0x0, 0x0, 0x80, 0x43, 0x6, 0x0, 0x0, 0x20, 0x42, 0x0, 0x0, 0xc0, 0x43, 0x0, 0x0, 0x12, 0x4b, 0x2e, 0x0, 0x4, 0x0, 0x0, 0x15, 0x4b, 0x36, 0x0, 0x4, 0x0, 0x0, 0x18, 0x4b, 0x36, 0x0, 0x4, 0x0, 0x0, 0x1b, 0x4b, 0x36, 0x0, 0x4, 0x0, 0x0, 0x1e, 0x4b, 0x2e, 0x0, 0x4, 0x0, 0x3, 0x27, 0x4b, 0x19, 0x19, 0x5, 0x1, 0x0, 0x21, 0x1e, 0xf, 0x19, 0x1, 0x2, 0x0, 0x24, 0x0, 0x43, 0x0, 0x4, 0x3, 0x0, 0x3, 0x0, 0x0, 0x0, 0x0, 0x3, 0x1, 0x6, 0x0, 0x0, 0x0, 0x0, 0x3, 0x2, 0xc, 0x0, 0x0, 0x0, 0x0, 0x3, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x6, 0x6, 0x1, 0x7, 0x1, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x9, 0x9, 0x9, 0x9, 0x0, 0x0, 0x3, 0x3, 0x0, 0x0, 0x0, 0x0, 0x0, 0x3, 0x0, 0x3, 0x0, 0x3, 0x0, 0x3, 0x0, 0x0, 0x3, 0x3, 0x0, 0x0, 0x0, 0x0, 0xb8, 0x1, 0x0, 0x70, 0x3, 0x0, 0x28, 0x5, 0x3, 0xe0, 0x6, 0x3, 0x4c, 0x8, 0x6, 0xb8, 0x9, 0x9, 0xa, 0xb, 0xc, 0x60, 0xc, 0xf, 0x58, 0xe, 0x12, 0xfa, 0xe, 0x15, 0xa, 0x13, 0x18, 0xda, 0x13, 0x1b, 0x1a, 0x15, 0x1e, 0x5c, 0x16, 0x14, 0x16, 0xab, 0x1c, 0xd, 0xab, 0xd, 0x1a, 0xac, 0x13, 0x12, 0xac, 0x1c, 0x12, 0xac, 0x9, 0x12, 0xac, 0x28, 0x1a, 0xac, 0x1a, 0x8, 0x25, 0x40, 0x5, 0xab, 0x17, 0xe, 0xac, 0x17, 0x10, 0xac, 0x3, 0x5, 0xac, 0x32, 0x8, 0xac, 0x91, 0xc5, 0x95, 0x29, 0x95, 0x88, 0x28, 0x95, 0x29, 0xd, 0x18, 0x72, 0x28, 0x81, 0x65, 0x71, 0x66, 0x42, 0x4a, 0x23, 0x19, 0x41, 0x6e, 0x7e, 0x9c, 0xab, 0xc9, 0xe7, 0x13, 0xe2, 0x32, 0xe1, 0x41, 0xe1, 0x32, 0xf2, 0x40, 0xb8, 0xaa, 0x12, 0x7, 0x3c, 0x8, 0xea, 0x85, 0xe3, 0x87, 0xc, 0xcb, 0xc3, 0xc4, 0x3, 0xc9, 0x43, 0x2, 0x61, 0x48, 0x11, 0x79, 0x91, 0x78, 0xa0, 0x78, 0x20, 0xc1, 0x78, 0x18, 0x8c, 0xa1, 0x94, 0x87, 0x8f, 0x8b, 0x7, 0x96, 0x87, 0x9d, 0x7, 0xa5, 0x7, 0x52, 0x96, 0x43, 0x9b, 0x78, 0x98, 0x90, 0x19, 0x79, 0x10, 0x9, 0x79, 0xd8, 0xd4, 0x21, 0x20, 0x40, 0x15, 0x62, 0x64, 0x42, 0x1e, 0xc4, 0xb7, 0x28, 0xe8, 0x64, 0xa1, 0x20, 0x91, 0x90, 0x90, 0x90, 0xa, 0xb, 0x82, 0xa6, 0xf0, 0xb1, 0x83, 0x32, 0x5, 0x40, 0x60, 0xe8, 0x9c, 0xa0, 0xdc, 0xdc, 0xd8, 0x48, 0x84, 0xc4, 0x44, 0xd0, 0x84, 0x84, 0xc4, 0xc4, 0x88, 0x2, 0x21, 0xa0, 0x50, 0x60, 0x2a, 0x16, 0x14, 0x26, 0x15, 0x14, 0x55, 0x7c, 0x25, 0x75, 0x63, 0x43, 0xd0, 0x8, 0x4e, 0xc, 0x8, 0x80, 0xd1, 0x30, 0x20, 0x9, 0x46, 0x63, 0x10, 0x32, 0x60, 0x44, 0x41, 0x42, 0x42, 0xe0, 0xb, 0x0, 0x4, 0x15, 0x30, 0xc7, 0xc1, 0x55, 0x41, 0x51, 0x22, 0x31, 0x21, 0xd2, 0x24, 0x31, 0x21, 0x44, 0x52, 0x64, 0x21, 0x24, 0x36, 0x85, 0x24, 0x36, 0x57, 0x25, 0x36, 0x37, 0x67, 0xa8, 0x0, 0x4, 0x86, 0x41, 0x50, 0x10, 0x20, 0x7, 0x8c, 0xa, 0xa3, 0x12, 0x21, 0x2a, 0x36, 0x36, 0x29, 0xf, 0x2a, 0x4a, 0x19, 0x4d, 0x49, 0x38, 0x6c, 0x58, 0x2c, 0x70, 0x82, 0x92, 0x70, 0x42, 0x4a, 0xd1, 0x38, 0x54, 0xc, 0x89, 0x90, 0xe3, 0x30, 0x90, 0x12, 0xc7, 0x87, 0x10, 0x12, 0xe6, 0x68, 0x14, 0x6a, 0x42, 0xd0, 0x91, 0x28, 0xc, 0xc9, 0x9c, 0x83, 0x21, 0x20, 0x73, 0x28, 0x18, 0x21, 0x21, 0x21, 0x43, 0x22, 0xc1, 0x90, 0x5, 0x1, 0x63, 0xc5, 0xa1, 0x28, 0x1c, 0x59, 0x99, 0xa, 0x41, 0x48, 0xb2, 0x62, 0x28, 0x8, 0x38, 0x81, 0x8, 0xc3, 0x42, 0x8c, 0x28, 0x9, 0x87, 0xc4, 0x10, 0xa1, 0xd4, 0xdb, 0x3, 0x49, 0xc5, 0x83, 0xc4, 0xc9, 0x8b, 0x85, 0xc, 0x92, 0x4b, 0xc5, 0x43, 0x5, 0xc5, 0x83, 0x49, 0xc4, 0x3c, 0x8, 0x10, 0x81, 0x4c, 0x20, 0x18, 0x15, 0xf, 0x1b, 0xf, 0x1f, 0x2a, 0x1f, 0x45, 0x71, 0x84, 0x23, 0xe3, 0x21, 0xe5, 0xc1, 0xe6, 0xa1, 0xe8, 0x21, 0x44, 0xc8, 0x47, 0x8a, 0x2b, 0x4c, 0x2d, 0xe, 0xdf, 0xd5, 0x1f, 0x2, 0x99, 0x7b, 0xf3, 0x2f, 0xe5, 0xa1, 0xe6, 0x81, 0xea, 0x41, 0xec, 0x21, 0x40, 0x9, 0xe0, 0x7a, 0x2e, 0x6b, 0xd3, 0x3, 0xcd, 0x43, 0xc9, 0x83, 0xc9, 0x83, 0x85, 0x53, 0x48, 0x48, 0x98, 0x84, 0x84, 0x44, 0x98, 0x94, 0x98, 0x90, 0x54, 0x48, 0x90, 0x84, 0x94, 0x8c, 0xa0, 0x50, 0x1c, 0xc8, 0x20, 0x92, 0x8a, 0xa, 0xc, 0x92, 0x90, 0x8, 0x9a, 0x19, 0x11, 0x11, 0x9a, 0x11, 0x9, 0x9, 0xa, 0xa, 0x3, 0x1d, 0x4, 0x15, 0x12, 0x83, 0xe0, 0x24, 0x67, 0x20, 0x60, 0x8, 0xd, 0xf, 0x87, 0x90, 0x91, 0xa0, 0x12, 0x19, 0x6, 0x12, 0x24, 0x3a, 0x0, 0x80, 0x6, 0x82, 0xc4, 0x84, 0x86, 0x2, 0x40, 0x22, 0x0, 0x82, 0x3, 0x83, 0x24, 0x24, 0x2a, 0x64, 0x24, 0x10, 0xb3, 0x38, 0x90, 0x94, 0x8c, 0x90, 0xef, 0xd1, 0x90, 0xa0, 0x19, 0x8a, 0xa1, 0x90, 0x10, 0x0, 0x0, 0x0, 
};

static const U8 d1[] = {
    0x9, 0x0, 0x0, 0x48, 0x42, 0x0, 0x0, 0xb0, 0x41, 0x1, 0x0, 0x0, 0x5c, 0x42, 0x0, 0x0, 0x96, 0x43, 0x1, 0x0, 0x0, 0x5c, 0x42, 0x0, 0x0, 0x16, 0x44, 0x1, 0x0, 0x0, 0x5c, 0x42, 0x0, 0x0, 0x61, 0x44, 0xff, 
};

static wasmMemory m0;

static void initMemories(void) {
    wasmAllocateMemory(&m0, 2, 65535);
    LOAD_DATA(m0, 40u, d0, 790);
    LOAD_DATA(m0, 20443u, d1, 37);
}

static void initTables(void) {
}

static F32 g0;

static F32 g1;

static U32 g2;

static U32 g3;

static U32 g4;

static F32 g5;

static F32 g6;

static void initGlobals(void) {
    g0 = 0;
    g1 = 50;
    g2 = 0u;
    g3 = 0u;
    g4 = 0u;
    g5 = 0;
    g6 = -0.5;
}

wasmMemory (*e_mem);

void (*e_run)();

static void initExports(void) {
    e_mem = &m0;
    e_run = &f4;
}

static void f1(U32 l0, U32 l1, U32 l2) {
    U32 si0;
    U32 si1;
    L1:;
    {
        si0 = l0;
        si1 = l1;
        si1 = i32_load8_u(&m0, (U64)(si1));
        i32_store8(&m0, (U64)(si0), si1);
        si0 = l1;
        si1 = 1u;
        si0 += si1;
        l1 = si0;
        si0 = l0;
        si1 = 1u;
        si0 += si1;
        l0 = si0;
        si1 = l2;
        si0 = si0 < si1;
        if (si0) {
            goto L1;
        }
    }
    L0:;
}

static void f2() {
    U32 l0 = 0;
    U32 l1 = 0;
    U32 l2 = 0;
    U32 l3 = 0;
    U32 l4 = 0;
    U32 l5 = 0;
    U32 l6 = 0;
    U32 l7 = 0;
    U32 l8 = 0;
    U32 l9 = 0;
    U32 l10 = 0;
    U32 l11 = 0;
    U32 si0;
    U32 si1;
    U32 si2;
    U32 si3;
    si0 = 7u;
    l2 = si0;
    si0 = 827u;
    l7 = si0;
    L1:;
    {
        si0 = l1;
        si1 = 16u;
        si0 = si0 < si1;
        if (si0) {
            si0 = l0;
            si1 = l6;
            si1 = i32_load16_u(&m0, (U64)(si1) + 336u);
            si2 = l1;
            si1 <<= (si2 & 31);
            si0 |= si1;
            l0 = si0;
            si0 = l1;
            si1 = 16u;
            si0 += si1;
            l1 = si0;
            si0 = l6;
            si1 = 2u;
            si0 += si1;
            l6 = si0;
        }
        L2:;
        si0 = l0;
        si1 = 1u;
        si2 = l2;
        si1 <<= (si2 & 31);
        si2 = 1u;
        si1 -= si2;
        si0 &= si1;
        l3 = si0;
        si0 = l0;
        si1 = l2;
        si0 >>= (si1 & 31);
        l0 = si0;
        si0 = l1;
        si1 = l2;
        si0 -= si1;
        l1 = si0;
        {
            {
                {
                    {
                        {
                            si0 = l9;
                            switch (si0) {
                            case 0:
                                goto L7;
                            case 1:
                                goto L6;
                            case 2:
                                goto L3;
                            default:
                                goto L4;
                            }
                        }
                        L7:;
                        si0 = l3;
                        l4 = si0;
                        si0 = !(si0);
                        if (si0) {
                            goto L5;
                        }
                        si0 = 1u;
                        l9 = si0;
                        si0 = 4u;
                        l2 = si0;
                        goto L1;
                    }
                    L6:;
                    si0 = l7;
                    si1 = l3;
                    i32_store8(&m0, (U64)(si0), si1);
                    si0 = l7;
                    si1 = 1u;
                    si0 += si1;
                    l7 = si0;
                    si0 = l4;
                    si1 = 1u;
                    si0 -= si1;
                    l4 = si0;
                    if (si0) {
                        goto L1;
                    }
                }
                L5:;
                si0 = 2u;
                l9 = si0;
                si0 = 7u;
                l2 = si0;
                goto L1;
            }
            L4:;
            si0 = l7;
            si1 = l7;
            si2 = l5;
            si1 -= si2;
            si2 = l7;
            si3 = l3;
            si2 += si3;
            l7 = si2;
            f1(si0, si1, si2);
            si0 = 0u;
            l9 = si0;
            goto L1;
        }
        L3:;
        si0 = l3;
        l5 = si0;
        si0 = 3u;
        l9 = si0;
        si0 = l6;
        si1 = 494u;
        si0 = si0 < si1;
        if (si0) {
            goto L1;
        }
    }
    L8:;
    {
        si0 = l6;
        si0 = i32_load8_u(&m0, (U64)(si0) + 333u);
        l10 = si0;
        if (si0) {
            si0 = l7;
            si1 = l11;
            i32_store8(&m0, (U64)(si0), si1);
            si0 = l7;
            si1 = 1u;
            si0 += si1;
            si1 = l7;
            si2 = l7;
            si3 = l10;
            si2 += si3;
            l7 = si2;
            f1(si0, si1, si2);
        }
        L9:;
        si0 = l11;
        si0 = !(si0);
        l11 = si0;
        si0 = l6;
        si1 = 1u;
        si0 += si1;
        l6 = si0;
        si1 = 1984u;
        si0 = si0 < si1;
        if (si0) {
            goto L8;
        }
    }
    L0:;
}

static U32 f3(U32 l0, U32 l1, U32 l2, U32 l3) {
    U32 l4 = 0;
    U32 l5 = 0;
    U32 l6 = 0;
    U32 l7 = 0;
    U32 l8 = 0;
    U32 l9 = 0;
    U32 l10 = 0;
    U32 l11 = 0;
    U32 si0;
    U32 si1;
    U32 si2;
    si0 = l2;
    si0 = i32_load8_u(&m0, (U64)(si0) + 297u);
    l4 = si0;
    l9 = si0;
    si0 = l2;
    si0 = i32_load8_u(&m0, (U64)(si0) + 298u);
    l5 = si0;
    si0 = l2;
    si0 = i32_load8_u(&m0, (U64)(si0) + 299u);
    si1 = 24u;
    si0 <<= (si1 & 31);
    l6 = si0;
    si0 = l0;
    si1 = 0u;
    si0 = (U32)((I32)si0 < (I32)si1);
    if (si0) {
        si0 = l4;
        si1 = l0;
        si0 += si1;
        l4 = si0;
        si0 = l3;
        si1 = l0;
        si0 -= si1;
        l3 = si0;
        si0 = 0u;
        l0 = si0;
    } else {
        si0 = l0;
        si1 = l4;
        si0 += si1;
        si1 = 300u;
        si0 = (U32)((I32)si0 > (I32)si1);
        if (si0) {
            si0 = 300u;
            si1 = l0;
            si0 -= si1;
            l4 = si0;
        }
        L2:;
    }
    L1:;
    si0 = l4;
    si1 = 0u;
    si0 = (U32)((I32)si0 > (I32)si1);
    if (si0) {
        si0 = l1;
        si1 = 300u;
        si0 *= si1;
        si1 = l0;
        si0 += si1;
        l7 = si0;
        L4:;
        {
            si0 = 0u;
            l10 = si0;
            L5:;
            {
                si0 = l3;
                si1 = l10;
                si0 += si1;
                si0 = i32_load8_u(&m0, (U64)(si0) + 2317u);
                if (si0) {
                    si0 = l11;
                    si1 = l7;
                    si2 = l10;
                    si1 += si2;
                    si2 = 2u;
                    si1 <<= (si2 & 31);
                    l8 = si1;
                    si1 = i32_load8_u(&m0, (U64)(si1) + 20483u);
                    si2 = 172u;
                    si1 = si1 == si2;
                    si0 |= si1;
                    l11 = si0;
                    si0 = l8;
                    si1 = l6;
                    i32_store(&m0, (U64)(si0) + 20480u, si1);
                }
                L6:;
                si0 = l10;
                si1 = 1u;
                si0 += si1;
                l10 = si0;
                si1 = l4;
                si0 = (U32)((I32)si0 < (I32)si1);
                if (si0) {
                    goto L5;
                }
            }
            si0 = l7;
            si1 = 300u;
            si0 += si1;
            l7 = si0;
            si0 = l3;
            si1 = l9;
            si0 += si1;
            l3 = si0;
            si0 = l5;
            si1 = 1u;
            si0 -= si1;
            l5 = si0;
            if (si0) {
                goto L4;
            }
        }
    }
    L3:;
    si0 = l11;
    L0:;
    return si0;
}

static void f4() {
    U32 l0 = 0;
    U32 l1 = 0;
    U32 l2 = 0;
    U32 l3 = 0;
    U32 l4 = 0;
    U32 l5 = 0;
    U32 l6 = 0;
    U32 l7 = 0;
    U32 l8 = 0;
    U32 l9 = 0;
    F32 l10 = 0;
    F32 l11 = 0;
    U32 si0;
    F32 sf0;
    U32 si1;
    F32 sf1;
    U32 si2;
    F32 sf2;
    U32 si3;
    F32 sf3;
    U32 si4;
    U32 si5;
    si0 = 20480u;
    si1 = 20479u;
    si2 = 110480u;
    f1(si0, si1, si2);
    si0 = g2;
    si1 = 1u;
    si0 += si1;
    g2 = si0;
    sf0 = g6;
    sf1 = 0.001953125;
    sf0 -= sf1;
    sf1 = -1;
    sf0 = FMAX(sf0, sf1);
    g6 = sf0;
    si0 = 0u;
    si0 = i32_load8_u(&m0, (U64)(si0));
    l0 = si0;
    si0 = 5u;
    sf0 = f32_load(&m0, (U64)(si0));
    l11 = sf0;
    {
        {
            {
                {
                    {
                        {
                            {
                                si0 = g4;
                                switch (si0) {
                                case 0:
                                    goto L6;
                                case 1:
                                    goto L5;
                                case 2:
                                    goto L4;
                                case 3:
                                    goto L3;
                                default:
                                    goto L7;
                                }
                            }
                            L7:;
                            si0 = 11u;
                            l1 = si0;
                            sf0 = g0;
                            g6 = sf0;
                            si0 = l0;
                            si0 = !(si0);
                            si1 = g2;
                            si2 = g3;
                            si1 -= si2;
                            si2 = 20u;
                            si1 = si1 <= si2;
                            si0 |= si1;
                            if (si0) {
                                goto L1;
                            }
                            si0 = 0u;
                            g3 = si0;
                            si0 = 0u;
                            g2 = si0;
                            sf0 = g0;
                            g5 = sf0;
                            sf0 = -0.5;
                            g6 = sf0;
                        }
                        L6:;
                        si0 = 9u;
                        l1 = si0;
                        sf0 = g1;
                        l11 = sf0;
                        si0 = 4u;
                        si1 = 20443u;
                        si2 = 40u;
                        f1(si0, si1, si2);
                        si0 = 1u;
                        g4 = si0;
                    }
                    L5:;
                    si0 = l0;
                    si1 = 2u;
                    si0 = si0 == si1;
                    si1 = 9u;
                    si0 += si1;
                    l1 = si0;
                    si0 = l0;
                    si1 = 1u;
                    si0 = si0 != si1;
                    if (si0) {
                        goto L2;
                    }
                    si0 = 2u;
                    g4 = si0;
                    sf0 = -6;
                    g5 = sf0;
                }
                L4:;
                si0 = l0;
                si1 = 1u;
                si0 = si0 == si1;
                sf1 = l11;
                sf2 = 30;
                si1 = sf1 >= sf2;
                si0 |= si1;
                sf1 = l11;
                sf2 = 10;
                si1 = sf1 >= sf2;
                si0 &= si1;
                if (si0) {
                    goto L3;
                }
                si0 = 3u;
                g4 = si0;
                sf0 = -1;
                g5 = sf0;
            }
            L3:;
            si0 = 8u;
            l1 = si0;
            sf0 = l11;
            sf1 = g5;
            sf0 += sf1;
            l11 = sf0;
            sf0 = g5;
            sf1 = 0.400000006;
            sf0 += sf1;
            g5 = sf0;
            sf0 = l11;
            sf1 = g1;
            si0 = sf0 <= sf1;
            if (si0) {
                goto L2;
            }
            si0 = 1u;
            g4 = si0;
            sf0 = g1;
            l11 = sf0;
            sf0 = g0;
            g5 = sf0;
        }
        L2:;
        si0 = g3;
        si1 = 1u;
        si0 += si1;
        g3 = si0;
    }
    L1:;
    si0 = 4u;
    si1 = l1;
    i32_store8(&m0, (U64)(si0), si1);
    si0 = 5u;
    sf1 = l11;
    f32_store(&m0, (U64)(si0), sf1);
    si0 = 121u;
    l2 = si0;
    L8:;
    {
        si0 = l2;
        sf0 = f32_load(&m0, (U64)(si0) + 5u);
        si0 = I32_TRUNC_S_F32(sf0);
        si1 = l2;
        sf1 = f32_load(&m0, (U64)(si1) + 1u);
        si1 = I32_TRUNC_S_F32(sf1);
        si2 = l2;
        si2 = i32_load8_u(&m0, (U64)(si2));
        si3 = 7u;
        si2 *= si3;
        l6 = si2;
        si2 = i32_load8_u(&m0, (U64)(si2) + 131u);
        si3 = 2u;
        si2 <<= (si3 & 31);
        si3 = g2;
        si4 = 15u;
        si3 &= si4;
        si4 = 2u;
        si3 >>= (si4 & 31);
        si2 += si3;
        l4 = si2;
        si2 = i32_load8_u(&m0, (U64)(si2) + 220u);
        si1 += si2;
        si2 = l6;
        si2 = i32_load8_u(&m0, (U64)(si2) + 132u);
        si3 = l4;
        si3 = i32_load8_u(&m0, (U64)(si3) + 236u);
        si2 += si3;
        l5 = si2;
        si2 = i32_load8_u(&m0, (U64)(si2) + 252u);
        si3 = l5;
        si3 = i32_load16_u(&m0, (U64)(si3) + 253u);
        si0 = f3(si0, si1, si2, si3);
        si1 = l2;
        si2 = 4u;
        si1 = si1 == si2;
        si0 &= si1;
        if (si0) {
            si0 = 4u;
            g4 = si0;
        }
        L9:;
        si0 = l2;
        sf0 = f32_load(&m0, (U64)(si0) + 5u);
        si1 = l6;
        si1 = i32_load8_u(&m0, (U64)(si1) + 136u);
        sf1 = (F32)(si1);
        sf2 = g6;
        sf1 *= sf2;
        sf0 += sf1;
        l10 = sf0;
        sf1 = -64;
        si0 = sf0 < sf1;
        if (si0) {
            si0 = l2;
            sf1 = (*f_Math_random)();
            si2 = l6;
            si2 = i32_load8_u(&m0, (U64)(si2) + 130u);
            si3 = 1u;
            si2 <<= (si3 & 31);
            l7 = si2;
            si2 = i32_load8_u(&m0, (U64)(si2) + 215u);
            sf2 = (F32)(si2);
            sf1 *= sf2;
            si1 = I32_TRUNC_S_F32(sf1);
            si2 = l7;
            si2 = i32_load8_u(&m0, (U64)(si2) + 214u);
            si1 += si2;
            l3 = si1;
            i32_store8(&m0, (U64)(si0), si1);
            sf0 = l10;
            sf1 = 384;
            sf0 += sf1;
            si1 = l3;
            si2 = 7u;
            si1 *= si2;
            l6 = si1;
            si1 = i32_load8_u(&m0, (U64)(si1) + 133u);
            si2 = 3u;
            si1 <<= (si2 & 31);
            sf1 = (F32)(si1);
            sf0 += sf1;
            l10 = sf0;
            si0 = l2;
            si1 = l6;
            si1 = i32_load8_u(&m0, (U64)(si1) + 134u);
            sf1 = (F32)(si1);
            sf2 = (*f_Math_random)();
            si3 = l6;
            si3 = i32_load8_u(&m0, (U64)(si3) + 135u);
            sf3 = (F32)(si3);
            sf2 *= sf3;
            sf1 += sf2;
            f32_store(&m0, (U64)(si0) + 1u, sf1);
        }
        L10:;
        si0 = l2;
        sf1 = l10;
        f32_store(&m0, (U64)(si0) + 5u, sf1);
        si0 = l2;
        si1 = 9u;
        si0 -= si1;
        l2 = si0;
        si1 = 0u;
        si0 = (U32)((I32)si0 > (I32)si1);
        if (si0) {
            goto L8;
        }
    }
    si0 = g3;
    l9 = si0;
    si0 = 300u;
    l8 = si0;
    L11:;
    {
        si0 = l8;
        si1 = 4u;
        si0 -= si1;
        l8 = si0;
        si1 = 4u;
        si2 = 33u;
        si3 = 6092u;
        si4 = l9;
        si5 = 10u;
        si4 = REM_U(si4, si5);
        si5 = 15u;
        si4 *= si5;
        si3 += si4;
        si0 = f3(si0, si1, si2, si3);
        si0 = l9;
        si1 = 10u;
        si0 = DIV_U(si0, si1);
        l9 = si0;
        if (si0) {
            goto L11;
        }
    }
    si0 = g4;
    si1 = 4u;
    si0 = si0 == si1;
    if (si0) {
        si0 = 125u;
        si1 = 33u;
        si2 = 36u;
        si3 = 6242u;
        si0 = f3(si0, si1, si2, si3);
    }
    L12:;
    L0:;
}

void init(void) {
    initMemories();
    initTables();
    initGlobals();
    initExports();
    f2();
}
