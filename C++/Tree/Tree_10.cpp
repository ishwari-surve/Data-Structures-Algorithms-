/*
===============================================================================
Program Name    : Complete Binary Search Tree Application
Program Number  : 10
File Name       : Tree_10.cpp
Description     : This program implements a complete Binary Search Tree
                  application using C++. It performs insertion, searching,
                  Inorder, Preorder, Postorder traversal, and counts total,
                  leaf, and parent nodes.

Date            : August 2026
Language        : C++
Author          : Ishwari Vijaykumar Surve
===============================================================================

Concepts Used:
1. Binary Search Tree (BST)
2. Node Insertion
3. Searching
4. Inorder Traversal
5. Preorder Traversal
6. Postorder Traversal
7. Recursion
8. Counting Total Nodes
9. Counting Leaf Nodes
10. Counting Parent Nodes
11. Class and Object
12. Self-Referential Structure
13. Dynamic Memory Allocation
14. Pointers

Key Learning Points:
- Understand the complete structure of a Binary Search Tree.
- Learn how to insert elements into a BST.
- Understand searching using BST properties.
- Implement Inorder, Preorder, and Postorder traversals.
- Count total nodes, leaf nodes, and parent nodes.
- Understand recursive Tree operations.
- Use wrapper functions to access recursive operations.

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

    void Inorder(struct node *first);
    void Preorder(struct node *first);
    void Postorder(struct node *first);

    int Count(struct node *first);
    int CountLeaf(struct node *first);
    int CountParent(struct node *first);

    void DisplayInorder();
    void DisplayPreorder();
    void DisplayPostorder();

    int CountNode();
    int CountLeafNode();
    int CountParentNode();
};

BST::BST()
{
    first = NULL;
}

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

void BST::Inorder(struct node *first)
{
    if(first != NULL)
    {
        Inorder(first->lchild);
        cout<<first->data<<"\n";
        Inorder(first->rchild);
    }
}

void BST::Preorder(struct node *first)
{
    if(first != NULL)
    {
        cout<<first->data<<"\n";
        Preorder(first->lchild);
        Preorder(first->rchild);
    }
}

void BST::Postorder(struct node *first)
{
    if(first != NULL)
    {
        Postorder(first->lchild);
        Postorder(first->rchild);
        cout<<first->data<<"\n";
    }
}

int BST::Count(struct node *first)
{
    if(first == NULL)
    {
        return 0;
    }

    return Count(first->lchild) +
           Count(first->rchild) + 1;
}

int BST::CountLeaf(struct node *first)
{
    if(first == NULL)
    {
        return 0;
    }

    if((first->lchild == NULL) &&
       (first->rchild == NULL))
    {
        return 1;
    }

    return CountLeaf(first->lchild) +
           CountLeaf(first->rchild);
}

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

void BST::DisplayInorder()
{
    Inorder(first);
}

void BST::DisplayPreorder()
{
    Preorder(first);
}

void BST::DisplayPostorder()
{
    Postorder(first);
}

int BST::CountNode()
{
    return Count(first);
}

int BST::CountLeafNode()
{
    return CountLeaf(first);
}

int BST::CountParentNode()
{
    return CountParent(first);
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

    cout<<"Inorder Traversal\n";
    bobj.DisplayInorder();

    cout<<"\nPreorder Traversal\n";
    bobj.DisplayPreorder();

    cout<<"\nPostorder Traversal\n";
    bobj.DisplayPostorder();

    cout<<"\nTotal Nodes : "<<bobj.CountNode()<<endl;
    cout<<"Leaf Nodes : "<<bobj.CountLeafNode()<<endl;
    cout<<"Parent Nodes : "<<bobj.CountParentNode()<<endl;

    if(bobj.Search(15))
    {
        cout<<"Element Found\n";
    }

    return 0;
}

/*
===============================================================================
Expected Output:
===============================================================================

Inorder Traversal
4
5
7
11
15
17
21

Preorder Traversal
11
5
4
7
17
15
21

Postorder Traversal
4
7
5
15
21
17
11

Total Nodes : 7
Leaf Nodes : 4
Parent Nodes : 3
Element Found

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

Inorder   : 4 → 5 → 7 → 11 → 15 → 17 → 21
Preorder  : 11 → 5 → 4 → 7 → 17 → 15 → 21
Postorder : 4 → 7 → 5 → 15 → 21 → 17 → 11

Total Nodes  : 7
Leaf Nodes   : 4
Parent Nodes : 3

===============================================================================
Algorithm:
===============================================================================

1. Start the program.
2. Create a Binary Search Tree object.
3. Insert the elements into the BST.
4. For insertion, compare each element with the current node.
5. Insert smaller elements into the left subtree.
6. Insert larger elements into the right subtree.
7. Reject duplicate elements.
8. Perform Inorder Traversal using recursion.
9. Perform Preorder Traversal using recursion.
10. Perform Postorder Traversal using recursion.
11. Count the total number of nodes recursively.
12. Identify and count leaf nodes.
13. Identify and count parent nodes.
14. Search for the required element using BST properties.
15. Display all results.
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
                 ┌─────────┴─────────┐
                 │                   │
                 ▼                   ▼
          Inorder Traversal    Preorder Traversal
                 │                   │
                 └─────────┬─────────┘
                           │
                           ▼
                   Postorder Traversal
                           │
                           ▼
                     Count Nodes
                           │
                           ▼
                  Count Leaf Nodes
                           │
                           ▼
                 Count Parent Nodes
                           │
                           ▼
                       Search
                           │
                           ▼
                    Display Results
                           │
                           ▼
                          Stop

===============================================================================
Time Complexity:
===============================================================================

Insert() - Best Case    : O(1)
Insert() - Average Case : O(log n)
Insert() - Worst Case   : O(n)

Search() - Best Case    : O(1)
Search() - Average Case : O(log n)
Search() - Worst Case   : O(n)

Inorder()   : O(n)
Preorder()  : O(n)
Postorder() : O(n)

Count()       : O(n)
CountLeaf()   : O(n)
CountParent() : O(n)

Where n is the number of nodes in the BST.

===============================================================================
Space Complexity:
===============================================================================

Recursive Traversal Auxiliary Space : O(h)

Where h is the height of the Tree.

For a balanced Tree : O(log n)
For a skewed Tree   : O(n)

Total Space : O(n)

===============================================================================
Conclusion:
===============================================================================

Program 010 implements a complete Binary Search Tree application using
C++. It combines insertion, searching, three standard Tree traversals,
and Tree analysis operations such as counting total nodes, leaf nodes,
and parent nodes. This program provides a complete understanding of
fundamental Binary Search Tree operations and recursive Tree processing.

===============================================================================
*/
