#include <stdio.h>

// Recursive function to compute a^b
int power(int a, int b) {
    if (b == 0) return 1;      // Base case: any number ^ 0 = 1
    if (b == 1) return a;      // Base case: any number ^ 1 = itself
    return a * power(a, b - 1); // Recursive: a^b = a * a^(b-1)
}

int main() {
    int a, b;
    scanf("%d %d", &a, &b);    // Read two space-separated integers
    printf("%d\n", power(a, b)); // Output a^b
    return 0;
}
