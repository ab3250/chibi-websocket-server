#ChibiWSServer
```c
char *ws_getaddress(int fd);
int ws_sendframe(int fd, const char *msg, uint64_t size, bool broadcast, int type);
int ws_sendframe_txt(int fd, const char *msg, bool broadcast);
int ws_sendframe_bin(int fd, const char *msg, uint64_t size,bool broadcast);
int ws_get_state(int fd);
int ws_close_client(int fd);
int ws_socket(struct ws_events *evs, uint16_t port, int thread_loop);
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
```
called from clang webserver events
```
onopen fd - void onopen(int fd)
onclose fd -  static void close_socket(int fd)
onmessage - void onmessage(int fd, const unsigned char *msg, uint64_t size, int type)
```
called in javascript websocket client events
```
ws.onmessage(evt)
ws.onopen(evt)
wd.onclose()


```
