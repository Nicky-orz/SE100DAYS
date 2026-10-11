#include<stdio.h>
#include<string.h>
typedef long long ll;
int n,m;
char number[55];
char ans[55];

int main(){
    m = 10;
    int len;
    scanf("%d %d\n",&len,&n);
    fgets(number,sizeof(number),stdin);
    ll tmp = 0;
    for(int i=0;i<len;i++){
        if(number[i] > '9'){
            if(number[i]-'A'+10 >= n){
                printf("Error");
                return 0;
            }
            else tmp = tmp*n+number[i]-'A'+10;
        }
        else{
            if(number[i]-'0' >= n){
                printf("Error");
                return 0;
            }
            else tmp = tmp*n+number[i]-'0';
        }
    }
        
    ll ttmp = 1;
    while(ttmp*m < tmp)
        ttmp*=m;
    int cnt = 0;
    while(ttmp > 0){
        if(tmp >= ttmp) {
            int num = tmp/ttmp;
            if(num > 9)
                ans[cnt++] = num-10+'A';
            else ans[cnt++] = num+'0';
            tmp = tmp % ttmp;
        }
        else
            ans[cnt++] = '0';
        ttmp/=m;
    }
    for(int i=0;i<cnt;i++)
        printf("%c",ans[i]);
    return 0;
}