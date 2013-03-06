#include <ruby.h>
#include <time.h>

// Outputs Tue, 05 Mar 2013 16:58:29 GMT
const VALUE late_httpdate(VALUE self, VALUE rb_epoch) {
  time_t epoch = FIX2LONG(rb_epoch);
  struct tm * timeinfo;
  char buffer[80];
  timeinfo = gmtime(&epoch);
  strftime(buffer, 80, "%a, %d %b %Y %H:%M:%S GMT", timeinfo);
  return rb_str_new2(buffer);
}

const VALUE late_pp(VALUE self, VALUE rb_epoch, VALUE rb_format) {
  time_t epoch = FIX2LONG(rb_epoch);
  char * format = RSTRING_PTR(rb_format);
  struct tm * timeinfo = gmtime(&epoch);
  int buffer_length = RSTRING_LEN(rb_format) + 40;
  char buffer[buffer_length];
  timeinfo = gmtime(&epoch);
  strftime(buffer, buffer_length, format, timeinfo);
  return rb_str_new2(buffer);
}

/* our new native method; it just returns the seconds since epoch" */
static VALUE late_epoch(VALUE self) {
  time_t current_time = time(NULL);
  return INT2FIX(current_time);
}

/* ruby calls this to load the extension */
void Init_late(void) {
  /* assume we haven't yet defined 'late' */
  VALUE klass = rb_define_class("Late", rb_cObject);

  rb_define_singleton_method(klass, "epoch", late_epoch, 0);
  rb_define_singleton_method(klass, "pp", late_pp, 2);
  rb_define_singleton_method(klass, "httpdate", late_httpdate, 1);
}
