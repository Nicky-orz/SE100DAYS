#include <bits/stdc++.h>
using namespace std;
const int maxn = 1005;
int n, m;
bool mp[maxn][maxn];
int up[maxn][maxn];
int l[maxn], r[maxn];
int ans;
int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            char t;
            cin >> t;
            if (t == 'R') mp[i][j] = false;
            else mp[i][j] = true; 
        }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            if (!mp[i][j]) continue;
            if (mp[i - 1][j]) up[i][j] = up[i - 1][j] + 1;
            else up[i][j] = 1;
        }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            l[j] = r[j] = j;
        for (int j = 0; j < m; j++)
            while(l[j] > 0 && up[i][j] <= up[i][l[j] - 1]) l[j] = l[l[j] - 1];
        for (int j = m - 1; j >= 0; j--)
            while(r[j] < m - 1 && up[i][j] <= up[i][r[j] + 1]) r[j] = r[r[j] + 1];
        for (int j = 0; j < m; j++)
            ans = max(ans, (r[j] - l[j] + 1) * up[i][j]);
    }
    cout << ans * 3;
    return 0;
}