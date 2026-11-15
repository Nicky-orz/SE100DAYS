#include <stdio.h>
#define maxn 505

//左上角是(x-1,y-1), (x-1,y), (x,y-1), (x,y)
const int dx[]={-1, -1, 0, 0};
const int dy[]={-1, 0, -1, 0};
int N, m;
int mp[maxn][maxn];
int ax[maxn * maxn], ay[maxn * maxn];
bool ungrown[maxn * maxn];
int ans1[maxn * maxn], ans2[maxn * maxn], ans3[maxn * maxn];

bool check(int x, int y, int time) {
    bool che = true;
    for (int i = 0; i < 4; i++) {
        int nx = x - dx[i];
        int ny = y - dy[i];
        if (!mp[nx][ny] || !ungrown[mp[nx][ny]] || mp[nx][ny] > time) {
            che = false;
            break;
        }
    }
    return che;
}

void grow(int x, int y) {
    for (int i = 0; i < 4; i++) {
        int nx = x - dx[i];
        int ny = y - dy[i];
        ungrown[mp[nx][ny]] = false;
    }
}
int main() {
    scanf("%d %d", &N, &m);
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= m; j++) {
            scanf("%d", &mp[i][j]);
            ax[mp[i][j]] = i, ay[mp[i][j]] = j;
            ungrown[mp[i][j]] = true;
        }
    int cnt = 0;
    for (int i = 1; i < maxn * maxn; i++) {
        if (!ungrown[i]) continue;
        for (int j = 0; j < 4; j++) {
            int nx = ax[i] + dx[j];
            int ny = ay[i] + dy[j];
            if (check(nx, ny, i)) {
                grow(nx, ny);
                ans1[++cnt] = i; ans2[cnt] = nx; ans3[cnt] = ny;
                break;
            }
        }
    }
    printf("%d\n", cnt);
    for (int i = 1; i <= cnt; i++)
        printf("%d %.1f %.1f\n", ans1[i], (float) (ans2[i]*2+1)/2, (float) (ans3[i]*2+1)/2);
    return 0;
}