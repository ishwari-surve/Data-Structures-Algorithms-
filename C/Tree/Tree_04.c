/*
===============================================================================
Program Name    : Binary Tree - Preorder Traversal
Program Number  : 004
File Name       : Tree_04.c
Description     : This program demonstrates the Preorder Traversal of a
                  Binary Search Tree (BST) using C. The traversal visits
                  the Root Node, Left Subtree, and Right Subtree (DLR)
                  recursively.

Date            : August 2026
Language        : C
Author          : Ishwari Vijaykumar Surve
===============================================================================

Concepts Used:
1. Structure
2. Self-Referential Structure
3. Pointer
4. Binary Search Tree (BST)
5. Recursion
6. Tree Traversal

Key Learning Points:
- Understand Preorder Traversal (DLR).
- Learn recursive tree traversal.
- Visit every node exactly once.
- Display the Root before its subtrees.

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

int main()
{
    PNODE head = NULL;

    Insert(&head,11);
    Insert(&head,5);
    Insert(&head,17);

    printf("Inorder Display: \n");
    Inorder(head);

    printf("Preorder Display: \n");
    Preorder(head);
    
    return 0;
}
/*
===============================================================================
Expected Output:
===============================================================================

Inorder Display:

5
11
17

Preorder Display:

11
5
17

===============================================================================
Memory Representation:
===============================================================================

          11
         /  \
        5    17


Preorder Traversal (DLR)

Step 1 : Visit Root       → 11
Step 2 : Visit Left Child → 5
Step 3 : Visit Right Child→ 17

Output:

11
5
17

===============================================================================
Algorithm:
===============================================================================

1. If the current node is not NULL:
   a. Display the current node.
   b. Traverse the left subtree.
   c. Traverse the right subtree.
2. Stop when NULL is reached.

===============================================================================
Program Flow:
===============================================================================

            Start
               │
               ▼
     Is Current Node NULL?
        │             │
      Yes            No
       │              │
       ▼              ▼
     Return      Display Root
                     │
                     ▼
              Traverse Left
                     │
                     ▼
             Traverse Right
                     │
                     ▼
                    Stop

===============================================================================
Time Complexity:
===============================================================================

Preorder Traversal : O(n)

Space Complexity : O(h)

where,

n = Number of Nodes
h = Height of the Tree

===============================================================================
Conclusion:
===============================================================================

Program 004 demonstrates the Preorder Traversal of a Binary Search Tree
using recursion. The traversal follows the Data-Left-Right (DLR)
sequence, visiting the root node before traversing its left and right
subtrees.

===============================================================================
*/
