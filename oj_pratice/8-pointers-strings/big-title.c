#include <stdio.h>
#include <stdlib.h>
int main() {
    char *s;
    s = malloc(2005  * sizeof(char));
    while (scanf("%s", s) == 1) {
        char top = *s;
        if (top >= 'a' && top <= 'z')
            *s = top - 'a' + 'A';
        for (int i = 1; *(s + i) != '\0'; i++) {
            char letter = *(s + i);
            if (letter >= 'A' && letter <= 'Z')
                *(s + i) = letter - 'A' + 'a';
        }
        printf("%s ", s);
    }
    return 0;
}