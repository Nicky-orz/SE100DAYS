#include<bits/stdc++.h>
using namespace std;
int n;
int con0[1000005],con1[1000005],con2[1000005];
int main(){
    cin>>n;
    con0[0]=1;
    con0[1]=1;
    for(int i=2;i<=n;i++){
        con0[i]=(con0[i-1]+con1[i-1]+con2[i-1]+con0[i-2])%10000;
        con1[i]=(con0[i-2]+con2[i-1])%10000;
        con2[i]=(con0[i-2]+con1[i-1])%10000;
    }
    cout<<con0[n];
    return 0;
}