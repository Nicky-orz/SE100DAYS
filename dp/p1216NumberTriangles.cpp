#include<bits/stdc++.h>
using namespace std;
const int maxn = 1005;
int dp[maxn][maxn];
int main(){
    int r;
    cin>>r;
    for(int i=1;i<=r;i++){
        for(int j=1;j<=i;j++){
            int a;
            cin>>a;
            dp[i][j] = max(dp[i-1][j-1],dp[i-1][j]) + a;
        }
    }
    int ans = -1;
    for(int i=1;i<=r;i++){
        ans = max(ans,dp[r][i]);
    }
    cout<<ans;
    return 0;
}