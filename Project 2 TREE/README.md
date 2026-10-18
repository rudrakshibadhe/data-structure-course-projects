# Project 2: AVL Tree LL Rotation

## Overview
This project demonstrates the insertion of elements
30, 20, and 10 into an AVL tree. It detects the
Left-Left (LL) imbalance and performs a right
rotation to restore balance.

## Objectives
- Understand AVL tree insertion.
- Calculate node balance factors.
- Detect the LL imbalance condition.
- Implement right rotation.
- Display the balanced tree.

## Algorithm
1. Insert 30, 20, and 10 into the AVL tree.
2. Update node heights after insertion.
3. Calculate the balance factor.
4. Detect the LL imbalance at node 30.
5. Perform a right rotation.
6. Display the balanced tree and inorder traversal.

## Expected Result
       20
      /  \
     10   30

Inorder Traversal: 10 20 30

## Technologies Used
- Language: C++
- Concept: AVL Tree
- Data Structure: Binary Search Tree
- Operation: LL Rotation (Right Rotation)

## Time Complexity
Insertion: O(log n) per operation in an AVL tree.
Rotation: O(1).

## How to Run
Compile:
g++ src/avl_ll_rotation.cpp -o avl

Run:
./avl

On Windows:
avl.exe

## Conclusion
The program successfully detects the LL imbalance
and performs a right rotation to produce a balanced
AVL tree with root node 20.
