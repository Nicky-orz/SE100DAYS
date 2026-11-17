#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define maxn 100005

int main() {
    char *s = malloc(maxn * sizeof(char));
    char *t = malloc(maxn * sizeof(char));
    scanf("%s %s", s, t);
    for (int i = 0; *(s + i) != '\0'; i++) {
        char S = *(s + i);
        if (S == *t) {
            int j = 0;
            while (*(s + i + j) == *(t + j) && *(s + i + j) != '\0' && *(t + j) != '\0')
                j++;
            if (*(t + j) == '\0')
                printf("%d ", i);
        }
    }
        

    return 0;
}