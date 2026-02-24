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

struct Node* buildList(int n) {
    struct Node* head = NULL;
    struct Node* tail = NULL;
    for(int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        struct Node* node = createNode(x);
        if(head == NULL) {
            head = tail = node;
        } else {
            tail->next = node;
            tail = node;
        }
    }
    return head;
}

struct Node* mergeLists(struct Node* a, struct Node* b) {
    struct Node dummy;
    struct Node* tail = &dummy;
    while(a != NULL && b != NULL) {
        if(a->data <= b->data) {
            tail->next = a;
            a = a->next;
        } else {
            tail->next = b;
            b = b->next;
        }
        tail = tail->next;
    }
    tail->next = (a != NULL) ? a : b;
    return dummy.next;
}

void printList(struct Node* head) {
    struct Node* curr = head;
    int first = 1;
    while(curr != NULL) {
        if(!first) printf(" ");
        printf("%d", curr->data);
        first = 0;
        curr = curr->next;
    }
    printf("\n");
}

void freeList(struct Node* head) {
    while(head != NULL) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    int n;
    scanf("%d", &n);
    struct Node* list1 = buildList(n);
    
    int m;
    scanf("%d", &m);
    struct Node* list2 = buildList(m);
    
    struct Node* merged = mergeLists(list1, list2);
    
    printList(merged);
    
    freeList(list1);
    freeList(list2);
    // Note: merged shares nodes with list1 and list2, so freeing one frees all
    return 0;
}
