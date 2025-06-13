
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_atomic.0.h"

void test() {
    atomic0Instance instance;
    atomic0Instantiate(&instance, resolveTestImports);
    printStart("atomic.0.wasm");
    atomic0_init(&instance, 506097522914230528ull);
    printOK("init(506097522914230528ull)");
    assertEqualU32(
        atomic0_i32X2EatomicX2Eload(&instance, 0u),
        50462976u,
        "i32.atomic.load(0u)"
    );
    assertEqualU32(
        atomic0_i32X2EatomicX2Eload(&instance, 4u),
        117835012u,
        "i32.atomic.load(4u)"
    );
    assertEqualU64(
        atomic0_i64X2EatomicX2Eload(&instance, 0u),
        506097522914230528ull,
        "i64.atomic.load(0u)"
    );
    assertEqualU32(
        atomic0_i32X2EatomicX2Eload8_u(&instance, 0u),
        0u,
        "i32.atomic.load8_u(0u)"
    );
    assertEqualU32(
        atomic0_i32X2EatomicX2Eload8_u(&instance, 5u),
        5u,
        "i32.atomic.load8_u(5u)"
    );
    assertEqualU32(
        atomic0_i32X2EatomicX2Eload16_u(&instance, 0u),
        256u,
        "i32.atomic.load16_u(0u)"
    );
    assertEqualU32(
        atomic0_i32X2EatomicX2Eload16_u(&instance, 6u),
        1798u,
        "i32.atomic.load16_u(6u)"
    );
    assertEqualU64(
        atomic0_i64X2EatomicX2Eload8_u(&instance, 0u),
        0ull,
        "i64.atomic.load8_u(0u)"
    );
    assertEqualU64(
        atomic0_i64X2EatomicX2Eload8_u(&instance, 5u),
        5ull,
        "i64.atomic.load8_u(5u)"
    );
    assertEqualU64(
        atomic0_i64X2EatomicX2Eload16_u(&instance, 0u),
        256ull,
        "i64.atomic.load16_u(0u)"
    );
    assertEqualU64(
        atomic0_i64X2EatomicX2Eload16_u(&instance, 6u),
        1798ull,
        "i64.atomic.load16_u(6u)"
    );
    assertEqualU64(
        atomic0_i64X2EatomicX2Eload32_u(&instance, 0u),
        50462976ull,
        "i64.atomic.load32_u(0u)"
    );
    assertEqualU64(
        atomic0_i64X2EatomicX2Eload32_u(&instance, 4u),
        117835012ull,
        "i64.atomic.load32_u(4u)"
    );
    atomic0_init(&instance, 0ull);
    printOK("init(0ull)");
    atomic0_i32X2EatomicX2Estore(&instance, 0u, 4293844428u);
    assertEqualU64(
        atomic0_i64X2EatomicX2Eload(&instance, 0u),
        4293844428ull,
        "i64.atomic.load(0u)"
    );
    atomic0_i64X2EatomicX2Estore(&instance, 0u, 81985529216486895ull);
    assertEqualU64(
        atomic0_i64X2EatomicX2Eload(&instance, 0u),
        81985529216486895ull,
        "i64.atomic.load(0u)"
    );
    atomic0_i32X2EatomicX2Estore8(&instance, 1u, 66u);
    assertEqualU64(
        atomic0_i64X2EatomicX2Eload(&instance, 0u),
        81985529216451311ull,
        "i64.atomic.load(0u)"
    );
    atomic0_i32X2EatomicX2Estore16(&instance, 4u, 34884u);
    assertEqualU64(
        atomic0_i64X2EatomicX2Eload(&instance, 0u),
        82059046171656943ull,
        "i64.atomic.load(0u)"
    );
    atomic0_i64X2EatomicX2Estore8(&instance, 1u, 153ull);
    assertEqualU64(
        atomic0_i64X2EatomicX2Eload(&instance, 0u),
        82059046171679215ull,
        "i64.atomic.load(0u)"
    );
    atomic0_i64X2EatomicX2Estore16(&instance, 4u, 51966ull);
    assertEqualU64(
        atomic0_i64X2EatomicX2Eload(&instance, 0u),
        82132412803029487ull,
        "i64.atomic.load(0u)"
    );
    atomic0_i64X2EatomicX2Estore32(&instance, 4u, 3735928559ull);
    assertEqualU64(
        atomic0_i64X2EatomicX2Eload(&instance, 0u),
        16045690983407131119ull,
        "i64.atomic.load(0u)"
    );
    atomic0_init(&instance, 1229782938247303441ull);
    printOK("init(1229782938247303441ull)");
    assertEqualU32(
        atomic0_i32X2EatomicX2ErmwX2Eadd(&instance, 0u, 305419896u),
        286331153u,
        "i32.atomic.rmw.add(0u, 305419896u)"
    );
    assertEqualU64(
        atomic0_i64X2EatomicX2Eload(&instance, 0u),
        1229782938552723337ull,
        "i64.atomic.load(0u)"
    );
    atomic0_init(&instance, 1229782938247303441ull);
    printOK("init(1229782938247303441ull)");
    assertEqualU64(
        atomic0_i64X2EatomicX2ErmwX2Eadd(&instance, 0u, 72340172854919682ull),
        1229782938247303441ull,
        "i64.atomic.rmw.add(0u, 72340172854919682ull)"
    );
    assertEqualU64(
        atomic0_i64X2EatomicX2Eload(&instance, 0u),
        1302123111102223123ull,
        "i64.atomic.load(0u)"
    );
    atomic0_init(&instance, 1229782938247303441ull);
    printOK("init(1229782938247303441ull)");
    assertEqualU32(
        atomic0_i32X2EatomicX2Ermw8X2Eadd_u(&instance, 0u, 3452816845u),
        17u,
        "i32.atomic.rmw8.add_u(0u, 3452816845u)"
    );
    assertEqualU64(
        atomic0_i64X2EatomicX2Eload(&instance, 0u),
        1229782938247303646ull,
        "i64.atomic.load(0u)"
    );
    atomic0_init(&instance, 1229782938247303441ull);
    printOK("init(1229782938247303441ull)");
    assertEqualU32(
        atomic0_i32X2EatomicX2Ermw16X2Eadd_u(&instance, 0u, 3405695742u),
        4369u,
        "i32.atomic.rmw16.add_u(0u, 3405695742u)"
    );
    assertEqualU64(
        atomic0_i64X2EatomicX2Eload(&instance, 0u),
        1229782938247355407ull,
        "i64.atomic.load(0u)"
    );
    atomic0_init(&instance, 1229782938247303441ull);
    printOK("init(1229782938247303441ull)");
    assertEqualU64(
        atomic0_i64X2EatomicX2Ermw8X2Eadd_u(&instance, 0u, 4774451407313060418ull),
        17ull,
        "i64.atomic.rmw8.add_u(0u, 4774451407313060418ull)"
    );
    assertEqualU64(
        atomic0_i64X2EatomicX2Eload(&instance, 0u),
        1229782938247303507ull,
        "i64.atomic.load(0u)"
    );
    atomic0_init(&instance, 1229782938247303441ull);
    printOK("init(1229782938247303441ull)");
    assertEqualU64(
        atomic0_i64X2EatomicX2Ermw16X2Eadd_u(&instance, 0u, 13758425323549998831ull),
        4369ull,
        "i64.atomic.rmw16.add_u(0u, 13758425323549998831ull)"
    );
    assertEqualU64(
        atomic0_i64X2EatomicX2Eload(&instance, 0u),
        1229782938247352320ull,
        "i64.atomic.load(0u)"
    );
    atomic0_init(&instance, 1229782938247303441ull);
    printOK("init(1229782938247303441ull)");
    assertEqualU64(
        atomic0_i64X2EatomicX2Ermw32X2Eadd_u(&instance, 0u, 14608453322185352933ull),
        286331153ull,
        "i64.atomic.rmw32.add_u(0u, 14608453322185352933ull)"
    );
    assertEqualU64(
        atomic0_i64X2EatomicX2Eload(&instance, 0u),
        1229782941648599030ull,
        "i64.atomic.load(0u)"
    );
    atomic0_init(&instance, 1229782938247303441ull);
    printOK("init(1229782938247303441ull)");
    assertEqualU32(
        atomic0_i32X2EatomicX2ErmwX2Esub(&instance, 0u, 305419896u),
        286331153u,
        "i32.atomic.rmw.sub(0u, 305419896u)"
    );
    assertEqualU64(
        atomic0_i64X2EatomicX2Eload(&instance, 0u),
        1229782942236850841ull,
        "i64.atomic.load(0u)"
    );
    atomic0_init(&instance, 1229782938247303441ull);
    printOK("init(1229782938247303441ull)");
    assertEqualU64(
        atomic0_i64X2EatomicX2ErmwX2Esub(&instance, 0u, 72340172854919682ull),
        1229782938247303441ull,
        "i64.atomic.rmw.sub(0u, 72340172854919682ull)"
    );
    assertEqualU64(
        atomic0_i64X2EatomicX2Eload(&instance, 0u),
        1157442765392383759ull,
        "i64.atomic.load(0u)"
    );
    atomic0_init(&instance, 1229782938247303441ull);
    printOK("init(1229782938247303441ull)");
    assertEqualU32(
        atomic0_i32X2EatomicX2Ermw8X2Esub_u(&instance, 0u, 3452816845u),
        17u,
        "i32.atomic.rmw8.sub_u(0u, 3452816845u)"
    );
    assertEqualU64(
        atomic0_i64X2EatomicX2Eload(&instance, 0u),
        1229782938247303492ull,
        "i64.atomic.load(0u)"
    );
    atomic0_init(&instance, 1229782938247303441ull);
    printOK("init(1229782938247303441ull)");
    assertEqualU32(
        atomic0_i32X2EatomicX2Ermw16X2Esub_u(&instance, 0u, 3405695742u),
        4369u,
        "i32.atomic.rmw16.sub_u(0u, 3405695742u)"
    );
    assertEqualU64(
        atomic0_i64X2EatomicX2Eload(&instance, 0u),
        1229782938247317011ull,
        "i64.atomic.load(0u)"
    );
    atomic0_init(&instance, 1229782938247303441ull);
    printOK("init(1229782938247303441ull)");
    assertEqualU64(
        atomic0_i64X2EatomicX2Ermw8X2Esub_u(&instance, 0u, 4774451407313060418ull),
        17ull,
        "i64.atomic.rmw8.sub_u(0u, 4774451407313060418ull)"
    );
    assertEqualU64(
        atomic0_i64X2EatomicX2Eload(&instance, 0u),
        1229782938247303631ull,
        "i64.atomic.load(0u)"
    );
    atomic0_init(&instance, 1229782938247303441ull);
    printOK("init(1229782938247303441ull)");
    assertEqualU64(
        atomic0_i64X2EatomicX2Ermw16X2Esub_u(&instance, 0u, 13758425323549998831ull),
        4369ull,
        "i64.atomic.rmw16.sub_u(0u, 13758425323549998831ull)"
    );
    assertEqualU64(
        atomic0_i64X2EatomicX2Eload(&instance, 0u),
        1229782938247320098ull,
        "i64.atomic.load(0u)"
    );
    atomic0_init(&instance, 1229782938247303441ull);
    printOK("init(1229782938247303441ull)");
    assertEqualU64(
        atomic0_i64X2EatomicX2Ermw32X2Esub_u(&instance, 0u, 14608453322185352933ull),
        286331153ull,
        "i64.atomic.rmw32.sub_u(0u, 14608453322185352933ull)"
    );
    assertEqualU64(
        atomic0_i64X2EatomicX2Eload(&instance, 0u),
        1229782939140975148ull,
        "i64.atomic.load(0u)"
    );
    atomic0_init(&instance, 1229782938247303441ull);
    printOK("init(1229782938247303441ull)");
    assertEqualU32(
        atomic0_i32X2EatomicX2ErmwX2Eand(&instance, 0u, 305419896u),
        286331153u,
        "i32.atomic.rmw.and(0u, 305419896u)"
    );
    assertEqualU64(
        atomic0_i64X2EatomicX2Eload(&instance, 0u),
        1229782938230460432ull,
        "i64.atomic.load(0u)"
    );
    atomic0_init(&instance, 1229782938247303441ull);
    printOK("init(1229782938247303441ull)");
    assertEqualU64(
        atomic0_i64X2EatomicX2ErmwX2Eand(&instance, 0u, 72340172854919682ull),
        1229782938247303441ull,
        "i64.atomic.rmw.and(0u, 72340172854919682ull)"
    );
    assertEqualU64(
        atomic0_i64X2EatomicX2Eload(&instance, 0u),
        72340172821233664ull,
        "i64.atomic.load(0u)"
    );
    atomic0_init(&instance, 1229782938247303441ull);
    printOK("init(1229782938247303441ull)");
    assertEqualU32(
        atomic0_i32X2EatomicX2Ermw8X2Eand_u(&instance, 0u, 3452816845u),
        17u,
        "i32.atomic.rmw8.and_u(0u, 3452816845u)"
    );
    assertEqualU64(
        atomic0_i64X2EatomicX2Eload(&instance, 0u),
        1229782938247303425ull,
        "i64.atomic.load(0u)"
    );
    atomic0_init(&instance, 1229782938247303441ull);
    printOK("init(1229782938247303441ull)");
    assertEqualU32(
        atomic0_i32X2EatomicX2Ermw16X2Eand_u(&instance, 0u, 3405695742u),
        4369u,
        "i32.atomic.rmw16.and_u(0u, 3405695742u)"
    );
    assertEqualU64(
        atomic0_i64X2EatomicX2Eload(&instance, 0u),
        1229782938247299088ull,
        "i64.atomic.load(0u)"
    );
    atomic0_init(&instance, 1229782938247303441ull);
    printOK("init(1229782938247303441ull)");
    assertEqualU64(
        atomic0_i64X2EatomicX2Ermw8X2Eand_u(&instance, 0u, 4774451407313060418ull),
        17ull,
        "i64.atomic.rmw8.and_u(0u, 4774451407313060418ull)"
    );
    assertEqualU64(
        atomic0_i64X2EatomicX2Eload(&instance, 0u),
        1229782938247303424ull,
        "i64.atomic.load(0u)"
    );
    atomic0_init(&instance, 1229782938247303441ull);
    printOK("init(1229782938247303441ull)");
    assertEqualU64(
        atomic0_i64X2EatomicX2Ermw16X2Eand_u(&instance, 0u, 13758425323549998831ull),
        4369ull,
        "i64.atomic.rmw16.and_u(0u, 13758425323549998831ull)"
    );
    assertEqualU64(
        atomic0_i64X2EatomicX2Eload(&instance, 0u),
        1229782938247303169ull,
        "i64.atomic.load(0u)"
    );
    atomic0_init(&instance, 1229782938247303441ull);
    printOK("init(1229782938247303441ull)");
    assertEqualU64(
        atomic0_i64X2EatomicX2Ermw32X2Eand_u(&instance, 0u, 14608453322185352933ull),
        286331153ull,
        "i64.atomic.rmw32.and_u(0u, 14608453322185352933ull)"
    );
    assertEqualU64(
        atomic0_i64X2EatomicX2Eload(&instance, 0u),
        1229782937962086401ull,
        "i64.atomic.load(0u)"
    );
    atomic0_init(&instance, 1229782938247303441ull);
    printOK("init(1229782938247303441ull)");
    assertEqualU32(
        atomic0_i32X2EatomicX2ErmwX2Eor(&instance, 0u, 305419896u),
        286331153u,
        "i32.atomic.rmw.or(0u, 305419896u)"
    );
    assertEqualU64(
        atomic0_i64X2EatomicX2Eload(&instance, 0u),
        1229782938283235193ull,
        "i64.atomic.load(0u)"
    );
    atomic0_init(&instance, 1229782938247303441ull);
    printOK("init(1229782938247303441ull)");
    assertEqualU64(
        atomic0_i64X2EatomicX2ErmwX2Eor(&instance, 0u, 72340172854919682ull),
        1229782938247303441ull,
        "i64.atomic.rmw.or(0u, 72340172854919682ull)"
    );
    assertEqualU64(
        atomic0_i64X2EatomicX2Eload(&instance, 0u),
        1229782938280989459ull,
        "i64.atomic.load(0u)"
    );
    atomic0_init(&instance, 1229782938247303441ull);
    printOK("init(1229782938247303441ull)");
    assertEqualU32(
        atomic0_i32X2EatomicX2Ermw8X2Eor_u(&instance, 0u, 3452816845u),
        17u,
        "i32.atomic.rmw8.or_u(0u, 3452816845u)"
    );
    assertEqualU64(
        atomic0_i64X2EatomicX2Eload(&instance, 0u),
        1229782938247303645ull,
        "i64.atomic.load(0u)"
    );
    atomic0_init(&instance, 1229782938247303441ull);
    printOK("init(1229782938247303441ull)");
    assertEqualU32(
        atomic0_i32X2EatomicX2Ermw16X2Eor_u(&instance, 0u, 3405695742u),
        4369u,
        "i32.atomic.rmw16.or_u(0u, 3405695742u)"
    );
    assertEqualU64(
        atomic0_i64X2EatomicX2Eload(&instance, 0u),
        1229782938247355391ull,
        "i64.atomic.load(0u)"
    );
    atomic0_init(&instance, 1229782938247303441ull);
    printOK("init(1229782938247303441ull)");
    assertEqualU64(
        atomic0_i64X2EatomicX2Ermw8X2Eor_u(&instance, 0u, 4774451407313060418ull),
        17ull,
        "i64.atomic.rmw8.or_u(0u, 4774451407313060418ull)"
    );
    assertEqualU64(
        atomic0_i64X2EatomicX2Eload(&instance, 0u),
        1229782938247303507ull,
        "i64.atomic.load(0u)"
    );
    atomic0_init(&instance, 1229782938247303441ull);
    printOK("init(1229782938247303441ull)");
    assertEqualU64(
        atomic0_i64X2EatomicX2Ermw16X2Eor_u(&instance, 0u, 13758425323549998831ull),
        4369ull,
        "i64.atomic.rmw16.or_u(0u, 13758425323549998831ull)"
    );
    assertEqualU64(
        atomic0_i64X2EatomicX2Eload(&instance, 0u),
        1229782938247348223ull,
        "i64.atomic.load(0u)"
    );
    atomic0_init(&instance, 1229782938247303441ull);
    printOK("init(1229782938247303441ull)");
    assertEqualU64(
        atomic0_i64X2EatomicX2Ermw32X2Eor_u(&instance, 0u, 14608453322185352933ull),
        286331153ull,
        "i64.atomic.rmw32.or_u(0u, 14608453322185352933ull)"
    );
    assertEqualU64(
        atomic0_i64X2EatomicX2Eload(&instance, 0u),
        1229782941647484917ull,
        "i64.atomic.load(0u)"
    );
    atomic0_init(&instance, 1229782938247303441ull);
    printOK("init(1229782938247303441ull)");
    assertEqualU32(
        atomic0_i32X2EatomicX2ErmwX2Exor(&instance, 0u, 305419896u),
        286331153u,
        "i32.atomic.rmw.xor(0u, 305419896u)"
    );
    assertEqualU64(
        atomic0_i64X2EatomicX2Eload(&instance, 0u),
        1229782938013747049ull,
        "i64.atomic.load(0u)"
    );
    atomic0_init(&instance, 1229782938247303441ull);
    printOK("init(1229782938247303441ull)");
    assertEqualU64(
        atomic0_i64X2EatomicX2ErmwX2Exor(&instance, 0u, 72340172854919682ull),
        1229782938247303441ull,
        "i64.atomic.rmw.xor(0u, 72340172854919682ull)"
    );
    assertEqualU64(
        atomic0_i64X2EatomicX2Eload(&instance, 0u),
        1157442765459755795ull,
        "i64.atomic.load(0u)"
    );
    atomic0_init(&instance, 1229782938247303441ull);
    printOK("init(1229782938247303441ull)");
    assertEqualU32(
        atomic0_i32X2EatomicX2Ermw8X2Exor_u(&instance, 0u, 3452816845u),
        17u,
        "i32.atomic.rmw8.xor_u(0u, 3452816845u)"
    );
    assertEqualU64(
        atomic0_i64X2EatomicX2Eload(&instance, 0u),
        1229782938247303644ull,
        "i64.atomic.load(0u)"
    );
    atomic0_init(&instance, 1229782938247303441ull);
    printOK("init(1229782938247303441ull)");
    assertEqualU32(
        atomic0_i32X2EatomicX2Ermw16X2Exor_u(&instance, 0u, 3405695742u),
        4369u,
        "i32.atomic.rmw16.xor_u(0u, 3405695742u)"
    );
    assertEqualU64(
        atomic0_i64X2EatomicX2Eload(&instance, 0u),
        1229782938247355375ull,
        "i64.atomic.load(0u)"
    );
    atomic0_init(&instance, 1229782938247303441ull);
    printOK("init(1229782938247303441ull)");
    assertEqualU64(
        atomic0_i64X2EatomicX2Ermw8X2Exor_u(&instance, 0u, 4774451407313060418ull),
        17ull,
        "i64.atomic.rmw8.xor_u(0u, 4774451407313060418ull)"
    );
    assertEqualU64(
        atomic0_i64X2EatomicX2Eload(&instance, 0u),
        1229782938247303507ull,
        "i64.atomic.load(0u)"
    );
    atomic0_init(&instance, 1229782938247303441ull);
    printOK("init(1229782938247303441ull)");
    assertEqualU64(
        atomic0_i64X2EatomicX2Ermw16X2Exor_u(&instance, 0u, 13758425323549998831ull),
        4369ull,
        "i64.atomic.rmw16.xor_u(0u, 13758425323549998831ull)"
    );
    assertEqualU64(
        atomic0_i64X2EatomicX2Eload(&instance, 0u),
        1229782938247344126ull,
        "i64.atomic.load(0u)"
    );
    atomic0_init(&instance, 1229782938247303441ull);
    printOK("init(1229782938247303441ull)");
    assertEqualU64(
        atomic0_i64X2EatomicX2Ermw32X2Exor_u(&instance, 0u, 14608453322185352933ull),
        286331153ull,
        "i64.atomic.rmw32.xor_u(0u, 14608453322185352933ull)"
    );
    assertEqualU64(
        atomic0_i64X2EatomicX2Eload(&instance, 0u),
        1229782941646370804ull,
        "i64.atomic.load(0u)"
    );
    atomic0_init(&instance, 1229782938247303441ull);
    printOK("init(1229782938247303441ull)");
    assertEqualU32(
        atomic0_i32X2EatomicX2ErmwX2Exchg(&instance, 0u, 305419896u),
        286331153u,
        "i32.atomic.rmw.xchg(0u, 305419896u)"
    );
    assertEqualU64(
        atomic0_i64X2EatomicX2Eload(&instance, 0u),
        1229782938266392184ull,
        "i64.atomic.load(0u)"
    );
    atomic0_init(&instance, 1229782938247303441ull);
    printOK("init(1229782938247303441ull)");
    assertEqualU64(
        atomic0_i64X2EatomicX2ErmwX2Exchg(&instance, 0u, 72340172854919682ull),
        1229782938247303441ull,
        "i64.atomic.rmw.xchg(0u, 72340172854919682ull)"
    );
    assertEqualU64(
        atomic0_i64X2EatomicX2Eload(&instance, 0u),
        72340172854919682ull,
        "i64.atomic.load(0u)"
    );
    atomic0_init(&instance, 1229782938247303441ull);
    printOK("init(1229782938247303441ull)");
    assertEqualU32(
        atomic0_i32X2EatomicX2Ermw8X2Exchg_u(&instance, 0u, 3452816845u),
        17u,
        "i32.atomic.rmw8.xchg_u(0u, 3452816845u)"
    );
    assertEqualU64(
        atomic0_i64X2EatomicX2Eload(&instance, 0u),
        1229782938247303629ull,
        "i64.atomic.load(0u)"
    );
    atomic0_init(&instance, 1229782938247303441ull);
    printOK("init(1229782938247303441ull)");
    assertEqualU32(
        atomic0_i32X2EatomicX2Ermw16X2Exchg_u(&instance, 0u, 3405695742u),
        4369u,
        "i32.atomic.rmw16.xchg_u(0u, 3405695742u)"
    );
    assertEqualU64(
        atomic0_i64X2EatomicX2Eload(&instance, 0u),
        1229782938247351038ull,
        "i64.atomic.load(0u)"
    );
    atomic0_init(&instance, 1229782938247303441ull);
    printOK("init(1229782938247303441ull)");
    assertEqualU64(
        atomic0_i64X2EatomicX2Ermw8X2Exchg_u(&instance, 0u, 4774451407313060418ull),
        17ull,
        "i64.atomic.rmw8.xchg_u(0u, 4774451407313060418ull)"
    );
    assertEqualU64(
        atomic0_i64X2EatomicX2Eload(&instance, 0u),
        1229782938247303490ull,
        "i64.atomic.load(0u)"
    );
    atomic0_init(&instance, 1229782938247303441ull);
    printOK("init(1229782938247303441ull)");
    assertEqualU64(
        atomic0_i64X2EatomicX2Ermw16X2Exchg_u(&instance, 0u, 13758425323549998831ull),
        4369ull,
        "i64.atomic.rmw16.xchg_u(0u, 13758425323549998831ull)"
    );
    assertEqualU64(
        atomic0_i64X2EatomicX2Eload(&instance, 0u),
        1229782938247347951ull,
        "i64.atomic.load(0u)"
    );
    atomic0_init(&instance, 1229782938247303441ull);
    printOK("init(1229782938247303441ull)");
    assertEqualU64(
        atomic0_i64X2EatomicX2Ermw32X2Exchg_u(&instance, 0u, 14608453322185352933ull),
        286331153ull,
        "i64.atomic.rmw32.xchg_u(0u, 14608453322185352933ull)"
    );
    assertEqualU64(
        atomic0_i64X2EatomicX2Eload(&instance, 0u),
        1229782941362267877ull,
        "i64.atomic.load(0u)"
    );
    atomic0_init(&instance, 1229782938247303441ull);
    printOK("init(1229782938247303441ull)");
    assertEqualU32(
        atomic0_i32X2EatomicX2ErmwX2Ecmpxchg(&instance, 0u, 0u, 305419896u),
        286331153u,
        "i32.atomic.rmw.cmpxchg(0u, 0u, 305419896u)"
    );
    assertEqualU64(
        atomic0_i64X2EatomicX2Eload(&instance, 0u),
        1229782938247303441ull,
        "i64.atomic.load(0u)"
    );
    atomic0_init(&instance, 1229782938247303441ull);
    printOK("init(1229782938247303441ull)");
    assertEqualU64(
        atomic0_i64X2EatomicX2ErmwX2Ecmpxchg(&instance, 0u, 0ull, 72340172854919682ull),
        1229782938247303441ull,
        "i64.atomic.rmw.cmpxchg(0u, 0ull, 72340172854919682ull)"
    );
    assertEqualU64(
        atomic0_i64X2EatomicX2Eload(&instance, 0u),
        1229782938247303441ull,
        "i64.atomic.load(0u)"
    );
    atomic0_init(&instance, 1229782938247303441ull);
    printOK("init(1229782938247303441ull)");
    assertEqualU32(
        atomic0_i32X2EatomicX2Ermw8X2Ecmpxchg_u(&instance, 0u, 0u, 3452816845u),
        17u,
        "i32.atomic.rmw8.cmpxchg_u(0u, 0u, 3452816845u)"
    );
    assertEqualU64(
        atomic0_i64X2EatomicX2Eload(&instance, 0u),
        1229782938247303441ull,
        "i64.atomic.load(0u)"
    );
    atomic0_init(&instance, 1229782938247303441ull);
    printOK("init(1229782938247303441ull)");
    assertEqualU32(
        atomic0_i32X2EatomicX2Ermw16X2Ecmpxchg_u(&instance, 0u, 0u, 3405695742u),
        4369u,
        "i32.atomic.rmw16.cmpxchg_u(0u, 0u, 3405695742u)"
    );
    assertEqualU64(
        atomic0_i64X2EatomicX2Eload(&instance, 0u),
        1229782938247303441ull,
        "i64.atomic.load(0u)"
    );
    atomic0_init(&instance, 1229782938247303441ull);
    printOK("init(1229782938247303441ull)");
    assertEqualU64(
        atomic0_i64X2EatomicX2Ermw8X2Ecmpxchg_u(&instance, 0u, 0ull, 4774451407313060418ull),
        17ull,
        "i64.atomic.rmw8.cmpxchg_u(0u, 0ull, 4774451407313060418ull)"
    );
    assertEqualU64(
        atomic0_i64X2EatomicX2Eload(&instance, 0u),
        1229782938247303441ull,
        "i64.atomic.load(0u)"
    );
    atomic0_init(&instance, 1229782938247303441ull);
    printOK("init(1229782938247303441ull)");
    assertEqualU64(
        atomic0_i64X2EatomicX2Ermw16X2Ecmpxchg_u(&instance, 0u, 0ull, 13758425323549998831ull),
        4369ull,
        "i64.atomic.rmw16.cmpxchg_u(0u, 0ull, 13758425323549998831ull)"
    );
    assertEqualU64(
        atomic0_i64X2EatomicX2Eload(&instance, 0u),
        1229782938247303441ull,
        "i64.atomic.load(0u)"
    );
    atomic0_init(&instance, 1229782938247303441ull);
    printOK("init(1229782938247303441ull)");
    assertEqualU64(
        atomic0_i64X2EatomicX2Ermw32X2Ecmpxchg_u(&instance, 0u, 0ull, 14608453322185352933ull),
        286331153ull,
        "i64.atomic.rmw32.cmpxchg_u(0u, 0ull, 14608453322185352933ull)"
    );
    assertEqualU64(
        atomic0_i64X2EatomicX2Eload(&instance, 0u),
        1229782938247303441ull,
        "i64.atomic.load(0u)"
    );
    atomic0_init(&instance, 1229782938247303441ull);
    printOK("init(1229782938247303441ull)");
    assertEqualU32(
        atomic0_i32X2EatomicX2ErmwX2Ecmpxchg(&instance, 0u, 286331153u, 305419896u),
        286331153u,
        "i32.atomic.rmw.cmpxchg(0u, 286331153u, 305419896u)"
    );
    assertEqualU64(
        atomic0_i64X2EatomicX2Eload(&instance, 0u),
        1229782938266392184ull,
        "i64.atomic.load(0u)"
    );
    atomic0_init(&instance, 1229782938247303441ull);
    printOK("init(1229782938247303441ull)");
    assertEqualU64(
        atomic0_i64X2EatomicX2ErmwX2Ecmpxchg(&instance, 0u, 1229782938247303441ull, 72340172854919682ull),
        1229782938247303441ull,
        "i64.atomic.rmw.cmpxchg(0u, 1229782938247303441ull, 72340172854919682ull)"
    );
    assertEqualU64(
        atomic0_i64X2EatomicX2Eload(&instance, 0u),
        72340172854919682ull,
        "i64.atomic.load(0u)"
    );
    atomic0_init(&instance, 1229782938247303441ull);
    printOK("init(1229782938247303441ull)");
    assertEqualU32(
        atomic0_i32X2EatomicX2Ermw8X2Ecmpxchg_u(&instance, 0u, 17u, 3452816845u),
        17u,
        "i32.atomic.rmw8.cmpxchg_u(0u, 17u, 3452816845u)"
    );
    assertEqualU64(
        atomic0_i64X2EatomicX2Eload(&instance, 0u),
        1229782938247303629ull,
        "i64.atomic.load(0u)"
    );
    atomic0_init(&instance, 1229782938247303441ull);
    printOK("init(1229782938247303441ull)");
    assertEqualU32(
        atomic0_i32X2EatomicX2Ermw16X2Ecmpxchg_u(&instance, 0u, 4369u, 3405695742u),
        4369u,
        "i32.atomic.rmw16.cmpxchg_u(0u, 4369u, 3405695742u)"
    );
    assertEqualU64(
        atomic0_i64X2EatomicX2Eload(&instance, 0u),
        1229782938247351038ull,
        "i64.atomic.load(0u)"
    );
    atomic0_init(&instance, 1229782938247303441ull);
    printOK("init(1229782938247303441ull)");
    assertEqualU64(
        atomic0_i64X2EatomicX2Ermw8X2Ecmpxchg_u(&instance, 0u, 17ull, 4774451407313060418ull),
        17ull,
        "i64.atomic.rmw8.cmpxchg_u(0u, 17ull, 4774451407313060418ull)"
    );
    assertEqualU64(
        atomic0_i64X2EatomicX2Eload(&instance, 0u),
        1229782938247303490ull,
        "i64.atomic.load(0u)"
    );
    atomic0_init(&instance, 1229782938247303441ull);
    printOK("init(1229782938247303441ull)");
    assertEqualU64(
        atomic0_i64X2EatomicX2Ermw16X2Ecmpxchg_u(&instance, 0u, 4369ull, 13758425323549998831ull),
        4369ull,
        "i64.atomic.rmw16.cmpxchg_u(0u, 4369ull, 13758425323549998831ull)"
    );
    assertEqualU64(
        atomic0_i64X2EatomicX2Eload(&instance, 0u),
        1229782938247347951ull,
        "i64.atomic.load(0u)"
    );
    atomic0_init(&instance, 1229782938247303441ull);
    printOK("init(1229782938247303441ull)");
    assertEqualU64(
        atomic0_i64X2EatomicX2Ermw32X2Ecmpxchg_u(&instance, 0u, 286331153ull, 14608453322185352933ull),
        286331153ull,
        "i64.atomic.rmw32.cmpxchg_u(0u, 286331153ull, 14608453322185352933ull)"
    );
    assertEqualU64(
        atomic0_i64X2EatomicX2Eload(&instance, 0u),
        1229782941362267877ull,
        "i64.atomic.load(0u)"
    );
}
