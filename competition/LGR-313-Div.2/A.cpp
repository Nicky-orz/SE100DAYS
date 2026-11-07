#include<bits/stdc++.h>
using namespace std;

const int maxn = 2000005;

int n, S;
int b[maxn];

void solve() {
    memset(b, 0, sizeof(b));
    cin >> n >> S;
    for (int i = 1; i <= S; i++)
        cin >> b[i];
    vector <int> ans;
    for (int i = 1; i <= S; i++)
        if (b[i] - i == S - 1)
            ans.push_back(b[i]);
    cout << ans.size() << "\n";
    for(int i : ans)
        cout << i << " ";
    cout << "\n";
}

int main() {
    int t;
    cin>>t;
    while (t--)
        solve();
    return 0;
}
//x为除去S后，第|S|+1小的数
//剩余集合中有bi-1个小于的，i-1个B的，能被配对的有bi-i个，如果bi-i = |S|，那么bi就是x