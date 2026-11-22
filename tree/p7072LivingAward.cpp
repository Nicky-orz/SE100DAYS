#include <bits/stdc++.h>
using namespace std;
const int maxn = 100005;
const int maxa = 1030;
int n, w;
int c[maxa];

void add(int x, int k) {
    while (x <= maxa) {
        c[x] += k;
        x += (x & (-x));
    }
}

int kth(int k) {
    int num = 0, sum = 0;
    for (int i = 1 << 10; i > 0; i >>= 1) 
        if (num + i <= maxa && sum + c[num + i] < k)
            num += i, sum += c[num];
    return num + 1;
}

int main() {
    cin >> n >> w;
    for (int i = 0; i < n; i++) {
       int a;
       cin >> a;
       a++;
       add(a, 1);
       cout << kth(i + 2 - max(1, (i + 1) * w / 100)) - 1 << " ";
    }
    return 0;
}