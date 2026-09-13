#include<bits/stdc++.h>
using namespace std;
const int INF=2147483647;
struct Node{
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {};
};

Node* root=nullptr;
Node* insert(Node* root, int val){
    if (!root) return new Node(val);
    if(val < root->data)
        root->left = insert(root->left, val);
    else if(val > root->data)
        root->right = insert(root->right, val);
    return root;
}

int getsize(Node* root){
    if(!root) return 0;
    return 1+getsize(root->left)+getsize(root->right);
}

int getrank(Node* root,int val){
    if(!root) return 1;
    if(val <= root->data)
        return getrank(root->left,val);
    else
        return 1+getsize(root->left)+getrank(root->right,val);
}


int getk(Node* root,int k) {
    int leftSize = getsize(root->left);
    if (k <= leftSize)
        return getk(root->left,k);
    else if (k == leftSize+1)
        return root->data;
    else
        return getk(root->right,k-leftSize-1);
}

int getpre(Node* root,int val){
    if(!root) return -INF;
    if(root->data >= val)
        return getpre(root->left,val);
    else    
        return max(root->data,getpre(root->right,val));
}

int getpost(Node* root,int val){
    if(!root) return INF;
    if(root->data <= val)
        return getpost(root->right,val);
    else    
        return min(root->data,getpost(root->left,val));
}


int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        if(a == 1)
            cout<<getrank(root,b)<<endl;
        if(a == 2)
            cout<<getk(root,b)<<endl;
        if(a == 3)
            cout<<getpre(root,b)<<endl;
        if(a == 4)
            cout<<getpost(root,b)<<endl;
        if(a == 5)
            root=insert(root,b);
    }
    return 0;
}