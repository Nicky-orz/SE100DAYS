#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = (1<<20)+5;
struct edge{
    int k,w;
}a[maxn];
int fa[maxn],sz[maxn];
int n;
vector <pair <int,int> > ans;
ll num,answ;

bool cmp(edge x,edge y){
    return x.w<y.w;
}

void init(int n){
    for(int i=0;i<n;i++)
        fa[i] = i,sz[i] =1;
}

int find(int x){
    if(fa[x] == x) return x;
    else return fa[x] = find(fa[x]);
}

bool unite(int x,int y){
    int fx = find(x);
    int fy = find(y);
    if(fx == fy) return false;
    if(sz[fx] < sz[fy])
        swap(fx,fy);
    fa[fy] = fx;
    sz[fx] += sz[fy];
    return true;
}

bool vis[maxn];
int main(){
    cin>>n;
    init(1<<n);
    for(int i=0;i<(1<<n);i++){
        a[i].k = i;
        cin>>a[i].w;
    }
    sort(a,a+(1<<n),cmp);
    cout<<(1<<n)-1<<"\n";
    for(int k=0;k<(1<<n);k++){
        int x = a[k].k;
        queue<int> q;
        q.push(x);
        while(!q.empty()){//bfs优化相对于暴力枚举实现了剪枝，这是图论视角相对于集合视角的优势
            int now = q.front();
            q.pop();
            if(vis[now]) continue;
            vis[now] = 1;
            for(int j = 0; j < n; j++){
                if((now >> j) & 1) continue;   // 第 j 位已经是 1
                int u = now ^ (1 << j);        // 翻转第 j 位，生成超集
                if(unite(x, u)){
                    ans.push_back({x, u});
                    answ += a[k].w;
                    q.push(u);
                }
            }
        }
    }

    for(auto i:ans)
        cout<<i.first<<" "<<i.second<<"\n";
    cout<<answ;
    return 0;
}
/*
遍历同权边->枚举超集->bfs处理
充分体现了图和集合的相互转化
*/