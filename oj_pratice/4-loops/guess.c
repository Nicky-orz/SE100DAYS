#include<stdio.h>

typedef long long ll;
ll ans;
int main(){
    ll le,ri;
    le=0;
    ri=(ll)1<<32;
    while(le <= ri){
        ans = (le+ri)/2;
        printf("%lld\n",ans);
        char reply[5];
        fflush(stdout);
        scanf("%s",reply);
        if(reply[0] == 'G')
            ri = ans - 1;
        if(reply[0] == 'L')
            le = ans + 1;
        if(reply[0] == 'E')
            return 0;
        if(reply[0] == 'O')
            return 0;
    }
    return 0;
}