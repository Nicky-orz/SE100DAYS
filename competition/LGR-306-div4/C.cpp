#include<bits/stdc++.h>
using namespace std;
const int maxn = 1005;
bool mp[maxn][maxn];
int main(){
    int n,r;
    cin>>n>>r;
    int a = (n+1)/2;
    int b = (n+1)/2;
    for(int x=1;x<=n;x++)
        for(int y=1;y<=n;y++)
            if(sqrt( pow(x-a,2) + pow(y-b,2) ) <= r)
                mp[x][y] = true;
    for(int x=1;x<=n;x++){
        for(int y=1;y<=n;y++)
            if(mp[x][y]) cout<<"#";
            else cout<<".";
        cout<<"\n";
    }
        
    return 0;
}