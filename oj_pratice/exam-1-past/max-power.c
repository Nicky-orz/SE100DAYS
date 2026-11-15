#include <stdio.h>
#define maxn 1005
#define MAX 10005
int N;
int a[maxn];

int max(int a, int b) {
    return a < b? b : a;
}

int min(int a, int b) {
    return a < b? a : b;
}

int main() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
        scanf("%d", &a[i]);
    int ans = 0;
    for (int i = 0; i < N; i++) {
        int mind = MAX, maxd = -MAX;
        for (int j = i-1; j >= 0; j--)
            mind = min(mind, a[j]);
        for (int j = i; j < N; j++)
            maxd = max(maxd, a[j]);
        ans = max(ans, maxd - mind);
        //printf("%d\n", maxd - mind);
    }
    printf("%d", ans);
    return 0;
}