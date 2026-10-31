(module
  (type $pair (func (result v128 funcref)))
  (table 1 funcref)
  (table $t 1 funcref)
  (elem (table $t) (i32.const 0) func $pair)
  (func $pair (result v128 funcref)
    v128.const i32x4 1 2 3 4 ref.func $pair)
  (func (export "call") (result v128 funcref)
    i32.const 0 call_indirect $t (type $pair))
  (func (export "branch") (param i32) (result funcref v128)
    block (result funcref v128)
      i64.const 99 ref.func $pair v128.const i32x4 5 6 7 8 local.get 0 br_if 0
      drop drop drop ref.null func v128.const i32x4 9 10 11 12
    end)
  (func (export "identity") (param i32) (result v128 funcref)
    v128.const i32x4 1 2 3 4 ref.func $pair local.get 0
    if (param v128 funcref) (result v128 funcref) end))
(assert_return (invoke "call") (v128.const i32x4 1 2 3 4) (ref.func))
(assert_return (invoke "branch" (i32.const 0)) (ref.null func) (v128.const i32x4 9 10 11 12))
(assert_return (invoke "branch" (i32.const 1)) (ref.func) (v128.const i32x4 5 6 7 8))
(assert_return (invoke "identity" (i32.const 0)) (v128.const i32x4 1 2 3 4) (ref.func))
(assert_return (invoke "identity" (i32.const 1)) (v128.const i32x4 1 2 3 4) (ref.func))

(module
  (type $mixed (func (param externref) (result externref funcref v128)))
  (table 1 funcref)
  (elem (i32.const 0) func $mixed)
  (func $mixed (export "mixed") (type $mixed)
    local.get 0 ref.func $mixed v128.const i32x4 1 2 3 4)
  (func (export "indirect") (param externref) (result externref funcref v128)
    local.get 0 i32.const 0 call_indirect (type $mixed))
  (func (export "branch") (param externref i32) (result externref funcref v128)
    local.get 0 call $mixed
    block (param externref funcref v128) (result externref funcref v128)
      local.get 1 br_if 0
      drop drop drop ref.null extern ref.null func v128.const i32x4 5 6 7 8
    end)
  (func (export "identity") (param externref i32) (result externref funcref v128)
    local.get 0 call $mixed local.get 1
    if (param externref funcref v128) (result externref funcref v128) end))
(assert_return (invoke "mixed" (ref.extern 0)) (ref.extern 0) (ref.func) (v128.const i32x4 1 2 3 4))
(assert_return (invoke "indirect" (ref.extern 1)) (ref.extern 1) (ref.func) (v128.const i32x4 1 2 3 4))
(assert_return (invoke "branch" (ref.extern 2) (i32.const 1)) (ref.extern 2) (ref.func) (v128.const i32x4 1 2 3 4))
(assert_return (invoke "branch" (ref.extern 2) (i32.const 0)) (ref.null extern) (ref.null func) (v128.const i32x4 5 6 7 8))
(assert_return (invoke "identity" (ref.extern 3) (i32.const 0)) (ref.extern 3) (ref.func) (v128.const i32x4 1 2 3 4))
(assert_return (invoke "identity" (ref.extern 3) (i32.const 1)) (ref.extern 3) (ref.func) (v128.const i32x4 1 2 3 4))
