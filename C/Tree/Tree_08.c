/*
===============================================================================
Program Name    : Binary Tree - Search Operation
Program Number  : 008
File Name       : Tree_08.c
Description     : This program demonstrates the Search() operation of a
                  Binary Search Tree (BST) using C. The Search() function
                  traverses the tree based on the Binary Search Tree
                  property and determines whether the specified element
                  is present or not.

Date            : August 2026
Language        : C
Author          : Ishwari Vijaykumar Surve
===============================================================================

Concepts Used:
1. Structure
2. Self-Referential Structure
3. Pointer
4. Binary Search Tree (BST)
5. Tree Traversal
6. Searching

Key Learning Points:
- Search an element in a BST.
- Traverse the tree efficiently.
- Apply the BST ordering property.
- Return search status using Boolean values.

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

// L    D   R
void Inorder(PNODE first)
{
    if(first != NULL)
    {
        Inorder(first -> lchild);
        printf("%d\n",first -> data);
        Inorder(first -> rchild);
    }
}

// D    L   R
void Preorder(PNODE first)
{
    if(first != NULL)
    {
        printf("%d\n",first -> data);
        Preorder(first -> lchild);
        Preorder(first -> rchild);
    }
}

// L    R   D
void Postorder(PNODE first)
{
    if(first != NULL)
    {
        Postorder(first -> lchild);
        Postorder(first -> rchild);
        printf("%d\n",first -> data);
    }
}

void Insert(PPNODE first, int iNo)
{
    PNODE newn = NULL;
    PNODE temp = NULL;

    newn = (PNODE)malloc(sizeof(NODE));

    newn -> data = iNo;
    newn -> lchild = NULL;
    newn -> rchild = NULL;

    if(*first == NULL)
    {
        *first = newn;
    }
    else
    {
        temp = *first;

        while(1)
        {
            if(iNo > temp -> data)
            {
                if(temp -> rchild == NULL)
                {
                    temp -> rchild = newn;
                    break;
                }
                temp = temp -> rchild;
            }
            else if(iNo < temp -> data)
            {
                if(temp -> lchild == NULL)
                {
                    temp -> lchild = newn;
                    break;
                }
                temp = temp -> lchild;
            }
            else if(iNo == temp -> data)
            {
                printf("Unable to Insert as Elements is Duplicate");
                free(newn);
                break;
            }
        }
    }
}

bool Search(PNODE first, int iNo)
{
    bool bFlag = false;

    while(first != NULL)
    {
        if(iNo == first -> data)
        {
            bFlag = true;
            break;
        }
        else if(iNo > first -> data)
        {
            first = first -> rchild;
        }
        else if(iNo < first -> data)
        {
            first = first -> lchild;
        }
    }
    return bFlag;
}

int Count(PNODE first)
{
    static int iCount = 0;
    

    if(first != NULL)
    {
        iCount++;
        Count(first -> lchild);
        Count(first -> rchild);
    }
    return iCount;
}

int main()
{
    PNODE head = NULL;
    int iRet = 0;

    Insert(&head,11);
    Insert(&head,5);
    Insert(&head,17);
    Insert(&head,21);
    Insert(&head,4);
    Insert(&head,7);
    Insert(&head,15);

    printf("Inorder Display: \n");
    Inorder(head);

    iRet = Count(head);
    printf("Number of Nodes are: %d\n",iRet);

    if(Search(head,17) == true)
    {
        printf("17 is present in BST");
    }
    else
    {
        printf("17 is not present in BST");
    }
    
    return 0;
}
/*
===============================================================================
Expected Output:
===============================================================================

Inorder Display:

4
5
7
11
15
17
21

Number of Nodes are: 7

17 is present in BST

===============================================================================
Memory Representation:
===============================================================================

                 11
               /    \
              5      17
             / \    /  \
            4   7  15  21


Searching for 17

11
 │
 ▼
17  ✓ Found

===============================================================================
Algorithm:
===============================================================================

1. Start from the Root node.
2. Compare the search element with the current node.
3. If equal, return TRUE.
4. If smaller, move to the left subtree.
5. If greater, move to the right subtree.
6. Repeat until the element is found or NULL is reached.
7. Return FALSE if the element is not present.

===============================================================================
Program Flow:
===============================================================================

            Start
               │
               ▼
      Start from Root
               │
               ▼
     Element == Current ?
        │             │
      Yes            No
       │              │
       ▼              ▼
 Return TRUE    Compare Value
                     │
           ┌─────────┴─────────┐
           ▼                   ▼
     Move Left           Move Right
           │                   │
           └─────────┬─────────┘
                     ▼
              NULL Reached?
                │        │
              Yes       No
               │         │
               ▼         │
          Return FALSE ◄─┘

===============================================================================
Time Complexity:
===============================================================================

Best Case    : O(log n)

Average Case : O(log n)

Worst Case   : O(n)

Space Complexity : O(1)

===============================================================================
Conclusion:
===============================================================================

Program 008 demonstrates the Search() operation of a Binary Search Tree
using C. By utilizing the Binary Search Tree property, the program
efficiently locates the required element and returns whether it is
present or absent in the tree.

===============================================================================
*/
