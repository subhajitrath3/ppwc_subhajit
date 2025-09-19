/*
 * Day 5: Arrays and Strings
 * Demonstrates: array declaration, initialization, string manipulation
 */

#include <stdio.h>
#include <string.h>

int main() {
    // Array basics
    int numbers[5] = {10, 20, 30, 40, 50};
    int grades[10];
    int i, sum = 0;
    float average;
    
    printf("=== Array Basics ===\n");
    printf("Predefined array: ");
    for (i = 0; i < 5; i++) {
        printf("%d ", numbers[i]);
        sum += numbers[i];
    }
    printf("\nSum: %d\n", sum);
    
    // Dynamic array input
    printf("\nEnter 5 grades: ");
    for (i = 0; i < 5; i++) {
        scanf("%d", &grades[i]);
        sum += grades[i];
    }
    
    average = (float)sum / 5;
    printf("Average grade: %.2f\n", average);
    
    // Find maximum and minimum
    int max = grades[0], min = grades[0];
    for (i = 1; i < 5; i++) {
        if (grades[i] > max) max = grades[i];
        if (grades[i] < min) min = grades[i];
    }
    printf("Maximum grade: %d\n", max);
    printf("Minimum grade: %d\n", min);
    
    // String operations
    printf("\n=== String Operations ===\n");
    char str1[50], str2[50], str3[100];
    
    printf("Enter first string: ");
    scanf("%49s", str1);
    printf("Enter second string: ");
    scanf("%49s", str2);
    
    printf("First string: %s\n", str1);
    printf("Second string: %s\n", str2);
    printf("Length of first string: %lu\n", strlen(str1));
    
    // String concatenation
    strcpy(str3, str1);
    strcat(str3, " ");
    strcat(str3, str2);
    printf("Concatenated string: %s\n", str3);
    
    // String comparison
    int cmp = strcmp(str1, str2);
    if (cmp == 0) {
        printf("Strings are equal\n");
    } else if (cmp < 0) {
        printf("First string comes before second alphabetically\n");
    } else {
        printf("First string comes after second alphabetically\n");
    }
    
    return 0;
}