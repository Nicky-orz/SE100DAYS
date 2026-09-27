#include<bits/stdc++.h>
using namespace std;
int x,y,z;
long long ans;
int main(){
    cin>>x>>y>>z;
    for(int i=x;i<=y;i++)
        ans = ans + i/z;
    cout<<ans;
    return 0;
}