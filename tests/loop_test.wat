(module
  (memory 1)

  (func (export "spin") (result i32)
    (loop $again (br $again))
    (i32.const 42))

  (func $conditional (export "conditional") (param $value i32) (result i32)
    (block $done
      (loop $again
        (br_if $done (i32.eq (local.get $value) (i32.const 1)))
        (local.set $value (i32.shl (local.get $value) (i32.const 1)))
        (br $again)))
    (i32.const 42))

  (func (export "caller") (param $value i32) (result i32)
    (drop (call $conditional (local.get $value)))
    (i32.const 43))

  (func (export "sum") (result i32) (local $index i32) (local $sum i32)
    (loop $again
      (local.set $sum (i32.add
        (local.get $sum)
        (i32.load (i32.shl (local.get $index) (i32.const 2)))))
      (local.set $index (i32.add (local.get $index) (i32.const 1)))
      (br_if $again (i32.lt_u (local.get $index) (i32.const 1024))))
    (local.get $sum)))
