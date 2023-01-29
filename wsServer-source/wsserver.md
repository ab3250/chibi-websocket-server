v#ChibiWSServer
```c
char *ws_getaddress(ws_cli_conn_t *client);
int ws_sendframe(
		ws_cli_conn_t *cli, const char *msg, uint64_t size, int type);
int ws_sendframe_txt(ws_cli_conn_t *cli, const char *msg);
int ws_sendframe_bin(ws_cli_conn_t *cli, const char *msg, uint64_t size);
int ws_get_state(ws_cli_conn_t *cli);
int ws_close_client(ws_cli_conn_t *cli);
int ws_socket(struct ws_events *evs, uint16_t port, int thread_loop,
		uint32_t timeout_ms);


```
c stub
```
(c-include "stdio.h")
(c-include "stdbool.h")
(c-include "stdlib.h")
(c-include "stdio.h")
(c-include "unistd.h")
(c-include "ws.h")

(define-c int ws_start())
(define-c int ws_sendframe(int (const string) unsigned-long bool int))
(define-c int ws_sendframe_txt(int (const string) bool))
(define-c int ws_sendframe_bin(int (const string)  unsigned-long bool))
(define-c int ws_close_client(int))
(define-c string ws_getaddress(int))
(define-c int ws_get_state(int))
(define-c int ws_socket(sexp int int))
(define-c-struct ws_events)
(define-c-struct ws_cli_conn_t
    (int client_sock get_fd set_fd)
    (int state get_state set_state))
int getFd (client->client_sock)


```

websocket.so
```
ws_sendframe_txt
ws_sendframe_bin
ws_sendframe
ws_socket
ws_get_state
ws_getaddress
ws_close_client
ws_start
ws_get_fd
ws_get_connections
```
called from clang webserver events
```
onopen fd - void (*onopen)(ws_cli_conn_t *client);
onclose fd -  void (*onclose)(ws_cli_conn_t *client);
onmessage - void (*onmessage)(ws_cli_conn_t *client,
			const unsigned char *msg, uint64_t msg_size, int type);
```
called in javascript websocket client events
```
ws.onmessage(evt)
ws.onopen(evt)
wd.onclose()


```
```
static struct ws_events cli_events;
static struct ws_connection client_socks[MAX_CLIENTS];
static uint32_t timeout;
static pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
static void close_socket(int fd)
static int get_client_state(ws_cli_conn_t *client)
static int set_client_state(ws_cli_conn_t *client, int state)
static ssize_t send_all(
static void close_client(ws_cli_conn_t *client, int lock)
static void *close_timeout(void *p)
static int start_close_timeout(ws_cli_conn_t *client)
static void set_client_address(ws_cli_conn_t *client)
 * @note The returned string is static, no need to free up memory.
static inline int32_t pong_msg_to_int32(uint8_t *msg)
static inline void int32_to_ping_msg(int32_t ping_id, uint8_t *msg)
static void send_ping_close(ws_cli_conn_t *cli, int threshold, int lock)
static inline int is_control_frame(int frame)
static int do_handshake(struct ws_frame_data *wfd)
static int do_close(struct ws_frame_data *wfd, int close_code)
static int do_pong(struct ws_frame_data *wfd, uint64_t frame_size)
static inline int next_byte(struct ws_frame_data *wfd)
static int skip_frame(struct ws_frame_data *wfd, uint64_t frame_size)
static int read_frame(struct ws_frame_data *wfd,
static int next_frame(struct ws_frame_data *wfd)
static void *ws_establishconnection(void *vclient)
static void *ws_accept(void *data)

void (*onopen)(ws_cli_conn_t *client);
void (*onclose)(ws_cli_conn_t *client);
void (*onmessage)(ws_cli_conn_t *client,
			const unsigned char *msg, uint64_t msg_size, int type);
            
int get_handshake_accept(char *wsKey, unsigned char **dest);
int get_handshake_response(char *hsrequest, char **hsresponse);
char *ws_getaddress(ws_cli_conn_t *client);
int ws_sendframe(ws_cli_conn_t *cli, const char *msg, uint64_t size, int type);
int ws_sendframe_txt(ws_cli_conn_t *cli, const char *msg);
int ws_sendframe_bin(ws_cli_conn_t *cli, const char *msg, uint64_t size);
int ws_get_state(ws_cli_conn_t *cli);
int ws_close_client(ws_cli_conn_t *cli);
int ws_socket(struct ws_events *evs, uint16_t port, int thread_loop,uint32_t timeout_ms);
```
```
compile websocket.so
```gcc -lchibi-scheme -Wall -Wextra -O2 -I /usr/local/include -I ./include/ -std=c99 -pedantic -fPIC -pthread -shared chibized-websocket.c libws.a -o websocket.so
```