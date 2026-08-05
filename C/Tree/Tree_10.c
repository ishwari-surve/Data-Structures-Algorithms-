/*
===============================================================================
Program Name    : Binary Tree - Count Leaf Nodes
Program Number  : 010
File Name       : Tree_10.c
Description     : This program demonstrates the CountLeaf() operation of a
                  Binary Search Tree (BST) using C. The CountLeaf() function
                  recursively traverses the tree and counts all leaf nodes
                  present in the Binary Search Tree.

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
- Identify leaf nodes.
- Traverse the complete tree recursively.
- Count leaf nodes.
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
    int iCount = 0;
    

    if(first != NULL)
    {
        iCount++;
        Count(first -> lchild);
        Count(first -> rchild);
    }
    return iCount;
}

int CountLeaf(PNODE first)
{
    int iCount = 0;

    if(first != NULL)
    {
        if(first -> lchild == NULL && first -> rchild == NULL)
        {
            iCount++;
        }
        CountLeaf(first -> lchild);
        CountLeaf(first -> rchild);
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

    if(Search(head,25) == true)
    {
        printf("25 is present in BST\n");
    }
    else
    {
        printf("25 is not present in BST\n");
    }
    
    iRet = CountLeaf(head);
    printf("Number of Leaf Nodes are: %d\n",iRet);

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

25 is not present in BST

Number of Leaf Nodes are: 4

===============================================================================
Memory Representation:
===============================================================================

                 11
               /    \
              5      17
             / \    /  \
            4   7  15  21


Leaf Nodes

4
7
15
21

Total Leaf Nodes = 4

===============================================================================
Algorithm:
===============================================================================

1. Start from the Root node.
2. If the current node is not NULL:
   a. Check whether both left and right child pointers are NULL.
   b. If yes, increment the leaf node count.
   c. Traverse the left subtree.
   d. Traverse the right subtree.
3. Continue until all nodes are visited.
4. Return the total number of leaf nodes.

===============================================================================
Time Complexity:
===============================================================================

CountLeaf() : O(n)

Space Complexity : O(h)

where,

n = Number of Nodes
h = Height of the Tree

===============================================================================
Conclusion:
===============================================================================

Program 010 demonstrates the CountLeaf() operation of a Binary Search
Tree using recursion. The function traverses the complete tree and
counts only those nodes that do not have any left or right child,
returning the total number of leaf nodes.

===============================================================================
*/
