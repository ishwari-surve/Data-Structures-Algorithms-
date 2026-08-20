/* 
=============================================================================== 
Program Name    : Binary Search Tree - Preorder Traversal 
Program Number  : 04 
File Name       : Tree_04.java 
 
Description     : This program demonstrates Preorder Traversal of a Binary 
                  Search Tree using Java. It first creates a Binary Search 
                  Tree by inserting elements and then displays the elements 
                  using Preorder Traversal. Preorder Traversal visits the 
                  current node, left subtree and right subtree. 
 
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
9. Preorder Traversal 
10. Function Overloading 
 
Key Learning Points: 
- Understand Preorder Traversal of a Binary Search Tree. 
- Learn how recursion is used to traverse a Tree. 
- Visit the root node before visiting its subtrees. 
- Visit the left subtree after the root node. 
- Visit the right subtree after the left subtree. 
- Understand function overloading using two Preorder functions. 
 
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
    // Function Name : Preorder 
    // Description   : Display tree using Preorder Traversal 
    // 
    /////////////////////////////////////////////////////////////////////////// 
 
    public void Preorder(node temp) 
    { 
        if(temp != null) 
        { 
            System.out.println(temp.data); 
 
            Preorder(temp.lchild); 
 
            Preorder(temp.rchild); 
        } 
    } 
 
    /////////////////////////////////////////////////////////////////////////// 
    // 
    // Function Name : Preorder 
    // Description   : Start Preorder Traversal from first node 
    // 
    /////////////////////////////////////////////////////////////////////////// 
 
    public void Preorder() 
    { 
        Preorder(first); 
    } 
} 
 
class Tree_04 
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
 
        System.out.println("Preorder Traversal : "); 
 
        tobj.Preorder(); 
    } 
} 
 
/* 
=============================================================================== 
Expected Output: 
=============================================================================== 
 
Preorder Traversal : 
11 
5 
4 
7 
17 
15 
21 
 
=============================================================================== 
Memory Representation: 
=============================================================================== 
 
                         11 
                       /    \ 
                      5      17 
                     / \    /  \ 
                    4   7  15  21 
 
Preorder Traversal: 
 
       Root  ->  Left Subtree  ->  Right Subtree 
 
             11  ->  5  ->  4  ->  7  ->  17  ->  15  ->  21 
 
=============================================================================== 
Preorder Traversal Process: 
=============================================================================== 
 
                         11 
                       /    \ 
                      5      17 
                     / \    /  \ 
                    4   7  15  21 
 
Step 1 : Visit 11 
Step 2 : Visit left subtree of 11 
Step 3 : Visit 5 
Step 4 : Visit left subtree of 5 
Step 5 : Visit 4 
Step 6 : Visit right subtree of 5 
Step 7 : Visit 7 
Step 8 : Visit right subtree of 11 
Step 9 : Visit 17 
Step 10: Visit left subtree of 17 
Step 11: Visit 15 
Step 12: Visit right subtree of 17 
Step 13: Visit 21 
 
Final Preorder Sequence: 
 
11  5  4  7  17  15  21 
 
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
7. Define the recursive Preorder function. 
8. Check whether the current node is NULL. 
9. If the node is not NULL, display the data of the current node. 
10. Recursively visit the left subtree. 
11. Recursively visit the right subtree. 
12. Call the Preorder function starting from the first node. 
13. Display all elements in Preorder sequence. 
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
   Call Preorder() 
          | 
          v 
      first Node 
          | 
          v 
      Display Root 
          | 
          v 
   Visit Left Subtree 
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
 
Insertion         : O(log n) Average 
Insertion         : O(n) Worst Case 
Preorder Traversal: O(n) 
 
=============================================================================== 
Space Complexity: 
=============================================================================== 
 
Tree Storage     : O(n) 
Recursion Stack  : O(h) 
 
Where h is the height of the Binary Search Tree. 
 
=============================================================================== 
Conclusion: 
=============================================================================== 
 
Program 04 demonstrates Preorder Traversal of a Binary Search Tree using 
Java. The recursive Preorder function visits the current node first, 
followed by the left subtree and then the right subtree. This traversal 
is useful for processing the root node before its child nodes. 
 
=============================================================================== 
*/
