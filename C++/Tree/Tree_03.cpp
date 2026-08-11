/*
===============================================================================
Program Name    : Binary Search Tree - Search Node 
Program Number  : 03
File Name       : Tree_03.cpp
Description     : This program implements the Search operation of a Binary
                  Search Tree using C++. The Search operation checks whether
                  a given element is present in the Binary Search Tree.

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
6. Searching

Key Learning Points:
- Understand how searching is performed in a Binary Search Tree.
- Use BST properties to decide the search direction.
- Move to the right subtree when the element is greater.
- Move to the left subtree when the element is smaller.
- Return true when the element is found and false when it is absent.

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
    bool Search(int iNo);
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

// Search Node
bool BST::Search(int iNo)
{
    struct node *temp = first;

    while(temp != NULL)
    {
        if(iNo == temp->data)
        {
            return true;
        }
        else if(iNo > temp->data)
        {
            temp = temp->rchild;
        }
        else
        {
            temp = temp->lchild;
        }
    }

    return false;
}

int main()
{
    BST bobj;

    bobj.Insert(11);
    bobj.Insert(5);
    bobj.Insert(17);
    bobj.Insert(4);
    bobj.Insert(7);

    if(bobj.Search(7) == true)
    {
        cout<<"Element Found\n";
    }
    else
    {
        cout<<"Element Not Found\n";
    }

    if(bobj.Search(21) == true)
    {
        cout<<"Element Found\n";
    }
    else
    {
        cout<<"Element Not Found\n";
    }

    return 0;
}

/*
===============================================================================
Expected Output:
===============================================================================

Element Found
Element Not Found

===============================================================================
Memory Representation:
===============================================================================

After inserting 11, 5, 17, 4 and 7:

                         first
                           |
                           ▼
                      +---------+
                      |  data 11 |
                      +---------+
                       /       \
                      /         \
                     ▼           ▼
                +---------+   +---------+
                |  data 5 |   | data 17 |
                +---------+   +---------+
                  /     \
                 /       \
                ▼         ▼
           +---------+ +---------+
           |  data 4 | |  data 7 |
           +---------+ +---------+

Search(7):

11 → 5 → 7 → Element Found

Search(21):

11 → 17 → NULL → Element Not Found

===============================================================================
Algorithm:
===============================================================================

1. Start the program.
2. Create a Binary Search Tree.
3. Insert the required elements into the BST.
4. Start searching from the root node.
5. Compare the search element with the current node.
6. If the element is equal to the current node, return true.
7. If the element is greater than the current node, move to the right child.
8. If the element is smaller than the current node, move to the left child.
9. Repeat the comparison until the element is found or the pointer becomes
   NULL.
10. If the pointer becomes NULL, return false.
11. Display the search result.
12. Stop the program.

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
                     Call Search()
                           │
                           ▼
                    Start from Root
                           │
                           ▼
                  Compare Search Value
                           │
                ┌──────────┴──────────┐
                │                     │
              Equal                Not Equal
                │                     │
                ▼                     ▼
        Return Element Found     Compare Values
                                      │
                             ┌────────┴────────┐
                             │                 │
                          Greater            Smaller
                             │                 │
                             ▼                 ▼
                       Move Right         Move Left
                             │                 │
                             └────────┬────────┘
                                      │
                                      ▼
                              Pointer == NULL?
                               /           \
                             Yes            No
                             │              │
                             ▼              │
                    Element Not Found      │
                             │              │
                             └──────┬───────┘
                                    ▼
                                  Stop

===============================================================================
Time Complexity:
===============================================================================

Search() - Best Case    : O(1)
Search() - Average Case : O(log n)
Search() - Worst Case   : O(n)

Where n is the number of nodes in the BST.

===============================================================================
Space Complexity:
===============================================================================

O(1) Auxiliary Space

O(n) Total Space for n Tree nodes.

===============================================================================
Conclusion:
===============================================================================

Program 003 implements the Search operation of a Binary Search Tree using
C++. The BST property is used to efficiently determine whether the search
element should be checked in the left or right subtree. The program
successfully identifies both present and absent elements in the BST.

===============================================================================
*/
