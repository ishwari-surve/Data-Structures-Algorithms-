/*
===============================================================================
Program Name    : Searching - Display Elements
Program Number  : 03
File Name       : Searching_03.java

Description     : This program accepts integer elements from the user and
                  displays the elements stored in the array.

Date            : August 2026
Language        : Java
Author          : Ishwari Vijaykumar Surve
===============================================================================

Concepts Used:
1. Class
2. Object-Oriented Programming (OOP)
3. Constructor
4. Array
5. Scanner Class
6. User Input
7. Accept Operation
8. Display Operation
9. Array Traversal
10. Private Data Members

Key Learning Points:
- Understand how to display elements of an array.
- Learn how to traverse an array using a for loop.
- Understand the Accept and Display operations.
- Learn how to access array elements through class methods.
- Understand array indexing in Java.

===============================================================================
*/

import java.util.*;

class Searching
{
    private int Arr[];
    private int iSize;

    public Searching(int iNo)
    {
        iSize = iNo;
        Arr = new int[iSize];
    }

    ///////////////////////////////////////////////////////////////////////////
    //
    // Function Name : Accept
    // Description   : Accept elements from user
    //
    ///////////////////////////////////////////////////////////////////////////

    public void Accept()
    {
        Scanner sobj = new Scanner(System.in);

        int i = 0;

        System.out.println("Enter the Elements : ");

        for(i = 0; i < iSize; i++)
        {
            Arr[i] = sobj.nextInt();
        }
    }

    ///////////////////////////////////////////////////////////////////////////
    //
    // Function Name : Display
    // Description   : Display elements of the array
    //
    ///////////////////////////////////////////////////////////////////////////

    public void Display()
    {
        int i = 0;

        System.out.println("\nElements of the Array are : ");

        for(i = 0; i < iSize; i++)
        {
            System.out.println(Arr[i]);
        }
    }
}

class Searching_03
{
    public static void main(String A[])
    {
        Searching sobj = new Searching(5);

        sobj.Accept();
        sobj.Display();
    }
}

/*
===============================================================================
Expected Output:
===============================================================================

Enter the Elements :
11
21
51
101
151

Elements of the Array are :
11
21
51
101
151

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
                       +----+----+----+-----+-----+
                       | 11 | 21 | 51 | 101 | 151 |
                       +----+----+----+-----+-----+
                         0    1    2     3     4

===============================================================================
Algorithm:
===============================================================================

1. Start the program.
2. Create the Searching class.
3. Declare an integer array Arr and integer iSize.
4. Create a Searching object with size 5.
5. Call the Accept() function.
6. Accept 5 integer elements from the user.
7. Store the elements in the array.
8. Call the Display() function.
9. Traverse the array using a for loop.
10. Display each element of the array.
11. Stop the program.

===============================================================================
Program Flow:
===============================================================================

        Start
          |
          v
   Create Searching Object
          |
          v
      Call Accept()
          |
          v
    Accept Array Elements
          |
          v
     Store Elements
          |
          v
     Call Display()
          |
          v
    Traverse the Array
          |
          v
    Display Elements
          |
          v
         Stop

===============================================================================
Time Complexity:
===============================================================================

Accept()  : O(n)

Display() : O(n)

Overall   : O(n)

Where n is the number of elements in the array.

===============================================================================
Space Complexity:
===============================================================================

O(n) for storing n integer elements in the array.

===============================================================================
Conclusion:
===============================================================================

Program 03 demonstrates how to accept and display elements of an array using
a Searching class in Java. It demonstrates array traversal, user input and
the use of separate Accept() and Display()
