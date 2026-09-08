#include<bits/stdc++.h>
using namespace std;
stack <int> sta;
int main(){
    char c;
    int te=0;
    while(cin >> c && c!='@'){
        if(c-'0' >= 0 && c-'0' < 10)
            te=te*10+(c-'0');
        else if(c == '.'){
            sta.push(te);
            te=0;
        }
        else {
            int num1,num2;
            num2=sta.top();
            sta.pop();
            num1=sta.top();
            sta.pop();
            if(c == '+')
                sta.push(num1+num2);
            if(c == '-')
                sta.push(num1-num2);
            if(c == '*')
                sta.push(num1*num2);
            if(c == '/')
                sta.push(num1/num2);
        }
    }
    cout<<sta.top();
    return 0;
}