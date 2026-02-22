#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int n;
    scanf("%d", &n);
    int *arr = malloc(n * sizeof(int));
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    qsort(arr, n, sizeof(int), cmp);
    
    int left = 0, right = n - 1;
    int min_diff = abs(arr[0] + arr[1]);
    int best_left = 0, best_right = 1;
    
    while (left < right) {
        int sum = arr[left] + arr[right];
        int diff = abs(sum);
        if (diff < min_diff) {
            min_diff = diff;
            best_left = left;
            best_right = right;
        }
        if (sum < 0) {
            left++;
        } else {
            right--;
        }
    }
    
    printf("%d %d\n", arr[best_left], arr[best_right]);
    free(arr);
    return 0;
}
