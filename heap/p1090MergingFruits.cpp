#include<bits/stdc++.h>
using namespace std;

const int maxn = 10005;

int n;
int h[maxn];

void up(int x){
    while(x > 1 && h[x] < h[x/2]){
        swap(h[x], h[x/2]);
        x /= 2;
    }
}

void down(int x){
    while(x*2 <= n){
        int t = x*2;
        if(t+1 <= n && h[t] > h[t+1]) t++;
        if(h[x] <= h[t]) break;
        swap(h[x], h[t]);
        x = t;
    }
}

void build(){
    for(int i=1;i<=n;i++){
        cin>>h[i];
        up(i);
    }
}

void Insert(int num){
    h[++n] = num;
    up(n);
}

void Delete(){
    swap(h[1], h[n]);
    h[n--] = 0;
    down(1);
}

int merge(){
    int ans = 0;
    while(n > 1){
        int t1,t2;
        t1 = h[1];
        Delete();
        t2 = h[1];
        Delete();
        ans += t1+t2;
        Insert(t1+t2);
        //cout<<ans<<"\n";
    }
    return ans;
}
int main(){
    cin>>n;
    build();
    int ans = merge();
    cout<<ans;
    return 0;
}