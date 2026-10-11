#include<stdio.h>
#include<string.h>
void solve(){
    char num[30]={};
    long long ans = 0,base = 3;
    fgets(num,sizeof(num),stdin);
    int len = strlen(num);
    for(int i=0;i<len-1;i++)
        if(num[i] != '1' && num[i] != '0' && num[i] != 'Z'){
            printf("Radix Error\n");
            return;
        }
    for(int i=0;i<len-1;i++){
        int dig;
        if(num[i] == 'Z') dig = -1;
        else dig = num[i] - '0';
        ans = ans*3+dig;
    }
    printf("%lld\n",ans);
}
int main(){
    int t;
    scanf("%d\n",&t);
    while(t--){
        solve();
    }
    return 0;
}