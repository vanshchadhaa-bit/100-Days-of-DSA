#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        if(i > 0) printf(" ");
        printf("%d", x);
    }
    printf("\n");
    return 0;
}
