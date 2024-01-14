#include <assert.h>

#include "mem.h"

void *s21_memset(void *b, int c, size_t n) {
  size_t i;
  unsigned char *pb = b;
  assert(b);
  for (i = 0; i < n; i++) {
    pb[i] = c;
  }
  return b;
}

void *s21_memcpy(void *dest, const void *src, size_t n) {
  size_t i;
  unsigned char *bdest = dest;
  const unsigned char *bsrc = src;
  assert(dest && src);
  for (i = 0; i < n; i++) {
    bdest[i] = bsrc[i];
  }
  return dest;
}

int s21_memcmp(const void *b1, const void *b2, size_t n) {
  size_t i;
  const unsigned char *pb1 = b1, *pb2 = b2;
  assert(b1 && b2);
  for (i = 0; i < n && pb1[i] == pb2[i]; i++)
    ;
  return i == n ? 0 : pb1[i] - pb2[i];
}

void *s21_memchr(const void *b, int c, size_t n) {
  size_t i;
  const unsigned char *pb = b;
  assert(b);
  for (i = 0; i < n && pb[i] != c; i++)
    ;
  return (void *)(i == n ? NULL : pb + i);
}
