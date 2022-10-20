#include<bits/stdc++.h>
using namespace std;

class Node{
    private:
        long long int val;
        Node *left, *right;

    public:
        void setRight(Node* n){
            this->right = n;
        }

        Node* getRight(){
            return(this->right);
        }

        void setLeft(Node* n){
            this->left = n;
        }

        Node* getLeft(){
            return(this->left);
        }

        void setVal(long long int v){
            this->val = v;
        }

        long long int getVal(){
            return(this->val);
        }

        Node (){
            this->val = 0;
            this->left = NULL;
            this->right = NULL;
        }
        Node (long long int v){
            this->val = v;
            this->left = NULL;
            this->right = NULL;
        }
};

Node* newNode(long long int v){
    Node *n = new Node(v);
    return(n);
}

Node* newNode(){
    Node *n = new Node();
    return(n);
}

class BT{
    private:
        Node *root;
    public:
        Node* getRoot(){
            return(this->root);
        }

        void setRoot(Node* r){
            this->root = r;
        }

        void printInorder(Node* r){
            if(r == NULL){
                return;
            }
            printInorder(r->getLeft());
            cout << r->getVal() << " ";
            printInorder(r->getRight());
        }

        void printPreorder(Node *r){
            if(r == NULL){
                return;
            }
            cout << r->getVal() << " ";
            printPreorder(r->getLeft());
            printPreorder(r->getRight());
        }

        void printPostorder(Node *r){
            if(r == NULL){
                return;
            }
            printPostorder(r->getLeft());
            printPostorder(r->getRight());
            cout << r->getVal() << " ";
        }

        BT(){
            this->root = newNode();
        }

        BT(long long int v){
            this->root = newNode(v);
        }
};

int main(){
    BT *tree = new BT(10);
    
    tree->getRoot()->setLeft(newNode(11));
    tree->getRoot()->getLeft()->setRight(newNode(20));
    tree->getRoot()->getLeft()->setLeft(newNode(211));
    tree->getRoot()->setRight(newNode(5));
    tree->getRoot()->getRight()->setLeft(newNode(-321));

    tree->printInorder(tree->getRoot());
    cout << endl;
    tree->printPostorder(tree->getRoot());
    cout << endl;
    tree->printPreorder(tree->getRoot());
    cout << endl;
    return(0);
}

