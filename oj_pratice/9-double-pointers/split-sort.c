#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char *s;
char d;
char *ans[105];
int cnt;

int cmp(const void *a, const void *b) {
    const char *x = *(const char*const *) a;
    const char *y = *(const char*const *) b; 
    return strcmp(x, y);
}

int main() {
    s = malloc(10005 * sizeof(char));
    scanf("%s", s);
    scanf(" %c", &d);
    char D[2] = {d, '\0'};
    char *p = strtok(s, D);
    while (p != NULL) {
        ans[cnt++] = p;
        p = strtok(NULL, D);
    }
    qsort(ans, cnt, sizeof(char*), cmp);
    for (int i = 0; i < cnt; i++)
        printf("%s\n", ans[i]);
    return 0;
}