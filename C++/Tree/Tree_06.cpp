/*
===============================================================================
Program Name    : Binary Search Tree - Postorder Traversal
Program Number  : 06
File Name       : Tree_06.cpp 
Description     : This program implements Postorder Traversal of a Binary
                  Search Tree using C++. Postorder Traversal visits the
                  nodes in Left, Right, Data (LRD) order.

Date            : August 2026
Language        : C++
Author          : Ishwari Vijaykumar Surve
===============================================================================

Concepts Used:
1. Binary Search Tree (BST)
2. Postorder Traversal
3. Recursion
4. Class and Object
5. Self-Referential Structure
6. Pointers

Key Learning Points:
- Understand Postorder Traversal of a Binary Search Tree.
- Learn the LRD traversal technique.
- Understand recursive traversal of Tree nodes.
- Learn how the root node is processed after its subtrees.
- Understand the use of a wrapper function for traversal.

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

    void Postorder(struct node *first);
    void Display();
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

// Postorder Traversal
// L R D
void BST::Postorder(struct node *first)
{
    if(first != NULL)
    {
        Postorder(first->lchild);

        Postorder(first->rchild);

        cout<<first->data<<"\n";
    }
}

// Wrapper Function
void BST::Display()
{
    Postorder(first);
}

int main()
{
    BST bobj;

    bobj.Insert(11);
    bobj.Insert(5);
    bobj.Insert(17);
    bobj.Insert(4);
    bobj.Insert(7);
    bobj.Insert(15);
    bobj.Insert(21);

    cout<<"Postorder Traversal :\n";

    bobj.Display();

    return 0;
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

Postorder Traversal: Left → Right → Data

Traversal Sequence:

4 → 7 → 5 → 15 → 21 → 17 → 11

===============================================================================
Algorithm:
===============================================================================

1. Start the program.
2. Create a Binary Search Tree.
3. Insert the required elements into the BST.
4. Call the Display() function.
5. Display() calls the Postorder() function with the root node.
6. In Postorder(), recursively visit the left subtree.
7. Recursively visit the right subtree.
8. Display the data of the current node.
9. Continue the process until all nodes are visited.
10. Stop the program.

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
                     Call Display()
                           │
                           ▼
                   Call Postorder()
                           │
                           ▼
                  Traverse Left Subtree
                           │
                           ▼
                 Traverse Right Subtree
                           │
                           ▼
                    Display Node Data
                           │
                           ▼
                    All Nodes Visited?
                       /          \
                     No            Yes
                     │              │
                     └─── Repeat    ▼
                                  Stop

===============================================================================
Time Complexity:
===============================================================================

Insert() - Best Case    : O(1)
Insert() - Average Case : O(log n)
Insert() - Worst Case   : O(n)

Postorder() - Best Case   : O(n)
Postorder() - Average Case: O(n)
Postorder() - Worst Case  : O(n)

Where n is the number of nodes in the BST.

===============================================================================
Space Complexity:
===============================================================================

Postorder() Auxiliary Space : O(h)

Where h is the height of the Tree.

For a balanced Tree : O(log n)
For a skewed Tree   : O(n)

Total Space : O(n)

===============================================================================
Conclusion:
===============================================================================

Program 006 implements Postorder Traversal of a Binary Search Tree using
C++. The traversal follows the Left, Right, Data (LRD) order. The left
subtree and right subtree are processed before the current node. Recursion
is used to traverse the complete Tree.

===============================================================================
*/
