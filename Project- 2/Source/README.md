# Source Code: AVL Tree LL Rotation

## Overview
The C++ source code implements an AVL tree and demonstrates
the Left-Left (LL) rotation required to balance the tree
after inserting the elements 30, 20, and 10.

## Main Components

### 1. Node Structure
Defines a tree node containing data, height, and pointers
to its left and right child nodes.

### 2. Height Function
Returns the height of a node and returns 0 if the node
is empty.

### 3. Balance Factor Function
Calculates the balance factor by subtracting the height
of the right subtree from the height of the left subtree.

### 4. Right Rotation Function
Performs a right rotation when an LL imbalance occurs.
It rearranges the nodes to restore the balance of the tree.

### 5. Insertion Function
Inserts elements according to Binary Search Tree rules,
updates node heights, calculates balance factors, and
detects the LL imbalance.

### 6. Inorder Traversal
Displays the tree elements in ascending order.

### 7. Display Tree Function
Displays the structure of the balanced AVL tree sideways.

### 8. Main Function
Inserts 30, 20, and 10, displays the LL imbalance message,
performs the rotation, and prints the final tree,
inorder traversal, root node, and balance factor.

## Expected Result
The final balanced AVL tree has node 20 as the root,
node 10 as the left child, and node 30 as the right child.

Inorder Traversal: 10 20 30
Root Node: 20
Balance Factor of Root: 0
