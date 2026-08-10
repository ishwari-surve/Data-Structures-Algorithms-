/*
===============================================================================
Program Name    : Queue Basic Structure
Program Number  : 001
File Name       : Queue_01.cpp

Description     : This program contains the basic structure of a Queue using
                  a singly linear linked list. It defines the node structure
                  and Queue class with member functions for Enqueue, Dequeue,
                  Display and Count operations.

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

    return 0;
}
/*
===============================================================================
Expected Output
===============================================================================
No output.

===============================================================================
Algorithm : Queue Basic Structure
===============================================================================

1. Start the program.

2. Define a node structure containing:
   - data
   - next pointer

3. Define the Queue class with:
   - first pointer
   - iCount variable

4. Declare the Queue operations:
   - Enqueue()
   - Dequeue()
   - Display()
   - Count()

5. Initialize first to NULL and iCount to 0 using the constructor.

6. Create an object of the Queue class.

7. Stop the program.

===============================================================================
Program Flow
===============================================================================

              START
                |
                v
       Define Node Structure
                |
                v
         Define Queue Class
                |
                v
      Initialize first = NULL
          iCount = 0
                |
                v
        Create Queue Object
                |
                v
               END

===============================================================================
Time Complexity
===============================================================================

Constructor : O(1)
Count()     : O(1)

No actual Queue operation is performed in this program.

Space Complexity : O(1)

===============================================================================
Conclusion
===============================================================================

This program defines the basic structure of a Queue using a linked list
in C++. It introduces the node structure, Queue class, data members,
constructor and declarations of basic Queue operations. The actual
implementation of Enqueue, Dequeue, Display and Count operations will
be performed in the subsequent programs.

===============================================================================
*/

