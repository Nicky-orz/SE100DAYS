#include<bits/stdc++.h>
using namespace std;
const int maxm = 100005;
struct Node{
    int criA,criB;
    int val;
}a[maxm];

int fa[40005],sz[40005];

bool cmp(Node x,Node y){
    if(x.val < y.val) return false;
    else return true;
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

int main(){
    int n,m,ans;
    ans=0;
    cin>>n>>m;
    init(2*n);
    for(int i=0;i<m;i++)
        cin>>a[i].criA>>a[i].criB>>a[i].val;
    sort(a,a+m,cmp);
    for(int i=0;i<m;i++){
        int faA1 = find(a[i].criA);
        int faB1 = find(a[i].criB);
        int faA2 = find(a[i].criA+n);
        int faB2 = find(a[i].criB+n);
        if(faA1 == faB1 || faA2 == faB2){
            ans = a[i].val;
            break;
        }
        unite(faA1,faB2);
        unite(faA2,faB1);
    }
    cout<<ans;
    return 0;
}
/*
WA+TLE:
1.放入i
2.判断i在set1,set2中哪个min
3.把i实际放入set中
4.cou,max(set1,set2)

check:
1.遍历set
    int n,m;
    int ans=0;

    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++){
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        if(a > b) swap(a,b);
        agrue[a][b] = c;
    }
    for(int i=1;i<=n;i++){
        int tmpA,tmpB;
        tmpA = tmpB = 0;
        for(auto A: cityA)
            tmpA = max(tmpA , agrue[A][i]);
        for(auto B: cityB)
            tmpB = max(tmpB , agrue[B][i]);
        if(tmpA < tmpB)  //暂时忽略agrue相同时导致的分支情况
            cityA.insert(i);
        else    
            cityB.insert(i);
        ans=max(ans, min(tmpA,tmpB) );
    }
    printf("%d\n",ans);

AC:
扩展域并查集

并查集中的元素是同真假的命题
*/