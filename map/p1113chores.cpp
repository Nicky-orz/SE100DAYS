#include<bits/stdc++.h>
using namespace std;
const int maxn = 10005;

int n;
int tim[maxn];
int ans;
int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        int a,b,t,tmp=0;
        cin>>a>>b;
        while(cin>>t && t!= 0)
            tmp = max(tmp,tim[t]);
        tim[a] = tmp+b;
        ans = max(ans,tim[a]);
    }
    cout<<ans;
    return 0;
}