(module
  (memory 1 2)
  (table 2 4 funcref)
  (global $offset i32 (i32.mul (i32.const 3) (i32.const 4)))
  (global $function funcref (ref.func 0))
  (global $copy funcref (global.get $function))
  (func (result i32) (i32.const 42))
  (data (global.get $offset) "root")
  (elem (i32.sub (global.get $offset) (i32.const 12)) funcref (global.get $copy))
)

(module
  (memory 1 2 shared)
)

(module
  (import "spectest" "shared_memory" (memory 1 2 shared))
  (import "spectest" "table" (table 10 20 funcref))
  (global $base (import "spectest" "global_i32") i32)
  (global $offset i32 (i32.add (global.get $base) (i32.const 4)))
  (data (global.get $offset) "data")
)
