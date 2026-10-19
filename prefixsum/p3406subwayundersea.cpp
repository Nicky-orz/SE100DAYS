#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 100005;

int n,m;
int d[maxn];
ll ans;

int main(){
    cin>>n>>m;
    int p,lp;
    for(int i=0;i<m;i++){
        cin>>p;
        if(i != 0){
            d[min(p,lp)]++;
            d[max(p,lp)]--;
        }
        lp = p;
    }
    ll pass = 0;
    for(int i=1;i<n;i++){
        ll a,b,c;
        cin>>a>>b>>c;
        pass += d[i];
        ans += min(pass*a, pass*b+c);
    }
    cout<<ans;
    return 0;
}