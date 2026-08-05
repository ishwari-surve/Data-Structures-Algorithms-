/*
===============================================================================
Program Name    : Binary Tree - Count Nodes
Program Number  : 007
File Name       : Tree_07.c
Description     : This program demonstrates the Count() operation of a
                  Binary Search Tree (BST) using C. Multiple nodes are
                  inserted into the tree, and the Count() function
                  recursively traverses the tree to determine the total
                  number of nodes present.

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
- Insert multiple nodes into a BST.
- Traverse the complete tree.
- Count all nodes recursively.
- Understand recursive tree processing.

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

===============================================================================
Memory Representation:
===============================================================================

                 11
               /    \
              5      17
             / \    /  \
            4   7  15  21


Total Nodes = 7

===============================================================================
Algorithm:
===============================================================================

1. Create an empty Binary Search Tree.
2. Insert all given nodes.
3. Start traversal from the Root node.
4. If the current node is not NULL:
   a. Increment the node count.
   b. Traverse the left subtree.
   c. Traverse the right subtree.
5. Continue until all nodes are visited.
6. Return the total node count.

===============================================================================
Program Flow:
===============================================================================

            Start
               │
               ▼
        Create BST
               │
               ▼
      Insert All Nodes
               │
               ▼
      Traverse Tree
               │
               ▼
     Count Every Node
               │
               ▼
   Display Total Count
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

Program 007 demonstrates the Count() operation on a Binary Search Tree
containing multiple nodes. The recursive Count() function visits every
node exactly once and returns the total number of nodes present in the
tree.

===============================================================================
*/
