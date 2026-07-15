/*
================================================================================
Program Name : Singly Linear Linked List - Parameterized Constructor
Program Number  : 007 
Description     : This program demonstrates the use of a
                  parameterized constructor to initialize
                  the data and next reference of a node
                  automatically during object creation.
                  The constructor simplifies node creation
                  and improves code readability by eliminating
                  manual initialization.
Date            : July 2026
Language        : Java
Author          : Ishwari Vijaykumar Surve
================================================================================
Concepts Used:
1. Classes and Objects
2. Constructors
3. Parameterized Constructor
4. this Keyword
5. Object References
6. Dynamic Object Creation
7. Automatic Initialization

Key Learning Points:

- Constructors execute automatically when an object is created.
- A parameterized constructor initializes object data using arguments.
- The this keyword refers to the current object.
- Object initialization becomes shorter and more reliable.
- Constructors eliminate repetitive initialization code.
- Every newly created node starts with next initialized to null.
- Constructors are used in linked list insertion operations.
================================================================================
*/

class node
{
    public int data;           // Data value stored in node
    public node next;          // Reference to next node

    // Parameterized Constructor
    node(int no)
    {
        this.data = no;        // Initialize data with parameter
        this.next = null;      // Initialize next to null
    }
}

class program450
{
    public static void main(String A[])
    {
        // Create node with data 11 - constructor runs automatically
        node newn = new node(11);
        
        // Display data value
        System.out.println(newn.data);
        
        // Display reference (next pointer)
        System.out.println(newn.next);
    }
}

/*
================================================================================
Expected Output:
================================================================================
11
null

================================================================================
Memory Diagram:
================================================================================

Stack:
┌──────────────────────────┐
│ newn (reference variable)│
│ Points to heap object    │
└──────────────────────────┘
         │
         ▼
Heap:
┌──────────┬──────────────┐
│ data: 11 │ next: null   │
└──────────┴──────────────┘

Constructor Execution:
new node(11) → node object created → Constructor runs
                                      this.data = 11
                                      this.next = null

Output:
11        (value of newn.data)
null      (value of newn.next - reference to nothing)

================================================================================
Pointer/Logic Explanation:
================================================================================

Constructor Concept:
- Special member of a class.
- Executes automatically during object creation.
- Used to initialize object members.

Syntax:
node(int no)              // Constructor signature
{
    this.data = no;       // Initialize data
    this.next = null;     // Initialize next
}

'this' Keyword:
- Refers to current object being created
- this.data = the data field of this object
- this.next = the next field of this object
- Used to distinguish instance variables from parameters

Why Constructor Better:
- Single line instead of three
- Automatic initialization
- Ensures data always initialized
- Less error-prone
- Required pattern for linked list functions

Execution Trace:

Line: node newn = new node(11);
Step 1: new node(11) allocates memory on heap
Step 2: Constructor node(int no) called with no=11
Step 3: this.data = 11 (initialize data field)
Step 4: this.next = null (initialize next field)
Step 5: Return reference to newly created object
Step 6: newn gets this reference

After Creation:
newn → [data: 11, next: null]

Line: System.out.println(newn.data);
- Access data field of object that newn points to
- Print value: 11

Line: System.out.println(newn.next);
- Access next field of object that newn points to
- next = null (no object assigned)
- Print: null

Constructor Pattern for Linked List:

Why Important:
- All node creation will use constructors
- InsertFirst will use: newn = new node(iNo);
- InsertLast will use: newn = new node(iNo);
- Eliminates manual initialization
- Clean and efficient

===============================================================================
Operations Performed
===============================================================================
1. Created a self-referential node class.
2. Defined a parameterized constructor.
3. Declared a node reference.
4. Created a node object using the new keyword.
5. Automatically initialized the data member.
6. Automatically initialized the next reference to null.
7. Displayed the data stored in the node.
8. Displayed the next reference.

================================================================================
Time Complexity:
================================================================================
Constructor Execution : O(1)
Data Access           : O(1)
Reference Display     : O(1)

Overall               : O(1)

Space Complexity      : O(1)

================================================================================
Conclusion:
================================================================================

This program demonstrates the use of a parameterized constructor
for automatic node initialization in a Singly Linear Linked List.
The constructor initializes both the data member and the next
reference during object creation, making the code cleaner,
more reliable, and easier to maintain.
Using constructors is the standard approach in Java and forms
the foundation for implementing linked list operations such as
InsertFirst(), InsertLast(), and InsertAtPos().ons.

================================================================================
*/
