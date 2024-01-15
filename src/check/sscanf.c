#include "sscanf.h"
#include "../sscanf.h"





START_TEST(test_d) {
  int x1, x2, y1, y2;
  ck_assert_int_eq(sscanf("298 7 3", "%d%*d%d", &x1, &x2),
                   s21_sscanf("298 7 3", "%d%*d%d", &y1, &y2));
  ck_assert_int_eq(x1, y1);
  ck_assert_int_eq(x2, y2);

  ck_assert_int_eq(sscanf("298/02", "%d%*c%d", &x1, &x2),
                   s21_sscanf("298/02", "%d%*c%d", &y1, &y2));
  ck_assert_int_eq(x1, y1);
  ck_assert_int_eq(x2, y2);

  ck_assert_int_eq(sscanf("298\n\t 3.1", "%d%d", &x1, &x2),
                   s21_sscanf("298\n\t 3.1", "%d%d", &y1, &y2));
  ck_assert_int_eq(x1, y1);
  ck_assert_int_eq(x2, y2);

  int x5, y5;
  ck_assert_int_eq(sscanf("298\n\t 3.1", "%d%d%n", &x1, &x2, &x5),
                   s21_sscanf("298\n\t 3.1", "%d%d%n", &y1, &y2, &y5));
  ck_assert_int_eq(x1, y1);
  ck_assert_int_eq(x2, y2);
  ck_assert_int_eq(x5, y5);

  short int x4, y4;
  ck_assert_int_eq(sscanf("298 3", "%d%hd", &x1, &x4),
                   s21_sscanf("298 3", "%d%hd", &y1, &y4));
  ck_assert_int_eq(x1, y1);
  ck_assert_int_eq(x4, y4);

  long int x3, y3;
  ck_assert_int_eq(sscanf("298 3", "%ld%hd", &x3, &x4),
                   s21_sscanf("298 3", "%ld%hd", &y3, &y4));
  ck_assert_int_eq(x3, y3);
  ck_assert_int_eq(x4, y4);

  ck_assert_int_eq(sscanf("298 3", "%ld%n%hd", &x3, &x1, &x4),
                   s21_sscanf("298 3", "%ld%n%hd", &y3, &y1, &y4));
  ck_assert_int_eq(x3, y3);
  ck_assert_int_eq(x1, y1);
  ck_assert_int_eq(x4, y4);
}

END_TEST

START_TEST(test_x) {
  unsigned int x1, x2, y1, y2;
  ck_assert_int_eq(sscanf("298 7 ab", "%x%*x%x", &x1, &x2),
                   s21_sscanf("298 7 ab", "%x%*x%x", &y1, &y2));
  ck_assert_int_eq(x1, y1);
  ck_assert_int_eq(x2, y2);

  unsigned short x3, y3;
  unsigned long x4, y4;
  ck_assert_int_eq(sscanf("298 7 ab", "%hX%*i%lx", &x3, &x4),
                   s21_sscanf("298 7 ab", "%hX%*i%lx", &y3, &y4));
  ck_assert_int_eq(x3, y3);
  ck_assert_int_eq(x4, y4);
}

END_TEST

START_TEST(test_o) {
  unsigned int x1, x2 = 0, y1, y2 = 0;
  ck_assert_int_eq(sscanf("298 7 ab", "%o%*o%o", &x1, &x2),
                   s21_sscanf("298 7 ab", "%o%*o%o", &y1, &y2));
  ck_assert_int_eq(x1, y1);
  ck_assert_int_eq(x2, y2);

  short unsigned x3, y3;
  long unsigned x4, y4;
  ck_assert_int_eq(sscanf("298 7 ab", "%ho%*i%lo", &x3, &x4),
                   s21_sscanf("298 7 ab", "%ho%*i%lo", &y3, &y4));
  ck_assert_int_eq(x3, y3);
  ck_assert_int_eq(x4, y4);
}

END_TEST

