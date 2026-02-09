#include <stdio.h>
#include <string.h>

int main() {
    char str[1000];  // Buffer for input line (alphabets only, no spaces)
    fgets(str, sizeof(str), stdin);  // Read single line
    str[strcspn(str, "\n")] = 0;     // Remove trailing newline

    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - 1 - i];
        str[len - 1 - i] = temp;
    }
    printf("%s\n", str);
    return 0;
}
