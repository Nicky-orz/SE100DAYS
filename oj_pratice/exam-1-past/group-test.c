#include <stdio.h>
#include <stdlib.h>
#define maxm 1005
int n, m;
int a[maxm][maxm];
int c[maxm];
int r[maxm];
bool negative[maxm], postive[maxm];
int C[maxm], P[maxm];
int solve[maxm];
int Ccnt, Pcnt, Scnt;

int cmp(const void *a, const void *b) {
    int x = *(const int*) a;
    int y = *(const int*) b;
    return (x > y) - (x < y);
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &c[i], &r[i]);
        for (int j = 0; j < c[i]; j++)
            scanf("%d", &a[i][j]);
    }

    //1.3.
    for (int i = 0; i < m; i++) {
        if (!r[i])
            for (int j = 0; j < c[i]; j++)
                negative[a[i][j]] = true;
        else if (c[i] == 1) {
                if(!postive[a[i][0]])
                    P[Pcnt++] = a[i][0], postive[a[i][0]] = true;
            }
             else solve[Scnt++] = i;
    }
    //2.
    for (int i = 1; i <= n; i++) 
        if (!negative[i]) C[Ccnt++] = i;
    //3.
    for (int i = 0; i < Ccnt; i++)
        for (int j = 0; j < Pcnt; j++)
            if (C[i] == P[j]) {C[i] = -1; break;}
    int unsolved = Scnt;
    for (int i = 0; i < Scnt; i++)
        for (int j = 0; j < c[solve[i]]; j++)
            if (postive[a[solve[i]][j]]) {solve[i] = -1; unsolved--; break;}
    //4.
    while (unsolved > 0) {
        int maxnum = 0, pos = 0;
        for (int i = 0; i < Ccnt; i++) { //s = C[i]
            if (C[i] == -1) continue;
            int num = 0;
            for (int j = 0; j < Scnt; j++) { //集合名solve[j]
                if (solve[j] == -1) continue;
                for (int k = 0; k < c[solve[j]]; k++)
                    if (a[solve[j]][k] == C[i]) {num++; break;}
            }
            if (num > maxnum)
                maxnum = num, pos = i;
        }
        for (int j = 0; j < Scnt; j++) {
            if (solve[j] == -1) continue;
            for (int k = 0; k < c[solve[j]]; k++)
                if (a[solve[j]][k] == C[pos]) {solve[j] = -1; break;}
        }
        P[Pcnt++] = C[pos]; postive[C[pos]] = true; C[pos] = -1;
        unsolved -= maxnum;
        if (maxnum == 0) break;
    }
    //5.
    printf("%d\n", Pcnt);
    qsort(P, Pcnt, sizeof(int), cmp);
    for (int i = 0; i < Pcnt; i++)
        printf("%d ", P[i]);
    return 0;
}