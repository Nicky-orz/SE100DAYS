#include<bits/stdc++.h>
using namespace std;
int k,gzx,gzy;
void dfs(int k,int lx,int ly,int px,int py){
    if(k==0) return;
    int hal=1<<(k-1);
    int mx=lx+hal;
    int my=ly+hal;
    if(px<mx&&py<my){
        printf("%d %d 1\n",mx,my);
        dfs(k-1,lx,ly,px,py);
        dfs(k-1,lx,my,mx-1,my);
        dfs(k-1,mx,ly,mx,my-1);
        dfs(k-1,mx,my,mx,my);
    }
    else if(px<mx&&py>=my){
        printf("%d %d 2\n",mx,my-1);
        dfs(k-1,lx,ly,mx-1,my-1);
        dfs(k-1,lx,my,px,py);
        dfs(k-1,mx,ly,mx,my-1);
        dfs(k-1,mx,my,mx,my);
    }
    else if(px>=mx&&py<my){
        printf("%d %d 3\n",mx-1,my);
        dfs(k-1,lx,ly,mx-1,my-1);
        dfs(k-1,lx,my,mx-1,my);
        dfs(k-1,mx,ly,px,py);
        dfs(k-1,mx,my,mx,my);
    }
    else if(px>=mx&&py>=my){
        printf("%d %d 4\n",mx-1,my-1);
        dfs(k-1,lx,ly,mx-1,my-1);
        dfs(k-1,lx,my,mx-1,my);
        dfs(k-1,mx,ly,mx,my-1);
        dfs(k-1,mx,my,px,py);
    }
}
int main(){
    cin>>k>>gzx>>gzy;
    dfs(k,1,1,gzx,gzy);
    return 0;
}