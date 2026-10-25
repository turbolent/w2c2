(module
  (import "env\00a" "function\00a" (func $a (result i32)))
  (import "env\00a" "function\00b" (func $b (result i32)))
  (import "module\00a" "global\00a" (global $first i32))
  (import "module\00b" "global\00a" (global $second i32))
  (import "module\00b" "global\00b" (global $third i32))
  (import "module\00" "memory\00" (memory 1 1))
  (import "module\00" "table\00" (table 1 1 funcref))

  (func (export "value") (result i32) (global.get $first))
  (func (export "value\00") (result i32) (global.get $second))
  (func (export "value\00a") (result i32) (global.get $third))
  (export "value\00b" (func $a))
  (export "\00" (func $b)))
