/*
===============================================================================
Program Name    : Binary Tree - Count Nodes
Program Number  : 006
File Name       : Tree_06.c
Description     : This program demonstrates the Count() operation of a
                  Binary Search Tree (BST) using C. The Count() function
                  recursively traverses the entire tree and returns the
                  total number of nodes present.

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
- Traverse the complete Binary Tree.
- Count all nodes recursively.
- Return the total number of nodes.
- Understand recursive counting.

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
        Preorder(first -> lchild);
        Preorder(first -> rchild);
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

    printf("Inorder Display: \n");
    Inorder(head);

    printf("Preorder Display: \n");
    Preorder(head);
    
    printf("Postorder Display: \n");
    Postorder(head);

    iRet = Count(head);
    printf("Number of Nodes are: %d\n",iRet);

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

Number of Nodes are: 3

===============================================================================
Memory Representation:
===============================================================================

          11
         /  \
        5    17

Nodes Present:

        11
       /  \
      5    17

Total Nodes = 3

===============================================================================
Algorithm:
===============================================================================

1. Start from the Root node.
2. If the current node is not NULL:
   a. Increment the node count.
   b. Traverse the left subtree.
   c. Traverse the right subtree.
3. Repeat until all nodes are visited.
4. Return the total node count.

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
     Return      Increment Count
                     │
                     ▼
              Traverse Left
                     │
                     ▼
             Traverse Right
                     │
                     ▼
              Return Count
                     │
                     ▼
                    Stop

===============================================================================
Time Complexity:
===============================================================================

Count() : O(n)

Space Complexity : O(h)

where,

n = Number of Nodes
h = Height of the Tree

===============================================================================
Conclusion:
===============================================================================

Program 006 demonstrates the Count() operation of a Binary Search Tree
using recursion. The function traverses the complete tree and returns
the total number of nodes present in the Binary Search Tree.

===============================================================================
*/
