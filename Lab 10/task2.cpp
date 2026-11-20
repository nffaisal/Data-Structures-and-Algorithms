
#include <iostream>
#include <algorithm>
using namespace std;

// AVL Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
    int height;
};

// Create a new node
Node* createNode(int value)
{
    Node* newNode = new Node;

    newNode->data = value;
    newNode->left = nullptr;
    newNode->right = nullptr;
    newNode->height = 1;

    return newNode;
}

// Get height of a node
int getHeight(Node* root)
{
    if (root == nullptr)
    {
        return 0;
    }

    return root->height;
}

// Calculate balance factor
int getBalance(Node* root)
{
    if (root == nullptr)
    {
        return 0;
    }

    return getHeight(root->left) -
           getHeight(root->right);
}

// Update height of a node
void updateHeight(Node* root)
{
    root->height = 1 + max(getHeight(root->left),
                           getHeight(root->right));
}

// Right Rotation (LL Case)
Node* rightRotate(Node* root)
{
    Node* newRoot = root->left;
    Node* temp = newRoot->right;

    // Perform rotation
    newRoot->right = root;
    root->left = temp;

    // Update heights
    updateHeight(root);
    updateHeight(newRoot);

    return newRoot;
}

// Left Rotation (RR Case)
Node* leftRotate(Node* root)
{
    Node* newRoot = root->right;
    Node* temp = newRoot->left;

    // Perform rotation
    newRoot->left = root;
    root->right = temp;

    // Update heights
    updateHeight(root);
    updateHeight(newRoot);

    return newRoot;
}

// AVL Insertion
Node* insertAVL(Node* root, int value)
{
    // Step 1: Normal BST insertion
    if (root == nullptr)
    {
        return createNode(value);
    }

    if (value < root->data)
    {
        root->left = insertAVL(root->left, value);
    }
    else if (value > root->data)
    {
        root->right = insertAVL(root->right, value);
    }
    else
    {
        // Duplicate values are not inserted
        return root;
    }

    // Step 2: Update height
    updateHeight(root);

    // Step 3: Calculate balance factor
    int balance = getBalance(root);

    // Step 4: Check four imbalance cases

    // LL Case
    if (balance > 1 && value < root->left->data)
    {
        return rightRotate(root);
    }

    // RR Case
    if (balance < -1 && value > root->right->data)
    {
        return leftRotate(root);
    }

    // LR Case
    if (balance > 1 && value > root->left->data)
    {
        root->left = leftRotate(root->left);

        return rightRotate(root);
    }

    // RL Case
    if (balance < -1 && value < root->right->data)
    {
        root->right = rightRotate(root->right);

        return leftRotate(root);
    }

    // Tree is already balanced
    return root;
}

// Inorder Traversal
void inorder(Node* root)
{
    if (root == nullptr)
    {
        return;
    }

    inorder(root->left);

    cout << root->data << " ";

    inorder(root->right);
}

// Preorder Traversal
void preorder(Node* root)
{
    if (root == nullptr)
    {
        return;
    }

    cout << root->data << " ";

    preorder(root->left);

    preorder(root->right);
}

// Verify balance factor of every node
bool verifyBalance(Node* root)
{
    if (root == nullptr)
    {
        return true;
    }

    int balance = getBalance(root);

    cout << "Node: " << root->data
         << " | Height: " << root->height
         << " | Balance Factor: " << balance
         << endl;

    // Check if current node is balanced
    if (balance < -1 || balance > 1)
    {
        return false;
    }

    // Check left and right subtrees
    return verifyBalance(root->left) &&
           verifyBalance(root->right);
}

// Delete entire tree to free memory
void deleteTree(Node* root)
{
    if (root == nullptr)
    {
        return;
    }

    deleteTree(root->left);
    deleteTree(root->right);

    delete root;
}

// Function to test one insertion sequence
void testSequence(int values[], int size, char name)
{
    // Every sequence gets a separate empty tree
    Node* root = nullptr;

    cout << "\n================================" << endl;
    cout << "Sequence " << name << endl;
    cout << "================================" << endl;

    // Insert values
    for (int i = 0; i < size; i++)
    {
        root = insertAVL(root, values[i]);
    }

    // Display preorder
    cout << "\nPreorder Traversal: ";
    preorder(root);

    // Display inorder
    cout << "\nInorder Traversal: ";
    inorder(root);

    cout << "\n\nBalance Verification:" << endl;

    // Verify all nodes
    if (verifyBalance(root))
    {
        cout << "All nodes are balanced." << endl;
    }
    else
    {
        cout << "Tree is not balanced." << endl;
    }

    // Free memory
    deleteTree(root);
}

// Main function
int main()
{
    // A: LL Case
    int A[] = {30, 20, 10};

    // B: RR Case
    int B[] = {10, 20, 30};

    // C: LR Case
    int C[] = {30, 10, 20};

    // D: RL Case
    int D[] = {10, 30, 20};

    // Test all four sequences
    testSequence(A, 3, 'A');

    testSequence(B, 3, 'B');

    testSequence(C, 3, 'C');

    testSequence(D, 3, 'D');

    return 0;
}
