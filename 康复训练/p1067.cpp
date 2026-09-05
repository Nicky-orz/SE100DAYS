#include<bits/stdc++.h>
using namespace std;
int n,a[105];
bool nfir;
int main(){
    cin>>n;
    for(int i=0;i<=n;i++)
        cin>>a[i];
    for(int i=0;i<=n;i++)
        if(a[i]==0)
            continue;
        else {
            if(nfir&&a[i]>0) cout<<"+";
            if(i!=n){
                if(a[i]==1) {cout<<"x";nfir=true;}
                else if(a[i]==-1) {cout<<"-x";nfir=true;}
                else {cout<<a[i]<<"x";nfir=true;}
                if(i!=n-1) {cout<<"^"<<n-i;nfir=true;}
            }
            else{
                cout<<a[i];nfir=true;
            }
                
        }
    return 0;
}