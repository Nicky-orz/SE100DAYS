#include<bits/stdc++.h>
using namespace std;
const int maxn = 100000005;
vector <int> primes;
bool prime[maxn];

void solve(int n){//欧拉筛
    prime[1] = true;
    for(int i=2;i<=n;i++){
        if(!prime[i]){
            primes.push_back(i);
        }
        for(int p:primes){
            if(i*p > n) break;
            prime[i*p] = true;
            if(i%p == 0) break;
        }
    }
}

/*
void solve(int n){//埃氏筛
    prime[1] = true;
    for(int i=2;i<=n;i++){
        if(!prime[i]){
            primes.push_back(i);
            for(int j=i+i;j<=n;j+=i)
                prime[j] = true;
        }
    }
}
*/
int main(){
    int n,q;
    scanf("%d%d",&n,&q);
    solve(maxn - 5);
    for(int i=0;i<q;i++){
        int t;
        scanf("%d",&t);
        printf("%d\n",primes[t-1]);
    }
    return 0;
}