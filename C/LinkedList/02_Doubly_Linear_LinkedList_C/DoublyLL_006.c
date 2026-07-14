/*
================================================================================
Program Name    : Doubly Linear Linked List - Complete Display and Count
Program Number  : 006
Description     : This program implements complete doubly linked list with all
                  core functions: InsertFirst(), InsertLast(), Display(), and
                  Count(). Demonstrates the complete implementation of basic 
                  Doubly Linear Linked List operations including InsertFirst(),
                  InsertLast(), Display(), and Count(). The program creates a 
                  six-node list using both front and rear insertions while 
                  maintaining proper forward and backward links.
Date            : July 2026
Language        : C
Author          : Ishwari Vijaykumar Surve
================================================================================
Concepts Used:
Concepts Used:
1. Doubly Linear Linked List
2. Self-Referential Structure
3. Previous and Next Pointers
4. PNODE and PPNODE typedef
5. Dynamic Memory Allocation (malloc)
6. InsertFirst() Operation
7. InsertLast() Operation
8. Display() Traversal
9. Count() Operation
10. Bidirectional Link Maintenance
11. #pragma pack(1)

Key Learning Points:
- InsertFirst adds nodes at beginning O(1)
- InsertLast adds nodes at end O(n)
- Display shows all nodes with <=> bidirectional indicators
- Count returns total node count
- (*first)->prev = newn maintains backward link in InsertFirst
- newn->prev = temp maintains backward link in InsertLast
- iRet stores return value from Count()
- - Demonstrates insertion at both beginning and end.
================================================================================
*/

#include<stdio.h>
#include<stdlib.h>

#pragma pack(1)
struct node
{
    int data;              // 4 bytes - stores the value
    struct node *next;     // 8 bytes - pointer to next node
    struct node *prev;     // 8 bytes - pointer to previous node
};

typedef struct node NODE;        // NODE is alias for struct node
typedef struct node* PNODE;      // PNODE is alias for pointer to NODE
typedef struct node** PPNODE;    // PPNODE is alias for pointer to pointer to NODE

void Display(PNODE first)
{
    printf("\nNULL <=> ");

    while(first != NULL)
    {
        printf("| %d | <=> ", first->data);
        first = first->next;
    }
    printf("NULL\n");
}

int Count(PNODE first)
{
    int iCount = 0;

    while(first != NULL)
    {
        iCount++;
        first = first->next;
    }
    
    return iCount;
}

void InsertFirst(PPNODE first, int iNo)
{
    PNODE newn = NULL;

    newn = (PNODE)malloc(sizeof(NODE));

    newn->data = iNo;
    newn->next = NULL;
    newn->prev = NULL;              // Initialize prev to NULL

    if(NULL == *first)              // Case 1: List is empty
    {
        *first = newn;
    }
    else                            // Case 2: List has nodes
    {
        newn->next = *first;        // New node points to old first
        (*first)->prev = newn;      // Old first's prev points to new node (CRITICAL)
        *first = newn;              // New node becomes head
    }
}

