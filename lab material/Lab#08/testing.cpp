#include <iostream>
using namespace std;

//node structure for bst

struct Node
{
    int data;
    Node *left;
    Node *right;
};

//function to create a new node

Node * createnode(int value)
{
    Node *newnode= new Node();
    newnode->data=value;
    newnode->left=nullptr;
    newnode->right=nullptr;
}

//function to insert a new node into bst
Node * insertinBST(int value, Node * root)
{
    if (root == nullptr)
    {
        cout<<"root is null hence itself could be added"<<endl;
        return createnode(value);
    }
    else if (value<root->data)
    {
        root->left=insertinBST(value,root->left);
    }
    else if (value>root->data)
    {
        root->right=insertinBST(value,root->right);
    }
    else
    {
        cout<<"duplicate value "<<value<<" ignored"<<endl;
    }

    return root;
    
}

void inOrderTraversal(Node * root)
{
    if (root!=nullptr)
    {
        inOrderTraversal(root->left);
        cout<<root->data<<" ";
        inOrderTraversal(root->right);
    }
    

}
int main()
{
    Node * root=nullptr;
    root=insertinBST(40,root);
    insertinBST(50,root);
}