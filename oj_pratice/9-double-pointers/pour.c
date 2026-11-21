#include <stdio.h>
#include <stdlib.h>
#define N 1005
typedef struct wine{
    int v;
    float price;
    char name[21];
}wine;
int n, V, x;
wine *bowl[N];
int cnt[N];
int vol[N];

void pour(int a, int b) {
    bowl[a] = realloc(bowl[a], (cnt[a] + cnt[b]) * sizeof(wine));
    while (cnt[b] > 0 && vol[a] + bowl[b][cnt[b] - 1].v <= V) {
        bowl[a][cnt[a]++] = bowl[b][cnt[b] - 1];
        vol[a] += bowl[b][cnt[b] - 1].v;
        vol[b] -= bowl[b][cnt[b] - 1].v;
        cnt[b]--;
    }
    if (cnt[b] > 0 && vol[a] != V) {
        bowl[a][cnt[a]++] = bowl[b][cnt[b] - 1];
        bowl[a][cnt[a] - 1].v = V - vol[a];
        bowl[b][cnt[b] - 1].v -= (V - vol[a]);
        vol[b] -= (V - vol[a]); vol[a] = V;
    }
    bowl[b] = realloc(bowl[b], (cnt[b] + 1) * sizeof(wine));
}

int main() {
    scanf("%d%d%d", &n, &V, &x);
    for (int i = 0; i < n; i++) {
        wine W;
        scanf("%d %f %s", &W.v, &W.price, W.name);
        bowl[i] = malloc(sizeof(wine));
        bowl[i][0] = W;
        cnt[i] = 1;
        vol[i] = W.v;
    }
    for (int i = 0; i < x; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        pour(b, a);
    }
    for (int i = 0; i < n; i++) {
        float sum = 0;
        for (int j = 0; j < cnt[i]; j++)
            sum += bowl[i][j].price * bowl[i][j].v;
        printf("%.2f ", sum);
        for (int j = cnt[i] - 1; j > 0; j--)
            printf("%s:%d,", bowl[i][j].name, bowl[i][j].v);
        if (cnt[i] > 0) printf("%s:%d", bowl[i][0].name, bowl[i][0].v);
        printf("\n");
    }
    return 0;
}