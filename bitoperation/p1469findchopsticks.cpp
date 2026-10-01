#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    int ans = 0;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        int tmp;
        scanf("%d",&tmp);
        ans ^= tmp;
    }
    cout<<ans;
    return 0;
}

/*
位运算模拟bool数组还是MLE了
#include<bits/stdc++.h>
using namespace std;
const int maxn = 1000000005;
map <int,unsigned long long> bits;

void flipbit(int i){
    bits[i>>6] ^= (1ULL << (i & 63));
}

bool getbit(int i){
    return (bits[i>>6] >> (i & 63)) & 1ULL;
}

int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int tmp;
        cin>>tmp;
        flipbit(tmp);
    }
    for(int i=1;i<=maxn-5;i++)
        if(getbit(i)){
            cout<<i;
            return 0;
        }
    cout<<-1;
    return 0;
}
*/