#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define maxn 100005

char s[maxn];
char sta_ch[maxn];
int  sta_pos[maxn];
int  top = 0;
bool che[maxn];

void solve(){
    memset(sta_ch,0,sizeof(sta_ch));
    memset(sta_pos,0,sizeof(sta_pos));
    memset(che,0,sizeof(che));
    top = 0;
    scanf("%s",s);
    int len = strlen(s);
    for(int i=0;i<len;i++){
        if(s[i] == '(' || s[i] == '[' || s[i] == '{'){
            sta_ch[top] = s[i];
            sta_pos[top] = i;
            top++;
        }else if(top > 0){
            if(s[i] == ')' && sta_ch[top-1] == '('){
                che[i] = che[sta_pos[top-1]] = true;
                top--;
            }else if(s[i] == ']' && sta_ch[top-1] == '['){
                che[i] = che[sta_pos[top-1]] = true;
                top--;
            }else if(s[i] == '}' && sta_ch[top-1] == '{'){
                che[i] = che[sta_pos[top-1]] = true;
                top--;
            }
        }
    }
    bool ans = true;
    for(int i=0;i<len;i++){
        if(che[i]) continue;
        ans = false;
        break;
    }
    if(ans) printf("True\n");
    else printf("False\n");
}

int main(){
    int t;
    scanf("%d\n",&t);
    while(t--){
        solve();
    }
    return 0;
}