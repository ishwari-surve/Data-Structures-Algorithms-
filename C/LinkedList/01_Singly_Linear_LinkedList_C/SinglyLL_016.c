/*
================================================================================ 
Program Name    : Singly Linked List - Display & Count Functions Combined
Program Number  : 016
Description     : This program demonstrates the implementation of two
                  fundamental linked list functions: Display() for
                  printing all node values and Count() for counting
                  the total number of nodes. Both functions use the
                  standard while loop traversal pattern and illustrate
                  code reusability through functions.
Date            : July 2026
Language        : C
Author          : Ishwari Vijaykumar Surve
================================================================================
Concepts Used:
1. Structures (struct)
2. Self-Referential Structures
3. PNODE typedef
4. Function Definition
5. Function Parameters (pass by value with pointer)
6. While Loop Traversal
7. Return Values
8. Display Function (void return)
9. Count Function (int return)
10. Function Calls from main
11. Variable Passing to Functions
12. #pragma pack(1)

Key Learning Points:
- Functions encapsulate traversal logic
- Display() prints all nodes without returning value
- Count() counts nodes and returns total count
- Both use while(first != NULL) loop pattern
- PNODE parameter allows function to work with any list
- iRet variable stores return value from Count()
- Functions receive pointer as parameter
- Foundation for implementing insert/delete functions
- Demonstrates code reusability
- Functions work with same pattern for any size list
================================================================================
*/

#include<stdio.h>

#pragma pack(1)
struct node 
{
    int data;              // 4 bytes - stores the value
    struct node *next;     // 8 bytes - pointer to next node
};

typedef struct node NODE;        // NODE is alias for struct node
typedef struct node *PNODE;      // PNODE is alias for pointer to NODE

int Count(PNODE first)
{
    int iCount = 0;                  // Counter initialized to 0

    while(first != NULL)             // Loop until end of list
    {
        iCount++;                    // Increment count for each node
        first = first->next;         // Move to next node
    } 
    return iCount;                   // Return total count
}

void Display(PNODE first)            // For displaying all node data
{
    while(first != NULL)             // Loop until end of list
    {
        printf("%d\n", first->data); // Print current node data
        first = first->next;         // Move to next node
    } 
}

int main()
{
    PNODE head = NULL;               // HEAD pointer - entry point
    int iRet = 0;                    // Variable to store count result
    NODE obj1, obj2, obj3;           // Three node objects

    // Link nodes together
    head = &obj1;

    // Initialize Node 1
    obj1.data = 11;
    obj1.next = &obj2;

    // Initialize Node 2
    obj2.data = 21;
    obj2.next = &obj3;

    // Initialize Node 3
    obj3.data = 51;
    obj3.next = NULL;

    // Call Display() to print all nodes
    Display(head);

    // Call Count() to count nodes and store result
    iRet = Count(head);

    // Print total count
    printf("Number of nodes are : %d\n", iRet);

    return 0; 
}

/*
================================================================================
Expected Output:
================================================================================
11
21
51
Number of nodes are : 3

================================================================================
Memory Diagram:
================================================================================
            head (PNODE)
                │
                ▼
      +-----------+      +-----------+      +-----------+
      | data = 11 | ---> | data = 21 | ---> | data = 51 |
      | next -----|      | next -----|      | next=NULL |
      +-----------+      +-----------+      +-----------+
      obj1              obj2              obj3

Visual Chain:
head → obj1(11) → obj2(21) → obj3(51) → NULL

Function Call Sequence:
main()
  │
  ├─→ Display(head)  ← Prints: 11, 21, 51
  │
  ├─→ Count(head)    ← Returns: 3
  │
  └─→ Print: "Number of rows are : 3"

================================================================================
Pointer/Logic Explanation:
================================================================================

Function 1: Display(PNODE first)

Purpose: Print data of all nodes

Logic:
1. Receives pointer to first node as parameter
2. while(first != NULL) loops through all nodes
3. Prints first->data at each iteration
4. Moves to next node: first = first->next
5. Loop exits when first becomes NULL

Execution Trace:
┌─ Call: Display(head)
├─ Iteration 1: first = obj1, print 11, first = &obj2
├─ Iteration 2: first = obj2, print 21, first = &obj3
├─ Iteration 3: first = obj3, print 51, first = NULL
├─ Iteration 4: first = NULL, exit loop
└─ Return to main (no return value - void function)


Function 2: Count(PNODE first)

Purpose: Count total nodes and return count

Logic:
1. Initialize counter iCount = 0
2. while(first != NULL) loops through all nodes
3. Increments iCount for each node visited
4. Moves to next node: first = first->next
5. Returns iCount when loop exits

Execution Trace:
┌─ Call: Count(head)
├─ Iteration 1: first = obj1, iCount = 1, first = &obj2
├─ Iteration 2: first = obj2, iCount = 2, first = &obj3
├─ Iteration 3: first = obj3, iCount = 3, first = NULL
├─ Iteration 4: first = NULL, exit loop
└─ Return iCount = 3 to main


Main Function Flow:

1. Create three nodes and link them
2. head = &obj1 (entry point)
3. Call Display(head) → Prints all data
4. Call Count(head) → Returns 3
5. Store result: iRet = 3
6. Print result with count


Function Parameter Passing:

Display(head) and Count(head) both receive pointer:
├─ Both get address of first node
├─ Inside function, parameter is PNODE first
├─ Parameter receives SAME address as head
├─ Function can traverse from that point
├─ Original head in main remains UNCHANGED

Why Parameter Works:
PNODE first receives pointer value (address), not the
pointer variable itself. When first = first->next inside
the function, it changes the LOCAL copy of the pointer,
not the original head in main. This is safe - head stays
pointing to first node.

================================================================================
Operations Performed
================================================================================

1. Created and linked three nodes.
2. Assigned HEAD to the first node.
3. Called Display() to print all node data.
4. Traversed the linked list using a while loop.
5. Called Count() to count the total number of nodes.
6. Returned the count to the main() function.
7. Stored the returned value in iRet.
8. Displayed the total number of nodes.

================================================================================
Time Complexity
================================================================================

Display()             : O(n)
Count()               : O(n)

Space Complexity      : O(1)

================================================================================
Conclusion
================================================================================

This program demonstrates how linked list operations can be implemented using
separate reusable functions. Display() traverses the list and prints every node,
while Count() traverses the list and returns the total number of nodes. Both
functions use the same while(first != NULL) traversal pattern without modifying
the original HEAD pointer. This modular approach improves code readability,
reusability, and forms the foundation for implementing insertion, deletion,
searching, and other linked list operations.

================================================================================
*/
