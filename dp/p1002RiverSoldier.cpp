#include<bits/stdc++.h>
using namespace std;
const int dx[]={1,1,2,2,-1,-1,-2,-2,0};
const int dy[]={2,-2,1,-1,2,-2,1,-1,0};

int bx,by,hx,hy;
long long dp[25][25];
int main(){
    cin>>bx>>by>>hx>>hy;
    dp[0][0] = 1;
    for(int i=0;i<=bx;i++)
        for(int j=0;j<=by;j++){
            bool check = false;
            for(int k=0;k<9;k++)
                if(i == hx+dx[k] && j == hy+dy[k])
                    check = true;
            if(check) continue;
            if(i != 0)
                dp[i][j] += dp[i-1][j];
            if(j != 0)
                dp[i][j] += dp[i][j-1];
        }
        
    cout<<dp[bx][by];
    return 0;
}