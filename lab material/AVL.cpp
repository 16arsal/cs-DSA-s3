#include <iostream>
using namespace std;

struct Node {
    int key;
    Node *left;
    Node *right;
    int height;
};

// Function to create a new Node
Node* createNode(int key) {
    Node* newNode = new Node();
    newNode->key = key;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->height = 0; 
    return newNode;
}

// Function to get height of a Node
int getHeight(Node* node) {
    if (node == NULL)
        return 0;
    return node->height;
}

// Function to get the balance factor of a Node
int getBalance(Node* node) {
    if (node == NULL)
        return 0;
    return getHeight(node->left) - getHeight(node->right);
}

// Function to perform right rotation
Node* rightRotate(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;

    x->right = y;
    y->left = T2;

    // Update heights
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;

    return x;
}

// Function to perform left rotation
Node* leftRotate(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;

    y->left = x;
    x->right = T2;

    // Update heights
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

    return y;
}

// Function to insert a Node in the AVL tree
Node* insertNode(Node* root, int key) {
    // Perform standard BST insertion
    if (root == NULL)
        return createNode(key);

    if (key < root->key)
        root->left = insertNode(root->left, key);
    else if (key > root->key)
        root->right = insertNode(root->right, key);
    else // Duplicate keys are not allowed
        return root;

    // Update height of this ancestor node
    root->height = 1 + max(getHeight(root->left), getHeight(root->right));

    // Get the balance factor and balance the tree if needed
    int balance = getBalance(root);

    // Left Left Case
    if (balance > 1 && key < root->left->key)
        return rightRotate(root);

    // Right Right Case
    if (balance < -1 && key > root->right->key)
        return leftRotate(root);

    // Left Right Case
    if (balance > 1 && key > root->left->key) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // Right Left Case
    if (balance < -1 && key < root->right->key) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

// Function to perform  traversal of the tree
void Traversal(Node* root) {
    if (root != NULL) {
        Traversal(root->left);
        cout << root->key << " ";
        Traversal(root->right);
    }
}

int main() {
    Node* root = NULL;

    root = insertNode(root, 10);
    root = insertNode(root, 20);
    root = insertNode(root, 30);
    root = insertNode(root, 40);
    root = insertNode(root, 50);
    root = insertNode(root, 25);

    cout << " traversal of the AVL tree: ";
    Traversal(root);
    return 0;
}

