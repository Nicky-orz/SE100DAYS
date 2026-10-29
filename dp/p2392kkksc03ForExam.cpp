#include<bits/stdc++.h>
using namespace std;
int s1, s2, s3, s4;
int dp[2005];

int solve(int s){
    memset(dp, 0, sizeof(dp));
    int a[25];
    int sum = 0;
    for(int i=0;i<s;i++){
        cin>>a[i];
        sum += a[i];
    }
    for(int i=0;i<s;i++)
        for(int j=sum/2;j>=a[i];j--)
            dp[j] = max(dp[j], dp[j-a[i]]+a[i]);
    return max(dp[sum/2], sum-dp[sum/2]);
}

int main(){
    cin>>s1>>s2>>s3>>s4;
    cout<<solve(s1)+solve(s2)+solve(s3)+solve(s4);
    return 0;
}