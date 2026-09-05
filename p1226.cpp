#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a,b,p;
ll ans;
ll dc(ll bas,ll exp,ll mod){
    if(exp==1)
        return bas%mod;
    ll le=dc(bas,exp/2,mod)%mod;
    if(exp%2==0)
        return (le%mod)*(le%mod)%mod;
    else    
        return (((le%mod)*(le%mod)%mod)*(bas%mod))%mod;
}
int main(){
    scanf("%lld%lld%lld",&a,&b,&p);
    ans=dc(a%p,b,p);
    printf("%lld^%lld mod %lld=%lld",a,b,p,ans);
    return 0;
}