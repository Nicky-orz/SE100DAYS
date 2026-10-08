#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll x,y;
ll ans;

ll solve(ll a,ll b){ //辗转相除法
    while(a%b != 0){
        ll tmp = a%b;
        a = b;
        b = tmp;
    }
    return b;
}

int main(){
    cin>>x>>y;
    ll plu = x*y;
    for(ll p=x;p<=sqrt(plu);p++){
        if(plu%p != 0) continue;
        ll q = plu/p;
        if(solve(p,q) == x){
            if(p != q) //特判p=q
                ans+=2;
            else
                ans++;
        }
    }
    cout<<ans;
    return 0;
}