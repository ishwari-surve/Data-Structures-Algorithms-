/*
===============================================================================
Program Name    : InsertFirst() Operation in Singly Circular Linked List
Program Number  : 009
Description     : This program demonstrates the implementation of the
                  InsertFirst() operation in a Singly Circular Linked List
                  using Java. A new node is inserted at the beginning of the
                  list while maintaining the circular link between the last
                  node and the first node. The node counter (iCount) is
                  updated after every successful insertion.

Date            : July 2026
Language        : Java
Author          : Ishwari Vijaykumar Surve
===============================================================================
Concepts Used:
1. Object-Oriented Programming (OOP)
2. Class and Object
3. Constructor
4. Self-Referential Class
5. Dynamic Memory Allocation using new
6. InsertFirst() Operation
7. Circular Linked List
8. Head and Tail Pointer Management
9. Node Counting

Key Learning Points:
- New nodes are created dynamically using new.
- InsertFirst() inserts a node at the beginning.
- first and last references are maintained correctly.
- last.next always points to first.
- iCount stores the total number of nodes.

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
    {}

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
            // Program 10
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

class SinglyCL9
{
    public static void main(String A[])
    {
        SinglyCL sobj = new SinglyCL();

        sobj.InsertFirst(51);
        sobj.InsertFirst(21);
        sobj.InsertFirst(11);
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

 first
   │
   ▼
+------+------+ 
|  51  |   •----+
+------+------+  |
   ▲             |
   |             |
   +-------------+
       last

iCount = 1

-------------------------------------------------------------------------------

After InsertFirst(21)

 first
   │
   ▼
+------+------+     +------+------+
|  21  |   •------->|  51  |   •----+
+------+------+     +------+------+ |
      ▲                        |     |
      |________________________|_____|
                 last

iCount = 2

-------------------------------------------------------------------------------

After InsertFirst(11)

 first
   │
   ▼
+------+------+     +------+------+     +------+------+
|  11  |   •------->|  21  |   •------->|  51  |   •----+
+------+------+     +------+------+     +------+------+ |
      ▲                                           |      |
      |___________________________________________|______|
                           last

iCount = 3

===============================================================================
Explanation:
===============================================================================

The constructor initializes the linked list by setting first and last to
NULL and iCount to 0.

InsertFirst() creates a new node using the parameterized constructor.

If the linked list is empty, both first and last reference the new node.

Otherwise,

• newn.next stores the address of the current first node.
• first is updated to the newly created node.

After every insertion,

last.next = first

is executed to maintain the circular nature of the linked list.

Finally, iCount is incremented to keep track of the total number of nodes.

===============================================================================
Program Flow:
===============================================================================

Create SinglyCL Object
          │
          ▼
Constructor Invoked
          │
          ▼
first = NULL
last = NULL
iCount = 0
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
4. Created new nodes dynamically.
5. Inserted nodes at the beginning of the list.
6. Updated first after each insertion.
7. Maintained circular link using last.next = first.
8. Incremented iCount after every insertion.

===============================================================================
Time Complexity:
===============================================================================

InsertFirst()   : O(1)

Space Complexity: O(1)

===============================================================================
Conclusion:
===============================================================================

Program 009 demonstrates the InsertFirst() operation of a Singly Circular
Linked List. The insertion is performed in constant time by updating the
first reference and maintaining the circular connection through last.next.
The iCount variable accurately keeps track of the number of nodes present
in the linked list.

===============================================================================
*/
