#include<bits/stdc++.h>
using namespace std;

const int maxt = 1005;
const int maxm  =105;

int t,m;
int tim[maxm],val[maxm];
int dp[maxt];

int main(){
    cin>>t>>m;
    for(int i=0;i<m;i++)
        cin>>tim[i]>>val[i];
    for(int i=0;i<m;i++){
        for(int j=t;j>=tim[i];j--)
            dp[j] = max(dp[j],dp[j-tim[i]] + val[i]);
    }
    cout<<dp[t];
    return 0;
}