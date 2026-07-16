/*
===============================================================================
Program Name    : Data Hiding using Private Members in Singly Linked List
Program Number  : 006 
Description     : This program demonstrates the concept of Data Hiding by
                  declaring the linked list data members as private.
                  Attempting to access these members directly from outside
                  the class results in compilation errors, thereby ensuring
                  data protection and encapsulation.
Date            : July 2026
Language        : C++
Author          : Ishwari Vijaykumar Surve
===============================================================================

Concepts Used:
1. Object-Oriented Programming (OOP)
2. Class and Object
3. Constructor
4. Access Specifiers
5. Private Data Members
6. Data Hiding
7. Encapsulation
8. this Pointer

Key Learning Points:
- Private members cannot be accessed directly outside the class.
- Data Hiding protects the internal state of the linked list.
- Compiler prevents unauthorized modification of important members.
- Encapsulation improves software reliability and security.
- Member functions provide controlled access to private data.

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
    private:

        PNODE first;
        int iCount;

    public:

        /*
        =========================================================================
        Default Constructor

        - Automatically invoked when a SinglyLL object is created.
        - Initializes first to NULL.
        - Initializes iCount to 0.
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

    // Assume the linked list contains 5 nodes

    sobj.first = NULL;      // Compilation Error
    sobj.iCount = 15;       // Compilation Error

    return 0;
}

/*
===============================================================================
Expected Output:
===============================================================================

Compilation Error

Example Error:

error: 'node* SinglyLL::first' is private within this context

error: 'int SinglyLL::iCount' is private within this context

===============================================================================
Class Representation:
===============================================================================

             SinglyLL
      +----------------------+
      | first   (private)    |
      | iCount  (private)    |
      +----------------------+
      | Constructor()        |
      +----------------------+

===============================================================================
Explanation:
===============================================================================

In this program, the data members first and iCount are declared inside the
private section of the SinglyLL class.

Private members cannot be accessed directly using an object outside the class.
Therefore, the following statements are invalid:

    sobj.first = NULL;
    sobj.iCount = 15;

The compiler detects these illegal accesses and generates compilation errors.

Only member functions of the same class (or friend functions/classes) are
allowed to access private data members.

This mechanism is known as Data Hiding and is one of the fundamental concepts
of Object-Oriented Programming.

===============================================================================
Program Flow:
===============================================================================

Create SinglyLL Object
          │
          ▼
Constructor Invoked
          │
          ├──► first = NULL
          │
          ├──► iCount = 0
          │
          ▼
Attempt Direct Access
          │
          ▼
Compiler Detects Private Members
          │
          ▼
Compilation Error

===============================================================================
Operations Performed:
===============================================================================

1. Defined a self-referential node structure.
2. Created the SinglyLL class.
3. Declared first as a private data member.
4. Declared iCount as a private data member.
5. Initialized both members inside the constructor.
6. Created an object of the class.
7. Attempted direct access from main().
8. Compiler prevented unauthorized access.

===============================================================================
Advantages of Private Members:
===============================================================================

• Prevent accidental modification of data.
• Protect internal implementation.
• Maintain data consistency.
• Support encapsulation.
• Improve software security and reliability.

===============================================================================
Time Complexity:
===============================================================================

Constructor      : O(1)
Space Complexity : O(1)

===============================================================================
Conclusion:
===============================================================================

Program 006 demonstrates Data Hiding by declaring first and iCount as private
members of the Singly Linked List class. Since these members cannot be accessed
directly from outside the class, the compiler prevents unauthorized
modifications. This ensures data integrity and forms the basis of
Encapsulation in Object-Oriented Programming.

===============================================================================
*/
