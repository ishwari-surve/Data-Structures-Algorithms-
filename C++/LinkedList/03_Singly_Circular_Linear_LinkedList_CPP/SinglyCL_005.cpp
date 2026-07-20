/*
===============================================================================
Program Name    : Singly Circular Linked List - Manual Traversal
Program Number  : 005
Description     : This program demonstrates how to traverse a Singly Circular
                  Linked List manually using a temporary pointer. It shows how
                  the pointer moves from one node to the next and finally
                  returns back to the first node.

Date            : July 2026
Language        : C++
Author          : Ishwari Vijaykumar Surve
===============================================================================

Concepts Used:
1. Singly Circular Linked List
2. Self-Referential Structure
3. Dynamic Memory Allocation (new)
4. Pointer Traversal
5. Temporary Pointer

Key Learning Points:
- Traversal starts from the first node.
- A temporary pointer is used for traversal.
- Each node is visited using temp = temp->next.
- In a circular linked list, traversal returns to the first node.

===============================================================================
*/

#include<iostream>
using namespace std;

struct node
{
    int data;
    struct node *next;
};

typedef struct node NODE;
typedef struct node *PNODE;

int main()
{
    PNODE first = NULL;
    PNODE second = NULL;
    PNODE third = NULL;
    PNODE temp = NULL;

    // Allocate memory
    first = new NODE;
    second = new NODE;
    third = new NODE;

    // Store data
    first->data = 11;
    second->data = 21;
    third->data = 51;

    // Connect nodes
    first->next = second;
    second->next = third;
    third->next = first;

    // Traversal
    temp = first;

    cout<<"Traversal of Singly Circular Linked List :\n"<<endl;

    cout<<temp->data<<endl;

    temp = temp->next;
    cout<<temp->data<<endl;

    temp = temp->next;
    cout<<temp->data<<endl;

    temp = temp->next;
    cout<<temp->data<<endl;

    delete first;
    delete second;
    delete third;

    return 0;
}

/*
===============================================================================
Expected Output:
===============================================================================

Traversal of Singly Circular Linked List :

11
21
51
11

===============================================================================
Memory Representation:
===============================================================================

          first,temp
              │
              ▼
+-------+     +-------+     +-------+
|  11   | --> |  21   | --> |  51   |
+-------+     +-------+     +-------+
     ^                             |
     |_____________________________|

Traversal:

temp
 │
 ▼
11 → 21 → 51 → 11 (Back to First)

===============================================================================
Program Flow:
===============================================================================

Create Three Nodes
        │
        ▼
Connect Nodes Circularly
        │
        ▼
Assign temp = first
        │
        ▼
Display Current Node
        │
        ▼
Move temp = temp->next
        │
        ▼
Reach First Node Again

===============================================================================
Time Complexity:
===============================================================================

Traversal of 3 Nodes : O(3)
General Traversal    : O(n)

Space Complexity     : O(1)

===============================================================================
Conclusion:
===============================================================================

This program demonstrates manual traversal of a Singly Circular Linked List
using a temporary pointer. The traversal moves through each node one by one
and finally returns to the first node because the last node points back to
the beginning of the list.

===============================================================================
*/
