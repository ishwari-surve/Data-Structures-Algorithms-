/* 
=============================================================================== 
Program Name    : Binary Search Tree - Insert Elements  
Program Number  : 02 
File Name       : Tree_02.java 
 
Description     : This program demonstrates how to insert elements into a 
                  Binary Search Tree using Java. It creates a new node for 
                  every element and places it at the correct position 
                  according to the Binary Search Tree property. 
 
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
6. Node Creation 
7. Dynamic Memory Allocation 
8. Tree Traversal using Links 
9. Insertion Operation 
10. Duplicate Element Handling 
 
Key Learning Points: 
- Understand how elements are inserted into a Binary Search Tree. 
- Learn how a new node is dynamically created. 
- Understand the Binary Search Tree insertion rule. 
- Smaller elements are inserted on the left side. 
- Greater elements are inserted on the right side. 
- Duplicate elements are not allowed. 
- Understand how lchild and rchild links are used. 
 
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
} 
 
class Tree_02 
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
 
        System.out.println("Elements inserted successfully"); 
    } 
} 
 
/* 
=============================================================================== 
Expected Output: 
=============================================================================== 
 
Elements inserted successfully 
 
=============================================================================== 
Memory Representation: 
=============================================================================== 
 
                         11 
                       /    \ 
                      5      17 
                     / \    /  \ 
                    4   7  15  21 
 
=============================================================================== 
Insertion Process: 
=============================================================================== 
 
1. Insert 11 
   
                         11 
 
2. Insert 5 
 
                         11 
                        / 
                       5 
 
3. Insert 17 
 
                         11 
                        /  \ 
                       5    17 
 
4. Insert 4 
 
                         11 
                        /  \ 
                       5    17 
                      / 
                     4 
 
5. Insert 7 
 
                         11 
                        /  \ 
                       5    17 
                      / \ 
                     4   7 
 
6. Insert 15 
 
                         11 
                        /  \ 
                       5    17 
                      / \   / 
                     4   7 15 
 
7. Insert 21 
 
                         11 
                        /  \ 
                       5    17 
                      / \   / \ 
                     4   7 15 21 
 
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
6. Create a new node dynamically. 
7. Store the given element in the data member. 
8. Initialize lchild and rchild to NULL. 
9. If the Tree is empty, make the new node the first node. 
10. Otherwise, start from the first node. 
11. If the new element is greater than the current node, move to rchild. 
12. If rchild is NULL, insert the new node there. 
13. If the new element is smaller than the current node, move to lchild. 
14. If lchild is NULL, insert the new node there. 
15. If the element is equal to the current node, display duplicate message. 
16. Repeat the process until the new node is inserted. 
17. Insert all given elements into the Tree. 
18. Display the success message. 
19. Stop the program. 
 
=============================================================================== 
Program Flow: 
=============================================================================== 
 
        Start 
          | 
          v 
     Create Tree 
          | 
          v 
     Call Insert() 
          | 
          v 
     Create New Node 
          | 
          v 
     Is Tree Empty? 
       /        \ 
     Yes         No 
      |           | 
      v           v 
  first = newn  Start from first 
                  | 
                  v 
            Compare Element 
             /           \ 
          Smaller       Greater 
             |             | 
             v             v 
          lchild         rchild 
             |             | 
             v             v 
       Insert Node     Insert Node 
             \             / 
              \           / 
               v         v 
             Display Success 
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
 
Node Creation : O(n) 
Auxiliary Space: O(1) 
 
=============================================================================== 
Conclusion: 
=============================================================================== 
 
Program 02 demonstrates the insertion operation in a Binary Search Tree 
using Java. Each new element is compared with the current node and placed 
on the left if it is smaller or on the right if it is greater. Duplicate 
elements are not allowed. This program forms the foundation for implementing 
other Binary Search Tree operations such as searching, traversal and 
deletion. 
 
=============================================================================== 
*/
