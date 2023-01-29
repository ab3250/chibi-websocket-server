(import
  (chibi time)  
  (scheme base)
  (scheme red)  
  (websocket)
  (only (srfi 130) string-pad)
  (schemepunk json)
  (delay-seconds)
  (srfi 1)
  (srfi 27))

(define (displayln x)
  (display x)
  (newline))   

(define for-acc (lambda (start end func)
  (let loop ((index start)
             (acc '()))
      (if (> index end)
                      acc   
                      (loop (+ index 1) (func index end acc))))))


(define (knuth-shuffle lst-org)  
  (let loop ((count (length lst-org)) (lst lst-org))      
    (if (zero? count)
    	lst
	(let*   ((j (random-integer count))
		 (new-count (- count 1))
	         (tmp (list-ref lst new-count))
	         (lst2 (list-set lst new-count (list-ref lst j)))
	         (lst3 (list-set lst2 j tmp)))	         
	         (loop new-count lst3)))))

(define (list-set lst idx val)
  (if (null? lst)
    lst
    (cons
      (if (zero? idx)
        val
        (car lst))
      (list-set (cdr lst) (- idx 1) val))))

(define padn (lambda(x y)
  (string-pad (number->string x) y #\0)))

(define (func x end acc)
  (cons (if (< (- x 1)(/ end 2)) "0" "1" ) acc))

(define deck (for-acc 1 80000 func))

(define gblFd 1)

;called by clang on webserver events
(define (onopen fd)   
    (set! gblFd fd)
    (displayln (list 'opened fd )))

;called by clang on webserver events
(define (onclose fd)
    (set! gblFd 1)    
    (displayln (list 'closed fd)))

;called by clang on webserver events
(define (onmessage fd msg size type) 
  (display "debug1")  
  (unless (equal? gblFd 1)(ws_send_txt (json->string deck) fd))  
  (displayln (list 'frame 'recieved 'client fd)))

(define (ws_send_txt msg fd)    
    (ws_sendframe_txt fd msg #f)
    (displayln (list 'frame 'sent 'client fd)))

(define (main args)
    (ws_start))
