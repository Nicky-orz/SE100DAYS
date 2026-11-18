#include <bits/stdc++.h>
using namespace std;
struct P{
    int val;
    int id;
    bool operator<(const P& o) const{
        if (val != o.val) return val > o.val;
        else return id > o.id;
    }
};
priority_queue <P> h;
int n;
int m;
int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        int a;
        cin >> a;
        h.push({a, i});
        if (i >= m) {
            while (!h.empty() && h.top().id < i - m + 1) {
                h.pop();
            }
            cout << h.top().val << "\n";
        }
    }
    return 0;
}