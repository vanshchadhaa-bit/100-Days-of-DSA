#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* top = NULL;

void push(int val) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = val;
    newNode->next = top;
    top = newNode;
}

int pop() {
    Node* temp = top;
    int val = temp->data;
    top = top->next;
    free(temp);
    return val;
}

int main() {
    char exp[1000];
    fgets(exp, sizeof(exp), stdin);

    int i = 0;
    while (exp[i] != '\0') {
        if (exp[i] == ' ') {
            i++;
            continue;
        }

        if (isdigit(exp[i])) {
            int num = 0;
            while (isdigit(exp[i])) {
                num = num * 10 + (exp[i] - '0');
                i++;
            }
            push(num);
        } else {
            int b = pop();
            int a = pop();

            if (exp[i] == '+') push(a + b);
            else if (exp[i] == '-') push(a - b);
            else if (exp[i] == '*') push(a * b);
            else if (exp[i] == '/') push(a / b);

            i++;
        }
    }

    printf("%d", pop());

    return 0;
}
