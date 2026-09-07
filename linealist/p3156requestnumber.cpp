#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[2000005];
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(int i=1;i<=m;i++){
        int req=0;
        scanf("%d",&req);
        printf("%d\n",a[req]);
    }
    return 0;
}