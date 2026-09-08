#include<bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node* prev;
    Node* next;
    Node(int val) : data(val), prev(nullptr), next(nullptr) {};
};
Node* head=new Node(1);
Node* pos[100005];

void ins(Node*& head,int val,int tar,int act){
    Node* newNode = new Node(val);
    Node* cur = pos[tar];
    if(act){
        newNode->next = cur->next;
        newNode->prev = cur;
        if(cur->next != nullptr)
            cur->next->prev = newNode;
        cur->next = newNode;
    }
    else{
        newNode->next = cur;
        newNode->prev = cur->prev;
        if(newNode->prev == nullptr)
            head=newNode;
        else
            cur->prev->next = newNode;
        cur->prev = newNode;
    }
    pos[val] = newNode;
}

void del(Node*& head,int tar){
    Node* cur = pos[tar];
    if(cur == nullptr)
        return;
    if(cur->prev == nullptr){
        head = cur->next;
        if(head != nullptr) head->prev = nullptr;
        return;
    }
    cur->prev->next = cur->next;
    if(cur->next != nullptr)
        cur->next->prev = cur->prev;
    pos[tar] = nullptr;
}

void cou(Node* head){
    Node* cur = head;
    while(cur->next != nullptr){
        cout<<cur->data<<" ";
        cur = cur->next;
    }
    cout<<cur->data;
}
int n,m;
int main(){
    ios::sync_with_stdio(false);
    cin>>n;
    pos[1] = head;
    for(int i=2;i<=n;i++){
        int k,p;
        cin>>k>>p;
        ins(head,i,k,p);
    }
    cin>>m;
    for(int i=0;i<m;i++){
        int x;
        cin>>x;
        del(head,x);
    }
    cou(head);
    return 0;
}