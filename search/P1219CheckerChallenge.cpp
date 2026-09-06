#include<bits/stdc++.h>
using namespace std;
int n;
int a[15];
int ans;
void dfs(int x){
    if(x==n+1){
        if(ans<3){
            for(int i=1;i<=n;i++){
                cout<<a[i]<<" ";
            }
            cout<<endl;
        }
        ans++;
        return;
    }
    for(int i=1;i<=n;i++){
        bool che=false;
        for(int j=1;j<x;j++)
            if(i+x==a[j]+j || x-i==j-a[j] || i==a[j]){
                che=true;
                break;
            }
        if(!che){
            a[x]=i;
            dfs(x+1);
            a[x]=0;
        }
    }
    return;
}
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        a[1]=i;
        dfs(2);
    }
    cout<<ans;
    return 0;
}