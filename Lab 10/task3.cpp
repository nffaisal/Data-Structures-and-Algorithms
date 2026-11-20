
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    int height;
};

// Create a new node
Node* createNode(int value) {
    Node* newNode = new Node;

    newNode->data = value;
    newNode->left = nullptr;
    newNode->right = nullptr;
    newNode->height = 1;

    return newNode;
}

// Return height of a node
int getHeight(Node* root) {
    if (root == nullptr)
        return 0;

    return root->height;
}

// Calculate balance factor
int getBalance(Node* root) {
    if (root == nullptr)
        return 0;

    return getHeight(root->left) - getHeight(root->right);
}

// Update height of a node
void updateHeight(Node* root) {
    if (root != nullptr) {
        int leftHeight = getHeight(root->left);
        int rightHeight = getHeight(root->right);

        root->height = 1 + max(leftHeight, rightHeight);
    }
}

// Right rotation (LL case)
Node* rightRotate(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;

    // Perform rotation
    x->right = y;
    y->left = T2;

    // Update heights
    updateHeight(y);
    updateHeight(x);

    return x;
}

// Left rotation (RR case)
Node* leftRotate(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;

    // Perform rotation
    y->left = x;
    x->right = T2;

    // Update heights
    updateHeight(x);
    updateHeight(y);

    return y;
}

// Rebalance a node after insertion or deletion
Node* rebalance(Node* root) {
    if (root == nullptr)
        return nullptr;

    updateHeight(root);

    int balance = getBalance(root);

    // Left-heavy subtree
    if (balance > 1) {

        // LL case: single right rotation
        if (getBalance(root->left) >= 0) {
            return rightRotate(root);
        }

        // LR case: left rotation, then right rotation
        else {
            root->left = leftRotate(root->left);
            return rightRotate(root);
        }
    }

    // Right-heavy subtree
    if (balance < -1) {

        // RR case: single left rotation
        if (getBalance(root->right) <= 0) {
            return leftRotate(root);
        }

        // RL case: right rotation, then left rotation
        else {
            root->right = rightRotate(root->right);
            return leftRotate(root);
        }
    }

    return root;
}

// AVL INSERTION
Node* insertAVL(Node* root, int value) {

    // Normal BST insertion
    if (root == nullptr)
        return createNode(value);

    if (value < root->data) {
        root->left = insertAVL(root->left, value);
    }
    else if (value > root->data) {
        root->right = insertAVL(root->right, value);
    }
    else {
        return root; // Ignore duplicates
    }

    // Update height and rebalance
    return rebalance(root);
}

// Find minimum node in a subtree
Node* findMin(Node* root) {
    Node* current = root;

    while (current != nullptr && current->left != nullptr) {
        current = current->left;
    }

    return current;
}

// AVL DELETION
Node* deleteAVL(Node* root, int value) {

    // Value not found
    if (root == nullptr)
        return nullptr;

    // Search in left subtree
    if (value < root->data) {
        root->left = deleteAVL(root->left, value);
    }

    // Search in right subtree
    else if (value > root->data) {
        root->right = deleteAVL(root->right, value);
    }

    // Node found
    else {

        // Case 1: No children (leaf node)
        if (root->left == nullptr && root->right == nullptr) {
            delete root;
            return nullptr;
        }

        // Case 2: Only right child
        else if (root->left == nullptr) {
            Node* temp = root->right;
            delete root;
            return temp;
        }

        // Case 2: Only left child
        else if (root->right == nullptr) {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        // Case 3: Two children
        else {
            // Find inorder successor
            Node* successor = findMin(root->right);

            // Copy successor's value
            root->data = successor->data;

            // Delete successor from right subtree
            root->right = deleteAVL(root->right, successor->data);
        }
    }

    // Rebalance every ancestor while recursion returns
    return rebalance(root);
}

// Inorder traversal: Left, Root, Right
void inorder(Node* root) {
    if (root == nullptr)
        return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// Preorder traversal: Root, Left, Right
void preorder(Node* root) {
    if (root == nullptr)
        return;

    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

// Display height and balance factor of every node
void displayBalance(Node* root) {
    if (root == nullptr)
        return;

    cout << "Node: " << root->data
         << " | Height: " << root->height
         << " | Balance Factor: " << getBalance(root)
         << endl;

    displayBalance(root->left);
    displayBalance(root->right);
}

// Verify that every node satisfies AVL balance condition
bool verifyBalance(Node* root) {
    if (root == nullptr)
        return true;

    int balance = getBalance(root);

    if (balance < -1 || balance > 1)
        return false;

    return verifyBalance(root->left) &&
           verifyBalance(root->right);
}

// Display all tree information
void displayTree(Node* root) {
    cout << "\nPreorder: ";
    preorder(root);

    cout << "\nInorder: ";
    inorder(root);

    cout << "\n\nNode Heights and Balance Factors:\n";
    displayBalance(root);

    cout << "\nAVL Valid: ";

    if (verifyBalance(root))
        cout << "YES\n";
    else
        cout << "NO\n";

    cout << "----------------------------------\n";
}

// Free allocated memory
void deleteTree(Node* root) {
    if (root == nullptr)
        return;

    deleteTree(root->left);
    deleteTree(root->right);

    delete root;
}

// Test insertion and deletion sequence
void testSequence() {
    Node* root = nullptr;

    int values[] = {30, 20, 40, 10, 25, 50, 5};

    cout << "\n========== MAIN TEST ==========\n";

    // Insert values
    for (int i = 0; i < 7; i++) {
        root = insertAVL(root, values[i]);
    }

    cout << "\nInitial AVL Tree:";
    displayTree(root);

    // Delete 50
    cout << "\nDeleting 50...";
    root = deleteAVL(root, 50);
    displayTree(root);

    // Delete 40
    cout << "\nDeleting 40...";
    root = deleteAVL(root, 40);
    displayTree(root);

    // Delete a value that does not exist
    cout << "\nDeleting missing value 100...";
    root = deleteAVL(root, 100);
    displayTree(root);

    deleteTree(root);
}

// Test empty tree
void testEmptyTree() {
    cout << "\n========== EMPTY TREE TEST ==========\n";

    Node* root = nullptr;

    root = deleteAVL(root, 10);

    displayTree(root);

    deleteTree(root);
}

// Test deletion of only node
void testSingleNode() {
    cout << "\n========== SINGLE NODE TEST ==========\n";

    Node* root = nullptr;

    root = insertAVL(root, 10);

    cout << "\nBefore deletion:";
    displayTree(root);

    root = deleteAVL(root, 10);

    cout << "\nAfter deletion:";
    displayTree(root);

    deleteTree(root);
}

// Test heavy child with balance factor 0
void testZeroBalanceChild() {
    cout << "\n========== BF ZERO TEST ==========\n";

    Node* root = nullptr;

    int values[] = {4, 2, 6, 1, 3};

    for (int i = 0; i < 5; i++) {
        root = insertAVL(root, values[i]);
    }

    cout << "\nBefore deleting 6:";
    displayTree(root);

    root = deleteAVL(root, 6);

    cout << "\nAfter deleting 6:";
    displayTree(root);

    deleteTree(root);
}

// Main function
int main() {

    testSequence();

    testEmptyTree();

    testSingleNode();

    testZeroBalanceChild();

    return 0;
}
