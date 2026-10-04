#include<bits/stdc++.h>
using namespace std;
int n,m;
bitset <1000005> Bits;
int main(){
    cin>>n>>m;
    string s;
    cin>>s;
    for(int i=0;i<s.length();i++){
        if(s[i] == '1')
            Bits.set(i+1,true);
    }
    for(int i=0;i<m;i++){
        int t;
        cin>>t;
        if(Bits[t] == true) continue;
        else Bits[t] = true;
    }
    cout<<Bits.count();
    return 0;
}