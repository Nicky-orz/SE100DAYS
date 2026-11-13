#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 500005;

int n;
int a[maxn];
ll c[maxn];

int lowbit(int x) {
    return x & (-x);
}

void add(int x, ll k) {
    while (x <= n) {
        c[x] += k;
        x += lowbit(x);
    }
}

ll query(int x, int y) {
    int t1 = 0, t2 = 0;
    if (x > y) swap(x, y);
    x--;
    while (x > 0) {
        t1 += c[x];
        x = x - lowbit(x);
    }
    while (y > 0) {
        t2 += c[y];
        y = y - lowbit(y);
    }
    return t2 - t1;
}

int main() {
    int m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) add(i + 1, a[i]);
    for (int i = 0; i < m; i++) {
        int ord, x, y;
        cin >> ord >> x >> y;
        if (ord == 1) add(x, y);
        else if (ord == 2) cout << query(x, y) << "\n";
    }
    return 0;
}