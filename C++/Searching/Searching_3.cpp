/*
===============================================================================
Program Name    : Searching - Linear Search
Program Number  : 003
File Name       : Searching_03.cpp

Description     : This program demonstrates the Linear Search technique
                  using a dynamically allocated array. The program accepts
                  array elements from the user and searches for a specified
                  element by comparing it with each array element sequentially.

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
6. Linear Search
7. Boolean Function
8. Member Functions

Key Learning Points:
- Implement Linear Search.
- Compare each array element sequentially.
- Return true when the element is found.
- Return false when the element is not found.
- Understand searching using arrays.

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
    bool bFlag = false;
    int i = 0;

    for(i = 0; i < iSize; i++)
    {
        if(Arr[i] == iNo)
        {
            bFlag = true;
            break;
        }
    }

    return bFlag;
}

int main()
{
    Searching sobj(5);

    sobj.Accept();
    sobj.Display();

    if(sobj.LinearSearch(30) == true)
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

Search Element = 30

10 ≠ 30  → Continue
20 ≠ 30  → Continue
30 = 30  → Element Found

===============================================================================
Algorithm:
===============================================================================

1. Accept the array elements from the user.
2. Accept the element to be searched.
3. Start from the first array element.
4. Compare the current element with the search element.
5. If both elements are equal, return true.
6. Continue until the element is found or the array ends.
7. If the element is not found, return false.
8. Display the search result.

===============================================================================
Program Flow:
===============================================================================

              Start
                │
                ▼
        Create Searching Object
                │
                ▼
          Accept Elements
                │
                ▼
         Display Elements
                │
                ▼
        Search Using Linear Search
                │
                ▼
        Compare Array Element
                │
          ┌─────┴─────┐
          │           │
        Equal       Not Equal
          │           │
          ▼           ▼
     Return True   Check Next
          │           │
          │      Array Finished?
          │           │
          │      Yes ─┴─ No
          │       │       │
          │       ▼       └── Continue
          │    Return False
          │       │
          └───┬───┘
              ▼
        Display Result
              │
              ▼
             Stop

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

Program 003 demonstrates the Linear Search technique in C++. The
program sequentially compares each array element with the given
search element and determines whether the element is present or not.

===============================================================================
*/
