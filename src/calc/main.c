#include "smart_calc.h"

START_TEST(test_1) {
  char* str = (char*)calloc(256, sizeof(char));
  double res = 0;
  double orig = 4;
  stack* work = NULL;
  sprintf(str, "2+2");
  parser(str);
  res = calculate(&work, str, 0);
  ck_assert_double_eq(res, orig);
  free(str);
}
END_TEST

START_TEST(test_2) {
  char* str = (char*)calloc(256, sizeof(char));
  double res = 0;
  stack* work = NULL;
  sprintf(str, "-1");
  parser(str);
  res = calculate(&work, str, 0);
  ck_assert_double_eq(res, -1);
  free(str);
}
END_TEST

START_TEST(test_3) {
  char* str = (char*)calloc(256, sizeof(char));
  double res = 0;
  stack* work = NULL;
  sprintf(str, "2*2");
  parser(str);
  res = calculate(&work, str, 0);
  ck_assert_double_eq(res, 2 * 2);
  free(str);
}
END_TEST

START_TEST(test_4) {
  char* str = (char*)calloc(256, sizeof(char));
  double res = 0;
  stack* work = NULL;
  sprintf(str, "44-2");
  parser(str);
  res = calculate(&work, str, 0);
  ck_assert_double_eq(res, 44 - 2);
  free(str);
}
END_TEST

START_TEST(test_5) {
  char* str = (char*)calloc(256, sizeof(char));
  double res = 0;
  stack* work = NULL;
  sprintf(str, "15*3");
  parser(str);
  res = calculate(&work, str, 0);
  ck_assert_double_eq(res, 15 * 3);
  free(str);
}
END_TEST

START_TEST(test_6) {
  char* str = (char*)calloc(256, sizeof(char));
  double res = 0;
  stack* work = NULL;
  sprintf(str, "12/4");
  parser(str);
  res = calculate(&work, str, 0);
  ck_assert_double_eq(res, 12 / 4);
  free(str);
}
END_TEST

START_TEST(test_7) {
  char* str = (char*)calloc(256, sizeof(char));
  double res = 0;
  stack* work = NULL;
  sprintf(str, "11^2");
  parser(str);
  res = calculate(&work, str, 0);
  ck_assert_double_eq(res, pow(11, 2));
  free(str);
}
END_TEST

START_TEST(test_8) {
  char* str = (char*)calloc(256, sizeof(char));
  double res = 0;
  stack* work = NULL;
  sprintf(str, "3 mod 10");
  parser(str);
  res = calculate(&work, str, 0);
  ck_assert_double_eq(res, fmod(3, 10));
  free(str);
}
END_TEST

START_TEST(test_9) {
  char* str = (char*)calloc(256, sizeof(char));
  double res = 0;
  stack* work = NULL;
  sprintf(str, "-1+3");
  parser(str);
  res = calculate(&work, str, 0);
  ck_assert_double_eq(res, -1 + 3);
  free(str);
}
END_TEST

START_TEST(test_10) {
  char* str = (char*)calloc(256, sizeof(char));
  double res = 0;
  stack* work = NULL;
  sprintf(str, "sin(1)");
  parser(str);
  res = calculate(&work, str, 0);
  ck_assert_double_eq(res, sin(1));
  free(str);
}
END_TEST

START_TEST(test_11) {
  char* str = (char*)calloc(256, sizeof(char));
  double res = 0;
  stack* work = NULL;
  sprintf(str, "cos(2)");
  parser(str);
  res = calculate(&work, str, 0);
  ck_assert_double_eq(res, cos(2));
  free(str);
}
END_TEST

START_TEST(test_12) {
  char* str = (char*)calloc(256, sizeof(char));
  double res = 0;
  stack* work = NULL;
  sprintf(str, "tan(2)");
  parser(str);
  res = calculate(&work, str, 0);
  ck_assert_double_eq(res, tan(2));
  free(str);
}
END_TEST

