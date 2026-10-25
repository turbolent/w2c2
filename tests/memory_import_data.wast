;; Active segments must reach imported memory before the start function runs.
;; Later segments overwrite earlier segments in declaration order.
(module
  (import "spectest" "memory" (memory 1))
  (import "spectest" "global_i32" (global $offset i32))
  (global $observed (mut i32) (i32.const 0))
  (data (i32.const 4) "\00\ff\7f\80")
  (data (global.get $offset) "ABCD")
  (data (i32.const 667) "xy")

  (func $start
    (global.set $observed (i32.load (global.get $offset))))
  (start $start)
  (func (export "observed") (result i32) (global.get $observed))
  (func (export "load") (param $address i32) (result i32)
    (i32.load8_u (local.get $address)))
)

(assert_return (invoke "observed") (i32.const 0x44797841))
(assert_return (invoke "load" (i32.const 4)) (i32.const 0))
(assert_return (invoke "load" (i32.const 5)) (i32.const 255))
(assert_return (invoke "load" (i32.const 6)) (i32.const 127))
(assert_return (invoke "load" (i32.const 7)) (i32.const 128))
(assert_return (invoke "load" (i32.const 666)) (i32.const 65))
(assert_return (invoke "load" (i32.const 667)) (i32.const 120))
(assert_return (invoke "load" (i32.const 668)) (i32.const 121))
(assert_return (invoke "load" (i32.const 669)) (i32.const 68))

;; Shared imported memory uses the same active-segment initialization.
(module
  (import "spectest" "shared_memory" (memory 1 2 shared))
  (global $observed (mut i32) (i32.const 0))
  (data (i32.const 8) "WASM")
  (func $start
    (global.set $observed (i32.load (i32.const 8))))
  (start $start)
  (func (export "observed") (result i32) (global.get $observed))
)

(assert_return (invoke "observed") (i32.const 0x4d534157))

;; Defined memory must still receive active segments after allocation.
(module
  (memory 1)
  (global $observed (mut i32) (i32.const 0))
  (data (i32.const 8) "WASM")
  (func $start
    (global.set $observed (i32.load (i32.const 8))))
  (start $start)
  (func (export "observed") (result i32) (global.get $observed))
)

(assert_return (invoke "observed") (i32.const 0x4d534157))
