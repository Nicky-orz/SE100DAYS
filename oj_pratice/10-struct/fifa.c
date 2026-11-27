#include <stdio.h>
#include <stdlib.h>
typedef struct team{
    char name[25];
    int a, b, c;
}team;
int cmp1(const void *a, const void *b) {
    const team x = *(const team *) a;
    const team y = *(const team *) b;
    return (x.a < y.a) - (x.a > y.a);
}

int cmp2(const void *a, const void *b) {
    const team x = *(const team *) a;
    const team y = *(const team *) b;
    return (x.b < y.b) - (x.b > y.b);
}

int cmp3(const void *a, const void *b) {
    const team x = *(const team *) a;
    const team y = *(const team *) b;
    return (x.c < y.c) - (x.c > y.c);
}

int n;
team T[1005];
int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", T[i].name);
        int suma = 0, sumb = 0, sumc = 0;
        for (int j = 0; j < 11; j++) {
            char s[25];
            int a, b, c;
            scanf("%20s %d %d %d", s, &a, &b, &c);
            suma += a; sumb += b; sumc += c;
        }
        T[i].a = suma, T[i].b = sumb, T[i].c = sumc;
    }
    qsort(T, n, sizeof(team), cmp1);
    for (int i = 0; i < n; i++)
        printf("%s ", T[i].name);
    printf("\n");

    qsort(T, n, sizeof(team), cmp2);
    for (int i = 0; i < n; i++)
        printf("%s ", T[i].name);
    printf("\n");

    qsort(T, n, sizeof(team), cmp3);
    for (int i = 0; i < n; i++)
        printf("%s ", T[i].name);
    printf("\n");
    return 0;
}