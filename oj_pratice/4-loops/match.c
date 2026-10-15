#include<stdio.h>
typedef struct p{
    int x;
    int y;
}p;
const int dx[]={0,0,1,-1};
const int dy[]={1,-1,0,0};
int n,m;
p pos[130005][2];
int mp[505][505];
bool vis[505][505];

bool check(int x,int y,int dir){
    int nx = x;
    int ny = y;
    while(nx > 0 && ny > 0 && nx <= n && ny <= m){
        nx += dx[dir];
        ny += dy[dir];
        if(!vis[nx][ny] && nx > 0 && ny > 0 && nx <= n && ny <= m)
            return false;
    }
    return true;
}

int max(int a,int b){
    return a>b?a:b;
}

int main(){
    scanf("%d%d",&n,&m);
    int maxnum = -1;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++){
            scanf("%d",&mp[i][j]);
            maxnum = max(maxnum,mp[i][j]);
            if(pos[mp[i][j]][0].x == 0) pos[mp[i][j]][0].x = i,pos[mp[i][j]][0].y = j;
            else pos[mp[i][j]][1].x = i,pos[mp[i][j]][1].y = j;
        }
    //printf("%d %d",check(pos[2][0].x,pos[2][0].y,1),check(pos[2][1].x,pos[2][1].y,1));
    for(int i=1;i<=maxnum;i++){
        for(int j=0;j<4;j++)
            if(!vis[pos[i][0].x][pos[i][0].y] && check(pos[i][0].x,pos[i][0].y,j) && check(pos[i][1].x,pos[i][1].y,j)){
                vis[pos[i][0].x][pos[i][0].y] = vis[pos[i][1].x][pos[i][1].y] = true;
                //printf("%d %d\n",i,j);
                printf("%d ",i);
            }
    }
    return 0;
}