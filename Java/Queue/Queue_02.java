/*
===============================================================================
Program Name    : Queue - Enqueue Operation
Program Number  : 02
File Name       : Queue_02.java
Description     : This program implements the Enqueue operation of a Queue
                  using a singly linear linked list in Java. The Enqueue
                  operation inserts a new element at the last position
                  of the Queue.

Date            : August 2026
Language        : Java
Author          : Ishwari Vijaykumar Surve
===============================================================================

Concepts Used:
1. Class
2. Object-Oriented Programming (OOP)
3. Self-Referential Class
4. Constructor
5. Object Creation
6. Reference Variable
7. Dynamic Memory Allocation
8. Enqueue Operation
9. Singly Linear Linked List

Key Learning Points:
- Understand the Enqueue operation of a Queue.
- Learn how a new node is created using the new operator.
- Insert a node at the last position of the Queue.
- Understand object references using next.
- Maintain the Queue count using iCount.

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

    ///////////////////////////////////////////////////////////////////////////
    //
    // Constructor
    //
    ///////////////////////////////////////////////////////////////////////////

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
}

class Queue_02
{
    public static void main(String A[])
    {
        Queue qobj = new Queue();

        qobj.Enqueue(11);
        qobj.Enqueue(21);
        qobj.Enqueue(51);
        qobj.Enqueue(101);

        System.out.println("Elements inserted successfully");
    }
}

/*
===============================================================================
Expected Output:
===============================================================================

Elements inserted successfully

===============================================================================
Memory Representation:
===============================================================================

After inserting 11, 21, 51 and 101:

              Queue Object

        +----------------------+
        | first  ------------- |----------------------+
        | iCount = 4           |                      |
        +----------------------+                      |
                                                      v
                                               +-----------+
                                               | data = 11 |
                                               | next  ----|----+
                                               +-----------+    |
                                                                v
                                                         +-----------+
                                                         | data = 21 |
                                                         | next  ----|----+
                                                         +-----------+    |
                                                                          v
                                                                   +-----------+
                                                                   | data = 51 |
                                                                   | next  ----|----+
                                                                   +-----------+    |
                                                                                    v
                                                                             +------------+
                                                                             | data = 101 |
                                                                             | next=NULL  |
                                                                             +------------+

===============================================================================
Queue Representation:
===============================================================================

first
  |
  v
+------+-------+    +------+-------+    +------+-------+    +-------+-------+
|  11  |   o-------->|  21  |   o-------->|  51  |   o-------->|  101  | NULL  |
+------+-------+    +------+-------+    +------+-------+    +-------+-------+

 Node 1              Node 2              Node 3               Node 4

===============================================================================
Algorithm:
===============================================================================

1. Start the program.
2. Create a Queue object.
3. Initialize first to null and iCount to 0.
4. Call Enqueue() with the given element.
5. Create a new node dynamically.
6. Store the given element in the data member.
7. Set the next reference of the new node to null.
8. Check whether the Queue is empty.
9. If the Queue is empty, assign the new node to first.
10. If the Queue is not empty:
    - Start traversal from first.
    - Traverse until the last node.
    - Connect the last node to the new node.
11. Increment iCount by 1.
12. Repeat the Enqueue operation for all elements.
13. Display the success message.
14. Stop the program.

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
    first = null
    iCount = 0
          |
          v
      Enqueue(11)
          |
          v
      Enqueue(21)
          |
          v
      Enqueue(51)
          |
          v
      Enqueue(101)
          |
          v
 Display Success Message
          |
          v
         Stop

===============================================================================
Time Complexity:
===============================================================================

Enqueue() : O(1)  -> When Queue is empty
Enqueue() : O(n)  -> When Queue contains n elements

For n elements:
Total Enqueue operations : O(n²)

===============================================================================
Space Complexity:
===============================================================================

Auxiliary Space : O(1)

Total Space     : O(n) for n Queue nodes

===============================================================================
Conclusion:
===============================================================================

Program 002 implements the Enqueue operation of a Queue using a singly
linear linked list in Java. A new node is created dynamically and inserted
at the last position of the Queue. The iCount variable is incremented after
every successful insertion.

===============================================================================
*/
