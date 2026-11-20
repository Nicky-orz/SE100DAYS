#include <stdio.h>
#include <stdlib.h>
int n, q;
int a[1000005];
int cmp(const void *a, const void *b) {
    int x = *(const int*)a;
    int y = *(const int*)b;
    return (x < y) - (x > y);
}
int main() {
    scanf("%d %d", &n, &q);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    while (q--) {
        int t;
        scanf("%d", &t);
        int *p = bsearch(&t, a, n, sizeof(int), cmp);
        if (p != NULL)
            printf("%d\n", (int)(p - a));
        else
            printf("-1\n");
    }
    return 0;
}