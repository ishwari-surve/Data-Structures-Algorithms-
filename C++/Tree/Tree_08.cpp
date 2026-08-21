/*
===============================================================================
Program Name    : Binary Search Tree - Count Leaf Nodes 
Program Number  : 08
File Name       : Tree_08.cpp
Description     : This program counts the total number of leaf nodes present
                  in a Binary Search Tree using recursive traversal.

Date            : August 2026
Language        : C++
Author          : Ishwari Vijaykumar Surve
===============================================================================

Concepts Used:
1. Binary Search Tree (BST)
2. Leaf Node
3. Recursion
4. Tree Traversal
5. Class and Object
6. Self-Referential Structure
7. Dynamic Memory Allocation
8. Pointers

Key Learning Points:
- Understand the concept of a leaf node.
- Learn how to count leaf nodes in a Binary Search Tree.
- Understand recursive traversal of a Tree.
- Identify a leaf node using its left and right child pointers.
- Understand the use of a wrapper function.

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
    int CountLeaf(struct node *first);
    int CountLeafNode();
};

// Constructor
BST::BST()
{
    first = NULL;
}

// Insert Node
BST::Insert(int iNo)
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

// Count Leaf Nodes
int BST::CountLeaf(struct node *first)
{
    if(first == NULL)
    {
        return 0;
    }

    if((first->lchild == NULL) && (first->rchild == NULL))
    {
        return 1;
    }

    return CountLeaf(first->lchild) +
           CountLeaf(first->rchild);
}

// Wrapper Function
int BST::CountLeafNode()
{
    return CountLeaf(first);
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

    iRet = bobj.CountLeafNode();

    cout<<"Leaf Nodes : "<<iRet<<endl;

    return 0;
}

/*
===============================================================================
Expected Output:
===============================================================================

Leaf Nodes : 4

===============================================================================
Memory Representation:
===============================================================================

                         first
                           |
                           ▼
                       +-------+
                       |  11   |
                       +---+---+
                          / \
                         /   \
                        ▼     ▼
                    +-----+ +-----+
                    |  5  | | 17  |
                    +--+--+ +--+--+
                      / \     / \
                     /   \   /   \
                    ▼     ▼ ▼     ▼
                  +---+ +---+ +---+ +---+
                  | 4 | | 7 | |15 | |21 |
                  +---+ +---+ +---+ +---+

Leaf Nodes:
4, 7, 15, 21

Total Leaf Nodes = 4

===============================================================================
Algorithm:
===============================================================================

1. Start the program.
2. Create a Binary Search Tree object.
3. Insert the required elements into the BST.
4. Call CountLeafNode().
5. CountLeafNode() calls CountLeaf() with the root node.
6. Check whether the current node is NULL.
7. If the node is NULL, return 0.
8. Check whether both left and right child pointers are NULL.
9. If both are NULL, the current node is a leaf node.
10. Return 1 for the leaf node.
11. Recursively count leaf nodes in the left subtree.
12. Recursively count leaf nodes in the right subtree.
13. Add the results from both subtrees.
14. Display the total number of leaf nodes.
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
                 Call CountLeafNode()
                           │
                           ▼
                    Call CountLeaf()
                           │
                           ▼
                     Is Node NULL?
                      /          \
                    Yes           No
                    │              │
                    ▼              ▼
                  Return 0   Is Leaf Node?
                              /        \
                            Yes         No
                            │            │
                            ▼            ▼
                         Return 1   Count Left
                                      +
                                  Count Right
                                       │
                                       ▼
                              Return Total Count
                                       │
                                       ▼
                              Display Leaf Nodes
                                       │
                                       ▼
                                      Stop

===============================================================================
Time Complexity:
===============================================================================

Insert() - Best Case    : O(1)
Insert() - Average Case : O(log n)
Insert() - Worst Case   : O(n)

CountLeaf() - Best Case    : O(n)
CountLeaf() - Average Case : O(n)
CountLeaf() - Worst Case   : O(n)

Where n is the number of nodes in the BST.

===============================================================================
Space Complexity:
===============================================================================

CountLeaf() Auxiliary Space : O(h)

Where h is the height of the Tree.

For a balanced Tree : O(log n)
For a skewed Tree   : O(n)

Total Space : O(n)

===============================================================================
Conclusion:
===============================================================================

Program 008 counts the total number of leaf nodes in a Binary Search Tree
using recursion. A node is considered a leaf node when both its left and
right child pointers are NULL. The program recursively examines every
node and calculates the total number of leaf nodes present in the Tree.

===============================================================================
*/
