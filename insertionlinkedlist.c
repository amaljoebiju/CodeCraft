#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Insert a new node at the end
void insertEnd(struct Node** head, int value) {
    struct Node* newNode = createNode(value);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Function to specifically add roll number 14
void addRoll14(struct Node** head) {
    insertEnd(head, 14);
}

// Display the linked list
void displayList(struct Node* head) {
    printf("Roll Numbers in Linked List: ");
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d", temp->data);
        if (temp->next != NULL) {
            printf(" -> ");
        }
        temp = temp->next;
    }
    printf("\n");
}

// Main function
int main() {
    struct Node* head = NULL;

    // Insert values into the linked list
    insertEnd(&head, 42);   // Insert 42
    addRoll14(&head);       // Insert 14 using new function
    insertEnd(&head, 13);   // Insert 13
    insertEnd(&head, 30);   // Insert 30

    // Display the list
    displayList(head);

    return 0;
}
