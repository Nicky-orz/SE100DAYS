#include<bits/stdc++.h>
using namespace std;
int n,k,a[100005];
int ans;
int main(){
    cin>>n>>k;
    for(int i=0;i<n;i++)
        cin>>a[i];
    int le,ri;
    le=0;ri=100000000;
    while(le!=ri-1){
        int te=0;
        ans=(le+ri)/2;
        for(int i=0;i<n;i++)
            te+=a[i]/ans;
        if(te<k)
            ri=ans;
        else
            le=ans;
    }
    cout<<le;
    return 0;
}