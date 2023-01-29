(import
    (scheme base)
    (scheme red)
    (chibi time)    
    (websocket)
    (chibi process))
;;;
;;;
;global variables
(define gblFd -1)
;;;;;
;functions
(define (delay sec)
    (define start (current-seconds))
    (let timeloop ()    
        (if ( < (- (current-seconds) start) sec) (timeloop))))

(define-syntax unless
  (syntax-rules ()
    ((unless test . body)
     (when (not test) . body))))
(define clock 0)
  (define handler #f) 

 (define start-timer
    (lambda (ticks new-handler)
      (set! handler new-handler)
      (set! clock ticks))) 

(define (displayln x)
  (display x)
  (newline))

(define (signalhandler)
  (displayln "signal alarm"))
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
    (set-signal-action! signal/alarm signalhandler)
        (start-timer 100000 signalhandler)
    (ws_start)
    (let loop2 ((count2 0))   
        (delay 1)                                 
        (unless (equal? gblFd -1)(ws_send_txt (number->string count2) gblFd))        
        (loop2 (+ count2 1))))
