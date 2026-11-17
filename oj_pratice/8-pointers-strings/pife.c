#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define maxn 1005
int main() {
    int n;
    scanf("%d", &n);
    char *s = malloc(maxn * sizeof(char));
    scanf("%s", s);
    int len = strlen(s);
    while (n--) {
        char *nxt = malloc(maxn * sizeof(char));
        for (int i = 0; i < len; i++)
            *(nxt + i) = *(s + i);
        for (int i = 0; i < len; i++) {
            char t = *(s + i);
            int numA = 0, numB = 0;
            for (int j = 1; j <= 3; j++) {
                char t1 = '\0', t2 = '\0';
                if (i - j >= 0) t1 = *(s + i - j);
                if (i + j < len) t2 = *(s + i + j);
                if (t1 == 'A') numA++;
                if (t2 == 'A') numA++;
                if (t1 == 'B') numB++;
                if (t2 == 'B') numB++;
            }
            if (t == '.') {
                if (numA >= 2 && numA <= 4 && numB == 0)
                    *(nxt + i) = 'A';
                else if (numB >= 2 && numB <= 4 && numA == 0)
                    *(nxt + i) = 'B';
            }
            if (t == 'A') {
                if (numB > 0 || numA >= 5 || numA <= 1)
                    *(nxt + i) = '.';
            }
            if (t == 'B') {
                if (numA > 0 || numB >= 5 || numB <= 1)
                    *(nxt + i) = '.';
            }
        }
        for (int i = 0; i < len; i++)
            *(s + i) = *(nxt + i);
    }
    printf("%s", s);
    return 0;
}