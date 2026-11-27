#include <bits/stdc++.h>
using namespace std;
struct node{
    int val;
    int id;
};
int n, k;
deque <node> q;
int main() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        while (!q.empty() && t >= q.back().val) q.pop_back();
        while (!q.empty() && q.front().id <= i - k) q.pop_front();
        q.push_back({t, i});
        if (i >= k - 1) cout << q.front().val << "\n";
    }
    return 0;
}