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

int countOccurrences(struct Node* head, int key) {
    int count = 0;
    struct Node* current = head;
    while (current != NULL) {
        if (current->data == key) {
            count++;
        }
        current = current->next;
    }
    return count;
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
    
    printf("%d\n", countOccurrences(head, key));
    
    // Free memory to prevent leaks
    struct Node* current = head;
    while (current != NULL) {
        struct Node* temp = current;
        current = current->next;
        free(temp);
    }
    
    return 0;
}
