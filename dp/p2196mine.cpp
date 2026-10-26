#include<bits/stdc++.h>
using namespace std;

int n;
int a[25];
int dp[25];
int pre[25];

void find(int x){
    if(pre[x] != x) find(pre[x]);
    cout<<x+1<<" ";
}

int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
        pre[i] = i;
        dp[i] = a[i];
    }
    for(int i=0;i<n-1;i++){
        for(int j=1+i;j<n;j++){
            bool e;
            cin>>e;
            if(e && dp[i] + a[j] > dp[j])
                dp[j] = dp[i] + a[j], pre[j] = i;
        }
    }
    int ans = -1, t;
    for(int i=0;i<n;i++){
        if(dp[i] > ans)
            ans = dp[i], t = i;
    }
    find(t);
    cout<<"\n"<<ans;
    return 0;
}