(module
  (type $tuple (func (param i32) (result i32 i64 f32 f64)))
  (import "env" "table" (table 8 funcref))
  (import "env" "host" (func $host (type $tuple)))
  (export "imported" (func $host))
  (global $state (mut i32) (i32.const 10))
  (elem (i32.const 0) $value $host)
  (func $value (export "value") (type $tuple)
    global.get $state local.get 0 i32.add global.set $state
    global.get $state i64.const 20 f32.const -0 f64.const 1.5)
  (func (export "host") (type $tuple) local.get 0 call $host))
