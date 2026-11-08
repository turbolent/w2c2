(module
  (import "env" "memory" (memory 1 2 shared))
  (func (export "read") (result i32)
    (i32.atomic.store (i32.const 4) (i32.const 1))
    (loop $wait
      (br_if $wait (i32.eqz (i32.atomic.load (i32.const 0)))))
    (i32.load (i32.const 65536))))
