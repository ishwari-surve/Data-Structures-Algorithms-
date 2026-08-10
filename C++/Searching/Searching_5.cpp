/*
===============================================================================
Program Name    : Complete Searching
Program Number  : 005
File Name       : Searching_05.cpp

Description     : This program implements searching operations on a dynamically
                  allocated array. It accepts and displays array elements and
                  performs Linear Search and Bi-Directional Search operations.

Date            : August 2026
Language        : C++
Author          : Ishwari Vijaykumar Surve
===============================================================================

Concepts Used:
1. Class and Object
2. Parameterized Constructor
3. Destructor
4. Dynamic Memory Allocation
5. Array
6. Linear Search
7. Bi-Directional Search
8. Boolean Function
9. Member Functions

Operations:
1. Accept elements
2. Display elements
3. Linear Search
4. Bi-Directional Search

===============================================================================
*/

#include<iostream>
using namespace std;

class Searching
{
private:
    int *Arr;
    int iSize;

public:
    Searching(int iNo);
    ~Searching();

    void Accept();
    void Display();

    bool LinearSearch(int iNo);
    bool BiDirectionalSearch(int iNo);
};

Searching::Searching(int iNo)
{
    iSize = iNo;
    Arr = new int[iSize];
}

Searching::~Searching()
{
    delete []Arr;
}

void Searching::Accept()
{
    int i = 0;

    cout<<"Enter the Elements:\n";

    for(i = 0; i < iSize; i++)
    {
        cin>>Arr[i];
    }
}

void Searching::Display()
{
    int i = 0;

    cout<<"Elements of the Array are:\n";

    for(i = 0; i < iSize; i++)
    {
        cout<<Arr[i]<<"\n";
    }
}

bool Searching::LinearSearch(int iNo)
{
    int i = 0;

    for(i = 0; i < iSize; i++)
    {
        if(Arr[i] == iNo)
        {
            return true;
        }
    }

    return false;
}

bool Searching::BiDirectionalSearch(int iNo)
{
    int iStart = 0;
    int iEnd = iSize - 1;

    while(iStart <= iEnd)
    {
        if((Arr[iStart] == iNo) || (Arr[iEnd] == iNo))
        {
            return true;
        }

        iStart++;
        iEnd--;
    }

    return false;
}

int main()
{
    Searching sobj(5);

    sobj.Accept();
    sobj.Display();

    if(sobj.LinearSearch(30) == true)
    {
        cout<<"\nLinear Search : Element is Present\n";
    }
    else
    {
        cout<<"\nLinear Search : Element is Absent\n";
    }

    if(sobj.BiDirectionalSearch(30) == true)
    {
        cout<<"Bi-Directional Search : Element is Present\n";
    }
    else
    {
        cout<<"Bi-Directional Search : Element is Absent\n";
    }

    return 0;
}
/*
===============================================================================
Expected Output
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

Linear Search : Element is Present
Bi-Directional Search : Element is Present

Array:

+----+----+----+----+----+
| 10 | 20 | 30 | 40 | 50 |
+----+----+----+----+----+
  0    1    2    3    4

Search Element = 30

===============================================================================
Algorithm
===============================================================================

1. Start the program.

2. Create an object of the Searching class by providing the size of the
   array.

3. Allocate memory dynamically for the array using the parameterized
   constructor.

4. Accept the elements of the array using the Accept() function.

5. Display the elements of the array using the Display() function.

6. Perform Linear Search:
   a. Start from the first element of the array.
   b. Compare each element with the given search element.
   c. If the element is found, return true.
   d. If the complete array is searched and the element is not found,
      return false.

7. Perform Bi-Directional Search:
   a. Set iStart to the first index.
   b. Set iEnd to the last index.
   c. Compare the elements at iStart and iEnd with the search element.
   d. If either element matches, return true.
   e. Increment iStart and decrement iEnd.
   f. Repeat the process until iStart becomes greater than iEnd.
   g. If the element is not found, return false.

8. Display the result of Linear Search.

9. Display the result of Bi-Directional Search.

10. Destructor releases the dynamically allocated memory.

11. Stop the program.

===============================================================================
Time Complexity
===============================================================================

Operation                  Best Case       Average Case       Worst Case
-------------------------------------------------------------------------------
Accept()                   O(n)            O(n)               O(n)

Display()                  O(n)            O(n)               O(n)

LinearSearch()             O(1)            O(n)               O(n)

BiDirectionalSearch()      O(1)            O(n)               O(n)

Destructor                 O(n)            O(n)               O(n)
-------------------------------------------------------------------------------

Space Complexity           : O(n)

Where:
n = Number of elements in the array.

===============================================================================
Conclusion
===============================================================================

This program successfully implements the basic Searching operations using
C++. It demonstrates dynamic memory allocation, array handling, Linear Search,
and Bi-Directional Search. The program also demonstrates the use of classes,
constructors, destructors, member functions, and boolean return values for
searching operations.

===============================================================================
*/
