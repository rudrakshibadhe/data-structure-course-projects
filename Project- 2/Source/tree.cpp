#include <iostream>
#include <algorithm>
using namespace std;

struct Node
{
    int data;
    int height;
    Node* left;
    Node* right;

    Node(int value)
    {
        data = value;
        height = 1;
        left = NULL;
        right = NULL;
    }
};

int height(Node* node)
{
    if (node == NULL)
        return 0;

    return node->height;
}

int getBalance(Node* node)
{
    if (node == NULL)
        return 0;

    return height(node->left) - height(node->right);
}

// Right rotation for LL case
Node* rightRotate(Node* y)
{
    Node* x = y->left;
    Node* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = 1 + max(height(y->left),
                        height(y->right));

    x->height = 1 + max(height(x->left),
                        height(x->right));

    return x;
}

Node* insert(Node* root, int value)
{
    // Normal BST insertion
    if (root == NULL)
        return new Node(value);

    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);
    else
        return root;

    // Update height
    root->height = 1 + max(height(root->left),
                           height(root->right));

    // Calculate balance factor
    int balance = getBalance(root);

    // LL imbalance
    if (balance > 1 && value < root->left->data)
    {
        cout << "LL imbalance detected at node "
             << root->data << endl;

        cout << "Performing right rotation..." << endl;

        return rightRotate(root);
    }

    return root;
}

void inorder(Node* root)
{
    if (root != NULL)
    {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

// Display tree sideways
void displayTree(Node* root, int space = 0)
{
    if (root == NULL)
        return;

    space = space + 5;

    displayTree(root->right, space);

    cout << endl;

    for (int i = 5; i < space; i++)
        cout << " ";

    cout << root->data << endl;

    displayTree(root->left, space);
}

int main()
{
    Node* root = NULL;

    int elements[3] = {30, 20, 10};

    cout << "===== AVL TREE: LL ROTATION ====="
         << endl;

    for (int i = 0; i < 3; i++)
    {
        cout << "\nInserting: " << elements[i]
             << endl;

        root = insert(root, elements[i]);
    }

    cout << "\nBalanced AVL Tree:" << endl;
    displayTree(root);

    cout << "\nInorder Traversal: ";
    inorder(root);

    cout << "\n\nRoot Node: " << root->data;

    cout << "\nBalance Factor of Root: "
         << getBalance(root) << endl;

    return 0;
}
