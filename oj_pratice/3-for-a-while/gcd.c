#include<stdio.h>
typedef long long ll;
ll gcd(ll a,ll b){
    while(a%b != 0){
        ll tmp = a%b;
        a = b;
        b = tmp;
    }
    return b;
}

int main(){
    ll a,b;
    scanf("%lld %lld",&a,&b);
    printf("%lld",gcd(a,b));
    return 0;
}