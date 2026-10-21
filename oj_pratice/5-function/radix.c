#include <stdio.h>

int dig(int x) {
    int m = 0;
    while(x > 0){
        if(x%10 > m) m = x%10;
        x/=10;
    }
    return m;
}

int solve(int x, int b) {
    int v = 0,p = 1;
    while(x > 0){
        v += x%10*p;
        p *= b;
        x/=10;
    }
    return v;
}

int main() {
    int p,q,r;
    scanf("%d%d%d",&p,&q,&r);
    int md = dig(p);
    if(dig(q) > md) md = dig(q);
    if(dig(r) > md) md = dig(r);
    int lo = md+1;
    if(lo < 2)
        lo = 2;
    //printf("%d ",lo);
    for(int b=lo;b<=100;b++){
        if(solve(p,b)*solve(q,b) == solve(r,b)){
            printf("%d",b);
            return 0;
        }
    }
    printf("0");
    return 0;
}