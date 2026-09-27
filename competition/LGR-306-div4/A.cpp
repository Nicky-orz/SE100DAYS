#include<bits/stdc++.h>
using namespace std;
double a,b,ans;
int main(){
    cin>>a>>b;
    ans = a/3+b/4;
    if(ans == floor(ans))
        cout<<int(ans);
    else    
        cout<<int(ans)+1;
    return 0;
}