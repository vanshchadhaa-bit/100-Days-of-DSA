#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void deleteFirstOccurrence(struct Node** headRef, int key) {
    struct Node* temp = *headRef;
    
    // If head itself holds the key
    if (temp != NULL && temp->data == key) {
        *headRef = temp->next;
        free(temp);
        return;
    }
    
    // Search for key and delete
    while (temp != NULL && temp->next != NULL) {
        if (temp->next->data == key) {
            struct Node* toDelete = temp->next;
            temp->next = toDelete->next;
            free(toDelete);
            return;
        }
        temp = temp->next;
    }
}

void printList(struct Node* head) {
    struct Node* current = head;
    int first = 1;
    while (current != NULL) {
        if (!first) printf(" ");
        printf("%d", current->data);
        first = 0;
        current = current->next;
    }
    printf("\n");
}

void freeList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        struct Node* temp = current;
        current = current->next;
        free(temp);
    }
}

int main() {
    int n;
    scanf("%d", &n);
    
    struct Node* head = NULL;
    struct Node* tail = NULL;
    
    for (int i = 0; i < n; i++) {
        int data;
        scanf("%d", &data);
        struct Node* newNode = createNode(data);
        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    
    int key;
    scanf("%d", &key);
    
    deleteFirstOccurrence(&head, key);
    printList(head);
    
    freeList(head);
    return 0;
}
