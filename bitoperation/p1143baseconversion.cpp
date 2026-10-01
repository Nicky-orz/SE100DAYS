#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m;
string number;
string ans;

string conver(int n,int m,string number){
    ll tmp = 0;
    for(int i=0;i<number.length();i++)
        if(number[i] > '9')
            tmp = tmp*n+number[i]-'A'+10;
        else
            tmp = tmp*n+number[i]-'0';
    ll ttmp = 1;
    string ans="";
    while(ttmp*m < tmp)
        ttmp*=m;
    while(ttmp > 0){
        if(tmp >= ttmp) {
            int num = tmp/ttmp;
            if(num > 9)
                ans += char(num-10+'A');
            else ans += char(num+'0');
            tmp = tmp % ttmp;
        }
        else
            ans += '0';
        ttmp/=m;
    }
    return ans;
}

int main(){
    cin>>n>>number>>m;
    cout<<conver(n,m,number);
    return 0;
}