#include <iostream>
using namespace std;

// Define the structure of a node in the BST
struct Node {
    int data;
    Node* left;
    Node* right;
    
    Node(int value) {
        data = value;
        left = NULL;
        right = NULL;
    }
};

// Function to search for a value in the BST
Node* searchBST(Node* root, int value) {
	//Base case
    // If the tree is empty 
    // or if the value does not exist in the tree
    if (root == NULL ){
    	return NULL;
	}
// the value is found at the root
	if( root->data == value) {
        return root;
    }
    
    // Recursively search left or right subtrees based on the value
    if (value < root->data) {
        return searchBST(root->left, value);
    } else {
        return searchBST(root->right, value);
    }
}

// Function to insert a new node into the BST
Node* insert(Node* root, int value) {
    if (root == NULL) {
        return new Node(value);
    }

    if (value < root->data) {
        root->left = insert(root->left, value);
    } else if (value > root->data) {
        root->right = insert(root->right, value);
    }
    
    return root;
}

// Function to create a sample BST
Node* createBST() {
    Node* root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);
    return root;
}

int main() {
    Node* root = createBST();

    int valueToFind = 40;
    Node* result = searchBST(root, valueToFind);

    if (result != NULL) {
        cout << "Value " << valueToFind << " is found in the BST." << endl;
    } else {
        cout << "Value " << valueToFind << " is not found in the BST." << endl;
    }

    return 0;
}

