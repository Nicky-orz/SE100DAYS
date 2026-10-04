#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    vector<pair<int, int>> queries(T);
    int S = 0;
    for (auto &[s, k] : queries) {
        int n;
        string x;
        cin >> n >> k >> x;
        s = 0;
        while (s < n && x[n - 1 - s] == '0') ++s;
        k = min(k, s);
        S = max(S, s);
    }

    // f[s][k]: number of distinct offsets using at most k of the s positions.
    vector<vector<int>> f(S + 1);
    f[0] = {1};
    int full = 1;
    for (int s = 1; s <= S; ++s) {
        f[s].resize(s + 1);
        f[s][0] = 1;
        full = (2LL * full + 1) % MOD;
        f[s][s] = full;
        for (int k = 1; k < s; ++k) {
            f[s][k] = (f[s - 1][k] + 2LL * f[s - 2][k - 1]) % MOD;
        }
    }
    for (auto [s, k] : queries) cout << f[s][k] << '\n';
    return 0;
}
