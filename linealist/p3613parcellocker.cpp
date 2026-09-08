#include<bits/stdc++.h>
using namespace std;
int n,q;
map <pair<int,int>,int> mp;
int main(){
    scanf("%d%d",&n,&q);
    while(q--){
        int te=0,i,j,k;
        scanf("%d%d%d",&te,&i,&j);
        
        pair <int,int> p;
        p.first=i;p.second=j;
        if(te == 1){
            scanf("%d",&k);
            if(k != 0)
                mp[p]=mp[p]+k;
            else
                mp[p]=0;
            
        }
        if(te == 2)
            printf("%d\n",mp[p]);
    }

    return 0;
}