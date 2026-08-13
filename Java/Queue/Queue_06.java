/*
===============================================================================
Program Name    : Queue - Complete Application
Program Number  : 06
File Name       : Queue_06.java

Description     : This program demonstrates multiple Dequeue operations of a
                  Queue using a singly linear linked list. Elements are
                  removed from the first position of the Queue according
                  to the FIFO (First In First Out) principle.

Date            : August 2026
Language        : Java
Author          : Ishwari Vijaykumar Surve
===============================================================================

Concepts Used:
1. Class
2. Object-Oriented Programming (OOP)
3. Self-Referential Class
4. Constructor
5. Singly Linear Linked List
6. Queue
7. Enqueue Operation
8. Dequeue Operation
9. Display Operation
10. Count Operation
11. FIFO Principle

Key Learning Points:
- Understand multiple Dequeue operations.
- Learn how elements are removed from the first position.
- Understand the FIFO principle of Queue.
- Learn how the first pointer changes after deletion.
- Understand how iCount is updated after every Dequeue operation.
- Display the Queue after each deletion.
- Track the number of remaining Queue elements.

===============================================================================
*/

class node
{
    public int data;
    public node next;
}

class Queue
{
    private node first;
    private int iCount;

    public Queue()
    {
        first = null;
        iCount = 0;
    }

    ///////////////////////////////////////////////////////////////////////////
    //
    // Function Name : Enqueue
    // Description   : Insert element at Last
    //
    ///////////////////////////////////////////////////////////////////////////

    public void Enqueue(int iNo)
    {
        node newn = null;
        node temp = null;

        newn = new node();

        newn.data = iNo;
        newn.next = null;

        if(first == null)
        {
            first = newn;
        }
        else
        {
            temp = first;

            while(temp.next != null)
            {
                temp = temp.next;
            }

            temp.next = newn;
        }

        iCount++;
    }

    ///////////////////////////////////////////////////////////////////////////
    //
    // Function Name : Dequeue
    // Description   : Delete element from First
    //
    ///////////////////////////////////////////////////////////////////////////

    public int Dequeue()
    {
        int iValue = 0;
        node temp = null;

        if(first == null)
        {
            System.out.println("Queue is Empty");
            return -1;
        }

        iValue = first.data;

        temp = first;
        first = first.next;
        temp = null;

        iCount--;

        return iValue;
    }

    ///////////////////////////////////////////////////////////////////////////
    //
    // Function Name : Display
    // Description   : Display Queue
    //
    ///////////////////////////////////////////////////////////////////////////

    public void Display()
    {
        node temp = first;

        System.out.println("\nElements of Queue are : ");

        while(temp != null)
        {
            System.out.print("|"+temp.data+"| -> ");
            temp = temp.next;
        }

        System.out.println("NULL");
    }

    ///////////////////////////////////////////////////////////////////////////
    //
    // Function Name : Count
    // Description   : Count number of elements
    //
    ///////////////////////////////////////////////////////////////////////////

    public int Count()
    {
        return iCount;
    }
}

class Queue_06
{
    public static void main(String A[])
    {
        Queue qobj = new Queue();

        int iRet = 0;

        qobj.Enqueue(11);
        qobj.Enqueue(21);
        qobj.Enqueue(51);
        qobj.Enqueue(101);

        qobj.Display();

        iRet = qobj.Count();

        System.out.println("\nNumber of Elements : "+iRet);

        iRet = qobj.Dequeue();

        System.out.println("\nRemoved Element : "+iRet);

        qobj.Display();

        iRet = qobj.Count();

        System.out.println("\nNumber of Elements : "+iRet);

        iRet = qobj.Dequeue();

        System.out.println("\nRemoved Element : "+iRet);

        qobj.Display();

        iRet = qobj.Count();

        System.out.println("\nNumber of Elements : "+iRet);
    }
}

/*
===============================================================================
Expected Output:
===============================================================================

Elements of Queue are :
|11| -> |21| -> |51| -> |101| -> NULL

Number of Elements : 4

Removed Element : 11

Elements of Queue are :
|21| -> |51| -> |101| -> NULL

Number of Elements : 3

Removed Element : 21

Elements of Queue are :
|51| -> |101| -> NULL

Number of Elements : 2

===============================================================================
Memory Representation:
===============================================================================

Initial Queue:

first
  |
  v
+------+-------+    +------+-------+    +------+-------+    +------+-------+
|  11  |   o-------->|  21  |   o-------->|  51  |   o-------->| 101  | NULL|
+------+-------+    +------+-------+    +------+-------+    +------+-------+


After First Dequeue:

first
  |
  v
+------+-------+    +------+-------+    +------+-------+
|  21  |   o-------->|  51  |   o-------->| 101  | NULL|
+------+-------+    +------+-------+    +------+-------+


After Second Dequeue:

first
  |
  v
+------+-------+    +------+-------+
|  51  |   o-------->| 101  | NULL|
+------+-------+    +------+-------+

===============================================================================
Algorithm:
===============================================================================

1. Start the program.
2. Create a Queue object.
3. Initialize first to NULL and iCount to 0.
4. Insert 11, 21, 51 and 101 using Enqueue().
5. Display the Queue elements.
6. Count and display the number of Queue elements.
7. Call Dequeue() for the first time.
8. Store the data of the first node.
9. Move first to the next node.
10. Decrease iCount.
11. Display the removed element.
12. Display the updated Queue.
13. Display the updated count.
14. Call Dequeue() for the second time.
15. Remove the current first node.
16. Move first to the next node.
17. Decrease iCount.
18. Display the removed element.
19. Display the updated Queue.
20. Display the updated count.
21. Stop the program.

===============================================================================
Program Flow:
===============================================================================

        Start
          |
          v
    Create Queue Object
          |
          v
    Enqueue 4 Elements
          |
          v
     Display Queue
          |
          v
       Count()
          |
          v
      Dequeue 1
          |
          v
    Update first Pointer
          |
          v
     Display Queue
          |
          v
       Count()
          |
          v
      Dequeue 2
          |
          v
    Update first Pointer
          |
          v
     Display Queue
          |
          v
       Count()
          |
          v
         Stop

===============================================================================
Time Complexity:
===============================================================================

Enqueue() : O(n)
Dequeue() : O(1)
Display() : O(n)
Count()   : O(1)

===============================================================================
Space Complexity:
===============================================================================

O(n) total space for n Queue nodes.

===============================================================================
Conclusion:
===============================================================================

Program 06 demonstrates multiple Dequeue operations in a Queue using a
singly linear linked list in Java. The elements 11 and 21 are removed
sequentially from the front of the Queue, demonstrating the FIFO
(First In First Out) principle. The first pointer and iCount are updated
after every successful Dequeue operation.

===============================================================================
*/
