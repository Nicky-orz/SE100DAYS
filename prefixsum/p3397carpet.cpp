#include<bits/stdc++.h>
using namespace std;
const int maxn = 1005;
int n,m;
int d[maxn][maxn];
int main(){
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int x1,x2,y1,y2;
        cin>>x1>>y1>>x2>>y2;
        for(int j=x1;j<=x2;j++){
            d[j][y1]++;
            d[j][y2+1]--;
        }
    }
    int now = 0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            now = now + d[i][j];
            cout<<now<<" ";
        }
        now += d[i][n+1];
        cout<<"\n";
    }
    return 0;
}
//上面写法本质一维差分，修改的时间复杂度O(n)
//二维差分是d[i][j] = a[i][j] - a[i-1][j] - a[i][j-1] + a[i-1][j-1]
//修改(x1,y1),(x2+1,y1),(x1,y2+1),(x2+1,y2+1)
//差分中，原数组被视作差分数组的前缀和数组