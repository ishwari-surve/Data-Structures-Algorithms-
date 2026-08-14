/*
===============================================================================
Program Name    : Searching - Bi-Directional Search
Program Number  : 05
File Name       : Searching_05.java

Description     : This program accepts elements from the user, displays the
                  array elements and searches for a particular element using
                  the Bi-Directional Search technique.

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
9. Bi-Directional Search
10. Array Traversal
11. Boolean Return Value
12. Two-End Searching

Key Learning Points:
- Understand the basic concept of Bi-Directional Search.
- Learn how to search an element from both ends of an array.
- Understand the use of start and end indexes.
- Learn how two elements can be checked in each iteration.
- Understand how the search range decreases from both sides.
- Compare Bi-Directional Search with Linear Search.

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

    ///////////////////////////////////////////////////////////////////////////
    //
    // Function Name : BiDirectionalSearch
    // Description   : Search element from both ends
    //
    ///////////////////////////////////////////////////////////////////////////

    public boolean BiDirectionalSearch(int iNo)
    {
        int iStart = 0;
        int iEnd = 0;
        boolean bFlag = false;

        iStart = 0;
        iEnd = iSize - 1;

        while(iStart <= iEnd)
        {
            if(Arr[iStart] == iNo || Arr[iEnd] == iNo)
            {
                bFlag = true;
                break;
            }

            iStart++;
            iEnd--;
        }

        return bFlag;
    }
}

class Searching_05
{
    public static void main(String A[])
    {
        Searching sobj = new Searching(5);

        sobj.Accept();
        sobj.Display();

        if(sobj.BiDirectionalSearch(30) == true)
        {
            System.out.println("\nElement is Present");
        }
        else
        {
            System.out.println("\nThere is no such element");
        }
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
30
101

Elements of the Array are :
11
21
51
30
101

Element is Present

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
                       +----+----+----+----+-----+
                       | 11 | 21 | 51 | 30 | 101 |
                       +----+----+----+----+-----+
                         0    1    2    3     4
                         ^              ^     ^
                         |              |     |
                       Start          Search  End
                                      30

Initial:
iStart = 0
iEnd   = 4

After first iteration:
iStart = 1
iEnd   = 3

After second iteration:
iStart = 2
iEnd   = 2

===============================================================================
Algorithm:
===============================================================================

1. Start the program.
2. Create a Searching object with size 5.
3. Call Accept() to accept array elements.
4. Call Display() to display the array elements.
5. Call BiDirectionalSearch() with the element to be searched.
6. Set iStart to 0.
7. Set iEnd to iSize - 1.
8. Compare the element at iStart with the search element.
9. Compare the element at iEnd with the search element.
10. If either element matches, set bFlag to true and stop searching.
11. Otherwise, increment iStart.
12. Decrement iEnd.
13. Continue until iStart becomes greater than iEnd.
14. Return bFlag.
15. Display whether the element is present or absent.
16. Stop the program.

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
          Call Display()
                |
                v
    BiDirectionalSearch(30)
                |
                v
       Set Start = 0
       Set End = n - 1
                |
                v
     Compare Start and End
                |
                v
        Element Found?
          /         \
        Yes          No
         |            |
         v            v
    Return true   Start++, End--
         |            |
         |            v
         |      Start <= End?
         |        /       \
         |      Yes        No
         |       |          |
         |       +----------+
         |                  |
         |                  v
         |             Return false
         |                  |
         +--------+---------+
                  |
                  v
            Display Result
                  |
                  v
                 Stop

===============================================================================
Time Complexity:
===============================================================================

Best Case    : O(1)
Average Case : O(n)
Worst Case   : O(n)

Where n is the number of elements in the array.

===============================================================================
Space Complexity:
===============================================================================

O(n) for storing n integer elements in the array.

Auxiliary Space : O(1)

===============================================================================
Conclusion:
===============================================================================

Program 05 demonstrates Bi-Directional Search in Java. The program searches
for an element by checking elements from both the beginning and the end of
the array simultaneously. The search range is reduced from both sides after
each iteration until the element is found or the complete search range is
checked.

===============================================================================
*/
