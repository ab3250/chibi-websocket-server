(import
    (scheme base)
    (scheme red)
    (chibi time)
    (sudokuWs)
    (chibi io) 
    (delay)
    (scheme vector)    
    (websocket))
;;;
;;;
;global variables
(define gblFd -1)
;;;;;
;functions
(define (lock-buttons)
  (ws_send_txt "{\"type\":\"lock\"}" gblFd))

(define (unlock-buttons)
  (ws_send_txt "{\"type\":\"unlock\"}" gblFd))

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

(define (solve grid)
  (let/ec return
    (nested-loop row 0 8 col 0 8
        (if (=(vector-ref grid (row_col->cell row col)) 0)
          (let num-loop ((num 1))                             
            (if (not (= 10 num))
              (begin            
                (if (possible? row col num grid)
                  (begin
                    (vector-set! grid (row_col->cell row col) num)                    
                    (ws_send_txt 
                      (grid-string grid) gblFd)
                    (solve grid)
                    (when (no-zeros-left? grid)(return))
                    (vector-set! grid (row_col->cell row col) 0)))
                (num-loop (+ 1 num)))
              (return)))))))

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
        (cond 
            ((string=? msg "button1")(solve (vector-copy grid1)))
            ((string=? msg "button2")(solve (vector-copy grid2)))
            ((string=? msg "button3")(solve (vector-copy grid3)))
            ((string=? msg "button4")(ws_send_txt (grid-string grid1) gblFd))
            ((string=? msg "button5")(ws_send_txt (grid-string grid2) gblFd))
            ((string=? msg "button6")(ws_send_txt (grid-string grid3) gblFd))))
;;;;;;

(define (ws_send_txt msg fd)    
    (ws_sendframe_txt fd msg #f)
    (displayln (list 'frame 'sent 'client fd)))

(define (ws_close_client fd) 
    (set! gblFd -1) 
    (displayln (list 'closed fd)))
;;;;;;



(define (main args)  
(ws_start))