#include<bits/stdc++.h>
using namespace std;
map <string,string> family;


string find(string x){
    if(family[x] == x) return x;
    else return family[x] = find(family[x]);
}

int main(){
    string s;
    string anc;
    while(cin>>s && s!= "$"){
        char order = s[0];
        string name=s.substr(1,s.length()-1);
        switch(order){
            case '#':{
                anc = name;
                if(!family.count(name))
                    family[name]=name;
                break;
            }
            case '+':{
                family[name] = anc;
                break;
            }
            case '?':{
                cout<<name<<" "<<find(name)<<endl;
                break;
            }
        }
    }
    return 0;
}