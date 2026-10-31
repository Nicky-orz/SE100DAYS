#include<bits/stdc++.h>
using namespace std;

const int maxm = 65;
const int maxn = 32005;

struct Node{
    int v,w,q;
    vector <Node> add;
}a[maxm];

int n,m;
int dp[maxn];

int main(){
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int v,w,q;
        cin>>v>>w>>q;
        if(q == 0)
            a[i].v = v, a[i].w = w, a[i].q = q;
        else
            a[q].add.push_back({v,w,q}), a[i].v = -1;
    }
    for(int i=1;i<=m;i++){
        if(a[i].v == -1) continue;
        for(int j=n;j>=a[i].v;j--){
            dp[j] = max(dp[j], dp[j-a[i].v] + a[i].v * a[i].w);
            for(auto node:a[i].add){
                int val = a[i].v*a[i].w + node.v*node.w;
                int cost = a[i].v + node.v;
                if(j >= cost)
                    dp[j] = max(dp[j], dp[j-cost] + val);
            }
            if(a[i].add.size() > 1){
                int val = a[i].v*a[i].w + a[i].add[0].v*a[i].add[0].w + a[i].add[1].v*a[i].add[1].w;
                int cost = a[i].v+a[i].add[0].v+a[i].add[1].v;
                if(j >= cost)
                    dp[j] = max(dp[j], dp[j - cost] + val);
            }
        }
    }
    cout<<dp[n];
    return 0;
}