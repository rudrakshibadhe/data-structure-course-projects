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

// Display tree sideways
void displayTree(Node* root, int space = 0)
{
    if (root == NULL)
        return;

    space += 5;

    displayTree(root->right, space);

    cout << endl;
    for (int i = 5; i < space; i++)
        cout << " ";

    cout << root->data << endl;

    displayTree(root->left, space);
}

// Display balance factors of all nodes
void displayBalanceFactors(Node* root)
{
    if (root == NULL)
        return;

    cout << "Node " << root->data
         << " : Balance Factor = "
         << getBalance(root) << endl;

    displayBalanceFactors(root->left);
    displayBalanceFactors(root->right);
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
    if (root == NULL)
        return new Node(value);

    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);
    else
        return root;

    root->height = 1 + max(height(root->left),
                           height(root->right));

    int balance = getBalance(root);

    // Detect LL imbalance
    if (balance > 1 &&
        value < root->left->data)
    {
        cout << "\nLL imbalance detected at node "
             << root->data << endl;

        // Modification 1: Display before rotation
        cout << "\nTree BEFORE rotation:\n";
        displayTree(root);

        // Modification 2: Balance factors before rotation
        cout << "\nBalance factors BEFORE rotation:\n";
        displayBalanceFactors(root);

        cout << "\nPerforming right rotation...\n";

        root = rightRotate(root);

        // Display after rotation
        cout << "\nTree AFTER rotation:\n";
        displayTree(root);

        // Balance factors after rotation
        cout << "\nBalance factors AFTER rotation:\n";
        displayBalanceFactors(root);

        return root;
    }

    return root;
}

void inorder(Node* root)
{
    if (root == NULL)
        return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main()
{
    Node* root = NULL;

    // Modification 3: New LL input sequence
    int elements[3] = {50, 40, 30};

    cout << "===== AVL TREE: LL ROTATION =====\n";
    cout << "Input sequence: 50, 40, 30\n";

    for (int i = 0; i < 3; i++)
    {
        cout << "\nInserting: " << elements[i]
             << endl;

        root = insert(root, elements[i]);
    }

    cout << "\nFinal balanced AVL tree:\n";
    displayTree(root);

    cout << "\nInorder traversal: ";
    inorder(root);

    cout << "\n\nRoot node: " << root->data;
    cout << "\nRoot balance factor: "
         << getBalance(root) << endl;

    return 0;
}
