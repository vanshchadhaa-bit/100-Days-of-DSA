#include <stdio.h>
#include <stdlib.h>

typedef struct Term {
    int coeff;
    int exp;
    struct Term* next;
} Term;

Term* createTerm(int c, int e) {
    Term* newTerm = (Term*)malloc(sizeof(Term));
    newTerm->coeff = c;
    newTerm->exp = e;
    newTerm->next = NULL;
    return newTerm;
}

void appendTerm(Term** head, int c, int e) {
    Term* newTerm = createTerm(c, e);
    if (*head == NULL) {
        *head = newTerm;
        return;
    }
    Term* tail = *head;
    while (tail->next != NULL) {
        tail = tail->next;
    }
    tail->next = newTerm;
}

void printPolynomial(Term* head) {
    if (head == NULL) {
        printf("0");
        return;
    }
    Term* current = head;
    int first = 1;
    while (current != NULL) {
        if (!first) {
            printf(" + ");
        }
        printf("%dx^%d", current->coeff, current->exp);
        current = current->next;
        first = 0;
    }
    printf("\n");
}

void freePoly(Term* head) {
    while (head != NULL) {
        Term* temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    int n;
    scanf("%d", &n);
    Term* poly = NULL;
    for (int i = 0; i < n; i++) {
        int c, e;
        scanf("%d %d", &c, &e);
        appendTerm(&poly, c, e);
    }
    printPolynomial(poly);
    freePoly(poly);
    return 0;
}
