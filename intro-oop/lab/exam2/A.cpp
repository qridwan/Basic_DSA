#include <bits/stdc++.h>
using namespace std;

int main()
{
    int size = 4;
    int array[4];
    int flag = 0;
    for (int i = 0; i < size; i++)
    {
        cin >> array[i];
        if (array[i] >= 10)
        {
            flag++;
        };
    };
    cout << flag << endl;
    return 0;
}

/*
    "For improving performance in competitive programming , you have to practice a lot of problems"
    Avishek took the above advice very seriously and decided to set a target for himself.
    -Avishek decides to solve at least 1010 problems every week for 44 weeks.

    Given the number of problems he actually solved in each week over 44 weeks as P1,P2,P3,P1​,P2​,P3​, and P4P4​, output the number of weeks in which Avishek met his target.

    Input Format

    There is a single line of input, with 44 integers P1,P2,P3,P1​,P2​,P3​, and P4P4​. These are the number of problems solved by Avishek in each of the 44 weeks.

    Output Format
    Output a single integer in a single line - the number of weeks in which Avishek solved at least 1010 problems.
    Constraints
        1≤P1,P2,P3,P4≤1001≤P1​,P2​,P3​,P4​≤100

    Inputcopy 	Outputcopy

12 15 8 10



3

Avishek solved at least 1010 problems in the first, second and fourth weeks. He failed to solve at least 1010 problems in the third week. Hence, the number of weeks in which Avishek met his target is 33.

https://www.codechef.com/problems/PRACTICEPERF

*/