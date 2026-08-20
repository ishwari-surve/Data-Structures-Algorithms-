/*
===============================================================================
Program Name    : Binary Search Tree - Count Leaf Nodes
Program Number  : 08
File Name       : Tree_08.java

Description     : This program demonstrates how to count the number of leaf
                  nodes in a Binary Search Tree using Java. A leaf node is a
                  node which does not have any left child or right child.
                  The program uses recursion to count all leaf nodes.

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
9. Leaf Node
10. Function Overloading

Key Learning Points:
- Understand the concept of a leaf node in a Binary Search Tree.
- A leaf node does not have a left child or right child.
- Learn how recursion is used to count leaf nodes.
- Return 0 when the current node is NULL.
- Return 1 when a leaf node is found.
- Add the leaf count of the left and right subtrees.

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
    // Function Name : CountLeaf
    // Description   : Count leaf nodes in the tree
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

    ///////////////////////////////////////////////////////////////////////////
    //
    // Function Name : CountLeaf
    // Description   : Start counting leaf nodes from first
    //
    ///////////////////////////////////////////////////////////////////////////

    public int CountLeaf()
    {
        return CountLeaf(first);
    }
}

class Tree_08
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

        int iRet = tobj.CountLeaf();

        System.out.println("Number of Leaf Nodes : " + iRet);
    }
}

/*
===============================================================================
Expected Output:
===============================================================================

Number of Leaf Nodes : 4

===============================================================================
Memory Representation:
===============================================================================

                         11
                       /    \
                      5      17
                     / \    /  \
                    4   7  15  21

Leaf Nodes:

              4       7       15       21
              |       |        |        |
            Leaf     Leaf     Leaf     Leaf

Total Leaf Nodes = 4

===============================================================================
Leaf Node Identification:
===============================================================================

A leaf node is a node whose:

lchild = NULL
rchild = NULL

For the given Binary Search Tree:

Node 4  -> Leaf
Node 7  -> Leaf
Node 15 -> Leaf
Node 21 -> Leaf

Total = 4 Leaf Nodes

===============================================================================
Counting Process:
===============================================================================

Step 1 : Start from root node 11.
Step 2 : Visit the left subtree of 11.
Step 3 : Visit node 5.
Step 4 : Visit node 4. Node 4 is a leaf node, return 1.
Step 5 : Visit node 7. Node 7 is a leaf node, return 1.
Step 6 : Visit the right subtree of 11.
Step 7 : Visit node 17.
Step 8 : Visit node 15. Node 15 is a leaf node, return 1.
Step 9 : Visit node 21. Node 21 is a leaf node, return 1.
Step 10: Add all leaf node counts.

Total = 1 + 1 + 1 + 1
      = 4

===============================================================================
Node Structure:
===============================================================================

                    +-----------+-----------+-----------+
                    |   data    |  lchild   |  rchild   |
                    +-----------+-----------+-----------+
                          |           |           |
                        Value       Address     Address

Leaf Node Structure:

                    +-----------+-----------+-----------+
                    |   data    |   NULL    |   NULL    |
                    +-----------+-----------+-----------+

===============================================================================
Algorithm:
===============================================================================

1. Start the program.
2. Define the node class with data, lchild and rchild members.
3. Define the Tree class.
4. Initialize first to NULL using the constructor.
5. Define the Insert function.
6. Insert the given elements into the Binary Search Tree.
7. Define the recursive CountLeaf function.
8. Check whether the current node is NULL.
9. If the current node is NULL, return 0.
10. Check whether lchild and rchild are both NULL.
11. If both are NULL, return 1 because the node is a leaf node.
12. Recursively count leaf nodes in the left subtree.
13. Recursively count leaf nodes in the right subtree.
14. Add both counts and return the result.
15. Call CountLeaf starting from the first node.
16. Display the number of leaf nodes.
17. Stop the program.

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
    Call CountLeaf()
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
   Return 0   Is Leaf Node?
                /     \
              Yes      No
               |        |
               v        v
           Return 1  Count Left
                        |
                        v
                    Count Right
                        |
                        v
                    Add Counts
                        |
                        v
                  Return Result
                        |
                        v
                  Display Result
                        |
                        v
                       Stop

===============================================================================
Time Complexity:
===============================================================================

Insertion : O(log n) Average
Insertion : O(n) Worst Case
CountLeaf : O(n)

===============================================================================
Space Complexity:
===============================================================================

Tree Storage    : O(n)
Recursion Stack : O(h)

Where h is the height of the Binary Search Tree.

===============================================================================
Conclusion:
===============================================================================

Program 08 demonstrates how to count the number of leaf nodes in a Binary
Search Tree using Java. The recursive CountLeaf function checks every node
and identifies a leaf node when both lchild and rchild are NULL. For the
given Binary Search Tree, the total number of leaf nodes is 4.

===============================================================================
*/
