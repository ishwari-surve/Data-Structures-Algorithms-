/*
===============================================================================
Program Name    : Binary Search Tree - Count Parent Nodes
Program Number  : 09
File Name       : Tree_09.java 

Description     : This program demonstrates how to count the number of parent
                  nodes in a Binary Search Tree using Java. A parent node is
                  a node which has at least one child. The program uses
                  recursion to count all parent nodes.

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
9. Parent Node
10. Function Overloading

Key Learning Points:
- Understand the concept of a parent node in a Binary Search Tree.
- A parent node has at least one child.
- Learn how recursion is used to count parent nodes.
- Return 0 when the current node is NULL.
- Check whether lchild or rchild is not NULL.
- Add 1 for every parent node found.
- Recursively count parent nodes from the left and right subtrees.

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
    // Function Name : CountParent
    // Description   : Count parent nodes in the tree
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

    ///////////////////////////////////////////////////////////////////////////
    //
    // Function Name : CountParent
    // Description   : Start counting parent nodes from first
    //
    ///////////////////////////////////////////////////////////////////////////

    public int CountParent()
    {
        return CountParent(first);
    }
}

class Tree_09
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

        int iRet = tobj.CountParent();

        System.out.println("Number of Parent Nodes : " + iRet);
    }
}

/*
===============================================================================
Expected Output:
===============================================================================

Number of Parent Nodes : 3

===============================================================================
Memory Representation:
===============================================================================

                         11
                       /    \
                      5      17
                     / \    /  \
                    4   7  15  21

Parent Nodes:

                         11
                       /    \
                      5      17
                     / \    /  \
                    4   7  15  21
                    |   |  |    |
                  Leaf Leaf Leaf Leaf

Parent Nodes = 11, 5, 17

Total Parent Nodes = 3

===============================================================================
Parent Node Identification:
===============================================================================

A parent node is a node which has at least one child.

Node 11 -> Parent
Node 5  -> Parent
Node 17 -> Parent
Node 4  -> Leaf
Node 7  -> Leaf
Node 15 -> Leaf
Node 21 -> Leaf

Total Parent Nodes = 3

===============================================================================
Counting Process:
===============================================================================

Step 1 : Start from root node 11.
Step 2 : Check node 11.
Step 3 : Node 11 has left and right children, so count = 1.
Step 4 : Visit left subtree of 11.
Step 5 : Check node 5.
Step 6 : Node 5 has left and right children, so count = 1.
Step 7 : Visit nodes 4 and 7.
Step 8 : Nodes 4 and 7 are leaf nodes, so their count is 0.
Step 9 : Visit right subtree of 11.
Step 10: Check node 17.
Step 11: Node 17 has left and right children, so count = 1.
Step 12: Visit nodes 15 and 21.
Step 13: Nodes 15 and 21 are leaf nodes, so their count is 0.
Step 14: Add all parent node counts.

Total = 1 + 1 + 1
      = 3

===============================================================================
Node Structure:
===============================================================================

                    +-----------+-----------+-----------+
                    |   data    |  lchild   |  rchild   |
                    +-----------+-----------+-----------+
                          |           |           |
                        Value       Address     Address

Parent Node:

                    +-----------+-----------+-----------+
                    |   data    |  Address   |  Address  |
                    +-----------+-----------+-----------+

Leaf Node:

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
7. Define the recursive CountParent function.
8. Check whether the current node is NULL.
9. If the current node is NULL, return 0.
10. Check whether the current node has at least one child.
11. If lchild or rchild is not NULL, count the current node as a parent.
12. Recursively count parent nodes in the left subtree.
13. Recursively count parent nodes in the right subtree.
14. Add all parent node counts.
15. Call CountParent starting from the first node.
16. Display the number of parent nodes.
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
   Call CountParent()
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
   Return 0   Has Child?
                /     \
              No       Yes
               |        |
               v        v
           Return 0   Count 1
                         |
                         v
                  Count Left Child
                         |
                         v
                 Count Right Child
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

Insertion     : O(log n) Average
Insertion     : O(n) Worst Case
CountParent   : O(n)

===============================================================================
Space Complexity:
===============================================================================

Tree Storage    : O(n)
Recursion Stack : O(h)

Where h is the height of the Binary Search Tree.

===============================================================================
Conclusion:
===============================================================================

Program 09 demonstrates how to count the number of parent nodes in a Binary
Search Tree using Java. A parent node is identified when it has at least one
child. The recursive CountParent function checks every node and calculates
the total number of parent nodes. For the given Binary Search Tree, the
total number of parent nodes is 3.

===============================================================================
*/
