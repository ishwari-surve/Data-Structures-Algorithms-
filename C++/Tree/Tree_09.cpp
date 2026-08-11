/*
===============================================================================
Program Name    : Binary Search Tree - Count Parent Nodes
Program Number  : 09
File Name       : Tree_09.cpp
Description     : This program counts the total number of parent nodes
                  present in a Binary Search Tree using recursive traversal.

Date            : August 2026
Language        : C++
Author          : Ishwari Vijaykumar Surve
===============================================================================

Concepts Used:
1. Binary Search Tree (BST)
2. Parent Node
3. Recursion
4. Tree Traversal
5. Class and Object
6. Self-Referential Structure
7. Dynamic Memory Allocation
8. Pointers

Key Learning Points:
- Understand the concept of a parent node.
- Learn how to count parent nodes in a Binary Search Tree.
- Identify a parent node using its child pointers.
- Understand recursive traversal of a Tree.
- Learn how to combine results from left and right subtrees.

===============================================================================
*/

#include<iostream>
using namespace std;

#pragma pack(1)

struct node
{
    int data;
    struct node *lchild;
    struct node *rchild;
};

class BST
{
private:
    struct node *first;

public:
    BST();
    void Insert(int iNo);
    int CountParent(struct node *first);
    int CountParentNode();
};

// Constructor
BST::BST()
{
    first = NULL;
}

// Insert Node
void BST::Insert(int iNo)
{
    struct node *newn = NULL;
    struct node *temp = NULL;

    newn = new node;

    newn->data = iNo;
    newn->lchild = NULL;
    newn->rchild = NULL;

    if(first == NULL)
    {
        first = newn;
    }
    else
    {
        temp = first;

        while(1)
        {
            if(iNo > temp->data)
            {
                if(temp->rchild == NULL)
                {
                    temp->rchild = newn;
                    break;
                }

                temp = temp->rchild;
            }
            else if(iNo < temp->data)
            {
                if(temp->lchild == NULL)
                {
                    temp->lchild = newn;
                    break;
                }

                temp = temp->lchild;
            }
            else
            {
                cout<<"Duplicate element not allowed\n";
                delete newn;
                break;
            }
        }
    }
}

// Count Parent Nodes
int BST::CountParent(struct node *first)
{
    if(first == NULL)
    {
        return 0;
    }

    if(first->lchild != NULL || first->rchild != NULL)
    {
        return 1 +
               CountParent(first->lchild) +
               CountParent(first->rchild);
    }

    return 0;
}

// Wrapper Function
int BST::CountParentNode()
{
    return CountParent(first);
}

int main()
{
    BST bobj;
    int iRet = 0;

    bobj.Insert(11);
    bobj.Insert(5);
    bobj.Insert(17);
    bobj.Insert(4);
    bobj.Insert(7);
    bobj.Insert(15);
    bobj.Insert(21);

    iRet = bobj.CountParentNode();

    cout<<"Parent Nodes : "<<iRet<<endl;

    return 0;
}

/*
===============================================================================
Expected Output:
===============================================================================

Parent Nodes : 3

===============================================================================
Memory Representation:
===============================================================================

                         first
                           |
                           ▼
                       +-------+
                       |  11   |  ← Parent
                       +---+---+
                          / \
                         /   \
                        ▼     ▼
                    +-----+ +-----+
                    |  5  | | 17  |  ← Parent
                    +--+--+ +--+--+
                      / \     / \
                     /   \   /   \
                    ▼     ▼ ▼     ▼
                  +---+ +---+ +---+ +---+
                  | 4 | | 7 | |15 | |21 |
                  +---+ +---+ +---+ +---+
                    ↑      ↑    ↑     ↑
                  Leaf   Leaf  Leaf   Leaf

Parent Nodes:
11, 5, 17

Total Parent Nodes = 3

===============================================================================
Algorithm:
===============================================================================

1. Start the program.
2. Create a Binary Search Tree object.
3. Insert the required elements into the BST.
4. Call CountParentNode().
5. CountParentNode() calls CountParent() with the root node.
6. Check whether the current node is NULL.
7. If the node is NULL, return 0.
8. Check whether the current node has a left child or right child.
9. If at least one child exists, consider the current node as a parent node.
10. Add 1 for the current parent node.
11. Recursively count parent nodes in the left subtree.
12. Recursively count parent nodes in the right subtree.
13. Return the total count.
14. Display the number of parent nodes.
15. Stop the program.

===============================================================================
Program Flow:
===============================================================================

                         Start
                           │
                           ▼
                    Create BST Object
                           │
                           ▼
                    Insert BST Nodes
                           │
                           ▼
                 Call CountParentNode()
                           │
                           ▼
                    Call CountParent()
                           │
                           ▼
                     Is Node NULL?
                      /          \
                    Yes           No
                    │              │
                    ▼              ▼
                  Return 0   Has Child Node?
                              /        \
                            Yes         No
                            │            │
                            ▼            ▼
                       Count Node     Return 0
                            │
                            ▼
                    Count Left Subtree
                            │
                            ▼
                   Count Right Subtree
                            │
                            ▼
                      Return Total
                            │
                            ▼
                   Display Parent Nodes
                            │
                            ▼
                           Stop

===============================================================================
Time Complexity:
===============================================================================

Insert() - Best Case    : O(1)
Insert() - Average Case : O(log n)
Insert() - Worst Case   : O(n)

CountParent() - Best Case    : O(n)
CountParent() - Average Case : O(n)
CountParent() - Worst Case   : O(n)

Where n is the number of nodes in the BST.

===============================================================================
Space Complexity:
===============================================================================

CountParent() Auxiliary Space : O(h)

Where h is the height of the Tree.

For a balanced Tree : O(log n)
For a skewed Tree   : O(n)

Total Space : O(n)

===============================================================================
Conclusion:
===============================================================================

Program 009 counts the total number of parent nodes in a Binary Search
Tree using recursion. A node is considered a parent node if it has at
least one child. The program recursively traverses the Tree and counts
all nodes that have either a left child or a right child.

===============================================================================
*/
