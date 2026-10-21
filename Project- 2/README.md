# Project 2: AVL Tree LL Rotation

## 1. Problem Statement

To write a C++ program to insert the elements 30, 20, and 10 into an AVL tree, detect the Left-Left (LL) imbalance, and perform the required right rotation to balance the tree.

## 2. Objectives

1. To understand the concept of an AVL tree.
2. To insert elements into an AVL tree using C++.
3. To calculate the height and balance factor of each node.
4. To detect the LL imbalance.
5. To perform a right rotation to balance the tree.
6. To display the balanced tree and verify its correctness.

## 3. Modifications

1. Display the tree before and after rotation.
2. Print the balance factors of affected nodes before and after rotation.
3. Change the input sequence from `30, 20, 10` to `50, 40, 30` to demonstrate another LL case.

## 4. Objectives with Modification

1. To display the tree structure before and after rotation.
2. To calculate and display the balance factors of affected nodes.
3. To demonstrate another LL imbalance using `50, 40, 30`.
4. To verify that the tree is balanced after rotation.
5. To display the final tree and inorder traversal.

## 5. Algorithm

1. Start and initialize an empty AVL tree.
2. Insert the elements 30, 20, and 10.
3. Update node heights and calculate balance factors.
4. Detect the LL imbalance at node 30 when its balance factor becomes +2.
5. Perform a right rotation at node 30.
6. Make node 20 the root, with 10 as its left child and 30 as its right child.
7. Display the balanced tree and inorder traversal.
8. Stop.

## 6. Modified Algorithm

1. Initialize an empty AVL tree and insert 50, 40, and 30.
2. Update node heights and calculate balance factors.
3. Detect the LL imbalance at node 50.
4. Display the tree and balance factors before rotation.
5. Perform a right rotation at node 50.
6. Display the balanced tree and updated balance factors.
7. Print the inorder traversal and root balance factor.
8. Stop.

## 7. Flowchart

![Modified AVL Tree LL Rotation Flowchart](Flowchart/modified_avl_ll_flowchart.png)

## 8. Source Code Explanation

- **Node Structure:** Stores data, height, and pointers to the left and right children.
- **height():** Returns the height of a node.
- **getBalance():** Calculates the balance factor.
- **insert():** Inserts elements and detects LL imbalance.
- **rightRotate():** Performs right rotation.
- **displayTree():** Displays the tree structure.
- **displayBalanceFactors():** Prints the balance factors of nodes.
- **inorder():** Displays elements in ascending order.

Source code: [avl_ll_rotation.cpp](avl_ll_rotation.cpp)

## 9. Expected Output

### Original Input Sequence

Input: `30, 20, 10`

Before rotation:

```text
    30
   /
  20
 /
10
```

After rotation:

```text
    20
   /  \
  10   30
```

Inorder Traversal: `10 20 30`

### Modified Input Sequence

Input: `50, 40, 30`

Before rotation:

```text
    50
   /
  40
 /
30
```

After rotation:

```text
    40
   /  \
  30   50
```

Inorder Traversal: `30 40 50`

Root Node: `40`

Root Balance Factor: `0`

## 10. Time and Space Complexity

| Operation | Time Complexity |
|---|---|
| AVL Insertion | O(log n) |
| Right Rotation | O(1) |
| Inorder Traversal | O(n) |

- **Tree storage:** O(n)
- **Auxiliary stack space:** O(log n) for a balanced tree.

Here, `n` represents the number of nodes in the tree.

## 11. Conclusion

The original program detects the LL imbalance and balances the AVL tree using the elements 30, 20, and 10. The modified program additionally displays the tree and balance factors before and after rotation and demonstrates another LL case using 50, 40, and 30. Both programs demonstrate how right rotation maintains AVL tree balance.

## 12. Technologies Used

- Programming Language: C++
- Data Structure: AVL Tree
- Operation: LL Rotation (Right Rotation)
- Platform: GitHub

## 13. How to Run

Compile the program:

```bash
g++ avl_ll_rotation.cpp -o avl
```

Run on Windows:

```text
avl.exe
```

Run on Linux:

```bash
./avl
```
