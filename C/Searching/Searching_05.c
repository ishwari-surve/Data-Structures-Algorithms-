/*
===============================================================================
Program Name    : Searching Application
Program Number  : 05
File Name       : Searching_05.c
Description     : This program implements both Linear Search and
                  Bi-Directional Search on a dynamically allocated array
                  and compares their searching results.

Date            : August 2026
Language        : C
Author          : Ishwari Vijaykumar Surve
===============================================================================

Concepts Used:
1. Structure
2. Pointer to Structure
3. Typedef
4. Dynamic Memory Allocation
5. Linear Search
6. Bi-Directional Search
7. Array Traversal
8. Function Reusability

Key Learning Points:
- Understand and implement Linear Search.
- Understand and implement Bi-Directional Search.
- Compare the results of two searching techniques.
- Search an element in an array using different approaches.
- Analyze the time and space complexity of searching techniques.

===============================================================================
*/

#include<stdio.h>
#include<stdlib.h>

struct Searching
{
    int *Arr;
    int iSize;
};

typedef struct Searching SEARCHING;
typedef struct Searching *PSEARCHING;

///////////////////////////////////////////////////////////////////////////////
//
// Function Name : Accept
// Description   : Accept elements from user
//
///////////////////////////////////////////////////////////////////////////////

void Accept(PSEARCHING first)
{
    int i = 0;

    printf("Enter the Elements:\n");

    for(i = 0; i < first->iSize; i++)
    {
        scanf("%d",&first->Arr[i]);
    }
}

///////////////////////////////////////////////////////////////////////////////
//
// Function Name : Display
// Description   : Display elements of array
//
///////////////////////////////////////////////////////////////////////////////

void Display(PSEARCHING first)
{
    int i = 0;

    printf("Elements of the Array are:\n");

    for(i = 0; i < first->iSize; i++)
    {
        printf("%d\n",first->Arr[i]);
    }
}

///////////////////////////////////////////////////////////////////////////////
//
// Function Name : LinearSearch
// Description   : Search element using Linear Search
//
///////////////////////////////////////////////////////////////////////////////

int LinearSearch(PSEARCHING first, int iNo)
{
    int i = 0;

    for(i = 0; i < first->iSize; i++)
    {
        if(first->Arr[i] == iNo)
        {
            return 1;
        }
    }

    return 0;
}

///////////////////////////////////////////////////////////////////////////////
//
// Function Name : BiDirectionalSearch
// Description   : Search element using Bi-Directional Search
//
///////////////////////////////////////////////////////////////////////////////

int BiDirectionalSearch(PSEARCHING first, int iNo)
{
    int iStart = 0;
    int iEnd = first->iSize - 1;

    while(iStart <= iEnd)
    {
        if((first->Arr[iStart] == iNo) ||
           (first->Arr[iEnd] == iNo))
        {
            return 1;
        }

        iStart++;
        iEnd--;
    }

    return 0;
}

///////////////////////////////////////////////////////////////////////////////
//
// Entry Point Function
//
///////////////////////////////////////////////////////////////////////////////

int main()
{
    SEARCHING sobj;
    int iRet = 0;

    sobj.iSize = 5;

    sobj.Arr = (int *)malloc(sizeof(int) * sobj.iSize);

    Accept(&sobj);
    Display(&sobj);

    iRet = LinearSearch(&sobj,30);

    if(iRet == 1)
    {
        printf("Element is Present using Linear Search\n");
    }
    else
    {
        printf("There is no such element using Linear Search\n");
    }

    iRet = BiDirectionalSearch(&sobj,30);

    if(iRet == 1)
    {
        printf("Element is Present using Bi-Directional Search\n");
    }
    else
    {
        printf("There is no such element using Bi-Directional Search\n");
    }

    free(sobj.Arr);

    return 0;
}

/*
===============================================================================
Expected Output:
===============================================================================

Enter the Elements:
10
20
30
40
50

Elements of the Array are:
10
20
30
40
50

Element is Present using Linear Search
Element is Present using Bi-Directional Search

===============================================================================
Memory Representation:
===============================================================================

              sobj
        +------------------+
        | Arr ------------ |--------+
        | iSize = 5        |        |
        +------------------+        |
                                    v
                         +------+------+------+------+------+
                         |  10  |  20  |  30  |  40  |  50  |
                         +------+------+------+------+------+
                           Arr[0] Arr[1] Arr[2] Arr[3] Arr[4]

Linear Search:
10 -> 20 -> 30 -> Match Found

Bi-Directional Search:
10 <-> 50
20 <-> 40
30 <-> 30 -> Match Found

===============================================================================
Algorithm:
===============================================================================

1. Start the program.
2. Define the Searching structure.
3. Create a SEARCHING object.
4. Set the array size to 5.
5. Allocate memory dynamically for the array.
6. Accept the array elements using Accept().
7. Display the array elements using Display().
8. Call LinearSearch() to search for the required element.
9. Compare each array element sequentially with the search element.
10. Display the result of Linear Search.
11. Call BiDirectionalSearch() to search for the same element.
12. Initialize iStart to the first position and iEnd to the last position.
13. Compare elements from both ends of the array.
14. Move iStart forward and iEnd backward after each comparison.
15. Display the result of Bi-Directional Search.
16. Release the dynamically allocated memory using free().
17. Stop the program.

===============================================================================
Program Flow:
===============================================================================

             Start
               |
               v
      Create SEARCHING Object
               |
               v
       Allocate Array Memory
               |
               v
            Accept()
               |
               v
           Display()
               |
               v
       Search using Linear
            Search
               |
               v
        Display Result
               |
               v
    Search using Bi-Directional
             Search
               |
               v
        Display Result
               |
               v
             free()
               |
               v
              Stop

===============================================================================
Time Complexity:
===============================================================================

Linear Search:

Best Case    : O(1)
Average Case : O(n)
Worst Case   : O(n)

Bi-Directional Search:

Best Case    : O(1)
Average Case : O(n)
Worst Case   : O(n)

Accept()     : O(n)
Display()    : O(n)

Space Complexity : O(n)

Where n is the number of elements in the array.

===============================================================================
Conclusion:
===============================================================================

Program 005 implements both Linear Search and Bi-Directional Search on a
dynamically allocated array. The same element is searched using both
techniques and the results are displayed. This program helps in understanding
and comparing different searching approaches while analyzing their time and
space complexity.

===============================================================================
*/
