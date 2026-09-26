#include <bits/stdc++.h>
using namespace std;

const int maxn = 1005;
vector<int> Edge[30];
string s[maxn];
int outdeg[30], indeg[30];
vector<string> ans;
int n;

//这题和dfs回溯最大的不同是，题目要求全部串联，也就是形成欧拉路径
//欧拉路径用Hierholzer，知道欧拉路径有解就不需要回溯了
void dfs(int u) { //dfs作为处理子路径的函数
    while (!Edge[u].empty()) {
        int id = Edge[u].back();
        Edge[u].pop_back();
        dfs(s[id].back() - 'a');//处理完子路径后，已经把正确的子路径全部记录下来了
        ans.push_back(s[id]);   // 返回后才记录
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> s[i];
    sort(s, s + n);   // 先升序，方便后面降序排序

    for (int i = 0; i < n; i++) {
        int u = s[i].front() - 'a';
        int v = s[i].back() - 'a';
        outdeg[u]++;
        indeg[v]++;
        Edge[u].push_back(i);
    }

    // 降序排列，使 pop_back 取到当前最小单词
    for (int i = 0; i < 26; i++) {
        sort(Edge[i].begin(), Edge[i].end(), [&](int a, int b) {
            return s[a] > s[b];
        });
    }

    // 判断欧拉路径
    int start = -1;
    int cnt_start = 0, cnt_end = 0;
    bool ok = true;
    for (int i = 0; i < 26; i++) {
        if (outdeg[i] == indeg[i]) continue;
        if (outdeg[i] - indeg[i] == 1) {
            start = i;
            cnt_start++;
        } else if (indeg[i] - outdeg[i] == 1) {
            cnt_end++;
        } else {
            ok = false;
            break;
        }
    }

    if (!ok) {
        cout << "***";
        return 0;
    }

    if (cnt_start == 0 && cnt_end == 0) {
        // 欧拉回路：起点选有出边的最小字母
        for (int i = 0; i < 26; i++) {
            if (outdeg[i] > 0) {
                start = i;
                break;
            }
        }
    } else if (!(cnt_start == 1 && cnt_end == 1)) {
        cout << "***";
        return 0;
    }

    if (start == -1) {
        cout << "***";
        return 0;
    }

    dfs(start);

    if ((int)ans.size() != n) {
        cout << "***";
        return 0;
    }

    reverse(ans.begin(), ans.end());
    for (int i = 0; i < n; i++) {
        if (i) cout << '.';
        cout << ans[i];
    }
    return 0;
}

/*
AC代码，但是写的太乱了，让AI优化了逻辑
#include<bits/stdc++.h>
using namespace std;
const int maxn = 1005;
vector <int> Edge[30];
bool vis[maxn];
string s[maxn];
int outdeg[30],indeg[30];
vector <string> ans;
int n;
bool done;
void dfs(int x,int k){
    if(k == n){
        return;
    }
    for(int i:Edge[x]){
        int v = s[i].back() - 'a';
        if(!vis[i]){
            vis[i] = true;
            dfs(v,k+1);
            ans.push_back(s[i]);
        }
    }

}
int main(){
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>s[i];
    sort(s,s+n);
    for(int i=0;i<n;i++){
        int top,back;
        top = s[i].front() - 'a';
        back = s[i].back() - 'a';
        outdeg[top]++,indeg[back]++;
        Edge[top].push_back(i);
    }
    int op1=0,op2=0;
    int root = 0;
    op1 = op2 = false;
    for(int i=0;i<26;i++){
        if(indeg[i] != outdeg[i])
            op1 = true;
        if(indeg[i]+1 == outdeg[i])
            op2++,root = i;
    }
    if(!op1)
        for(int i=0;i<26;i++){
            if(outdeg[i] > 0){
                root = i;
                break;
            }
        }
    dfs(root,0);
    int sz = ans.size();
    if(sz != n){
        cout<<"***";
        return 0;
    }
    cout<<ans[sz-1];
    for(int i=sz-2;i>-1;i--)
        cout<<'.'<<ans[i];
    return 0;
}
*/
/*
回溯dfsTLE两个点
#include<bits/stdc++.h>
using namespace std;
const int maxn = 1005;
vector <int> Edge[30];
bool vis[maxn];
string s[maxn];
vector <string> ans;
int n;
bool done;
void dfs(int x,int k,int w){
    if(k == n){
        done = true;
        return;
    }
    for(int i:Edge[x]){
        int v = s[i].back() - 'a';
        if(!done && !vis[i]){
            ans.push_back(s[i]);
            vis[i] = true;
            dfs(v,k+1,i);
            if(!done){
                vis[i] = false;
                ans.pop_back();
            }
            
        }
    }
}
int main(){
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>s[i];
    sort(s,s+n);
    for(int i=0;i<n;i++){
        int top;
        top = s[i].front() - 'a';
        Edge[top].push_back(i);
    }
    for(int i=0;i<n;i++){
        ans.push_back(s[i]);
        vis[i] = true;
        dfs(s[i].back() - 'a',1,i);
        if(done) break;
        ans.pop_back();
        vis[i] = false;
    }
        
    if(done){
        cout<<ans[0];
        for(int i=1;i<ans.size();i++)
            cout<<'.'<<ans[i];
    }
    else{
        cout<<"***";
    }
    return 0;
}
*/