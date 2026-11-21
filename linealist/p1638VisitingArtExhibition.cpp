#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000005;
const int maxm = 2005;
int n, m;
int a[maxn];
int seen[maxm];
int ansx, ansy, mind;
int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> a[i];
    int T = 0, B = 0;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (seen[a[i]] == 0) cnt++;
        seen[a[i]]++;
        if (cnt == m) {B = i; ansx = 0; ansy = i; mind = i; break;}
    }
    while (T + 1 < n && B < n) {
        int top = a[T];
        seen[top]--;
        T++;
        if (seen[top] == 0) {
            while (B < n && a[B] != top) seen[a[++B]]++;
            if (B >= n) break;
        }
        if (B - T < mind) mind = B - T, ansx = T, ansy = B;
    }
    cout << ansx + 1 << " " << ansy + 1;
    return 0;
}