#include<stdio.h>
int a[1000005];
int main(){
    int n;
    
    int ans;
    scanf("%d",&n);
    for(int i=0;i<2*n-1;i++){
        int tmp;
        scanf("%d",&tmp);
        a[tmp]++;
    }
    for(int i=1;i<1000005;i++){
        if(a[i] == 1)
            ans = i;
    }
    printf("%d",ans);
    return 0;
}