#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MOD = 998244353;
const int maxn = 2000005;

int n, N;
ll fac[2*maxn], invfac[2*maxn];

ll qpow(ll a, ll b) {
    ll r = 1;
    a %= MOD;
    while (b) {
        if (b & 1) r = r * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return r;
}

ll C(int a, int b) {
    if (b < 0 || b > a) return 0;
    return fac[a] * invfac[b] % MOD * invfac[a - b] % MOD;
}

int main() {
    cin >> n;
    N = 2 * n;
    fac[0] = 1;
    for (int i = 1; i <= N; i++)
        fac[i] = fac[i - 1] * i % MOD;
    invfac[N] = qpow(fac[N], MOD - 2);
    for (int i = N; i >= 1; i--)
        invfac[i - 1] = invfac[i] * i % MOD;

    ll total = C(N, n);
    ll inv_total = qpow(total, MOD - 2);

    for (int k = 0; k <= n; k++) {
        ll a = C(N, n - k - 1);
        ll b = C(N, k - 1);
        ll Nk = (total - a - b) % MOD;
        if (Nk < 0) Nk += MOD;
        ll ans = Nk * inv_total % MOD;
        cout << ans << "\n";
    }

    return 0;
}