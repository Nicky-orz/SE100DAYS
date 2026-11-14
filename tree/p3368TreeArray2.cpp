#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 500005;

int n;
ll c1[maxn], c2[maxn];

int lowbit(int x) {
    return x & (-x);
}

void add(int x, ll k1) {
    ll k2 = x * k1;
    while (x <= n) {
        c1[x] += k1; c2[x] += k2;
        x += lowbit(x);
    }
}

void range_add(int l, int r, ll k) {
    add(l, k);
    add(r + 1, -k);
}

ll getsum(ll *t, int x) {
    ll sum = 0;
    while (x > 0) {
        sum += t[x];
        x -= lowbit(x);
    }
    return sum;
}

ll presum(int x) {
    return (x + 1) * getsum(c1, x) - getsum(c2, x);
}

ll rangesum(int l, int r) {
    return presum(r) - presum(l - 1);
}

int main() {
    int m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        range_add(i + 1, i + 1, a);
    }
    for (int i = 0; i < m; i++) {
        int ord;
        cin >> ord;
        if (ord == 1) {
            int x, y, k;
            cin >> x >> y >> k;
            range_add(x, y, k);
        }
        else if (ord == 2) {
            int x;
            cin >> x;
            cout << rangesum(x, x) << "\n";
        }
    }
    return 0;
}