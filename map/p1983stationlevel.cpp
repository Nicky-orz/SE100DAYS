#include<bits/stdc++.h>
using namespace std;
const int maxn = 2100;

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
    for(int i=1;i<=n+m;i++)
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
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int s;
        bool a[maxn];
        int L,R;
        L = maxn;
        R = -1;
        memset(a,0,sizeof(a));
        cin>>s;
        for(int j=0;j<s;j++){
            int tmp;
            cin>>tmp;
            a[tmp] = true;
            L = min(L,tmp);
            R = max(R,tmp);
        }
        bool has_unstopped = false;//如果全部停靠，这辆列车没有提供任何信息，不建图
        for(int j=L;j<=R;j++){
            if(!a[j])has_unstopped=true;
        }
        if(has_unstopped)
            for(int j=L;j<=R;j++){ //途径站[L,R]
                if(a[j]){
                    Edge tmp={j,1};
                    edge[i+n].push_back(tmp);//虚拟节点减少边数，从N*M变成N+M，重要的技巧
                    in[j]++;
                }
                else{
                    Edge tmp={i+n,0};
                    edge[j].push_back(tmp);
                    in[i+n]++;
                }
            }
    }

    toposort();
    fill(dis,dis+maxn,0);

    for(int i=0;i<n+m;i++){
        int u = L[i];
        for(auto E:edge[u])
            dis[E.v] = max(dis[E.v],dis[u]+E.w);
    }

    int ans = 0;
    for(int i=1;i<=n;i++)
        ans = max(ans,dis[i]);
    cout<<ans+1;
    return 0;
}