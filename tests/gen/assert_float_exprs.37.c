
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_float_exprs.37.h"

void test() {
    floatexprs37Instance instance;
    floatexprs37Instantiate(&instance, resolveTestImports);
    printStart("float_exprs.37.wasm");
    assertEqualF32(
        floatexprs37_no_demote_mixed_add(&instance, 4.941266527909197e-29, 1.8767182723004972e-36),
        4.941266675715419e-29,
        "no_demote_mixed_add(4.941266527909197e-29, 1.8767182723004972e-36)"
    );
    assertEqualF32(
        floatexprs37_no_demote_mixed_add(&instance, 140851523637.69385, 401096441856.0),
        541947953152.0,
        "no_demote_mixed_add(140851523637.69385, 401096441856.0)"
    );
    assertEqualF32(
        floatexprs37_no_demote_mixed_add(&instance, 2.0831160914192852e-36, -6.050095133542437e-37),
        1.4781065702760415e-36,
        "no_demote_mixed_add(2.0831160914192852e-36, -6.050095133542437e-37)"
    );
    assertEqualF32(
        floatexprs37_no_demote_mixed_add(&instance, -1.0032827553674626e-06, 1.931291793155765e-09),
        -1.0013515066020773e-06,
        "no_demote_mixed_add(-1.0032827553674626e-06, 1.931291793155765e-09)"
    );
    assertEqualF32(
        floatexprs37_no_demote_mixed_add(&instance, -1.3840207035752711e-06, -5.202814091012642e-13),
        -1.3840211749993614e-06,
        "no_demote_mixed_add(-1.3840207035752711e-06, -5.202814091012642e-13)"
    );
    assertEqualF32(
        floatexprs37_no_demote_mixed_add_commuted(&instance, 1.8767182723004972e-36, 4.941266527909197e-29),
        4.941266675715419e-29,
        "no_demote_mixed_add_commuted(1.8767182723004972e-36, 4.941266527909197e-29)"
    );
    assertEqualF32(
        floatexprs37_no_demote_mixed_add_commuted(&instance, 401096441856.0, 140851523637.69385),
        541947953152.0,
        "no_demote_mixed_add_commuted(401096441856.0, 140851523637.69385)"
    );
    assertEqualF32(
        floatexprs37_no_demote_mixed_add_commuted(&instance, -6.050095133542437e-37, 2.0831160914192852e-36),
        1.4781065702760415e-36,
        "no_demote_mixed_add_commuted(-6.050095133542437e-37, 2.0831160914192852e-36)"
    );
    assertEqualF32(
        floatexprs37_no_demote_mixed_add_commuted(&instance, 1.931291793155765e-09, -1.0032827553674626e-06),
        -1.0013515066020773e-06,
        "no_demote_mixed_add_commuted(1.931291793155765e-09, -1.0032827553674626e-06)"
    );
    assertEqualF32(
        floatexprs37_no_demote_mixed_add_commuted(&instance, -5.202814091012642e-13, -1.3840207035752711e-06),
        -1.3840211749993614e-06,
        "no_demote_mixed_add_commuted(-5.202814091012642e-13, -1.3840207035752711e-06)"
    );
}
