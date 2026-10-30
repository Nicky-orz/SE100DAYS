#include<stdio.h>
#include<string.h>

typedef struct Point{
    int x,y;
}Point;

int max(int a, int b){
    return a<b?b:a;
}

int min(int a, int b){
    return a<b?a:b;
}

int n,m,d;
Point ans[100005];
int mp[1205][1205];
long long add[1205][1205];

int main(){
    scanf("%d %d %d",&n,&m,&d);
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            scanf("%d",&mp[i+j+1][i-j+m]);
    for(int i=1;i<n+m;i++)
        for(int j=1;j<n+m;j++)
            add[i][j] = mp[i][j] + add[i-1][j] + add[i][j-1] - add[i-1][j-1];
    int cnt = 0;
    long long score = -1e9;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++){
            int x = i+j+1;
            int y = i-j+m;

            int x1 = max(1, x-d);
            int y1 = max(1, y-d);
            int x2 = min(n+m-1, x+d);
            int y2 = min(n+m-1, y+d);
            long long sum = add[x2][y2] - add[x2][y1-1] - add[x1-1][y2] + add[x1-1][y1-1];
            if(sum > score){
                cnt = 0;
                score = sum;
                memset(ans,0,sizeof(ans));
                ans[++cnt] = (Point){i,j};
            }
            else if(sum == score)
                ans[++cnt] = (Point){i,j};
        }
    printf("%lld %d\n",score,cnt);
    for(int i=1;i<=cnt;i++){
        printf("%d %d\n",ans[i].x+1,ans[i].y+1);
    }
    return 0;
}