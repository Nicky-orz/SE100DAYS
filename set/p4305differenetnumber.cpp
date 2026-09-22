#include<bits/stdc++.h>
using namespace std;
const int N = 100007; //哈希值取质数,最起码是个奇数

int h[N];

int gethash(int x){
    return (x%N+N)%N;
}

void insert(int x){
    int has = gethash(x);
    while(h[has] != -1 && h[has] != x) {
        has = (has + 1)%N;
    }
    if(h[has] == -1){
        printf("%d ",x);
        h[has] = x;
    }
}

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        memset(h,-1,sizeof(h));
        int n;
        scanf("%d",&n);
        for(int i=0;i<n;i++){
            int a;
            scanf("%d",&a);
            insert(a);
        }
        printf("\n");
    }
    return 0;
}
//123456开放寻址TLE了4个点