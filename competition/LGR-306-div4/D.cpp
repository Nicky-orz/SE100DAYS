#include<bits/stdc++.h>
using namespace std;
bool primes[105];

void solve(){
    primes[1] = true;
    for(int i=2;i<=105;i++){
        if(!primes[i]){
            for(int j=i+i;j<=105;j+=i)
                primes[j] = true;
        }
    }
}

long long ans;
string s;
int main(){
    cin>>s;
    solve();
    for(int i=1;i<s.length();i++){
        int puzzle = (s[i-1] - '0') *10 + (s[i] - '0');
        if(!primes[puzzle])
            ans += puzzle;
    }
    cout<<ans;
    return 0;
}