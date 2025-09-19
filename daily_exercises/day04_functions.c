/*
 * Day 4: Functions and Modular Programming
 * Demonstrates: function declaration, definition, parameter passing
 */

#include <stdio.h>

// Function declarations
int add(int a, int b);
int factorial(int n);
float calculateArea(float radius);
void printPattern(int rows);
int isPrime(int num);

int main() {
    int num1, num2, n;
    float radius;
    
    // Function call demonstration
    printf("Enter two numbers: ");
    scanf("%d %d", &num1, &num2);
    
    int result = add(num1, num2);
    printf("Sum of %d and %d is: %d\n", num1, num2, result);
    
    // Factorial calculation
    printf("\nEnter a number for factorial: ");
    scanf("%d", &n);
    printf("Factorial of %d is: %d\n", n, factorial(n));
    
    // Area calculation
    printf("\nEnter radius of a circle: ");
    scanf("%f", &radius);
    printf("Area of circle with radius %.2f is: %.2f\n", radius, calculateArea(radius));
    
    // Pattern printing
    printf("\nEnter number of rows for pattern: ");
    scanf("%d", &n);
    printPattern(n);
    
    // Prime number check
    printf("\nEnter a number to check if prime: ");
    scanf("%d", &n);
    if (isPrime(n)) {
        printf("%d is a prime number\n", n);
    } else {
        printf("%d is not a prime number\n", n);
    }
    
    return 0;
}

// Function definitions
int add(int a, int b) {
    return a + b;
}

int factorial(int n) {
    if (n <= 1) {
        return 1;
    }
    return n * factorial(n - 1);  // Recursive call
}

float calculateArea(float radius) {
    const float PI = 3.14159;
    return PI * radius * radius;
}

void printPattern(int rows) {
    printf("\nStar pattern:\n");
    for (int i = 1; i <= rows; i++) {
        for (int j = 1; j <= i; j++) {
            printf("* ");
        }
        printf("\n");
    }
}

int isPrime(int num) {
    if (num <= 1) {
        return 0;  // Not prime
    }
    
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return 0;  // Not prime
        }
    }
    return 1;  // Prime
}