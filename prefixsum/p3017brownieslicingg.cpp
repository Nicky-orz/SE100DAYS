#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int R,c,a,b;
ll add[505][505];

bool check(ll m){
    int cnt = 0,sta = 1;
    ll sum = 0;
    for(int i=1;i<=R;i++){
        sum += add[i][c] - add[i-1][c];
        if(sum/b < m) continue;
        ll ccnt = 0;
        int csta = 0;
        for(int j=1;j<=c;j++){
            ll csum = add[i][j] - add[sta-1][j] - add[i][csta] + add[sta-1][csta];
            if(csum >= m)
                ccnt++,csta = j;
        }
        if(ccnt >= b){
            cnt++;
            sum = 0;
            sta = i+1;
        }
    }
    return cnt >= a ? true : false;
}

int main(){
    cin>>R>>c>>a>>b;
    for(int i=1;i<=R;i++){
        for(int j=1;j<=c;j++){
            int t;
            cin>>t;
            add[i][j] = add[i-1][j] + add[i][j-1] - add[i-1][j-1] + t;
        }
    }
    ll l = 0, r = add[R][c]/a/b+1;
    while(l < r){
        ll mid = (l+r)/2;
        if(check(mid))
            l = mid+1;
        else
            r = mid;
    }
    cout<<l-1;
    return 0;
}