#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll ans[3];

ll gcd(ll a,ll b){
    a = llabs(a); //取绝对值的辗转相除
    b = llabs(b);
    while(a%b != 0){
        ll tmp = a%b;
        a = b;
        b = tmp;
    }
    return llabs(b);
}

int main(){
    ll a,b;
    ans[1] = 0;ans[2] = 1;
    while(scanf("%lld/%lld",&a,&b) == 2){ //对于紧凑且格式固定的数据，可以用scanf格式化输入
        ll tmp = gcd(a,b); //ab约分
        a/=tmp;b/=tmp;
        //cout<<ans[1]<<"/"<<ans[2]<<"\n";
        ll gc = gcd(ans[2],b); //计算和/差
        ll lc = ans[2]/gc*b;
        ans[1] = ans[1]*lc/ans[2]+a*lc/b;
        ans[2] = lc;
        ll t = gcd(ans[1],ans[2]); //答案约分
        ans[1] /= t;
        ans[2] /= t;
    }
    if(ans[2] == 1)
        cout<<ans[1];
    else
        cout<<ans[1]<<"/"<<ans[2];
    return 0;
}