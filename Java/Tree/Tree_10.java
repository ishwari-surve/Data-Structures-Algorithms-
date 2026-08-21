/*
===============================================================================
Program Name    : Binary Search Tree - Complete Operations
Program Number  : 10 
File Name       : Tree_10.java

Description     : This program demonstrates the major operations of a Binary
                  Search Tree using Java. It performs insertion, searching,
                  inorder traversal, preorder traversal, postorder traversal,
                  counting total nodes, counting leaf nodes and counting
                  parent nodes.

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
7. Insertion
8. Searching
9. Inorder Traversal
10. Preorder Traversal
11. Postorder Traversal
12. Recursion
13. Node Counting
14. Leaf Node
15. Parent Node

Key Learning Points:
- Understand the basic operations of a Binary Search Tree.
- Learn how elements are inserted into a Binary Search Tree.
- Understand how searching is performed using the BST property.
- Learn the three depth-first tree traversals.
- Count the total number of nodes in the tree.
- Count the leaf nodes in the tree.
- Count the parent nodes in the tree.

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

    ///////////////////////////////////////////////////////////////////////////
    //
    // Function Name : Inorder
    // Description   : Left -> Data -> Right
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

    public void Inorder()
    {
        Inorder(first);
    }

    ///////////////////////////////////////////////////////////////////////////
    //
    // Function Name : Preorder
    // Description   : Data -> Left -> Right
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

    public void Preorder()
    {
        Preorder(first);
    }

    ///////////////////////////////////////////////////////////////////////////
    //
    // Function Name : Postorder
    // Description   : Left -> Right -> Data
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

    public void Postorder()
    {
        Postorder(first);
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

        return Count(temp.lchild) +
               Count(temp.rchild) + 1;
    }

    public int Count()
    {
        return Count(first);
    }

    ///////////////////////////////////////////////////////////////////////////
    //
    // Function Name : CountLeaf
    // Description   : Count leaf nodes
    //
    ///////////////////////////////////////////////////////////////////////////

    public int CountLeaf(node temp)
    {
        if(temp == null)
        {
            return 0;
        }

        if(temp.lchild == null && temp.rchild == null)
        {
            return 1;
        }

        return CountLeaf(temp.lchild) +
               CountLeaf(temp.rchild);
    }

    public int CountLeaf()
    {
        return CountLeaf(first);
    }

    ///////////////////////////////////////////////////////////////////////////
    //
    // Function Name : CountParent
    // Description   : Count parent nodes
    //
    ///////////////////////////////////////////////////////////////////////////

    public int CountParent(node temp)
    {
        if(temp == null)
        {
            return 0;
        }

        if(temp.lchild != null || temp.rchild != null)
        {
            return 1 +
                   CountParent(temp.lchild) +
                   CountParent(temp.rchild);
        }

        return 0;
    }

    public int CountParent()
    {
        return CountParent(first);
    }
}

class Tree_10
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

        System.out.println("==================================");
        System.out.println("      Binary Search Tree");
        System.out.println("==================================");

        System.out.println("\nInorder Traversal :");
        tobj.Inorder();

        System.out.println("\nPreorder Traversal :");
        tobj.Preorder();

        System.out.println("\nPostorder Traversal :");
        tobj.Postorder();

        System.out.println("\nTotal Nodes : " + tobj.Count());

        System.out.println("Leaf Nodes : " + tobj.CountLeaf());

        System.out.println("Parent Nodes : " + tobj.CountParent());

        int iNo = 15;

        System.out.println("\nSearching Element : " + iNo);

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

==================================
      Binary Search Tree
==================================

Inorder Traversal :
4
5
7
11
15
17
21

Preorder Traversal :
11
5
4
7
17
15
21

Postorder Traversal :
4
7
5
15
21
17
11

Total Nodes : 7
Leaf Nodes : 4
Parent Nodes : 3

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

Total Nodes  = 7
Leaf Nodes   = 4
Parent Nodes = 3

===============================================================================
Traversal Representation:
===============================================================================

Inorder:
Left -> Data -> Right

4 -> 5 -> 7 -> 11 -> 15 -> 17 -> 21


Preorder:
Data -> Left -> Right

11 -> 5 -> 4 -> 7 -> 17 -> 15 -> 21


Postorder:
Left -> Right -> Data

4 -> 7 -> 5 -> 15 -> 21 -> 17 -> 11

===============================================================================
Search Process:
===============================================================================

Searching Element = 15

                         11
                           \
                           17
                          /
                        15

Step 1 : Start from node 11.
Step 2 : 15 is greater than 11, move to the right.
Step 3 : Reach node 17.
Step 4 : 15 is smaller than 17, move to the left.
Step 5 : Reach node 15.
Step 6 : 15 is equal to 15, so the element is found.

===============================================================================
Node Counting:
===============================================================================

Total Nodes:

                         11
                       /    \
                      5      17
                     / \    /  \
                    4   7  15  21

Total = 7


Leaf Nodes:

4, 7, 15, 21

Total Leaf Nodes = 4


Parent Nodes:

11, 5, 17

Total Parent Nodes = 3

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
2. Define the node class with data, lchild and rchild.
3. Define the Tree class.
4. Initialize first to NULL using the constructor.
5. Insert the given elements into the Binary Search Tree.
6. Perform Inorder traversal.
7. Perform Preorder traversal.
8. Perform Postorder traversal.
9. Count the total number of nodes.
10. Count the number of leaf nodes.
11. Count the number of parent nodes.
12. Set the element to be searched.
13. Search for the given element using the BST property.
14. Display whether the element is present or not.
15. Stop the program.

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
    Inorder Traversal
          |
          v
    Preorder Traversal
          |
          v
   Postorder Traversal
          |
          v
      Count Nodes
          |
          v
     Count Leaves
          |
          v
    Count Parents
          |
          v
      Search Element
          |
          v
     Display Result
          |
          v
         Stop

===============================================================================
Time Complexity:
===============================================================================

Insertion     : O(log n) Average
Insertion     : O(n) Worst Case
Searching     : O(log n) Average
Searching     : O(n) Worst Case
Inorder       : O(n)
Preorder      : O(n)
Postorder     : O(n)
Count         : O(n)
CountLeaf     : O(n)
CountParent   : O(n)

===============================================================================
Space Complexity:
===============================================================================

Tree Storage    : O(n)
Traversal Stack : O(h)

Where h is the height of the Binary Search Tree.

===============================================================================
Conclusion:
===============================================================================

Program 10 demonstrates the complete implementation of a Binary Search Tree
using Java. It performs insertion, searching, inorder traversal, preorder
traversal, postorder traversal, total node counting, leaf node counting and
parent node counting. This program combines the important Binary Search Tree
operations implemented in the previous programs.

===============================================================================
*/
