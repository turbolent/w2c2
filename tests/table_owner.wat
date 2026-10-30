(module
  (type $step (func (param i32) (result i32)))
  (type $read (func (result i32)))
  (type $write (func (param i32)))
  (import "env" "host" (func $host (type $step)))
  (import "env" "slot" (global $slot i32))
  (import "env" "table" (table 12 12 funcref))
  (memory 1)
  (global $value (mut i32) (i32.const 0))
  (elem (global.get $slot) $step $host $state $write)
  (elem $passive func $step $host)

  (func (export "init-elements") (param i32)
    local.get 0 i32.const 0 i32.const 2 table.init $passive)
  (func (export "drop-elements") elem.drop $passive)
  (func (export "get-ref") (param i32) (result funcref) local.get 0 table.get)
  (func (export "set-ref") (param i32 funcref) local.get 0 local.get 1 table.set)

  (func (export "init") (param $value i32) (param $byte i32)
    (global.set $value (local.get $value))
    (i32.store (i32.const 0) (local.get $byte)))

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

  (func $write (type $write) (param $value i32)
    (global.set $value (local.get $value))
    (i32.store (i32.const 0) (i32.const 6)))

  (func (export "call") (param $index i32) (param $delta i32) (result i32)
    (call_indirect (type $step) (local.get $delta) (local.get $index)))

  (func (export "read") (param $index i32) (result i32)
    (call_indirect (type $read) (local.get $index)))

  (func (export "write") (param $index i32) (param $value i32)
    (call_indirect (type $write) (local.get $value) (local.get $index))))
