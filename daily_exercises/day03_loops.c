/*
 * Day 3: Loops and Iterations
 * Demonstrates: for loop, while loop, do-while loop
 */

#include <stdio.h>

int main() {
    int n, i, sum = 0;
    
    printf("Enter a positive number: ");
    scanf("%d", &n);
    
    // For loop demonstration - print numbers 1 to n
    printf("\n=== For Loop Demo ===\n");
    printf("Numbers from 1 to %d:\n", n);
    for (i = 1; i <= n; i++) {
        printf("%d ", i);
    }
    printf("\n");
    
    // While loop demonstration - calculate sum of numbers 1 to n
    printf("\n=== While Loop Demo ===\n");
    i = 1;
    sum = 0;
    while (i <= n) {
        sum += i;
        i++;
    }
    printf("Sum of numbers from 1 to %d is: %d\n", n, sum);
    
    // Do-while loop demonstration - input validation
    printf("\n=== Do-While Loop Demo ===\n");
    int choice;
    do {
        printf("Enter a number between 1 and 10: ");
        scanf("%d", &choice);
        if (choice < 1 || choice > 10) {
            printf("Invalid input! Please try again.\n");
        }
    } while (choice < 1 || choice > 10);
    printf("You entered: %d\n", choice);
    
    // Nested loops - multiplication table
    printf("\n=== Nested Loops Demo ===\n");
    printf("Multiplication table for %d:\n", choice);
    for (i = 1; i <= 10; i++) {
        printf("%d x %d = %d\n", choice, i, choice * i);
    }
    
    return 0;
}