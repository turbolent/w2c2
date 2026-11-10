(module
  (type $grow (func (param i32) (result i32)))
  (import "env" "grow" (func $host (type $grow)))
  (import "env" "memory" (memory 1 16))
  (table 2 funcref)
  (elem (i32.const 0) $relay $host)

  (func $grow (type $grow) (param i32) (result i32)
    (memory.grow (local.get 0)))
  (func $relay (type $grow) (param i32) (result i32)
    (call $grow (local.get 0)))

  (func (export "grow") (param i32) (result i32)
    (drop (i32x4.extract_lane 0 (v128.load (i32.const 0))))
    (drop (memory.grow (local.get 0)))
    (i32x4.extract_lane 0 (v128.load (i32.const 0))))

  (func (export "direct") (param i32) (result i32)
    (drop (i32x4.extract_lane 0 (v128.load (i32.const 0))))
    (drop (call $relay (local.get 0)))
    (v128.store32_lane 0 (i32.const 65536) (i32x4.splat (i32.const 29)))
    (i32.add
      (i32x4.extract_lane 0 (v128.load (i32.const 0)))
      (i32x4.extract_lane 0 (v128.load (i32.const 65536)))))

  (func (export "host") (param i32) (result i32)
    (drop (i32x4.extract_lane 0 (v128.load (i32.const 0))))
    (drop (call $host (local.get 0)))
    (v128.store32_lane 0 (i32.const 65536) (i32x4.splat (i32.const 29)))
    (i32.add
      (i32x4.extract_lane 0 (v128.load (i32.const 0)))
      (i32x4.extract_lane 0 (v128.load (i32.const 65536)))))

  (func (export "late") (param i32) (result i32)
    (drop (call $host (local.get 0)))
    (i32x4.extract_lane 0 (v128.load (i32.const 0))))

  (func (export "indirect") (param i32) (result i32)
    (drop (i32x4.extract_lane 0 (v128.load (i32.const 0))))
    (drop (call_indirect (type $grow) (i32.const 1) (local.get 0)))
    (v128.store32_lane 0 (i32.const 65536) (i32x4.splat (i32.const 29)))
    (i32.add
      (i32x4.extract_lane 0 (v128.load (i32.const 0)))
      (i32x4.extract_lane 0 (v128.load (i32.const 65536)))))

  (func (export "branch") (param i32) (result i32)
    (drop (i32x4.extract_lane 0 (v128.load (i32.const 0))))
    (if (local.get 0)
      (then (drop (call $host (i32.const 1))))
      (else (drop (memory.grow (i32.const 1)))))
    (i32x4.extract_lane 0 (v128.load (i32.const 0))))

  (func $pair (param i32) (result i32 i32)
    (memory.grow (local.get 0))
    (i32.const 42))
  (func (export "multi") (param i32) (result i32)
    (drop (i32x4.extract_lane 0 (v128.load (i32.const 0))))
    (call $pair (local.get 0)) drop drop
    (i32x4.extract_lane 0 (v128.load (i32.const 0))))

  (func (export "loop") (param i32) (result i32) (local $sum i32)
    (block $done
      (br_if $done (i32.eqz (local.get 0)))
      (loop $again
        (v128.store32_lane 0 (i32.const 0) (i32x4.splat (i32.const 17)))
        (drop (call $host (i32.const 1)))
        (local.set $sum (i32.add
          (local.get $sum)
          (i32x4.extract_lane 0 (v128.load (i32.const 0)))))
        (local.set 0 (i32.sub (local.get 0) (i32.const 1)))
        (br_if $again (local.get 0))))
    (local.get $sum)))
