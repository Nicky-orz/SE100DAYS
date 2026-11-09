#include <bits/stdc++.h>
using namespace std;

struct Node {
    int x,y;
    int val;
    bool operator<(const Node& o) const {
        if (val != o.val) return val > o.val;
        else return x > o.x;
    }
};

const int maxn = 200005;

priority_queue <Node> h;

int a[maxn];
int nxt[maxn];
int pre[maxn];
bool vis[maxn];

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        nxt[i] = i + 1;
        pre[i] = i - 1;
    }
    for (int i = 1; i < n; i++)
        if (s[i] != s[i-1])
            h.push({i-1, i, abs(a[i-1] - a[i])});
    vector <Node> ans;
    while (!h.empty()) {
        Node t = h.top();
        h.pop();
        if (!vis[t.x] && !vis[t.y]) {
            ans.push_back({t.x + 1, t.y + 1, 0});
            vis[t.x] = vis[t.y] = true;
            int nx = pre[t.x], ny = nxt[t.y];
            if (nx >= 0 && ny < n && s[nx] != s[ny])
                h.push({nx, ny, abs(a[nx] - a[ny])});
            nxt[pre[t.x]] = ny;
            pre[nxt[t.y]] = nx;
        }
    }
    cout << ans.size() << "\n";
    for (auto i : ans) {
        cout << i.x << " " << i.y << "\n";
    }
    return 0;
}