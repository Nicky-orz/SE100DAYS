#include<bits/stdc++.h>
using namespace std;
string a,b,ans;
string plu(string m,string n){
    if(a=="0"||b=="0")
        return "0";
    int cm[2005]={},cn[2005]={},an[4005]={};
    int ml=m.length(),nl=n.length();
    int anl=ml+nl-1;
    string te;
    for(int i=0;i<ml;i++)
        cm[i]=m[ml-i-1]-'0';
    for(int i=0;i<nl;i++)
        cn[i]=n[nl-i-1]-'0';
    for(int i=0;i<nl;i++)
       for(int j=0;j<ml;j++)
            an[i+j]+=cm[j]*cn[i];
    for(int i=0;i<anl;i++)
        if(an[i]>=10)
            an[i+1]+=an[i]/10,an[i]%=10;
    while (an[anl]>0){
        an[anl+1]+=an[anl]/10;
        an[anl]%=10;
        anl++;
    } 
    for(int i=0;i<anl;i++)
        te.push_back(char('0'+an[anl-i-1]));
    return te;
}
int main(){
    cin>>a>>b;
    ans=plu(a,b);
    cout<<ans;
    return 0;
}