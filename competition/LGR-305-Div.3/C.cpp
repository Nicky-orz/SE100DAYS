#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll mod = 1e9+7;
int t;
int n,k;
string s;

int main(){
    cin>>t;
    while(t--){
        int p = 0;
        ll pp = 1;
        ll kk = 1;
        cin>>n>>k>>s;
        for(int i=0;i<s.length();i++)
            if(s[i] == '1')
                p = max(i,p);
        p = n-p;
        if(p<k){cout<<"0\n";continue;} //p<k的特殊情况
        for(int i=0;i<p;i++)
            pp = pp*2%mod;
        for(int i=0;i<k;i++)
            kk = kk*2%mod;
        cout<<(pp-kk+mod)%mod<<"\n";
    }
    return 0;
}
//change(low,s.length())
//>>(low,s.length())