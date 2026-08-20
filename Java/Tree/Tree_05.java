/* 
=============================================================================== 
Program Name    : Binary Search Tree - Postorder Traversal 
Program Number  : 05 
File Name       : Tree_05.java 
 
Description     : This program demonstrates Postorder Traversal of a Binary 
                  Search Tree using Java. It first creates a Binary Search 
                  Tree by inserting elements and then displays the elements 
                  using Postorder Traversal. Postorder Traversal visits the 
                  left subtree, right subtree and current node. 
 
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
9. Postorder Traversal 
10. Function Overloading 
 
Key Learning Points: 
- Understand Postorder Traversal of a Binary Search Tree. 
- Learn how recursion is used to traverse a Tree. 
- Visit the left subtree first. 
- Visit the right subtree after the left subtree. 
- Visit the root node after both subtrees. 
- Understand function overloading using two Postorder functions. 
 
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
    // Function Name : Postorder 
    // Description   : Display tree using Postorder Traversal 
    // 
    /////////////////////////////////////////////////////////////////////////// 
 
    public void Postorder(node temp) 
    { 
        if(temp != null) 
        { 
            Postorder(temp.lchild); 
 
            Postorder(temp.rchild); 
 
            System.out.println(temp.data); 
        } 
    } 
 
    /////////////////////////////////////////////////////////////////////////// 
    // 
    // Function Name : Postorder 
    // Description   : Start Postorder Traversal from first node 
    // 
    /////////////////////////////////////////////////////////////////////////// 
 
    public void Postorder() 
    { 
        Postorder(first); 
    } 
} 
 
class Tree_05 
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
 
        System.out.println("Postorder Traversal : "); 
 
        tobj.Postorder(); 
    } 
} 
 
/* 
=============================================================================== 
Expected Output: 
=============================================================================== 
 
Postorder Traversal : 
4 
7 
5 
15 
21 
17 
11 
 
=============================================================================== 
Memory Representation: 
=============================================================================== 
 
                         11 
                       /    \ 
                      5      17 
                     / \    /  \ 
                    4   7  15  21 
 
Postorder Traversal: 
 
       Left Subtree  ->  Right Subtree  ->  Root 
 
             4  ->  7  ->  5  ->  15  ->  21  ->  17  ->  11 
 
=============================================================================== 
Postorder Traversal Process: 
=============================================================================== 
 
                         11 
                       /    \ 
                      5      17 
                     / \    /  \ 
                    4   7  15  21 
 
Step 1 : Visit left subtree of 11 
Step 2 : Visit left subtree of 5 
Step 3 : Visit 4 
Step 4 : Visit 7 
Step 5 : Visit 5 
Step 6 : Visit right subtree of 11 
Step 7 : Visit left subtree of 17 
Step 8 : Visit 15 
Step 9 : Visit 21 
Step 10: Visit 17 
Step 11: Visit 11 
 
Final Postorder Sequence: 
 
4  7  5  15  21  17  11 
 
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
7. Define the recursive Postorder function. 
8. Check whether the current node is NULL. 
9. If the node is not NULL, recursively visit the left subtree. 
10. Recursively visit the right subtree. 
11. Display the data of the current node. 
12. Call the Postorder function starting from the first node. 
13. Display all elements in Postorder sequence. 
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
   Call Postorder() 
          | 
          v 
      first Node 
          | 
          v 
   Visit Left Subtree 
          | 
          v 
   Visit Right Subtree 
          | 
          v 
      Display Root 
          | 
          v 
    Display Elements 
          | 
          v 
         Stop 
 
=============================================================================== 
Time Complexity: 
=============================================================================== 
 
Insertion          : O(log n) Average 
Insertion          : O(n) Worst Case 
Postorder Traversal: O(n) 
 
=============================================================================== 
Space Complexity: 
=============================================================================== 
 
Tree Storage     : O(n) 
Recursion Stack  : O(h) 
 
Where h is the height of the Binary Search Tree. 
 
=============================================================================== 
Conclusion: 
=============================================================================== 
 
Program 05 demonstrates Postorder Traversal of a Binary Search Tree using 
Java. The recursive Postorder function visits the left subtree first, 
followed by the right subtree and finally the current node. This traversal 
is useful when child nodes need to be processed before their parent node. 
 
=============================================================================== 
*/
