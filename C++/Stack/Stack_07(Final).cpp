/*
=============================================================================== 
Program Name    : Stack - Menu Driven Implementation
Program Number  : 007
File Name       : Stack_07.cpp
Description     : This program demonstrates a menu-driven implementation of
                  Stack using C++. It allows the user to perform Push(),
                  Pop(), Peep(), Display(), and Count() operations
                  interactively while following the LIFO principle.

Date            : August 2026
Language        : C++
Author          : Ishwari Vijaykumar Surve
===============================================================================

Concepts Used:
1. Class
2. Object-Oriented Programming (OOP)
3. Self-Referential Structure
4. Dynamic Memory Allocation
5. Menu Driven Programming
6. LIFO (Last-In-First-Out)

Key Learning Points:
- Perform all Stack operations using a menu.
- Understand dynamic memory allocation.
- Implement Stack using linked lists.
- Maintain the LIFO property.
- Build an interactive Stack application.

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

class Stack
{
private:
    struct node *first;
    int iCount;

public:
    Stack();
    void Push(int iNo);
    int Pop();
    int Peep();
    void Display();
    int Count();
};

//=========================================================
// Constructor
//=========================================================

Stack::Stack()
{
    this->first = NULL;
    this->iCount = 0;
}

//=========================================================
// Push (Insert First)
//=========================================================

void Stack::Push(int iNo)
{
    struct node *newn = NULL;

    newn = new struct node;

    newn->data = iNo;
    newn->next = first;

    first = newn;

    iCount++;
}

//=========================================================
// Pop (Delete First)
//=========================================================

int Stack::Pop()
{
    int iValue = 0;

    struct node *temp = NULL;

    if(first == NULL)
    {
        cout<<"Stack is empty\n";
        return -1;
    }

    temp = first;

    iValue = first->data;

    first = first->next;

    delete temp;

    iCount--;

    return iValue;
}

//=========================================================
// Peep (Top Element)
//=========================================================

int Stack::Peep()
{
    if(first == NULL)
    {
        cout<<"Stack is empty\n";
        return -1;
    }

    return first->data;
}

//=========================================================
// Display
//=========================================================

void Stack::Display()
{
    struct node *temp = first;

    while(temp != NULL)
    {
        cout<<"| "<<temp->data<<" |"<<endl;
        temp = temp->next;
    }

    cout<<"NULL"<<endl;
}

//=========================================================
// Count
//=========================================================

int Stack::Count()
{
    return iCount;
}
//=========================================================
// Main
//=========================================================

int main()
{
    Stack sobj;

    int iChoice = 0;
    int iNo = 0;
    int iRet = 0;

    while(true)
    {
        cout<<"\n-------------------------------------------------\n";
        cout<<"               Stack Operations                  \n";
        cout<<"-------------------------------------------------\n";

        cout<<"1 : Push\n";
        cout<<"2 : Pop\n";
        cout<<"3 : Peep\n";
        cout<<"4 : Display\n";
        cout<<"5 : Count\n";
        cout<<"6 : Exit\n";

        cout<<"\nEnter your choice : ";
        cin>>iChoice;

        switch(iChoice)
        {
            case 1:
                cout<<"Enter the element : ";
                cin>>iNo;

                sobj.Push(iNo);
                break;

            case 2:
                iRet = sobj.Pop();

                if(iRet != -1)
                {
                    cout<<"Removed element is : "<<iRet<<"\n";
                }
                break;

            case 3:
                iRet = sobj.Peep();

                if(iRet != -1)
                {
                    cout<<"Top element is : "<<iRet<<"\n";
                }
                break;

            case 4:
                cout<<"\nElements of Stack are :\n";
                sobj.Display();
                break;

            case 5:
                cout<<"Number of elements are : "<<sobj.Count()<<"\n";
                break;

            case 6:
                cout<<"Thank you for using Stack.\n";
                return 0;

            default:
                cout<<"Invalid choice...\n";
                break;
        }
    }

    return 0;
}
/*
===============================================================================
Expected Output:
===============================================================================

-------------------------------------------------
               Stack Operations
-------------------------------------------------
1 : Push
2 : Pop
3 : Peep
4 : Display
5 : Count
6 : Exit

Enter your choice : 1
Enter the element : 11

Enter your choice : 1
Enter the element : 21

Enter your choice : 1
Enter the element : 51

Enter your choice : 4

Elements of Stack are :

| 51 |
| 21 |
| 11 |
NULL

Enter your choice : 3
Top element is : 51

Enter your choice : 2
Removed element is : 51

Enter your choice : 5
Number of elements are : 2

Enter your choice : 6
Thank you for using Stack.

===============================================================================
Memory Representation:
===============================================================================

                TOP
                 │
                 ▼
            +--------+
            |   51   | •────┐
            +--------+      │
                            ▼
            +--------+
            |   21   | •────┐
            +--------+      │
                            ▼
            +--------+
            |   11   | ───► NULL
            +--------+

iCount = 3

===============================================================================
Algorithm:
===============================================================================

1. Create an empty Stack.
2. Display the menu repeatedly.
3. Accept the user's choice.
4. Perform the selected Stack operation.
5. Display the result.
6. Repeat until the user selects Exit.
7. Stop.

===============================================================================
Time Complexity:
===============================================================================

Push()    : O(1)
Pop()     : O(1)
Peep()    : O(1)
Display() : O(n)
Count()   : O(1)

Space Complexity : O(1)

===============================================================================
Conclusion:
===============================================================================

Program 007 demonstrates the complete Menu-Driven implementation of a Stack
using C++. It allows users to perform Push(), Pop(), Peep(), Display(), and
Count() operations interactively while maintaining the Last-In-First-Out
(LIFO) principle.

===============================================================================
*/
