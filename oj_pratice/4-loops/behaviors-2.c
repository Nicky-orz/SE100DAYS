#include<stdio.h>

int main(){
    int ans[20]={0,-1,-2,-3,-4,-5,-6,-7,8,9,-10,11,12};
    int n;
    int a=-1,b=0,c=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        int t;
        scanf("%d",&t);
        a = a&ans[t];
        b = b|ans[t];
        c = c^ans[t];
    }
    printf("%d %d %d",a,b,c);
    return 0;
}