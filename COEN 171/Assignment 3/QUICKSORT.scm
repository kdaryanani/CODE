;Karan Daryanani
;Programming Languages
;COEN 171
;Pantoja

;This is an implemenentation of Quicksort in Scheme
;There are 2 ways to run the program. I used the online Compiler on repl.it and I implemented 2 ways to run it.
;The first is entering in the 10 elements you would like sorted
;The second way is to call quicksort() on a set of 10 integers
;Quicksort is a divide and conquire sorting method with a average sort time of O(nlogn) and a worst case of O(n^2)

;There were 3 functions that are necessary to solving the problem. THe first chooses the pivot and sorts elements around the pivot, then the pivot is placed.

;The second function is used to partition each set on each side of the pivot.

;The third function is used to call quicksort on each array  and use the partition and pivot methods to sort the array.

(define pivot (lambda (array)
    (cond ((null? array) 'done)
    ((null? (cdr array)) 'done)
    ((<= (car array) (cadr array)) (pivot (cdr array)))
    (#t (car array)))))

(define divide (lambda (start array pivot1 pivot2)
    (if (null? array) (list pivot1 pivot2)
        (if (< (car array) start) (divide start (cdr array) (cons (car array) pivot1) pivot2)
            (divide start (cdr array) pivot1 (cons (car array) pivot2))))))

(define (quicksort array)
    (let ((piv (pivot array)))
        (if (equal? piv 'done) array
            (let ((parts (partition piv array () ())))
                (append (quicksort (car parts))
                    (quicksort (cadr parts)))))))

(display "Now enter the elements you would like sorted. Each integer should be followed with a hit of the return/enter key \n")

(define number1 (read))
(define number2 (read))
(define number3 (read))
(define number4 (read))
(define number5 (read))
(define number6 (read))
(define number7 (read))
(define number8 (read))
(define number9 (read))
(define number10 (read))

(define array (list number1 number2 number3 number4 number5 number6 number7 number8 number9 number10))
(display( quicksort array ))

;(quicksort '(6 4 7 9 2 1 6 7 4 4))


