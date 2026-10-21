#include<bits/stdc++.h>
using namespace std;
int h[10005];

int main(){
    int l,hig,r;
    int Min = 1e9, Max = -1;
    while(cin>>l>>hig>>r){
        Min = min(Min,l);
        Max = max(Max,r);
        for(int i=l;i<r;i++)
            h[i] = max(h[i],hig);
    }
    for(int i=Min;i<=Max;i++){
        if(h[i] != h[i-1])
            cout<<i<<" "<<h[i]<<" ";
    }
    return 0;
}