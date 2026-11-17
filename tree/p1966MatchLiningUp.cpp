#include <bits/stdc++.h>
using namespace std;
const int maxn = 100005;
const int mod = 1e8 - 3;
struct P{
    int val, id;
};

int n;
P a[maxn], b[maxn];
int c[maxn];
int h[maxn];

bool cmp(P a, P b) {
    return a.val < b.val;
}

void add(int x, int k) {
    while (x <= n) {
        h[x] += k;
        x += (x & (-x));
    }
}

int sum(int x) {
    int t = 0;
    while (x > 0) {
        t += h[x];
        x -= (x & (-x));
    }
    return t;
}
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i].val, a[i].id = i;
    for (int i = 1; i <= n; i++) cin >> b[i].val, b[i].id = i;
    sort(a + 1, a + n + 1, cmp);
    sort(b + 1, b + n + 1, cmp);
    for (int i = 1; i <= n; i++)
        c[a[i].id] = b[i].id;
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        ans = (ans + i - 1 - sum(c[i])) % mod;
        add(c[i], 1);
    }
    cout << ans;
    return 0;
}