#include<bits/stdc++.h>
using namespace std;
struct point{
    int x,y;
};
int n,m;
int ans;
int dx[10]={1,1,1,0,0,-1,-1,-1};
int dy[10]={1,0,-1,1,-1,1,0,-1};
string ma[105];
bool vis[105][105];
void dfs(int nx,int ny){
    vis[nx][ny]=true;
    for(int i=0;i<8;i++){
        int lx=nx+dx[i],ly=ny+dy[i];
        if(lx>=0 &&  lx<n && ly>=0 && ly<m){
            if(!vis[lx][ly] && ma[lx][ly]=='W')
                dfs(lx,ly);
        }
        
    }
}
int main(){
    cin>>n>>m;
    for(int i=0;i<n;i++)
        cin>>ma[i];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(!vis[i][j] && ma[i][j]=='W'){
                dfs(i,j);
                ans++;
            }
                
        }
    }
    cout<<ans;
    return 0;
}