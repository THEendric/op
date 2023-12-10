#include <iostream> 
  
class TreeNode { 
public: 
    int data; 
    TreeNode* left; 
    TreeNode* right; 
  
    TreeNode(int value) : data(value), left(nullptr), right(nullptr) {} 
}; 
  
class BinarySearchTree { 
private: 
    TreeNode* root; 
  
    // Helper function to insert a value into the BST 
    TreeNode* insert(TreeNode* node, int value) { 
        if (node == nullptr) { 
            return new TreeNode(value); 
        } 
  
        if (value < node->data) { 
            node->left = insert(node->left, value); 
        } else if (value > node->data) { 
            node->right = insert(node->right, value); 
        } 
  
        return node; 
    } 
  
    // Helper function to search for a value in the BST 
    bool search(TreeNode* node, int value) { 
        if (node == nullptr) { 
            return false; // Value not found 
        } 
  
        if (value == node->data) { 
            return true; // Value found 
        } else if (value < node->data) { 
            return search(node->left, value); 
        } else { 
            return search(node->right, value); 
        } 
    } 
  
    // Helper functions for tree traversals 
    void preorderTraversal(TreeNode* node) { 
        if (node != nullptr) { 
            std::cout << node->data << " "; 
            preorderTraversal(node->left); 
            preorderTraversal(node->right); 
        } 
    } 
  
    void inorderTraversal(TreeNode* node) { 
        if (node != nullptr) { 
            inorderTraversal(node->left); 
            std::cout << node->data << " "; 
            inorderTraversal(node->right); 
        } 
    } 
  
    void postorderTraversal(TreeNode* node) { 
        if (node != nullptr) { 
            postorderTraversal(node->left); 
            postorderTraversal(node->right); 
            std::cout << node->data << " "; 
        } 
    } 
  
public: 
    BinarySearchTree() : root(nullptr) {} 
  
    // Public method to insert a value into the BST 
    void insert(int value) { 
        root = insert(root, value); 
    } 
  
    // Public method to search for a value in the BST 
    bool search(int value) { 
        return search(root, value); 
    } 
  
    // Public methods to display elements in preorder, inorder, and postorder 
    // traversal 
    void displayPreorder() { 
        std::cout << "Preorder Traversal: "; 
        preorderTraversal(root); 
        std::cout << std::endl; 
    } 
  
    void displayInorder() { 
        std::cout << "Inorder Traversal: "; 
        inorderTraversal(root); 
        std::cout << std::endl; 
    } 
  
    void displayPostorder() { 
        std::cout << "Postorder Traversal: "; 
        postorderTraversal(root); 
        std::cout << std::endl; 
    } 
}; 
  
int main() { 
    BinarySearchTree bst; 
  
    // Insert elements into the BST 
    bst.insert(50); 
    bst.insert(30); 
    bst.insert(20); 
    bst.insert(40); 
    bst.insert(70); 
    bst.insert(60); 
    bst.insert(80); 
  
    // Display the BST in different traversals 
    bst.displayPreorder(); 
    bst.displayInorder(); 
    bst.displayPostorder(); 
  
    // Search for an element in the BST 
    int searchValue = 40; 
    if (bst.search(searchValue)) { 
        std::cout << searchValue << " is found in the BST." << std::endl; 
    } else { 
        std::cout << searchValue << " is not found in the BST." << std::endl; 
    } 
  
    return 0; 
} 
