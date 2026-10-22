#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, w;
    cin>>n>>w;
    int a[1005];
    memset(a,0,sizeof(a));
    for(int i=0;i<n;i++)
        cin>>a[i];
    int dp[10005];
    memset(dp,0x3f,sizeof(dp));
    dp[0] = 0;
    for(int i=0;i<n;i++)
        for(int j=a[i];j<=w;j++)
            if(dp[j-a[i]] != 0x3f3f3f3f)
                dp[j] = min(dp[j],dp[j-a[i]]+1);
    cout<<dp[w];
    return 0;
}