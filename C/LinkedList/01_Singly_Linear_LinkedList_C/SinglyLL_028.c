/*
================================================================================
Program Name    : Singly Linked List - Invalid NULL Assignment Demonstration
Program Number  : 028
Description     : This program demonstrates a common programming mistake by
                  using NULL = *first instead of NULL == *first while checking
                  whether the linked list is empty. The incorrect statement
                  generates a compiler error because NULL is a constant and
                  cannot be assigned a value. Display() and Count() functions
                  are implemented, while InsertFirst() intentionally contains
                  the invalid comparison for learning purposes.
Date            : July 2026
Language        : C
Author          : Ishwari Vijaykumar Surve
================================================================================
Concepts Used:
1. Structures (struct)
2. PNODE and PPNODE typedef
3. Dynamic Memory Allocation (malloc)
4. Pointer to Pointer (PPNODE)
5. Compiler Error Demonstration
6. Assignment Operator (=)
7. Comparison Operator (==)
8. Display and Count Functions

Key Learning Points:
- NULL is a constant and cannot be assigned a value.
- NULL = *first is an invalid statement.
- NULL == *first is the correct comparison.
- Compiler detects the mistake immediately.
- Understanding '=' versus '==' prevents logical errors.
================================================================================
*/

...

/*
================================================================================
Expected Output:
================================================================================

Compilation Error

Example:

error: lvalue required as left operand of assignment

or

error: assignment of read-only location

(The exact message depends on the compiler.)

================================================================================
Memory Diagram:
================================================================================

Program does not execute because compilation fails.

================================================================================
Pointer/Logic Explanation:
================================================================================

Incorrect Statement:

if(NULL = *first)

Explanation:
- '=' is the assignment operator.
- NULL is a constant value.
- Constants cannot appear on the left side of an assignment.
- Therefore, the compiler reports an error before execution.

Correct Statement:

if(NULL == *first)

or

if(*first == NULL)

Both statements compare whether the head pointer is NULL.

Comparison of Statements:

Correct:
if(NULL == *first)

Correct:
if(*first == NULL)

Incorrect:
if(NULL = *first)

Reason:
The assignment operator attempts to modify NULL, which is illegal.

Why This Program is Important:

- Demonstrates the difference between assignment and comparison.
- Shows how compiler errors help detect programming mistakes.
- Reinforces safe conditional checking in linked list programs.
- Prevents accidental pointer modification.

================================================================================
Time Complexity:
================================================================================

Compilation fails before execution.

If corrected:

InsertFirst()    : O(1)
Display()        : O(n)
Count()          : O(n)
Space Complexity : O(1)

================================================================================
Conclusion:
================================================================================

Program 028 intentionally demonstrates an invalid assignment statement
(NULL = *first) inside the InsertFirst() function. Since NULL is a
constant, assigning a value to it is illegal and the compiler reports
an error immediately. Replacing '=' with '==' corrects the condition
and allows the linked list to function properly. This example highlights
the importance of using the correct comparison operator while working
with pointers and conditional statements.

================================================================================
*/
