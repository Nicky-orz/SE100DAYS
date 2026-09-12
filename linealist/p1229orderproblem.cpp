#include <bits/stdc++.h>
using namespace std;
string pre,post;
int main() {
    cin>>pre>>post;
    int k=0;
    for (int i=0;i+1<(int)pre.size();i++){
        char x = pre[i];
        char y = pre[i+1];
        for (int j=0;j+1<(int)post.size();j++) 
            if (post[j] == y && post[j+1] == x) {
                k++;
                break;
            }
    }
    cout<<(1LL << k)<<endl;

    return 0;
}