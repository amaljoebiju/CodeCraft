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


void searchNode(struct Node* head, int value) {
    struct Node* temp = head;
    int position = 1; 
    while (temp != NULL) {
        if (temp->data == value) {
            printf("Value %d found at position %d in the list.\n", value, position);
            return;
        }
        temp = temp->next;
        position++;
    }
    printf("Value %d not found in the list.\n", value);
}

int main() {
    struct Node* head = NULL;

    insertEnd(&head, 42);
    insertEnd(&head, 14);
    insertEnd(&head, 13);
    insertEnd(&head, 30);

    displayList(head);

   
    searchNode(head, 14);

    return 0;
}
