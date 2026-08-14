/*
===============================================================================
Program Name    : Searching - Object Creation
Program Number  : 01
File Name       : Searching_01.java

Description     : This program creates a Searching object and dynamically
                  allocates an integer array of the specified size.

Date            : August 2026
Language        : Java
Author          : Ishwari Vijaykumar Surve
===============================================================================

Concepts Used:
1. Class
2. Object-Oriented Programming (OOP)
3. Constructor
4. Array
5. Dynamic Array Creation
6. Private Data Members

Key Learning Points:
- Understand the basic structure of a Searching class.
- Learn how to create an integer array inside a class.
- Understand the use of a constructor.
- Learn how to initialize the size of an array.
- Understand object creation in Java.

===============================================================================
*/

class Searching
{
    private int Arr[];
    private int iSize;

    public Searching(int iNo)
    {
        iSize = iNo;
        Arr = new int[iSize];
    }
}

class Searching_01
{
    public static void main(String A[])
    {
        Searching sobj = new Searching(5);

        System.out.println("Searching object created successfully");
    }
}

/*
===============================================================================
Expected Output:
===============================================================================

Searching object created successfully

===============================================================================
Memory Representation:
===============================================================================

Searching Object

       sobj
        |
        v
+----------------------+
| Searching Object     |
+----------------------+
| iSize = 5            |
| Arr ----------------------+
+----------------------+     |
                             v
                       +---+---+---+---+---+
                       | 0 | 0 | 0 | 0 | 0 |
                       +---+---+---+---+---+
                         0   1   2   3   4

===============================================================================
Algorithm:
===============================================================================

1. Start the program.
2. Define the Searching class.
3. Declare private array Arr and integer iSize.
4. Create a constructor which accepts the array size.
5. Store the given size in iSize.
6. Create an integer array of size iSize.
7. Create a Searching object with size 5.
8. Display the successful object creation message.
9. Stop the program.

===============================================================================
Program Flow:
===============================================================================

        Start
          |
          v
   Create Searching Class
          |
          v
   Call Constructor
          |
          v
      Set iSize = 5
          |
          v
    Create Integer Array
          |
          v
   Create Searching Object
          |
          v
    Display Message
          |
          v
         Stop

===============================================================================
Time Complexity:
===============================================================================

Constructor : O(n)

Array Creation : O(n)

===============================================================================
Space Complexity:
===============================================================================

O(n) for storing n integer elements in the array.

===============================================================================
Conclusion:
===============================================================================

Program 01 demonstrates the basic structure of a Searching class in Java.
It creates a Searching object using a constructor and dynamically creates
an integer array according to the specified size.

===============================================================================
*/
