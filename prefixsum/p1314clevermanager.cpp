#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 200005;
ll n,m,s;
ll w[maxn],v[maxn];
int l[maxn],r[maxn];
ll add[maxn],num[maxn];
ll check(int W){
    memset(add,0,sizeof(add));
    memset(num,0,sizeof(num));
    for(int i=1;i<=n;i++){
        add[i] = add[i-1];
        num[i] = num[i-1];
        if(W <= w[i])
            add[i] += v[i],num[i]++;
    }
    ll ans = 0;
    for(int i=1;i<=m;i++){
        ans += (num[r[i]] - num[l[i]-1])*(add[r[i]] - add[l[i]-1]);
        //cout<<ans<<"\n";
    }
    return ans;
}

int main(){
    cin>>n>>m>>s;
    ll L=1e9,R=-1;
    for(int i=1;i<=n;i++){
        cin>>w[i]>>v[i];
        L = min(L,w[i]);
        R = max(R,w[i]);
    }
    for(int i=1;i<=m;i++)
        cin>>l[i]>>r[i];
    ll mid;
    //cout<<check(4)<<"---\n";
    while(R-L > 1){
        mid = (L+R)/2;
        //cout<<L<<" "<<R<<" "<<mid<<"\n";
        if(check(mid) < s)
            R = mid;
        else
            L = mid;
    }
    ll ansl = abs(check(L) - s),ansr = abs(s - check(R));
    if(ansl > ansr)
        cout<<ansr;
    else
        cout<<ansl;
    return 0;
}