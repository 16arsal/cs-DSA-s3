//MUHAMMAD ARSAL
//2022350
//Lab Tasks
//AVL Trees
#include<iostream>
using namespace std;

class AVLTree {
public:
    struct TreeNode {
        int value;
        TreeNode* left;
        TreeNode* right;
        int height;
    };

    AVLTree() : root(nullptr) {}

    int getHeight(TreeNode* node) {
        return (node == nullptr) ? -1 : node->height;
    }

    int max(int a, int b) {
        return (a > b) ? a : b;
    }

    TreeNode* newNode(int value) {
        TreeNode* node = new TreeNode();
        node->value = value;
        node->left = nullptr;
        node->right = nullptr;
        node->height = 0;
        return node;
    }

    TreeNode* rightRotate(TreeNode* y) {
        TreeNode* x = y->left;
        TreeNode* T2 = x->right;

        x->right = y;
        y->left = T2;

        y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
        x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
        return x;
    }

    TreeNode* leftRotate(TreeNode* x) {
        TreeNode* y = x->right;
        TreeNode* T2 = y->left;

        y->left = x;
        x->right = T2;

        x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
        y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

        return y;
    }

    int getBalance(TreeNode* N) {
        return (N == nullptr) ? 0 : getHeight(N->left) - getHeight(N->right);
    }

    TreeNode* minValueNode(TreeNode* node) {
        TreeNode* current = node;
        while (current->left != nullptr)
            current = current->left;
        return current;
    }

    TreeNode* insert(TreeNode* node, int value) {
        if (node == nullptr)
            return newNode(value);

        if (value < node->value)
            node->left = insert(node->left, value);
        else if (value > node->value)
            node->right = insert(node->right, value);
        else {
            cout << "Duplicate data not allowed" << endl;
            return node;
        }

        node->height = 1 + max(getHeight(node->left), getHeight(node->right));

        int balance = getBalance(node);

        if (balance > 1 && value < node->left->value)
            return rightRotate(node);

        if (balance < -1 && value > node->right->value)
            return leftRotate(node);

        if (balance > 1 && value > node->left->value) {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }

        if (balance < -1 && value < node->right->value) {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        return node;
    }

    void preOrder(TreeNode* node) {
        if (node != nullptr) {
            cout << node->value << " ";
            preOrder(node->left);
            preOrder(node->right);
        }
    }

    TreeNode* deleteNode(TreeNode* node, int value) {
        if (node == nullptr) {
            cout << "Data not found" << endl;
            return node;
        }

        if (value < node->value)
            node->left = deleteNode(node->left, value);
        else if (value > node->value)
            node->right = deleteNode(node->right, value);
        else {
            if ((node->left == nullptr)) {
                TreeNode* temp = node;
                node = node->right;
                delete temp;
            } else if (node->right == nullptr) {
                TreeNode* temp = node;
                node = node->left;
                delete temp;
            } else {
                TreeNode* temp = minValueNode(node->right);
                node->value = temp->value;
                node->right = deleteNode(node->right, temp->value);
            }
        }

        if (node == nullptr)
            return node;

        node->height = 1 + max(getHeight(node->left), getHeight(node->right));

        int balance = getBalance(node);

        if (balance > 1 && value < node->left->value)
            return rightRotate(node);

        if (balance < -1 && value > node->right->value)
            return leftRotate(node);

        if (balance > 1 && value > node->left->value) {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }

        if (balance < -1 && value < node->right->value) {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        return node;
    }

    void menu() {
        int choice;
        while (true) {
            cout << "1. Insert" << endl;
            cout << "2. Delete" << endl;
            cout << "3. Preorder" << endl;
            cout << "4. Exit" << endl;
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice) {
                case 1: {
                    int value;
                    cout << "Enter value: ";
                    cin >> value;
                    root = insert(root, value);
                    break;
                }
                case 2: {
                    int value;
                    cout << "Enter value to delete: ";
                    cin >> value;
                    root = deleteNode(root, value);
                    break;
                }
                case 3:
                    preOrder(root);
                    cout << endl;
                    break;
                case 4:
                    return;
                default:
                    cout << "Invalid choice" << endl;
            }
        }
    }

private:
    TreeNode* root;
};

int main() {
    AVLTree avlTree;
    avlTree.menu();
    return 0;
}
