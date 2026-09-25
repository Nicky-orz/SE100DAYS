#include<bits/stdc++.h>
using namespace std;
const int mod =80112002;
const int maxn = 5005;
int n,m;
vector <int> fedge[maxn],bedge[maxn];
int num[maxn];
int dfs(int x){
    if(fedge[x].empty())
        return 1;
    if(num[x])
        return num[x]%mod;
    int ans=0;
    for(auto i:fedge[x]){
        ans = (ans+dfs(i)%mod)%mod;
    }
    num[x] = ans%mod;
    return ans%mod;
}

int main(){
    int ans = 0;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        fedge[u].push_back(v);
        bedge[v].push_back(u);
    }
    for(int i=1;i<=n;i++){
        if(bedge[i].empty())
            ans = (ans+dfs(i)%mod)%mod;
    }
    cout<<ans%mod;
    return 0;
}
/*
暴力搜索无记忆化，tle8个点
#include<bits/stdc++.h>
using namespace std;
const int maxn = 5005;
int n,m;
vector <int> fedge[maxn],bedge[maxn];
int dfs(int x){
    if(fedge[x].empty())
        return 1;
    int ans=0;
    for(auto i:fedge[x]){
        ans += dfs(i);
    }
    return ans%80112002;
}

int main(){
    int ans = 0;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        fedge[u].push_back(v);
        bedge[v].push_back(u);
    }
    for(int i=1;i<=n;i++){
        if(bedge[i].empty())
            ans += dfs(i)%80112002;
    }
    cout<<ans%80112002;
    return 0;
}
*/