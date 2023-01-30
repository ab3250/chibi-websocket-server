(define-library (alarm)
  (import
    (scheme base))
  (export  
    timer_init
    timer_set
    )        	                
(include-shared "alarm"))
