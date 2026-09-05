#include<bits/stdc++.h>
using namespace std;
int n,numb[10][5]={{7,5,5,5,7},{3,3,3,3,3},{7,3,7,1,7},{7,3,7,3,7},{5,5,7,3,3},{7,1,7,3,7},{7,1,7,5,7},{7,3,3,3,3},{7,5,7,5,7},{7,5,7,3,7}};
string num,po[10]={"","X..",".X.","..X",".XX","X.X","XX.","XXX"};
int main(){
    cin>>n>>num;
    for(int i=0;i<5;i++){
        for(int j=0;j<num.length();j++){
            int te=num[j]-'0';
            if(j!=num.length()-1)
                cout<<po[numb[te][i]]<<'.';
            else
                cout<<po[numb[te][i]];
        }
        cout<<endl;
    }
    return 0;
}