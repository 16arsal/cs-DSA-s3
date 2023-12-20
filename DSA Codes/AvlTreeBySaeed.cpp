#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node* left;
    Node* right;
    int height;
};

int height(Node* node){
    if(node == NULL){
        return -1;
    }
    return node->height;
}

int max(int a, int b) 
{
    if (a > b) {
        return a;
    } 
    else {
        return b;
    }
}

Node* newNode(int data)  
{  
    Node* node = new Node(); 
    node->data = data;  
    node->left = NULL;
    node->right = NULL;
    node->height = 0;
    return(node);  
}  

Node* rightRotate(Node* y){
    Node* x = y->left;  
    Node* T2 = x->right;

    x->right = y;  
    y->left = T2;  
   
    y->height = max(height(y->left), height(y->right)) + 1;  
    x->height = max(height(x->left), height(x->right)) + 1;   
    return x;  
}

Node* leftRotate(Node* x){  
    Node* y = x->right;  
    Node* T2 = y->left;  
  
    y->left = x;  
    x->right = T2;  
  
    x->height = max(height(x->left), height(x->right)) + 1;  
    y->height = max(height(y->left), height(y->right)) + 1;  
  
    return y;  
}

int getBalance(Node *N){  
    if (N == NULL)  
        return 0;  
    return height(N->left) - height(N->right);  
}

Node * minValueNode(Node* node) 
{ 
    Node* current = node; 
    while (current->left != NULL) 
        current = current->left; 
    return current; 
} 

Node* insert(Node* node, int data){
    if(node==NULL){
        return newNode(data);
    }
    if(data < node->data){
        node->left = insert(node->left, data);
    }
    else if(data > node->data){
        node->right = insert(node->right, data);
    }
    else{
        cout<<"Duplicate data not allowed"<<endl;
        return node;
    }
    node->height = 1 + max(height(node->left), height(node->right));
    int balance = getBalance(node);
    // Left Left Case  
    if (balance > 1 && data < node->left->data)
            return rightRotate(node);
    // Right Right Case  
    if (balance < -1 && data > node->right->data)  
        return leftRotate(node);  
    // Left Right Case  
    if (balance > 1 && data > node->left->data){  
        node->left = leftRotate(node->left);  
        return rightRotate(node);  
    }
    // Right Left Case  
    if (balance < -1 && data < node->right->data){  
        node->right = rightRotate(node->right);  
        return leftRotate(node);  
    }
    return node;
}

void preOrder(Node *node)  
{  
    if(node != NULL)  
    {  
        cout << node->data << " ";  
        preOrder(node->left);  
        preOrder(node->right);  
    }  
}

// modified subtree. 
Node* deleteNode(Node* node, int data){
    if (node == NULL){
        cout<<"Data not found"<<endl;
        return node;
    }
    if ( data < node->data ) 
        node->left = deleteNode(node->left, data); 
    else if( data > node->data ) 
        node->right = deleteNode(node->right, data); 
    else
    {
        if((node->left == NULL)){ 
            Node *temp = node;
            node=node->right;
            delete temp;
        }
        else if(node->right==NULL){
            Node *temp = node;
            node=node->left;
            delete temp;
        }
        else{
            Node* temp = minValueNode(node->right);
            node->data = temp->data; 
            node->right = deleteNode(node->right, temp->data); 
        } 
    }
    if (node == NULL) 
        return node;
    node->height = 1 + max(height(node->left), height(node->right)); 
    int balance = getBalance(node);
    // Left Left Case  
    if (balance > 1 && data < node->left->data)
            return rightRotate(node);
    // Right Right Case  
    if (balance < -1 && data > node->right->data)  
        return leftRotate(node);  
    // Left Right Case  
    if (balance > 1 && data > node->left->data){  
        node->left = leftRotate(node->left);  
        return rightRotate(node);  
    }
    // Right Left Case  
    if (balance < -1 && data < node->right->data){  
        node->right = rightRotate(node->right);  
        return leftRotate(node);  
    }
    return node;
}

int main(){
    Node* root = NULL;
    int choice;
    while(true){
        cout<<"1. Insert"<<endl;
        cout<<"2. Delete"<<endl;
        cout<<"3. Preorder"<<endl;
        cout<<"4. Exit"<<endl;
        cout<<"Enter your choice: ";
        cin>>choice;
        switch(choice){
            case 1:
                int data;
                cout<<"Enter data: ";
                cin>>data;
                root = insert(root, data);
                break;
            case 2:
                int del;
                cout<<"Enter data to delete: ";
                cin>>del;
                root = deleteNode(root, del);
                break;
            case 3:
                preOrder(root);
                cout<<endl;
                break;
            case 4:
                return 0;
            default:
                cout<<"Invalid choice"<<endl;
        }
    }
}