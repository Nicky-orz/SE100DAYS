#include<bits/stdc++.h>
using namespace std;
string a,b;
void solve(string in,string post){
    if(in.empty() || post.empty())
        return;
    int len=post.length();
    char root = post[len-1];
    int pos = in.find(root);

    string inleft = in.substr(0,pos);
    string inright = in.substr(pos+1);
    string postleft = post.substr(0,pos);
    string postright = post.substr(pos,len-pos-1);

    cout<<root;
    solve(inleft,postleft);
    solve(inright,postright);
}
int main(){
    cin>>a>>b;
    solve(a,b);
    return 0;
}