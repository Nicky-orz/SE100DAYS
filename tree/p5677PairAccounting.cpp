#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 300005;
struct Node{
    int val;
    int id;
}a[maxn];

struct Q{
    int l;
    int r;
    int id;
}query[maxn], pai[maxn * 2];

int n, m;
int c[maxn];
int Pcnt;

int lowbit(int x) {
    return x & (-x);
}

void add(int x, int k) {
    while (x <= n) {
        c[x] += k;
        x += lowbit(x);
    }
}

ll sum(int x) {
    ll t = 0;
    while (x > 0) {
        t += c[x];
        x -= lowbit(x);
    } 
    return t;
}

bool cmp1(Node a, Node b) {
    return a.val < b.val;
}

bool cmp2(Q a, Q b) {
    return a.l > b.l;
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {cin >> a[i].val; a[i].id = i;}
    for (int i = 1; i <= m; i++) {cin >> query[i].l >> query[i].r; query[i].id = i;}
    sort(a + 1, a + n + 1, cmp1);
    sort(query + 1, query + m + 1, cmp2);
    for (int i = 1; i <= n; i++) {
        if (i == 1) {
            pai[++Pcnt].l = min(a[i].id, a[i+1].id);
            pai[Pcnt].r = max(a[i].id, a[i+1].id);
        }
        else if (i == n) {
            pai[++Pcnt].l = min(a[i-1].id, a[i].id);
            pai[Pcnt].r = max(a[i-1].id, a[i].id);
        }
        else {
            if (a[i + 1].val - a[i].val >= a[i].val - a[i - 1].val) {
                pai[++Pcnt].l = min(a[i-1].id, a[i].id);
                pai[Pcnt].r = max(a[i-1].id, a[i].id);
            }
            if (a[i + 1].val - a[i].val <= a[i].val - a[i - 1].val) {
                pai[++Pcnt].l = min(a[i].id, a[i+1].id);
                pai[Pcnt].r = max(a[i].id, a[i+1].id);
            }
        }
    }
    sort(pai + 1, pai + Pcnt + 1, cmp2);
    ll ans = 0;
    for (int i = 1, j = 1; i <= m; i++) {
        while (j <= Pcnt && pai[j].l >= query[i].l) {
            add(pai[j].r, 1);
            j++;
        }
        ans += sum(query[i].r) * query[i].id;
    }
    cout << ans;
    return 0;
}