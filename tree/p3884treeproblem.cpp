#include<bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    int depth;
    Node* fat;
    Node* left;
    Node* right;
    Node(int val) : data(val), depth(0), fat(nullptr), left(nullptr), right(nullptr){};
};

Node* pos[105];
bool vis[105];
int width[105];
vector<int> children[105];
int answidth = 1, ansdepth = 1, ansdist = -1;
void build(int u) {
    for (int v : children[u]) {
        Node* newNode = new Node(v);
        newNode->depth = pos[u]->depth + 1;
        newNode->fat = pos[u];
        if (!pos[u]->left)
            pos[u]->left = newNode;
        else
            pos[u]->right = newNode;
        pos[v] = newNode;
        width[newNode->depth]++;
        answidth = max(answidth, width[newNode->depth]);
        ansdepth = max(ansdepth, newNode->depth);
        build(v);
    }
}

void dfs(Node* root, int step, int tar){
    if (!root || ansdist != -1 || vis[root->data]) return;
    vis[root->data] = true;
    if (root->data == tar) {
        ansdist = step;
        return;
    }
    dfs(root->fat, step + 2, tar);
    dfs(root->left, step + 1, tar);
    dfs(root->right, step + 1, tar);
}

int main(){
    int n;
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        children[u].push_back(v);
    }
    pos[1] = new Node(1);
    pos[1]->depth = 1;
    width[1] = 1;
    build(1);

    int x, y;
    cin >> x >> y;
    dfs(pos[x], 0, y);

    cout << ansdepth << endl << answidth << endl << ansdist;
    return 0;
}