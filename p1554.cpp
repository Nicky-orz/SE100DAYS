#include<bits/stdc++.h>
using namespace std;
int n,m;
int ans[15];
int main(){
    cin>>n>>m;
    for(int i=n;i<=m;i++){
        int t=i;
        if(t%10==0)
            ans[0]++,t/=10;
        while(t!=0){
            ans[t%10]++;
            t=t/10;
        }
    }
    for(int i;i<10;i++)
        cout<<ans[i]<<" ";
    return 0;
}