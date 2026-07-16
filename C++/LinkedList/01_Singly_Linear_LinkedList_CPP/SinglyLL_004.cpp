/*
===============================================================================
Program Name    : Singly Linked List Class with Node Counter
Program Number  : 004 
Description     : This program extends the Singly Linked List class by
                  introducing a node counter (iCount) along with the head
                  pointer (first). The constructor initializes both data
                  members, representing an empty linked list with zero nodes.
Date            : July 2026
Language        : C++
Author          : Ishwari Vijaykumar Surve
===============================================================================

Concepts Used:
1. Object-Oriented Programming (OOP)
2. Class and Object
3. Constructor
4. Self-Referential Structure
5. Pointer Initialization
6. Node Counter (iCount)
7. this Pointer

Key Learning Points:
- first stores the address of the first node in the linked list.
- iCount maintains the total number of nodes.
- Constructor initializes first to NULL and iCount to 0.
- this pointer is used to access the current object's data members.
- Node counter simplifies future Count() implementation.

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

        - Automatically invoked when a SinglyLL object is created.
        - Initializes the head pointer (first) to NULL.
        - Initializes the node counter (iCount) to 0.
        - Represents an empty linked list.
        =========================================================================
        */
        SinglyLL()
        {
            cout<<"Inside Constructor\n";

            this->first = NULL;
            this->iCount = 0;
        }
};

int main()
{
    SinglyLL sobj;

    cout<<sobj.first<<endl;
    cout<<sobj.iCount<<endl;

    return 0;
}

/*
===============================================================================
Expected Output:
===============================================================================

Inside Constructor
0
0

(Note: The NULL pointer may appear as 0, 0x0, or nullptr depending upon the
compiler and platform.)

===============================================================================
Memory Representation:
===============================================================================

               sobj
                 │
                 ▼
      +----------------------+
      | first  = NULL        |
      | iCount = 0           |
      +----------------------+

Linked List:

first
  │
  ▼
NULL

===============================================================================
Explanation:
===============================================================================

The SinglyLL class now contains two important data members:

• first
  - Stores the address of the first node.
  - Initialized to NULL because the list is empty.

• iCount
  - Stores the total number of nodes present in the linked list.
  - Initialized to 0 since no nodes exist initially.

When a SinglyLL object is created, the constructor executes automatically
and initializes both members, ensuring that the linked list starts in a
valid and predictable state.

===============================================================================
Program Flow:
===============================================================================

Create SinglyLL Object
          │
          ▼
Constructor Invoked Automatically
          │
          ├──► first = NULL
          │
          ├──► iCount = 0
          │
          ▼
Display Initialized Values
          │
          ▼
Program Terminates

===============================================================================
Operations Performed:
===============================================================================

1. Defined a self-referential node structure.
2. Created the SinglyLL class.
3. Declared first as the head pointer.
4. Declared iCount as the node counter.
5. Initialized first to NULL.
6. Initialized iCount to 0.
7. Created an object of the SinglyLL class.
8. Displayed the initialized values.

===============================================================================
Time Complexity:
===============================================================================

Constructor      : O(1)
Display Values   : O(1)
Space Complexity : O(1)

===============================================================================
Conclusion:
===============================================================================

Program 004 extends the Singly Linked List class by introducing a node
counter (iCount) along with the head pointer (first). The constructor
initializes both members, ensuring that every newly created linked list
starts empty with zero nodes. This node counter will be used in future
programs to efficiently maintain and retrieve the total number of nodes.

===============================================================================
*/
