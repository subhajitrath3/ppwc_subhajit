/*
 * Dynamic Data Structures - Linked List
 * Demonstrates: dynamic memory allocation, linked lists, pointers
 */

#include <stdio.h>
#include <stdlib.h>

// Node structure for linked list
struct Node {
    int data;
    struct Node* next;
};

// Function prototypes
struct Node* createNode(int data);
void insertAtBeginning(struct Node** head, int data);
void insertAtEnd(struct Node** head, int data);
void deleteNode(struct Node** head, int data);
void printList(struct Node* head);
int getLength(struct Node* head);
void freeList(struct Node** head);

int main() {
    struct Node* head = NULL;
    int choice, data;
    
    printf("=== Dynamic Linked List Demo ===\n");
    
    do {
        printf("\n--- Menu ---\n");
        printf("1. Insert at beginning\n");
        printf("2. Insert at end\n");
        printf("3. Delete node\n");
        printf("4. Print list\n");
        printf("5. Get length\n");
        printf("6. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                insertAtBeginning(&head, data);
                printf("Inserted %d at beginning\n", data);
                break;
                
            case 2:
                printf("Enter data: ");
                scanf("%d", &data);
                insertAtEnd(&head, data);
                printf("Inserted %d at end\n", data);
                break;
                
            case 3:
                printf("Enter data to delete: ");
                scanf("%d", &data);
                deleteNode(&head, data);
                break;
                
            case 4:
                printf("Current list: ");
                printList(head);
                break;
                
            case 5:
                printf("List length: %d\n", getLength(head));
                break;
                
            case 6:
                printf("Freeing memory and exiting...\n");
                freeList(&head);
                break;
                
            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 6);
    
    return 0;
}

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Error: Memory allocation failed!\n");
        return NULL;
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertAtBeginning(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (newNode == NULL) return;
    
    newNode->next = *head;
    *head = newNode;
}

void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (newNode == NULL) return;
    
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    
    struct Node* current = *head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
}

void deleteNode(struct Node** head, int data) {
    if (*head == NULL) {
        printf("List is empty!\n");
        return;
    }
    
    struct Node* current = *head;
    
    // If head node contains the data
    if (current->data == data) {
        *head = current->next;
        free(current);
        printf("Deleted %d from list\n", data);
        return;
    }
    
    // Search for the node to delete
    while (current->next != NULL && current->next->data != data) {
        current = current->next;
    }
    
    if (current->next == NULL) {
        printf("Data %d not found in list\n", data);
        return;
    }
    
    struct Node* nodeToDelete = current->next;
    current->next = nodeToDelete->next;
    free(nodeToDelete);
    printf("Deleted %d from list\n", data);
}

void printList(struct Node* head) {
    if (head == NULL) {
        printf("Empty list\n");
        return;
    }
    
    struct Node* current = head;
    while (current != NULL) {
        printf("%d", current->data);
        if (current->next != NULL) {
            printf(" -> ");
        }
        current = current->next;
    }
    printf(" -> NULL\n");
}

int getLength(struct Node* head) {
    int count = 0;
    struct Node* current = head;
    
    while (current != NULL) {
        count++;
        current = current->next;
    }
    
    return count;
}

void freeList(struct Node** head) {
    struct Node* current = *head;
    struct Node* next;
    
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
    
    *head = NULL;
    printf("All memory freed\n");
}