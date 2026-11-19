#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
int n;
int L[N], R[N];
int cnt;

void add(int x, int k) {
    while (x <= N) {
        L[x] += k;
        x += (x & (-x));
    }
}

int sum(int x) {
    int t = 0;
    while (x > 0) {
        t += L[x];
        x -= (x & (-x));
    }
    return t;
}

int kth(int k) {
    int p = 0;
    for (int i = 1 << 17; i > 0; i >>= 1)
        if (p + i <= N && L[p + i] < k)
            p += i, k -= L[p];
    return p + 1;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        char ord;
        cin >> ord;
        if (ord == 'A') {
            int a, b;
            cin >> a >> b;
            int removed = 0;
            for (int k = sum(b); k > 0; k--){
                int p = kth(k);
                if (R[p] < a) break;
                add(p, -1);
                R[p] = 0;
                removed++;
            }
            add(a, 1);
            R[a] = b;
            cnt += 1 - removed;
            cout << removed << "\n";
        }
        if (ord == 'B') {
            cout << cnt << "\n";
        }
    }
    return 0;
}
//A:li < l && ri > l || li > l && ri < r || li < l && ri > r