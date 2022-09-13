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


void printInorder(Node *root)
{
    if(root == NULL)
    {
        return;
    }
    printInorder(root->left);
    cout << root->val << " ";
    printInorder(root->right);
}

void printPreorder(Node *root)
{
    if(root == NULL)
    {
        return;
    }
    cout << root->val << " ";
    printPreorder(root->left);
    printPreorder(root->right);
}

void printPostorder(Node *root)
{
    if(root == NULL)
    {
        return;
    }
    printPostorder(root->left);
    printPostorder(root->right);
    cout << root->val << " ";
}

int main()
{
    Node *root = new Node(10);
    root->left = new Node(11);
    root->left->right = new Node(20);
    root->left->left = new Node(211);
    root->right = new Node(5);
    root->right->left = new Node(-321);

    // cout << endl;
    return(0);
}

