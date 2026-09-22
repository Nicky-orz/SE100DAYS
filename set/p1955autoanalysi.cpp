#include<bits/stdc++.h>
using namespace std;

struct Node{
    int x,y;
};

map <int,int> fa,sz; // 下标i,j太大，需要用map代替数组实现并查集

void init(int n){
    if(!fa.count(n)){
        fa[n] = n;
        sz[n] = 1;
    }
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

void solve(){
    fa.clear();
    sz.clear();
    int n;
    bool ans = true;
    vector <Node> check;
    cin>>n;
    init(2*n);
    for(int i=0;i<n;i++){
        int order,x,y;
        cin>>x>>y>>order;
        init(x); init(y);
        if(order == 1)
            unite(x,y);
        if(order == 0){
            Node tmp;
            tmp.x = x,tmp.y = y;
            check.push_back(tmp);
        }
    }
    for(auto i:check){
        int fx = find(i.x);
        int fy = find(i.y);
        if(fx == fy){
            ans = false;
            break;
        }
    }
    cout<< (ans?"YES\n":"NO\n") ;
}

int main(){
    int t;
    cin>>t;
    while(t--)
        solve();
    return 0;
}