/*
===============================================================================
Program Name    : Bi-Directional Search
Program Number  : 04
File Name       : Searching_04.c
Description     : This program implements Bi-Directional Search to search for
                  a particular element by comparing elements from both ends
                  of a dynamically allocated array.

Date            : August 2026
Language        : C
Author          : Ishwari Vijaykumar Surve
===============================================================================

Concepts Used:
1. Structure
2. Pointer to Structure
3. Typedef
4. Dynamic Memory Allocation
5. Bi-Directional Search
6. Array Traversal

Key Learning Points:
- Understand the concept of Bi-Directional Search.
- Search elements from both ends of the array.
- Compare the starting and ending elements simultaneously.
- Analyze the time and space complexity of the searching technique.

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

void Accept(PSEARCHING first)
{
    int i = 0;

    printf("Enter the Elements:\n");

    for(i = 0; i < first->iSize; i++)
    {
        scanf("%d",&first->Arr[i]);
    }
}

void Display(PSEARCHING first)
{
    int i = 0;

    printf("Elements of the Array are:\n");

    for(i = 0; i < first->iSize; i++)
    {
        printf("%d\n",first->Arr[i]);
    }
}

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

int main()
{
    SEARCHING sobj;
    int iRet = 0;

    sobj.iSize = 5;

    sobj.Arr = (int *)malloc(sizeof(int) * sobj.iSize);

    Accept(&sobj);
    Display(&sobj);

    iRet = BiDirectionalSearch(&sobj,30);

    if(iRet == 1)
    {
        printf("Element is Present\n");
    }
    else
    {
        printf("There is no such element\n");
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

Element is Present

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
                             ^                         ^
                           iStart                    iEnd

Step 1:
Compare Arr[0] and Arr[4]
10 != 30
50 != 30

Step 2:
Compare Arr[1] and Arr[3]
20 != 30
40 != 30

Step 3:
Compare Arr[2] and Arr[2]
30 == 30

Element Found

===============================================================================
Algorithm:
===============================================================================

1. Start the program.
2. Define the Searching structure.
3. Create a SEARCHING object.
4. Set the array size.
5. Allocate memory dynamically for the array.
6. Accept the array elements from the user.
7. Display the array elements.
8. Initialize iStart to 0.
9. Initialize iEnd to iSize - 1.
10. Compare the elements at iStart and iEnd with the search element.
11. If either element matches, return 1.
12. Increment iStart.
13. Decrement iEnd.
14. Repeat the process while iStart is less than or equal to iEnd.
15. If no match is found, return 0.
16. Display whether the element is present or absent.
17. Release the allocated memory using free().
18. Stop the program.

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
 Initialize iStart and iEnd
          |
          v
 Compare Elements From
       Both Ends
          |
       +--+--+
       |     |
     Match  No Match
       |     |
       v     v
 Return 1  Move iStart
           and iEnd
              |
              v
       iStart <= iEnd ?
          |        |
         Yes       No
          |        |
          +----+---+
               |
               v
           Return 0
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

Best Case    : O(1)   → Element found at either end
Average Case : O(n)
Worst Case   : O(n)   → Element found near the middle or absent

Space Complexity : O(n)

Where n is the size of the dynamically allocated array.

===============================================================================
Conclusion:
===============================================================================

Program 004 implements Bi-Directional Search in C using a dynamically
allocated array. The program compares elements from both the beginning
and the end of the array in each iteration. This reduces the number of
iterations compared with checking only one side at a time in some cases,
while the overall worst-case time complexity remains O(n).

===============================================================================
*/
