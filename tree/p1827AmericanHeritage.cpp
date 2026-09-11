#include<bits/stdc++.h>
using namespace std;
string a,b;
void solve(string in,string pre){
    if(in.empty() || pre.empty())
        return;
    char root = pre[0];
    int pos = in.find(root);

    string inleft = in.substr(0,pos);
    string inright = in.substr(pos+1);
    string preleft = pre.substr(1,pos);
    string preright = pre.substr(pos+1);

    solve(inleft,preleft);
    solve(inright,preright);
    cout<<root;
}
int main(){
    cin>>a>>b;
    solve(a,b);
    return 0;
}