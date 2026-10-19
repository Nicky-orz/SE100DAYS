#include<bits/stdc++.h>
using namespace std;

const int maxn = 1000005;
typedef long long ll;

int n,m;
int r[maxn];
int d[maxn],s[maxn],t[maxn];
ll dif[maxn];

bool check(int M){
    memset(dif,0,sizeof(dif));
    for(int i=1;i<=M;i++){
        dif[s[i]] += d[i];
        dif[t[i]+1] -= d[i];
    }
    ll num = 0;
    for(int i=1;i<=n;i++){
        num += dif[i];
        if(num > r[i])
            return false;
    }
    return true;
}

int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>r[i];
    for(int i=1;i<=m;i++)
        cin>>d[i]>>s[i]>>t[i];
    int l = 1,r = m+1;
    while(l < r){
        int mid = (l+r)/2;
        if(check(mid))
            l = mid+1;
        else
            r = mid;
    }
    if(l != m+1)
        cout<<"-1\n"<<l;
    else
        cout<<0;
    return 0;
}