;; proposals/threads/memory.wast

(module (memory 0 0 shared))
(module (memory 1 2 shared))

;; proposals/threads/exports.wast

(module (memory (export "a") 0 1 shared))
(module (memory 0 1 shared) (export "a" (memory 0)))
(module (memory $a (export "a") 0 1 shared))
(module (memory $a 0 1 shared) (export "a" (memory $a)))
(module (export "a" (memory 0)) (memory 0 1 shared))
(module (export "a" (memory $a)) (memory $a 0 1 shared))


;; proposals/threads/imports.wast

;; Shared Memory

(module (import "spectest" "shared_memory" (memory 1 2 shared)))
