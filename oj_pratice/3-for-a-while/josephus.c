#include<stdio.h>
int main(){
    int n,k;
    bool per[505]={};
    scanf("%d %d",&n,&k);
    int num = n;
    int i =0;
    int count = 0;
    while(num != 1){
        i++;
        if(i > n) i = 1;
        if(per[i]) continue;
        count++;
        if(count % k == 0) per[i] = true,num--;
    }
    for(int i=1;i<=n;i++)
        if(!per[i])
            printf("%d\n",i);
    return 0;
}