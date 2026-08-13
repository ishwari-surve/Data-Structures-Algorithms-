/*
===============================================================================
Program Name    : Queue - Count Operation
Program Number  : 04
File Name       : Queue_04.java

Description     : This program implements the Count operation of a Queue
                  using a singly linear linked list. The Count operation
                  returns the total number of elements currently present
                  in the Queue.

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
8. Display Operation
9. Count Operation
10. Instance Variables

Key Learning Points:
- Understand the basic structure of a Queue in Java.
- Learn how a Queue is represented using a linked list.
- Understand insertion of elements at the last position.
- Learn how iCount keeps track of Queue elements.
- Understand how the Count operation returns the number of elements.
- Learn how to display Queue elements.

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
    // Function Name : Display
    // Description   : Display Queue elements
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

class Queue_04
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
    }
}

/*
===============================================================================
Expected Output:
===============================================================================

Elements of Queue are :
|11| -> |21| -> |51| -> |101| -> NULL

Number of Elements : 4

===============================================================================
Memory Representation:
===============================================================================

                         Queue Object

                 +-----------------------+
                 | first -----------------|------+
                 | iCount = 4             |      |
                 +-----------------------+      |
                                                |
                                                v
                                      +------------------+
                                      | data = 11        |
                                      | next ------------|------+
                                      +------------------+      |
                                                                |
                                                                v
                                                      +------------------+
                                                      | data = 21        |
                                                      | next ------------|------+
                                                      +------------------+      |
                                                                                |
                                                                                v
                                                                      +------------------+
                                                                      | data = 51        |
                                                                      | next ------------|------+
                                                                      +------------------+      |
                                                                                              |
                                                                                              v
                                                                                    +------------------+
                                                                                    | data = 101       |
                                                                                    | next = NULL      |
                                                                                    +------------------+

===============================================================================
Algorithm:
===============================================================================

1. Start the program.
2. Create a Queue object.
3. Initialize first to NULL and iCount to 0.
4. Insert 11, 21, 51 and 101 using Enqueue().
5. Create a new node for each element.
6. Insert every new node at the last position of the Queue.
7. Increment iCount after every successful insertion.
8. Call Display() to display all Queue elements.
9. Call Count() to get the total number of elements.
10. Store the returned value in iRet.
11. Display the number of elements.
12. Stop the program.

===============================================================================
Program Flow:
===============================================================================

        Start
          |
          v
    Create Queue Object
          |
          v
   Initialize Queue
          |
          v
    Enqueue Elements
          |
          v
     Display Queue
          |
          v
       Call Count()
          |
          v
   Display Element Count
          |
          v
         Stop

===============================================================================
Time Complexity:
===============================================================================

Enqueue() : O(n)
Display() : O(n)
Count()   : O(1)

===============================================================================
Space Complexity:
===============================================================================

O(n) total space for n Queue nodes.

===============================================================================
Conclusion:
===============================================================================

Program 04 demonstrates the Count operation of a Queue using a singly
linear linked list in Java. The iCount variable is incremented whenever
a new element is inserted into the Queue. The Count() function returns
the current number of elements in constant time.

===============================================================================
*/
