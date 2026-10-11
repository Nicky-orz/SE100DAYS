#include<stdio.h>
#include<string.h>
typedef long long ll;
int main(){
    char s[10005];
    while(fgets(s,sizeof(s),stdin)){
        int n = strlen(s);
        for(int i=0;i<n;){
            if(s[i] >= '0' && s[i] <= '9'){
                ll ans = 0;
                int cnt=0;
                ll num[10005]={};
                while(i < n && s[i] >= '0' && s[i] <= '9')
                    num[++cnt] = s[i++] - '0';
                for(int j=1;j<=cnt;j++){
                    ll t=0;
                    for(int k=j;k<=cnt;k++){
                        t = t*(ll)10+num[k];
                        ans += t;
                    }
                }
                bool zero = true;
                while(ans > 0){
                    if(zero && ans%10 == 0) {
                        ans /= (ll)10;
                        continue;
                    }
                    else {
                        printf("%lld",ans%(ll)10);
                        zero = false;
                        ans /= (ll)10;
                    }
                }
                if(zero) printf("0");
            }
            else printf("%c",s[i++]);
        }
    }
    return 0;
}