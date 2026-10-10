#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ll x,y;
    cin>>x>>y;
    ll ans = 0;
    while(x != 0 && y != 0){
        if(x > y) swap(x,y);
        ans += y/x*4*x;
        y %= x;
    }
    cout<<ans;
    return 0;
}
/*
S=l*w
C=2*(l+w)
C/S = 2*(l+w)/l/w >= 4/sqrt(l*w) (l=w)
*/