void InsertLast(PPNODE first, int iNo)
{
    PNODE newn = NULL;
    PNODE temp = NULL;

    newn = (PNODE)malloc(sizeof(NODE));

    newn->data = iNo;
    newn->next = NULL;
    newn->prev = NULL;              // Initialize prev to NULL

    if(NULL == *first)              // Case 1: List is empty
    {
        *first = newn;
    }
    else                            // Case 2: List has nodes
    {
        temp = *first;

        // Traverse to last node
        while(temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newn;          // Link last node to new node
        newn->prev = temp;          // New node's prev links to last node (CRITICAL)
    }
}

void InsertAtPos(PPNODE first, int iNo, int iPos)
{
}

void DeleteFirst(PPNODE first)
{
}

void DeleteLast(PPNODE first)
{
}

void DeleteAtPos(PPNODE first, int iPos)
{
}

int main()
{
    PNODE head = NULL;
    int iRet = 0;

    // Build list with alternating insertions
    InsertFirst(&head, 51);
    InsertFirst(&head, 21);
    InsertFirst(&head, 11);

    InsertLast(&head, 101);
    InsertLast(&head, 111);
    InsertLast(&head, 121);

    // Display all nodes
    Display(head);

    // Count and display total
    iRet = Count(head);

    printf("Number of Nodes are: %d\n", iRet);

    return 0;
}

/*
================================================================================
Expected Output:
================================================================================
NULL <=> | 11 | <=> | 21 | <=> | 51 | <=> | 101 | <=> | 111 | <=> | 121 | <=> NULL
Number of elements are: 6

================================================================================
Memory Diagram:
================================================================================

Node Structure (20 bytes with pragma pack):
┌──────┬──────────┬──────────┐
│ data │ next     │ prev     │
│ (4B) │ (8B)     │ (8B)     │
└──────┴──────────┴──────────┘

Final List After All Operations:
head → [11] ↔ [21] ↔ [51] ↔ [101] ↔ [111] ↔ [121]

Visual Chain:
NULL
  ^
  |
[NULL|11|•] ⇄ [•|21|•] ⇄ [•|51|•] ⇄ [•|101|•] ⇄ [•|111|•] ⇄ [•|121|NULL]
                                                                     |
                                                                     v
                                                                    NULL

Display Output:
NULL <=> | 11 | <=> | 21 | <=> | 51 | <=> | 101 | <=> | 111 | <=> | 121 | <=> NULL

Count Result:
Number of elements are: 6

Memory Allocation:
6 nodes × 20 bytes per node = 120 bytes total on heap

================================================================================
Pointer/Logic Explanation:
================================================================================

Execution Sequence:

Call 1: InsertFirst(&head, 51)
- head = NULL initially
- newn allocated: data=51, next=NULL, prev=NULL
- *first == NULL? YES (head is NULL)
- *first = newn (newn becomes head)
- List: [51]

Call 2: InsertFirst(&head, 21)
- head points to 51
- newn allocated: data=21, next=NULL, prev=NULL
- *first == NULL? NO
- newn->next = 51node (21 points to 51)
- 51node->prev = newn (51's prev points to 21) (CRITICAL)
- *first = newn (21 becomes new head)
- List: [21] ↔ [51]

Call 3: InsertFirst(&head, 11)
- head points to 21
- newn allocated: data=11, next=NULL, prev=NULL
- *first == NULL? NO
- newn->next = 21node (11 points to 21)
- 21node->prev = newn (21's prev points to 11) (CRITICAL)
- *first = newn (11 becomes new head)
- List: [11] ↔ [21] ↔ [51]

Call 4: InsertLast(&head, 101)
- head points to 11
- newn allocated: data=101, next=NULL, prev=NULL
- *first == NULL? NO
- temp = head (11)
- while(temp->next != NULL): temp traverses 11 → 21 → 51 → stops
- temp points to 51 (last node)
- 51->next = newn (51 points to 101)
- newn->prev = temp (101's prev points to 51) (CRITICAL)
- List: [11] ↔ [21] ↔ [51] ↔ [101]

Call 5: InsertLast(&head, 111)
- temp traverses to 101 (last node)
- 101->next = newn (101 points to 111)
- newn->prev = 101 (111's prev points to 101) (CRITICAL)
- List: [11] ↔ [21] ↔ [51] ↔ [101] ↔ [111]

Call 6: InsertLast(&head, 121)
- temp traverses to 111 (last node)
- 111->next = newn (111 points to 121)
- newn->prev = 111 (121's prev points to 111) (CRITICAL)
- List: [11] ↔ [21] ↔ [51] ↔ [101] ↔ [111] ↔ [121]

Display Function Execution:

printf("\nNULL <=> ");
└─ Prints: "\nNULL <=> "

Iteration 1: first = 11node
- printf("| %d | <=> ", 11) → Prints: "| 11 | <=> "
- first = 11node->next (21node)

Iteration 2: first = 21node
- printf("| %d | <=> ", 21) → Prints: "| 21 | <=> "
- first = 21node->next (51node)

Iteration 3: first = 51node
- printf("| %d | <=> ", 51) → Prints: "| 51 | <=> "
- first = 51node->next (101node)

Iteration 4: first = 101node
- printf("| %d | <=> ", 101) → Prints: "| 101 | <=> "
- first = 101node->next (111node)

Iteration 5: first = 111node
- printf("| %d | <=> ", 111) → Prints: "| 111 | <=> "
- first = 111node->next (121node)

Iteration 6: first = 121node
- printf("| %d | <=> ", 121) → Prints: "| 121 | <=> "
- first = 121node->next (NULL)

Loop exits: first = NULL

printf("NULL\n");
└─ Prints: "NULL\n"

Complete Output:
NULL <=> | 11 | <=> | 21 | <=> | 51 | <=> | 101 | <=> | 111 | <=> | 121 | <=> NULL


Count Function Execution:

iCount = 0

Iteration 1: first = 11node, iCount = 1, first = 21node
Iteration 2: first = 21node, iCount = 2, first = 51node
Iteration 3: first = 51node, iCount = 3, first = 101node
Iteration 4: first = 101node, iCount = 4, first = 111node
Iteration 5: first = 111node, iCount = 5, first = 121node
Iteration 6: first = 121node, iCount = 6, first = NULL

Loop exits: return iCount (6)

iRet = 6

printf("Number of elements are: %d\n", iRet);
└─ Prints: "Number of elements are: 6"


Why Critical Operations Matter:

(*first)->prev = newn in InsertFirst:
├─ Makes old first node aware of new node
├─ Enables backward traversal from old first
├─ Without updating prev, the backward links become invalid and reverse traversal fails.

newn->prev = temp in InsertLast:
├─ Makes new node aware of last node
├─ Enables backward traversal from new last node
├─ Without updating prev, the last node loses its backward connection.


Alternating Insertion Strategy:

Why alternate InsertFirst and InsertLast?
- Demonstrates both operations work correctly
- Creates balanced list with insertions from both ends
- Shows O(1) vs O(n) operations together
- Tests bidirectional linking thoroughly

Final Sequence: 11 21 51 in middle (from InsertFirst)
                101 111 121 at end (from InsertLast)

================================================================================
Time Complexity:
================================================================================
InsertFirst()    : O(1) - No traversal, direct insertion
InsertLast()     : O(n) - Must traverse to find last node
Display()        : O(n) - Visit all n nodes
Count()          : O(n) - Visit all n nodes
Space Complexity : O(1) - Functions use constant extra space

Total Space: 6 nodes × 20 bytes = 120 bytes heap allocation

================================================================================
Conclusion:
================================================================================

Program DoublyLL_006 completes the basic implementation of a Doubly Linear
Linked List by integrating InsertFirst(), InsertLast(), Display(), and Count()
operations. The program demonstrates how forward and backward links are
maintained using both next and prev pointers while performing insertions at
both ends of the list. Display() traverses and prints the list correctly,
and Count() verifies the total number of nodes. This program establishes a
strong foundation for implementing advanced operations such as deletion,
position-based insertion, and backward traversal in subsequent programs.

================================================================================
*/
