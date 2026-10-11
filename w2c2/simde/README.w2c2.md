Vendored subset of SIMDe (MIT), commit c6bc9b883ef2f430adb8e43679a4cff6fb438fb1.
Source: https://github.com/simd-everywhere/simde
Only wasm/simd128.h and its transitive local includes are bundled.
Local C89 syntax adaptations: line comments use block comments, size_t loop
variables are declared in an enclosing block, and debug-trap uses HEDLEY_INLINE.
Vectorization pragmas stay immediately before their loops. The four
convert/shuffle builtin branches also check that vector subscripting
is enabled, so SIMDE_NO_VECTOR works with recent GCC/Clang. Scalar wrapping
arithmetic, absolute value, negation, shifts, and dot sums use unsigned bits
to avoid signed overflow. Saturating scalar conversion checks include the
rounded floating-point upper bound before casting. Native instruction mappings
are unchanged. COPYING contains the upstream license.
WABT-LICENSE covers the adapted wasm2c endian adapters in ../w2c2_simd.h.
