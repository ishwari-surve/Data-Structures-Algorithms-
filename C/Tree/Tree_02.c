/*
===============================================================================
Program Name    : Binary Tree - Insert Operation
Program Number  : 002
File Name       : Tree_02.c
Description     : This program demonstrates the Insert() operation of a
                  Binary Search Tree (BST) using C. It inserts nodes into
                  the tree while maintaining the Binary Search Tree property.

Date            : August 2026
Language        : C
Author          : Ishwari Vijaykumar Surve
===============================================================================

Concepts Used:
1. Structure
2. Self-Referential Structure
3. Pointer
4. Dynamic Memory Allocation
5. Binary Search Tree (BST)

Key Learning Points:
- Create a new tree node dynamically.
- Insert nodes into a Binary Search Tree.
- Maintain BST ordering property.
- Handle duplicate elements.

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
                printf("Unable to insert as element is duplicate\n");
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

    printf("Nodes inserted successfully\n");

    return 0;
}
/*
===============================================================================
Expected Output:
===============================================================================

Nodes inserted successfully

===============================================================================
Memory Representation:
===============================================================================

          11
         /  \
        5    17

Root = 11

Left Child  = 5
Right Child = 17

===============================================================================
Algorithm:
===============================================================================

1. Create a new node.
2. Store the given data.
3. If the tree is empty, make the new node the Root.
4. Otherwise, compare the data with the current node.
5. If smaller, move to the left child.
6. If greater, move to the right child.
7. Repeat until an empty position is found.
8. Insert the node.
9. If the element already exists, do not insert it.

===============================================================================
Program Flow:
===============================================================================

            Start
               │
               ▼
       Create New Node
               │
               ▼
      Is Tree Empty?
        │           │
      Yes          No
       │            │
       ▼            ▼
 Make Root     Compare Values
                    │
        ┌───────────┴───────────┐
        ▼                       ▼
   Smaller                  Greater
        │                       │
        ▼                       ▼
 Move Left               Move Right
        │                       │
        └───────────┬───────────┘
                    ▼
             Insert New Node
                    │
                    ▼
                   Stop

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

Program 002 demonstrates the Insert() operation of a Binary Search Tree
using C. The program inserts nodes while maintaining the BST property,
ensuring that all smaller elements are stored in the left subtree and
larger elements are stored in the right subtree.

===============================================================================
*/
