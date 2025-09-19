/*
 * Utility Functions for Common Operations
 * Provides reusable functions for daily programming exercises
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

// String utilities
int stringLength(const char* str);
void stringReverse(char* str);
void stringToUpper(char* str);
void stringToLower(char* str);
int isPalindrome(const char* str);

// Math utilities
int power(int base, int exp);
int gcd(int a, int b);
int lcm(int a, int b);
int fibonacci(int n);

// Array utilities
void printArray(int arr[], int size, const char* name);
void sortArray(int arr[], int size);
int binarySearch(int arr[], int size, int target);

int main() {
    printf("=== Utility Functions Demo ===\n");
    
    // String utilities demo
    printf("\n--- String Utilities ---\n");
    char testStr[] = "Hello World";
    printf("Original string: %s\n", testStr);
    printf("Length: %d\n", stringLength(testStr));
    
    char reverseStr[] = "programming";
    printf("Before reverse: %s\n", reverseStr);
    stringReverse(reverseStr);
    printf("After reverse: %s\n", reverseStr);
    
    char upperStr[] = "convert to upper";
    stringToUpper(upperStr);
    printf("Uppercase: %s\n", upperStr);
    
    char lowerStr[] = "CONVERT TO LOWER";
    stringToLower(lowerStr);
    printf("Lowercase: %s\n", lowerStr);
    
    printf("Is 'racecar' a palindrome? %s\n", 
           isPalindrome("racecar") ? "Yes" : "No");
    printf("Is 'hello' a palindrome? %s\n", 
           isPalindrome("hello") ? "Yes" : "No");
    
    // Math utilities demo
    printf("\n--- Math Utilities ---\n");
    printf("2^8 = %d\n", power(2, 8));
    printf("GCD of 48 and 18: %d\n", gcd(48, 18));
    printf("LCM of 12 and 8: %d\n", lcm(12, 8));
    printf("10th Fibonacci number: %d\n", fibonacci(10));
    
    // Array utilities demo
    printf("\n--- Array Utilities ---\n");
    int numbers[] = {64, 34, 25, 12, 22, 11, 90};
    int size = sizeof(numbers) / sizeof(numbers[0]);
    
    printArray(numbers, size, "Original array");
    sortArray(numbers, size);
    printArray(numbers, size, "Sorted array");
    
    int target = 25;
    int index = binarySearch(numbers, size, target);
    if (index != -1) {
        printf("Found %d at index %d\n", target, index);
    } else {
        printf("%d not found in array\n", target);
    }
    
    return 0;
}

// String utility implementations
int stringLength(const char* str) {
    int length = 0;
    while (str[length] != '\0') {
        length++;
    }
    return length;
}

void stringReverse(char* str) {
    int len = stringLength(str);
    int start = 0;
    int end = len - 1;
    
    while (start < end) {
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
}

void stringToUpper(char* str) {
    for (int i = 0; str[i]; i++) {
        str[i] = toupper(str[i]);
    }
}

void stringToLower(char* str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

int isPalindrome(const char* str) {
    int len = stringLength(str);
    for (int i = 0; i < len / 2; i++) {
        if (tolower(str[i]) != tolower(str[len - 1 - i])) {
            return 0;
        }
    }
    return 1;
}

// Math utility implementations
int power(int base, int exp) {
    int result = 1;
    for (int i = 0; i < exp; i++) {
        result *= base;
    }
    return result;
}

int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int lcm(int a, int b) {
    return (a * b) / gcd(a, b);
}

int fibonacci(int n) {
    if (n <= 1) return n;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

// Array utility implementations
void printArray(int arr[], int size, const char* name) {
    printf("%s: [", name);
    for (int i = 0; i < size; i++) {
        printf("%d", arr[i]);
        if (i < size - 1) printf(", ");
    }
    printf("]\n");
}

void sortArray(int arr[], int size) {
    // Simple bubble sort
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int binarySearch(int arr[], int size, int target) {
    int left = 0;
    int right = size - 1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        if (arr[mid] == target) {
            return mid;
        }
        
        if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    
    return -1; // Not found
}