
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_f64_const.0.h"

void test() {
    f64const0Instance instance;
    f64const0Instantiate(&instance, resolveTestImports);
    printStart("f64_const.0.wasm");
    assertEqualU64(
        f64const0_nan(&instance),
        9221120237041090560ull,
        "nan()"
    );
    assertEqualU64(
        f64const0_negative_nan(&instance),
        18444492273895866368ull,
        "negative_nan()"
    );
    assertEqualU64(
        f64const0_high_payload(&instance),
        9221120239188574208ull,
        "high_payload()"
    );
    assertEqualU64(
        f64const0_negative_high_payload(&instance),
        18444492276043350016ull,
        "negative_high_payload()"
    );
    assertEqualU64(
        f64const0_bit23_payload(&instance),
        9218868437235793920ull,
        "bit23_payload()"
    );
    assertEqualU64(
        f64const0_negative_bit23_payload(&instance),
        18442240474090569728ull,
        "negative_bit23_payload()"
    );
    assertEqualU64(
        f64const0_low_payload(&instance),
        9218868437227405313ull,
        "low_payload()"
    );
    assertEqualU64(
        f64const0_negative_low_payload(&instance),
        18442240474082181121ull,
        "negative_low_payload()"
    );
    assertEqualU64(
        f64const0_inf(&instance),
        9218868437227405312ull,
        "inf()"
    );
    assertEqualU64(
        f64const0_negative_inf(&instance),
        18442240474082181120ull,
        "negative_inf()"
    );
    assertEqualU64(
        f64const0_global_nan(&instance),
        9221120237041090560ull,
        "global_nan()"
    );
    assertEqualU64(
        f64const0_global_negative_nan(&instance),
        18444492273895866368ull,
        "global_negative_nan()"
    );
    assertEqualU64(
        f64const0_global_inf(&instance),
        9218868437227405312ull,
        "global_inf()"
    );
    assertEqualU64(
        f64const0_global_negative_inf(&instance),
        18442240474082181120ull,
        "global_negative_inf()"
    );
}
