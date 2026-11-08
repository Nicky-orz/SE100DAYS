#include <stdio.h>

#define N 100

void merge(int *arr1, int m, int *arr2, int n, int *ret) {
    int i = 0, j = 0, k = 0;
    while (i < m && j < n) {
        if (arr1[i] < arr2[j]) 
            ret[k++] = arr1[i++];
        else ret[k++] = arr2[j++];
    }
    while (i < m)
        ret[k++] = arr1[i++];
    while (j < n)
        ret[k++] = arr2[j++];
}

int main() {
    int m, n;
    int arr1[N], arr2[N], ret[2 * N];

    scanf("%d%d", &m, &n);
    for (int i = 0; i < m; i++) {
        scanf("%d", &arr1[i]);
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr2[i]);
    }
    merge(arr1, m, arr2, n, ret);
    for (int i = 0; i < m + n; i++) {
        printf("%d ", ret[i]);
    }
    return 0;
}
