#include<bits/stdc++.h>
using namespace std;

class Node
{
    public:
        long long int val;
        Node *left, *right;

        Node ()
        {
            this->val = 0;
            this->left = NULL;
            this->right = NULL;
        }
        Node (long long int v)
        {
            this->val = v;
            this->left = NULL;
            this->right = NULL;
        }
};

Node* newNode(long long int v)
{
    Node *n = new Node(v);
    return(n);
}

Node* newNode()
{
    Node *n = new Node();
    return(n);
}

class BT
{
    public:
        Node *root;

        void printInorder(Node* r)
        {
            if(r == NULL)
            {
                return;
            }
            printInorder(r->left);
            cout << r->val << " ";
            printInorder(r->right);
        }

        void printPreorder(Node *r)
        {
            if(r == NULL)
            {
                return;
            }
            cout << r->val << " ";
            printPreorder(r->left);
            printPreorder(r->right);
        }

        void printPostorder(Node *r)
        {
            if(r == NULL)
            {
                return;
            }
            printPostorder(r->left);
            printPostorder(r->right);
            cout << r->val << " ";
        }

        BT()
        {
            root = newNode();
        }

        BT(long long int v)
        {
            root = newNode(v);
        }
};

int main()
{
    BT *tree = new BT(10);
    
    tree->root->left = newNode(11);
    tree->root->left->right = newNode(20);
    tree->root->left->left = newNode(211);
    tree->root->right = newNode(5);
    tree->root->right->left = newNode(-321);

    tree->printInorder(tree->root);
    cout << endl;
    tree->printPostorder(tree->root);
    cout << endl;
    tree->printPreorder(tree->root);
    cout << endl;
    return(0);
}

