/*
===============================================================================
Program Name    : InsertFirst() and InsertLast() in Singly Circular Linked List
Program Number  : 010
Description     : This program demonstrates the implementation of
                  InsertFirst() and InsertLast() operations in a
                  Singly Circular Linked List using Java.

                  InsertFirst() inserts a new node at the beginning,
                  while InsertLast() inserts a new node at the end of
                  the linked list. After every insertion, the circular
                  link is maintained by updating last.next to first.

Date            : July 2026
Language        : Java
Author          : Ishwari Vijaykumar Surve
===============================================================================
Concepts Used:
1. Object-Oriented Programming (OOP)
2. Class and Object
3. Constructor
4. Self-Referential Class
5. Dynamic Memory Allocation
6. InsertFirst() Operation
7. InsertLast() Operation
8. Circular Linked List
9. Head and Tail Pointer Management
10. Node Counting

Key Learning Points:
- InsertFirst() inserts a node at the beginning.
- InsertLast() inserts a node at the end.
- first always points to the first node.
- last always points to the last node.
- last.next always points back to first.
- iCount maintains the total number of nodes.

===============================================================================
*/
// Singly Circular Linked List in Java

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

    public void Display()
    {
    }

    public int Count()
    {
        return iCount;
    }

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

    public void InsertAtPos(int no, int iPos)
    {
    }

    public void DeleteFirst()
    {
    }

    public void DeleteLast()
    {
    }

    public void DeleteAtPos(int iPos)
    {
    }
}

class SinglyCL10
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
    }
}
/*
===============================================================================
Expected Output:
===============================================================================

(No Output)

===============================================================================
Memory Representation:
===============================================================================

Initially

first = NULL
last  = NULL
iCount = 0

-------------------------------------------------------------------------------

After InsertFirst(51)
After InsertFirst(21)
After InsertFirst(11)

                 first
                   │
                   ▼
        +------+      +------+      +------+
        | 11 | •----->| 21 | •----->| 51 | •----+
        +------+      +------+      +------+    |
            ▲                                  |
            |__________________________________|
                         last

iCount = 3

-------------------------------------------------------------------------------

After InsertLast(101)
After InsertLast(111)
After InsertLast(121)

                 first
                   │
                   ▼
 +------+    +------+    +------+    +-------+    +-------+    +-------+
 | 11 | •--->| 21 | •--->| 51 | •--->| 101 | •--->| 111 | •--->| 121 | •--+
 +------+    +------+    +------+    +-------+    +-------+    +-------+   |
      ▲                                                                    |
      |____________________________________________________________________|
                                   last

iCount = 6

===============================================================================
Explanation:
===============================================================================

The constructor initializes the linked list by setting first and last to
NULL and iCount to 0.

InsertFirst() creates a new node and inserts it at the beginning of the
linked list.

If the list is empty,

• first and last both point to the new node.

Otherwise,

• newn.next points to the current first node.
• first is updated to the new node.

InsertLast() creates a new node and inserts it at the end of the linked
list.

If the list is empty,

• first and last both point to the new node.

Otherwise,

• last.next points to the new node.
• last is updated to the newly inserted node.

After every insertion, the statement

last.next = first;

maintains the circular structure of the linked list.

The iCount variable is incremented after each successful insertion.

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
InsertFirst(51)
          │
          ▼
InsertFirst(21)
          │
          ▼
InsertFirst(11)
          │
          ▼
InsertLast(101)
          │
          ▼
InsertLast(111)
          │
          ▼
InsertLast(121)
          │
          ▼
Update last.next = first
          │
          ▼
Increment iCount
          │
          ▼
Program Terminates

===============================================================================
Operations Performed:
===============================================================================

1. Created a Singly Circular Linked List object.
2. Initialized first and last to NULL.
3. Initialized iCount to 0.
4. Inserted three nodes using InsertFirst().
5. Inserted three nodes using InsertLast().
6. Updated first and last references.
7. Maintained the circular link using last.next = first.
8. Incremented iCount after every insertion.

===============================================================================
Time Complexity:
===============================================================================

InsertFirst()   : O(1)

InsertLast()    : O(1)

Space Complexity: O(1)

===============================================================================
Conclusion:
===============================================================================

Program 010 demonstrates insertion at both the beginning and the end of a
Singly Circular Linked List. By maintaining both first and last pointers,
each insertion operation is performed in constant time O(1). The statement
last.next = first preserves the circular nature of the linked list, while
iCount accurately tracks the total number of nodes.

===============================================================================
*/
