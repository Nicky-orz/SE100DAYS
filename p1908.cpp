#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
int a[500005],te[500005];
ll ans;
ll fz(int l,int r){
    if(l>=r)
        return 0;

    int m=(l+r)/2;
    ll le,ri;
    le=fz(l,m);
    ri=fz(m+1,r);

    ll nxd=0;
    int i=l,j=m+1,k=l;
    while (i<=m&&j<=r) {
        if (a[i]<=a[j]) {
            te[k++]=a[i++];
        } else {
            nxd+=(m-i+1);
            te[k++]=a[j++];
        }
    }
    while(i<=m) te[k++]=a[i++];
    while(j<=r) te[k++]=a[j++];
    for(int i=l;i<=r;i++)
        a[i]=te[i];
    return nxd+le+ri;
}
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    ans=fz(0,n-1);
    cout<<ans;
    return 0;
}