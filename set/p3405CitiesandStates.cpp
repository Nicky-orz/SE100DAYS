#include<bits/stdc++.h>
using namespace std;
const int maxn = 200005;
const int hashmaxn = 26*26;
const int base=26;

int gethash(const string &s){
    return (s[0]-'A')*base+(s[1]-'A');
}

int main(){
    int n;
    cin>>n;
    int hash[hashmaxn][hashmaxn]={};

    for(int i=0;i<n;i++){
        int hashci,hashst;
        string city,state;

        cin>>city>>state;
        hashci = gethash(city);
        hashst = gethash(state);
        hash[hashst][hashci]++;
    }
    int ans;
    ans=0;
    for(int i=0;i<hashmaxn;i++)
        for(int j=0;j<hashmaxn;j++)
            if(hash[i][j] && hash[j][i] && i != j)
                ans+= hash[i][j]*hash[j][i];
    cout<<ans/2;
    return 0;
}