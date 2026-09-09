#include<bits/stdc++.h>
using namespace std;
string s;
stack <pair<char,int>> sta;
bool che[105];
int main(){
    cin>>s;
    for(int i=0;i<s.length();i++){
        if(s[i] == '(')
            sta.push(pair<char,int>('(',i));
            
        if(s[i] == '[')
            sta.push(pair<char,int>('[',i));
            
        if(!sta.empty()){
            if(s[i] == ')' && sta.top().first == '('){
                che[i]=che[sta.top().second]=true;
                sta.pop();
            }

            if(s[i] == ']' && sta.top().first == '['){
                che[i]=che[sta.top().second]=true;
                sta.pop();
            }
        }
    }
    for(int i=0;i<s.length();i++){
        if(che[i]){
            cout<<s[i];
            continue;
        }
        if(s[i] == '(' || s[i] == ')')
            cout<<"()";
        if(s[i] == '[' || s[i] == ']')
            cout<<"[]";
    }
    return 0;
}
