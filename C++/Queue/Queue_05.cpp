/*
===============================================================================
Program Name    : Queue Using Singly Linear Linked List
Program Number  : 05
File Name       : Queue_05.cpp

Description     : This program implements Enqueue, Dequeue, Display
                  and Count operations of Queue using a singly
                  linear linked list.

Date            : August 2026
Language        : C++
Author          : Ishwari Vijaykumar Surve
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

class Queue
{
private:
    struct node *first;
    int iCount;

public:
    Queue();
    void Enqueue(int iNo);
    int Dequeue();
    void Display();
    int Count();
};

///////////////////////////////////////////////////////////////////////////////
//
// Constructor
//
///////////////////////////////////////////////////////////////////////////////

Queue :: Queue()
{
    this->first = NULL;
    this->iCount = 0;
}

///////////////////////////////////////////////////////////////////////////////
//
// Function Name : Enqueue
// Description   : Insert element at Last position
//
///////////////////////////////////////////////////////////////////////////////

void Queue :: Enqueue(int iNo)
{
    struct node *newn = NULL;
    struct node *temp = NULL;

    newn = new struct node();

    newn->data = iNo;
    newn->next = NULL;

    if(first == NULL)
    {
        first = newn;
    }
    else
    {
        temp = first;

        while(temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newn;
    }

    iCount++;
}

///////////////////////////////////////////////////////////////////////////////
//
// Function Name : Dequeue
// Description   : Delete element from First position
//
///////////////////////////////////////////////////////////////////////////////

int Queue :: Dequeue()
{
    struct node *temp = NULL;
    int iValue = 0;

    if(first == NULL)
    {
        cout<<"Queue is Empty"<<endl;
        return -1;
    }

    iValue = first->data;

    temp = first;
    first = first->next;

    delete temp;

    iCount--;

    return iValue;
}

///////////////////////////////////////////////////////////////////////////////
//
// Function Name : Display
// Description   : Display Queue elements
//
///////////////////////////////////////////////////////////////////////////////

void Queue :: Display()
{
    struct node *temp = NULL;

    temp = first;

    while(temp != NULL)
    {
        cout<<"| "<<temp->data<<" | -> ";
        temp = temp->next;
    }

    cout<<"NULL"<<endl;
}

///////////////////////////////////////////////////////////////////////////////
//
// Function Name : Count
// Description   : Return number of elements
//
///////////////////////////////////////////////////////////////////////////////

int Queue :: Count()
{
    return iCount;
}

///////////////////////////////////////////////////////////////////////////////
//
// Entry Point Function
//
///////////////////////////////////////////////////////////////////////////////

int main()
{
    Queue qobj;
    int iRet = 0;

    qobj.Enqueue(11);
    qobj.Enqueue(21);
    qobj.Enqueue(51);
    qobj.Enqueue(101);

    cout<<"Queue Elements : "<<endl;
    qobj.Display();

    iRet = qobj.Dequeue();

    cout<<"Removed Element : "<<iRet<<endl;

    cout<<"Queue after Dequeue : "<<endl;
    qobj.Display();

    iRet = qobj.Count();

    cout<<"Number of Elements in Queue are : "<<iRet<<endl;

    return 0;
}
/*
===============================================================================
Expected Output
===============================================================================
Queue Elements :
| 11 | -> | 21 | -> | 51 | -> | 101 | -> NULL

Removed Element : 11

Queue after Dequeue :
| 21 | -> | 51 | -> | 101 | -> NULL

Number of Elements in Queue are : 3

===============================================================================
Memory Diagram
===============================================================================
After inserting 11, 21, 51, 101

===============================================================================
Algorithm
===============================================================================
1. Start
2. Create a Queue object.
3. Initialize first to NULL and iCount to 0.
4. Insert elements using Enqueue().
5. Display all Queue elements.
6. Call Dequeue().
7. Store the data of the first node.
8. Move first to the next node.
9. Delete the previous first node.
10. Decrease iCount.
11. Display the removed element.
12. Display the updated Queue.
13. Count and display the remaining elements.
14. Stop.

===============================================================================
Time Complexity
===============================================================================
| **Operation** | **Time Complexity** |
| ------------- | ------------------: |
| **Enqueue()** |            **O(n)** |
| **Dequeue()** |            **O(1)** |
| **Display()** |            **O(n)** |
| **Count()**   |            **O(1)** |

===============================================================================
Conclusion
===============================================================================
The program successfully implements a Queue using a Singly Linear Linked List.
The Enqueue operation inserts elements at the rear of the Queue.
The Dequeue operation removes elements from the front of the Queue.
The program follows the FIFO (First In First Out) principle.
The program also demonstrates dynamic memory allocation, classes, objects, pointers,
and member functions in C++.
===============================================================================
*/

