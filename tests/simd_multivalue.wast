;; Multi-value regressions with vector results and block parameters.
(module
  (type $tuple (func (result i32 v128 f64 v128)))
  (table 1 funcref)
  (elem (i32.const 0) $tuple)
  (func $tuple (export "tuple") (type $tuple)
    i32.const 7 v128.const i32x4 1 2 3 4 f64.const -0
    v128.const f32x4 nan nan nan nan)
  (func (export "direct") (type $tuple) call $tuple)
  (func (export "indirect") (type $tuple) i32.const 0 call_indirect (type $tuple))
  (func (export "block") (result v128 i32)
    v128.const i32x4 1 2 3 4
    block (param v128) (result v128 i32) i32.const 9 end)
  (func (export "if") (param i32) (result v128 i32)
    v128.const i32x4 1 2 3 4 i32.const 9 local.get 0
    if (param v128 i32) (result v128 i32)
      i32.const 1 i32.add
    else
      i32.const 2 i32.add
    end)
  (func (export "identity") (param i32) (result v128 i32)
    v128.const i32x4 1 2 3 4 i32.const 9 local.get 0
    if (param v128 i32) (result v128 i32) i32.const 1 i32.add end)
  (func (export "loop") (result v128 i32) (local $n i32)
    v128.const i32x4 1 2 3 4 i32.const 3
    loop $again (param v128 i32) (result v128 i32)
      local.set $n v128.const i32x4 1 1 1 1 i32x4.add
      local.get $n i32.const 1 i32.sub local.tee $n local.get $n br_if $again
    end)
  (func (export "br") (param i32) (result v128 v128)
    block (result v128 v128)
      v128.const i32x4 99 99 99 99
      v128.const i32x4 1 2 3 4 v128.const i32x4 5 6 7 8 local.get 0 br_if 0
      v128.xor v128.xor v128.const i32x4 0 0 0 0
    end)
  (func (export "return") (result v128 i32)
    i32.const 99 v128.const i32x4 1 2 3 4 i32.const 9 return)
  (func $dead (result v128 i32) unreachable)
  (func (export "dead") call $dead drop drop))
(assert_return (invoke "tuple") (i32.const 7) (v128.const i32x4 1 2 3 4) (f64.const -0) (v128.const f32x4 nan:canonical nan:canonical nan:canonical nan:canonical))
(assert_return (invoke "direct") (i32.const 7) (v128.const i32x4 1 2 3 4) (f64.const -0) (v128.const f32x4 nan:canonical nan:canonical nan:canonical nan:canonical))
(assert_return (invoke "indirect") (i32.const 7) (v128.const i32x4 1 2 3 4) (f64.const -0) (v128.const f32x4 nan:canonical nan:canonical nan:canonical nan:canonical))
(assert_return (invoke "block") (v128.const i32x4 1 2 3 4) (i32.const 9))
(assert_return (invoke "if" (i32.const 1)) (v128.const i32x4 1 2 3 4) (i32.const 10))
(assert_return (invoke "if" (i32.const 0)) (v128.const i32x4 1 2 3 4) (i32.const 11))
(assert_return (invoke "identity" (i32.const 1)) (v128.const i32x4 1 2 3 4) (i32.const 10))
(assert_return (invoke "identity" (i32.const 0)) (v128.const i32x4 1 2 3 4) (i32.const 9))
(assert_return (invoke "loop") (v128.const i32x4 4 5 6 7) (i32.const 0))
(assert_return (invoke "br" (i32.const 1)) (v128.const i32x4 1 2 3 4) (v128.const i32x4 5 6 7 8))
(assert_return (invoke "br" (i32.const 0)) (v128.const i32x4 103 103 103 111) (v128.const i32x4 0 0 0 0))
(assert_return (invoke "return") (v128.const i32x4 1 2 3 4) (i32.const 9))
(assert_trap (invoke "dead") "unreachable")
;; Include independently generated headers with the same vector tuple.
(module
  (func (export "tuple") (result i32 v128 f64 v128)
    i32.const 1 v128.const i32x4 1 1 1 1 f64.const 1 v128.const i32x4 2 2 2 2))
(assert_return (invoke "tuple") (i32.const 1) (v128.const i32x4 1 1 1 1) (f64.const 1) (v128.const i32x4 2 2 2 2))
