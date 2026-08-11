/*
===============================================================================
Program Name    : Binary Search Tree - Inorder Traversal
Program Number  : 04 
File Name       : Tree_04.cpp
Description     : This program implements Inorder Traversal of a Binary
                  Search Tree using C++. Inorder Traversal visits the
                  nodes in Left, Data, Right (LDR) order.

Date            : August 2026
Language        : C++
Author          : Ishwari Vijaykumar Surve
===============================================================================

Concepts Used:
1. Binary Search Tree (BST)
2. Inorder Traversal
3. Recursion
4. Class and Object
5. Self-Referential Structure
6. Pointers

Key Learning Points:
- Understand Inorder Traversal of a Binary Search Tree.
- Learn the LDR traversal technique.
- Understand recursive traversal of Tree nodes.
- Learn how Inorder Traversal displays BST elements in sorted order.
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
    void Inorder(struct node *first);
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

// Inorder Traversal
// L D R
void BST::Inorder(struct node *first)
{
    if(first != NULL)
    {
        Inorder(first->lchild);

        cout<<first->data<<"\n";

        Inorder(first->rchild);
    }
}

// Wrapper Function
void BST::Display()
{
    Inorder(first);
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

    cout<<"Inorder Traversal :\n";

    bobj.Display();

    return 0;
}

/*
===============================================================================
Expected Output:
===============================================================================

Inorder Traversal :
4
5
7
11
15
17
21

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

Inorder Traversal: Left → Data → Right

Traversal Sequence:

4 → 5 → 7 → 11 → 15 → 17 → 21

===============================================================================
Algorithm:
===============================================================================

1. Start the program.
2. Create a Binary Search Tree.
3. Insert the required elements into the BST.
4. Call the Display() function.
5. Display() calls the Inorder() function with the root node.
6. In Inorder(), first visit the left subtree.
7. Display the data of the current node.
8. Visit the right subtree.
9. Continue the process recursively until all nodes are visited.
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
                    Call Inorder()
                           │
                           ▼
                  Traverse Left Subtree
                           │
                           ▼
                    Display Node Data
                           │
                           ▼
                 Traverse Right Subtree
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

Inorder() - Best Case   : O(n)
Inorder() - Average Case: O(n)
Inorder() - Worst Case  : O(n)

Where n is the number of nodes in the BST.

===============================================================================
Space Complexity:
===============================================================================

Inorder() Auxiliary Space : O(h)

Where h is the height of the Tree.

For a balanced Tree : O(log n)
For a skewed Tree   : O(n)

Total Space : O(n)

===============================================================================
Conclusion:
===============================================================================

Program 004 implements Inorder Traversal of a Binary Search Tree using
C++. The traversal follows the Left, Data, Right (LDR) order. In a Binary
Search Tree, Inorder Traversal visits the elements in ascending sorted
order. Recursion is used to traverse both the left and right subtrees.

===============================================================================
*/
