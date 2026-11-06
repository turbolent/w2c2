;; Discarded SIMD results must not suppress bounds traps.
(module
  (memory 0)
  (func (export "load") (drop (v128.load (i32.const 0))))
  (func (export "splat") (drop (v128.load8_splat (i32.const 0))))
  (func (export "extend") (drop (v128.load8x8_s (i32.const 0))))
  (func (export "lane")
    (drop (v128.load64_lane 0 (i32.const 0) (v128.const i32x4 0 0 0 0)))))

(assert_trap (invoke "load") "out of bounds memory access")
(assert_trap (invoke "splat") "out of bounds memory access")
(assert_trap (invoke "extend") "out of bounds memory access")
(assert_trap (invoke "lane") "out of bounds memory access")

(module
  (memory 1)
  (global $state (export "state") (mut i32) (i32.const 0))
  (func (export "ordered-load") (param $address i32)
    (global.set $state (i32.const 1))
    (drop (v128.load (local.get $address)))
    (global.set $state (i32.const 2)))
  (func (export "offset-load") (param $address i32)
    (drop (v128.load offset=4294967295 (local.get $address)))))

(assert_trap (invoke "ordered-load" (i32.const 65521)) "out of bounds memory access")
(assert_return (get "state") (i32.const 1))
(assert_return (invoke "ordered-load" (i32.const 65520)))
(assert_return (get "state") (i32.const 2))
(assert_trap (invoke "offset-load" (i32.const 1)) "out of bounds memory access")
