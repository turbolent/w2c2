;; w2c2 regressions supplementing the multi-value cases in the spec tests.
(module
  (global $calls (mut i32) (i32.const 0))
  (func $pair (export "pair") (result i32 i64)
    global.get $calls i32.const 1 i32.add global.set $calls
    i32.const 17 i64.const 29)
  (func (export "calls") (result i32) global.get $calls)
  (func (export "direct") (result i32 i64) call $pair)

  (func $recursive (export "recursive") (param $n i32) (result i32 i64) (local $product i64)
    local.get $n i32.eqz
    if (result i32 i64)
      i32.const 0 i64.const 1
    else
      local.get $n i32.const 1 i32.sub call $recursive
      local.set $product
      i32.const 1 i32.add
      local.get $product local.get $n i64.extend_i32_u i64.mul
    end)

  ;; The taken branch copies overlapping slots.
  ;; The untaken path keeps them.
  (func (export "overlap") (param i32) (result i32 i32 i32)
    block (result i32 i32 i32)
      i32.const 99 i32.const 1 i32.const 2 i32.const 3 local.get 0 br_if 0
      i32.add i32.add i32.add i32.const 5 i32.const 6
    end)

  ;; A loop branch carries parameters even when the loop has no results.
  (func (export "loop-table") (result i32 i64) (local $n i32) (local $sum i64)
    block $exit (result i32 i64)
      i32.const 3 i64.const 0
      loop $again (param i32 i64)
        local.set $sum local.set $n
        f32.const 99 local.get $n i32.const 1 i32.sub local.tee $n
        local.get $sum i64.const 1 i64.add
        local.get $n i32.eqz br_table $again $exit
      end
      unreachable
    end)

  ;; Decode unreachable constructs without reading their operands.
  (func (export "nested-dead") (result i32 i64)
    block $out (result i32 i64)
      i32.const 1 i64.const 2 br $out
      block (param i32 i64) (result i32 i64)
        loop (param i32 i64) (result i32 i64)
          i32.const 1
          if (param i32 i64) (result i32 i64)
            call $pair drop drop
          else
            call $pair drop drop
          end
        end
      end
    end)
  (func (result i32 i64) unreachable i32.add drop))

;; Each assertion must call the function once.
(assert_return (invoke "pair") (i32.const 17) (i64.const 29))
(assert_return (invoke "calls") (i32.const 1))
(assert_return (invoke "direct") (i32.const 17) (i64.const 29))
(assert_return (invoke "calls") (i32.const 2))
(assert_return (invoke "recursive" (i32.const 0)) (i32.const 0) (i64.const 1))
(assert_return (invoke "recursive" (i32.const 1)) (i32.const 1) (i64.const 1))
(assert_return (invoke "recursive" (i32.const 5)) (i32.const 5) (i64.const 120))
(assert_return (invoke "overlap" (i32.const 1)) (i32.const 1) (i32.const 2) (i32.const 3))
(assert_return (invoke "overlap" (i32.const 0)) (i32.const 105) (i32.const 5) (i32.const 6))
(assert_return (invoke "loop-table") (i32.const 0) (i64.const 3))
(assert_return (invoke "nested-dead") (i32.const 1) (i64.const 2))
