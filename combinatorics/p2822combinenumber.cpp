#include<bits/stdc++.h>
using namespace std;
int t,k;
int num[2005][2005];
int add[2005][2005];
int main(){
    for(int i=0;i<=2000;i++)
        num[i][0] = 1;
    cin>>t>>k;
    for(int i=1;i<=2000;i++){
        for(int j=1;j<=i;j++){
            num[i][j] = (num[i-1][j] + num[i-1][j-1])%k;
        }
    }
    for(int i=1;i<=2000;i++)
        for(int j=1;j<=2000;j++)
            add[i][j] = add[i][j-1] + add[i-1][j] - add[i-1][j-1] + (j <= i && num[i][j] == 0);
    while(t--){
        int n,m;
        cin>>n>>m;
        cout<<add[n][m]<<"\n";
    }
    return 0;
}