#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

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

// ✅ New function to add roll no 14
void addRoll14(struct Node** head) {
    insertEnd(head, 14);
}

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

int main() {
    struct Node* head = NULL;

    insertEnd(&head, 42);

    // using new function to add roll number 14
    addRoll 14(&head);
    insertEnd(&head,  7);
    insertEnd(&head, 13);
    insertEnd(&head, 30);

    displayList(head);

    return 0;
}
