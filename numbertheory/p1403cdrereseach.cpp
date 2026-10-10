#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1000005;
ll dp[maxn];

void solve(int n){
    for(int i=1;i<=n;i++)
        for(int j=i;j<=n;j+=i)
            dp[j]++;
}

int main(){
    int n;
    cin>>n;
    solve(n);
    ll ans = 0;
    for(int i=1;i<=n;i++)
        ans += dp[i];
    cout<<ans;
    return 0;
}