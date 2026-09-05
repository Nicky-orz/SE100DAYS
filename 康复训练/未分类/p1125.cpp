#include<bits/stdc++.h>
using namespace std;
int let[50];
string wor;
bool ans=true;
int main(){
    cin>>wor;
    for(int i=0;i<wor.length();i++)
        let[int(wor[i]-'a')]++;
    int ma=0,mi=114;
    for(int i=0;i<26;i++){
        ma=max(ma,let[i]);
        if(let[i]!=0)mi=min(mi,let[i]);
    }
    if((ma-mi)>1)
        for(int i=2;i<ma-mi;i++){
            if((ma-mi)%i==0)
                ans=false;
        }    
    else
        ans=false;
    if(ans)
        cout<<"Lucky Word"<<endl<<ma-mi;
    else
        cout<<"No Answer"<<endl<<0;
    return 0;
}