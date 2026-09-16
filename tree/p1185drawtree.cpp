#include<bits/stdc++.h>
using namespace std;
struct point{
    int x,y;
};
int n,m;
int H=1;
int width[15];
bool node[15][1000];
char ans[2000][2000];

void draw(int fx,int fy,int k,int w,bool dir){
    if(k>n || !node[k][w])
        return;
    int sx=fx,sy=fy;
    for(int i=1;i<=width[n-k];i++){
        sx++;
        if(!dir){
            sy--;
            ans[sx][sy]='/';
        }
        else{
            sy++;
            ans[sx][sy]='\\';
        }    
    }

    sx++;
    if(!dir) sy--; else sy++;
    ans[sx][sy]='o';
    draw(sx,sy,k+1,w*2-1,0);
    draw(sx,sy,k+1,w*2,1);
    
}
int main(){
    width[0]=1;
    width[1]=2;  
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=1<<(i-1);j++)
            node[i][j] = true;
    for(int i=2;i<=n;i++){
        width[i]=width[i-1]*2+1;
        H+=width[i-2]+1;
    }
    for(int i=1;i<=H;i++)
        for(int j=1;j<=width[n];j++)
            ans[i][j]=' ';
    for(int i=0;i<m;i++){
        point tmp;
        cin>>tmp.x>>tmp.y;
        node[tmp.x][tmp.y] = false;
    }

    point root;
    root.x = 1;
    root.y = width[n]/2+1;
    ans[root.x][root.y]='o';
    draw(root.x,root.y,2,1,0);
    draw(root.x,root.y,2,2,1);

    for(int i=1;i<=H;i++){
        for(int j=1;j<=width[n];j++)
            cout<<ans[i][j];
        cout<<endl;
    }
        
    return 0;
}

/*
                       o
                      / \
                     /   \
                    /     \
                   /       \
                  /         \
                 /           \           high[i]=width[n-i]
                /             \
               /               \
              /                 \
             /                   \
            /                     \ 
           o                       o           
          / \                     / \          
         /   \                   /   \         
        /     \                 /     \        
       /       \               /       \       
      /         \             /         \      
     o           o           o           o     
    / \         / \         / \         / \    
   /   \       /   \       /   \       /   \   
  o     o     o     o     o     o     o     o  
 / \   / \   / \   / \   / \   / \   / \   / \ 
o   o o   o o   o o   o o   o o   o o   o o   o

a1=5
a2=11
a3=23
a4=47
*/