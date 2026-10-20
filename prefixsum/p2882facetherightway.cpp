#include<bits/stdc++.h>
using namespace std;

const int maxn = 5005;

int n;
int dif[maxn];

int solve(int k){
    int d[maxn];
    for(int i=1;i<=n;i++)
        d[i] = dif[i];
    int m = 0;
    for(int i=1;i<=n;i++){
        if(d[i]%2 == 1){
            if(i+k <= n+1)
                d[i]++,d[i+k]++,m++;
            else
                return 1e9;     //代表无法翻转
        }
    }
    return m;
}

int main(){
    cin>>n;
    char t,lt = 'F';
    for(int i=1;i<=n;i++){
        cin>>t;
        dif[i] = (t != lt?1:0);
        lt = t;
    }
    int k,m = 1e9;
    for(int i=1;i<=n;i++){
        int im = solve(i);
        if(m > im)
            m = im, k = i;
    }
    cout<<k<<" "<<m;
    return 0;
}