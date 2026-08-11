/*
===============================================================================
Program Name    : Binary Search Tree - Complete Menu Driven Application
Program Number  : 12
File Name       : Tree_12.cpp
Description     : This program implements a complete menu-driven Binary Search
                  Tree (BST) application. It supports insertion, searching,
                  tree traversals, node counting, and height calculation.

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
6. Recursion
7. Inorder Traversal
8. Preorder Traversal
9. Postorder Traversal
10. Searching
11. Node Counting
12. Leaf Node Counting
13. Parent Node Counting
14. Height Calculation
15. Menu Driven Application
16. Switch Case

Key Learning Points:
- Understand the complete structure of a Binary Search Tree.
- Insert elements according to BST properties.
- Search elements efficiently in a BST.
- Perform Inorder, Preorder and Postorder traversals.
- Count total nodes, leaf nodes and parent nodes.
- Calculate the height of the BST recursively.
- Understand the use of wrapper functions.
- Implement multiple BST operations using a menu-driven application.

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
    int Height(struct node *first);

    void DisplayInorder();
    void DisplayPreorder();
    void DisplayPostorder();

    int CountNode();
    int CountLeafNode();
    int CountParentNode();
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

// Inorder Traversal
void BST::Inorder(struct node *first)
{
    if(first != NULL)
    {
        Inorder(first->lchild);
        cout<<first->data<<"\n";
        Inorder(first->rchild);
    }
}

// Preorder Traversal
void BST::Preorder(struct node *first)
{
    if(first != NULL)
    {
        cout<<first->data<<"\n";
        Preorder(first->lchild);
        Preorder(first->rchild);
    }
}

// Postorder Traversal
void BST::Postorder(struct node *first)
{
    if(first != NULL)
    {
        Postorder(first->lchild);
        Postorder(first->rchild);
        cout<<first->data<<"\n";
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

// Count Leaf Nodes
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

// Count Parent Nodes
int BST::CountParent(struct node *first)
{
    if(first == NULL)
    {
        return 0;
    }

    if(first->lchild != NULL ||
       first->rchild != NULL)
    {
        return 1 +
               CountParent(first->lchild) +
               CountParent(first->rchild);
    }

    return 0;
}

// Calculate Height
int BST::Height(struct node *first)
{
    int iLeft = 0;
    int iRight = 0;

    if(first == NULL)
    {
        return 0;
    }

    iLeft = Height(first->lchild);
    iRight = Height(first->rchild);

    if(iLeft > iRight)
    {
        return iLeft + 1;
    }
    else
    {
        return iRight + 1;
    }
}

// Display Inorder
void BST::DisplayInorder()
{
    Inorder(first);
}

// Display Preorder
void BST::DisplayPreorder()
{
    Preorder(first);
}

// Display Postorder
void BST::DisplayPostorder()
{
    Postorder(first);
}

// Count Nodes
int BST::CountNode()
{
    return Count(first);
}

// Count Leaf Nodes
int BST::CountLeafNode()
{
    return CountLeaf(first);
}

// Count Parent Nodes
int BST::CountParentNode()
{
    return CountParent(first);
}

// Calculate Height
int BST::CalculateHeight()
{
    return Height(first);
}

int main()
{
    BST bobj;

    int iChoice = 1;
    int iNo = 0;

    while(iChoice != 0)
    {
        cout<<"\n====================================\n";
        cout<<"      Binary Search Tree Menu\n";
        cout<<"====================================\n";

        cout<<"1. Insert Node\n";
        cout<<"2. Search Node\n";
        cout<<"3. Inorder Traversal\n";
        cout<<"4. Preorder Traversal\n";
        cout<<"5. Postorder Traversal\n";
        cout<<"6. Count Total Nodes\n";
        cout<<"7. Count Leaf Nodes\n";
        cout<<"8. Count Parent Nodes\n";
        cout<<"9. Height of Tree\n";
        cout<<"0. Exit\n";

        cout<<"Enter your choice : ";
        cin>>iChoice;

        switch(iChoice)
        {
            case 1:

                cout<<"Enter element : ";
                cin>>iNo;

                bobj.Insert(iNo);
                break;

            case 2:

                cout<<"Enter element to search : ";
                cin>>iNo;

                if(bobj.Search(iNo))
                {
                    cout<<"Element Found\n";
                }
                else
                {
                    cout<<"Element Not Found\n";
                }

                break;

            case 3:

                cout<<"\nInorder Traversal\n";
                bobj.DisplayInorder();
                break;

            case 4:

                cout<<"\nPreorder Traversal\n";
                bobj.DisplayPreorder();
                break;

            case 5:

                cout<<"\nPostorder Traversal\n";
                bobj.DisplayPostorder();
                break;

            case 6:

                cout<<"Total Nodes : "
                    <<bobj.CountNode()<<endl;
                break;

            case 7:

                cout<<"Leaf Nodes : "
                    <<bobj.CountLeafNode()<<endl;
                break;

            case 8:

                cout<<"Parent Nodes : "
                    <<bobj.CountParentNode()<<endl;
                break;

            case 9:

                cout<<"Height of Tree : "
                    <<bobj.CalculateHeight()<<endl;
                break;

            case 0:

                cout<<"Thank you for using BST Application\n";
                break;

            default:

                cout<<"Invalid Choice\n";
                break;
        }
    }

    return 0;
}

/*
===============================================================================
Expected Output:
===============================================================================

====================================
      Binary Search Tree Menu
====================================
1. Insert Node
2. Search Node
3. Inorder Traversal
4. Preorder Traversal
5. Postorder Traversal
6. Count Total Nodes
7. Count Leaf Nodes
8. Count Parent Nodes
9. Height of Tree
0. Exit

Enter your choice : 1
Enter element : 11

Enter your choice : 1
Enter element : 5

Enter your choice : 1
Enter element : 17

Enter your choice : 3

Inorder Traversal
5
11
17

Enter your choice : 6
Total Nodes : 3

Enter your choice : 7
Leaf Nodes : 2

Enter your choice : 8
Parent Nodes : 1

Enter your choice : 9
Height of Tree : 2

Enter your choice : 2
Enter element to search : 17
Element Found

Enter your choice : 0
Thank you for using BST Application

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
                    +-----+ +-----+

                    Binary Search Tree

             11
            /  \
           5    17

===============================================================================
Algorithm:
===============================================================================

1. Start the program.
2. Create a BST object.
3. Initialize first to NULL.
4. Display the BST menu.
5. Accept the user's choice.
6. If the choice is Insert:
   - Accept an element.
   - Create a new node.
   - Insert the node according to BST properties.
7. If the choice is Search:
   - Accept the element to search.
   - Compare it with the current node.
   - Move to the left subtree if the element is smaller.
   - Move to the right subtree if the element is larger.
   - Display whether the element is found or not.
8. If the choice is Inorder:
   - Traverse Left, Data, Right.
9. If the choice is Preorder:
   - Traverse Data, Left, Right.
10. If the choice is Postorder:
    - Traverse Left, Right, Data.
11. If the choice is Count Total Nodes:
    - Recursively count all nodes.
12. If the choice is Count Leaf Nodes:
    - Count nodes having no children.
13. If the choice is Count Parent Nodes:
    - Count nodes having at least one child.
14. If the choice is Height:
    - Recursively calculate left and right subtree heights.
    - Select the maximum height and add 1.
15. If the choice is 0:
    - Display the exit message.
16. Repeat the menu until the user selects Exit.
17. Stop the program.

===============================================================================
Program Flow:
===============================================================================

                         Start
                           │
                           ▼
                    Create BST Object
                           │
                           ▼
                    Display BST Menu
                           │
                           ▼
                    Accept User Choice
                           │
              ┌────────────┼────────────┐
              ▼            ▼            ▼
           Insert        Search      Traversals
              │            │            │
              │            │      ┌─────┼─────┐
              │            │      ▼     ▼     ▼
              │            │   Inorder Preorder Postorder
              │            │
              └──────┬─────┴──────────────┐
                     │                    │
                     ▼                    ▼
               Node Counting          Height
                     │                    │
              ┌──────┼──────┐            │
              ▼      ▼      ▼            │
            Total   Leaf   Parent        │
              │      │      │            │
              └──────┴──────┴─────┬──────┘
                                   │
                                   ▼
                            Continue Menu?
                              │       │
                             Yes      No
                              │       │
                              └───┐   ▼
                                  │  Stop
                                  ▼

===============================================================================
Time Complexity:
===============================================================================

Insert() - Best Case    : O(1)
Insert() - Average Case : O(log n)
Insert() - Worst Case   : O(n)

Search() - Best Case    : O(1)
Search() - Average Case : O(log n)
Search() - Worst Case   : O(n)

Inorder Traversal  : O(n)
Preorder Traversal : O(n)
Postorder Traversal: O(n)

Count Nodes        : O(n)
Count Leaf Nodes   : O(n)
Count Parent Nodes : O(n)
Height             : O(n)

Where n is the number of nodes in the BST.

===============================================================================
Space Complexity:
===============================================================================

BST Nodes               : O(n)
Traversal/Counting      : O(h) auxiliary space due to recursion
Height Calculation      : O(h)

Where h is the height of the BST.

For a balanced BST : O(log n)
For a skewed BST   : O(n)

Total Space : O(n)

===============================================================================
Conclusion:
===============================================================================

Program 012 implements a complete menu-driven Binary Search Tree
application using C++. It combines all the major BST operations studied
in the previous programs, including insertion, searching, tree
traversals, node counting, leaf node counting, parent node counting,
and height calculation.

The program provides a practical understanding of how different BST
operations work together in a single application and demonstrates the
use of classes, pointers, dynamic memory allocation, recursion, and
menu-driven programming.

===============================================================================
*/
