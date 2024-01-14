#include <stdlib.h>

#include "mem.h"
#include "sprintf.h"
#include "sscanf.h"
#include "str.h"

int main() {
  int nfailed;
  Suite *s;
  SRunner *sr;

  s = suite_create("s21_string");
  suite_add_str(s);
  suite_add_mem(s);
  suite_add_sprintf(s);
  suite_add_sscanf(s);
  sr = srunner_create(s);
  srunner_run_all(sr, CK_NORMAL);
  nfailed = srunner_ntests_failed(sr);
  srunner_free(sr);
  return nfailed ? EXIT_FAILURE : EXIT_SUCCESS;
}
