/*
 * Simple Test Framework for C Programs
 * This provides basic testing functionality for the daily exercises
 */

#include <stdio.h>
#include <string.h>

// Test statistics
static int tests_run = 0;
static int tests_passed = 0;

// Test macros
#define ASSERT_EQUAL(expected, actual, message) \
    do { \
        tests_run++; \
        if ((expected) == (actual)) { \
            tests_passed++; \
            printf("✓ PASS: %s\n", message); \
        } else { \
            printf("✗ FAIL: %s (expected: %d, got: %d)\n", message, expected, actual); \
        } \
    } while(0)

#define ASSERT_STRING_EQUAL(expected, actual, message) \
    do { \
        tests_run++; \
        if (strcmp(expected, actual) == 0) { \
            tests_passed++; \
            printf("✓ PASS: %s\n", message); \
        } else { \
            printf("✗ FAIL: %s (expected: '%s', got: '%s')\n", message, expected, actual); \
        } \
    } while(0)

#define ASSERT_TRUE(condition, message) \
    do { \
        tests_run++; \
        if (condition) { \
            tests_passed++; \
            printf("✓ PASS: %s\n", message); \
        } else { \
            printf("✗ FAIL: %s\n", message); \
        } \
    } while(0)

// Test functions for basic mathematical operations
int test_add(int a, int b) {
    return a + b;
}

int test_factorial(int n) {
    if (n <= 1) return 1;
    return n * test_factorial(n - 1);
}

int test_is_prime(int num) {
    if (num <= 1) return 0;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) return 0;
    }
    return 1;
}

void run_tests() {
    printf("=== Running Basic Tests ===\n");
    
    // Test addition
    ASSERT_EQUAL(5, test_add(2, 3), "Addition test: 2 + 3 = 5");
    ASSERT_EQUAL(0, test_add(-5, 5), "Addition test: -5 + 5 = 0");
    
    // Test factorial
    ASSERT_EQUAL(1, test_factorial(0), "Factorial test: 0! = 1");
    ASSERT_EQUAL(1, test_factorial(1), "Factorial test: 1! = 1");
    ASSERT_EQUAL(6, test_factorial(3), "Factorial test: 3! = 6");
    ASSERT_EQUAL(120, test_factorial(5), "Factorial test: 5! = 120");
    
    // Test prime number check
    ASSERT_TRUE(test_is_prime(2), "Prime test: 2 is prime");
    ASSERT_TRUE(test_is_prime(7), "Prime test: 7 is prime");
    ASSERT_TRUE(!test_is_prime(4), "Prime test: 4 is not prime");
    ASSERT_TRUE(!test_is_prime(1), "Prime test: 1 is not prime");
    
    // Test summary
    printf("\n=== Test Summary ===\n");
    printf("Tests run: %d\n", tests_run);
    printf("Tests passed: %d\n", tests_passed);
    printf("Tests failed: %d\n", tests_run - tests_passed);
    printf("Success rate: %.1f%%\n", (float)tests_passed / tests_run * 100);
}

int main() {
    run_tests();
    return 0;
}