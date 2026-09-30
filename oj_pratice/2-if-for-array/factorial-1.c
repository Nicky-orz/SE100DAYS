#include<stdio.h>
int main(){
    int n;
    int ans = 0;
    int plus = 1;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
       plus = (plus*i)%10007,ans = (ans + plus)%10007;
    printf("%d",ans);
    return 0;
}