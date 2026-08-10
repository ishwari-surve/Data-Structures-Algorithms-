/*
===============================================================================

Program Name    : Queue Complete Program
Program Number  : 006
File Name       : Queue_06.cpp

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
    int iValue = 0;
    struct node *temp = NULL;

    if(first == NULL)
    {
        cout<<"Queue is Empty!!!\n";
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

    cout<<"\nQueue Elements : \n";

    while(temp != NULL)
    {
        cout<<"| "<<temp->data<<" |"<<endl;
        temp = temp->next;
    }
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

    qobj.Display();

    iRet = qobj.Count();

    cout<<"\nNumber of Elements in Queue are : "<<iRet<<endl;

    iRet = qobj.Dequeue();

    cout<<"\nRemoved Element : "<<iRet<<endl;

    qobj.Display();

    iRet = qobj.Count();

    cout<<"\nNumber of Elements in Queue are : "<<iRet<<endl;

    iRet = qobj.Dequeue();

    cout<<"\nRemoved Element : "<<iRet<<endl;

    qobj.Display();

    iRet = qobj.Count();

    cout<<"\nNumber of Elements in Queue are : "<<iRet<<endl;

    return 0;
}

/*
===============================================================================
Expected Output
===============================================================================

Queue Elements :
| 11 |
| 21 |
| 51 |
| 101 |

Number of Elements in Queue are : 4

Removed Element : 11

Queue Elements :
| 21 |
| 51 |
| 101 |

Number of Elements in Queue are : 3

Removed Element : 21

Queue Elements :
| 51 |
| 101 |

Number of Elements in Queue are : 2

===============================================================================
Algorithm
===============================================================================

1. Start.
2. Create a Queue object.
3. Initialize first to NULL and iCount to 0.
4. Insert 11, 21, 51 and 101 using Enqueue().
5. Display all Queue elements using Display().
6. Call Count() to get the total number of elements.
7. Call Dequeue() to remove the first element.
8. Store the data of the first node.
9. Move first to the next node.
10. Delete the previous first node.
11. Decrease iCount by 1.
12. Display the removed element.
13. Display the updated Queue.
14. Count and display the remaining elements.
15. Perform Dequeue() again.
16. Display the updated Queue and count.
17. Stop.

===============================================================================
Program Flow
===============================================================================

Start
  |
  v
Create Queue Object
  |
  v
Initialize first = NULL
iCount = 0
  |
  v
Enqueue 11, 21, 51, 101
  |
  v
Display Queue
  |
  v
Count Elements
  |
  v
Dequeue First Element
  |
  v
Delete First Node
  |
  v
Decrease iCount
  |
  v
Display Updated Queue
  |
  v
Dequeue Again
  |
  v
Display Updated Queue
  |
  v
Count Remaining Elements
  |
  v
Stop

===============================================================================
Time Complexity
===============================================================================

| Operation | Time Complexity |
|-----------|-----------------|
| Enqueue() | O(n) |
| Dequeue() | O(1) |
| Display() | O(n) |
| Count() | O(1) |

===============================================================================
Space Complexity
===============================================================================

O(n)

Where n is the number of elements present in the Queue.

===============================================================================
Conclusion
===============================================================================

This program successfully implements the Queue data structure using a
singly linear linked list. It demonstrates insertion using Enqueue(),
deletion using Dequeue(), displaying elements using Display(), and
maintaining the number of elements using Count(). The Queue follows the
FIFO (First In First Out) principle.

===============================================================================
*/

