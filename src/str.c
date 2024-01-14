#include <assert.h>

#include "str.h"

size_t s21_strlen(const char *s) {
  const char *t;
  assert(s);
  for (t = s; *t; t++)
    ;
  return t - s;
}

char *s21_strncpy(char *dest, const char *src, size_t n) {
  size_t i;
  assert(dest && src);
  for (i = 0; i < n; i++) {
    if (*src) {
      dest[i] = *src;
      src++;
    } else {
      dest[i] = '\0';
    }
  }
  return dest;
}

char *s21_strchr(const char *s, int c) {
  assert(s);
  for (; *s && *s != (char)c; s++)
    ;
  return *s == (char)c ? (char *)s : NULL;
}

char *s21_strrchr(const char *s, int c) {
  const char *t = NULL;
  assert(s);
  for (; *s; s++)
    if (*s == (char)c)
      t = s;
  if (*s == (char)c)
    t = s;
  return (char *)t;
}

char *s21_strncat(char *dest, const char *src, size_t n) {
  size_t i;
  char *tmp = dest;
  assert(dest && src);
  for (; *dest; dest++)
    ;
  for (i = 0; i < n && *src; i++)
    dest[i] = src[i];
  dest[i] = '\0';
  return tmp;
}

int s21_strncmp(const char *s1, const char *s2, size_t n) {
  size_t i;
  assert(s1 && s2);
  for (i = 0; i < n && s1[i] && s1[i] == s2[i]; i++)
    ;
  return i == n ? 0 : (unsigned char)s1[i] - (unsigned char)s2[i];
}

size_t s21_strcspn(const char *s, const char *set) {
  size_t i;
  assert(s);
  for (i = 0; !s21_strchr(set, s[i]); i++)
    ;
  return i;
}

char *s21_strpbrk(const char *s, const char *set) {
  assert(s);
  for (; !s21_strchr(set, *s); s++)
    ;
  return *s ? (char *)s : NULL;
}

char *s21_strstr(const char *haystack, const char *needle) {
  size_t n = s21_strlen(needle);
  assert(haystack && needle);
  for (; *haystack && 0 != s21_strncmp(haystack, needle, n); haystack++)
    ;
  return 0 != s21_strncmp(haystack, needle, n) ? NULL : (char *)haystack;
}

char *s21_strtok(char *s, const char *delim) {
  static char *cache = NULL, *tok;
  assert(delim && (s || cache));
  if (s) {
    cache = s;
  }
  for (; *cache && s21_strchr(delim, *cache); cache++)
    ;
  tok = cache;
  for (; !s21_strchr(delim, *cache); cache++)
    ;
  if (*cache) {
    *cache = '\0';
    cache++;
  }
  return *tok ? tok : NULL;
}

char *s21_strerror(int errnum) { return NULL; }

void *to_upper(const char *s) { return NULL; }

void *to_lower(const char *s) { return NULL; }

void *insert(const char *s1, char *s2, size_t ind) { return NULL; }

void *trim(const char *s, const char *set) { return NULL; }
