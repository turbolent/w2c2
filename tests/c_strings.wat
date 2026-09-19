(module $cstrings
  (import "module\22\5c\0a\0d\09\08\0c\017AF\7f\c3\a9??/end\5c"
    "memory\22\5c\0a\0d\09\08\0c\017AF\7f\c3\a9??/end\5c" (memory 1 1))
  (import "module\22\5c\0a\0d\09\08\0c\017AF\7f\c3\a9??/end\5c"
    "table\22\5c\0a\0d\09\08\0c\017AF\7f\c3\a9??/end\5c" (table 1 1 funcref))
  (import "module\22\5c\0a\0d\09\08\0c\017AF\7f\c3\a9??/end\5c"
    "global\22\5c\0a\0d\09\08\0c\017AF\7f\c3\a9??/end\5c" (global $value i32))

  (func $helper (result i32)
    (global.get $value))
  (func (export "") (export "ordinary")
    (export "export\22\5c\0a\0d\09\08\0c\017AF\7f\c3\a9??/end\5c") (result i32)
    (call $helper)))