START_TEST(test_u) {
  unsigned int x1, x2 = 0, y1, y2 = 0;
  ck_assert_int_eq(sscanf("298 -7 ab", "%u%*u%u", &x1, &x2),
                   s21_sscanf("298 -7 ab", "%u%*u%u", &y1, &y2));
  ck_assert_int_eq(x1, y1);
  ck_assert_int_eq(x2, y2);

  ck_assert_int_eq(sscanf("298 7 -3", "%u%*u%u", &x1, &x2),
                   s21_sscanf("298 7 -3", "%u%*u%u", &y1, &y2));
  ck_assert_int_eq(x1, y1);
  ck_assert_int_eq(x2, y2);

  short unsigned x3, y3;
  long unsigned x4, y4;
  ck_assert_int_eq(sscanf("298 -7 0003", "%hu%*i%lu", &x3, &x4),
                   s21_sscanf("298 -7 0003", "%hu%*i%lu", &y3, &y4));
  ck_assert_int_eq(x3, y3);
  ck_assert_int_eq(x4, y4);
}

END_TEST

START_TEST(test_i) {
  int x1, x2 = 0, y1, y2 = 0;
  ck_assert_int_eq(sscanf("0x298 -7 ab", "%i%*i%i", &x1, &x2),
                   s21_sscanf("0x298 -7 ab", "%i%*i%i", &y1, &y2));
  ck_assert_int_eq(x1, y1);
  ck_assert_int_eq(x2, y2);

  short x3, y3;
  long x4, y4;
  ck_assert_int_eq(sscanf("298 -7 0xab", "%hi%*i%li", &x3, &x4),
                   s21_sscanf("298 -7 0xab", "%hi%*i%li", &y3, &y4));
  ck_assert_int_eq(x1, y1);
  ck_assert_int_eq(x2, y2);

  ck_assert_int_eq(sscanf("298 -7 0xab", "%hn%i%ln", &x3, &x1, &x4),
                   s21_sscanf("298 -7 0xab", "%hn%i%ln", &y3, &y1, &y4));
  ck_assert_int_eq(x1, y1);
  ck_assert_int_eq(x3, y3);
  ck_assert_int_eq(x4, y4);
}

END_TEST

START_TEST(test_p) {
  void *x1, *x2, *y1, *y2;
  ck_assert_int_eq(sscanf("298 7 0xab", "%p%*p%p", &x1, &x2),
                   s21_sscanf("298 7 0xab", "%p%*p%p", &y1, &y2));
  ck_assert_int_eq((long)x1, (long)y1);
  ck_assert_int_eq((long)x2, (long)y2);
}

END_TEST

START_TEST(test_f) {
  float x1, x2 = 0, y1, y2 = 0;
  ck_assert_int_eq(sscanf("298.3 4", "%f%f", &x1, &x2),
                   s21_sscanf("298.3 4", "%f%f", &y1, &y2));
  ck_assert_int_eq((x1 - y1) * 1e15, 0);
  ck_assert_int_eq((x2 - y2) * 1e15, 0);

  ck_assert_int_eq(sscanf("298.3 0 nAN 4", "%f%*f%*f%f", &x1, &x2),
                   s21_sscanf("298.3 0 Nan 4", "%f%*f%*f%f", &y1, &y2));
  ck_assert_int_eq((x1 - y1) * 1e15, 0);
  ck_assert_int_eq((x2 - y2) * 1e15, 0);

  long double x3, y3;
  ck_assert_int_eq(sscanf("298e-2 iNf 3E3", "%Lf%*f%f", &x3, &x2),
                   s21_sscanf("298e-2 InF 3E3", "%Lf%*f%f", &y3, &y2));
  ck_assert_int_eq((x2 - y2) * 1e15, 0);
  ck_assert_int_eq((x3 - y3) * 1e15, 0);
}

END_TEST

