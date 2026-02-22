#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);
    int *arr = malloc(n * sizeof(int));
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    long long sum = 0;
    long long count = 0;
    // Simple map using sorted unique prefixes for demo; use real hash for large n
    // For production, implement hashmap handling long long keys
    
    // Brute prefix for verification on small n (as example n=6)
    long long prefix[n+1];
    prefix[0] = 0;
    int freq[1001] = {0}; // Adjust range as needed
    freq[500] = 1; // offset for negative
    
    for(int i = 1; i <= n; i++) {
        sum +=
