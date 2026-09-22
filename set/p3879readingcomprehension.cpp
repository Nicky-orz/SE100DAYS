#include<bits/stdc++.h>
using namespace std;
int n;
map <string,int> has[1005]; // RE,会把10^3当成100......
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        int l;
        string word;
        cin>>l;
        while(l--){
            cin>>word;
            has[i][word] = i;
        }
    }
    int m;
    cin>>m;
    while(m--){
        string query;
        cin>>query;
        for(int i=1;i<=n;i++){
            if(has[i].count(query))
                cout<<i<<" ";
        }
        cout<<"\n";
    }
    return 0;
}
//字符串哈希，每篇短文存到一个hash表里面，然后对单词查询每个hash表
//不想重复写了，偷个懒用map