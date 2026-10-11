#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 100005;
ll add[maxn];
int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        int a;
        cin>>a;
        add[i] = add[i-1] + a;
    }
    int m;
    cin>>m;
    for(int i=1;i<=m;i++){
        int l,r;
        cin>>l>>r;
        cout<<add[r]-add[l-1]<<"\n";
    }
    return 0;
}