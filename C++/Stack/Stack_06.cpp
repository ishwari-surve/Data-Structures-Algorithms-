===============================================================================
Program Name    : Stack - Complete Implementation
Program Number  : 006
File Name       : Stack_06.cpp
Description     : This program demonstrates the complete implementation of a
                  Stack using C++. It performs all fundamental Stack
                  operations including Push(), Pop(), Peep(), Display(),
                  and Count() while following the Last-In-First-Out (LIFO)
                  principle.

Date            : August 2026
Language        : C++
Author          : Ishwari Vijaykumar Surve
===============================================================================

Concepts Used:
1. Class
2. Object-Oriented Programming (OOP)
3. Self-Referential Structure
4. Dynamic Memory Allocation
5. Stack Operations
6. LIFO (Last-In-First-Out)

Key Learning Points:
- Implement the complete Stack using a linked list.
- Perform Push(), Pop(), Peep(), Display(), and Count() operations.
- Understand insertion and deletion at the top of the Stack.
- Maintain the LIFO property throughout all operations.
- Develop a foundation for a Menu-Driven Stack application.

===============================================================================
  // Final Stack
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

// Constructor
Stack::Stack()
{
    this->first = NULL;
    this->iCount = 0;
}

// Push (Insert First)
void Stack::Push(int iNo)
{  
    struct node *newn = NULL;

    newn = new struct node;

    newn->data = iNo;
    newn->next = NULL;
    newn->next = first;
    first = newn;

    iCount++;
}

// Pop (Delete First)
int Stack::Pop()
{
    int iValue = 0;
    struct node *temp = NULL;

    if(first == NULL)
    {
        cout<<"Stack is Empty";
        return -1;
    }
    else
    {
       iValue = first->data;
       temp = first;

       first = first->next;
       delete temp;

       iCount--;
       return iValue;
    }
    
}

// Peep (Top Element)
int Stack::Peep()
{
    
    int iValue = 0;
    
    if(first == NULL)
    {
        cout<<"Stack is Empty";
        return -1;
    }
    else
    {
       iValue = first->data;
       
       return iValue;
    }
    
}

// Display
void Stack::Display()
{
    struct node *temp = NULL;
    temp = first;
    
    while(temp != NULL)
    {
        cout<<"| "<<temp->data<<" |\n";
        temp = temp->next;
    }

    cout<<"NULL\n";
    
}

// Count
int Stack::Count()
{
    return iCount;
}

// Main
int main()
{
    Stack sobj;
    int iRet = 0;

    sobj.Push(11);
    sobj.Push(21);
    sobj.Push(51);
    sobj.Push(101);

    sobj.Display();
    iRet =sobj.Count();
    cout<<"Number of nodes are :"<<iRet<<"\n";

    iRet = sobj.Pop();
    
    cout<<"Removed element is :"<<iRet<<"\n";

    sobj.Display();
    iRet =sobj.Count();
    cout<<"Number of nodes are :"<<iRet<<"\n";

    iRet = sobj.Peep();

    cout<<"Peeped element is :"<<iRet<<"\n";

    sobj.Display();
    iRet =sobj.Count();
    cout<<"Number of nodes are :"<<iRet<<"\n";

    return 0;
}
/*
===============================================================================
Expected Output:
===============================================================================

Current Stack is :

| 101 |
| 51 |
| 21 |
| 11 |
NULL

Number of nodes are : 4

Top element is : 101

Removed element is : 101

Stack after Pop() :

| 51 |
| 21 |
| 11 |
NULL

Number of nodes are : 3

===============================================================================
Memory Representation:
===============================================================================

Before Pop()

                TOP
                 │
                 ▼
            +--------+
            | 101 | •──┐
            +--------+  │
                        ▼
            +--------+
            |  51 | •──┐
            +--------+  │
                        ▼
            +--------+
            |  21 | •──┐
            +--------+  │
                        ▼
            +--------+
            |  11 | ───► NULL
            +--------+

↓

After Pop()

                TOP
                 │
                 ▼
            +--------+
            |  51 | •──┐
            +--------+  │
                        ▼
            +--------+
            |  21 | •──┐
            +--------+  │
                        ▼
            +--------+
            |  11 | ───► NULL
            +--------+

===============================================================================
Algorithm:
===============================================================================

1. Create an empty Stack.
2. Insert elements using Push().
3. Display the Stack.
4. Count the total elements.
5. Retrieve the top element using Peep().
6. Remove the top element using Pop().
7. Display the updated Stack.
8. Display the updated count.
9. Stop.

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

Program 006 demonstrates the complete implementation of a Stack using C++.
It performs all fundamental Stack operations including Push(), Pop(),
Peep(), Display(), and Count(), while maintaining the LIFO
(Last-In-First-Out) property of the Stack.

===============================================================================
*/
