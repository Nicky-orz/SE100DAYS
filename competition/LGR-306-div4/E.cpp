#include<bits/stdc++.h>
using namespace std;
const int dx[]={0,1,0,-1};
const int dy[]={1,0,-1,0};
int h,w;
int mp[35][35];
int ans;
int main(){
    cin>>h>>w;
    for(int i=0;i<h;i++)
        for(int j=0;j<w;j++)
            cin>>mp[i][j];
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            for(int k=0;k<4;k++){
                int nx = i+dx[k];
                int ny = j+dy[k];
                if(nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
                if(mp[nx][ny] == mp[i][j])
                    ans++;
            }
        }
    }
    int maxplus = 0;
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            int tmp[5];
            tmp[1] = tmp[2] =tmp[3] = 0;
            for(int color = 1;color <= 3;color++){
                for(int k=0;k<4;k++){
                    int nx = i+dx[k];
                    int ny = j+dy[k];
                    if(nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
                    if(mp[nx][ny] == color)
                        tmp[color]++;
                }
                
            }
            for(int color = 1;color <= 3;color++)
                maxplus = max(maxplus,tmp[color] - tmp[mp[i][j]]);
        }
    }
    cout<<ans/2 + maxplus;
    return 0;
}