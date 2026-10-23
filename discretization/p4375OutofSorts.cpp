#include<bits/stdc++.h>
using namespace std;
const int maxn = 100005;
struct Node{
    int val;
    int ori;
}id[maxn];
int n;
int a[maxn];
int d[maxn];

int moni(){
    int ans = 0;
    bool sorted = false;
    int t[maxn];
    for(int i=0;i<n;i++)
        t[i] = a[i];
    while(!sorted){
        sorted = true;
        ans++;
        for(int i=0;i<n-1;i++)//小数冒泡
            if(t[i+1] < t[i])
                swap(t[i+1],t[i]);
        for(int i=n-2;i>=0;i--)//大数冒泡
            if(t[i+1] < t[i])
                swap(t[i+1],t[i]);
        for(int i=0;i<n-1;i++)
            if(t[i+1] < t[i])
                sorted = false;
    }
    return ans;
}

bool cmp(Node a,Node b){ //处理同值
    if(a.val != b.val) return a.val < b.val;
    else return a.ori < b.ori;
}

int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
        id[i].val = a[i];
        id[i].ori = i;
    }
    //cout<<moni();
    sort(id,id+n,cmp);
    for(int i=0;i<n;i++)
        a[id[i].ori] = i;
    //cout<<endl;
    for(int i=0;i<n;i++){
        //cout<<a[i]<<" ";
        if(a[i] > i) d[i]++, d[a[i]]--;
    }
    /*cout<<endl;
    for(int i=0;i<n;i++)
        cout<<d[i]<<" ";*/
    int cnt = 0, ans = -1;
    for(int i=0;i<n;i++){
        cnt += d[i];
        ans = max(ans,cnt);
    }
    if(ans == 0) cout<<1;
    else    cout<<ans;
    return 0;
}
//从单向冒泡拓展到双向
//单向的大数和小数移动不同，但是双向的大小数移动是对称的