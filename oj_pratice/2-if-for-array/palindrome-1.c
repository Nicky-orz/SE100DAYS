#include<stdio.h>
int main(){
    int n;
    char line[2005];
    scanf("%d",&n);
    int half = n/2;
    scanf("%s",line);
    for(int i=0;i<n;i++)
        if(line[i] == '?')
            line[i] = line[n-i-1];
    for(int i=0;i<n;i++)
        printf("%c",line[i]);
    return 0;
}