#include <stdio.h>

#define MAX_SIZE 100

int main() {
    int m, n;
    int matrix[MAX_SIZE][MAX_SIZE];
    
    scanf("%d %d", &m, &n);
    
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
    
    if(m != n) {
        printf("Not a Symmetric Matrix\n");
        return 0;
    }
    
    int isSymmetric = 1;
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < i; j++) {
            if(matrix[i][j] != matrix[j][i]) {
                isSymmetric = 0;
                break;
            }
        }
        if(!isSymmetric) break;
    }
    
    if(isSymmetric) {
        printf("Symmetric Matrix\n");
    } else {
        printf("Not a Symmetric Matrix\n");
    }
    
    return 0;
}
