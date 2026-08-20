/* 
=============================================================================== 
Program Name    : Binary Search Tree - Basic Structure 
Program Number  : 01 
File Name       : Tree_01.java 
 
Description     : This program demonstrates the basic structure of a Binary 
                  Search Tree using Java. It defines the node class, Tree 
                  class, constructor, and initializes an empty Binary 
                  Search Tree. 
 
Date            : August 2026 
Language        : Java 
Author          : Ishwari Vijaykumar Surve 
=============================================================================== 
 
Concepts Used: 
1. Class 
2. Object-Oriented Programming (OOP) 
3. Self-Referential Class 
4. Constructor 
5. Binary Tree 
6. Binary Search Tree (BST) 
7. Dynamic Memory Allocation Preparation 
 
Key Learning Points: 
- Understand the basic structure of a Binary Search Tree. 
- Learn how a Tree is represented using nodes. 
- Understand the node structure used in a BST. 
- Initialize an empty Tree using a constructor. 
- Understand the first pointer which represents the root node. 
 
=============================================================================== 
*/ 
 
class node
{
    public int data;
    public node lchild;
    public node rchild;
}

class Tree
{
    private node first;

    public Tree()
    {
        first = null;
    }
}

class Tree_01
{
    public static void main(String A[])
    {
        Tree tobj = new Tree();

        System.out.println("Binary Search Tree created successfully");
    }
}

/* 
=============================================================================== 
Expected Output: 
=============================================================================== 
 
Binary Search Tree created successfully 
 
=============================================================================== 
Memory Representation: 
=============================================================================== 
 
              Tree Object 
 
        +----------------------+ 
        | first -------> NULL  | 
        +----------------------+ 
 
Tree is Empty. 
 
=============================================================================== 
Node Structure: 
=============================================================================== 
 
              +-----------+-----------+-----------+ 
              |   data    |  lchild   |  rchild   | 
              +-----------+-----------+-----------+ 
                    |           |           | 
                    |           |           | 
                  Value       NULL        NULL 
 
=============================================================================== 
Algorithm: 
=============================================================================== 
 
1. Start the program. 
2. Define the node class with data, lchild and rchild members. 
3. Define the Tree class. 
4. Declare first as a private data member. 
5. Initialize first to NULL using the constructor. 
6. Create a Tree object. 
7. Display the Tree creation message. 
8. Stop the program. 
 
=============================================================================== 
Program Flow: 
=============================================================================== 
 
        Start 
          | 
          v 
     Define Node Class 
          | 
          v 
     Create Tree Class 
          | 
          v 
    Call Constructor 
          | 
          v 
 Initialize first = NULL 
          | 
          v 
    Create Tree Object 
          | 
          v 
    Display Message 
          | 
          v 
         Stop 
 
=============================================================================== 
Time Complexity: 
=============================================================================== 
 
Constructor : O(1) 
 
=============================================================================== 
Space Complexity: 
=============================================================================== 
 
O(1) 
 
=============================================================================== 
Conclusion: 
=============================================================================== 
 
Program 01 introduces the basic structure of a Binary Search Tree using 
Java. It defines the node class and Tree class and initializes an empty 
Tree using a constructor. This program serves as the foundation for 
implementing various Binary Search Tree operations in subsequent programs. 
 
=============================================================================== 
*/
