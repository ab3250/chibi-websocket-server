(import
    (scheme base)
    (scheme red)
    (chibi time)    
    (websocket)
    (alarm)
    (chibi process))
;;;
;;;
;global variables
(define gblFd -1)
;;;;;

(define (timer_callback)
(display "timer from scheme")
(newline)
(set_timer 30000 #t))

;functions
(define (delay sec)
    (define start (current-seconds))
    (let timeloop ()    
        (if ( < (- (current-seconds) start) sec) (timeloop))))

(define-syntax unless
  (syntax-rules ()
    ((unless test . body)
     (when (not test) . body))))

(define (displayln x)
  (display x)
  (newline))
;;;;;;
;called by clang on webserver events
(define (onopen fd)   
    (set! gblFd fd)
    (displayln (list 'opened fd )))

;called by clang on webserver events
(define (onclose fd)
    (set! gblFd -1)    
    (displayln (list 'closed fd)))

;called by clang on webserver events
(define (onmessage fd msg size type)
    (if (equal? msg "close")
        (ws_close_client fd)
        (begin
            (displayln (list 'frame 'recieved 'client fd))            
            (ws_send_txt msg fd)))) ;echo
;;;;;;

(define (ws_send_txt msg fd)
    (ws_sendframe_txt fd msg #f)
    (displayln (list 'frame 'sent 'client fd)))

(define (ws_close_client fd) 
    (set! gblFd -1) 
    (displayln (list 'closed fd)))
;;;;;;
(define (main args)
    (set_timer 10000 #t)
    (ws_start))
