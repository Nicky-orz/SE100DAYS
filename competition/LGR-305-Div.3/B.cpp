#include<bits/stdc++.h>
using namespace std;
int n;
string s;
int ans;
int main(){
    cin>>n>>s;
    for(int x=1;x<=n;x++){
        for(int p=1;p<=n;p++){
            int tmp = 0;
            for(int i=p;i>=1;i-=2*x)
                if(s[i-1] == 'X')
                    tmp++;
                else break;
            for(int i=p+x;i<=n;i+=x)
                if(s[i-1] == 'X')
                    tmp++;
                else break;
            ans = max(ans,tmp);
        }
    }
    cout<<ans;
    return 0;
}