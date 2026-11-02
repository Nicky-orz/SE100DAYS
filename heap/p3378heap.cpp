#include<bits/stdc++.h>
using namespace std;

const int maxn = 1000005;

int h[maxn];
int n;

void up(int x){
  while(x > 1 && h[x] < h[x/2]){
    swap(h[x], h[x/2]);
    x /= 2;
  }
}

void down(int x){
  while(x*2 <= n){
    long long t = x * 2;
    if(t+1 <= n && h[t+1] < h[t]) t++;
    if(h[t] >= h[x]) break;
    swap(h[x], h[t]);
    x = t;
  }
}

void Insert(int num){
    h[++n] = num;
    up(n);
}

void Delete(){
    swap(h[1], h[n]);
    h[n--] = 0;
    down(1);
}
int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int op;
        cin>>op;
        switch(op){
            case 1:{
                int num;
                cin>>num;
                Insert(num);
                break;
            }
            case 2:{
                cout<<h[1]<<"\n";
                break;
            }
            case 3:{
                Delete();
                break;
            }
        }
    }
    return 0;
}