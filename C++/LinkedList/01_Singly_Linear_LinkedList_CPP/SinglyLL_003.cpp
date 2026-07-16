/*
===============================================================================
Program Name    : Introduction to Singly Linked List Class
Program Number  : 003 (C++ Version)
Description     : This program introduces the Singly Linked List class using
                  Object-Oriented Programming. It demonstrates constructor
                  invocation and initializes the head pointer (first) to NULL,
                  representing an empty linked list ready for future operations.
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
6. Head Pointer (first)
7. this Pointer

Key Learning Points:
- Constructor executes automatically when an object is created.
- first acts as the head pointer of the linked list.
- first is initialized to NULL to represent an empty list.
- this pointer accesses the current object's data members.
- Forms the foundation for all linked list operations.

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

        /*
        =========================================================================
        Default Constructor

        - Automatically called whenever a SinglyLL object is created.
        - Initializes the head pointer (first) to NULL.
        - Indicates that the linked list is initially empty.
        =========================================================================
        */
        SinglyLL()
        {
            cout<<"Inside Constructor\n";
            this->first = NULL;
        }
};

int main()
{
    SinglyLL sobj;

    return 0;
}

/*
===============================================================================
Expected Output:
===============================================================================

Inside Constructor

===============================================================================
Memory Representation:
===============================================================================

             sobj
               │
               ▼
      +------------------+
      | first = NULL     |
      +------------------+

Linked List:

first
  │
  ▼
NULL

===============================================================================
Explanation:
===============================================================================

The program creates a Singly Linked List class containing a single data
member named first, which stores the address of the first node in the list.

When an object of the class is created, the constructor executes
automatically and initializes first to NULL. This indicates that the linked
list is empty because no nodes have been created yet.

This program focuses only on constructor-based initialization and serves as
the starting point for implementing linked list operations.

===============================================================================
Program Flow:
===============================================================================

Create SinglyLL Object
          │
          ▼
Constructor Invoked Automatically
          │
          ▼
Initialize first = NULL
          │
          ▼
Display "Inside Constructor"
          │
          ▼
Program Terminates

===============================================================================
Operations Performed:
===============================================================================

1. Defined a self-referential node structure.
2. Created the SinglyLL class.
3. Declared first as the head pointer.
4. Initialized first to NULL inside the constructor.
5. Created an object of the SinglyLL class.
6. Executed the constructor automatically.

===============================================================================
Time Complexity:
===============================================================================

Constructor      : O(1)
Space Complexity : O(1)

===============================================================================
Conclusion:
===============================================================================

Program 003 introduces the Singly Linked List class using Object-Oriented
Programming. The constructor initializes the head pointer to NULL, ensuring
that the list starts in an empty state. This serves as the foundation for
implementing insertion, deletion, traversal, and other linked list
operations in the upcoming programs.

===============================================================================
*/
