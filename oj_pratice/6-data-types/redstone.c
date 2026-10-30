#include<stdio.h>

int dx[]={-1,1,0,0};
int dy[]={0,0,-1,1};

int n,m,t;
char pre[105][105];
char next[105][105];

int CharToInt(char x){
    if(x >= '0' && x <= '9')
        return x - '0';
    else if(x >= 'A' && x <= 'F')
        return x - 'A' + 10;
    else if(x == '*')
        return 16;
    else return -1;
}

char IntToChar(int x){
    if(x >= 0 && x <= 9)
        return x + '0';
    else if(x >= 10 && x <= 15)
        return 'A' + x - 10;
    else
        return '\0';
}

bool CheckPowder(char x){
    return (x >= '0' && x <= '9')||(x >= 'A' && x <= 'F');
}

int GetDir(char c){
    if(c == 'n' || c == '^') return 0;
    if(c == 'u' || c == 'v') return 1;
    if(c == '(' || c == '<') return 2;
    if(c == ')' || c == '>') return 3;
    return -1;
}

int IsActive(char c){
    if(c == '^' || c == 'v' || c == '<' || c == '>') return 1;
    return 0;
}

void UpdatePowder(){//红石粉
    for(int round=0;round<15;round++){
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(CheckPowder(pre[i][j])){
                    int max_in = 0;
                    for(int k=0;k<4;k++){
                        int nx = i+dx[k];
                        int ny = j+dy[k];
                        if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                        if(pre[nx][ny] == '*'){
                            max_in = 16;
                        }
                        else if(CheckPowder(pre[nx][ny])){
                            int v = CharToInt(pre[nx][ny]);
                            if(v > max_in) max_in = v;
                        }
                        else if(IsActive(pre[nx][ny])){
                            int d = GetDir(pre[nx][ny]);
                            if(nx + dx[d] == i && ny + dy[d] == j){
                                max_in = 16;
                            }
                        }
                    }
                    int target = 0;
                    if(max_in > 0) target = max_in - 1;
                    pre[i][j] = IntToChar(target);
                }
            }
        }
    }
}

int main(){
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            scanf(" %c",&pre[i][j]);
            
    int x, y;
    char ord;
    scanf("%d %d %c",&x,&y,&ord);
    scanf("%d",&t);
    
    if(ord != '?') pre[x][y] = ord;
    
    UpdatePowder();
    
    for(int tick=1;tick<=t;tick++){
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                next[i][j] = pre[i][j];
        
        //中继器
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int d = GetDir(pre[i][j]);
                if(d == -1) continue;
                
                int bx = i - dx[d];
                int by = j - dy[d];
                int in_sig = 0;
                
                if(bx >= 0 && bx < n && by >= 0 && by < m){
                    char b = pre[bx][by];
                    if(b == '*') in_sig = 16;
                    else if(CheckPowder(b)) in_sig = CharToInt(b);
                    else if(IsActive(b)){
                        int bd = GetDir(b);
                        if(bx + dx[bd] == i && by + dy[bd] == j) in_sig = 16;
                    }
                }
                
                if(in_sig > 0){
                    if(d == 0) next[i][j] = '^';
                    if(d == 1) next[i][j] = 'v';
                    if(d == 2) next[i][j] = '<';
                    if(d == 3) next[i][j] = '>';
                }
                else{
                    if(d == 0) next[i][j] = 'n';
                    if(d == 1) next[i][j] = 'u';
                    if(d == 2) next[i][j] = '(';
                    if(d == 3) next[i][j] = ')';
                }
            }
        }
        
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                if(GetDir(pre[i][j]) != -1)
                    pre[i][j] = next[i][j];
        /*
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++)
                printf("%c",pre[i][j]);
            printf("\n");
        }
        */
        UpdatePowder();
    }
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)
            printf("%c",pre[i][j]);
        printf("\n");
    }
    return 0;
}
/*
3 8
*__00000
(*)))))0
___00000
1 1 ?
1
*/