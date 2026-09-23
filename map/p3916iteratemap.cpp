#include<bits/stdc++.h>
using namespace std;
const int maxm = 100005;
const int maxn = 100005;

vector <pair <int,int> > edge;
vector <int> mp[maxm];

bool vis[maxn];
int fetch[maxn];

void dfs(int N,int Max){
    fetch[N] = Max;
    for(auto E:mp[N])
        if(!fetch[E])
            dfs(E,Max);
}

int main(){
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        mp[v].push_back(u);//反向图能解决1->2,2->1这种正向图处理不了的循环图
    }
    for(int i=n;i>=1;i--)
        if(!fetch[i]) dfs(i,i);
    for(int i=1;i<=n;i++)
        cout<<fetch[i]<<" ";
    return 0;

}