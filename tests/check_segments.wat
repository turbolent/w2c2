(module
  (import "env" "memory" (memory 0))
  (import "env" "table" (table 0 funcref))
  (import "env" "memory_offset" (global $memory_offset i32))
  (import "env" "table_offset" (global $table_offset i32))
  (data (global.get $memory_offset) "abcd")
  (elem (global.get $table_offset) $first $second)
  (func $first)
  (func $second))
