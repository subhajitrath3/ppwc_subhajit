/*
 * Day 7: Structures and User-Defined Types
 * Demonstrates: struct definition, initialization, array of structures
 */

#include <stdio.h>
#include <string.h>
#include <math.h>

// Structure definitions
struct Student {
    int id;
    char name[50];
    float gpa;
    int age;
};

struct Point {
    float x;
    float y;
};

// Function prototypes
void printStudent(struct Student s);
void inputStudent(struct Student *s);
float calculateDistance(struct Point p1, struct Point p2);

int main() {
    // Single structure
    printf("=== Single Structure Demo ===\n");
    struct Student student1 = {101, "Alice Johnson", 3.85, 20};
    
    printf("Student Information:\n");
    printStudent(student1);
    
    // Structure with user input
    printf("\n=== User Input Structure ===\n");
    struct Student student2;
    inputStudent(&student2);
    printf("\nYou entered:\n");
    printStudent(student2);
    
    // Array of structures
    printf("\n=== Array of Structures ===\n");
    struct Student students[3];
    
    printf("Enter information for 3 students:\n");
    for (int i = 0; i < 3; i++) {
        printf("\nStudent %d:\n", i + 1);
        inputStudent(&students[i]);
    }
    
    // Find student with highest GPA
    int topIndex = 0;
    for (int i = 1; i < 3; i++) {
        if (students[i].gpa > students[topIndex].gpa) {
            topIndex = i;
        }
    }
    
    printf("\n=== Results ===\n");
    printf("All students:\n");
    for (int i = 0; i < 3; i++) {
        printf("Student %d: ", i + 1);
        printStudent(students[i]);
    }
    
    printf("\nStudent with highest GPA:\n");
    printStudent(students[topIndex]);
    
    // Point structure demo
    printf("\n=== Point Structure Demo ===\n");
    struct Point p1, p2;
    
    printf("Enter coordinates for point 1 (x y): ");
    scanf("%f %f", &p1.x, &p1.y);
    
    printf("Enter coordinates for point 2 (x y): ");
    scanf("%f %f", &p2.x, &p2.y);
    
    float distance = calculateDistance(p1, p2);
    printf("Distance between (%.2f, %.2f) and (%.2f, %.2f) is: %.2f\n", 
           p1.x, p1.y, p2.x, p2.y, distance);
    
    return 0;
}

void printStudent(struct Student s) {
    printf("ID: %d, Name: %s, GPA: %.2f, Age: %d\n", 
           s.id, s.name, s.gpa, s.age);
}

void inputStudent(struct Student *s) {
    printf("Enter student ID: ");
    scanf("%d", &s->id);
    
    printf("Enter student name: ");
    scanf("%49s", s->name);
    
    printf("Enter GPA: ");
    scanf("%f", &s->gpa);
    
    printf("Enter age: ");
    scanf("%d", &s->age);
}

float calculateDistance(struct Point p1, struct Point p2) {
    float dx = p2.x - p1.x;
    float dy = p2.y - p1.y;
    return sqrt(dx * dx + dy * dy);
}