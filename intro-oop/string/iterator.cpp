#include <bits/stdc++.h>
using namespace std;

int main()
{
    string st = "ridwan";
    string::iterator it;
    for (it = st.begin(); it != st.end(); it++)
    {
        cout << *it << " ";
    }
    cout << "" << endl;

    // reverse iterator, right to left
    string st2 = "ridwan";
    string::reverse_iterator it2;
    for (it2 = st2.rbegin(); it2 != st2.rend(); it2++)
    {
        cout << *it2 << " ";
    }
    cout << "" << endl;

    // easy soln using auto
    string st3 = "ridwan";
    for (auto it3 = st3.rbegin(); it3 != st3.rend(); it3++)
    {
        cout << *it3 << " ";
    }
    cout << "" << endl;
    return 0;
}