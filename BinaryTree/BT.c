#include<stdio.h>
#include<stdlib.h>

struct Node{
    long long int val;
    struct Node *left, *right;
};

struct Node* newNode(long long int v){
    struct Node* n = (struct Node*)malloc(sizeof(struct Node));
    n->val = v;
    n->left = NULL;
    n->right = NULL;
    return(n);
}

struct BT{
    struct Node* root;
};

void printInorder(struct Node* r){
    if(r == NULL){
        return;
    }
    printInorder(r->left);
    printf("%lld ", r->val);
    printInorder(r->right);
}

void printPreorder(struct Node* r){
    if(r == NULL){
        return;
    }
    printf("%lld ", r->val);
    printPreorder(r->left);
    printPreorder(r->right);
}

void printPostorder(struct Node* r){
    if(r == NULL){
        return;
    }
    printPostorder(r->left);
    printPostorder(r->right);
    printf("%lld ", r->val);
}

struct BT* newBT(long long int v){
    struct BT* b = (struct BT*)malloc(sizeof(struct BT));
    struct Node* n = newNode(v);
    b->root = n;
    return(b);
}

int main(){
    struct BT *tree = newBT(10);
    
    tree->root->left = newNode(11);
    tree->root->left->right = newNode(20);
    tree->root->left->left = newNode(211);
    tree->root->right = newNode(5);
    tree->root->right->left = newNode(-321);

    printInorder(tree->root);
    printf("\n");
    printPostorder(tree->root);
    printf("\n");
    printPreorder(tree->root);
    printf("\n");
}
