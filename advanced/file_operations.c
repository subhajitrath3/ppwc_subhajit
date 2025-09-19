/*
 * File Operations Demo
 * Demonstrates: file I/O, reading/writing files, error handling
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void writeToFile(const char* filename);
void readFromFile(const char* filename);
void appendToFile(const char* filename);
int countLinesInFile(const char* filename);

int main() {
    const char* filename = "sample_data.txt";
    
    printf("=== File Operations Demo ===\n");
    
    // Write to file
    printf("1. Writing initial data to file...\n");
    writeToFile(filename);
    
    // Read from file
    printf("\n2. Reading from file:\n");
    readFromFile(filename);
    
    // Append to file
    printf("\n3. Appending more data...\n");
    appendToFile(filename);
    
    // Read again to show appended data
    printf("\n4. Reading file after append:\n");
    readFromFile(filename);
    
    // Count lines
    int lines = countLinesInFile(filename);
    printf("\n5. Total lines in file: %d\n", lines);
    
    // Clean up
    remove(filename);
    printf("\n6. Cleaned up temporary file.\n");
    
    return 0;
}

void writeToFile(const char* filename) {
    FILE* file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error: Could not open file for writing!\n");
        return;
    }
    
    fprintf(file, "Line 1: Hello, File!\n");
    fprintf(file, "Line 2: This is a demonstration of file operations.\n");
    fprintf(file, "Line 3: C programming with files is powerful.\n");
    
    fclose(file);
    printf("Successfully wrote to %s\n", filename);
}

void readFromFile(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: Could not open file for reading!\n");
        return;
    }
    
    char line[256];
    int lineNumber = 1;
    
    while (fgets(line, sizeof(line), file) != NULL) {
        printf("  %d: %s", lineNumber++, line);
    }
    
    fclose(file);
}

void appendToFile(const char* filename) {
    FILE* file = fopen(filename, "a");
    if (file == NULL) {
        printf("Error: Could not open file for appending!\n");
        return;
    }
    
    fprintf(file, "Line 4: This line was appended.\n");
    fprintf(file, "Line 5: File operations are essential in C.\n");
    
    fclose(file);
    printf("Successfully appended to %s\n", filename);
}

int countLinesInFile(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: Could not open file for counting!\n");
        return -1;
    }
    
    int count = 0;
    char ch;
    
    while ((ch = fgetc(file)) != EOF) {
        if (ch == '\n') {
            count++;
        }
    }
    
    fclose(file);
    return count;
}