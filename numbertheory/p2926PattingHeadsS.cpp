#include<bits/stdc++.h>
using namespace std;
const int maxn = 100005;
int n;
int a[maxn];
int cow[1000005];
int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        int tmp;
        cin>>tmp;
        a[i] = tmp;
        cow[tmp]++;
    }
    for(int i=0;i<n;i++){
        int ans = 0;
        for(int j=1;j<=sqrt(a[i]);j++){
            if(a[i]%j == 0){
                if(a[i]/j != j) ans += cow[j] + cow[a[i]/j];
                else ans += cow[j];
            }
            //cout<<ans-1<<" ";
        }
        cout<<ans-1<<"\n";
    }
    return 0;
}
//O(n*sqrt(A))1e9真能过啊