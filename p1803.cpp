#include<bits/stdc++.h>
using namespace std;
struct pa{
    int a,b;
};
int n,ans;
pa bs[1000005];
int main(){
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>bs[i].a>>bs[i].b;
    sort(bs,bs+n,[](const pa& aa, const pa& bb) {return aa.b < bb.b;});
    int time=0;
    for(int i=0;i<n;i++)
        if(bs[i].a>=time){
            ans++;
            time=bs[i].b;
        }
            
    cout<<ans;
    return 0;
}