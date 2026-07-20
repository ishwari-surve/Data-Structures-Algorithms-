/*
===============================================================================
Program Name    : Singly Circular Linked List - Class Creation
Program Number  : 007
Description     : This program demonstrates the creation of a Singly Circular
                  Linked List class in C++. It introduces the class members
                  first, last, and iCount along with the default constructor.

Date            : July 2026
Language        : C++
Author          : Ishwari Vijaykumar Surve
===============================================================================

Concepts Used:
1. C++ Class
2. Constructor
3. Encapsulation
4. Self-Referential Structure
5. Pointer Members
6. Object Creation

Key Learning Points:
- Creating a class for Singly Circular Linked List.
- Understanding the purpose of first and last pointers.
- Initializing class members using a constructor.
- Maintaining the node count using iCount.
- Creating an object of the linked list class.

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

class SinglyCL
{
    private:
        PNODE first;
        PNODE last;
        int iCount;

    public:
        SinglyCL();
};

SinglyCL::SinglyCL()
{
    first = NULL;
    last = NULL;
    iCount = 0;
}

int main()
{
    SinglyCL sobj;

    cout<<"Singly Circular Linked List object created successfully."<<endl;

    return 0;
}

/*
===============================================================================
Expected Output:
===============================================================================

Singly Circular Linked List object created successfully.

===============================================================================
Class Representation:
===============================================================================

                 SinglyCL
        +------------------------+
        | first   : PNODE        |
        | last    : PNODE        |
        | iCount  : int          |
        +------------------------+

After Constructor Execution

first  -----> NULL

last   -----> NULL

iCount -----> 0

===============================================================================
Pointer Explanation:
===============================================================================

first
└── Points to the first node of the linked list.

last
└── Points to the last node of the linked list.

iCount
└── Stores the total number of nodes present in the list.

===============================================================================
Program Flow:
===============================================================================

Create SinglyCL Object
        │
        ▼
Call Constructor
        │
        ▼
Initialize first = NULL
        │
        ▼
Initialize last = NULL
        │
        ▼
Initialize iCount = 0
        │
        ▼
Object Ready for Operations

===============================================================================
Time Complexity:
===============================================================================

Object Creation      : O(1)

Space Complexity     : O(1)

===============================================================================
Conclusion:
===============================================================================

Program 007 introduces the Singly Circular Linked List class. The constructor
initializes the first pointer, last pointer, and node count. This class serves
as the foundation for implementing insertion, deletion, traversal, and other
linked list operations in the upcoming programs.

===============================================================================
*/
