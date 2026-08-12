/*
===============================================================================
Program Name    : Linear Search
Program Number  : 03
File Name       : Searching_03.c
Description     : This program implements Linear Search to search for a
                  particular element in a dynamically allocated array.

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
6. Array Traversal

Key Learning Points:
- Understand the concept of Linear Search.
- Search an element sequentially from the beginning of the array.
- Return the result based on whether the element is present or absent.
- Analyze the time complexity of Linear Search.

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

Linear Search:

10  ->  Not Match
20  ->  Not Match
30  ->  Match Found

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
8. Take the element to be searched.
9. Start traversing the array from the first element.
10. Compare each array element with the search element.
11. If a match is found, return 1.
12. If the complete array is searched without a match, return 0.
13. Display whether the element is present or absent.
14. Release the allocated memory using free().
15. Stop the program.

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
    LinearSearch(30)
          |
          v
   Compare Each Element
          |
       +--+--+
       |     |
     Match  No Match
       |     |
       v     v
   Return 1  Continue
       |     |
       |    Complete Array?
       |     |
       |     v
       |   Return 0
       |     |
       +--+--+
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

Best Case    : O(1)   → Element found at the first position
Average Case : O(n)
Worst Case   : O(n)   → Element found at the last position or absent

Space Complexity : O(n)

Where n is the size of the dynamically allocated array.

===============================================================================
Conclusion:
===============================================================================

Program 003 implements Linear Search in C using a dynamically allocated
array. The program checks each element sequentially until the required
element is found or the complete array is traversed. Linear Search is
simple and works on both sorted and unsorted arrays, with O(n) worst-case
time complexity.

===============================================================================
*/
