#include<bits/stdc++.h>
using namespace std;
struct Node{
    int key,val;
};

void solve(){
    int n;
    map <int,int> tot; //桶计数法开map，a<=2^31-1
    vector <Node> ys;
    cin>>n;
    for(int i=0;i<n;i++){
        int t;
        cin>>t;
        for(int j=2;j*j<=t;j++){
            if(t%j == 0){
                int num = 0;
                while(t%j == 0){
                    t/=j;
                    num++;
                    tot[j]++;
                }
                if(i == 1) ys.push_back(Node{j,num});
            }
        }
        if(t != 1){
            if(i == 1)
                ys.push_back(Node{t,1});
            tot[t]++;
        }
            
    }
    bool check = true;
    for(Node num:ys){ //只需要判断a2做分母就够了，其它都可以变成分子，但a2不能
        if(num.val > tot[num.key] - num.val){
            check = false;
            break;
        }
    }
    cout<<(check?"Yes\n":"No\n");
}

int main(){
    int t;
    cin>>t;
    while(t--)
        solve();
    return 0;
}