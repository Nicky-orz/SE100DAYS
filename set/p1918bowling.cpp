#include<bits/stdc++.h>
using namespace std;
const int M = 200005;
struct Node{
    int key;
    int val;
}h[M];

void init(){
    for(int i=0;i<M;i++)
        h[i].key = -1;
}

int gethash(int x){
    return (x%M+M)%M;
}

void insert(int x,int i){
    int pos = gethash(x);
    while(h[pos].key !=-1 && h[pos].key !=x)
        pos = (pos+1)%M;
    if(h[pos].key == -1){
        h[pos].key = x;
        h[pos].val = i;
    }
}

int query(int x){
    int pos = gethash(x);
    while(h[pos].key !=-1 && h[pos].key !=x)
        pos = (pos+1)%M;
     return h[pos].val;
}

void del(int x){
    int pos = gethash(x);
    h[pos].key = -1;
    h[pos].val = 0;
}

int main(){
    init();
    int n,q;
    cin>>n;
    for(int i=1;i<=n;i++){
        int a;
        cin>>a;
        insert(a,i);
    }
    cin>>q;
    while(q--){
        int a;
        cin>>a;
        int ans=query(a);
        cout<<ans<<"\n";
        //if(ans) del(a);居然发球之后不会撞倒球
    }
    return 0;
}