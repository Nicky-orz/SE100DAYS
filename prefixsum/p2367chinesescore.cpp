#include<bits/stdc++.h>
using namespace std;
const int maxn = 5000005;
int n,p;
int a[maxn],d[maxn];
int main(){
    cin>>n>>p;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        d[i] = a[i] - a[i-1];
    }
    for(int i=1;i<=p;i++){
        int x,y,z;
        cin>>x>>y>>z;
        d[x] += z;
        d[y+1] -= z;
    }
    int t,ans;
    t = 0;
    ans = 1e9;
    for(int i=1;i<=n;i++){
        t += d[i];
        ans = min(t,ans);
    }
    cout<<ans;
    return 0;
}