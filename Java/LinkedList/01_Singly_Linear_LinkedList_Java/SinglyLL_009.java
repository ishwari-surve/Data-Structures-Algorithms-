/*
===============================================================================
Program Name    : Singly Linear Linked List - InsertFirst() and InsertLast()
Program Number  : 009
Description     : This program demonstrates the implementation of
                  InsertFirst() and InsertLast() operations in a
                  Singly Linear Linked List using Java.

                  The linked list is implemented using an
                  object-oriented approach where all data members
                  and member functions are encapsulated inside
                  the SinglyLL class.
                  
Date            : July 2026
Language        : Java
Author          : Ishwari Vijaykumar Surve

===============================================================================
Concepts Used:
1. Classes and Objects
2. Self-Referential Class
3. Constructors
4. Object References
5. Encapsulation
6. Private Data Members
7. Public Member Functions
8. Dynamic Object Creation
9. InsertFirst()
10. InsertLast()

Key Learning Points:

- Linked list operations are implemented as member functions.
- first stores the reference of the first node.
- iCount stores the total number of nodes.
- InsertFirst() inserts a node at the beginning.
- InsertLast() inserts a node at the end.
- Constructors initialize newly created nodes automatically.
- Encapsulation improves code organization and security.

===============================================================================
*/
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

class SinglyLL
{
    private node first;
    private int iCount;

    public SinglyLL()
    {
        this.first = null;
        this.iCount = 0;
    }

    public void Display()
    {}

    public int Count()
    {
        return iCount;
    }

    public void InsertFirst(int iNo)
    {
        node newn = new node(iNo);
        newn.data = iNo;
        newn.next = null;

        if(first == null)
        {
            first = newn;
        }
        else
        {
            newn.next = first;
            first = newn;
        }
    }

    public void InsertLast(int No)
    {
        node newn = new node(No);
        node temp = null;

        newn.data = No;
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
    }

    public void InsertAtPos(int iNo,int iPos)
    {}

    public void DeleteFirst()
    {}

    public void DeleteLast()
    {}

    public void DeleteAtPos(int iPos)
    {}
}

class SinglyLL009
{
    public static void main(String A[])
    {
        SinglyLL sobj = new SinglyLL();

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
Expected Output
===============================================================================
No Output

The program creates a Singly Linear Linked List and performs
InsertFirst() and InsertLast() operations internally.

===============================================================================
Memory Diagram
===============================================================================

Initial List

first
  |
  v
null

After InsertFirst(51)

first
  |
  v
+------+------+
|  51  | null |
+------+------+

After InsertFirst(21)

first
  |
  v
+------+------+
|  21  |   o------+
+------+------+    |
                  v
             +------+------+
             |  51  | null |
             +------+------+

After InsertFirst(11)

first
  |
  v
+------+------+
|  11  |   o------+
+------+------+    |
                  v
             +------+------+
             |  21  |   o------+
             +------+------+    |
                               v
                          +------+------+
                          |  51  | null |
                          +------+------+

After InsertLast(101), InsertLast(111), InsertLast(121)

first
  |
  v
[11] → [21] → [51] → [101] → [111] → [121] → null

===============================================================================
Pointer / Logic Explanation
===============================================================================

InsertFirst()

Step 1:
Create a new node.

Step 2:
If the linked list is empty,
make the new node the first node.

Step 3:
Otherwise,

newn.next = first;
first = newn;

The new node becomes the first node.

------------------------------------------------------------

InsertLast()

Step 1:
Create a new node.

Step 2:
If the linked list is empty,
make the new node the first node.

Step 3:
Otherwise,

Traverse the linked list using a temporary
reference until the last node is reached.

temp.next = newn;

The new node becomes the last node.

===============================================================================
Operations Performed
===============================================================================
1. Created the node class.
2. Created the SinglyLL class.
3. Declared first as the head reference.
4. Declared iCount as the node counter.
5. Implemented Display() function prototype.
6. Implemented Count() function.
7. Implemented InsertFirst().
8. Implemented InsertLast().
9. Declared InsertAtPos().
10. Declared DeleteFirst().
11. Declared DeleteLast().
12. Declared DeleteAtPos().
13. Created a SinglyLL object.
14. Inserted nodes at the beginning.
15. Inserted nodes at the end.

===============================================================================
Time Complexity
===============================================================================
InsertFirst()      : O(1)

InsertLast()       : O(n)

Count()            : O(1)

Space Complexity   : O(n)

===============================================================================
Conclusion
===============================================================================
This program demonstrates the implementation of the
InsertFirst() and InsertLast() operations using an
object-oriented approach in Java. The linked list is
managed through the SinglyLL class, where both data
members and member functions are encapsulated together.

This program forms the foundation for implementing
Display(), Delete(), Search(), and other linked list
operations in the upcoming programs.

===============================================================================
*/

