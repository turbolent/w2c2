(module
  (type $unused (func (result i32)))
  (type $tuple (func (param i32) (result i32 i64 f32 f64)))
  (type $alias (func (param i32) (result i32 i64 f32 f64)))
  (import "env" "table" (table 8 funcref))
  (import "owner" "value" (func $value (type $tuple)))
  (func (export "direct") (type $tuple) local.get 0 call $value)
  (func (export "indirect") (param i32 i32) (result i32 i64 f32 f64)
    local.get 1 local.get 0 call_indirect (type $alias)))
