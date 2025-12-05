#include <unity.h>
#include "util.h"

// Test CLAMP template function
void test_clamp_within_range() {
    TEST_ASSERT_EQUAL_INT(5, CLAMP(5, 0, 10));
    TEST_ASSERT_EQUAL_FLOAT(5.5f, CLAMP(5.5f, 0.0f, 10.0f));
}

void test_clamp_below_minimum() {
    TEST_ASSERT_EQUAL_INT(0, CLAMP(-5, 0, 10));
    TEST_ASSERT_EQUAL_FLOAT(0.0f, CLAMP(-5.5f, 0.0f, 10.0f));
}

void test_clamp_above_maximum() {
    TEST_ASSERT_EQUAL_INT(10, CLAMP(15, 0, 10));
    TEST_ASSERT_EQUAL_FLOAT(10.0f, CLAMP(15.5f, 0.0f, 10.0f));
}

void test_clamp_at_boundaries() {
    TEST_ASSERT_EQUAL_INT(0, CLAMP(0, 0, 10));
    TEST_ASSERT_EQUAL_INT(10, CLAMP(10, 0, 10));
}

void test_clamp_negative_range() {
    TEST_ASSERT_EQUAL_INT(-5, CLAMP(-5, -10, -1));
    TEST_ASSERT_EQUAL_INT(-10, CLAMP(-15, -10, -1));
    TEST_ASSERT_EQUAL_INT(-1, CLAMP(5, -10, -1));
}

// Test lerp function
void test_lerp_basic() {
    // Map 5 from range [0,10] to [0,100] should give 50
    TEST_ASSERT_EQUAL_FLOAT(50.0f, lerp(5.0f, 0.0f, 10.0f, 0.0f, 100.0f));
}

void test_lerp_at_boundaries() {
    // At minimum input
    TEST_ASSERT_EQUAL_FLOAT(0.0f, lerp(0.0f, 0.0f, 10.0f, 0.0f, 100.0f));
    // At maximum input
    TEST_ASSERT_EQUAL_FLOAT(100.0f, lerp(10.0f, 0.0f, 10.0f, 0.0f, 100.0f));
}

void test_lerp_reverse_mapping() {
    // Map 5 from range [0,10] to [100,0] should give 50
    TEST_ASSERT_EQUAL_FLOAT(50.0f, lerp(5.0f, 0.0f, 10.0f, 100.0f, 0.0f));
}

void test_lerp_negative_ranges() {
    // Map 0 from range [-10,10] to [0,100] should give 50
    TEST_ASSERT_EQUAL_FLOAT(50.0f, lerp(0.0f, -10.0f, 10.0f, 0.0f, 100.0f));
}

void test_lerp_scaling() {
    // Map 25 from range [0,100] to [0,10] should give 2.5
    TEST_ASSERT_FLOAT_WITHIN(0.01f, 2.5f, lerp(25.0f, 0.0f, 100.0f, 0.0f, 10.0f));
}

void test_lerp_offset_ranges() {
    // Map 15 from range [10,20] to [100,200] should give 150
    TEST_ASSERT_EQUAL_FLOAT(150.0f, lerp(15.0f, 10.0f, 20.0f, 100.0f, 200.0f));
}

// Test sgn function
void test_sgn_positive() {
    TEST_ASSERT_EQUAL_INT(1, sgn(5));
    TEST_ASSERT_EQUAL_INT(1, sgn(100));
    TEST_ASSERT_EQUAL_INT(1, sgn(0.1f));
}

void test_sgn_negative() {
    TEST_ASSERT_EQUAL_INT(-1, sgn(-5));
    TEST_ASSERT_EQUAL_INT(-1, sgn(-100));
    TEST_ASSERT_EQUAL_INT(-1, sgn(-0.1f));
}

void test_sgn_zero() {
    TEST_ASSERT_EQUAL_INT(0, sgn(0));
    TEST_ASSERT_EQUAL_INT(0, sgn(0.0f));
}

void test_sgn_different_types() {
    TEST_ASSERT_EQUAL_INT(1, sgn(1));
    TEST_ASSERT_EQUAL_INT(1, sgn(1L));
    TEST_ASSERT_EQUAL_INT(1, sgn(1.0));
    TEST_ASSERT_EQUAL_INT(1, sgn(1.0f));
}

// Test COUNT_OF macro
void test_count_of_int_array() {
    int arr[] = {1, 2, 3, 4, 5};
    TEST_ASSERT_EQUAL_size_t(5, COUNT_OF(arr));
}

void test_count_of_float_array() {
    float arr[] = {1.0f, 2.0f, 3.0f};
    TEST_ASSERT_EQUAL_size_t(3, COUNT_OF(arr));
}

void test_count_of_single_element() {
    int arr[] = {42};
    TEST_ASSERT_EQUAL_size_t(1, COUNT_OF(arr));
}

void test_count_of_struct_array() {
    struct TestStruct {
        int a;
        float b;
    };
    TestStruct arr[] = {{1, 1.0f}, {2, 2.0f}, {3, 3.0f}, {4, 4.0f}};
    TEST_ASSERT_EQUAL_size_t(4, COUNT_OF(arr));
}

void setup() {
    delay(2000); // Give time for serial monitor to connect
    UNITY_BEGIN();

    // CLAMP tests
    RUN_TEST(test_clamp_within_range);
    RUN_TEST(test_clamp_below_minimum);
    RUN_TEST(test_clamp_above_maximum);
    RUN_TEST(test_clamp_at_boundaries);
    RUN_TEST(test_clamp_negative_range);

    // lerp tests
    RUN_TEST(test_lerp_basic);
    RUN_TEST(test_lerp_at_boundaries);
    RUN_TEST(test_lerp_reverse_mapping);
    RUN_TEST(test_lerp_negative_ranges);
    RUN_TEST(test_lerp_scaling);
    RUN_TEST(test_lerp_offset_ranges);

    // sgn tests
    RUN_TEST(test_sgn_positive);
    RUN_TEST(test_sgn_negative);
    RUN_TEST(test_sgn_zero);
    RUN_TEST(test_sgn_different_types);

    // COUNT_OF tests
    RUN_TEST(test_count_of_int_array);
    RUN_TEST(test_count_of_float_array);
    RUN_TEST(test_count_of_single_element);
    RUN_TEST(test_count_of_struct_array);

    UNITY_END();
}

void loop() {
    // Tests run once in setup()
}
