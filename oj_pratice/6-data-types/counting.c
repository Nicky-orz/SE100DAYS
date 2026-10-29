#include<stdio.h>
#define maxn 105
int R, C;
bool mp[maxn][maxn];
int count(int x, int y){
    int cnt = 0;
    int tx, ly, ry;
    tx = x; ly = y-1; ry = y;
    while(tx < R && ly >= 0 && ry < C && !mp[tx][ly] && mp[tx][ry]){
        int Tx, Ly, Ry;
        Tx = tx+1; Ly = ly; Ry = ry;
        while(Tx < R && mp[Tx][Ly] && !mp[Tx][Ry] && Ly+1 < Ry-1)
            Tx++, Ly++, Ry--;
        if(Ly == Ry-1 && mp[Tx][Ly] && !mp[Tx][Ry])
            cnt++;
        tx++, ly--, ry++;
    }
    return cnt;
}

int main(){
    
    scanf("%d %d",&R,&C);
    for(int i=0;i<R;i++){
        char t[maxn];
        scanf("%s",t);
        for(int j=0;j<C;j++)
            if(t[j] == '\\')
                mp[i][j] = true;
            else mp[i][j] = false;
    }
    int ans = 0;
    for(int i=0;i<R;i++){
        for(int j=1;j<C;j++){
            if(!mp[i][j-1] && mp[i][j])
                ans += count(i, j);
        }
    }
    printf("%d",ans);
    return 0;
}