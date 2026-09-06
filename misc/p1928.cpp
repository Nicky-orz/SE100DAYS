#include<bits/stdc++.h>
using namespace std;
string n,ans;
string ulo(string a){
    string te="",an=a,sub="";
    int al=a.length();
    int l,r,num;
    l=r=-1;
    for(int i=0;i<al;i++)
        if(a[i]=='[')
            l=i;
        else if(l!=-1&&a[i]==']'){
             r=i;
             break;
        }
    if(l!=-1&&r!=-1){
        int nn=0;
        if(a[l+2]-'0'>=0&&a[l+2]-'0'<10)
            num=(a[l+1]-'0')*10+a[l+2]-'0',nn=2;
        else
            num=a[l+1]-'0',nn=1;
        sub=a.substr(l+nn+1,r-l-nn-1);
        for(int i=0;i<num;i++)
            te+=sub;
        an.replace(l,sub.length()+2+nn,te);
    }
    return an;
}
int main(){
    cin>>n;
    string lans=n;
    ans=ulo(n);
    while(lans!=ans){
        lans=ans;
        ans=ulo(lans);
    }
    cout<<ans;
    return 0;
}