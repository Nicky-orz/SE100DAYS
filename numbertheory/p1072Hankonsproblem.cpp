#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct Node{
    int key;
    ll val;
};

vector <Node> ys;
int ysz;
ll a0,a1,b0,b1;
vector <ll> ans;
ll gcd(ll a,ll b){
    while(a%b != 0){
        ll tmp = a%b;
        a = b;
        b = tmp;
    }
    return b;
}

void dfs(int k,ll x){
    if(k == ysz)
        return;
    ll num = ys[k].key;
    for(int i=0;i<=ys[k].val;i++){
        ll tmp = x;
        for(int j=0;j<i;j++)
            tmp*=num;
        if(gcd(tmp,a0) == a1 && gcd(tmp,b0)*b1 == tmp*b0){
            ans.push_back(tmp);
        }
        dfs(k+1,tmp);
    }
}

void solve(){
    ys.clear();
    ans.clear();
    cin>>a0>>a1>>b0>>b1;
    if(b1 == 1){
        if(gcd(1,a0) == a1 && gcd(1,b0)*b1 == 1*b0)
            cout<<"1\n";
        else
            cout<<"0\n";
        return;
    }
    int i = 2;
    ll tb1 = b1;
    while(tb1 != 1 && i <= sqrt(tb1)){
        if(tb1%i == 0){
            tb1/=i;
            if(ys.empty()){
                Node tmp={i,1};
                ys.push_back(tmp);
            }
            else if(ys.back().key == i){
                ys.back().val++;
            }
            else{
                Node tmp={i,1};
                ys.push_back(tmp);
            }
        }
        else i++;
    }
    if(tb1 != 1){ //由于找因子只找到sqrt,必须要补上最后的一个因子
        Node tmp={int(tb1),1};
        ys.push_back(tmp);
    }
    ysz = ys.size();
    dfs(0,1);
    if(ans.empty()){
        cout<<"0\n";
        return;
    }
    sort(ans.begin(),ans.end());
    ans.erase(unique(ans.begin(),ans.end()),ans.end());
    cout<<ans.size()<<"\n";
}

int main(){
    int t;
    cin>>t;
    while(t--)
        solve();
    return 0;
}