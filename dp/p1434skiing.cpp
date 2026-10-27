#include<bits/stdc++.h>
using namespace std;

const int dx[]={0,0,1,-1};
const int dy[]={1,-1,0,0};
struct Node{
    int x,y,val;
};
int R,C;
int mp[105][105];
int dp[105][105];
vector <Node> node;

bool cmp(Node a,Node b){
    return a.val > b.val;
}

int main(){
    cin>>R>>C;
    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            cin>>mp[i][j];
            node.push_back({i,j,mp[i][j]});
        }
    }
    sort(node.begin(),node.end(),cmp);
    for(auto n:node){
        for(int i=0;i<4;i++){
            int nx = n.x + dx[i];
            int ny = n.y + dy[i];
            if(nx < 0 || nx >= R || ny < 0 || ny >= C) continue;
            if(mp[nx][ny] < mp[n.x][n.y])
                dp[nx][ny] = max(dp[nx][ny], dp[n.x][n.y]+1);
        }
    }
    int ans = -1;
    for(int i=0;i<R;i++)
        for(int j=0;j<C;j++)
            ans = max(ans, dp[i][j]);
    cout<<ans+1;
    return 0;
}