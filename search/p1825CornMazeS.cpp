#include<bits/stdc++.h>
using namespace std;
const int N = 305;

int n, m;
char mp[N][N];
int dist[N][N];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
pair<int,int> portal[26][2];
int cnt[26];

struct Node {
    int x, y, step;
};

int bfs(int sx, int sy) {
    memset(dist, -1, sizeof(dist));
    queue<Node> q;
    q.push({sx, sy, 0});
    dist[sx][sy] = 0;
    while (!q.empty()) {
        Node cur = q.front(); q.pop();
        int x = cur.x, y = cur.y, step = cur.step;
        if (mp[x][y] >= 'A' && mp[x][y] <= 'Z') {
            int id = mp[x][y] - 'A';
            int nx, ny;
            if (x == portal[id][0].first && y == portal[id][0].second) {
                nx = portal[id][1].first;
                ny = portal[id][1].second;
            } else {
                nx = portal[id][0].first;
                ny = portal[id][0].second;
            }
            x = nx; y = ny;
        }
        if (mp[x][y] == '=') return step;
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (mp[nx][ny] == '#') continue;
            if (dist[nx][ny] != -1) continue;

            dist[nx][ny] = step + 1;
            q.push({nx, ny, step + 1});
        }
    }
    return -1;
}

int main() {
    scanf("%d%d", &n, &m);
    int sx, sy;
    for (int i = 0; i < n; i++) {
        scanf("%s", mp[i]);
        for (int j = 0; j < m; j++) {
            if (mp[i][j] == '@') {
                sx = i; sy = j;
            } else if (mp[i][j] >= 'A' && mp[i][j] <= 'Z') {
                int id = mp[i][j] - 'A';
                portal[id][cnt[id]++] = {i, j};
            }
        }
    }
    printf("%d\n", bfs(sx, sy));
    return 0;
}