#include<stdio.h>
#include<math.h>
int main(){
    int n,base;
    int nn;
    char ans[1005];
    int len = 0;
    scanf("%d%d",&n,&base);
    nn = n;
    while(abs(n) > 0){
        int low = n % base;
        n /= base;
        if(low < 0) n++,low -= base;
        if(low < 10) ans[len++] = low + '0';
        else ans[len++] = low - 10 + 'A';
    }
    printf("%d=",nn);
    for(int i=len-1;i>=0;i--)
        printf("%c",ans[i]);
    printf("(base%d)",base);
    return 0;
}