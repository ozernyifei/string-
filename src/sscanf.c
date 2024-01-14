#include <assert.h>
#include <ctype.h>
#include <stdarg.h>
#include <stdlib.h>

#include "sscanf.h"

enum { EOF = -1, OK, ERROR };

struct format {
  char specifier;
  char length; /* h, l or L */
  char flag;   /* '*' */
  int width;
};

static void eval_format(const char **fmt, struct format *res) {
  (*fmt)++;
  if (**fmt == '*') {
    res->flag = '*';
    (*fmt)++;
  } else {
    res->flag = '\0';
  }
  res->width = strtol(*fmt, (char **)fmt, 10);
  if (**fmt == 'h' || **fmt == 'l' || **fmt == 'L') {
    res->length = **fmt;
    (*fmt)++;
  } else {
    res->length = '\0';
  }
  res->specifier = **fmt;
}

static void skip_spaces(const char **buf) {
  while (isspace(**buf)) {
    (*buf)++;
  }
}

static int sscanf_character(const char **buf, const struct format *f,
                            va_list vl) {
  int err;

  if (!f->length && **buf) {
    char *p;
    if (!f->flag) {
      p = va_arg(vl, char*);
    }
    for (int i = 0; i < f->width; i++) {
      if (!f->flag) {
        *p = **buf; 
      }
      (*buf)++;
    }
  }
  else if (f->length == 'l' && **buf) {
    wchar_t *p;
    if (!f->flag) {
      p = va_arg(vl, wchar_t*);
    }
    else {
      p = NULL;
    }
    int length = s21_strlen(*buf);
    for (int i = 0; i < f->width; i++) {  
      int n = mbtowc(p, *buf, length);
      (*buf) += n;
    }
  }
  if (!**buf) {
    err = EOF;
  }
  else {
    err = OK;
  }

  return err;
}

static int sscanf_string(const char **buf, const struct format *f, va_list vl) {
   int err;

  /* Условия остановки: isspace, /0, n > specifier width */
  if (!f->length && **buf) {
    char *p;
    if (!f->flag) {
      p = va_arg(vl, char*);
    }
    for (int i = 0; i < f->width; i++) {
      if (!f->flag) {
        *p = **buf; 
      }
      (*buf)++;
    }
  }
  else if (f->length == 'l' && **buf) {
    wchar_t *p;
    if (!f->flag) {
      p = va_arg(vl, wchar_t*);
    }
    else {
      p = NULL;
    }
    int length = s21_strlen(*buf);
    for (int i = 0; i < f->width; i++) {  
      int n = mbtowc(p, *buf, length);
      (*buf) += n;
    }
  }
  if (!**buf) {
    err = EOF;
  }
  else {
    err = OK;
  }

  return err;
}

static int sscanf_decimal(const char **buf, const struct format *f,
                          va_list vl) {
  int err;
  long n;
  char *end;

  n = strtol(*buf, &end, 10);

  if (!f->flag && !f->length) {
    int *p = va_arg(vl, int *);
    *p = n;
  } else if (!f->flag && f->length == 'h') {
    short *p = va_arg(vl, short *);
    *p = n;
  } else if (!f->flag && f->length == 'l') {
    long *p = va_arg(vl, long *);
    *p = n;
  }

  if (!**buf) {
    err = EOF;
  } else if (end == *buf) {
    err = ERROR;
  } else {
    err = OK;
  }
  *buf = end;
  return err;
}

static int sscanf_integer(const char **buf, const struct format *f,
                          va_list vl) {
  int err;
  long n;
  char *end;

  n = strtol(*buf, &end, 0);

  if (!f->flag && !f->length) {
    int *p = va_arg(vl, int *);
    *p = n;
  } else if (!f->flag && f->length == 'h') {
    short *p = va_arg(vl, short *);
    *p = n;
  } else if (!f->flag && f->length == 'l') {
    long *p = va_arg(vl, long *);
    *p = n;
  }

  if (!**buf) {
    err = EOF;
  } else if (end == *buf) {
    err = ERROR;
  } else {
    err = OK;
  }
  *buf = end;
  return err;
}

static int sscanf_unsigned(const char **buf, const struct format *f,
                           va_list vl) {
  int err;
  unsigned long n;
  char *end;

  n = strtoul(*buf, &end, 10);

  if (!f->flag && !f->length) {
    int *p = va_arg(vl, int *);
    *p = n;
  } else if (!f->flag && f->length == 'h') {
    short *p = va_arg(vl, short *);
    *p = n;
  } else if (!f->flag && f->length == 'l') {
    long *p = va_arg(vl, long *);
    *p = n;
  }

  if (!**buf) {
    err = EOF;
  } else if (end == *buf) {
    err = ERROR;
  } else {
    err = OK;
  }
  *buf = end;
  return err;
}

