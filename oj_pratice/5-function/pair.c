#include<stdio.h>
#define maxn 1000005
int n,m,t;
int a[maxn];
int ans = 1e9;

int min(int a,int b){
    return a<b?a:b;
}

int main(){
    scanf("%d%d%d",&n,&m,&t);
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    for(int i=0;i<m;i++){
        int b;
        scanf("%d",&b);
        int l=0,r=n;
        while(l < r){
            int mid = (l+r)/2;
            if(a[mid]+b > t)
                r = mid;
            else
                l = mid+1;
        }
        if(l > 0) l--;
        //printf("%d %d\n",a[l],b);
        if(a[l]+b <= t)
            ans = min(ans,t-a[l]-b);
    }
    printf("%d",(ans==1e9?-1:ans));
    return 0;
}