#include<bits/stdc++.h>
using namespace std;
const int dx[]={0,0,1,-1};
const int dy[]={1,-1,0,0};
const int maxn = 1505;
struct p{
    int x,y;
}root,rel[maxn][maxn];
int n,m;
bool mp[maxn][maxn];
bool ans;

void dfs(int x,int y,int rx,int ry){
    //cout<<x<<" "<<y<<" "<<mp[x][y]<<"\n";
    rel[x][y].x = rx;rel[x][y].y =ry;
    for(int i=0;i<4;i++){
        int nx = x+dx[i];
        int ny = y+dy[i];
        int nrx = rx+dx[i];
        int nry = ry+dy[i];
        nx = (nx + n) %n;
        ny = (ny + m) %m;
        if(!mp[nx][ny]) continue; //撞墙
        
        if(rel[nx][ny].x == 0 && rel[nx][ny].y == 0){//没来过
            dfs(nx,ny,nrx,nry);
        } 
        else if(rel[nx][ny].x == nrx && rel[nx][ny].y == nry) continue; //访问重复点
        else{ //可无限循环
            ans = true;
        }


        /*
        两次dfs不能处理成环的迷宫
        if(!che){
            if(nx < 0 || ny < 0 || nx >=  n || ny >= m){
                nx = (nx + n) %n;
                ny = (ny + m) %m;
                if(nx == parent.x && ny == parent.y)
                    continue;
                if(mp[nx][ny])
                    dfs(nx,ny,now,true);
            }
            else if(!mp[nx][ny] || vis[nx][ny]) continue;
            else dfs(nx,ny,now,che);
        }
        else{
            if(nx < 0 || ny < 0 || nx >=  n || ny >= m){
                nx = (nx + n) %n;
                ny = (ny + m) %m;
                if(nx == parent.x && ny == parent.y)
                    continue;
                if(mp[nx][ny]){
                    if(vis[nx][ny]) ans = true;
                    else dfs(nx,ny,now,che);
                }
            }
            else if(!mp[nx][ny]) continue;
            else if(vis[nx][ny]) ans = true;
            else dfs(nx,ny,now,che);
        }
        */
    }
}

void init(int n,int m){
    memset(mp,0,sizeof(mp));
    for(int i=0;i<=n;i++)
        for(int j=0;j<=m;j++)
            rel[i][j].x = rel[i][j].y = 0;
}

int main(){
    while(cin>>n>>m){
        init(n,m);
        root.x = root.y =0;
        ans = false;
        for(int i=0;i<n;i++){
            string s;
            cin>>s;
            for(int j=0;j<m;j++){
                if(s[j] != '#') mp[i][j] = true;
                if(s[j] == 'S') root.x = i,root.y = j;
            }
        }
        dfs(root.x,root.y,root.x,root.y);
        cout<<(ans?"Yes\n":"No\n");
    }
    return 0;
}
/*
5 6
###.##
###.##
###S##
....##
######

*/