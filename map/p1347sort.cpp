#include<bits/stdc++.h>
using namespace std;
const int maxn = 30;
vector <int> Edge[maxn];
vector <int> L;
int in[maxn];

int ans = -1;

void toposort(int n){
    int tin[maxn];
    queue <int> S;
    for(int i=0;i<n;i++){
        tin[i] = in[i];
        if(in[i] == 0) S.push(i);
    }
    int sl = S.size();

    if(sl == 1) ans = 1;
    if(sl == 0) ans = 0;
    if(sl > 1) ans = 2;

    while(!S.empty()){
        int num = 0;
        int u = S.front();
        S.pop();
        L.push_back(u);
        for(int v:Edge[u])
            if(--tin[v] == 0){
                S.push(v);
                num++;
            }
        if(num > 1)
            ans = 2;
    }
    if(L.size() != n)
        ans = 0;
}
int main(){
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        string s;
        cin>>s;

        int u = s[0] - 'A';
        int v = s[2] - 'A';
        Edge[u].push_back(v);
        in[v]++;
        L.clear();
        toposort(n);
        if(ans == 0){
            printf("Inconsistency found after %d relations.",i+1);
            break;
        }
        if(ans == 1 && L.size() == n){
            printf("Sorted sequence determined after %d relations: ",i+1);
            for(int k:L)
                printf("%c",k+'A');
            printf(".");
            break;
        }
    }
    if(ans == 2){
        printf("Sorted sequence cannot be determined.");
    }
    if(ans == -1){
        printf("Error");
    }
    return 0;
}