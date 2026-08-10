/*
===============================================================================
Program Name    : Queue Enqueue Operation
Program Number  : 002
File Name       : Queue_02.cpp

Description     : This program implements the Enqueue operation of a Queue
                  using a singly linear linked list. The Enqueue operation
                  inserts a new element at the last position of the Queue.

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

int Queue :: Dequeue()
{
    return 0;
}

void Queue :: Display()
{
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

    cout<<"Elements inserted successfully"<<endl;

    return 0;
}
/*
===============================================================================
Expected Output
===============================================================================
Elements inserted successfully

===============================================================================
Memory Diagram
===============================================================================
first
  |
  v
+------+-------+    +------+-------+    +------+-------+    +------+-------+
|  11  |   o-------->|  21  |   o-------->|  51  |   o-------->| 101  | NULL|
+------+-------+    +------+-------+    +------+-------+    +------+-------+

        Node 1              Node 2              Node 3              Node 4
  
                
===============================================================================
Algorithm : Enqueue Operation
===============================================================================

1. Start the program.

2. Create a new node dynamically.

3. Store the given element in the data member of the new node.

4. Set the next pointer of the new node to NULL.

5. Check whether the Queue is empty.

6. If the Queue is empty:
   - Assign the new node to first.

7. If the Queue is not empty:
   - Traverse the Queue until the last node.
   - Connect the last node to the new node.

8. Increment iCount by 1.

9. Stop the program.

===============================================================================
Time Complexity
===============================================================================

Enqueue Operation:

Best Case    : O(1)     → Queue is empty
Average Case : O(n)
Worst Case   : O(n)     → Traverse up to the last node

Count()      : O(1)

Space Complexity : O(1) auxiliary space
                    O(n) total space for n Queue nodes

===============================================================================
Conclusion
===============================================================================

This program implements the Enqueue operation of a Queue using a singly
linear linked list. A new node is dynamically created and inserted at
the last position of the Queue. The iCount variable is also updated
after every successful insertion.

===============================================================================
*/
