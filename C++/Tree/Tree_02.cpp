/*
===============================================================================
Program Name    : Binary Search Tree - Insert Node
Program Number  : 02
File Name       : Tree_02.cpp
Description     : This program implements the Insert operation of a Binary
                  Search Tree using C++. A new node is dynamically created
                  and inserted at its appropriate position according to
                  Binary Search Tree properties.

Date            : August 2026
Language        : C++
Author          : Ishwari Vijaykumar Surve
===============================================================================

Concepts Used:
1. Binary Search Tree (BST)
2. Class and Object
3. Self-Referential Structure
4. Dynamic Memory Allocation
5. Pointers
6. Node Insertion

Key Learning Points:
- Understand how a node is inserted into a Binary Search Tree.
- Learn the difference between left and right subtree insertion.
- Understand dynamic creation of Tree nodes.
- Handle duplicate elements in a BST.
- Understand traversal of a BST while searching for the insertion position.

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
};

// Constructor
BST::BST()
{
    first = NULL;
}

// Insert
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

int main()
{
    BST bobj;

    bobj.Insert(11);
    bobj.Insert(5);
    bobj.Insert(17);
    bobj.Insert(4);
    bobj.Insert(7);

    cout<<"Nodes inserted successfully into BST\n";

    return 0;
}

/*
===============================================================================
Expected Output:
===============================================================================

Nodes inserted successfully into BST

===============================================================================
Memory Representation:
===============================================================================

After inserting 11, 5, 17, 4 and 7:

                    BST Object
                +---------------+
                | first --------|----------------+
                +---------------+                |
                                                 ▼
                                            +---------+
                                            | data 11 |
                                            |   / \   |
                                            +--/---\--+
                                              /     \
                                             ▼       ▼
                                       +---------+ +---------+
                                       | data 5  | | data 17 |
                                       |  /  \   | |  NULL   |
                                       +-/----\--+ +---------+
                                        /      \
                                       ▼        ▼
                                  +---------+ +---------+
                                  | data 4  | | data 7  |
                                  | NULL    | | NULL    |
                                  +---------+ +---------+

BST Property:
Left child  <  Parent  <  Right child

===============================================================================
Algorithm:
===============================================================================

1. Start the program.
2. Create a BST object.
3. Create a new node dynamically.
4. Store the given element in the data member.
5. Set lchild and rchild to NULL.
6. Check whether the BST is empty.
7. If the BST is empty, make the new node the root node.
8. Otherwise, start from the root node.
9. Compare the new element with the current node.
10. If the element is greater, move to the right subtree.
11. If the element is smaller, move to the left subtree.
12. If the appropriate child pointer is NULL, insert the new node there.
13. If the element is equal to an existing node, reject the duplicate element.
14. Repeat the process until the node is inserted.
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
                     Call Insert()
                           │
                           ▼
                    Create New Node
                           │
                           ▼
                    Is BST Empty?
                     /          \
                   Yes           No
                   │              │
                   ▼              ▼
              Make Node       Compare Element
               as Root             │
                                   ▼
                         ┌─────────┴─────────┐
                         │                   │
                    Greater               Smaller
                         │                   │
                         ▼                   ▼
                  Move Right            Move Left
                         │                   │
                         └─────────┬─────────┘
                                   │
                                   ▼
                          Is Child NULL?
                           /          \
                         Yes           No
                         │              │
                         ▼              ▼
                    Insert Node      Continue
                         │           Traversal
                         │              │
                         └──────┬───────┘
                                │
                                ▼
                         Duplicate Check
                                │
                                ▼
                              Stop

===============================================================================
Time Complexity:
===============================================================================

Insert() - Best Case    : O(1)
Insert() - Average Case : O(log n)
Insert() - Worst Case   : O(n)

Where n is the number of nodes in the BST.

===============================================================================
Space Complexity:
===============================================================================

O(1) Auxiliary Space

O(n) Total Space for n dynamically allocated Tree nodes.

===============================================================================
Conclusion:
===============================================================================

Program 002 implements the Insert operation of a Binary Search Tree using
C++. A new node is dynamically created and placed at its appropriate
position according to the BST property. Elements smaller than the current
node are inserted into the left subtree, while greater elements are
inserted into the right subtree. Duplicate elements are not allowed.

===============================================================================
*/
