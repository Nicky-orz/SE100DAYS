#include<bits/stdc++.h>
using namespace std;
int n;
bool m[30005],k[30005];
int ans;
int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        int t;
        cin>>t;
        m[t]=true;
    }
    for(int i=0;i<10005;i++){
        for(int j=i+1;j<10005;j++)
            if(m[i]==true&&m[j]==true&&m[i+j]==true&&k[i+j]==false)
                ans++,k[i+j]=true;
    }
    cout<<ans;
    return 0;
}