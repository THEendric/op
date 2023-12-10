#include <iostream> 
  
class AVLNode { 
public: 
    int data; 
    AVLNode* left; 
    AVLNode* right; 
    int height; 
  
    AVLNode(int value) : data(value), left(nullptr), right(nullptr), height(1) {} 
}; 
  
class AVLTree { 
private: 
    AVLNode* root; 
  
    // Helper function to get the height of a node 
    int height(AVLNode* node) { 
        return (node != nullptr) ? node->height : 0; 
    } 
  
    // Helper function to update the height of a node 
    void updateHeight(AVLNode* node) { 
        if (node != nullptr) { 
            node->height = 1 + std::max(height(node->left), height(node->right)); 
        } 
    } 
  
    // Helper function to perform right rotation 
    AVLNode* rightRotate(AVLNode* y) { 
        AVLNode* x = y->left; 
        AVLNode* T2 = x->right; 
  
        x->right = y; 
        y->left = T2; 
  
        updateHeight(y); 
        updateHeight(x); 
  
        return x; 
    } 
  
    // Helper function to perform left rotation 
    AVLNode* leftRotate(AVLNode* x) { 
        AVLNode* y = x->right; 
        AVLNode* T2 = y->left; 
  
        y->left = x; 
        x->right = T2; 
  
        updateHeight(x); 
        updateHeight(y); 
  
        return y; 
    } 
  
    // Helper function to get the balance factor of a node 
    int balanceFactor(AVLNode* node) { 
        return (node != nullptr) ? height(node->left) - height(node->right) : 0; 
    } 
  
    // Helper function to insert a value into the AVL tree 
    AVLNode* insert(AVLNode* node, int value) { 
        if (node == nullptr) { 
            return new AVLNode(value); 
        } 
  
        if (value < node->data) { 
            node->left = insert(node->left, value); 
        } else if (value > node->data) { 
            node->right = insert(node->right, value); 
        } else { 
            // Duplicate values are not allowed 
            return node; 
        } 
  
        updateHeight(node); 
  
        int balance = balanceFactor(node); 
  
        // Left Left Case 
        if (balance > 1 && value < node->left->data) { 
            return rightRotate(node); 
        } 
  
        // Right Right Case 
        if (balance < -1 && value > node->right->data) { 
            return leftRotate(node); 
        } 
  
        // Left Right Case 
        if (balance > 1 && value > node->left->data) { 
            node->left = leftRotate(node->left); 
            return rightRotate(node); 
        } 
  
        // Right Left Case 
        if (balance < -1 && value < node->right->data) { 
            node->right = rightRotate(node->right); 
            return leftRotate(node); 
        } 
  
        return node; 
    } 
  
    // Helper function to search for a value in the AVL tree 
    bool search(AVLNode* node, int value) { 
        while (node != nullptr) { 
            if (value == node->data) { 
                return true; // Value found 
            } else if (value < node->data) { 
                node = node->left; 
            } else { 
                node = node->right; 
            } 
        } 
        return false; // Value not found 
    } 
  
public: 
    AVLTree() : root(nullptr) {} 
  
    // Public method to insert a value into the AVL tree 
    void insert(int value) { 
        root = insert(root, value); 
    } 
  
    // Public method to search for a value in the AVL tree 
    bool search(int value) { 
        return search(root, value); 
    } 
}; 
  
int main() { 
    AVLTree avl; 
  
    // Insert elements into the AVL tree 
    avl.insert(50); 
    avl.insert(30); 
    avl.insert(20); 
    avl.insert(40); 
    avl.insert(70); 
    avl.insert(60); 
    avl.insert(80); 
  
    // Search for values in the AVL tree 
    int searchValue = 40; 
    if (avl.search(searchValue)) { 
        std::cout << searchValue << " is found in the AVL tree." << std::endl; 
    } else { 
        std::cout << searchValue << " is not found in the AVL tree." << std::endl; 
    } 
  
    return 0; 
} 
