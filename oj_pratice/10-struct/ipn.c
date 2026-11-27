#include <stdio.h>
#include <stdlib.h>
typedef struct node{
    int id, type, price, a, b;
}node;

int cmp(const void *a, const void *b) {
    const node x = *(const node *) a;
    const node y = *(const node *) b;
    if (x.type != y.type) return (x.type > y.type) - (x.type < y.type);
    else if (x.a != y.a) return (x.a < y.a) - (x.a > y.a);
    else if (x.b != y.b) return (x.b < y.b) - (x.b > y.b);
    else if (x.price != y.price) return (x.price > y.price) - (x.price < y.price);
    else return (x.id > y.id) - (x.id < y.id);
}
int n;
node a[100005];
int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d %d %d %d %d", &a[i].id, &a[i].type, &a[i].price, &a[i].a, &a[i].b);
    qsort(a, n, sizeof(node), cmp);
    for (int i = 0; i < n; i++)
        printf("%d %d %d %d %d\n", a[i].id, a[i].type, a[i].price, a[i].a, a[i].b);
    return 0;
}