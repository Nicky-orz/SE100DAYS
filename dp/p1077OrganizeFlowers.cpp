#include<bits/stdc++.h>
using namespace std;
const int mod = 1e6+7;
int n,m;
int a[105];
int dp[105];
int main(){
    cin>>n>>m;
    for(int i=0;i<n;i++)
        cin>>a[i];
    dp[0] = 1;
    for(int i=0;i<n;i++){
        for(int j=m;j>=0;j--){
            int sum = 0;
            for(int k=0;k<=min(a[i], j);k++)
                sum = (sum+dp[j-k])%mod;
            dp[j] = sum;
        }
    }
    cout<<dp[m];
    return 0;
}