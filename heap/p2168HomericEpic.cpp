#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 100005;
struct Node{
    ll val;
    int dep;
    bool operator<(const Node& o) const{
        if (val != o.val) return val > o.val;
        else return dep > o.dep;
    }
};

priority_queue <Node> h;
int n, k;
ll w[maxn];

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> w[i];
    while ((n-1) % (k-1) != 0) n++;
    for (int i = 0; i < n; i++) h.push({w[i], 0});
    ll ans = 0;
    while ((int) h.size() >= k) {
        vector <Node> topk;
        ll sum = 0;
        int maxd = -1;
        for (int i = 0; i < k; i++) {
            topk.push_back(h.top());
            h.pop();
        }

        for (Node i : topk) {
            sum += i.val;
            maxd = max(maxd, i.dep);
        }

        h.push({sum, maxd + 1});
        ans += sum;
    }
    cout << ans << "\n" << h.top().dep;
    return 0;
}
//6 = 110 = 4 + 2
//9 = 1001 = 8 + 1 = 7 + 1
//ans = 1*(9+9) + 2*(3+3) + 3*(1+1) = 36
//6 = 1 + 1 + (1 + 1 + 3)
//9 = 1 + 1 + 9 = 3 + 3 + 3
//27-> 9 9 9 -> 3 3 3 9 9