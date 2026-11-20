#include <bits/stdc++.h>
using namespace std;
const int maxn = 100005;
const int N = 50005;
int n;
int a[maxn];
int c[maxn]; 
int dp1[maxn], dp2[maxn];

void update(int x, int k) {
    while (x < N) {
        c[x] = max(c[x], k);
        x += (x & (-x));
    }
}

int Max(int x) {
    int t = 0;
    while (x > 0) {
        t = max(t, c[x]);
        x -= (x & (-x));
    }
    return t;
}

int main() {
    while (cin >> a[n] && a[n] != EOF) n++;
    int ans1 = 0;
    for (int i = n-1; i >= 0; i--) {
        int len = Max(a[i]) + 1;
        update(a[i], len);
        ans1 = max(ans1, len);
    }
    memset(c, 0, sizeof(c));
    int ans2 = 0;
    for (int i = 0; i < n; i++) {
        int len = Max(a[i] - 1) + 1;
        update(a[i], len);
        ans2 = max(ans2, len);
    }
    cout << ans1 << "\n" << ans2;
    return 0;
}