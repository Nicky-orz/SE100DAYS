#include<bits/stdc++.h>
using namespace std;
int fa[2005],sz[2005];

void init(int n){
    for(int i=1;i<=n;i++)
        fa[i]=i,sz[i]=1;
}

int find(int x){
    if(fa[x] == x) return x;
    else return fa[x] = find(fa[x]);
}

void unite(int x,int y){
    int fax = find(x);
    int fay = find(y);
    if(fax == fay)
        return;
    if(sz[fax] <= sz[fay])
        swap(fax,fay);
    fa[fay] = fax;
    sz[fax]+=sz[fay];
}

int count(int n){
    bool vis[2005];
    memset(vis,false,sizeof(vis));
    int num=0;
    for(int i=1;i<=n;i++){
        int root = find(i);
        if(!vis[root]){
            vis[root] = true;
            num++;
        }
    }
    return num;
}
int main(){
    int n,m;
    cin>>n>>m;
    init(2*n);

    for(int i=0;i<m;i++){
        char relationship;
        int p,q;
        cin>>relationship>>p>>q;
        if(relationship == 'E'){
            unite(p,q+n);
            unite(p+n,q);
        }
        else
            unite(p,q);
    }
    cout<<count(n);
    return 0;
}