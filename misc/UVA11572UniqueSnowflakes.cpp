#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000005;
const int H = 1000007;
struct node{
    int key, val;
};
int n;
int num;
node a[maxn];
int t[maxn];

int get_hash(int x) {
    return (x + H) % H;
}

void init() {
    for (int i = 0; i < maxn; i++)
        a[i].key = -1, a[i].val = 0;
}

void del(int x) {
        int pos = get_hash(x);
    while (a[pos].key != -1 && a[pos].key != x)
        pos = (pos + 1) % H;
    if (a[pos].key != -1) a[pos].val--;
    if (a[pos].val == 0) a[pos].key = -1, num--;
}

void solve() {
    int ans = 0;
    num = 0;
    init();
    cin >> n;
    int l = 0;
    for (int r = 0; r < n; r++) {
        cin >> t[r];
        int pos = get_hash(t[r]);
        while (a[pos].key != -1 && a[pos].key != t[r])
            pos = (pos + 1) % H;
        if (a[pos].key == -1) a[pos].key = t[r], a[pos].val = 1 , num++;
        else a[pos].val++;
        while (a[pos].val > 1) del(t[l++]);
        ans = max(ans, num);
    }
    cout << ans << "\n";
}
int main() {
    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}
/*
# UVA11572 唯一的雪花 Unique Snowflakes

## 题目描述

企业家 Emily 有一个很酷的主意：把雪花包起来卖。她发明了一台机器，这台机器可以捕捉飘落的雪花，并把它们一片一片打包进一个包裹里。一旦这个包裹满了，它就会被封上送去发售。

Emily 的公司的口号是“把独特打包起来”，为了实现这一诺言，一个包裹里不能有两片一样的雪花。不幸的是，这并不容易做到，因为实际上通过机器的雪花中有很多是相同的。Emily 想知道这样一个不包含两片一样的雪花的包裹最大能有多大，她可以在任何时候启动机器，但是一旦机器启动了，直到包裹被封上为止，所有通过机器的雪花都必须被打包进这个包裹里，当然，包裹可以在任何时候被封上。

## 输入格式

第一行是测试数据组数 $T$，对于每一组数据，第一行是通过机器的雪花总数 $n$（$n \le {10}^6$），下面 $n$ 行每行一个在 $[0, {10}^9]$ 内的整数，标记了这片雪花，当两片雪花标记相同时，这两片雪花是一样的。

## 输出格式

对于每一组数据，输出最大包裹的大小。

## 输入输出样例 #1

### 输入 #1

```
1
5
1
2
3
2
1
```

### 输出 #1

```
3
```
*/