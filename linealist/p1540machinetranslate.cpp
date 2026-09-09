#include<bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {};
};
Node* head=nullptr;
Node* tail=nullptr;
int n,m;
bool dic[1005];
int len,ans;

void ins(Node*& tail,int val){
    Node* newNode = new Node(val);
    if(tail == nullptr && head == nullptr){
        tail = newNode;
        head = newNode;
        return;
    }
    tail->next = newNode;
    tail = newNode;
    
}

void del(Node*& head){
    if(head == nullptr)
        return;
    head = head->next;
}
/*
void cou(Node* head){
    Node* cur = head;
    while(cur != nullptr){
        cout<<cur->data<<" ";
        cur = cur->next;
    }
}
*/
int main(){
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int a;
        cin>>a;
        if(!dic[a]){
            ans++;
            if(len<n){
                ins(tail,a);
                dic[a]=true;
                len++;
            }
            else{
                dic[head->data]=false;
                del(head);
                ins(tail,a);
                dic[a]=true;
            }
        }
        
    }
    cout<<ans;
    return 0;
}