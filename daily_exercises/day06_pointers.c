/*
 * Day 6: Pointers and Memory Management
 * Demonstrates: pointer basics, pointer arithmetic, dynamic memory
 */

#include <stdio.h>
#include <stdlib.h>

void swapValues(int *a, int *b);
void printArray(int *arr, int size);
int* createArray(int size);

int main() {
    // Pointer basics
    printf("=== Pointer Basics ===\n");
    int num = 42;
    int *ptr = &num;
    
    printf("Value of num: %d\n", num);
    printf("Address of num: %p\n", (void*)&num);
    printf("Value of ptr: %p\n", (void*)ptr);
    printf("Value pointed by ptr: %d\n", *ptr);
    
    // Modify value through pointer
    *ptr = 100;
    printf("After modifying through pointer: %d\n", num);
    
    // Pointer arithmetic
    printf("\n=== Pointer Arithmetic ===\n");
    int arr[] = {10, 20, 30, 40, 50};
    int *arrPtr = arr;
    
    printf("Array elements using pointer arithmetic:\n");
    for (int i = 0; i < 5; i++) {
        printf("arr[%d] = %d (address: %p)\n", i, *(arrPtr + i), (void*)(arrPtr + i));
    }
    
    // Function with pointers - pass by reference
    printf("\n=== Pass by Reference ===\n");
    int x = 10, y = 20;
    printf("Before swap: x = %d, y = %d\n", x, y);
    swapValues(&x, &y);
    printf("After swap: x = %d, y = %d\n", x, y);
    
    // Dynamic memory allocation
    printf("\n=== Dynamic Memory Allocation ===\n");
    int size;
    printf("Enter size for dynamic array: ");
    scanf("%d", &size);
    
    int *dynamicArr = createArray(size);
    if (dynamicArr == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }
    
    printf("Enter %d elements: ", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &dynamicArr[i]);
    }
    
    printf("Dynamic array contents: ");
    printArray(dynamicArr, size);
    
    // Free allocated memory
    free(dynamicArr);
    printf("Memory freed successfully\n");
    
    return 0;
}

void swapValues(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void printArray(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int* createArray(int size) {
    int *arr = (int*)malloc(size * sizeof(int));
    return arr;
}