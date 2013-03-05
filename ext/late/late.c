#include <ruby.h>

/* our new native method; it just returns the string "bonjour!" */
static VALUE late_bonjour(VALUE self) {
  return rb_str_new2("bonjour!");
}

/* ruby calls this to load the extension */
void Init_late(void) {
  /* assume we haven't yet defined 'late' */
  VALUE klass = rb_define_class("Late", rb_cObject);

  /* the late_bonjour function can be called from ruby as Late.bonjour */
  rb_define_singleton_method(klass, "bonjour", late_bonjour, 0);
}
