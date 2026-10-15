#include<stdio.h>
int count(int a){
    int cnt = 0;
    while(a > 0){
        cnt += a&1;
        a = a>>1;
    }
    return cnt;
}

int main(){
    int a,b;
    scanf("%d%d",&a,&b);
    printf("%d\n",a&b);
    printf("%d\n",a|b);
    printf("%d\n",a^b);
    printf("%d\n",~a);
    printf("%d\n",a<<b);
    printf("%d\n",a>>b);
    printf("%d\n",(a&(1<<b)) >> b);
    printf("%d\n",count(a));
    return 0;
}