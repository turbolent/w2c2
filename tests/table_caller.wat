(module
  (type $read (func (result i32)))
  (type $write (func (param i32)))
  (type $step (func (param i32) (result i32)))
  (type $step_alias (func (param i32) (result i32)))
  (table 12 12 funcref)
  (memory 1)
  (global $value (mut i32) (i32.const 90))
  (data (i32.const 0) "\05\00\00\00")
  (elem (i32.const 0) $step)
  (elem (i32.const 5) $float_parameter $wide_result)

  (func $float_parameter (param f32) (result i32)
    (i32.const 42))

  (func $wide_result (param i32) (result i64)
    (i64.const 42))

  (func $state (export "state") (result i32)
    (i32.add
      (i32.mul (global.get $value) (i32.const 1000))
      (i32.load (i32.const 0))))

  (func $step (type $step) (param $delta i32) (result i32)
    (global.set $value (i32.add (global.get $value) (local.get $delta)))
    (i32.store (i32.const 0)
      (i32.add (i32.load (i32.const 0))
        (i32.mul (local.get $delta) (i32.const 2))))
    (call $state))

  (func (export "call") (param $index i32) (param $delta i32) (result i32)
    (call_indirect (type $step) (local.get $delta) (local.get $index)))

  (func (export "call_alias") (param $index i32) (param $delta i32) (result i32)
    (call_indirect (type $step_alias) (local.get $delta) (local.get $index)))

  (func (export "read") (param $index i32) (result i32)
    (call_indirect (type $read) (local.get $index)))

  (func (export "write") (param $index i32) (param $value i32)
    (call_indirect (type $write) (local.get $value) (local.get $index))))
