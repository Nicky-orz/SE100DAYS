#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;
const int maxn = 1005;
const int maxw = 10005;
int n,w;
int dp[maxw];
int a[maxn];
int main(){
    cin>>n>>w;
    for(int i=0;i<n;i++)
        cin>>a[i];
    dp[0] = 1;
    for(int i=0;i<=w;i++){
        for(int j=0;j<n;j++)
            if(i+a[j] <= w)
                dp[i+a[j]] = (dp[i+a[j]]+dp[i])%mod;
        
    }
    cout<<dp[w];
    return 0;
}