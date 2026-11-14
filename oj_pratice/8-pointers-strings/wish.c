#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define maxn 1005
#define L 105

int n;
char *p[maxn];

int cmp(const void *a, const void *b) {
    const char* x = *(const char**)a;
    const char* y = *(const char**)b;
    return strcmp(x, y);
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        p[i] = malloc(L*sizeof(char));
        scanf("%s", p[i]);
    }
    qsort(p, n, sizeof(char*), cmp);
    for (int i = 0; i < n; i++) {
        printf("%s\n", p[i]);
    }
    return 0;
}