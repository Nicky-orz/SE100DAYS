#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
const ull base=131;

ull gethash(const string &s){
    ull h=0;
    for(auto c:s)
        h=h*base+c;
    return h;
}


int main(){
    int n;
    cin>>n;
    vector <ull> hashes;
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        hashes.push_back(gethash(s));
    }
    sort(hashes.begin(),hashes.end());
    hashes.erase(unique(hashes.begin(),hashes.end()),hashes.end());
    cout<<hashes.size()<<endl;
    return 0;
}