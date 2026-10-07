#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector <ll> primes;
bool prime[50005];
bool inprime[1000005];
ll l,r;
void solve(){
    prime[1] = true;
    ll n = sqrt(r);
    for(ll i=2;i<=n;i++){
        if(!prime[i])
            primes.push_back(i);
        for(ll p:primes){
            if(i*p > n) break;
            prime[i*p] = true;
            if(i%p == 0) break;
        }
    }
}
int main(){
    cin>>l>>r;
    solve();
    for(ll p:primes){
        for(ll i = max(l/p,ll(2));i*p <= r;i++){//每个合数都有小于sqrt的最小质因子
            if(i*p < l) continue;
            inprime[i*p - l] = true;
        }
    }
    int ans = 0;
    for(int i=0;i<=r-l;i++){
        if(!inprime[i]) ans++;
    }
    if(l == 1) ans--; //边界处理
    cout<<ans;
    return 0;
}