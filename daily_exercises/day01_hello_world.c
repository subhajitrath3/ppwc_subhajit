/*
 * Day 1: Hello World and Basic I/O
 * Demonstrates: printf, scanf, basic data types
 */

#include <stdio.h>

int main() {
    // Basic output
    printf("Hello, World!\n");
    printf("Welcome to daily C programming practice!\n");
    
    // Variables and basic data types
    int age;
    float height;
    char name[50];
    
    // Basic input
    printf("\nEnter your name: ");
    scanf("%49s", name);  // Safer input with buffer limit
    
    printf("Enter your age: ");
    scanf("%d", &age);
    
    printf("Enter your height in meters: ");
    scanf("%f", &height);
    
    // Output with formatting
    printf("\nHello %s!\n", name);
    printf("You are %d years old\n", age);
    printf("Your height is %.2f meters\n", height);
    
    return 0;
}