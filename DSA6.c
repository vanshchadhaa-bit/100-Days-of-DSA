#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    int arr[200];  // Constraints imply n <= 200
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    if(n == 0) return 0;
    
    int i = 0;
    for(int j = 1; j < n; j++) {
        if(arr[i] != arr[j]) {
            i++;
            arr[i] = arr[j];
        }
    }
    
    for(int k = 0; k <= i; k++) {
        printf("%d", arr[k]);
        if(k < i) printf(" ");
    }
    printf("\n");
    return 0;
}
