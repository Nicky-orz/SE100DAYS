#include <bits/stdc++.h>
using namespace std;
const int maxn = 100005;
const int mod = 10007;
typedef long long ll;
struct Node{
    ll num;
    ll id;
};
int n, m;
ll a[maxn];
vector <Node> c1[maxn], c2[maxn];
ll ans;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) {
        ll col;
        cin >> col;
        if (i % 2 == 1) c1[col].push_back({a[i] % mod, i % mod});
        else c2[col].push_back({a[i] % mod, i % mod});
    }
    for (int i = 1; i <= m; i++) {
        ll S1 = c1[i].size();
        ll sum1 = 0;
        for (int j = 0; j < S1; j++)
            sum1 += c1[i][j].id % mod;
        for (int j = 0; j < S1; j++) 
            ans += (sum1 - c1[i][j].id  + c1[i][j].id % mod * (S1 - 1) % mod + mod) % mod * c1[i][j].num % mod;
        ll S2 = c2[i].size();
        ll sum2 = 0;
        for (int j = 0; j < S2; j++)
            sum2 += c2[i][j].id % mod;
        for (int j = 0; j < S2; j++) 
            ans += (sum2 - c2[i][j].id  + c2[i][j].id % mod * (S2 - 1) % mod + mod) % mod * c2[i][j].num % mod;
    }
    cout << ans % mod;
    return 0;
}