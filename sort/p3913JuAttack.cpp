#include<bits/stdc++.h>
using namespace std;
const int maxk = 1000005;
long long col[maxk],row[maxk];
int main(){
    long long n,k;
    cin>>n>>k;
    for(int i=0;i<k;i++)
        cin>>col[i]>>row[i];
    sort(col,col+k);
    sort(row,row+k);
    long long R = unique(row,row+k) - row; //sort+unique去重
    long long C = unique(col,col+k) - col;
    cout<<(R+C)*n - R*C;
    return 0;
}