static int sscanf_octal(const char **buf, const struct format *f, va_list vl) {
  int err;
  unsigned long n;
  char *end;

  n = strtoul(*buf, &end, 8);

  if (!f->flag && !f->length) {
    int *p = va_arg(vl, int *);
    *p = n;
  } else if (!f->flag && f->length == 'h') {
    short *p = va_arg(vl, short *);
    *p = n;
  } else if (!f->flag && f->length == 'l') {
    long *p = va_arg(vl, long *);
    *p = n;
  }

  if (!**buf) {
    err = EOF;
  } else if (end == *buf) {
    err = ERROR;
  } else {
    err = OK;
  }
  *buf = end;
  return err;
}

static int sscanf_hex(const char **buf, const struct format *f, va_list vl) {
  int err;
  unsigned long n;
  char *end;

  n = strtoul(*buf, &end, 16);

  if (!f->flag && !f->length) {
    int *p = va_arg(vl, int *);
    *p = n;
  } else if (!f->flag && f->length == 'h') {
    short *p = va_arg(vl, short *);
    *p = n;
  } else if (!f->flag && f->length == 'l') {
    long *p = va_arg(vl, long *);
    *p = n;
  }

  if (!**buf) {
    err = EOF;
  } else if (end == *buf) {
    err = ERROR;
  } else {
    err = OK;
  }
  *buf = end;
  return err;
}

static int sscanf_floating(const char **buf, const struct format *f,
                           va_list vl) {
  int err;
  double n;
  char *end;

  n = strtof(*buf, &end);

  if (!f->flag && !f->length) {
    int *p = va_arg(vl, float *);
    *p = n;
  } else if (!f->flag && f->length == 'L') {
    long *p = va_arg(vl, double *);
    *p = n;
  }

  if (!**buf) {
    err = EOF;
  } else if (end == *buf) {
    err = ERROR;
  } else {
    err = OK;
  }
  *buf = end;
  return err;
}

static int sscanf_pointer(const char **buf, const struct format *f,
                          va_list vl) {
  int err = OK;

  return err;
}

static int sscanf_nscanned(int n, const struct format *f, va_list vl) {
  int err = OK;

  return err;
}

static int sscanf_literal(const char **buf, char ch) {
  int err;
  if (!**buf) {
    err = EOF;
  } else if (**buf != ch) {
    err = ERROR;
  } else {
    err = OK;
    (*buf)++;
  }
  return err;
}

static int sscanf_format(const char **buf, const struct format *f,
                         int nscanned, va_list vl) {
  int err;

  switch (f->specifier) {
  case '%':
    err = sscanf_literal(buf, '%');
    break;
  case 'c':
    err = sscanf_character(buf, f, vl);
    break;
  case 's':
    err = sscanf_string(buf, f, vl);
    break;
  case 'd':
    err = sscanf_decimal(buf, f, vl);
    break;
  case 'i':
    err = sscanf_integer(buf, f, vl);
    break;
  case 'u':
    err = sscanf_unsigned(buf, f, vl);
    break;
  case 'o':
    err = sscanf_octal(buf, f, vl); 
  case 'x':
    err = sscanf_hex(buf, f, vl); 
    break;
  case 'X':
    err = sscanf_hex(buf, f, vl); 
    break;
  case 'e':
    err = sscanf_floating(buf, f, vl);
    break;
  case 'E':
    err = sscanf_floating(buf, f, vl);
    break;
  case 'f':
    err = sscanf_floating(buf, f, vl);
    break;
  case 'g':
    err = sscanf_floating(buf, f, vl);
    break;
  case 'G':
    err = sscanf_floating(buf, f, vl);
    break;
  case 'p':
    err = sscanf_pointer(buf, f, vl);
    break;
  case 'n':
    sscanf_nscanned(nscanned, f, vl);
    err = OK;
    break;
  default:
    assert(0); /* ERROR */
    break;
  }
  return err;
}

int s21_sscanf(const char *buf, const char *fmt, ...) {
  int nscanned = 0, err = OK;
  const char *p, *q = buf;
  struct format f;
  va_list vl;

  va_start(vl, fmt);
  for (p = fmt; *p && !err; p++) {
    if (isspace(*p)) {
      skip_spaces(&q);
    } else if (*p != '%') {
      err = sscanf_literal(&q, *p);
    } else {
      eval_format(&p, &f);
      if (f.specifier != '%' && f.specifier != 'n' && f.specifier != 'c') {
        skip_spaces(&q);
      }
      err = sscanf_format(&q, &f, nscanned, vl);
      if (!err) {
        nscanned++;
      }
    }
  }
  va_end(vl);
  return !nscanned && err == EOF ? EOF : nscanned;
}
