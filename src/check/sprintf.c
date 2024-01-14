#include "sprintf.h"
#include "../sprintf.h"

static void suite_add_s21_sprintf(Suite *s) {
  TCase *tc;
  tc = tcase_create("s21_sprintf");
  suite_add_tcase(s, tc);
}

void suite_add_sprintf(Suite *s) { suite_add_s21_sprintf(s); }
