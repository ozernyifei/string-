#include "str.h"
#include "../str.h"

static void suite_add_s21_strlen(Suite *s) {
  TCase *tc;
  tc = tcase_create("s21_strlen");
  suite_add_tcase(s, tc);
}

static void suite_add_s21_strncpy(Suite *s) {
  TCase *tc;
  tc = tcase_create("s21_strncpy");
  suite_add_tcase(s, tc);
}

static void suite_add_s21_strchr(Suite *s) {
  TCase *tc;
  tc = tcase_create("s21_strchr");
  suite_add_tcase(s, tc);
}

static void suite_add_s21_strrchr(Suite *s) {
  TCase *tc;
  tc = tcase_create("s21_strrchr");
  suite_add_tcase(s, tc);
}

static void suite_add_s21_strncat(Suite *s) {
  TCase *tc;
  tc = tcase_create("s21_strncat");
  suite_add_tcase(s, tc);
}

static void suite_add_s21_strncmp(Suite *s) {
  TCase *tc;
  tc = tcase_create("s21_strncmp");
  suite_add_tcase(s, tc);
}

static void suite_add_s21_strcspn(Suite *s) {
  TCase *tc;
  tc = tcase_create("s21_strcspn");
  suite_add_tcase(s, tc);
}

static void suite_add_s21_strpbrk(Suite *s) {
  TCase *tc;
  tc = tcase_create("s21_strpbrk");
  suite_add_tcase(s, tc);
}

static void suite_add_s21_strstr(Suite *s) {
  TCase *tc;
  tc = tcase_create("s21_strstr");
  suite_add_tcase(s, tc);
}

static void suite_add_s21_strtok(Suite *s) {
  TCase *tc;
  tc = tcase_create("s21_strtok");
  suite_add_tcase(s, tc);
}

static void suite_add_s21_strerror(Suite *s) {
  TCase *tc;
  tc = tcase_create("s21_strerror");
  suite_add_tcase(s, tc);
}

void suite_add_str(Suite *s) {
  suite_add_s21_strlen(s);
  suite_add_s21_strncpy(s);
  suite_add_s21_strchr(s);
  suite_add_s21_strrchr(s);
  suite_add_s21_strncat(s);
  suite_add_s21_strncmp(s);
  suite_add_s21_strcspn(s);
  suite_add_s21_strpbrk(s);
  suite_add_s21_strstr(s);
  suite_add_s21_strtok(s);
  suite_add_s21_strerror(s);
}
