#include<bits/stdc++.h>
using namespace std;
const int maxn = 5005;

int fa[maxn],sz[maxn];

void init(int n){
    for(int i=1;i<=n;i++){
        fa[i]=i;
        sz[i]=1;
    }
}

int find(int x){
    if(fa[x] == x) return x;
    else return fa[x] = find(fa[x]);
}

void unite(int x,int y){
    int fx = find(x);
    int fy = find(y);
    if(fx == fy) return;
    if(sz[fx] < sz[fy]) swap(fx,fy);
    fa[fy] = fx;
    sz[fx] += sz[fy];
    sz[fy] = 0;
}

bool same(int x,int y){
    return find(x) == find(y);
}

int main(){
    int n,m,p;
    cin>>n>>m>>p;
    init(n);
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        unite(x,y);
    }
    for(int i=0;i<p;i++){
        int x,y;
        cin>>x>>y;
        if(same(x,y))
            cout<<"Yes"<<endl;
        else    
            cout<<"No"<<endl;
    }
    return 0;
}