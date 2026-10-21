#include<stdio.h>
#include<math.h>
#define maxn 10005

bool prime[maxn];
int ans[maxn];
void solve(){
    prime[1] = true;
    for(int i=2;i<=sqrt(10000);i++){
        if(!prime[i])
            for(int j=i+i;j<=10000;j+=i)
                prime[j] = true;
    }
}

int reverse(int x){
    int t = 0;
    while(x > 0){
        t = t*10+x%10;
        x /= 10;
    }
    return t;
}

void count(){
    int cnt = 0;
    for(int i=1;i<=1000;i++){
        if(!prime[i] && !prime[reverse(i)])
            cnt++;
        ans[i] = cnt;
    }
}

int main(){
    solve();
    count();
    int n;
    scanf("%d",&n);
    printf("%d",ans[n]);
    return 0;
}