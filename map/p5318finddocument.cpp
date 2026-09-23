#include<bits/stdc++.h>
using namespace std;
const int maxm = 1000005;
const int maxn = 100005;

vector <pair <int,int> > edge;
vector <int> mp[maxm];

bool vis[maxn];

void dfs(int N){
    vis[N] = true;
    cout<<N<<" ";
    for(auto E:mp[N])
        if(!vis[E])  dfs(E);
}

void bfs(int N){
    queue <int> q;
    vis[N] = true;
    q.push(N);
    while(!q.empty()){
        int fro = q.front();
        cout<<fro<<" ";
        for(auto E:mp[fro])
            if(!vis[E]){
                vis[E] = true;
                q.push(E);
            } 
        q.pop();
    }
}

int main(){
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        pair <int,int> E;
        cin>>E.first>>E.second;
        edge.push_back(E);
    }
    sort(edge.begin(),edge.end());
    for(auto E:edge)
        mp[E.first].push_back(E.second);
    dfs(1);
    memset(vis,false,sizeof(vis));
    cout<<"\n";
    bfs(1);
    return 0;

}