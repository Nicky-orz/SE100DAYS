#include<bits/stdc++.h>
using namespace std;
const int Maxn=1005;
struct Node{
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {};
};

Node* pos[Maxn];

void leftins(int fat,int val){
    if(val == int('*'))
        return;
    Node* newNode = nullptr;
    if(pos[val] == nullptr){
        newNode = new Node(val);
        newNode->data = val;
        pos[val] = newNode;
    }
    else    
        newNode = pos[val];
    pos[fat]->left = newNode;
}

void rightins(int fat,int val){
    if(val == int('*'))
        return;
    Node* newNode = nullptr;
    if(pos[val] == nullptr){
        newNode = new Node(val);
        newNode->data = val;
        pos[val] = newNode;
    }
    else    
        newNode = pos[val];
    pos[fat]->right = newNode;
}

void pre(Node* root){
    if(!root)
        return;
    cout<<char(root->data);
    pre(root->left);
    pre(root->right);
}
int main(){
    int n,rootNode;
    cin>>n;
    for(int i=1;i<=n;i++){
        string tmp;
        cin>>tmp;

        int ro = int(tmp[0]);
        int l = int(tmp[1]);
        int r = int(tmp[2]);

        if(i == 1)
            rootNode = ro;
        if(!pos[ro])
            pos[ro] = new Node(ro);
        leftins(ro,l);
        rightins(ro,r);
    }
    pre(pos[rootNode]);
    return 0;
}