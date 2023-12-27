#include <iostream>

struct Node {
    int data;
    Node* left;
    Node* right;
};

// Function to create a new node
Node* createNode(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to find the minimum value node in a BST
Node* findMin(Node* root) {
    while (root->left != NULL) {
        root = root->left;
    }
    return root;
}

// Function to delete a node in a BST
Node* deleteNode(Node* root, int key) {
    if (root == NULL) {
        return root;
    }

    if (key < root->data) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->data) {
        root->right = deleteNode(root->right, key);
    } else {
    	 // Case 1: Node with no child
    	if (root->left == NULL && root->right == NULL) {    
            delete root;
            return NULL;}
        // Case 2: Node with only one child 
        else if (root->left == NULL) {
        	// Node with only right child
            Node* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == NULL) {
        	// Node with only left child
            Node* temp = root->left;
            delete root;
            return temp;
        }

        // Case 2:  function to find the minimum value node in the right subtree
		//Node with two children 
        Node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

// Function to perform in-order traversal of BST
void inOrderTraversal(Node* root) {
    if (root != NULL) {
        inOrderTraversal(root->left);
        std::cout << root->data << " ";
        inOrderTraversal(root->right);
    }
}

int main() {
    Node* root = NULL;

    // Sample insertions
    root = createNode(50);
    root->left = createNode(30);
    root->right = createNode(70);
    root->left->left = createNode(20);
    root->left->right = createNode(40);
    root->right->right = createNode(80);

    std::cout << "BST before deletion: ";
    inOrderTraversal(root);
    std::cout << std::endl;

    // Deleting a node
    int keyToDelete = 20;
    root = deleteNode(root, keyToDelete);

    std::cout << "BST after deleting " << keyToDelete << ": ";
    inOrderTraversal(root);
    std::cout << std::endl;

    return 0;
}

