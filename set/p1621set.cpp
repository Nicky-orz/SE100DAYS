#include<bits/stdc++.h>
using namespace std;
const int maxn = 100005;
int fa[maxn],sz[maxn];
bool prime[maxn];
vector <int> primes;

void solve(int n){
    prime[1] = true;
    for(int i=2;i<=n;i++){
        if(!prime[i]){
            primes.push_back(i);
            for(int j=i+i;j<=n;j+=i)
                prime[j] = true;
        }
    }
}

void init(int n){
    for(int i=1;i<=n;i++)
        fa[i]=i,sz[i]=1;
}

int find(int x){
    if(fa[x] == x) return x;
    else return fa[x] = find(fa[x]);
}

void unite(int x,int y){
    int fax = find(x);
    int fay = find(y);
    if(fax == fay)
        return;
    if(sz[fax] <= sz[fay])
        swap(fax,fay);
    fa[fay] = fax;
    sz[fax]+=sz[fay];
}

int count(int n,int m){
    int num=0;
    for(int i=n;i<=m;i++)
        if(fa[i] == i)
            num++;
    return num;
}

int main(){
    int a,b,p;
    cin>>a>>b>>p;
    init(b);
    solve(b);
    for(int i=1;i<=b;i++){
        if(!prime[i] && i >= p)
            for(int j=i;j<=b;j+=i) //j从i开始，合并集合不能把素数本身排除在外
                if(j >= a && j <= b && j+i >=a && j+i <=b)
                    unite(j,j+i);
    }
    cout<<count(a,b);
    return 0;
}