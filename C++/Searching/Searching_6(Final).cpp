/*
===============================================================================
Program Name    : Menu Driven Searching
Program Number  : 006
File Name       : Searching_06.cpp

Description     : This program implements a menu driven Searching Application
                  using a dynamically allocated array. It provides options to
                  accept and display array elements and perform Linear Search
                  and Bi-Directional Search.

Date            : August 2026
Language        : C++
Author          : Ishwari Vijaykumar Surve
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

Searching :: Searching(int iNo)
{
    iSize = iNo;
    Arr = new int[iSize];
}

Searching :: ~Searching()
{
    delete []Arr;
}

void Searching :: Accept()
{
    int i = 0;

    cout<<"Enter the Elements:\n";

    for(i = 0; i < iSize; i++)
    {
        cin>>Arr[i];
    }
}

void Searching :: Display()
{
    int i = 0;

    cout<<"\nElements of the Array are:\n";

    for(i = 0; i < iSize; i++)
    {
        cout<<Arr[i]<<"\t";
    }

    cout<<"\n";
}

bool Searching :: LinearSearch(int iNo)
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

bool Searching :: BiDirectionalSearch(int iNo)
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
    int iSize = 0;
    int iChoice = 0;
    int iValue = 0;

    cout<<"Enter Number of Elements : ";
    cin>>iSize;

    Searching sobj(iSize);

    while(1)
    {
        cout<<"\n=================================================\n";
        cout<<"              Searching Application\n";
        cout<<"=================================================\n";

        cout<<"1. Accept Elements\n";
        cout<<"2. Display Elements\n";
        cout<<"3. Linear Search\n";
        cout<<"4. Bi-Directional Search\n";
        cout<<"5. Exit\n";

        cout<<"Enter your choice : ";
        cin>>iChoice;

        switch(iChoice)
        {
            case 1:
                sobj.Accept();
                break;

            case 2:
                sobj.Display();
                break;

            case 3:
                cout<<"Enter element to search : ";
                cin>>iValue;

                if(sobj.LinearSearch(iValue))
                {
                    cout<<"Element is Present\n";
                }
                else
                {
                    cout<<"Element is Absent\n";
                }
                break;

            case 4:
                cout<<"Enter element to search : ";
                cin>>iValue;

                if(sobj.BiDirectionalSearch(iValue))
                {
                    cout<<"Element is Present\n";
                }
                else
                {
                    cout<<"Element is Absent\n";
                }
                break;

            case 5:
                cout<<"Thank you for using Searching Application\n";
                return 0;

            default:
                cout<<"Invalid Choice\n";
                break;
        }
    }

    return 0;
}
/*
===============================================================================
Expected Output
===============================================================================
===============================================================================
                         Searching Application
===============================================================================

Enter Number of Elements : 5

=================================================
              Searching Application
=================================================
1. Accept Elements
2. Display Elements
3. Linear Search
4. Bi-Directional Search
5. Exit
Enter your choice : 1

Enter the Elements:
10
20
30
40
50

=================================================
              Searching Application
=================================================
1. Accept Elements
2. Display Elements
3. Linear Search
4. Bi-Directional Search
5. Exit
Enter your choice : 2

Elements of the Array are:
10    20    30    40    50

=================================================
              Searching Application
=================================================
1. Accept Elements
2. Display Elements
3. Linear Search
4. Bi-Directional Search
5. Exit
Enter your choice : 3

Enter element to search : 30
Element is Present

=================================================
              Searching Application
=================================================
1. Accept Elements
2. Display Elements
3. Linear Search
4. Bi-Directional Search
5. Exit
Enter your choice : 4

Enter element to search : 40
Element is Present

=================================================
              Searching Application
=================================================
1. Accept Elements
2. Display Elements
3. Linear Search
4. Bi-Directional Search
5. Exit
Enter your choice : 5

Thank you for using Searching Application
===============================================================================
  
===============================================================================
Algorithm
===============================================================================

1. Start the program.

2. Accept the number of elements from the user.

3. Create an object of the Searching class with the given size.

4. Display the Searching Application menu.

5. Accept the user's choice.

6. Perform the selected operation:

   a. Accept Elements:
      - Accept all elements into the dynamically allocated array.

   b. Display Elements:
      - Traverse the array.
      - Display all elements.

   c. Linear Search:
      - Accept the element to search.
      - Compare the search element with every array element.
      - If a match is found, display "Element is Present".
      - Otherwise, display "Element is Absent".

   d. Bi-Directional Search:
      - Accept the element to search.
      - Set iStart to the first index.
      - Set iEnd to the last index.
      - Compare elements from both ends.
      - Move iStart forward and iEnd backward.
      - Continue until iStart becomes greater than iEnd.
      - Display whether the element is present or absent.

   e. Exit:
      - Display the termination message.
      - Terminate the program.

7. Repeat the menu until the user selects Exit.

8. Destructor releases the dynamically allocated memory.

9. Stop the program.

===============================================================================
Time Complexity
===============================================================================

Operation                  Best Case       Average Case       Worst Case
-------------------------------------------------------------------------------
Accept()                   O(n)            O(n)               O(n)

Display()                  O(n)            O(n)               O(n)

LinearSearch()             O(1)            O(n)               O(n)

BiDirectionalSearch()      O(1)            O(n)               O(n)
-------------------------------------------------------------------------------

Space Complexity           : O(n)

Where:
n = Number of elements in the array.

===============================================================================
Conclusion
===============================================================================

This program successfully implements a Menu Driven Searching Application
using C++. It provides options to accept and display array elements and
perform Linear Search and Bi-Directional Search. The program demonstrates
classes, constructors, destructors, dynamic memory allocation, arrays,
member functions, boolean functions, and switch-case based menu handling.

===============================================================================
*/
