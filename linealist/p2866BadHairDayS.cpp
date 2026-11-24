#include <bits/stdc++.h>
using namespace std;
const int maxn = 80005;
int n;
int a[maxn];
stack <int> s;
long long ans;
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    a[n] = 1e9 + 1;
    for (int i = 0; i <= n; i++) {
        while(!s.empty() && a[i] >= a[s.top()]) {
            ans += i - s.top() - 1;
            s.pop();
        }
        s.push(i);
    }
    cout << ans;
    return 0;
}