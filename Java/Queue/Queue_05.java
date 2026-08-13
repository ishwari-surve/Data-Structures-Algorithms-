/*
===============================================================================
Program Name    : Queue - Dequeue Operation
Program Number  : 05
File Name       : Queue_05.java

Description     : This program implements the Dequeue operation of a Queue
                  using a singly linear linked list. The Dequeue operation
                  removes an element from the first position of the Queue.

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

Key Learning Points:
- Understand the Dequeue operation of a Queue.
- Learn how to delete the first node of a Queue.
- Understand the FIFO principle of Queue.
- Learn how the first pointer is moved to the next node.
- Understand how iCount is updated after deletion.
- Handle the Queue Empty condition.

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

class Queue_05
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

===============================================================================
Memory Representation:
===============================================================================

Before Dequeue:

first
  |
  v
+------+-------+    +------+-------+    +------+-------+    +------+-------+
|  11  |   o-------->|  21  |   o-------->|  51  |   o-------->| 101  | NULL|
+------+-------+    +------+-------+    +------+-------+    +------+-------+


After Dequeue:

first
  |
  v
+------+-------+    +------+-------+    +------+-------+
|  21  |   o-------->|  51  |   o-------->| 101  | NULL|
+------+-------+    +------+-------+    +------+-------+

Removed Node : 11

===============================================================================
Algorithm:
===============================================================================

1. Start the program.
2. Create a Queue object.
3. Initialize first to NULL and iCount to 0.
4. Insert 11, 21, 51 and 101 using Enqueue().
5. Display the Queue elements.
6. Call Count() to display the number of elements.
7. Call Dequeue().
8. Check whether the Queue is empty.
9. If the Queue is empty, display "Queue is Empty".
10. Otherwise, store the data of the first node.
11. Store the first node in temp.
12. Move first to the next node.
13. Set temp to NULL.
14. Decrease iCount by 1.
15. Return the removed element.
16. Display the updated Queue.
17. Display the updated count.
18. Stop the program.

===============================================================================
Program Flow:
===============================================================================

        Start
          |
          v
    Create Queue Object
          |
          v
    Enqueue Elements
          |
          v
     Display Queue
          |
          v
       Count()
          |
          v
      Dequeue()
          |
          v
    Remove First Node
          |
          v
    Update first Pointer
          |
          v
     Decrease iCount
          |
          v
   Display Updated Queue
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

Program 05 demonstrates the Dequeue operation of a Queue using a singly
linear linked list in Java. The first element of the Queue is removed
according to the FIFO (First In First Out) principle. The first pointer
is moved to the next node and iCount is decreased after successful
deletion.

===============================================================================
*/
