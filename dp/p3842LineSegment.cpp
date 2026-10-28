#include<bits/stdc++.h>
using namespace std;
const int maxn = 20005;
int n;
long long dp[maxn][2];
int main(){
    cin>>n;
    int preL = 1,preR = 1;
    for(int i=1;i<=n;i++){
        int l,r;
        cin>>l>>r;
        dp[i][0] = min(dp[i-1][0] + abs(r-preL) + r-l, dp[i-1][1] + abs(r-preR) + r-l);
        dp[i][1] = min(dp[i-1][0] + abs(l-preL) + r-l, dp[i-1][1] + abs(l-preR) + r-l);
        preL = l;
        preR = r;
    }
    cout<<min(dp[n][0] + n - preL, dp[n][1] + n - preR) + n-1;
    return 0;
}