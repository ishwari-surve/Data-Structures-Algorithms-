# Tree in C++

## Description

This folder contains programs based on the **Tree Data Structure** implemented using **C++**.

The programs demonstrate the basic concepts and operations of a **Binary Search Tree (BST)**, including node creation, insertion, tree traversal, searching, counting nodes, and other tree operations.

## Topics Covered

* **Node Structure**
* **Binary Tree**
* **Binary Search Tree (BST)**
* **Node Insertion**
* **Inorder Traversal**
* **Preorder Traversal**
* **Postorder Traversal**
* **Searching**
* **Counting Total Nodes**
* **Counting Leaf Nodes**
* **Counting Parent Nodes**
* **Menu Driven Tree Application**

## Node Structure

Each Tree node contains three members:

* **data** – Stores the value of the node.
* **lchild** – Stores the address of the left child.
* **rchild** – Stores the address of the right child.

```cpp
struct node
{
    int data;
    struct node *lchild;
    struct node *rchild;
};
```

## Binary Search Tree

A **Binary Search Tree (BST)** is a binary tree in which:

* Elements smaller than the current node are stored in the **left subtree**.
* Elements greater than the current node are stored in the **right subtree**.
* Duplicate elements are generally not inserted.

Example:

```text
              11
             /  \
            5    17
           / \   / \
          4   7 15 21
```

## Tree Traversals

### Inorder Traversal

```text
Left → Data → Right
```

In a Binary Search Tree, Inorder traversal displays the elements in **ascending order**.

### Preorder Traversal

```text
Data → Left → Right
```

### Postorder Traversal

```text
Left → Right → Data
```

## Operations

The Tree programs cover the following operations:

* **Insert()**

  * Inserts a new element into the Binary Search Tree.

* **Inorder()**

  * Displays nodes using Inorder traversal.

* **Preorder()**

  * Displays nodes using Preorder traversal.

* **Postorder()**

  * Displays nodes using Postorder traversal.

* **Search()**

  * Searches for a particular element in the Binary Search Tree.

* **Count()**

  * Counts the total number of nodes.

* **CountLeaf()**

  * Counts the number of leaf nodes.

* **CountParent()**

  * Counts the number of parent nodes.

## Technologies Used

* **Language:** C++
* **Data Structure:** Tree / Binary Search Tree
* **Concepts:** Pointers, Dynamic Memory Allocation, Classes, Structures, Recursion
* **Memory Allocation:** `new` and `delete`
* **Compiler:** GCC / G++ / MSVC
* **IDE:** VS Code / CodeBlocks / Dev-C++ / Any C++ IDE

## Requirements

## Language

**C++**

* **C++ Compiler**

  * GCC / G++
  * Clang
  * MSVC

* **IDE / Code Editor**

  * VS Code
  * CodeBlocks
  * Dev-C++
  * Any C++ IDE

## Program Structure

The Tree folder contains programs arranged sequentially according to the concepts covered.

```text
Tree/
│
├── Tree_01.cpp
├── Tree_02.cpp
├── Tree_03.cpp
├── Tree_04.cpp
├── Tree_05.cpp
├── ...
└── README.md
```

## Applications of Trees

- **File System** – Organizing files and folders.
- **Database** – Indexing and searching data.
- **Compiler Design** – Representing program structure.
- **AI & ML** – Decision Trees for classification.
- **Web Development** – Representing HTML/XML DOM.
- **Networking** – Spanning Tree Protocol.
- **Data Compression** – Huffman Coding.
- **Searching & Sorting** – Efficient data management.

## Learning Objectives

By completing these programs, the following concepts can be understood:

* Understand the basic structure of a Tree.
* Understand Binary Search Tree concepts.
* Implement dynamic node creation.
* Understand left and right child relationships.
* Perform different Tree traversals.
* Search elements efficiently in a BST.
* Count different types of nodes.
* Understand recursion in Tree operations.
* Implement a menu-driven Tree application.

## Conclusion

The Tree programs provide practical implementation of the **Tree Data Structure** using C++. They help in understanding Binary Search Trees, dynamic memory allocation, recursion, tree traversal techniques, searching, and various node-counting operations.

## Author

**Ishwari Vijaykumar Surve**





