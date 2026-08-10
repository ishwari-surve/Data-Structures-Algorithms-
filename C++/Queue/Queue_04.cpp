/*
===============================================================================
Program Name    : Queue Count Operation
Program Number  : 004
File Name       : Queue_04.cpp

Description     : This program implements the Count operation of a Queue
                  using a singly linear linked list. The Count operation
                  returns the total number of elements currently present
                  in the Queue.

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

int Queue :: Count()
{
    return iCount;
}

int Queue :: Dequeue()
{
    return 0;
}

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

Number of Elements in Queue are : 4

===============================================================================
Algorithm : Count Queue Elements
===============================================================================

1. Start the program.

2. Create a Queue object.

3. Insert elements into the Queue using Enqueue().

4. Display the Queue elements.

5. Call the Count() function.

6. Return the value of iCount.

7. Display the number of elements present in the Queue.

8. Stop the program.

===============================================================================
Time Complexity
===============================================================================

Enqueue Operation : O(n)

Display Operation : O(n)

Count Operation   : O(1)

Best Case         : O(1)
Average Case      : O(1)
Worst Case        : O(1)

Space Complexity  : O(1) auxiliary space

===============================================================================
Conclusion
===============================================================================

This program implements the Count operation of a Queue using a singly
linear linked list. The iCount data member keeps track of the number of
elements inserted into the Queue. The Count() function directly returns
this value, making the operation efficient with O(1) time complexity.

===============================================================================
*/
