#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1005;

int n,x;
ll val[maxn],wei[maxn];
ll dp[maxn];
ll ans;
int main(){
    cin>>n>>x;
    for(int i=0;i<n;i++){
        ll lose,win;
        cin>>lose>>win>>wei[i];
        ans += lose;
        val[i] = win - lose;
    }
    for(int i=0;i<n;i++)
        for(int j=x;j>=wei[i];j--)
            dp[j] = max(dp[j], dp[j-wei[i]]+val[i]);
    ll t = -1;
    for(int i=0;i<=x;i++)
        t = max(t,dp[i]);
    ans += t;
    cout<<5*ans;
    return 0;
}