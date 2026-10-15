#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 20005;
int n;
ll ans;
pair <int,int> a[maxn];
int main(){
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>a[i].first>>a[i].second;
    sort(a,a+n);
    int l,r;
    bool check = false;
    for(int i=0;i<n;i++){
        if(!check){
            l = a[i].first;
            r = a[i].second;
            check = true;
        }
        else{
            if(a[i].first <= r)
                r = max(a[i].second,r);
            else{
                ans += r-l;
                l = a[i].first;
                r = a[i].second;
            }
        }
    }
    ans += r-l;
    cout<<ans;
    return 0;
}