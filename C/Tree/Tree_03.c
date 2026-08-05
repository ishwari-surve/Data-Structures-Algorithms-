/*
===============================================================================
Program Name    : Binary Tree - Inorder Traversal
Program Number  : 003
File Name       : Tree_03.c
Description     : This program demonstrates the Inorder Traversal of a
                  Binary Search Tree (BST) using C. The traversal visits
                  the Left Subtree, Root Node, and Right Subtree (LDR),
                  resulting in the elements being displayed in ascending
                  order for a Binary Search Tree.

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
- Understand Inorder Traversal (LDR).
- Learn recursive tree traversal.
- Visit every node exactly once.
- Display BST elements in sorted order.

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

===============================================================================
Memory Representation:
===============================================================================

          11
         /  \
        5    17


Traversal Order (LDR)

        11
       /  \
      5    17

Step 1 : Visit Left Child  → 5
Step 2 : Visit Root        → 11
Step 3 : Visit Right Child → 17

Output:

5
11
17

===============================================================================
Algorithm:
===============================================================================

1. If the current node is not NULL:
   a. Traverse the left subtree.
   b. Display the current node.
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
     Return     Traverse Left
                     │
                     ▼
               Display Root
                     │
                     ▼
              Traverse Right
                     │
                     ▼
                    Stop

===============================================================================
Time Complexity:
===============================================================================

Inorder Traversal : O(n)

Space Complexity : O(h)

where,

n = Number of Nodes
h = Height of the Tree

===============================================================================
Conclusion:
===============================================================================

Program 003 demonstrates the Inorder Traversal of a Binary Search Tree
using recursion. The traversal follows the Left-Data-Right (LDR)
sequence and displays the elements of a Binary Search Tree in ascending
order.

===============================================================================
*/
