/*
===============================================================================
Program Name    : Binary Tree - Postorder Traversal
Program Number  : 005
File Name       : Tree_05.c
Description     : This program demonstrates the Postorder Traversal of a
                  Binary Search Tree (BST) using C. The traversal visits
                  the Left Subtree, Right Subtree, and Root Node (LRD)
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
- Understand Postorder Traversal (LRD).
- Learn recursive tree traversal.
- Visit every node exactly once.
- Display the Root after traversing both subtrees.

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
    
    printf("Postorder Display: \n");
    Postorder(head);
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

Postorder Display:

5
17
11

===============================================================================
Memory Representation:
===============================================================================

          11
         /  \
        5    17


Postorder Traversal (LRD)

Step 1 : Visit Left Child  → 5
Step 2 : Visit Right Child → 17
Step 3 : Visit Root        → 11

Output:

5
17
11

===============================================================================
Algorithm:
===============================================================================

1. If the current node is not NULL:
   a. Traverse the left subtree.
   b. Traverse the right subtree.
   c. Display the current node.
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
     Return      Traverse Left
                     │
                     ▼
              Traverse Right
                     │
                     ▼
              Display Root
                     │
                     ▼
                    Stop

===============================================================================
Time Complexity:
===============================================================================

Postorder Traversal : O(n)

Space Complexity : O(h)

where,

n = Number of Nodes
h = Height of the Tree

===============================================================================
Conclusion:
===============================================================================

Program 005 demonstrates the Postorder Traversal of a Binary Search Tree
using recursion. The traversal follows the Left-Right-Data (LRD)
sequence, visiting the root node only after traversing both the left and
right subtrees.

===============================================================================
*/
