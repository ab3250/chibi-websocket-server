/* Automatically generated by chibi-ffi; version: 0.4 */

#include <chibi/eval.h>

#include "stdio.h"

#include "stdbool.h"

#include "stdlib.h"

#include "stdio.h"

#include "unistd.h"

#include "ws.h"
/*
types: (ws_connection ws_events)
enums: ()
*/

sexp sexp_ws_socket_stub (sexp ctx, sexp self, sexp_sint_t n, sexp arg0, sexp arg1, sexp arg2, sexp arg3) {
  sexp res;
  if (! sexp_exact_integerp(arg1))
    return sexp_type_exception(ctx, self, SEXP_FIXNUM, arg1);
  if (! sexp_exact_integerp(arg2))
    return sexp_type_exception(ctx, self, SEXP_FIXNUM, arg2);
  if (! sexp_exact_integerp(arg3))
    return sexp_type_exception(ctx, self, SEXP_FIXNUM, arg3);
  res = sexp_make_integer(ctx, ws_socket(arg0, sexp_sint_value(arg1), sexp_sint_value(arg2), sexp_uint_value(arg3)));
  return res;
}

sexp sexp_ws_get_state_stub (sexp ctx, sexp self, sexp_sint_t n, sexp arg0) {
  sexp res;
  if (! (sexp_pointerp(arg0) && (sexp_pointer_tag(arg0) == sexp_unbox_fixnum(sexp_opcode_arg1_type(self)))))
    return sexp_type_exception(ctx, self, sexp_unbox_fixnum(sexp_opcode_arg1_type(self)), arg0);
  res = sexp_make_integer(ctx, ws_get_state((struct ws_connection*)sexp_cpointer_value(arg0)));
  return res;
}

sexp sexp_ws_getaddress_stub (sexp ctx, sexp self, sexp_sint_t n, sexp arg0) {
  sexp res;
  if (! (sexp_pointerp(arg0) && (sexp_pointer_tag(arg0) == sexp_unbox_fixnum(sexp_opcode_arg1_type(self)))))
    return sexp_type_exception(ctx, self, sexp_unbox_fixnum(sexp_opcode_arg1_type(self)), arg0);
  res = sexp_c_string(ctx, ws_getaddress((struct ws_connection*)sexp_cpointer_value(arg0)), -1);
  return res;
}

sexp sexp_ws_close_client_stub (sexp ctx, sexp self, sexp_sint_t n, sexp arg0) {
  sexp res;
  if (! (sexp_pointerp(arg0) && (sexp_pointer_tag(arg0) == sexp_unbox_fixnum(sexp_opcode_arg1_type(self)))))
    return sexp_type_exception(ctx, self, sexp_unbox_fixnum(sexp_opcode_arg1_type(self)), arg0);
  res = sexp_make_integer(ctx, ws_close_client((struct ws_connection*)sexp_cpointer_value(arg0)));
  return res;
}

sexp sexp_ws_sendframe_bin_stub (sexp ctx, sexp self, sexp_sint_t n, sexp arg0, sexp arg1, sexp arg2) {
  sexp res;
  if (! (sexp_pointerp(arg0) && (sexp_pointer_tag(arg0) == sexp_unbox_fixnum(sexp_opcode_arg1_type(self)))))
    return sexp_type_exception(ctx, self, sexp_unbox_fixnum(sexp_opcode_arg1_type(self)), arg0);
  if (! sexp_stringp(arg1))
    return sexp_type_exception(ctx, self, SEXP_STRING, arg1);
  if (! sexp_exact_integerp(arg2))
    return sexp_type_exception(ctx, self, SEXP_FIXNUM, arg2);
  res = sexp_make_integer(ctx, ws_sendframe_bin((struct ws_connection*)sexp_cpointer_value(arg0), sexp_string_data(arg1), sexp_uint_value(arg2)));
  return res;
}

