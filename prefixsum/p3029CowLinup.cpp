#include<bits/stdc++.h>
using namespace std;
struct Cow{
    int x;
    int id;
};
const int maxn = 50005;

int n;
Cow cow[maxn];
bool cmp(Cow a,Cow b){
    return a.x < b.x;
}


int main(){
    vector<int> ids;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>cow[i].x>>cow[i].id;
        ids.push_back(cow[i].id);
    }

    sort(ids.begin(),ids.end());
    ids.erase(unique(ids.begin(), ids.end()), ids.end());
    for(int i=0;i<n;i++)
        cow[i].id = lower_bound(ids.begin(), ids.end(), cow[i].id) - ids.begin();
    
    sort(cow,cow+n,cmp);
    int cnt[maxn], dis = 0, ans = 1e9, l = 0;
    int tot = ids.size();
    memset(cnt,0,sizeof(cnt));
    for(int r=0;r<n;r++){
        cnt[cow[r].id]++;
        if(cnt[cow[r].id] == 1) dis++;
        while(dis == tot){
            ans = min(ans, cow[r].x - cow[l].x);
            cnt[cow[l].id]--;
            if(cnt[cow[l].id] == 0) dis--;
            l++;
        }
    }
    cout<<ans;
    return 0;
}