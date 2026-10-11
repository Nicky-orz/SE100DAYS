#include<bits/stdc++.h>
using namespace std;
const int maxn = 125;
typedef long long ll;
ll add[maxn][maxn];

int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++){
            ll a;
            cin>>a;
            add[i][j] = add[i-1][j] + add[i][j-1] - add[i-1][j-1] + a;
        }
    ll ans = -1e9;
    for(int x=1;x<=n;x++)
        for(int y=1;y<=n;y++)
            for(int i=x;i<=n;i++)
                for(int j=y;j<=n;j++)
                    ans = max(ans,add[i][j] - add[x-1][j] - add[i][y-1] + add[x-1][y-1]);
    cout<<ans;
    return 0;
}