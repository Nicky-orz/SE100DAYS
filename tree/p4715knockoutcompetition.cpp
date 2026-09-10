#include<bits/stdc++.h>
using namespace std;
int n;
int a1=-1,a2=-1,b1,b2;
int main(){
    cin>>n;
    for(int i=0;i<int(1 << n-1);i++){
        int t;
        cin>>t;
        if(t > a1){
            a1=t;
            b1=i+1;
        }
    }
    for(int i=0;i<int(1 << n-1);i++){
        int t;
        cin>>t;
        if(t > a2){
            a2=t;
            b2=i+1+int(1 << n-1);
        }
    }
    if(a1 > a2)
        cout<<b2;
    else
        cout<<b1;
    return 0;
}