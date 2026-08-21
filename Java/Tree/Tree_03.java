/* 
=============================================================================== 
Program Name    : Binary Search Tree - Inorder Traversal  
Program Number  : 03 
File Name       : Tree_03.java 
 
Description     : This program demonstrates Inorder Traversal of a Binary 
                  Search Tree using Java. It first creates a Binary Search 
                  Tree by inserting elements and then displays the elements 
                  using Inorder Traversal. Inorder Traversal visits the left 
                  subtree, current node and right subtree. 
 
Date            : August 2026 
Language        : Java 
Author          : Ishwari Vijaykumar Surve 
=============================================================================== 
 
Concepts Used: 
1. Class 
2. Object-Oriented Programming (OOP) 
3. Self-Referential Class 
4. Constructor 
5. Binary Search Tree (BST) 
6. Dynamic Memory Allocation 
7. Recursion 
8. Insertion Operation 
9. Inorder Traversal 
10. Function Overloading 
 
Key Learning Points: 
- Understand Inorder Traversal of a Binary Search Tree. 
- Learn how recursion is used to traverse a Tree. 
- Visit the left subtree before the root node. 
- Visit the right subtree after the root node. 
- Understand that Inorder Traversal of a BST gives elements in sorted order. 
- Understand function overloading using two Inorder functions. 
 
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
 
    /////////////////////////////////////////////////////////////////////////// 
    // 
    // Function Name : Insert 
    // Description   : Insert element into Binary Search Tree 
    // 
    /////////////////////////////////////////////////////////////////////////// 
 
    public void Insert(int iNo) 
    { 
        node newn = null; 
        node temp = null; 
 
        newn = new node(); 
 
        newn.data = iNo; 
        newn.lchild = null; 
        newn.rchild = null; 
 
        if(first == null) 
        { 
            first = newn; 
        } 
        else 
        { 
            temp = first; 
 
            while(true) 
            { 
                if(iNo > temp.data) 
                { 
                    if(temp.rchild == null) 
                    { 
                        temp.rchild = newn; 
                        break; 
                    } 
 
                    temp = temp.rchild; 
                } 
                else if(iNo < temp.data) 
                { 
                    if(temp.lchild == null) 
                    { 
                        temp.lchild = newn; 
                        break; 
                    } 
 
                    temp = temp.lchild; 
                } 
                else 
                { 
                    System.out.println("Duplicate element not allowed"); 
                    break; 
                } 
            } 
        } 
    } 
 
    /////////////////////////////////////////////////////////////////////////// 
    // 
    // Function Name : Inorder 
    // Description   : Display tree using Inorder Traversal 
    // 
    /////////////////////////////////////////////////////////////////////////// 
 
    public void Inorder(node temp) 
    { 
        if(temp != null) 
        { 
            Inorder(temp.lchild); 
 
            System.out.println(temp.data); 
 
            Inorder(temp.rchild); 
        } 
    } 
 
    /////////////////////////////////////////////////////////////////////////// 
    // 
    // Function Name : Inorder 
    // Description   : Start Inorder Traversal from first node 
    // 
    /////////////////////////////////////////////////////////////////////////// 
 
    public void Inorder() 
    { 
        Inorder(first); 
    } 
} 
 
class Tree_03 
{ 
    public static void main(String A[]) 
    { 
        Tree tobj = new Tree(); 
 
        tobj.Insert(11); 
        tobj.Insert(5); 
        tobj.Insert(17); 
        tobj.Insert(4); 
        tobj.Insert(7); 
        tobj.Insert(15); 
        tobj.Insert(21); 
 
        System.out.println("Inorder Traversal : "); 
 
        tobj.Inorder(); 
    } 
} 
 
/* 
=============================================================================== 
Expected Output: 
=============================================================================== 
 
Inorder Traversal : 
4 
5 
7 
11 
15 
17 
21 
 
=============================================================================== 
Memory Representation: 
=============================================================================== 
 
                         11 
                       /    \ 
                      5      17 
                     / \    /  \ 
                    4   7  15  21 
 
Inorder Traversal: 
 
       Left Subtree  ->  Root  ->  Right Subtree 
 
             4  ->  5  ->  7  ->  11  ->  15  ->  17  ->  21 
 
=============================================================================== 
Inorder Traversal Process: 
=============================================================================== 
 
                         11 
                       /    \ 
                      5      17 
                     / \    /  \ 
                    4   7  15  21 
 
Step 1 : Visit left subtree of 11 
Step 2 : Visit left subtree of 5 
Step 3 : Visit 4 
Step 4 : Visit 5 
Step 5 : Visit 7 
Step 6 : Visit 11 
Step 7 : Visit left subtree of 17 
Step 8 : Visit 15 
Step 9 : Visit 17 
Step 10: Visit 21 
 
Final Inorder Sequence: 
 
4  5  7  11  15  17  21 
 
=============================================================================== 
Node Structure: 
=============================================================================== 
 
                    +-----------+-----------+-----------+ 
                    |   data    |  lchild   |  rchild   | 
                    +-----------+-----------+-----------+ 
                          |           |           | 
                        Value       Address     Address 
 
=============================================================================== 
Algorithm: 
=============================================================================== 
 
1. Start the program. 
2. Define the node class with data, lchild and rchild members. 
3. Define the Tree class. 
4. Initialize first to NULL using the constructor. 
5. Define the Insert function. 
6. Insert the given elements into the Binary Search Tree. 
7. Define the recursive Inorder function. 
8. Check whether the current node is NULL. 
9. If the node is not NULL, recursively visit the left subtree. 
10. Display the data of the current node. 
11. Recursively visit the right subtree. 
12. Call the Inorder function starting from the first node. 
13. Display all elements in sorted order. 
14. Stop the program. 
 
=============================================================================== 
Program Flow: 
=============================================================================== 
 
        Start 
          | 
          v 
     Create Tree 
          | 
          v 
   Insert Tree Elements 
          | 
          v 
   Call Inorder() 
          | 
          v 
      first Node 
          | 
          v 
   Inorder(first) 
          | 
          v 
   Visit Left Subtree 
          | 
          v 
    Display Root 
          | 
          v 
  Visit Right Subtree 
          | 
          v 
    Display Elements 
          | 
          v 
         Stop 
 
=============================================================================== 
Time Complexity: 
=============================================================================== 
 
Insertion        : O(log n) Average 
Insertion        : O(n) Worst Case 
Inorder Traversal: O(n) 
 
=============================================================================== 
Space Complexity: 
=============================================================================== 
 
Tree Storage     : O(n) 
Recursion Stack  : O(h) 
 
Where h is the height of the Binary Search Tree. 
 
=============================================================================== 
Conclusion: 
=============================================================================== 
 
Program 03 demonstrates Inorder Traversal of a Binary Search Tree using 
Java. The recursive Inorder function visits the left subtree, current node 
and right subtree. Since the Tree is a Binary Search Tree, the Inorder 
Traversal displays all elements in sorted ascending order. 
 
=============================================================================== 
*/
