/*
===============================================================================
Program Name    : Queue Display Operation
Program Number  : 03
File Name       : Queue_03.cpp

Description     : This program implements the Display operation of a Queue
                  using a singly linear linked list. The Display operation
                  traverses the Queue from the first node and displays all
                  the elements.

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

Queue :: Queue()
{
    this->first = NULL;
    this->iCount = 0;
}

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

void Queue :: Display()
{
    struct node *temp = NULL;

    temp = first;

    while(temp != NULL)
    {
        cout<<"| "<<temp->data<<" |"<<endl;
        temp = temp->next;
    }
}

int Queue :: Dequeue()
{
    return 0;
}

int Queue :: Count()
{
    return iCount;
}

int main()
{
    Queue qobj;

    qobj.Enqueue(11);
    qobj.Enqueue(21);
    qobj.Enqueue(51);
    qobj.Enqueue(101);

    qobj.Display();

    return 0;
}
/*
===============================================================================
Expected Output
===============================================================================
| 11 |
| 21 |
| 51 |
| 101 |
  
===============================================================================
Algorithm : Display Queue Elements
===============================================================================

1. Start the program.

2. Create a Queue object.

3. Insert elements into the Queue using Enqueue().

4. Initialize a temporary pointer with first.

5. Check whether the temporary pointer is NULL.

6. If it is not NULL:
   - Display the data of the current node.
   - Move the temporary pointer to the next node.

7. Repeat Step 6 until the temporary pointer becomes NULL.

8. Stop the program.

===============================================================================
Time Complexity
===============================================================================

Enqueue Operation : O(n)

Display Operation : O(n)

Count Operation   : O(1)

Best Case         : O(1)     → Empty Queue for Display
Average Case      : O(n)
Worst Case        : O(n)

Space Complexity  : O(1) auxiliary space

===============================================================================
Conclusion
===============================================================================

This program implements the Display operation of a Queue using a singly
linear linked list. A temporary pointer is used to traverse the Queue
from the first node to the last node, and each element is displayed
sequentially.

===============================================================================
*/