START_TEST(test_13) {
  char* str = (char*)calloc(256, sizeof(char));
  double res = 0;
  stack* work = NULL;
  sprintf(str, "acos(0.4)");
  parser(str);
  res = calculate(&work, str, 0);
  ck_assert_double_eq(res, acos(0.4));
  free(str);
}
END_TEST

START_TEST(test_14) {
  char* str = (char*)calloc(256, sizeof(char));
  double res = 0;
  stack* work = NULL;
  sprintf(str, "sqrt(169)");
  parser(str);
  res = calculate(&work, str, 0);
  ck_assert_double_eq(res, sqrt(169));
  free(str);
}
END_TEST

START_TEST(test_15) {
  char* str = (char*)calloc(256, sizeof(char));
  double res = 0;
  stack* work = NULL;
  sprintf(str, "ln(3)");
  parser(str);
  res = calculate(&work, str, 0);
  ck_assert_double_eq(res, log(3));
  free(str);
}
END_TEST

START_TEST(test_16) {
  char* str = (char*)calloc(256, sizeof(char));
  double res = 0;
  stack* work = NULL;
  sprintf(str, "log(10000)");
  parser(str);
  res = calculate(&work, str, 0);
  ck_assert_double_eq(res, log10(10000));
  free(str);
}
END_TEST

START_TEST(test_17) {
  char* str = (char*)calloc(256, sizeof(char));
  double res = 0;
  stack* work = NULL;
  sprintf(str, "asin(0.4)");
  parser(str);
  res = calculate(&work, str, 0);
  ck_assert_double_eq(res, asin(0.4));
  free(str);
}
END_TEST

START_TEST(test_18) {
  char* str = (char*)calloc(256, sizeof(char));
  double res = 0;
  stack* work = NULL;
  sprintf(str, "atan(5)");
  parser(str);
  res = calculate(&work, str, 0);
  ck_assert_double_eq(res, atan(5));
  free(str);
}
END_TEST

START_TEST(test_19) {
  char* str = (char*)calloc(256, sizeof(char));
  double res = 0;
  stack* work = NULL;
  sprintf(str, "sin(1)^tan(1)+43/2*0+cos(45)");
  parser(str);
  res = calculate(&work, str, 0);
  ck_assert_double_eq_tol(res, 1.289607, 1e-6);
  free(str);
}
END_TEST

START_TEST(test_20) {
  char* str = (char*)calloc(256, sizeof(char));
  double res = 0;
  stack* work = NULL;
  sprintf(str, "1/(1+3-5)*1000");
  parser(str);
  res = calculate(&work, str, 0);
  ck_assert_double_eq(res, 1 / (1 + 3 - 5) * 1000);
  free(str);
}
END_TEST

START_TEST(test_21) {
  char* str = (char*)calloc(256, sizeof(char));
  double res = 0;
  stack* work = NULL;
  sprintf(str, "sin ( x )");
  parser(str);
  res = calculate(&work, str, 0);
  ck_assert_double_eq(res, sin(0));
  free(str);
}
END_TEST

START_TEST(test_verification_1) {
  char* str = (char*)calloc(256, sizeof(char));
  sprintf(str, "1/(*1+3-5)*1000");
  int res = verification(str);
  ck_assert_int_eq(1, res);
  free(str);
}
END_TEST

START_TEST(test_verification_2) {
  char* str = (char*)calloc(256, sizeof(char));
  sprintf(str, "sin( )");
  int res = verification(str);
  ck_assert_int_eq(1, res);
  free(str);
}
END_TEST

START_TEST(test_verification_3) {
  char* str = (char*)calloc(256, sizeof(char));
  sprintf(str, "lnsinsqrtx");
  int res = verification(str);
  ck_assert_int_eq(1, res);
  free(str);
}
END_TEST

START_TEST(test_verification_4) {
  char* str = (char*)calloc(256, sizeof(char));
  sprintf(str, "1++12");
  int res = verification(str);
  ck_assert_int_eq(1, res);
  free(str);
}
END_TEST

