/*
=============================================================================== 
Program Name    : Binary Search Tree - Height Calculation
Program Number  : 11
File Name       : Tree_11.cpp 
Description     : This program calculates the height of a Binary Search Tree
                  using recursion. The height is calculated by finding the
                  maximum height of the left and right subtrees.

Date            : August 2026
Language        : C++
Author          : Ishwari Vijaykumar Surve
===============================================================================

Concepts Used:
1. Binary Search Tree (BST)
2. Node Insertion
3. Recursion
4. Height of Tree
5. Class and Object
6. Self-Referential Structure
7. Dynamic Memory Allocation
8. Pointers
9. Wrapper Function

Key Learning Points:
- Understand the height of a Binary Search Tree.
- Learn how to calculate Tree height recursively.
- Find the height of left and right subtrees.
- Select the maximum subtree height.
- Understand recursive Tree processing.
- Use a wrapper function to calculate height.

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

    int Height(struct node *first);
    int CalculateHeight();
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

// Calculate Height
int BST::Height(struct node *first)
{
    int iLeftHeight = 0;
    int iRightHeight = 0;

    if(first == NULL)
    {
        return 0;
    }

    iLeftHeight = Height(first->lchild);
    iRightHeight = Height(first->rchild);

    if(iLeftHeight > iRightHeight)
    {
        return iLeftHeight + 1;
    }
    else
    {
        return iRightHeight + 1;
    }
}

// Wrapper Function
int BST::CalculateHeight()
{
    return Height(first);
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

    iRet = bobj.CalculateHeight();

    cout<<"Height of BST is : "<<iRet<<endl;

    return 0;
}

/*
===============================================================================
Expected Output:
===============================================================================

Height of BST is : 3

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

Level 1 : 11
Level 2 : 5, 17
Level 3 : 4, 7, 15, 21

Height of BST = 3

===============================================================================
Algorithm:
===============================================================================

1. Start the program.
2. Create a Binary Search Tree object.
3. Initialize first to NULL.
4. Insert the elements into the BST.
5. Compare each element with the current node.
6. Insert smaller elements into the left subtree.
7. Insert larger elements into the right subtree.
8. Call CalculateHeight().
9. CalculateHeight() calls the recursive Height() function.
10. If the current node is NULL, return 0.
11. Recursively calculate the height of the left subtree.
12. Recursively calculate the height of the right subtree.
13. Compare the left and right subtree heights.
14. Return the greater height plus 1.
15. Display the height of the BST.
16. Stop the program.

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
                  Call CalculateHeight()
                           │
                           ▼
                     Height(first)
                           │
                           ▼
                ┌──────────┴──────────┐
                │                     │
                ▼                     ▼
        Calculate Left         Calculate Right
           Height                 Height
                │                     │
                └──────────┬──────────┘
                           │
                           ▼
                 Compare Both Heights
                           │
                           ▼
                Select Maximum Height
                           │
                           ▼
                     Add 1 to Height
                           │
                           ▼
                  Display BST Height
                           │
                           ▼
                          Stop

===============================================================================
Time Complexity:
===============================================================================

Insert() - Best Case    : O(1)
Insert() - Average Case : O(log n)
Insert() - Worst Case   : O(n)

Height() : O(n)

CalculateHeight() : O(n)

Where n is the number of nodes in the BST.

===============================================================================
Space Complexity:
===============================================================================

Recursive Height() Auxiliary Space : O(h)

Where h is the height of the Tree.

For a balanced Tree : O(log n)
For a skewed Tree   : O(n)

Total Tree Space : O(n)

===============================================================================
Conclusion:
===============================================================================

Program 011 calculates the height of a Binary Search Tree using recursion.
The program recursively calculates the height of the left and right
subtrees and selects the greater height. One is then added to represent
the current node. This program helps in understanding recursive Tree
processing and the concept of Tree height.

===============================================================================
*/
