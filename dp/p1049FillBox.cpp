#include<bits/stdc++.h>
using namespace std;
int V,n;
int a[35];
bool ans[20005];
int main(){
    cin>>V>>n;
    for(int i=0;i<n;i++)
        cin>>a[i];
    //sort(a,a+n);
    ans[0] = true;
    for(int i=n-1;i>=0;i--)
        for(int j=V;j>=a[i];j--)
            if(ans[j-a[i]])
                ans[j] = true;
    for(int i=V;i>=0;i--)
        if(ans[i]){
            cout<<V-i;
            break;
        }
    return 0;
}