#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef long long ll;
void solve(){
    char num[30]={};
    char ans[30]={};
    fgets(num,sizeof(num),stdin);
    int len = strlen(num);
    for(int i=0;i<len-1;i++){
        if(i == 0 && num[i] == '-') continue;
        if(num[i] < '0' || num[i] > '9'){
            printf("Radix Error\n");
            return;
        }
    }
    ll number = abs(atoi(num));
    if(number == 0){
        printf("0\n");
        return;
    }
    int cnt = 0;
    while(number > 0){
        int dig = number % 3;
        if(dig == 2){
            number++;
            ans[cnt++] = 'Z';
        }
        else ans[cnt++] = dig + '0';
        number /= 3;
    }
    for(int i=cnt-1;i>=0;i--){
        if(num[0] == '-'){
            if(ans[i] == 'Z')
                printf("1");
            else if(ans[i] == '1')
                printf("Z");
            else 
                printf("0");
        }
        else printf("%c",ans[i]);
    }
    printf("\n");
}

int main(){
    int t;
    scanf("%d\n",&t);
    while(t--){
        solve();
    }
    return 0;
}