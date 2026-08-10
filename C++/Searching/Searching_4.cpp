/*
===============================================================================
Program Name    : Searching - Bi-Directional Search
Program Number  : 004
File Name       : Searching_04.cpp

Description     : This program demonstrates the Bi-Directional Search technique
                  using a dynamically allocated array. The search starts from
                  both ends of the array and moves towards the center until
                  the required element is found or the search is completed.

Date            : August 2026
Language        : C++
Author          : Ishwari Vijaykumar Surve
===============================================================================

Concepts Used:
1. Class
2. Parameterized Constructor
3. Destructor
4. Dynamic Memory Allocation
5. Array
6. Bi-Directional Search
7. Boolean Function
8. Member Functions

Key Learning Points:
- Implement Bi-Directional Search.
- Search elements from both ends of an array.
- Move the starting index forward.
- Move the ending index backward.
- Handle the middle element correctly.

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

bool Searching::BiDirectionalSearch(int iNo)
{
    int iStart = 0;
    int iEnd = iSize - 1;

    bool bFlag = false;

    while(iStart <= iEnd)
    {
        if((Arr[iStart] == iNo) || (Arr[iEnd] == iNo))
        {
            bFlag = true;
            break;
        }

        iStart++;
        iEnd--;
    }

    return bFlag;
}

int main()
{
    Searching sobj(5);

    sobj.Accept();
    sobj.Display();

    if(sobj.BiDirectionalSearch(30) == true)
    {
        cout<<"Element is Present\n";
    }
    else
    {
        cout<<"There is no such element\n";
    }

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

Array:

+----+----+----+----+----+
| 10 | 20 | 30 | 40 | 50 |
+----+----+----+----+----+
  0    1    2    3    4
  ↑                   ↑
iStart              iEnd

Step 1:
Check 10 and 50

Step 2:
Check 20 and 40

Step 3:
Check 30 and 30

Element 30 is found.

===============================================================================
Algorithm:
===============================================================================

1. Start with iStart = 0.
2. Start with iEnd = iSize - 1.
3. Compare the elements at iStart and iEnd with the search element.
4. If either element matches, return true.
5. Increment iStart.
6. Decrement iEnd.
7. Repeat the process while iStart <= iEnd.
8. If the element is not found, return false.

===============================================================================
Time Complexity:
===============================================================================

Best Case    : O(1)
Average Case : O(n)
Worst Case   : O(n)

Space Complexity : O(n)

where,

n = Number of elements in the array

===============================================================================
Conclusion:
===============================================================================

Program 004 demonstrates the Bi-Directional Search technique in C++.
The program searches for an element by checking the array from both
ends and moving towards the center. The middle element is also checked
by using the condition iStart <= iEnd.

===============================================================================
*/
