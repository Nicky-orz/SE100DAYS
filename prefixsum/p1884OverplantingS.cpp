#include<bits/stdc++.h>
using namespace std;

int xs[2005],ys[2005];
int diff[2005][2005];
int x1[1005],Y1[1005],x2[1005],y2[1005];

int main(){
    int n;
    cin>>n;
    int xn = 0, yn = 0;
    for(int i=0;i<n;i++){
        cin>>x1[i]>>Y1[i]>>x2[i]>>y2[i];
        xs[xn++] = x1[i]; xs[xn++] = x2[i];
        ys[yn++] = Y1[i]; ys[yn++] = y2[i];
    }
    sort(xs,xs+xn);
    sort(ys,ys+yn);
    xn = unique(xs,xs+xn) - xs;
    yn = unique(ys,ys+yn) - ys;
    for(int i=0;i<n;i++){
        int l = lower_bound(xs,xs+xn,x1[i]) - xs;
        int r = lower_bound(xs,xs+xn,x2[i]) - xs;
        int d = lower_bound(ys,ys+yn,y2[i]) - ys;
        int u = lower_bound(ys,ys+yn,Y1[i]) - ys;
        diff[l][d]++;
        diff[r][d]--;
        diff[l][u]--;
        diff[r][u]++;
    }
    for(int i=0;i<xn;i++)
        for(int j=0;j<yn;j++){
            if(i > 0) diff[i][j] += diff[i-1][j];
            if(j > 0) diff[i][j] += diff[i][j-1];
            if(i > 0 && j > 0) diff[i][j] -= diff[i-1][j-1];
        }
    long long ans = 0;
    for(int i=0;i<xn-1;i++)
        for(int j=0;j<yn-1;j++)
            if(diff[i][j] > 0)
                ans += (long long)(xs[i+1] - xs[i]) * (ys[j+1] - ys[j]);
    cout<<ans;
    return 0;
}