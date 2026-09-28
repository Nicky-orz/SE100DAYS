#include <bits/stdc++.h>
using namespace std;

const int maxn = 1005;
int K, N, M;
vector<int> Edge[maxn];
int cow[105];
int cnt[maxn];
bool vis[maxn];

void dfs(int u){
    vis[u] = true;
    cnt[u]++;
    for(int v:Edge[u]) 
        if(!vis[v]) dfs(v);
}

int main() {
    cin>>K>>N>>M;
    for(int i=0;i<K;i++)
        cin>>cow[i];
    for(int i=0;i<M;i++){
        int u,v;
        cin>>u>>v;
        Edge[u].push_back(v);
    }
    for (int i=0;i<K;i++){
        memset(vis,0,sizeof(vis));
        dfs(cow[i]); //暴力dfs，数据量小能过
    }
    int ans = 0;
    for(int i=1;i<=N;i++)
        if(cnt[i] == K)ans++;
    cout<<ans;
    return 0;
}

/*
拓扑只能处理无环图,10分
#include<bits/stdc++.h>
using namespace std;
const int maxn = 1005;

vector <int> Edge[maxn],L;
int n;
int in[maxn];
int ans[maxn];

void toposort(){
    queue <int> S;
    for(int i=1;i<=n;i++)
        if(in[i] == 0)
            S.push(i);
    while(!S.empty()){
        int u = S.front();
        L.push_back(u);
        S.pop();
        for(auto v:Edge[u])
            if(--in[v] == 0) S.push(v);
    }

}

int main(){
    int k,m;
    cin>>k>>n>>m;
    for(int i=0;i<k;i++){
        int t;
        cin>>t;
        ans[t]++;
    }
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        Edge[u].push_back(v);
        in[v]++;
    }
    toposort();
    for(auto u:L){
        for(auto v:Edge[u])
            ans[v]+=ans[u];
    }
    int num = 0;
    for(int i=1;i<=n;i++)
        if(ans[i] == k)
            num++;
    cout<<num;
    return 0;
}

2 4 4
2
3
1 2
2 3
3 4
4 1
*/