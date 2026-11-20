
#include <iostream>
using namespace std;

// BST Node
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

// Insert a node into BST
Node* insertBST(Node* root, int value)
{
    // Empty position found
    if (root == nullptr)
    {
        return createNode(value);
    }

    if (value < root->data)
    {
        root->left = insertBST(root->left, value);
    }
    else if (value > root->data)
    {
        root->right = insertBST(root->right, value);
    }

    return root;
}

// Find the smallest node in a subtree
Node* findMin(Node* root)
{
    while (root->left != nullptr)
    {
        root = root->left;
    }

    return root;
}

// Recursive BST deletion
Node* deleteBST(Node* root, int value)
{
    // Base case: empty tree or key not found
    if (root == nullptr)
    {
        return nullptr;
    }

    // Search in left subtree
    if (value < root->data)
    {
        root->left = deleteBST(root->left, value);
    }

    // Search in right subtree
    else if (value > root->data)
    {
        root->right = deleteBST(root->right, value);
    }

    // Node found
    else
    {
        // CASE 1: Node is a leaf
        if (root->left == nullptr &&
            root->right == nullptr)
        {
            delete root;
            return nullptr;
        }

        // CASE 2: Node has only right child
        else if (root->left == nullptr)
        {
            Node* temp = root->right;

            delete root;

            return temp;
        }

        // CASE 2: Node has only left child
        else if (root->right == nullptr)
        {
            Node* temp = root->left;

            delete root;

            return temp;
        }

        // CASE 3: Node has two children
        else
        {
            // Find inorder successor
            Node* successor = findMin(root->right);

            // Copy successor's value
            root->data = successor->data;

            // Delete original successor
            root->right = deleteBST(root->right,
                                    successor->data);
        }
    }

    return root;
}

// Inorder traversal
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

// Free all remaining nodes
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

// Main function
int main()
{
    Node* root = nullptr;

    // Insert required values
    int values[] = {50, 30, 70, 20, 40, 60, 80, 65};

    for (int i = 0; i < 8; i++)
    {
        root = insertBST(root, values[i]);
    }

    // Display initial tree
    cout << "Initial BST (Inorder): ";
    inorder(root);
    cout << endl << endl;

    // Delete 20 - Case 1: Leaf
    cout << "Deleting 20 (Leaf Node)" << endl;

    root = deleteBST(root, 20);

    cout << "Inorder: ";
    inorder(root);
    cout << endl << endl;

    // Delete 60 - Case 2: One Child
    cout << "Deleting 60 (One Child)" << endl;

    root = deleteBST(root, 60);

    cout << "Inorder: ";
    inorder(root);
    cout << endl << endl;

    // Delete 50 - Case 3: Two Children
    cout << "Deleting 50 (Two Children)" << endl;

    root = deleteBST(root, 50);

    cout << "Inorder: ";
    inorder(root);
    cout << endl << endl;

    // Test deleting a missing key
    cout << "Deleting missing key 100" << endl;

    root = deleteBST(root, 100);

    cout << "Inorder: ";
    inorder(root);
    cout << endl << endl;

    // Test deletion from an empty tree
    cout << "Deleting from an empty tree:" << endl;

    Node* empty = nullptr;
    empty = deleteBST(empty, 50);

    if (empty == nullptr)
    {
        cout << "Tree is still empty." << endl;
    }

    // Test deleting the only node
    cout << endl << "Deleting the only node:" << endl;

    Node* single = nullptr;

    single = insertBST(single, 10);

    single = deleteBST(single, 10);

    if (single == nullptr)
    {
        cout << "Only node deleted. Root is nullptr." << endl;
    }

    // Free remaining memory
    deleteTree(root);

    return 0;
}
