#include "unity.h"
#include "math_utils.h"

void setUp(void) {}
void tearDown(void) {}

void test_add_positive_numbers(void) {
    TEST_ASSERT_EQUAL_INT(5, add(2, 3));
}

void test_add_with_zero(void) {
    TEST_ASSERT_EQUAL_INT(7, add(7, 0));
}

void test_add_negative_numbers(void) {
    TEST_ASSERT_EQUAL_INT(-1, add(-3, 2));
}

void test_multiply_positive_numbers(void) {
    TEST_ASSERT_EQUAL_INT(12, multiply(3, 4));
}

void test_multiply_by_zero(void) {
    TEST_ASSERT_EQUAL_INT(0, multiply(5, 0));
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_add_positive_numbers);
    RUN_TEST(test_add_with_zero);
    RUN_TEST(test_add_negative_numbers);
    RUN_TEST(test_multiply_positive_numbers);
    RUN_TEST(test_multiply_by_zero);
    return UNITY_END();
}
