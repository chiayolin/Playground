(define (abs x)
  (cond ((> x 0) x)
        ((= x 0) 0)
        ((< x 0) (- x))))
 
(define (print i t)
  (display i)
  (display " ")
  (display t) 
  (newline))

(print "(abs  3)" (abs  3))
(print "(abs -5)" (abs -5))
(print "(abs  0)" (abs  0))

(define (test x)
  (display x)
  (newline))

(test "hello, world")