START_TEST(test_c) {
  char x1, x2, y1, y2;
  ck_assert_int_eq(sscanf("0 a", "%c %c", &x1, &x2),
                   s21_sscanf("0 a", "%c %c", &y1, &y2));
  ck_assert_int_eq(x1, y1);
  ck_assert_int_eq(x2, y2);

  ck_assert_int_eq(sscanf("0.a", "%c.%c", &x1, &x2),
                   s21_sscanf("0.a", "%c.%c", &y1, &y2));
  ck_assert_int_eq(x1, y1);
  ck_assert_int_eq(x2, y2);

  wchar_t x3, y3;
  ck_assert_int_eq(sscanf("3/5gf", "%lc%*c%cg%c", &x3, &x2, &x1),
                   s21_sscanf("3/5gf", "%lc%*c%cg%c", &y3, &y2, &y1));
  ck_assert_int_eq(x1, y1);
  ck_assert_int_eq(x2, y2);
  ck_assert_int_eq(x3, y3);

  ck_assert_int_eq(sscanf("ȬŚƾ", "%lc%c%c", &x3, &x2, &x1),
                   s21_sscanf("ȬŚƾ", "%lc%c%c", &y3, &y2, &y1));
  ck_assert_int_eq(x3, y3);
  ck_assert_int_eq(x1, y1);
  ck_assert_int_eq(x2, y2);
}

END_TEST

START_TEST(test_s) {
  char x1[10] = "\0", x2[10] = "\0", y1[10] = "\0", y2[10] = "\0";
  ck_assert_int_eq(sscanf("ya ebu sobak", "%9sebu%9s", x1, x2),
                   s21_sscanf("ya ebu sobak", "%9sebu%9s", y1, y2));
  ck_assert_str_eq(x1, y1);
  ck_assert_str_eq(x2, y2);

  ck_assert_int_eq(sscanf("ya ebu sobak", "%9s%*2s%9s", x1, x2),
                   s21_sscanf("ya ebu sobak", "%9s%*2s%9s", y1, y2));
  ck_assert_str_eq(x1, y1);
  ck_assert_str_eq(x2, y2);

  ck_assert_int_eq(sscanf("ya ebu sobak", "%9sf%9s", x1, x2),
                   s21_sscanf("ya ebu sobak", "%9sf%9s", y1, y2));
  ck_assert_str_eq(x1, y1);
  ck_assert_str_eq(x2, y2);

  ck_assert_int_eq(sscanf("  ya", "%9s%9s", x1, x2),
                   s21_sscanf("  ya", "%9s%9s", y1, y2));
  ck_assert_str_eq(x1, y1);
  ck_assert_str_eq(x2, y2);

  wchar_t x3[10], y3[10];
  int x4, y4;
  ck_assert_int_eq(
      sscanf("ya ebu % sobak", "%9ls%9s%%%n%9s", x3, x2, &x4, x1),
      s21_sscanf("ya ebu % sobak", "%9ls%s%%%n%9s", y3, y2, &y4, y1));
  ck_assert_str_eq(x1, y1);
  ck_assert_str_eq(x2, y2);
  ck_assert_int_eq(*x3, *y3);
  ck_assert_int_eq(x4, y4);

  ck_assert_int_eq(sscanf("ȬŚƾ", "%9ls%*s%n%9s", x3, &x4, x1),
                   s21_sscanf("ȬŚƾ", "%9ls%*s%n%9s", y3, &y4, y1));
  ck_assert_str_eq(x1, y1);
  ck_assert_int_eq(*x3, *y3);
  ck_assert_int_eq(x4, y4);
}

END_TEST


void suite_add_s21_sscanf(Suite *s) {
  // s21_sscanf
  TCase *tc;
  tc = tcase_create("s21_sscanf");
  

  tcase_add_test(tc, test_d);
  tcase_add_test(tc, test_x);
  tcase_add_test(tc, test_o);
  tcase_add_test(tc, test_u);
  tcase_add_test(tc, test_i);
  tcase_add_test(tc, test_p);
  tcase_add_test(tc, test_f);
  tcase_add_test(tc, test_c);
  tcase_add_test(tc, test_s);

  suite_add_tcase(s, tc);
}

void suite_add_sscanf(Suite *s) { suite_add_s21_sscanf(s); }