/* 
=============================================================================== 
Program Name    : Binary Search Tree - Search Element 
Program Number  : 06 
File Name       : Tree_06.java 
 
Description     : This program demonstrates how to search an element in a 
                  Binary Search Tree using Java. It creates a Binary Search 
                  Tree by inserting elements and searches for a given element 
                  using the Binary Search Tree property. 
 
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
7. Insertion Operation 
8. Searching Operation 
9. Boolean Return Value 
10. Iterative Searching 
 
Key Learning Points: 
- Understand how searching is performed in a Binary Search Tree. 
- Learn how the Binary Search Tree property makes searching efficient. 
- If the element is greater than the current node, move to the right subtree. 
- If the element is smaller than the current node, move to the left subtree. 
- If the element is equal to the current node, the element is found. 
- Understand the use of boolean return values. 
 
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
    // Function Name : Search 
    // Description   : Search element in Binary Search Tree 
    // 
    /////////////////////////////////////////////////////////////////////////// 
 
    public boolean Search(int iNo) 
    { 
        node temp = null; 
 
        temp = first; 
 
        while(temp != null) 
        { 
            if(iNo == temp.data) 
            { 
                return true; 
            } 
            else if(iNo > temp.data) 
            { 
                temp = temp.rchild; 
            } 
            else 
            { 
                temp = temp.lchild; 
            } 
        } 
 
        return false; 
    } 
} 
 
class Tree_06 
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
 
        int iNo = 15; 
 
        System.out.println("Searching Element : " + iNo); 
 
        if(tobj.Search(iNo) == true) 
        { 
            System.out.println("Element is Present"); 
        } 
        else 
        { 
            System.out.println("There is no such element"); 
        } 
    } 
} 
 
/* 
=============================================================================== 
Expected Output: 
=============================================================================== 
 
Searching Element : 15 
Element is Present 
 
=============================================================================== 
Memory Representation: 
=============================================================================== 
 
                         11 
                       /    \ 
                      5      17 
                     / \    /  \ 
                    4   7  15  21 
 
Searching for : 15 
 
                         11 
                           \ 
                           17 
                          / 
                        15 
 
Search Path: 
 
15 > 11  -> Move Right 
15 < 17  -> Move Left 
15 = 15  -> Element Found 
 
=============================================================================== 
Search Process: 
=============================================================================== 
 
Step 1 : Start from the first node 11. 
Step 2 : Compare 15 with 11. 
Step 3 : Since 15 is greater than 11, move to the right child. 
Step 4 : Reach node 17. 
Step 5 : Compare 15 with 17. 
Step 6 : Since 15 is smaller than 17, move to the left child. 
Step 7 : Reach node 15. 
Step 8 : Since 15 is equal to 15, the element is found. 
 
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
7. Define the Search function. 
8. Start searching from the first node. 
9. Compare the given element with the current node. 
10. If both elements are equal, return true. 
11. If the given element is greater, move to the right subtree. 
12. If the given element is smaller, move to the left subtree. 
13. Continue until the element is found or the current node becomes NULL. 
14. If the current node becomes NULL, return false. 
15. Display whether the element is present or not. 
16. Stop the program. 
 
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
    Set iNo = 15 
          | 
          v 
     Call Search() 
          | 
          v 
   Start from first 
          | 
          v 
    Compare Element 
       /    |    \ 
   Equal  Greater  Smaller 
     |       |       | 
     v       v       v 
   Found    Right   Left 
             |       | 
             +---+---+ 
                 | 
                 v 
          Continue Search 
                 | 
                 v 
         Display Result 
                 | 
                 v 
                Stop 
 
=============================================================================== 
Time Complexity: 
=============================================================================== 
 
Best Case    : O(1) 
Average Case : O(log n) 
Worst Case   : O(n) 
 
=============================================================================== 
Space Complexity: 
=============================================================================== 
 
Tree Storage    : O(n) 
Search Variable : O(1) 
 
=============================================================================== 
Conclusion: 
=============================================================================== 
 
Program 06 demonstrates the searching operation in a Binary Search Tree 
using Java. The Search function compares the given element with each node 
and moves either to the left or right subtree according to the BST property. 
The function returns true when the element is found and false when the 
element is not present in the Tree. 
 
=============================================================================== 
*/
