#include "mem.h"
#include "../mem.h"

static void suite_add_s21_memset(Suite *s) {
  TCase *tc;
  tc = tcase_create("s21_memset");
  suite_add_tcase(s, tc);
}

static void suite_add_s21_memcpy(Suite *s) {
  TCase *tc;
  tc = tcase_create("s21_memcpy");
  suite_add_tcase(s, tc);
}

static void suite_add_s21_memcmp(Suite *s) {
  TCase *tc;
  tc = tcase_create("s21_memcmp");
  suite_add_tcase(s, tc);
}

static void suite_add_s21_memchr(Suite *s) {
  TCase *tc;
  tc = tcase_create("s21_memchr");
  suite_add_tcase(s, tc);
}

void suite_add_mem(Suite *s) {
  suite_add_s21_memset(s);
  suite_add_s21_memchr(s);
  suite_add_s21_memcpy(s);
  suite_add_s21_memcmp(s);
}
