#include<bits/stdc++.h>
using namespace std;
const int maxn = 1505;

struct Edge{
    int v,w;
};

int n,m;
vector <Edge> edge[maxn];
int in[maxn];
int dis[maxn];
vector<int> L;

void toposort(){
    queue<int> S;
    for(int i=1;i<=n;i++)
        if(in[i] == 0) S.push(i);
    while(!S.empty()){
        int u = S.front();
        S.pop();
        L.push_back(u);
        for(auto E:edge[u])
            if(--in[E.v] == 0)
                S.push(E.v);
    }
}

int main(){
    bool fetch = false;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int u;
        Edge tmp;
        cin>>u>>tmp.v>>tmp.w;
        in[tmp.v]++;
        edge[u].push_back(tmp);
    }
    toposort();
    fill(dis,dis+maxn,-1e9); //memset按字节填充，要极小应该是memset(dis,0xc0,sizeof(dis));
    dis[1] = 0;
    for(int i=0;i<n;i++){
        int u = L[i];
        if(dis[u] == -1e9) continue; //判断节点是否不可达
        for(auto E:edge[u])
            dis[E.v] = max(dis[E.v],dis[u]+E.w);
    }
    if(dis[n] != -1e9) cout<<dis[n];
    else cout<<-1;
    return 0;
}
//认真学，所以没有用记忆化搜索水了这题
//Dijkstra 算法后面学了优先队列和堆再练，先学拓扑排序+dp