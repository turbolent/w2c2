(module
  (memory 1 2)
  (table 2 4 funcref)
)

(module
  (memory 1 2 shared)
)

(module
  (import "spectest" "shared_memory" (memory 1 2 shared))
  (import "spectest" "table" (table 10 20 funcref))
  (data (i32.const 12) "data")
)
