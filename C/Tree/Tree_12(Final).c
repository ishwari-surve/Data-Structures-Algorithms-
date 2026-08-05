/*
===============================================================================
Program Name    : Menu Driven Binary Search Tree
Program Number  : 012
File Name       : Tree_12.c
Description     : This program demonstrates a complete Menu Driven
                  Binary Search Tree (BST) implementation using C.
                  The application allows the user to perform various
                  BST operations such as insertion, searching,
                  traversals, counting nodes, counting leaf nodes,
                  and counting parent nodes.

Date            : August 2026
Language        : C
Author          : Ishwari Vijaykumar Surve
===============================================================================

Concepts Used:
1. Structure
2. Self-Referential Structure
3. Pointer
4. Binary Search Tree (BST)
5. Dynamic Memory Allocation
6. Recursion
7. Menu Driven Programming
8. Tree Traversal

Key Learning Points:
- Create a complete BST application.
- Perform all BST operations.
- Implement recursive traversals.
- Build a menu-driven program.
- Handle user interaction efficiently.

===============================================================================
*/
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#pragma pack(1)

struct node
{
    int data;
    struct node *lchild;
    struct node *rchild;
};

typedef struct node NODE;
typedef struct node* PNODE;
typedef struct node** PPNODE;

// L D R
void Inorder(PNODE first)
{
    if(first != NULL)
    {
        Inorder(first->lchild);
        printf("%d\n", first->data);
        Inorder(first->rchild);
    }
}

// D L R
void Preorder(PNODE first)
{
    if(first != NULL)
    {
        printf("%d\n", first->data);
        Preorder(first->lchild);
        Preorder(first->rchild);
    }
}

// L R D
void Postorder(PNODE first)
{
    if(first != NULL)
    {
        Postorder(first->lchild);
        Postorder(first->rchild);
        printf("%d\n", first->data);
    }
}

void Insert(PPNODE first, int iNo)
{
    PNODE newn = NULL;
    PNODE temp = NULL;

    newn = (PNODE)malloc(sizeof(NODE));

    newn->data = iNo;
    newn->lchild = NULL;
    newn->rchild = NULL;

    if(*first == NULL)
    {
        *first = newn;
    }
    else
    {
        temp = *first;

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
                printf("Duplicate element not allowed\n");
                free(newn);
                break;
            }
        }
    }
}

bool Search(PNODE first, int iNo)
{
    while(first != NULL)
    {
        if(iNo == first->data)
        {
            return true;
        }
        else if(iNo > first->data)
        {
            first = first->rchild;
        }
        else
        {
            first = first->lchild;
        }
    }

    return false;
}

int Count(PNODE first)
{
    if(first == NULL)
    {
        return 0;
    }

    return Count(first->lchild) +
           Count(first->rchild) + 1;
}

int CountLeaf(PNODE first)
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

int CountParent(PNODE first)
{
    if(first == NULL)
    {
        return 0;
    }

    if(first->lchild != NULL || first->rchild != NULL)
    {
        return 1 + CountParent(first->lchild)
                 + CountParent(first->rchild);
    }

    return 0;
}

int main()
{
    PNODE head = NULL;

    int iChoice = 1;
    int iNo = 0;

    while(iChoice != 0)
    {
        printf("\n====================================\n");
        printf("      Binary Search Tree Menu\n");
        printf("====================================\n");

        printf("1. Insert Node\n");
        printf("2. Search Node\n");
        printf("3. Inorder Traversal\n");
        printf("4. Preorder Traversal\n");
        printf("5. Postorder Traversal\n");
        printf("6. Count Total Nodes\n");
        printf("7. Count Leaf Nodes\n");
        printf("8. Count Parent Nodes\n");
        printf("0. Exit\n");

        printf("Enter your choice : ");
        scanf("%d",&iChoice);

        switch(iChoice)
        {
            case 1:
                printf("Enter element : ");
                scanf("%d",&iNo);

                Insert(&head,iNo);
                break;

            case 2:
                printf("Enter element to search : ");
                scanf("%d",&iNo);

                if(Search(head,iNo))
                {
                    printf("Element Found\n");
                }
                else
                {
                    printf("Element Not Found\n");
                }
                break;

            case 3:
                printf("\nInorder Traversal:\n");
                Inorder(head);
                break;

            case 4:
                printf("\nPreorder Traversal:\n");
                Preorder(head);
                break;

            case 5:
                printf("\nPostorder Traversal:\n");
                Postorder(head);
                break;

            case 6:
                printf("Total Nodes : %d\n", Count(head));
                break;

            case 7:
                printf("Leaf Nodes : %d\n", CountLeaf(head));
                break;

            case 8:
                printf("Parent Nodes : %d\n", CountParent(head));
                break;

            case 0:
                printf("Thank you for using BST Application\n");
                break;

            default:
                printf("Invalid Choice\n");
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
0. Exit

Enter your choice :

===============================================================================
Memory Representation:
===============================================================================

                 11
               /    \
              5      17
             / \    /  \
            4   7  15  21


Operations Available

• Insert
• Search
• Inorder Traversal
• Preorder Traversal
• Postorder Traversal
• Count Nodes
• Count Leaf Nodes
• Count Parent Nodes

===============================================================================
Algorithm:
===============================================================================

1. Create an empty Binary Search Tree.
2. Display the menu repeatedly.
3. Accept the user's choice.
4. Perform the selected BST operation.
5. Continue until the user selects Exit.
6. Terminate the application.

===============================================================================
Program Flow:
===============================================================================

             Start
                │
                ▼
        Display Menu
                │
                ▼
        Read User Choice
                │
                ▼
      Perform Selected Operation
                │
                ▼
        Exit Selected?
          │           │
        No            Yes
         │             │
         └──────► End Program
                ▲
                │
          Display Menu Again

===============================================================================
Time Complexity:
===============================================================================

Insert              : O(log n) Average, O(n) Worst
Search              : O(log n) Average, O(n) Worst
Inorder Traversal   : O(n)
Preorder Traversal  : O(n)
Postorder Traversal : O(n)
Count Nodes         : O(n)
Count Leaf Nodes    : O(n)
Count Parent Nodes  : O(n)

Space Complexity (Recursive Operations): O(h)

where,

n = Number of Nodes
h = Height of the Tree

===============================================================================
Conclusion:
===============================================================================

Program 012 demonstrates a complete Menu Driven Binary Search Tree
application in C. It combines all fundamental BST operations into a
single interactive program, allowing users to insert nodes, search
elements, perform traversals, and obtain tree statistics through an
easy-to-use menu interface.

===============================================================================
*/
