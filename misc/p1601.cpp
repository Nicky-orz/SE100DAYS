#include<bits/stdc++.h>
using namespace std;
string a,b,ans;
string add(string m,string n){
    int cm[2005]={},cn[2005]={},an[2005]={};
    int ml=m.length(),nl=n.length();
    int anl=max(ml,nl);
    string te;
    for(int i=0;i<ml;i++)
        cm[i]=m[ml-i-1]-'0';
    for(int i=0;i<nl;i++)
        cn[i]=n[nl-i-1]-'0';
    for(int i=0;i<anl;i++)
        if(cm[i]+cn[i]+an[i]<10)
            an[i]=cm[i]+cn[i]+an[i];
        else
            an[i]=(cm[i]+cn[i]+an[i])%10,an[i+1]++;
    if(an[anl]==1)
        anl++;
    for(int i=0;i<anl;i++)
        te.push_back(char('0'+an[anl-i-1]));
    return te;
}
int main(){
    cin>>a>>b;
    ans=add(a,b);
    cout<<ans;
    return 0;
}