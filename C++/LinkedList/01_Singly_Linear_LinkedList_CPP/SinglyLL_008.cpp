/*
===============================================================================
Program Name    : Singly Linked List using Scope Resolution Operator
Program Number  : 008 
Description     : This program demonstrates how member functions of a Singly
                  Linked List class can be declared inside the class and
                  defined outside using the Scope Resolution Operator (::).
                  This improves code organization, readability, and follows
                  standard Object-Oriented Programming practices.
Date            : July 2026
Language        : C++
Author          : Ishwari Vijaykumar Surve
===============================================================================

Concepts Used:
1. Object-Oriented Programming (OOP)
2. Class and Object
3. Constructor
4. Scope Resolution Operator (::)
5. Function Declaration
6. Function Definition
7. Encapsulation
8. Data Hiding

Key Learning Points:
- Member functions can be declared inside the class.
- Function definitions can be written outside the class.
- Scope Resolution Operator (::) connects declarations with definitions.
- Separating interface and implementation improves code readability.
- This approach is commonly used in large C++ applications.

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

class SinglyLL
{
    private:

        PNODE first;
        int iCount;

    public:

        SinglyLL();

        void Display();
        int Count();

        void InsertFirst(int iNo);
        void InsertLast(int iNo);
        void InsertAtPos(int iNo,int iPos);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int iPos);
};

/*
===============================================================================
Constructor Definition
===============================================================================
*/

SinglyLL::SinglyLL()
{
    cout<<"Inside Constructor\n";

    this->first = NULL;
    this->iCount = 0;
}

/*
===============================================================================
Member Function Definitions
===============================================================================
*/

void SinglyLL::Display()
{
}

int SinglyLL::Count()
{
    return this->iCount;
}

void SinglyLL::InsertFirst(int iNo)
{
}

void SinglyLL::InsertLast(int iNo)
{
}

void SinglyLL::InsertAtPos(int iNo,int iPos)
{
}

void SinglyLL::DeleteFirst()
{
}

void SinglyLL::DeleteLast()
{
}

void SinglyLL::DeleteAtPos(int iPos)
{
}

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
Class Representation:
===============================================================================

                SinglyLL
      +-----------------------------+
      | first   (private)           |
      | iCount  (private)           |
      +-----------------------------+
      | Display()                   |
      | Count()                     |
      | InsertFirst()               |
      | InsertLast()                |
      | InsertAtPos()               |
      | DeleteFirst()               |
      | DeleteLast()                |
      | DeleteAtPos()               |
      +-----------------------------+

===============================================================================
Explanation:
===============================================================================

This program demonstrates the use of the Scope Resolution Operator (::) to
define member functions outside the class.

Inside the class, only the function prototypes (declarations) are provided.
The actual implementation of each member function is written separately using
the syntax:

ReturnType ClassName::FunctionName()
{
    // Function Definition
}

This approach separates the interface of the class from its implementation,
making the program cleaner, easier to understand, and simpler to maintain.

The constructor initializes the linked list by setting first to NULL and
iCount to 0.

===============================================================================
Program Flow:
===============================================================================

Declare SinglyLL Class
          │
          ▼
Declare Member Functions
          │
          ▼
Define Functions using ::
          │
          ▼
Create SinglyLL Object
          │
          ▼
Constructor Invoked
          │
          ▼
Initialize first = NULL
Initialize iCount = 0
          │
          ▼
Program Terminates

===============================================================================
Operations Performed:
===============================================================================

1. Defined a self-referential node structure.
2. Created the SinglyLL class.
3. Declared all member functions inside the class.
4. Defined member functions outside the class.
5. Used the Scope Resolution Operator (::).
6. Initialized first and iCount in the constructor.
7. Created an object of the SinglyLL class.

===============================================================================
Advantages of Scope Resolution Operator:
===============================================================================

• Separates declaration from implementation.
• Improves code readability.
• Makes programs easier to maintain.
• Supports modular programming.
• Widely used in professional C++ development.

===============================================================================
Time Complexity:
===============================================================================

Constructor      : O(1)
Count()          : O(1)
Space Complexity : O(1)

===============================================================================
Conclusion:
===============================================================================

Program 008 demonstrates how the Scope Resolution Operator (::) is used to
define member functions outside the class. This programming style improves
code organization, promotes modularity, and is considered a standard practice
for developing large-scale Object-Oriented C++ applications.

===============================================================================
*/
