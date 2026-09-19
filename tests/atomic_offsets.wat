(module
  (memory 1 1 shared)

  (func (export "notify") (param $address i32) (param $count i32) (result i32)
    (memory.atomic.notify (local.get $address) (local.get $count)))
  (func (export "notify_offset") (param $address i32) (param $count i32) (result i32)
    (memory.atomic.notify offset=16 (local.get $address) (local.get $count)))

  (func (export "wait32") (param $address i32) (param $expected i32) (param $timeout i64) (result i32)
    (memory.atomic.wait32 (local.get $address) (local.get $expected) (local.get $timeout)))
  (func (export "wait32_offset") (param $address i32) (param $expected i32) (param $timeout i64) (result i32)
    (memory.atomic.wait32 offset=12 (local.get $address) (local.get $expected) (local.get $timeout)))

  (func (export "wait64") (param $address i32) (param $expected i64) (param $timeout i64) (result i32)
    (memory.atomic.wait64 (local.get $address) (local.get $expected) (local.get $timeout)))
  (func (export "wait64_offset") (param $address i32) (param $expected i64) (param $timeout i64) (result i32)
    (memory.atomic.wait64 offset=256 (local.get $address) (local.get $expected) (local.get $timeout)))
)
