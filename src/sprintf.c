#include <assert.h>
#include <stdarg.h>

#include "sprintf.h"

struct format {
  char specifier;
  char length;   /* h, l or L */
  char flags[5]; /* -, +, 0, # and whitespace */
  int width;
  int precision;
};

static void eval_format(const char **fmt, struct format *res, va_list vl) {
  return;
}

static int sprintf_character(char **buf, const struct format *f, va_list vl) {
  int err = 0;

  return err;
}

static int sprintf_string(char **buf, const struct format *f, va_list vl) {
  int err = 0;

  return err;
}

static void sprintf_decimal(char **buf, const struct format *f, va_list vl) {
  return;
}

static void sprintf_unsigned(char **buf, const struct format *f, va_list vl) {
  return;
}

static void sprintf_octal(char **buf, const struct format *f, va_list vl) {
  return;
}

static void sprintf_hex(char **buf, const struct format *f, va_list vl) {
  return;
}

static void sprintf_fixed(char **buf, const struct format *f, va_list vl) {
  return;
}

static void sprintf_scientific(char **buf, const struct format *f, va_list vl) {
  return;
}

static void sprintf_floating(char **buf, const struct format *f, va_list vl) {
  return;
}

static void sprintf_pointer(char **buf, const struct format *f, va_list vl) {
  return;
}

static void sprintf_nprinted(int nprinted, const struct format *f, va_list vl) {
  return;
}

static int sprintf_format(char **buf, const struct format *f, int nprinted,
                          va_list vl) {
  int err = 0;

  switch (f->specifier) {
  case '%':
    *(*buf)++ = '%';
    break;
  case 'c':
    err = sprintf_character(buf, f, vl);
    break;
  case 's':
    err = sprintf_string(buf, f, vl);
    break;
  case 'd':
  case 'i':
    sprintf_decimal(buf, f, vl);
    break;
  case 'u':
    sprintf_unsigned(buf, f, vl);
    break;
  case 'o':
    sprintf_octal(buf, f, vl);
    break;
  case 'x':
  case 'X':
    sprintf_hex(buf, f, vl);
    break;
  case 'f':
    sprintf_fixed(buf, f, vl);
    break;
  case 'e':
  case 'E':
    sprintf_scientific(buf, f, vl);
    break;
  case 'g':
  case 'G':
    sprintf_floating(buf, f, vl);
    break;
  case 'p':
    sprintf_pointer(buf, f, vl);
    break;
  case 'n':
    sprintf_nprinted(nprinted, f, vl);
    break;
  default:
    assert(0); /* ERROR */
    break;
  }
  return err;
}

int s21_sprintf(char *buf, const char *fmt, ...) {
  const char *p;
  char *q = buf;
  struct format f;
  int err = 0;
  va_list vl;

  va_start(vl, fmt);
  for (p = fmt; *p && !err; p++) {
    if (*p == '%') {
      eval_format(&p, &f, vl);
      err = sprintf_format(&q, &f, q - buf, vl);
    } else {
      *q++ = *p;
    }
  }
  va_end(vl);
  *q = '\0';
  return err ? err : q - buf;
}