sexp sexp_ws_sendframe_txt_stub (sexp ctx, sexp self, sexp_sint_t n, sexp arg0, sexp arg1) {
  sexp res;
  if (! (sexp_pointerp(arg0) && (sexp_pointer_tag(arg0) == sexp_unbox_fixnum(sexp_opcode_arg1_type(self)))))
    return sexp_type_exception(ctx, self, sexp_unbox_fixnum(sexp_opcode_arg1_type(self)), arg0);
  if (! sexp_stringp(arg1))
    return sexp_type_exception(ctx, self, SEXP_STRING, arg1);
  res = sexp_make_integer(ctx, ws_sendframe_txt((struct ws_connection*)sexp_cpointer_value(arg0), sexp_string_data(arg1)));
  return res;
}

sexp sexp_ws_sendframe_stub (sexp ctx, sexp self, sexp_sint_t n, sexp arg0, sexp arg1, sexp arg2, sexp arg3) {
  sexp res;
  if (! (sexp_pointerp(arg0) && (sexp_pointer_tag(arg0) == sexp_unbox_fixnum(sexp_opcode_arg1_type(self)))))
    return sexp_type_exception(ctx, self, sexp_unbox_fixnum(sexp_opcode_arg1_type(self)), arg0);
  if (! sexp_stringp(arg1))
    return sexp_type_exception(ctx, self, SEXP_STRING, arg1);
  if (! sexp_exact_integerp(arg2))
    return sexp_type_exception(ctx, self, SEXP_FIXNUM, arg2);
  if (! sexp_exact_integerp(arg3))
    return sexp_type_exception(ctx, self, SEXP_FIXNUM, arg3);
  res = sexp_make_integer(ctx, ws_sendframe((struct ws_connection*)sexp_cpointer_value(arg0), sexp_string_data(arg1), sexp_uint_value(arg2), sexp_sint_value(arg3)));
  return res;
}

sexp sexp_ws_get_connections_stub (sexp ctx, sexp self, sexp_sint_t n) {
  sexp res;
  res = ws_get_connections();
  return res;
}

sexp sexp_ws_get_fd_stub (sexp ctx, sexp self, sexp_sint_t n, sexp arg0) {
  sexp res;
  if (! (sexp_pointerp(arg0) && (sexp_pointer_tag(arg0) == sexp_unbox_fixnum(sexp_opcode_arg1_type(self)))))
    return sexp_type_exception(ctx, self, sexp_unbox_fixnum(sexp_opcode_arg1_type(self)), arg0);
  res = sexp_make_integer(ctx, ws_get_fd((struct ws_connection*)sexp_cpointer_value(arg0)));
  return res;
}

sexp sexp_ws_start_stub (sexp ctx, sexp self, sexp_sint_t n) {
  sexp res;
  res = sexp_make_integer(ctx, ws_start());
  return res;
}

sexp sexp_ws_connection_get_client_sock (sexp ctx, sexp self, sexp_sint_t n, sexp x) {
  if (! (sexp_pointerp(x) && (sexp_pointer_tag(x) == sexp_unbox_fixnum(sexp_opcode_arg1_type(self)))))
    return sexp_type_exception(ctx, self, sexp_unbox_fixnum(sexp_opcode_arg1_type(self)), x);
  return sexp_make_integer(ctx, ((struct ws_connection*)sexp_cpointer_value(x))->client_sock);
}

sexp sexp_ws_connection_set_client_sock (sexp ctx, sexp self, sexp_sint_t n, sexp x, sexp v) {
  if (! (sexp_pointerp(x) && (sexp_pointer_tag(x) == sexp_unbox_fixnum(sexp_opcode_arg1_type(self)))))
    return sexp_type_exception(ctx, self, sexp_unbox_fixnum(sexp_opcode_arg1_type(self)), x);
  if (! sexp_exact_integerp(v))
    return sexp_type_exception(ctx, self, SEXP_FIXNUM, v);
  ((struct ws_connection*)sexp_cpointer_value(x))->client_sock = sexp_sint_value(v);
  return SEXP_VOID;
}


