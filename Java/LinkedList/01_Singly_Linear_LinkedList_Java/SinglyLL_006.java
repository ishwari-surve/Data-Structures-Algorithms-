/*
================================================================================
Program Name    : Singly Linear Linked List - Traversal Using While Loop
Program Number  : 006 
Description     : This program demonstrates traversal of a Singly
                  Linear Linked List using a while loop.
                  Three node objects are created manually, linked
                  together using next references, and displayed by
                  traversing the list with a temporary reference.
Date            : July 2026
Language        : Java
Author          : Ishwari Vijaykumar Surve
================================================================================
Concepts Used:

1. Classes and Objects
2. Self-Referential Class
3. Object References
4. Dynamic Object Creation
5. Head Reference
6. Temporary Reference
7. Linked List Traversal
8. While Loop
9. null Reference

Key Learning Points:

- Java creates objects using the new keyword.
- Object references are used instead of pointers.
- The head reference stores the first node.
- A temporary reference is used for traversal.
- The while loop visits every node until temp becomes null.
- The original head reference remains unchanged.
- This traversal logic is used in Display(), Count(), Search(), and
  many other linked list operations.
================================================================================
*/

class node
{
    public int data;           // Data value stored in node
    public node next;          // Reference to next node
}

class SinglyLL006
{
    public static void main(String A[])
    {
        node head = null;      // Head reference - starting point of the linked list
        node obj1 = null;      // First node object reference
        node obj2 = null;      // Second node object reference
        node obj3 = null;      // Third node object reference

        // Step 1: Create three node objects using 'new' keyword
        obj1 = new node();
        obj2 = new node();
        obj3 = new node();

        // Step 2: Initialize data in each node
        obj1.data = 11;
        obj2.data = 21;
        obj3.data = 51;

        // Step 3: Link nodes together
        obj1.next = obj2;      // obj1 points to obj2
        obj2.next = obj3;      // obj2 points to obj3
        obj3.next = null;      // obj3 points to null (end of list)

        // Step 4: Assign head to first node
        head = obj1;

        // Step 5: Traverse and display all nodes
        node temp = head;

        while(temp != null)
        {
            System.out.println(temp.data);
            temp = temp.next;
        }
    }
}
/*
================================================================================
Expected Output:
================================================================================
11
21
51

================================================================================
Memory Diagram:
================================================================================

Heap Memory Structure:
head (reference variable on stack) → obj1 (on heap)
                                        │
                                        ▼
                                    [data:11|next→obj2]
                                        │
                                        ▼
                                    [data:21|next→obj3]
                                        │
                                        ▼
                                    [data:51|next:null]

Visual Chain:
head → [11] → [21] → [51] → null

Stack Variables:
head  (reference to obj1)
obj1  (reference to first node)
obj2  (reference to second node)
obj3  (reference to third node)
temp  (reference for traversal)

================================================================================
Pointer/Logic Explanation:
================================================================================

Java vs C Differences:

C Implementation:
struct node {
    int data;
    struct node *next;
};
NODE obj1;                          // Object on stack
obj1.next = &obj2;                  // Address assignment
malloc(sizeof(NODE));               // Dynamic memory allocation

Java Implementation:
class node {
    public int data;
    public node next;
}
node obj1 = new node();            // Object on heap via reference
obj1.next = obj2;                  // Reference assignment
new node();                         // Dynamic memory allocation


Object Creation Process:

Step 1: Declaration
  node obj1 = null;
  └─ Create reference variable obj1 on stack
  └─ Initialize to null (points to nothing)

Step 2: Instantiation
  obj1 = new node();
  └─ new keyword allocates memory on heap
  └─ Creates new node object
  └─ obj1 now points to this new object
  └─ Automatic memory management by garbage collector

Step 3: Data Assignment
  obj1.data = 11;
  └─ Access data field of object that obj1 points to
  └─ Assign value 11
  └─ Using dot notation (.) instead of arrow (->)

Step 4: Linking
  obj1.next = obj2;
  └─ Assign reference obj2 to obj1's next field
  └─ obj1 now points to obj2
  └─ Creates chain: obj1 → obj2


Execution Trace:

Before Linking:
obj1 → [11|null]
obj2 → [21|null]
obj3 → [51|null]

After obj1.next = obj2:
obj1 → [11|→obj2]
       └─────→ obj2 → [21|null]

After obj2.next = obj3:
obj1 → [11|→obj2]
            [21|→obj3]
                 └─→ obj3 → [51|null]

After obj3.next = null:
obj1 → [11|→obj2]
            [21|→obj3]
                 [51|null]

After head = obj1:
head → obj1 → obj2 → obj3 → null


Traversal Execution:

temp = head;              // temp points to obj1 (data: 11)

Iteration 1:
- while(temp != null)? YES (temp points to obj1)
- System.out.println(temp.data) → Output: 11
- temp = temp.next (temp now points to obj2)

Iteration 2:
- while(temp != null)? YES (temp points to obj2)
- System.out.println(temp.data) → Output: 21
- temp = temp.next (temp now points to obj3)

Iteration 3:
- while(temp != null)? YES (temp points to obj3)
- System.out.println(temp.data) → Output: 51
- temp = temp.next (temp now points to null)

Iteration 4:
- while(temp != null)? NO (temp is null)
- Loop exits


Key Java Features:

1. 'new' Keyword:
   - Allocates memory on heap
   - Returns reference (not pointer)
   - Memory automatically freed by garbage collector

2. null Reference:
   - Equivalent to NULL pointer in C
   - Indicates empty/no reference
   - Default value for object references

3. Dot Notation (.):
   - Used to access members: obj.data, obj.next
   - Equivalent to arrow (->) in C for pointers
   - Cleaner and more intuitive

4. Automatic Garbage Collection:
   - No manual memory deallocation needed
   - Unused objects automatically freed
   - Reduces memory leaks

5. Class and Object:
   - class node defines structure
   - class SinglyLL006 contains main logic
   - Both follow OOP principles


Comparison: Manual Nodes in C vs Java

C Version (equivalent):
struct node obj1, obj2, obj3;    // Stack allocation
obj1.next = &obj2;               // Address of obj2
obj2.next = &obj3;               // Address of obj3

Java Version (same logic):
node obj1 = new node();          // Heap allocation via reference
node obj2 = new node();          // Heap allocation via reference
node obj3 = new node();          // Heap allocation via reference
obj1.next = obj2;                // Reference to obj2
obj2.next = obj3;                // Reference to obj3


Why Manual Node Creation?

Purpose: Educational - shows underlying structure
- Demonstrates how nodes are created
- Shows how linking works manually
- Foundation before implementing functions
- Clear understanding of references

Later: Functions will automate this process
- InsertFirst/InsertLast will create nodes
- Eliminates manual object creation
- More scalable for larger lists

===============================================================================
Operations Performed
===============================================================================

1. Created a self-referential node class.
2. Declared object references for the linked list.
3. Dynamically created three node objects using the new keyword.
4. Initialized the data members of each node.
5. Linked all nodes using next references.
6. Assigned the first node to the head reference.
7. Created a temporary reference (temp) for traversal.
8. Traversed the linked list using a while loop.
9. Displayed the data stored in each node.
10. Preserved the original head reference during traversal.

================================================================================
Time Complexity:
================================================================================
Traversal (while loop)    : O(n) - Visit all n nodes
Data Assignment           : O(1) - Single assignment
Node Creation (new)       : O(1) - Single allocation
Space Complexity          : O(n) - Three nodes on heap

================================================================================
Conclusion:
================================================================================

This program demonstrates how to traverse a Singly Linear Linked List
using a temporary reference and a while loop. By visiting each node
through its next reference, all elements of the linked list can be
accessed sequentially without modifying the original head reference.
The while loop continues until the temporary reference becomes null,
making it the standard and most efficient technique for implementing
linked list operations such as Display(), Count(), Search(), Maximum(),
Minimum(), and Frequency()

================================================================================
*/
