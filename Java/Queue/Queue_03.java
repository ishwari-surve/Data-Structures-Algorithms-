/*
===============================================================================
Program Name    : Queue - Display Operation
Program Number  : 03
File Name       : Queue_03.java

Description     : This program implements the Display operation of a Queue
                  using a singly linear linked list. The Display operation
                  traverses the Queue from the first node and displays all
                  elements.

Date            : August 2026
Language        : Java
Author          : Ishwari Vijaykumar Surve
===============================================================================

Concepts Used:
1. Class
2. Object-Oriented Programming (OOP)
3. Self-Referential Class
4. Constructor
5. Dynamic Memory Allocation
6. Singly Linear Linked List
7. Queue
8. Enqueue Operation
9. Display Operation

Key Learning Points:
- Understand the basic structure of a Queue in Java.
- Learn how a Queue is represented using a linked list.
- Understand insertion of elements at the last position.
- Learn how to traverse a linked list.
- Display all elements of the Queue.
- Understand the use of first and next references.

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
        node temp = null;

        temp = first;

        System.out.println("\nElements of Queue are : ");

        while(temp != null)
        {
            System.out.print("| " + temp.data + " | -> ");
            temp = temp.next;
        }

        System.out.println("NULL");
    }
}

class Queue_03
{
    public static void main(String A[])
    {
        Queue qobj = new Queue();

        qobj.Enqueue(11);
        qobj.Enqueue(21);
        qobj.Enqueue(51);
        qobj.Enqueue(101);

        qobj.Display();
    }
}

/*
===============================================================================
Expected Output:
===============================================================================

Elements of Queue are :
| 11 | -> | 21 | -> | 51 | -> | 101 | -> NULL

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
5. Create a new node for every element.
6. Traverse the Queue until the last node.
7. Connect the new node at the last position.
8. Increment iCount after every insertion.
9. Call Display().
10. Start traversal from the first node.
11. Display the data of every node.
12. Move temp to the next node.
13. Continue until temp becomes NULL.
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
   Initialize first = NULL
          |
          v
    Enqueue Elements
          |
          v
     Call Display()
          |
          v
 Traverse from first node
          |
          v
   Display Queue Elements
          |
          v
         Stop

===============================================================================
Time Complexity:
===============================================================================

Enqueue() : O(n)
Display() : O(n)

===============================================================================
Space Complexity:
===============================================================================

O(n) total space for n Queue nodes.

===============================================================================
Conclusion:
===============================================================================

Program 03 demonstrates the Display operation of a Queue using a singly
linear linked list in Java. The Queue is traversed from the first node and
each element is displayed sequentially until NULL is reached.

===============================================================================
*/
