
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_float_exprs.70.h"

void test() {
    floatexprs70Instance instance;
    floatexprs70Instantiate(&instance, resolveTestImports);
    printStart("float_exprs.70.wasm");
    assertEqualF32(
        floatexprs70_f32X2Eno_fold_add_divs(&instance, 377.368896484375, -0.04011818394064903, -1.3629298560546316e+38),
        -2.768512148377355e-36,
        "f32.no_fold_add_divs(377.368896484375, -0.04011818394064903, -1.3629298560546316e+38)"
    );
    assertEqualF32(
        floatexprs70_f32X2Eno_fold_add_divs(&instance, -1.8234023041237435e-19, -3.3970288113369237e-15, -170996707360768.0),
        1.9867115411157125e-29,
        "f32.no_fold_add_divs(-1.8234023041237435e-19, -3.3970288113369237e-15, -170996707360768.0)"
    );
    assertEqualF32(
        floatexprs70_f32X2Eno_fold_add_divs(&instance, -1.967263835557856e-14, 6.414098702699398e-20, -541989070176256.0),
        3.6296996567176507e-29,
        "f32.no_fold_add_divs(-1.967263835557856e-14, 6.414098702699398e-20, -541989070176256.0)"
    );
    assertEqualF32(
        floatexprs70_f32X2Eno_fold_add_divs(&instance, -4.038505822193515e-31, 3.848228081428171e-30, -3.4523719791292376e+26),
        0.0,
        "f32.no_fold_add_divs(-4.038505822193515e-31, 3.848228081428171e-30, -3.4523719791292376e+26)"
    );
    assertEqualF32(
        floatexprs70_f32X2Eno_fold_add_divs(&instance, 0.0010934415040537715, 0.2070312350988388, 1.3509783969902986e-37),
        1.540547727687837e+36,
        "f32.no_fold_add_divs(0.0010934415040537715, 0.2070312350988388, 1.3509783969902986e-37)"
    );
    assertEqualF64(
        floatexprs70_f64X2Eno_fold_add_divs(&instance, -4.91701943214376e+129, 6.813215632201902e+130, 2.6125410100237784e+274),
        2.4196801752520584e-144,
        "f64.no_fold_add_divs(-4.91701943214376e+129, 6.813215632201902e+130, 2.6125410100237784e+274)"
    );
    assertEqualF64(
        floatexprs70_f64X2Eno_fold_add_divs(&instance, -1.020646795322455e+16, 63.422616671746226, -1.6024747869814892e-288),
        6.369190976445851e+303,
        "f64.no_fold_add_divs(-1.020646795322455e+16, 63.422616671746226, -1.6024747869814892e-288)"
    );
    assertEqualF64(
        floatexprs70_f64X2Eno_fold_add_divs(&instance, -1.5270569633109837e-291, 2.5755503329232514e-294, 5.882693916421492e+151),
        0.0,
        "f64.no_fold_add_divs(-1.5270569633109837e-291, 2.5755503329232514e-294, 5.882693916421492e+151)"
    );
    assertEqualF64(
        floatexprs70_f64X2Eno_fold_add_divs(&instance, 2.666796487439464e+94, -2.1315692524936578e+99, 1.2377004518680012e-38),
        -1.7221796932462534e+137,
        "f64.no_fold_add_divs(2.666796487439464e+94, -2.1315692524936578e+99, 1.2377004518680012e-38)"
    );
    assertEqualF64(
        floatexprs70_f64X2Eno_fold_add_divs(&instance, -1.2952888377288216e-219, 5.808769259900048e-228, 1.6745741699443756e-21),
        -7.735034106987796e-199,
        "f64.no_fold_add_divs(-1.2952888377288216e-219, 5.808769259900048e-228, 1.6745741699443756e-21)"
    );
}
