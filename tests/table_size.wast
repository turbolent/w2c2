(module
  (table $t0 0 externref)
  (table $t1 1 externref)
  (table $t2 0 2 externref)
  (table $t3 3 8 externref)

  (func (export "size-t0") (result i32) table.size)
  (func (export "size-t1") (result i32) (table.size $t1))
  (func (export "size-t2") (result i32) (table.size $t2))
  (func (export "size-t3") (result i32) (table.size $t3))

  (func (export "grow-t0") (param $sz i32)
    (drop (table.grow $t0 (ref.null extern) (local.get $sz)))
  )
  (func (export "grow-t1") (param $sz i32)
    (drop (table.grow $t1 (ref.null extern) (local.get $sz)))
  )
  (func (export "grow-t2") (param $sz i32)
    (drop (table.grow $t2 (ref.null extern) (local.get $sz)))
  )
  (func (export "grow-t3") (param $sz i32)
    (drop (table.grow $t3 (ref.null extern) (local.get $sz)))
  )
)

(assert_return (invoke "size-t0") (i32.const 0))
(assert_return (invoke "grow-t0" (i32.const 1)))
(assert_return (invoke "size-t0") (i32.const 1))
(assert_return (invoke "grow-t0" (i32.const 4)))
(assert_return (invoke "size-t0") (i32.const 5))
(assert_return (invoke "grow-t0" (i32.const 0)))
(assert_return (invoke "size-t0") (i32.const 5))

(assert_return (invoke "size-t1") (i32.const 1))
(assert_return (invoke "grow-t1" (i32.const 1)))
(assert_return (invoke "size-t1") (i32.const 2))
(assert_return (invoke "grow-t1" (i32.const 4)))
(assert_return (invoke "size-t1") (i32.const 6))
(assert_return (invoke "grow-t1" (i32.const 0)))
(assert_return (invoke "size-t1") (i32.const 6))

(assert_return (invoke "size-t2") (i32.const 0))
(assert_return (invoke "grow-t2" (i32.const 3)))
(assert_return (invoke "size-t2") (i32.const 0))
(assert_return (invoke "grow-t2" (i32.const 1)))
(assert_return (invoke "size-t2") (i32.const 1))
(assert_return (invoke "grow-t2" (i32.const 0)))
(assert_return (invoke "size-t2") (i32.const 1))
(assert_return (invoke "grow-t2" (i32.const 4)))
(assert_return (invoke "size-t2") (i32.const 1))
(assert_return (invoke "grow-t2" (i32.const 1)))
(assert_return (invoke "size-t2") (i32.const 2))

(assert_return (invoke "size-t3") (i32.const 3))
(assert_return (invoke "grow-t3" (i32.const 1)))
(assert_return (invoke "size-t3") (i32.const 4))
(assert_return (invoke "grow-t3" (i32.const 3)))
(assert_return (invoke "size-t3") (i32.const 7))
(assert_return (invoke "grow-t3" (i32.const 0)))
(assert_return (invoke "size-t3") (i32.const 7))
(assert_return (invoke "grow-t3" (i32.const 2)))
(assert_return (invoke "size-t3") (i32.const 7))
(assert_return (invoke "grow-t3" (i32.const 1)))
(assert_return (invoke "size-t3") (i32.const 8))


;; Type errors

(assert_invalid
  (module
    (table $t 1 externref)
    (func $type-result-i32-vs-empty
      (table.size $t)
    )
  )
  "type mismatch"
)
(assert_invalid
  (module
    (table $t 1 externref)
    (func $type-result-i32-vs-f32 (result f32)
      (table.size $t)
    )
  )
  "type mismatch"
)

;; The same size and growth behavior applies to function tables.
(module
  (table $zero 0 funcref)
  (table $limited 1 3 funcref)
  (func (export "zero") (result i32) table.size $zero)
  (func (export "size") (result i32) table.size $limited)
  (func (export "grow") (param i32) (result i32) ref.null func local.get 0 table.grow $limited))
(assert_return (invoke "zero") (i32.const 0))
(assert_return (invoke "size") (i32.const 1))
(assert_return (invoke "grow" (i32.const 0)) (i32.const 1))
(assert_return (invoke "grow" (i32.const 2)) (i32.const 1))
(assert_return (invoke "size") (i32.const 3))
(assert_return (invoke "grow" (i32.const 1)) (i32.const -1))
(assert_return (invoke "size") (i32.const 3))
