
#include <stdio.h>
#include "w2c2_base.h"
#include "test.h"
#include "test_float_exprs.27.h"

void test() {
    floatexprs27Instance instance;
    floatexprs27Instantiate(&instance, resolveTestImports);
    printStart("float_exprs.27.wasm");
    assertEqualF32(
        floatexprs27_f32X2Eno_approximate_reciprocal_sqrt(&instance, 1.6117864692650336e-13),
        2490842.5,
        "f32.no_approximate_reciprocal_sqrt(1.6117864692650336e-13)"
    );
    assertEqualF32(
        floatexprs27_f32X2Eno_approximate_reciprocal_sqrt(&instance, 0.007449136581271887),
        11.586359977722168,
        "f32.no_approximate_reciprocal_sqrt(0.007449136581271887)"
    );
    assertEqualF32(
        floatexprs27_f32X2Eno_approximate_reciprocal_sqrt(&instance, 2.339817041277766e-20),
        6537460224.0,
        "f32.no_approximate_reciprocal_sqrt(2.339817041277766e-20)"
    );
    assertEqualF32(
        floatexprs27_f32X2Eno_approximate_reciprocal_sqrt(&instance, 1.1123504325754804e-13),
        2998328.25,
        "f32.no_approximate_reciprocal_sqrt(1.1123504325754804e-13)"
    );
    assertEqualF32(
        floatexprs27_f32X2Eno_approximate_reciprocal_sqrt(&instance, 1.7653063085045715e-26),
        7526446268416.0,
        "f32.no_approximate_reciprocal_sqrt(1.7653063085045715e-26)"
    );
    assertEqualF64(
        floatexprs27_f64X2Eno_fuse_reciprocal_sqrt(&instance, 4.472459252766337e+267),
        1.4952947335898096e-134,
        "f64.no_fuse_reciprocal_sqrt(4.472459252766337e+267)"
    );
    assertEqualF64(
        floatexprs27_f64X2Eno_fuse_reciprocal_sqrt(&instance, 4.752392260007119e+93),
        1.4505872638954843e-47,
        "f64.no_fuse_reciprocal_sqrt(4.752392260007119e+93)"
    );
    assertEqualF64(
        floatexprs27_f64X2Eno_fuse_reciprocal_sqrt(&instance, 2.9014415885392436e+31),
        1.8564920084793608e-16,
        "f64.no_fuse_reciprocal_sqrt(2.9014415885392436e+31)"
    );
    assertEqualF64(
        floatexprs27_f64X2Eno_fuse_reciprocal_sqrt(&instance, 1.3966125076974778e+201),
        2.6758516751072132e-101,
        "f64.no_fuse_reciprocal_sqrt(1.3966125076974778e+201)"
    );
    assertEqualF64(
        floatexprs27_f64X2Eno_fuse_reciprocal_sqrt(&instance, 1.5159641544070443e+44),
        8.121860649480894e-23,
        "f64.no_fuse_reciprocal_sqrt(1.5159641544070443e+44)"
    );
}
