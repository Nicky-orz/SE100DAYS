#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int n, m, k;
int score = 0, fire = 0;
int recipe[205][15];

int cmp(const void *a, const void *b) {
    int x = *(const int *)a;
    int y = *(const int *)b;
    if (x < y) return -1;
    if (x > y) return 1;
    return 0;
}

int check(const int *food, int cnt){
    int che = 0;
    for(int i=0;i<m;i++){
        if(cnt > recipe[i][0]) continue;
        bool bomb = false;
        int k = 1;
        for(int j=0;j<cnt;j++){
            while(k <= recipe[i][0] && recipe[i][k] < food[j])
                k++;
            if(recipe[i][k] > food[j] || k > recipe[i][0]){
                bomb = true;
                break;
            }
            k++;
        }
        if(!bomb){
            if(cnt == recipe[i][0]){
                che = 2, recipe[i][0] = 0;
                break;
            }
            else{
                che = 1;
            }
        }
    }
    return che;
}

int main(){
    scanf("%d %d %d",&n,&m,&k);
    for(int i=0;i<m;i++){
        int cnt;
        scanf("%d",&cnt);
        recipe[i][0] = cnt;
        for(int j=1;j<=cnt;j++)
            scanf("%d",&recipe[i][j]);
        qsort(recipe[i]+1, cnt, sizeof(int), cmp);
    }
    int food[205], cnt = 0;
    memset(food, 0, sizeof(food));
    for(int i=0;i<k;i++){
        int t;
        scanf("%d",&t);
        bool bomb = false;
        for(int j=0;j<cnt;j++)
            if(food[j] == t)
                bomb = true;
        if(bomb){
            cnt = 0;
            memset(food, 0, sizeof(food));
            fire++;
        }
        else{
            food[cnt++] = t;
            qsort(food, cnt, sizeof(int), cmp);
            int che = check(food, cnt);
            if(che == 0){
                cnt = 0;
                memset(food, 0, sizeof(food));
                fire++;
            }
            else if(che == 1){
                continue;
            }
            else if(che == 2){
                cnt = 0;
                memset(food, 0, sizeof(food));
                score++;
            }
        }
    }
    if(score == m)
        printf("Well Done!\n");
    else if(fire == 0)
        printf("Not Bad!\n");
    else printf("Cooked!\n");
    printf("%d\n%d",score,fire);
    return 0;
}