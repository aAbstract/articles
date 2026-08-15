#include "unity.h"

#include "module.c"

void setUp(void) {
    // set stuff up here
}

void tearDown(void) {
    // clean stuff up here
}

void test_add_1(void) {
    TEST_ASSERT_EQUAL_INT(11, add_nums(5, 6));
}

void test_add_2(void) {
    TEST_ASSERT_EQUAL_INT(5, add_nums(2, 3));
}

void test_add_3(void) {
    TEST_ASSERT_EQUAL_INT(12, add_nums(4, 9));
}

int main(void) {
    UNITY_BEGIN();

    RUN_TEST(test_add_1);
    RUN_TEST(test_add_2);
    RUN_TEST(test_add_3);

    return UNITY_END();
}