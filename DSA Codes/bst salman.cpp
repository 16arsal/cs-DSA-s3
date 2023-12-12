#include <iostream>
using namespace std;

template <class Object>
class TreeNode 
{
public:
  Object *object;
  TreeNode *left;
  TreeNode *right;

  // Constructors
  TreeNode() : object(nullptr), left(nullptr), right(nullptr) {}
  TreeNode(Object *obj) : object(obj), left(nullptr), right(nullptr) {}

  // Getter and setter for object
  Object *getInfo() { return object; }
  void setInfo(Object *obj) { object = obj; }

  // Getter and setter for left child
  TreeNode *getLeft() { return left; }
  void setLeft(TreeNode *leftNode) { left = leftNode; }

  // Getter and setter for right child
  TreeNode *getRight() { return right; }
  void setRight(TreeNode *rightNode) { right = rightNode; }
};

template <class Object>
void insert(TreeNode<Object> *&root, Object *info) 
{
  // Create a new node to store the data.
  TreeNode<Object> *node = new TreeNode<Object>(info);

  // If the tree is empty, make the new node the root node.
  if (root == nullptr) 
  {
    root = node;
    return;
  }

  // Find the parent of the new node.
  TreeNode<Object> *current = root;
  TreeNode<Object> *parent = nullptr;
  while (current != nullptr) 
  {
    parent = current;
    if (*info == *(current->getInfo())) 
    {
      // The element already exists in the tree, so we don't insert it.
      delete node;
      return;
    } 
    else if (*info < *(current->getInfo()))
     {
      current = current->getLeft();
     } else 
    {
      current = current->getRight();
    }
  }

  // Insert the new node based on the comparison with the parent.
  if (*info < *(parent->getInfo())) {
    parent->setLeft(node);
  } else {
    parent->setRight(node);
  }
}

template <class Object>
void inorderTraversal(TreeNode<Object> *root)
{
  if (root != nullptr) {
    // Traverse the left subtree.
    inorderTraversal(root->getLeft());

    // Visit the current node.
    cout << *(root->getInfo()) << " ";

    // Traverse the right subtree.
    inorderTraversal(root->getRight());
  }
}

int main() {
  int x[] = {14, 15, 4, 9, 7, 18, 3, 5, 16, 4, 20, 17, 9, 14, 5, -1};
  TreeNode<int> *root = new TreeNode<int>(&x[0]);
  for (int i = 1; x[i] > 0; i++) {
    insert(root, &x[i]);
  }

  cout << "In-order traversal: ";
  inorderTraversal(root);
  cout << endl;

  return 0;
}
