/*
===============================================================================
Program Name    : Importance of Encapsulation in Singly Linked List
Program Number  : 005 (C++ Version)
Description     : This program demonstrates why linked list data members
                  should not be declared as public. It shows how direct
                  access from outside the class can unintentionally modify
                  the head pointer and node counter, leading to data loss
                  and an inconsistent linked list.
Date            : July 2026
Language        : C++
Author          : Ishwari Vijaykumar Surve
===============================================================================

Concepts Used:
1. Object-Oriented Programming (OOP)
2. Class and Object
3. Constructor
4. Access Specifiers
5. Encapsulation
6. Data Hiding
7. Public Data Members
8. Head Pointer
9. Node Counter

Key Learning Points:
- Public data members can be modified directly from outside the class.
- Modifying first may disconnect the entire linked list.
- Modifying iCount may produce an incorrect node count.
- Internal data should be protected using private access.
- Encapsulation improves security, reliability, and maintainability.

===============================================================================
*/

#include<iostream>
using namespace std;

#pragma pack(1)

struct node
{
    int data;
    struct node *next;
};

typedef struct node NODE;
typedef struct node *PNODE;
typedef struct node **PPNODE;

class SinglyLL
{
    public:

        PNODE first;
        int iCount;

        /*
        =========================================================================
        Default Constructor

        - Initializes the linked list to an empty state.
        - first is set to NULL.
        - iCount is initialized to 0.
        =========================================================================
        */
        SinglyLL()
        {
            this->first = NULL;
            this->iCount = 0;
        }
};

int main()
{
    SinglyLL sobj;

    // Assume the linked list contains 5 nodes

    sobj.first = NULL;      // Unsafe direct modification
    sobj.iCount = 15;       // Incorrect node count

    return 0;
}

/*
===============================================================================
Expected Output:
===============================================================================

(No Output)

===============================================================================
Memory Representation:
===============================================================================

Before External Modification:

               sobj
                 │
                 ▼
      +----------------------+
      | first  ───────► Node |
      | iCount = 5           |
      +----------------------+

Linked List:

first
  │
  ▼
[11] → [21] → [51] → [101] → [111] → NULL


After External Modification:

               sobj
                 │
                 ▼
      +----------------------+
      | first  = NULL        |
      | iCount = 15          |
      +----------------------+

Linked List:

first
  │
  ▼
NULL

(The existing nodes remain in memory but are no longer accessible.)

===============================================================================
Explanation:
===============================================================================

In this program, both first and iCount are declared as public data members.
Since they are publicly accessible, any external code can modify them directly.

Changing first to NULL disconnects the linked list from its head, making all
existing nodes inaccessible. Similarly, assigning an arbitrary value to
iCount results in an incorrect node count that no longer reflects the actual
number of nodes.

This demonstrates why important data members should never be exposed publicly.

===============================================================================
Program Flow:
===============================================================================

Create SinglyLL Object
          │
          ▼
Constructor Initializes
(first = NULL, iCount = 0)
          │
          ▼
External Code Modifies Members
          │
          ├──► first = NULL
          │
          ├──► iCount = 15
          │
          ▼
Linked List Integrity Lost

===============================================================================
Operations Performed:
===============================================================================

1. Defined a self-referential node structure.
2. Created the SinglyLL class.
3. Declared first and iCount as public members.
4. Created an object of the class.
5. Modified the head pointer directly.
6. Modified the node counter directly.
7. Demonstrated the drawback of public data members.

===============================================================================
Time Complexity:
===============================================================================

Constructor          : O(1)
Member Assignment    : O(1)
Space Complexity     : O(1)

===============================================================================
Conclusion:
===============================================================================

Program 005 demonstrates the importance of encapsulation in Object-Oriented
Programming. Allowing direct access to critical members such as first and
iCount can corrupt the linked list and produce inconsistent results. In the
next program, these members will be declared private to protect the internal
state of the linked list and ensure controlled access through member
functions.

===============================================================================
*/
