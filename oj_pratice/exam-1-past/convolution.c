#include <stdio.h>
#define maxn 55
int N, m;
int matrix[maxn][maxn], kernel[5][5], result[maxn][maxn];
int main() {
    scanf("%d %d", &N, &m);
    for (int i = 0; i < N; i++) 
        for (int j = 0; j < m; j++)
            scanf("%d", &matrix[i][j]);
    for (int i = 0; i < 3; i++) 
        for (int j = 0; j < 3; j++)
            scanf("%d", &kernel[i][j]);
    for (int i = 0; i < N; i++) 
        for (int j = 0; j < m; j++) {
            for (int M = 0; M < 3; M++)
                for (int N = 0; N < 3; N++)
                    result[i][j] += matrix[i + M][j + N]*kernel[M][N];
        }
    for (int i = 0; i < N - 2; i++) {
        for (int j = 0; j < m - 2; j++)
            printf("%d ", result[i][j]);
        printf("\n");
    }
        
    return 0;
}