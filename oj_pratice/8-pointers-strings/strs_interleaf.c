#include <stdio.h>
#include <string.h>
#define N 1025

int main() {
    int t;
    scanf("%d\n", &t);
    char s[2*N]={};
    while (t-- && fgets(s, sizeof(s), stdin) != NULL) {
        char s1[N], s2[N];
        char ans[2*N] = {};
        int d1, d2, size;
        sscanf(s, "%[^;];%[^;];%d;%d;%d", s1, s2, &d1, &d2, &size);
        //printf("%s;%s;%d;%d;%d", s1, s2, d1, d2, size);
        int i = 0, j = 0, k = 0;
        int l1 = strlen(s1) , l2 = strlen(s2);
        size--;
        while (k < size && i < l1 && j < l2) {
            for (int t = 0; k < size && i < l1 && t < d1; t++)
                ans[k++] = s1[i++];
            for (int t = 0; k < size && j < l2 && t < d2; t++)
                ans[k++] = s2[j++];
        }
        while (k < size && i < l1)
            ans[k++] = s1[i++];
        while (k < size && j < l2)
            ans[k++] = s2[j++];
        printf("%s\n",ans);
    }
    return 0;
}