;; a procedure of computing factorial
(define f (lambda (x) (if (= x 1) 1 (* x (f (- x 1))))))

;; tests
(f 12)
(f 30)
(f 97)
