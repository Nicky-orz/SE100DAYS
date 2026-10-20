#include<bits/stdc++.h>
using namespace std;

const int maxn = 100005;
typedef long long ll;

int n;
ll dif[maxn];
ll sum,nsum;
vector <int> ori;

ll solve(ll tar){
    if(dif[1] > tar) //1需要减操作
        return max(dif[1]-tar+sum,nsum);
    else
        return max(sum,tar-dif[1]+nsum); 
}
//target: tar 0 0 0 0 0 0 0 0 0 0...
//eg1: 1 1 0 -1
//eg2: -1 0 1 0
int main(){
    cin>>n;
    int t,lt = 0;
    for(int i=1;i<=n;i++){
        cin>>t;
        ori.push_back(t);
        dif[i] = t-lt;
        lt = t;
        if(i > 1){
            if(dif[i] > 0)
                sum += dif[i];
            else
                nsum += -dif[i];
        }
    }
    //cout<<solve(1)<<" "<<solve(2);
    ll tim = max(sum,nsum);
    ll var = llabs(sum-nsum)+1;
    cout<<tim<<"\n"<<var;
    return 0;
}
/*
构造tar a1 a2 an数列
寻求{d}使得dn = 0
*/