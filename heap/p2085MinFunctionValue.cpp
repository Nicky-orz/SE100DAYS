#include <bits/stdc++.h>
using namespace std;

priority_queue <int> p;

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        for (int x = max(-(b/2/a), 1); x > 0; x++) {
            int val = a*x*x + b*x + c;
            p.push(val);
            if (!p.empty() && (int)p.size() > m && val >= p.top())
                break;
        }
        for (int x = max(-(b/2/a)-1, 0); x > 0; x--) {
            int val = a*x*x + b*x + c;
            p.push(val);
            if (!p.empty() && (int)p.size() > m && val >= p.top())
                break;
        }
        while ((int)p.size() > m) {
            p.pop();
        }
    }
    vector <int> ans;
    for (int i = 0; i < m; i++) {
        ans.push_back(p.top());
        p.pop();
    }
    for (int i = ans.size()-1; i >= 0; i--)
        cout<<ans[i]<<" ";
    return 0;
}