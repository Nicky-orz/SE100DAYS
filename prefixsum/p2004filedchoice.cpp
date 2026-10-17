#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1005;
ll a[maxn][maxn];
int main(){
    int n,m,c;
    cin>>n>>m>>c;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            int t;
            cin>>t;
            a[i][j] = a[i-1][j] + a[i][j-1] - a[i-1][j-1] + t;
        }
    }
    ll ans = -1;
    int x,y;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(i >= c && j >= c) {
                ll now = a[i][j] - a[i-c][j] - a[i][j-c] + a[i-c][j-c];
                if(ans < now)
                    ans = now, x = i-c+1, y = j-c+1;
            }
        }
    }
    cout<<x<<" "<<y;
    return 0;
}