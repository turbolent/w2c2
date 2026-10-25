
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_f64_const.0.h"

void test() {
    m11_f64X5FconstX2E0Instance instance;
    m11_f64X5FconstX2E0Instantiate(&instance, resolveTestImports);
    printStart("f64_const.0.wasm");
    assertEqualU64(
        m11_f64X5FconstX2E0Export3_nan(&instance),
        9221120237041090560ull,
        "nan()"
    );
    assertEqualU64(
        m11_f64X5FconstX2E0Export12_negativeX5Fnan(&instance),
        18444492273895866368ull,
        "negative_nan()"
    );
    assertEqualU64(
        m11_f64X5FconstX2E0Export12_highX5Fpayload(&instance),
        9221120239188574208ull,
        "high_payload()"
    );
    assertEqualU64(
        m11_f64X5FconstX2E0Export21_negativeX5FhighX5Fpayload(&instance),
        18444492276043350016ull,
        "negative_high_payload()"
    );
    assertEqualU64(
        m11_f64X5FconstX2E0Export13_bit23X5Fpayload(&instance),
        9218868437235793920ull,
        "bit23_payload()"
    );
    assertEqualU64(
        m11_f64X5FconstX2E0Export22_negativeX5Fbit23X5Fpayload(&instance),
        18442240474090569728ull,
        "negative_bit23_payload()"
    );
    assertEqualU64(
        m11_f64X5FconstX2E0Export11_lowX5Fpayload(&instance),
        9218868437227405313ull,
        "low_payload()"
    );
    assertEqualU64(
        m11_f64X5FconstX2E0Export20_negativeX5FlowX5Fpayload(&instance),
        18442240474082181121ull,
        "negative_low_payload()"
    );
    assertEqualU64(
        m11_f64X5FconstX2E0Export3_inf(&instance),
        9218868437227405312ull,
        "inf()"
    );
    assertEqualU64(
        m11_f64X5FconstX2E0Export12_negativeX5Finf(&instance),
        18442240474082181120ull,
        "negative_inf()"
    );
    assertEqualU64(
        m11_f64X5FconstX2E0Export10_globalX5Fnan(&instance),
        9221120237041090560ull,
        "global_nan()"
    );
    assertEqualU64(
        m11_f64X5FconstX2E0Export19_globalX5FnegativeX5Fnan(&instance),
        18444492273895866368ull,
        "global_negative_nan()"
    );
    assertEqualU64(
        m11_f64X5FconstX2E0Export10_globalX5Finf(&instance),
        9218868437227405312ull,
        "global_inf()"
    );
    assertEqualU64(
        m11_f64X5FconstX2E0Export19_globalX5FnegativeX5Finf(&instance),
        18442240474082181120ull,
        "global_negative_inf()"
    );
}
