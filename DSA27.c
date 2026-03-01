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

int getLength(struct Node* head) {
    int len = 0;
    while (head) {
        len++;
        head = head->next;
    }
    return len;
}

int findIntersection(struct Node* head1, struct Node* head2) {
    int len1 = getLength(head1);
    int len2 = getLength(head2);
    struct Node *p1 = head1, *p2 = head2;
    int diff = len1 - len2;
    if (diff < 0) {
        diff = -diff;
        p1 = head2;
        p2 = head1;
    }
    for (int i = 0; i < diff; i++) {
        p1 = p1->next;
    }
    while (p1 && p2) {
        if (p1->data == p2->data) {
            return p1->data;
        }
        p1 = p1->next;
        p2 =
