#include<stdio.h>
void swap(long long *a, long long *b){
    long long t = *a;
    *a = *b;
    *b = t;
}
int main(){
    int n;
    long long a[55];
    long long ans = 1;
    long long mod = 1e9+7;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%lld",&a[i]);
    for(int i=0;i<n;i++)
        for(int j=i+1;j<n;j++)
            if(a[i] > a[j]) swap(&a[i],&a[j]);
    for(int i=0;i<n;i++){
        ans = ans * (a[i]- i) % mod;
        if(ans < 0){
            ans = 0;
            break;
        }
    }
    printf("%lld",ans);
    return 0;
}