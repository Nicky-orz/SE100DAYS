#include<stdio.h>
int main(){
    unsigned int n;
    scanf("%u",&n); //无符号整型%u
    printf("%u",(n << 16) | (n >> 16));
    return 0;
}