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

void appendNode(struct Node** head_ref, int data) {
    struct Node* newNode = createNode(data);
    if (*head_ref == NULL) {
        *head_ref = newNode;
        return;
    }
    struct Node* tail = *head_ref;
    while (tail->next != NULL) {
        tail = tail->next;
    }
    tail->next = newNode;
}

void printList(struct Node* head) {
    if (head == NULL) {
        printf("\n");
        return;
    }
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

void freeList(struct Node* head) {
    while (head != NULL) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    int n;
    scanf("%d", &n);

    struct Node* head = NULL;

    for (int i = 0; i < n; i++) {
        int val;
        scanf("%d", &val);
        appendNode(&head, val);
    }

    int k;
    scanf("%d", &k);

    if (n <= 1 || k % n == 0) {
        printList(head);
        freeList(head);
        return 0;
    }

    k = k % n;

    // Find tail
    struct Node* tail = head;
    while (tail->next != NULL) {
        tail = tail->next;
    }

    // Make circular
    tail->next = head;

    // Traverse (n - k - 1) steps to reach new_tail (the (n-k)th node)
    struct Node* new_tail = head;
    for (int i = 0; i < n - k - 1; i++) {
        new_tail = new_tail->next;
    }

    // Update head and break circle
    struct Node* newHead = new_tail->next;
    new_tail->next = NULL;
    head = newHead;

    printList(head);
    freeList(head);
    return 0;
}
