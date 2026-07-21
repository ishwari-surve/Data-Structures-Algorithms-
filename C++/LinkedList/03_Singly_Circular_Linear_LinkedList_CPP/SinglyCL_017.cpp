/*
===============================================================================
Program Name    : Menu Driven Singly Circular Linked List
Program Number  : 017
Description     : This program implements a Menu Driven Singly Circular Linked
                  List. Users can perform insertion, deletion, display,
                  counting and position-based operations interactively.

Date            : July 2026
Language        : C++
Author          : Ishwari Vijaykumar Surve
===============================================================================

Concepts Used:

1. Class and Objects
2. Self-Referential Structure
3. Dynamic Memory Allocation
4. Constructor
5. Member Functions
6. Encapsulation
7. Circular Linked List
8. Menu Driven Programming
9. Switch Case
10. Looping

===============================================================================

Operations Implemented

✔ InsertFirst()
✔ InsertLast()
✔ InsertAtPos()

✔ DeleteFirst()
✔ DeleteLast()
✔ DeleteAtPos()

✔ Display()
✔ Count()

===============================================================================

Key Learning Points

• Complete implementation of Singly Circular Linked List.
• Menu Driven approach.
• User interaction using switch-case.
• Position validation.
• Dynamic memory management.
• Reusability of member functions.

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

    void Display();
    int Count();

    void InsertFirst(int);
    void InsertLast(int);
    void InsertAtPos(int,int);

    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPos(int);
};
SinglyCL::SinglyCL()
{
    first = NULL;
    last = NULL;
    iCount = 0;
}
///////////////////////////////////////////////////////////////////////////

void SinglyCL::Display()
{
    if(first == NULL && last == NULL)
    {
        return;
    }

    PNODE temp = first;

    do
    {
        cout<<"| "<<temp->data<<" | -> ";
        temp = temp->next;
    }while(temp != last->next);

    cout<<endl;
}

///////////////////////////////////////////////////////////////////////////

int SinglyCL::Count()
{
    return iCount;
}

///////////////////////////////////////////////////////////////////////////

void SinglyCL::InsertFirst(int iNo)
{
    PNODE newn = new NODE;

    newn->data = iNo;
    newn->next = NULL;

    if(first == NULL && last == NULL)
    {
        first = newn;
        last = newn;
    }
    else
    {
        newn->next = first;
        first = newn;
    }

    last->next = first;

    iCount++;
}

///////////////////////////////////////////////////////////////////////////

void SinglyCL::InsertLast(int iNo)
{
    PNODE newn = new NODE;

    newn->data = iNo;
    newn->next = NULL;

    if(first == NULL && last == NULL)
    {
        first = newn;
        last = newn;
    }
    else
    {
        last->next = newn;
        last = newn;
    }

    last->next = first;

    iCount++;
}

///////////////////////////////////////////////////////////////////////////

void SinglyCL::DeleteFirst()
{
    if(first == NULL && last == NULL)
    {
        return;
    }
    else if(first == last)
    {
        delete first;
        first = NULL;
        last = NULL;
    }
    else
    {
        first = first->next;
        delete last->next;
        last->next = first;
    }

    iCount--;
}

void SinglyCL::DeleteLast()
{
    if(first == NULL && last == NULL)
    {
        return;
    }
    else if(first == last)
    {
        delete first;
        first = NULL;
        last = NULL;
    }
    else
    {
        PNODE temp = first;

        while(temp->next != last)
        {
            temp = temp->next;
        }

        delete last;
        last = temp;
        last->next = first;
    }

    iCount--;
}
void SinglyCL::InsertAtPos(int iNo, int iPos)
{
    if((iPos < 1) || (iPos > iCount + 1))
    {
        cout<<"Invalid Position\n";
        return;
    }

    if(iPos == 1)
    {
        InsertFirst(iNo);
    }
    else if(iPos == iCount + 1)
    {
        InsertLast(iNo);
    }
    else
    {
        PNODE newn = new NODE;
        PNODE temp = first;

        newn->data = iNo;
        newn->next = NULL;

        for(int i = 1; i < iPos - 1; i++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        temp->next = newn;

        iCount++;
    }
}

///////////////////////////////////////////////////////////////////////////

void SinglyCL::DeleteAtPos(int iPos)
{
    if((iPos < 1) || (iPos > iCount))
    {
        cout<<"Invalid Position\n";
        return;
    }

    if(iPos == 1)
    {
        DeleteFirst();
    }
    else if(iPos == iCount)
    {
        DeleteLast();
    }
    else
    {
        PNODE temp = first;
        PNODE target = NULL;

        for(int i = 1; i < iPos-1; i++)
        {
            temp = temp->next;
        }

        target = temp->next;
        temp->next = target->next;

        delete target;

        iCount--;
    }
}

/*
================================================================================
Main Function: Menu-Driven Interface
Purpose: Provide interactive console application for all operations
================================================================================
*/
int main()
{
    SinglyCL sobj;

    int iChoice = 1;
    int iValue = 0;
    int iPos = 0;
    int iRet = 0;

    while(iChoice != 0)
    {
        cout << "\n--------------------------------------\n";
        cout << "Singly Circular Linked List\n";
        cout << "--------------------------------------\n";

        cout << "1 : Insert First\n";
        cout << "2 : Insert Last\n";
        cout << "3 : Insert At Position\n";
        cout << "4 : Delete First\n";
        cout << "5 : Delete Last\n";
        cout << "6 : Delete At Position\n";
        cout << "7 : Display\n";
        cout << "8 : Count\n";
        cout << "0 : Exit\n";

        cout << "\nEnter your choice : ";
        cin >> iChoice;

        switch(iChoice)
        {
            case 1:
                cout << "Enter data : ";
                cin >> iValue;
                sobj.InsertFirst(iValue);
                cout << "Node inserted at first\n";
                break;

            case 2:
                cout << "Enter data : ";
                cin >> iValue;
                sobj.InsertLast(iValue);
                cout << "Node inserted at last\n";
                break;

            case 3:
                cout << "Enter data : ";
                cin >> iValue;
                cout << "Enter Position : ";
                cin >> iPos;
                sobj.InsertAtPos(iValue, iPos);
                cout << "Node inserted at position " << iPos << "\n";
                break;

            case 4:
                sobj.DeleteFirst();
                cout << "First node deleted\n";
                break;

            case 5:
                sobj.DeleteLast();
                cout << "Last node deleted\n";
                break;

            case 6:
                cout << "Enter Position : ";
                cin >> iPos;
                sobj.DeleteAtPos(iPos);
                cout << "Node deleted from position " << iPos << "\n";
                break;

            case 7:
                sobj.Display();
                break;

            case 8:
                iRet = sobj.Count();
                cout << "\nNumber of nodes are : " << iRet << "\n";
                break;

            case 0:
                cout << "\nThank you for using Singly Circular Linked List.\n";
                break;

            default:
                cout << "Invalid Choice\n";
                break;
        }
    }

    return 0;
}
*/
/*
===============================================================================
Expected Output:
===============================================================================

--------------------------------------
Singly Circular Linked List
--------------------------------------
1 : Insert First
2 : Insert Last
3 : Insert At Position
4 : Delete First
5 : Delete Last
6 : Delete At Position
7 : Display
8 : Count
0 : Exit

Enter your choice : 1
Enter data : 11

--------------------------------------
Singly Circular Linked List
--------------------------------------
1 : Insert First
2 : Insert Last
3 : Insert At Position
4 : Delete First
5 : Delete Last
6 : Delete At Position
7 : Display
8 : Count
0 : Exit

Enter your choice : 2
Enter data : 21

--------------------------------------
Singly Circular Linked List
--------------------------------------
1 : Insert First
2 : Insert Last
3 : Insert At Position
4 : Delete First
5 : Delete Last
6 : Delete At Position
7 : Display
8 : Count
0 : Exit

Enter your choice : 2
Enter data : 51

--------------------------------------
Singly Circular Linked List
--------------------------------------
1 : Insert First
2 : Insert Last
3 : Insert At Position
4 : Delete First
5 : Delete Last
6 : Delete At Position
7 : Display
8 : Count
0 : Exit

Enter your choice : 7

| 11 | -> | 21 | -> | 51 | ->

--------------------------------------
Singly Circular Linked List
--------------------------------------
1 : Insert First
2 : Insert Last
3 : Insert At Position
4 : Delete First
5 : Delete Last
6 : Delete At Position
7 : Display
8 : Count
0 : Exit

Enter your choice : 8

Number of nodes are : 3

--------------------------------------
Singly Circular Linked List
--------------------------------------
1 : Insert First
2 : Insert Last
3 : Insert At Position
4 : Delete First
5 : Delete Last
6 : Delete At Position
7 : Display
8 : Count
0 : Exit

Enter your choice : 3
Enter data : 31
Enter Position : 3

--------------------------------------
Singly Circular Linked List
--------------------------------------
1 : Insert First
2 : Insert Last
3 : Insert At Position
4 : Delete First
5 : Delete Last
6 : Delete At Position
7 : Display
8 : Count
0 : Exit

Enter your choice : 7

| 11 | -> | 21 | -> | 31 | -> | 51 | ->

--------------------------------------
Singly Circular Linked List
--------------------------------------
1 : Insert First
2 : Insert Last
3 : Insert At Position
4 : Delete First
5 : Delete Last
6 : Delete At Position
7 : Display
8 : Count
0 : Exit

Enter your choice : 6
Enter Position : 2

--------------------------------------
Singly Circular Linked List
--------------------------------------
1 : Insert First
2 : Insert Last
3 : Insert At Position
4 : Delete First
5 : Delete Last
6 : Delete At Position
7 : Display
8 : Count
0 : Exit

Enter your choice : 7

| 11 | -> | 31 | -> | 51 | ->

--------------------------------------
Singly Circular Linked List
--------------------------------------
1 : Insert First
2 : Insert Last
3 : Insert At Position
4 : Delete First
5 : Delete Last
6 : Delete At Position
7 : Display
8 : Count
0 : Exit

Enter your choice : 0

Thank you for using Singly Circular Linked List.

===============================================================================
Memory Representation:
===============================================================================

Example:

User performs the following operations:

InsertFirst(21)
InsertFirst(11)
InsertLast(51)
InsertLast(101)

                     first
                       │
                       ▼
      ┌──────────┐     ┌──────────┐     ┌──────────┐     ┌──────────┐
      │ Data :11 │ ──► │ Data :21 │ ──► │ Data :51 │ ──► │Data :101 │
      └──────────┘     └──────────┘     └──────────┘     └──────────┘
            ▲                                                   │
            │                                                   │
            └───────────────────────────────────────────────────┘
                                ▲
                                │
                              last


first
│
└── Points to the first node.

last
│
└── Points to the last node.

last->next
│
└── Always points back to first, making the list circular.

===============================================================================

Node Structure

      +---------------------------+
      |        data               |
      +---------------------------+
      |        next               |
      +---------------------------+

===============================================================================

Circular Connection

first
  │
  ▼
+----+     +----+     +----+     +-----+
| 11 | ──► | 21 | ──► | 51 | ──► | 101 |
+----+     +----+     +----+     +-----+
  ▲                                       │
  └───────────────────────────────────────┘

There is NO NULL pointer at the end of the list.

===============================================================================
Algorithm:
===============================================================================

1. Start the program.
2. Create an object of the Singly Circular Linked List class.
3. Display the menu repeatedly until the user chooses Exit.
4. Accept the user's choice.
5. Perform the corresponding linked list operation:
      • InsertFirst()
      • InsertLast()
      • InsertAtPos()
      • DeleteFirst()
      • DeleteLast()
      • DeleteAtPos()
      • Display()
      • Count()
6. After completing the operation, display the menu again.
7. If the user enters 0, terminate the program.
8. End.

===============================================================================
Program Flow:
===============================================================================

                Start
                  │
                  ▼
      Create SinglyCL Object
                  │
                  ▼
          Display Menu
                  │
                  ▼
        Read User Choice
                  │
      ┌───────────┼────────────┐
      │           │            │
      ▼           ▼            ▼
   Insert      Delete      Display/Count
      │           │            │
      └───────────┼────────────┘
                  │
                  ▼
         Continue? (Choice ≠ 0)
            │              │
           Yes            No
            │              │
            ▼              ▼
      Display Menu        Exit
            │
            ▼
           End

===============================================================================
Time Complexity:
===============================================================================

InsertFirst()      : O(1)

InsertLast()       : O(1)

InsertAtPos()      : O(n)

DeleteFirst()      : O(1)

DeleteLast()       : O(n)

DeleteAtPos()      : O(n)

Display()          : O(n)

Count()            : O(1)

Overall Space Complexity : O(n)

where n = Number of Nodes in the Linked List.

===============================================================================
Conclusion:
===============================================================================

Program 017 implements a complete Menu Driven Singly Circular Linked List
using C++ classes and dynamic memory allocation. It provides an interactive
interface for performing all fundamental linked list operations such as
insertion, deletion, display, and counting of nodes. This program
demonstrates object-oriented programming concepts, pointer manipulation,
dynamic memory management, and the practical implementation of a circular
linked list, making it an excellent reference for mastering Data Structures.

===============================================================================
*/



