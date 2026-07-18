/*
===============================================================================
Program Name    : Display Function in Singly Circular Linked List
Program Number  : 011
Description     : This program demonstrates the implementation of the
                  Display() function in a Singly Circular Linked List
                  using Java.

                  The Display() function traverses the circular linked
                  list using a do-while loop and prints all node values.
                  Since the last node points back to the first node,
                  traversal continues until the first node is reached
                  again.

Date            : July 2026
Language        : Java
Author          : Ishwari Vijaykumar Surve
===============================================================================
Concepts Used:
1. Object-Oriented Programming (OOP)
2. Class and Object
3. Constructor
4. Self-Referential Class
5. Circular Linked List
6. Display() Function
7. do-while Loop
8. Traversal
9. Head and Tail Pointer
10. Node Counting

Key Learning Points:
- Display() traverses a circular linked list using a do-while loop.
- Traversal starts from the first node.
- Traversal stops after reaching first again.
- last.next always points to first.
- do-while loop is ideal for circular linked list traversal.
- Empty list is handled separately.

===============================================================================
*/
// Program 11 : Display Function in Singly Circular Linked List

class node
{
    public int data;
    public node next;

    node(int no)
    {
        this.data = no;
        this.next = null;
    }
}

class SinglyCL
{
    public node first;
    public node last;
    public int iCount;

    public SinglyCL()
    {
        this.first = null;
        this.last = null;
        this.iCount = 0;
    }

    ///////////////////////////////////////////////////////////////

    public void Display()
    {
        node temp = first;

        if(first == null && last == null)
        {
            return;
        }

        do
        {
            System.out.print("| " + temp.data + " | -> ");
            temp = temp.next;
        }while(temp != last.next);

        System.out.println();
    }

    ///////////////////////////////////////////////////////////////

    public int Count()
    {
        return iCount;
    }

    ///////////////////////////////////////////////////////////////

    public void InsertFirst(int no)
    {
        node newn = new node(no);

        if(first == null && last == null)
        {
            first = newn;
            last = newn;
        }
        else
        {
            newn.next = first;
            first = newn;
        }

        last.next = first;

        iCount++;
    }

    ///////////////////////////////////////////////////////////////

    public void InsertLast(int no)
    {
        node newn = new node(no);

        if(first == null && last == null)
        {
            first = newn;
            last = newn;
        }
        else
        {
            last.next = newn;
            last = newn;
        }

        last.next = first;

        iCount++;
    }

    ///////////////////////////////////////////////////////////////

    public void InsertAtPos(int no, int iPos)
    {

    }

    ///////////////////////////////////////////////////////////////

    public void DeleteFirst()
    {

    }

    ///////////////////////////////////////////////////////////////

    public void DeleteLast()
    {

    }

    ///////////////////////////////////////////////////////////////

    public void DeleteAtPos(int iPos)
    {

    }
}

///////////////////////////////////////////////////////////////////////////

class SinglyCL11
{
    public static void main(String A[])
    {
        SinglyCL sobj = new SinglyCL();

        sobj.InsertFirst(51);
        sobj.InsertFirst(21);
        sobj.InsertFirst(11);

        sobj.InsertLast(101);
        sobj.InsertLast(111);
        sobj.InsertLast(121);

        sobj.Display();
    }
}
/*
===============================================================================
Expected Output:
===============================================================================

| 11 | -> | 21 | -> | 51 | -> | 101 | -> | 111 | -> | 121 | ->

===============================================================================
Memory Representation:
===============================================================================

                    first
                      │
                      ▼
      +------+    +------+    +------+    +-------+    +-------+    +-------+
      | 11 | •--->| 21 | •--->| 51 | •--->| 101 | •--->| 111 | •--->| 121 | •--+
      +------+    +------+    +------+    +-------+    +-------+    +-------+   |
           ▲                                                                     |
           |_____________________________________________________________________|
                                      last

===============================================================================
Explanation:
===============================================================================

The constructor initializes first and last to NULL and iCount to 0.

InsertFirst() inserts nodes at the beginning of the circular linked list.

InsertLast() inserts nodes at the end of the circular linked list.

After every insertion,

• last.next is updated to point to first.

This maintains the circular structure of the linked list.

The Display() function first checks whether the linked list is empty.

If the list is empty, the function immediately returns.

Otherwise,

• A temporary pointer (temp) is initialized to first.
• A do-while loop prints each node.
• temp moves to the next node after every iteration.
• Traversal continues until temp becomes last.next
  (which is equal to first).

Thus every node is displayed exactly once.

===============================================================================
Program Flow:
===============================================================================

Create SinglyCL Object
          │
          ▼
Constructor Invoked
          │
          ▼
Initialize first = NULL
Initialize last = NULL
Initialize iCount = 0
          │
          ▼
Insert Nodes
          │
          ▼
Maintain Circular Link
(last.next = first)
          │
          ▼
Call Display()
          │
          ▼
Traverse using do-while Loop
          │
          ▼
Display All Nodes
          │
          ▼
Program Terminates

===============================================================================
Operations Performed:
===============================================================================

1. Created a Singly Circular Linked List object.
2. Initialized first and last pointers.
3. Inserted nodes using InsertFirst().
4. Inserted nodes using InsertLast().
5. Maintained the circular link.
6. Traversed the linked list using a do-while loop.
7. Displayed every node exactly once.

===============================================================================
Time Complexity:
===============================================================================

Display()       : O(n)

Space Complexity: O(1)

===============================================================================
Conclusion:
===============================================================================

Program 011 demonstrates the Display() operation of a Singly Circular
Linked List. The do-while loop is the most suitable choice for traversal
because it guarantees that the first node is processed before checking the
termination condition. The loop stops when traversal reaches the starting
node again, ensuring that every node is displayed exactly once while
maintaining the circular nature of the linked list.

===============================================================================
*/
