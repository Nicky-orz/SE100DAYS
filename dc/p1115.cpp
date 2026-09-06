#include<bits/stdc++.h>
using namespace std;
int n;
int a[200005];
int fz(int l,int r){
    int m=(l+r)/2;
    int le,ri,ml,mr,mil,mir;
    le=ri=ml=mr=0;
    mil=mir=-10005;
    if(l==r)
        return a[l];
    if(l+1==r)
        return max(a[l],a[r]);
    le=fz(l,m);
    ri=fz(m+1,r);
    for(int i=m;i>=l;i--){
        ml+=a[i];
        mil=max(mil,ml);
    }
    for(int i=m+1;i<=r;i++){
        mr+=a[i];
        mir=max(mir,mr);
    }
    return max(le,max(ri,mil+mir));
}
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    int ans=fz(0,n-1);
    cout<<ans;
    return 0;
}