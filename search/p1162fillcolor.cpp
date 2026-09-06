#include<bits/stdc++.h>
using namespace std;
int n;
int dx[5]={1,0,-1,0};
int dy[5]={0,1,0,-1};
int ma[35][35];
bool vis[35][35];
bool che;
void dfs(int x,int y){
    if(ma[x][y]==1 || vis[x][y])
        return;
    if(x<0 || x>=n || y<0 || y>=n){
        che=true;
        return;
    }

    vis[x][y]=true;
    for(int i=0;i<4;i++){
        int nx=x+dx[i],ny=y+dy[i];
        dfs(nx,ny);
    }
    if(!che)
        ma[x][y]=2;
}
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            scanf("%d",&ma[i][j]);
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            if(!vis[i][j]){
                che=false;
                dfs(i,j);
            }
               
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
            printf("%d ",ma[i][j]);
        printf("\n");
    }
        
    return 0;
}