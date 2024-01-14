#include "sscanf.h"
#include "../sscanf.h"

static void suite_add_s21_sscanf(Suite *s) {
  TCase *tc;
  tc = tcase_create("s21_sscanf");
  suite_add_tcase(s, tc);
}

void suite_add_sscanf(Suite *s) { suite_add_s21_sscanf(s); }
