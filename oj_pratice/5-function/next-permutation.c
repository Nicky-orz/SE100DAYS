#include<stdio.h>
#define maxn 2005
int n;
int a[maxn];

void swap(int *a,int *b){
    int t = *a;
    *a = *b;
    *b = t;
}

int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    int l = n-1, r = n-1;
    while(l-1 >= 0 && a[l-1] > a[l])
        l--;
    //printf("%d %d\n",l,r);
    int swa = l;
    while(swa+1 < n && a[swa+1] > a[l-1])
        swa++;
    swap(&a[l-1],&a[swa]);
    for(int i=0;i<l;i++)
        printf("%d ",a[i]);
    for(int i=r;i>=l;i--)   
        printf("%d ",a[i]);
    return 0;
}