sexp sexp_init_library (sexp ctx, sexp self, sexp_sint_t n, sexp env, const char* version, const sexp_abi_identifier_t abi) {
  sexp sexp_ws_connection_type_obj;
  sexp sexp_ws_events_type_obj;
  sexp_gc_var3(name, tmp, op);
  if (!(sexp_version_compatible(ctx, version, sexp_version)
        && sexp_abi_compatible(ctx, abi, SEXP_ABI_IDENTIFIER)))
    return SEXP_ABI_ERROR;
  sexp_gc_preserve3(ctx, name, tmp, op);
  name = sexp_c_string(ctx, "ws_connection", -1);
  sexp_ws_connection_type_obj = sexp_register_c_type(ctx, name, sexp_finalize_c_type);
  tmp = sexp_string_to_symbol(ctx, name);
  sexp_env_define(ctx, env, tmp, sexp_ws_connection_type_obj);
  sexp_type_slots(sexp_ws_connection_type_obj) = SEXP_NULL;
  sexp_push(ctx, sexp_type_slots(sexp_ws_connection_type_obj), sexp_intern(ctx, "state", -1));
  sexp_push(ctx, sexp_type_slots(sexp_ws_connection_type_obj), sexp_intern(ctx, "client_sock", -1));
  sexp_type_getters(sexp_ws_connection_type_obj) = sexp_make_vector(ctx, SEXP_TWO, SEXP_FALSE);
  sexp_type_setters(sexp_ws_connection_type_obj) = sexp_make_vector(ctx, SEXP_TWO, SEXP_FALSE);
  name = sexp_c_string(ctx, "ws_events", -1);
  sexp_ws_events_type_obj = sexp_register_c_type(ctx, name, sexp_finalize_c_type);
  tmp = sexp_string_to_symbol(ctx, name);
  sexp_env_define(ctx, env, tmp, sexp_ws_events_type_obj);
  op = sexp_define_foreign(ctx, env, "set_sock", 2, sexp_ws_connection_set_client_sock);
  if (sexp_opcodep(op)) {
    sexp_opcode_return_type(op) = sexp_make_fixnum(SEXP_FIXNUM);
    sexp_opcode_arg1_type(op) = sexp_make_fixnum(sexp_type_tag(sexp_ws_connection_type_obj));
    sexp_opcode_arg2_type(op) = sexp_make_fixnum(SEXP_FIXNUM);
  }
  if (sexp_vectorp(sexp_type_setters(sexp_ws_connection_type_obj))) sexp_vector_set(sexp_type_setters(sexp_ws_connection_type_obj), SEXP_ZERO, op);
  op = sexp_define_foreign(ctx, env, "get_sock", 1, sexp_ws_connection_get_client_sock);
  if (sexp_opcodep(op)) {
    sexp_opcode_return_type(op) = sexp_make_fixnum(SEXP_FIXNUM);
    sexp_opcode_arg1_type(op) = sexp_make_fixnum(sexp_type_tag(sexp_ws_connection_type_obj));
  }
  if (sexp_vectorp(sexp_type_getters(sexp_ws_connection_type_obj))) sexp_vector_set(sexp_type_getters(sexp_ws_connection_type_obj), SEXP_ZERO, op);
  op = sexp_define_foreign(ctx, env, "ws_socket", 4, sexp_ws_socket_stub);
  if (sexp_opcodep(op)) {
    sexp_opcode_return_type(op) = sexp_make_fixnum(SEXP_FIXNUM);
    sexp_opcode_arg2_type(op) = sexp_make_fixnum(SEXP_FIXNUM);
    sexp_opcode_arg3_type(op) = sexp_make_fixnum(SEXP_FIXNUM);
    sexp_opcode_argn_type(op) = sexp_make_vector(ctx, SEXP_ONE, sexp_make_fixnum(SEXP_OBJECT));
    sexp_vector_set(sexp_opcode_argn_type(op), SEXP_ZERO, sexp_make_fixnum(SEXP_FIXNUM));
  }
  op = sexp_define_foreign(ctx, env, "ws_get_state", 1, sexp_ws_get_state_stub);
  if (sexp_opcodep(op)) {
    sexp_opcode_return_type(op) = sexp_make_fixnum(SEXP_FIXNUM);
    sexp_opcode_arg1_type(op) = sexp_make_fixnum(sexp_type_tag(sexp_ws_connection_type_obj));
  }
  op = sexp_define_foreign(ctx, env, "ws_getaddress", 1, sexp_ws_getaddress_stub);
  if (sexp_opcodep(op)) {
    sexp_opcode_return_type(op) = sexp_make_fixnum(SEXP_STRING);
    sexp_opcode_arg1_type(op) = sexp_make_fixnum(sexp_type_tag(sexp_ws_connection_type_obj));
  }
  op = sexp_define_foreign(ctx, env, "ws_close_client", 1, sexp_ws_close_client_stub);
  if (sexp_opcodep(op)) {
    sexp_opcode_return_type(op) = sexp_make_fixnum(SEXP_FIXNUM);
    sexp_opcode_arg1_type(op) = sexp_make_fixnum(sexp_type_tag(sexp_ws_connection_type_obj));
  }
  op = sexp_define_foreign(ctx, env, "ws_sendframe_bin", 3, sexp_ws_sendframe_bin_stub);
  if (sexp_opcodep(op)) {
    sexp_opcode_return_type(op) = sexp_make_fixnum(SEXP_FIXNUM);
    sexp_opcode_arg1_type(op) = sexp_make_fixnum(sexp_type_tag(sexp_ws_connection_type_obj));
    sexp_opcode_arg2_type(op) = sexp_make_fixnum(SEXP_STRING);
    sexp_opcode_arg3_type(op) = sexp_make_fixnum(SEXP_FIXNUM);
  }
  op = sexp_define_foreign(ctx, env, "ws_sendframe_txt", 2, sexp_ws_sendframe_txt_stub);
  if (sexp_opcodep(op)) {
    sexp_opcode_return_type(op) = sexp_make_fixnum(SEXP_FIXNUM);
    sexp_opcode_arg1_type(op) = sexp_make_fixnum(sexp_type_tag(sexp_ws_connection_type_obj));
    sexp_opcode_arg2_type(op) = sexp_make_fixnum(SEXP_STRING);
  }
  op = sexp_define_foreign(ctx, env, "ws_sendframe", 4, sexp_ws_sendframe_stub);
  if (sexp_opcodep(op)) {
    sexp_opcode_return_type(op) = sexp_make_fixnum(SEXP_FIXNUM);
    sexp_opcode_arg1_type(op) = sexp_make_fixnum(sexp_type_tag(sexp_ws_connection_type_obj));
    sexp_opcode_arg2_type(op) = sexp_make_fixnum(SEXP_STRING);
    sexp_opcode_arg3_type(op) = sexp_make_fixnum(SEXP_FIXNUM);
    sexp_opcode_argn_type(op) = sexp_make_vector(ctx, SEXP_ONE, sexp_make_fixnum(SEXP_OBJECT));
    sexp_vector_set(sexp_opcode_argn_type(op), SEXP_ZERO, sexp_make_fixnum(SEXP_FIXNUM));
  }
  op = sexp_define_foreign(ctx, env, "ws_get_connections", 0, sexp_ws_get_connections_stub);
  op = sexp_define_foreign(ctx, env, "ws_get_fd", 1, sexp_ws_get_fd_stub);
  if (sexp_opcodep(op)) {
    sexp_opcode_return_type(op) = sexp_make_fixnum(SEXP_FIXNUM);
    sexp_opcode_arg1_type(op) = sexp_make_fixnum(sexp_type_tag(sexp_ws_connection_type_obj));
  }
  op = sexp_define_foreign(ctx, env, "ws_start", 0, sexp_ws_start_stub);
  if (sexp_opcodep(op)) {
    sexp_opcode_return_type(op) = sexp_make_fixnum(SEXP_FIXNUM);
  }
  sexp_gc_release3(ctx);
  return SEXP_VOID;
}
