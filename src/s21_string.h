#ifndef S21_STRING_H_SENTRY
#define S21_STRING_H_SENTRY

#ifndef NULL
#define NULL (void *)0
#endif
typedef unsigned long size_t;

void *s21_memset(void *s, int c, size_t n);
void *s21_memcpy(void *dest, const void *src, size_t n);
int s21_memcmp(const void *s1, const void *s2, size_t n);
void *s21_memchr(const void *s, int c, size_t n);

size_t s21_strlen(const char *s);
char *s21_strncpy(char *dest, const char *src, size_t n);
char *s21_strchr(const char *s, int c);
char *s21_strrchr(const char *s, int c);
char *s21_strncat(char *dest, const char *src, size_t n);
int s21_strncmp(const char *s1, const char *s2, size_t n);
size_t s21_strcspn(const char *s1, const char *s2);
char *s21_strpbrk(const char *s1, const char *s2);
char *s21_strstr(const char *haystack, const char *needle);
char *s21_strtok(char *s, const char *delim);
char *s21_strerror(int errnum);

void *to_upper(const char *s);
void *to_lower(const char *s);
void *insert(const char *s1, char *s2, size_t ind);
void *trim(const char *s, const char *set);

int s21_sscanf(const char *buf, const char *fmt, ...);
int s21_sprintf(char *buf, const char *fmt, ...);

#endif
