(module
  (memory (export "memory") 32)
  ;; Four independent wrapping multiply-add reductions over two arrays.
  (func (export "dot") (param $a i32) (param $b i32) (param $count i32) (result v128)
    (local $sum v128)
    (block $done
      (loop $loop
        (br_if $done (i32.eqz (local.get $count)))
        (local.set $sum (i32x4.add (local.get $sum)
          (i32x4.mul (v128.load (local.get $a)) (v128.load (local.get $b)))))
        (local.set $a (i32.add (local.get $a) (i32.const 16)))
        (local.set $b (i32.add (local.get $b) (i32.const 16)))
        (local.set $count (i32.sub (local.get $count) (i32.const 1)))
        (br $loop)))
    (local.get $sum))
)