START_TEST(test_verification_5) {
  char* str = (char*)calloc(256, sizeof(char));
  sprintf(str, "sin(x)+cos((1-67)/2)");
  int res = verification(str);
  ck_assert_int_eq(0, res);
  free(str);
}
END_TEST

START_TEST(test_verification_6) {
  char* str = (char*)calloc(256, sizeof(char));
  sprintf(str, "sin(x)");
  int res = verification(str);
  ck_assert_int_eq(0, res);
  free(str);
}
END_TEST

START_TEST(test_verification_7) {
  char* str = (char*)calloc(1000, sizeof(char));
  sprintf(
      str,
      "123123456765432123456787654321345678909876543212345678909876543212345678"
      "909876543212345678909876543234567898765432123456789876543212345678987654"
      "321234567897654323456789876543234567876543213456789876543213456789876543"
      "234567898765432345678987654323456789876543234567890987654321234567890987"
      "654321234567898765432123456789098765432123456789876543234567898765432");
  int res = verification(str);
  ck_assert_int_eq(1, res);
  free(str);
}
END_TEST

START_TEST(test_verification_8) {
  char* str = (char*)calloc(1000, sizeof(char));
  sprintf(str, "2.345.2324");
  int res = verification(str);
  ck_assert_int_eq(1, res);
  free(str);
}
END_TEST

START_TEST(test_credit_1) {
  double x = 0, y = 0, z = 0;
  credit_an(20000, 12, 15, &x, &y, &z);
  ck_assert_double_eq_tol(x, 1805.166247, 1e-6);
  ck_assert_double_eq_tol(y, 1661.994963, 1e-6);
  ck_assert_double_eq_tol(z, 21661.994963, 1e-6);
}
END_TEST

START_TEST(test_credit_2) {
  double x1 = 0, x2 = 0, y = 0, z = 0;
  credit_diff(20000, 12, 15, &x1, &x2, &y, &z);
  ck_assert_double_eq_tol(x1, 1916.666667, 1e-6);
  ck_assert_double_eq_tol(x2, 1687.5, 1e-6);
  ck_assert_double_eq(y, 1625);
  ck_assert_double_eq(z, 21625);
}
END_TEST

START_TEST(test_deposit_1) {
  double x = 0, y = 0, z = 0;
  deposit(20000, 9, 12, 12, 0, 0, 0, 0, 0, 0, &x, &y, &z);
  ck_assert_double_eq_tol(x, 1798.79, 1e-2);
  ck_assert_double_eq_tol(y, 21798.79, 1e-2);
  ck_assert_double_eq_tol(z, 0, 1e-6);
}
END_TEST

START_TEST(test_deposit_2) {
  double x = 0, y = 0, z = 0;
  deposit(20000, 9, 12, 12, 0, 0, 1, 0, 1, 0, &x, &y, &z);
  ck_assert_double_eq_tol(x, 1798.79, 1e-2);
  ck_assert_double_eq_tol(y, 21798.79, 1e-2);
  ck_assert_double_eq_tol(z, 0, 1e-6);
}
END_TEST

START_TEST(test_deposit_3) {
  double x = 0, y = 0, z = 0;
  deposit(20000, 9, 12, 12, 0, 0, 3, 0, 3, 0, &x, &y, &z);
  ck_assert_double_eq_tol(x, 1798.79, 1e-2);
  ck_assert_double_eq_tol(y, 21798.79, 1e-2);
  ck_assert_double_eq_tol(z, 0, 1e-6);
}
END_TEST

START_TEST(test_deposit_4) {
  double x = 0, y = 0, z = 0;
  deposit(20000, 9, 12, 12, 0, 0, 2, 0, 2, 0, &x, &y, &z);
  ck_assert_double_eq_tol(x, 1798.79, 1e-2);
  ck_assert_double_eq_tol(y, 21798.79, 1e-2);
  ck_assert_double_eq_tol(z, 0, 1e-6);
}
END_TEST

