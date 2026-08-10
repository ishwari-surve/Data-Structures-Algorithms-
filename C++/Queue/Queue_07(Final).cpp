/*
===============================================================================

Program Name    : Queue Menu Driven Application
Program Number  : 007
File Name       : Queue_07.cpp

Description     : This program implements a menu-driven Queue application
                  using a singly linear linked list. It provides operations
                  such as Enqueue, Dequeue, Display and Count.


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

    if(first == NULL)
    {
        cout<<"Queue is Empty!!!\n";
        return;
    }

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

    int iChoice = 0;
    int iValue = 0;
    int iRet = 0;

    cout<<"--------------------------------------------------\n";
    cout<<"          Queue Menu Driven Application\n";
    cout<<"--------------------------------------------------\n";

    while(1)
    {
        cout<<"\n--------------------------------------------------\n";
        cout<<"1. Enqueue\n";
        cout<<"2. Dequeue\n";
        cout<<"3. Display\n";
        cout<<"4. Count\n";
        cout<<"5. Exit\n";
        cout<<"--------------------------------------------------\n";

        cout<<"Enter your choice : ";
        cin>>iChoice;

        switch(iChoice)
        {
            case 1:

                cout<<"Enter the data : ";
                cin>>iValue;

                qobj.Enqueue(iValue);

                cout<<"Element inserted successfully\n";
                break;

            case 2:

                iRet = qobj.Dequeue();

                if(iRet != -1)
                {
                    cout<<"Removed Element : "<<iRet<<endl;
                }
                break;

            case 3:

                qobj.Display();
                break;

            case 4:

                iRet = qobj.Count();

                cout<<"Number of Elements : "<<iRet<<endl;
                break;

            case 5:

                cout<<"Thank you for using Queue Application\n";
                return 0;

            default:

                cout<<"Invalid Choice\n";
                break;
        }
    }

    return 0;
}

/*
===============================================================================
Expected Output
===============================================================================

--------------------------------------------------
          Queue Menu Driven Application
--------------------------------------------------

--------------------------------------------------
1. Enqueue
2. Dequeue
3. Display
4. Count
5. Exit
--------------------------------------------------
Enter your choice : 1
Enter the data : 11
Element inserted successfully

--------------------------------------------------
1. Enqueue
2. Dequeue
3. Display
4. Count
5. Exit
--------------------------------------------------
Enter your choice : 1
Enter the data : 21
Element inserted successfully

--------------------------------------------------
1. Enqueue
2. Dequeue
3. Display
4. Count
5. Exit
--------------------------------------------------
Enter your choice : 3

Queue Elements :
| 11 |
| 21 |

--------------------------------------------------
1. Enqueue
2. Dequeue
3. Display
4. Count
5. Exit
--------------------------------------------------
Enter your choice : 4
Number of Elements : 2

--------------------------------------------------
1. Enqueue
2. Dequeue
3. Display
4. Count
5. Exit
--------------------------------------------------
Enter your choice : 2
Removed Element : 11

--------------------------------------------------
1. Enqueue
2. Dequeue
3. Display
4. Count
5. Exit
--------------------------------------------------
Enter your choice : 3

Queue Elements :
| 21 |

--------------------------------------------------
1. Enqueue
2. Dequeue
3. Display
4. Count
5. Exit
--------------------------------------------------
Enter your choice : 5
Thank you for using Queue Application

===============================================================================
Memory Diagram
===============================================================================

After inserting 11 and 21:

        Queue Object
        +----------------------+
        | first --------------+ |
        | iCount = 2          | |
        +----------------------+
                 |
                 v
          +-----------+      +-----------+
          | data = 11 |      | data = 21 |
          | next -----|----->| next =NULL|
          +-----------+      +-----------+
             Node 1              Node 2

===============================================================================
Algorithm
===============================================================================

1. Start the program.

2. Create a Queue object.

3. Initialize first to NULL and iCount to 0.

4. Display the Queue menu.

5. Accept the user's choice.

6. If the choice is Enqueue:
   
   - Accept the element from the user.
   - Create a new node dynamically.
   - Store the element in the new node.
   - Set the next pointer to NULL.
   - If the Queue is empty, assign the new node to first.
   - Otherwise, traverse to the last node.
   - Link the last node with the new node.
   - Increment iCount.

7. If the choice is Dequeue:
   
   - Check whether the Queue is empty.
   - If empty, display "Queue is Empty".
   - Otherwise, store the data of the first node.
   - Move first to the next node.
   - Delete the previous first node.
   - Decrement iCount.
   - Display the removed element.

8. If the choice is Display:
   
   - Check whether the Queue is empty.
   - If not empty, traverse from first to NULL.
   - Display every node's data.

9. If the choice is Count:
   
   - Return and display iCount.

10. If the choice is Exit:
    
    - Display the termination message.
    - Stop the program.

11. Repeat the menu until the user selects Exit.

12. Stop.

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
Display Menu
  |
  v
Accept Choice
  |
  +-------------------+
  |                   |
  v                   v
Enqueue            Dequeue
  |                   |
  v                   v
Insert Node        Delete First Node
  |                   |
  v                   v
Increment          Decrement
iCount             iCount
  |                   |
  +---------+---------+
            |
            v
         Display
            |
            v
       Traverse Queue
            |
            v
          Count
            |
            v
       Display iCount
            |
            v
          Exit?
         /     \
       No       Yes
       |         |
       |         v
       +------> Stop

===============================================================================
Time Complexity
===============================================================================

| Operation | Best Case | Average Case | Worst Case |
|-----------|-----------|--------------|------------|
| Enqueue() | O(1)      | O(n)         | O(n)       |
| Dequeue() | O(1)      | O(1)         | O(1)       |
| Display() | O(n)      | O(n)         | O(n)       |
| Count()   | O(1)      | O(1)         | O(1)       |

Enqueue() takes O(n) in the current implementation because the program
traverses the Queue from the first node to the last node.

===============================================================================
Space Complexity
===============================================================================

O(n)

Where n is the number of nodes currently present in the Queue.

Auxiliary space used by individual operations is O(1), excluding the
dynamically allocated Queue nodes.

===============================================================================
Conclusion
===============================================================================

This program successfully implements a menu-driven Queue application
using a singly linear linked list. It demonstrates the major Queue
operations: Enqueue, Dequeue, Display and Count. The Queue follows the
FIFO (First In First Out) principle, where the element inserted first
is removed first.

===============================================================================
*/

