(module
 (type $none_=>_none (func))
 (import "spectest" "print" (func $module/test))
 (memory $0 0)
 (export "test" (func $module/test))
 (export "memory" (memory $0))
)