START_TEST(test_deposit_5) {
  double x = 0, y = 0, z = 0;
  deposit(20000, 9, 12, 12, 0, 0, 4, 0, 4, 0, &x, &y, &z);
  ck_assert_double_eq_tol(x, 1798.79, 1e-2);
  ck_assert_double_eq_tol(y, 21798.79, 1e-2);
  ck_assert_double_eq_tol(z, 0, 1e-6);
}
END_TEST

START_TEST(test_deposit_6) {
  double x = 0, y = 0, z = 0;
  deposit(20000, 9, 15, 12, 0, 1, 4, 0, 4, 0, &x, &y, &z);
  ck_assert_double_eq_tol(x, 2248.48, 1e-2);
  ck_assert_double_eq_tol(y, 22248.48, 1e-2);
  ck_assert_double_eq_tol(z, 0, 1e-6);
}
END_TEST

START_TEST(test_deposit_7) {
  double x = 0, y = 0, z = 0;
  deposit(200000000, 9, 15, 10, 0, 1, 4, 0, 4, 0, &x, &y, &z);
  ck_assert_double_eq_tol(x, 22484845.995893, 1e-2);
  ck_assert_double_eq_tol(y, 222484845.995893, 1e-2);
  ck_assert_double_eq_tol(z, 1623029.979466, 1e-6);
}
END_TEST

int main(void) {
  Suite* s1 = suite_create("calc");
  TCase* tc1_1 = tcase_create("calculate");
  SRunner* sr = srunner_create(s1);
  int nf;

  suite_add_tcase(s1, tc1_1);
  tcase_add_test(tc1_1, test_1);
  tcase_add_test(tc1_1, test_2);
  tcase_add_test(tc1_1, test_3);
  tcase_add_test(tc1_1, test_4);
  tcase_add_test(tc1_1, test_5);
  tcase_add_test(tc1_1, test_6);
  tcase_add_test(tc1_1, test_7);
  tcase_add_test(tc1_1, test_8);
  tcase_add_test(tc1_1, test_9);
  tcase_add_test(tc1_1, test_10);
  tcase_add_test(tc1_1, test_11);
  tcase_add_test(tc1_1, test_12);
  tcase_add_test(tc1_1, test_13);
  tcase_add_test(tc1_1, test_14);
  tcase_add_test(tc1_1, test_15);
  tcase_add_test(tc1_1, test_16);
  tcase_add_test(tc1_1, test_17);
  tcase_add_test(tc1_1, test_18);
  tcase_add_test(tc1_1, test_19);
  tcase_add_test(tc1_1, test_20);
  tcase_add_test(tc1_1, test_21);
  tcase_add_test(tc1_1, test_verification_1);
  tcase_add_test(tc1_1, test_verification_2);
  tcase_add_test(tc1_1, test_verification_3);
  tcase_add_test(tc1_1, test_verification_4);
  tcase_add_test(tc1_1, test_verification_5);
  tcase_add_test(tc1_1, test_verification_6);
  tcase_add_test(tc1_1, test_verification_7);
  tcase_add_test(tc1_1, test_verification_8);
  tcase_add_test(tc1_1, test_credit_1);
  tcase_add_test(tc1_1, test_credit_2);
  tcase_add_test(tc1_1, test_deposit_1);
  tcase_add_test(tc1_1, test_deposit_2);
  tcase_add_test(tc1_1, test_deposit_3);
  tcase_add_test(tc1_1, test_deposit_4);
  tcase_add_test(tc1_1, test_deposit_5);
  tcase_add_test(tc1_1, test_deposit_6);
  tcase_add_test(tc1_1, test_deposit_7);

  srunner_run_all(sr, CK_ENV);
  nf = srunner_ntests_failed(sr);
  srunner_free(sr);

  return nf == 0 ? 0 : 1;
}