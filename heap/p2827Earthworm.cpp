#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 100005;

int n, m, q, u, v, t;
int a[maxn];
queue <ll> h1, h2, h3; //用堆会TLE

ll getmaxd() {
    ll t1, t2, t3;
    t1 = t2 = t3 = -1e9;
    if (!h1.empty()) t1 = h1.front();
    if (!h2.empty()) t2 = h2.front();
    if (!h3.empty()) t3 = h3.front();
    ll maxd = max(t1, max(t2, t3));
    if (maxd == t1) h1.pop();
    else if (maxd == t2) h2.pop();
    else if (maxd == t3) h3.pop();
    return maxd;
}

int main() {
    cin >> n >> m >> q >> u >> v >> t;
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n, greater<ll>());
    for (int i = 0; i < n; i++) h1.push(a[i]);
    ll add = 0;
    for (int i = 0; i < m; i++) {
        ll maxd = getmaxd() + add;
        ll x1 = maxd * u / v;
        ll x2 = maxd - x1;
        h2.push(x1 - add - q); h3.push(x2 - add - q);
        add += q;
        if ((i + 1) % t == 0) cout << maxd << " ";
    }
    cout << "\n";
    for (int i = 0; i < n + m; i++) {
        ll maxd = getmaxd();
        if ((i + 1) % t == 0) cout << maxd + m * q << " ";
    }
    return 0;
}