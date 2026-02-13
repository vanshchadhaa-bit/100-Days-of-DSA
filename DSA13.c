#include <stdio.h>

#define MAX_SIZE 100

int main() {
    int r, c;
    int matrix[MAX_SIZE][MAX_SIZE];
    
    scanf("%d %d", &r, &c);
    
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
    
    int min_r = 0, min_c = 0, max_r = r - 1, max_c = c - 1;
    
    while(min_r <= max_r && min_c <= max_c) {
        // Top row
        for(int j = min_c; j <= max_c; j++) {
            printf("%d ", matrix[min_r][j]);
        }
        min_r++;
        
        // Right column
        for(int i = min_r; i <= max_r; i++) {
            printf("%d ", matrix[i][max_c]);
        }
        max_c--;
        
        // Bottom row (if still valid)
        if(min_r <= max_r) {
            for(int j = max_c; j >= min_c; j--) {
                printf("%d ", matrix[max_r][j]);
            }
            max_r--;
        }
        
        // Left column (if still valid)
        if(min_c <= max_c) {
            for(int i = max_r; i >= min_r; i--) {
                printf("%d ", matrix[i][min_c]);
            }
            min_c++;
        }
    }
    
    printf("\n");
    return 0;
}
