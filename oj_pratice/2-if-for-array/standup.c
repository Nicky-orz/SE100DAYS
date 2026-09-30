#include<stdio.h>
int main(){
    int n;
    int a[100005];
    scanf("%d",&n);
    for(int i=0;i<=n;i++)
        scanf("%d",&a[i]);
    int cur = 0;
    int ans = 0;
    for(int i=0;i<=n;i++)
        if(cur >= i)
            cur = cur + a[i];
        else
            ans += i - cur,cur = i + a[i];
    printf("%d",ans);
    return 0;
}