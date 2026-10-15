#include<stdio.h>

const int dx[]={0,0,-1,1,1,1,-1,-1};
const int dy[]={1,-1,0,0,1,-1,1,-1};
int n;
char m[105][105];
int count(int x,int y){
    int cnt = 0;
    for(int i=0;i<8;i++){
        int nx = x+dx[i];
        int ny = y+dy[i];
        if(nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
        if(m[nx][ny] == '*')
            cnt++;
    }
    return cnt;
}

int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%s",m[i]);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
            if(m[i][j] == 'o')
                printf("%d",count(i,j));
            else
                printf("*");
        printf("\n");
    }
        
    return 0;
}