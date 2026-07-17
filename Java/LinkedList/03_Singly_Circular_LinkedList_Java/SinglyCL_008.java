/*
===============================================================================
Program Name    : Singly Circular Linked List Class Skeleton
Program Number  : 008
Description     : This program demonstrates the basic skeleton of a Singly
                  Circular Linked List in Java. The class contains all the
                  essential member functions required for performing linked
                  list operations such as insertion, deletion, traversal,
                  and counting. The functions are declared but their
                  implementations are left empty for future programs.

Date            : July 2026
Language        : Java
Author          : Ishwari Vijaykumar Surve
===============================================================================

Concepts Used:
1. Class and Object
2. Constructor
3. Encapsulation
4. Data Hiding
5. Self-Referential Class
6. Method Declaration
7. Linked List Framework

Key Learning Points:
- first stores the reference of the first node.
- last stores the reference of the last node.
- iCount maintains the total number of nodes.
- Member functions define the operations of the linked list.
- This class serves as the foundation for implementing a complete
  Singly Circular Linked List.

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

    ////////////////////////////////////////////////////////////

    public void Display()
    {

    }

    ////////////////////////////////////////////////////////////

    public int Count()
    {
        return iCount;
    }

    ////////////////////////////////////////////////////////////

    public void InsertFirst(int no)
    {

    }

    ////////////////////////////////////////////////////////////

    public void InsertLast(int no)
    {

    }

    ////////////////////////////////////////////////////////////

    public void InsertAtPos(int no, int iPos)
    {

    }

    ////////////////////////////////////////////////////////////

    public void DeleteFirst()
    {

    }

    ////////////////////////////////////////////////////////////

    public void DeleteLast()
    {

    }

    ////////////////////////////////////////////////////////////

    public void DeleteAtPos(int iPos)
    {

    }
}

class SinglyCL8
{
    public static void main(String A[])
    {
        SinglyCL sobj = new SinglyCL();
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

                 SinglyCL Object (sobj)

        +---------------------------------+
        | first  = NULL                   |
        | last   = NULL                   |
        | iCount = 0                      |
        +---------------------------------+
        | Display()                       |
        | Count()                         |
        | InsertFirst()                   |
        | InsertLast()                    |
        | InsertAtPos()                   |
        | DeleteFirst()                   |
        | DeleteLast()                    |
        | DeleteAtPos()                   |
        +---------------------------------+

===============================================================================
Explanation:
===============================================================================

The program defines a node class that represents each node of the Singly
Circular Linked List.

The SinglyCL class encapsulates the linked list by maintaining three data
members:

• first  – Stores the reference of the first node.
• last   – Stores the reference of the last node.
• iCount – Stores the total number of nodes.

The constructor initializes the linked list as empty by setting:

first = null
last = null
iCount = 0

The class also declares all the important member functions required for a
complete Singly Circular Linked List implementation.

Display()
    Displays all nodes of the linked list.

Count()
    Returns the total number of nodes.

InsertFirst()
    Inserts a node at the beginning.

InsertLast()
    Inserts a node at the end.

InsertAtPos()
    Inserts a node at the specified position.

DeleteFirst()
    Deletes the first node.

DeleteLast()
    Deletes the last node.

DeleteAtPos()
    Deletes a node from the specified position.

Currently, these functions contain empty bodies except Count(), which
returns the value of iCount.

===============================================================================
Program Flow:
===============================================================================

Start Program
      │
      ▼
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
Object Ready for Linked List Operations
      │
      ▼
Program Terminates

===============================================================================
Operations Performed:
===============================================================================

1. Defined a self-referential node class.
2. Created the SinglyCL class.
3. Declared first, last and iCount.
4. Initialized data members in the constructor.
5. Declared all linked list member functions.
6. Created an object of the SinglyCL class.

===============================================================================
Time Complexity:
===============================================================================

Object Creation  : O(1)

Space Complexity : O(1)

===============================================================================
Conclusion:
===============================================================================

Program 008 provides the complete framework of a Singly Circular Linked
List in Java. It defines all the essential member functions that will be
implemented in subsequent programs, making it the foundation for a complete
menu-driven linked list implementation.

===============================================================================
*/
