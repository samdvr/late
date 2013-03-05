#include <ruby.h>
#include <time.h>

/* our new native method; it just returns the seconds since epoch" */
static VALUE late_epoch(VALUE self) {
  time_t current_time = time(NULL);
  return INT2FIX(current_time);
}

/* ruby calls this to load the extension */
void Init_late(void) {
  /* assume we haven't yet defined 'late' */
  VALUE klass = rb_define_class("Late", rb_cObject);

  /* the late_bonjour function can be called from ruby as Late.bonjour */
  rb_define_singleton_method(klass, "epoch", late_epoch, 0);
}
