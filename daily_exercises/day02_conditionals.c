/*
 * Day 2: Control Structures - Conditionals
 * Demonstrates: if-else, switch-case, comparison operators
 */

#include <stdio.h>

int main() {
    int number, choice;
    
    printf("Enter a number: ");
    scanf("%d", &number);
    
    // If-else demonstration
    printf("\n=== If-Else Demo ===\n");
    if (number > 0) {
        printf("%d is positive\n", number);
    } else if (number < 0) {
        printf("%d is negative\n", number);
    } else {
        printf("The number is zero\n");
    }
    
    // Even/odd check
    if (number % 2 == 0) {
        printf("%d is even\n", number);
    } else {
        printf("%d is odd\n", number);
    }
    
    // Switch-case demonstration
    printf("\n=== Switch-Case Demo ===\n");
    printf("Choose an operation:\n");
    printf("1. Square the number\n");
    printf("2. Double the number\n");
    printf("3. Check if divisible by 5\n");
    printf("Enter choice (1-3): ");
    scanf("%d", &choice);
    
    switch (choice) {
        case 1:
            printf("Square of %d is %d\n", number, number * number);
            break;
        case 2:
            printf("Double of %d is %d\n", number, number * 2);
            break;
        case 3:
            if (number % 5 == 0) {
                printf("%d is divisible by 5\n", number);
            } else {
                printf("%d is not divisible by 5\n", number);
            }
            break;
        default:
            printf("Invalid choice!\n");
    }
    
    return 0;
}