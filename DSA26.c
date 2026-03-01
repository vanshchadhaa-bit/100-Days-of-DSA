#include <stdio.h>
#include <stdlib.h>

// Doubly linked list node structure
typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

// Insert new node at tail of doubly linked list
void insertAtTail(Node** head_ref, int data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;
    new_node->prev = NULL;
    
    if (*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }
    
    Node* last = *head_ref;
    while (last->next != NULL) {
        last = last->next;
    }
    
    last->next = new_node;
    new_node->prev = last;
}

// Print linked list forward (head -> tail)
void printForward(Node* head) {
    Node* curr = head;
    while (curr != NULL) {
        printf("%d", curr->data);
        if (curr->next != NULL) {
            printf(" ");
        }
        curr = curr->next;
    }
    printf("\n");
}

// Free memory to prevent leaks
void freeList(Node* head) {
    Node* curr = head;
    while (curr != NULL) {
        Node* temp = curr;
        curr = curr->next;
        free(temp);
    }
}

int main() {
    int n;
    scanf("%d", &n);
    
    Node* head = NULL;
    
    // Read n integers and insert each at tail
    for (int i = 0; i < n; i++) {
        int data;
        scanf("%d", &data);
        insertAtTail(&head, data);
    }
    
    // Print forward traversal
    printForward(head);
    
    // Cleanup
    freeList(head);
    
    return 0;
}
