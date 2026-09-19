#include<bits/stdc++.h>
using namespace std;
const int M = 500003;
struct Node{
    long long key;
    int val;
}h[M];

int gethash(long long x){
    return (x%M+M)%M;
}

void init(){
    for(int i=0;i<M;i++)
        h[i].key=-1;
}

void insert(long long x){
    int pos = gethash(x);
    while(h[pos].key != -1 && h[pos].key !=x)
        pos = (pos+1)%M;
    if(h[pos].key == x)
        h[pos].val++;
    else {
        h[pos].key = x;
        h[pos].val = 1;
    }
}

int query(long long x){
    int pos = gethash(x);
    while(h[pos].key != -1){
        if(h[pos].key == x)
            return h[pos].val;
        pos = (pos+1) %M;
    }
    return 0;
}

long long n,c;
long long a[M/2];
int main(){
    long long ans=0;
    cin>>n>>c;
    init();
    for(int i=0;i<n;i++){
        cin>>a[i];
        insert(a[i]);
    }
    for(int i=0;i<n;i++)
        ans+=query(a[i]+c);
    cout<<ans;
    return 0;
}