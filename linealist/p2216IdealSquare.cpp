#include <bits/stdc++.h>
using namespace std;
const int maxn = 1005;
struct node{
    int val;
    int id;
};
int a, b, n;
int maxd[maxn][maxn], mind[maxn][maxn];
deque <node> maxq, minq;
int ans = 1e9;
int main() {
    cin >> a >> b >> n;
    for (int i = 0; i < a; i++) {
        maxq.clear(); minq.clear();
        for (int j = 0; j < b; j++) {
            int t;
            cin >> t;
            while (!maxq.empty() && t > maxq.back().val) maxq.pop_back();
            while (!minq.empty() && t < minq.back().val) minq.pop_back();
            while (!maxq.empty() && maxq.front().id < j - n + 1) maxq.pop_front();
            while (!minq.empty() && minq.front().id < j - n + 1) minq.pop_front();
            maxq.push_back({t, j});
            minq.push_back({t, j});
            if (j >= n - 1) maxd[i][j] = maxq.front().val, mind[i][j] = minq.front().val;
        }
    }
    for (int j = n - 1; j < b; j++) {
        maxq.clear(); minq.clear();
        for (int i = 0; i < a; i++) {
            while (!maxq.empty() && maxd[i][j] > maxq.back().val) maxq.pop_back();
            while (!minq.empty() && mind[i][j] < minq.back().val) minq.pop_back();
            while (!maxq.empty() && maxq.front().id < i - n + 1) maxq.pop_front();
            while (!minq.empty() && minq.front().id < i - n + 1) minq.pop_front();
            maxq.push_back({maxd[i][j], i});
            minq.push_back({mind[i][j], i});
            if (i >= n - 1) ans = min(ans, maxq.front().val - minq.front().val);
        }
    }
    cout << ans;
    return 0;
}