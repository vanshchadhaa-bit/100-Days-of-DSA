#include <stdio.h>
#include <string.h>

int main() {
    char s[1000];
    fgets(s, sizeof(s), stdin);
    
    // Remove newline if present
    int len = strlen(s);
    if (len > 0 && s[len-1] == '\n') {
        s[--len] = '\0';
    }
    
    // Two-pointer comparison
    int left = 0, right = len - 1;
    int is_palindrome = 1;
    
    while (left < right) {
        if (s[left] != s[right]) {
            is_palindrome = 0;
            break;
        }
        left++;
        right--;
    }
    
    printf("%s\n", is_palindrome ? "YES" : "NO");
    return 0;
}
