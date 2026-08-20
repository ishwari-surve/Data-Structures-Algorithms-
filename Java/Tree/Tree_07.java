/* 
=============================================================================== 
Program Name    : Binary Search Tree - Count Total Nodes 
Program Number  : 07 
File Name       : Tree_07.java 
 
Description     : This program demonstrates how to count the total number 
                  of nodes in a Binary Search Tree using Java. It uses 
                  recursion to visit every node in the tree and calculates 
                  the total number of nodes. 
 
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
9. Node Counting 
10. Function Overloading 
 
Key Learning Points: 
- Understand how to count total nodes in a Binary Search Tree. 
- Learn how recursion is used to count nodes. 
- Return 0 when the current node is NULL. 
- Count nodes in the left subtree. 
- Count nodes in the right subtree. 
- Add 1 for the current node. 
- Understand function overloading using two Count functions. 
 
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
    // Function Name : Count 
    // Description   : Count total number of nodes 
    // 
    /////////////////////////////////////////////////////////////////////////// 
 
    public int Count(node temp) 
    { 
        if(temp == null) 
        { 
            return 0; 
        } 
 
        return Count(temp.lchild) + Count(temp.rchild) + 1; 
    } 
 
    /////////////////////////////////////////////////////////////////////////// 
    // 
    // Function Name : Count 
    // Description   : Start counting from first node 
    // 
    /////////////////////////////////////////////////////////////////////////// 
 
    public int Count() 
    { 
        return Count(first); 
    } 
} 
 
class Tree_07 
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
 
        int iRet = tobj.Count(); 
 
        System.out.println("Total Number of Nodes : " + iRet); 
    } 
} 
 
/* 
=============================================================================== 
Expected Output: 
=============================================================================== 
 
Total Number of Nodes : 7 
 
=============================================================================== 
Memory Representation: 
=============================================================================== 
 
                         11 
                       /    \ 
                      5      17 
                     / \    /  \ 
                    4   7  15  21 
 
Total Nodes: 
 
             11 
           /    \ 
          5      17 
         / \    /  \ 
        4   7  15  21 
 
        1 + 1 + 1 + 1 + 1 + 1 + 1 = 7 
 
Total Number of Nodes = 7 
 
=============================================================================== 
Counting Process: 
=============================================================================== 
 
Step 1 : Start from the root node 11. 
Step 2 : Count all nodes in the left subtree of 11. 
Step 3 : Count node 5 and its child nodes 4 and 7. 
Step 4 : Left subtree contains 3 nodes. 
Step 5 : Count all nodes in the right subtree of 11. 
Step 6 : Count node 17 and its child nodes 15 and 21. 
Step 7 : Right subtree contains 3 nodes. 
Step 8 : Add the root node 11. 
 
Total Nodes = Left Subtree + Right Subtree + Root 
            = 3 + 3 + 1 
            = 7 
 
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
7. Define the recursive Count function. 
8. Check whether the current node is NULL. 
9. If the current node is NULL, return 0. 
10. Recursively count nodes in the left subtree. 
11. Recursively count nodes in the right subtree. 
12. Add 1 for the current node. 
13. Return the total count. 
14. Call Count starting from the first node. 
15. Display the total number of nodes. 
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
      Call Count() 
          | 
          v 
      Start at Root 
          | 
          v 
      Is Node NULL? 
        /       \ 
      Yes        No 
       |          | 
       v          v 
   Return 0   Count Left 
                  | 
                  v 
             Count Right 
                  | 
                  v 
              Add 1 
                  | 
                  v 
           Return Count 
                  | 
                  v 
           Display Result 
                  | 
                  v 
                 Stop 
 
=============================================================================== 
Time Complexity: 
=============================================================================== 
 
Insertion   : O(log n) Average 
Insertion   : O(n) Worst Case 
Count       : O(n) 
 
=============================================================================== 
Space Complexity: 
=============================================================================== 
 
Tree Storage    : O(n) 
Recursion Stack : O(h) 
 
Where h is the height of the Binary Search Tree. 
 
=============================================================================== 
Conclusion: 
=============================================================================== 
 
Program 07 demonstrates how to count the total number of nodes in a Binary 
Search Tree using Java. The recursive Count function counts the nodes in 
the left subtree, counts the nodes in the right subtree and adds one for 
the current node. For the given Tree, the total number of nodes is 7. 
 
=============================================================================== 
*/
