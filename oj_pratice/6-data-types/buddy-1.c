#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
    int data;
    int id;
    struct Node *next;
}Node;

int size = 1;

Node *new(int val){
    Node *newNode = malloc(sizeof(Node));
    newNode->data = val;
    newNode->id = 0;
    newNode->next = NULL;
    return newNode;
}

Node *split(Node *node, int tar) {
    int half = node->data/2;
    Node *right = new(half);
    right->next = node->next;
    node->data = half;
    node->next = right;
    size++;
    if(half == tar){
        return node;
    }else{
        return split(node, tar);
    }
}

Node *find_exact(Node *node, int tar){
    for(Node *p = node;p!=NULL;p=p->next)
        if(p->id == 0 && p->data == tar)return p;
    return NULL;
}

Node *find_bigger(Node *node, int tar){
    Node *best = NULL;
    for(Node *p = node; p != NULL; p = p->next){
        if(p->id == 0 && p->data > tar){
            if(best == NULL || p->data < best->data)
                best = p;
        }
    }
    return best;
}

void ins(Node *node, int tar, int Id){
    Node *insnode;
    insnode = find_exact(node,tar);
    if(insnode == NULL){
        insnode = find_bigger(node,tar);
        insnode = split(insnode,tar);
    }
    insnode->id = Id;
}

void print(Node *node){
    printf("%d ",node->id);
    if(node->next != NULL)
        print(node->next);
    else
        printf("\n");
}

int main(){
    int n, q;
    scanf("%d%d",&n,&q);
    Node *root = new(1<<n);
    while(q--){
        char order;
        scanf(" %c",&order);
        if(order == 'Q'){
            printf("%d\n",size);
            print(root);
        }
            
        if(order == 'A'){
            int Id,tar;
            scanf("%d%d",&Id,&tar);
            int Tar = 1;
            while(Tar < tar)
                Tar = Tar<<1;
            ins(root,Tar,Id);
        }
    }
    return 0;
}