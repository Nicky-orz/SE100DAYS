#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll gcd(ll a,ll b){
    a = llabs(a);
    b = llabs(b);
    while(a%b != 0){
        ll tmp = a%b;
        a = b;
        b = tmp;
    }
    return llabs(b);
}

ll lcm(ll a,ll b){
    return (a*b/gcd(a,b));
}
int main(){
    ll a,b,c;
    cin>>a>>b>>c;
    cout<<lcm(a,lcm(b,c));
    return 0;
}