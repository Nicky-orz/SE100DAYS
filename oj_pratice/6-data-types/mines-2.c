#include<stdio.h>

typedef struct Bomb{
    int x,y,z;
}Bomb;
int dx[]={0,0,1,-1,0,0};
int dy[]={1,-1,0,0,0,0};
int dz[]={0,0,0,0,1,-1};
int n;

char mp[605][605][605];
unsigned char count[605][605][605]; 
Bomb req;
Bomb illegal[55];

char buf[1 << 24];
int buf_pos = 0, buf_len = 0;

char get_char() {
    if(buf_pos == buf_len){
        buf_len = fread(buf, 1, sizeof(buf), stdin);
        buf_pos = 0;
        if(buf_len == 0)return EOF;
    }
    return buf[buf_pos++];
}

char read_nonspace() {
    char c = get_char();
    while(c != '*' && c != '?' && (c < '0' || c > '9')) c = get_char();
    return c;
}

int requiry(int x, int y, int z, char tar){
    int cnt = 0;
    for(int i=0;i<6;i++){
        int nx = x+dx[i];
        int ny = y+dy[i];
        int nz = z+dz[i];
        if(nx <= 0 || nx > n ) continue;
        if(ny <= 0 || ny > n ) continue;
        if(nz <= 0 || nz > n ) continue;
        if(mp[nx][ny][nz] == tar) cnt++;
    }
    return cnt;
}

int main(){
    scanf("%d",&n);
    for(int x=1;x<=n;x++){
        for(int y=1;y<=n;y++){
            for(int z=1;z<=n;z++){
                mp[x][y][z] = read_nonspace();
                if(mp[x][y][z] == '?')
                    req = (Bomb){x,y,z};
                if(mp[x][y][z] == '*'){
                    for(int i=0;i<6;i++){
                        int nx = x+dx[i];
                        int ny = y+dy[i];
                        int nz = z+dz[i];
                        if(nx <= 0 || nx > n ) continue;
                        if(ny <= 0 || ny > n ) continue;
                        if(nz <= 0 || nz > n ) continue;
                        count[nx][ny][nz]++;
                    }
                }
            }
        }
    }

    int cnt = 0;
    bool check = true;
    bool need_bomb = false;
    bool need_empty = false;
    for(int x=1;x<=n;x++){
        for(int y=1;y<=n;y++){
            for(int z=1;z<=n;z++){
                if(mp[x][y][z] >= '0' && mp[x][y][z] <= '9'){
                    int expect = mp[x][y][z] - '0';
                    int base = count[x][y][z];
                    int near = requiry(x,y,z,'?');
                    bool ok_empty = (base == expect);
                    bool ok_bomb = (base + near == expect);

                    if (!ok_empty && !ok_bomb) {
                        illegal[++cnt] = (Bomb){x,y,z};
                        check = false;
                    } else if (!ok_empty && ok_bomb) {
                        need_bomb = true;
                    } else if (ok_empty && !ok_bomb) {
                        need_empty = true;
                    }
                }
            }
        }
    }

    if(!check || (need_bomb && need_empty)){
        printf("invalid\n");
        for(int x=1;x<=n;x++){
            for(int y=1;y<=n;y++){
                for(int z=1;z<=n;z++){
                    if(mp[x][y][z] >= '0' && mp[x][y][z] <= '9'){
                        int expect = mp[x][y][z] - '0';
                        int base = count[x][y][z];
                        int near = requiry(x,y,z,'?');
                        if (base + near != expect) {
                            printf("%d %d %d\n", x, y, z);
                        }
                    }
                }
            }
        }
    }else{
        printf("valid\n");
        if(need_bomb)
            printf("*\n");
        else
            printf("%d\n", count[req.x][req.y][req.z]);
    }

    return 0;
}