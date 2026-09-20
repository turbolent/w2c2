(module
  (memory 0 0)
  (table 0 0 funcref)
  (func (export "size") (result i32) (memory.size))
  (func (export "grow") (param i32) (result i32)
    (memory.grow (local.get 0)))
)

(assert_return (invoke "size") (i32.const 0))
(assert_return (invoke "grow" (i32.const 0)) (i32.const 0))
(assert_return (invoke "grow" (i32.const 1)) (i32.const -1))
(assert_return (invoke "grow" (i32.const -1)) (i32.const -1))
(assert_return (invoke "size") (i32.const 0))

(module
  (memory 0 0 shared)
  (func (export "size") (result i32) (memory.size))
  (func (export "grow") (param i32) (result i32)
    (memory.grow (local.get 0)))
)

(assert_return (invoke "size") (i32.const 0))
(assert_return (invoke "grow" (i32.const 0)) (i32.const 0))
(assert_return (invoke "grow" (i32.const 1)) (i32.const -1))
(assert_return (invoke "grow" (i32.const -1)) (i32.const -1))
(assert_return (invoke "size") (i32.const 0))
