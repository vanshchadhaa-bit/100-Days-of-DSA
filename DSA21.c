#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

int main() {
    int n;
    scanf("%d", &n);
    struct Node* head = NULL;
    struct Node* tail = NULL;
    for(int i = 0; i < n; i++) {
        int val;
        scanf("%d", &val);
        struct Node* node = malloc(sizeof(struct Node));
        node->data = val;
        node->next = NULL;
        if(!head) head = tail = node;
        else tail->next = node, tail = node;
    }
    while(head) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
    return 0;
}
