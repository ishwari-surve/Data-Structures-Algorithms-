/*
===============================================================================
Program Name    : Binary Search Tree - Count Total Nodes
Program Number  : 07
File Name       : Tree_07.cpp 
Description     : This program counts the total number of nodes present in
                  a Binary Search Tree using recursive traversal.

Date            : August 2026
Language        : C++
Author          : Ishwari Vijaykumar Surve
===============================================================================

Concepts Used:
1. Binary Search Tree (BST)
2. Recursion
3. Tree Traversal
4. Class and Object
5. Self-Referential Structure
6. Dynamic Memory Allocation
7. Pointers

Key Learning Points:
- Understand how to count all nodes in a Binary Search Tree.
- Learn recursive traversal of a Tree.
- Understand the base condition of recursion.
- Learn how results from left and right subtrees are combined.
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
    int Count(struct node *first);
    int CountNode();
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

// Count Total Nodes
int BST::Count(struct node *first)
{
    if(first == NULL)
    {
        return 0;
    }

    return Count(first->lchild) +
           Count(first->rchild) + 1;
}

// Wrapper Function
int BST::CountNode()
{
    return Count(first);
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

    iRet = bobj.CountNode();

    cout<<"Total Nodes : "<<iRet<<endl;

    return 0;
}

/*
===============================================================================
Expected Output:
===============================================================================

Total Nodes : 7

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

Total Nodes = 7

===============================================================================
Algorithm:
===============================================================================

1. Start the program.
2. Create a Binary Search Tree object.
3. Insert the required elements into the BST.
4. Call CountNode().
5. CountNode() calls Count() with the root node.
6. Check whether the current node is NULL.
7. If the node is NULL, return 0.
8. Recursively count the nodes in the left subtree.
9. Recursively count the nodes in the right subtree.
10. Add 1 for the current node.
11. Return the total count.
12. Display the total number of nodes.
13. Stop the program.

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
                   Call CountNode()
                           │
                           ▼
                     Call Count()
                           │
                           ▼
                     Is Node NULL?
                      /          \
                    Yes           No
                    │              │
                    ▼              ▼
                  Return 0    Count Left Subtree
                                   │
                                   ▼
                             Count Right Subtree
                                   │
                                   ▼
                          Add 1 for Current Node
                                   │
                                   ▼
                            Return Total Count
                                   │
                                   ▼
                           Display Total Nodes
                                   │
                                   ▼
                                  Stop

===============================================================================
Time Complexity:
===============================================================================

Insert() - Best Case    : O(1)
Insert() - Average Case : O(log n)
Insert() - Worst Case   : O(n)

Count() - Best Case     : O(n)
Count() - Average Case  : O(n)
Count() - Worst Case    : O(n)

Where n is the number of nodes in the BST.

===============================================================================
Space Complexity:
===============================================================================

Count() Auxiliary Space : O(h)

Where h is the height of the Tree.

For a balanced Tree : O(log n)
For a skewed Tree   : O(n)

Total Space : O(n)

===============================================================================
Conclusion:
===============================================================================

Program 007 counts the total number of nodes present in a Binary Search
Tree using recursion. The Count() function recursively visits the left
and right subtrees and adds one for the current node. This demonstrates
how recursive Tree traversal can be used to calculate Tree properties.

===============================================================================
*/
