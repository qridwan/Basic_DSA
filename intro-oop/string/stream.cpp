#include <bits/stdc++.h>
using namespace std;

int main()
{
    string str = "ridwan  alam  shoyab";
    // stringstream stream(str); // on way;
    stringstream stream; // ano way
    stream << str;
    string w;

    while (stream >> w)
    {
        cout << w << endl;
    }

    // string s1="Hello";
    // s1.erase(2,3);
    // cout<<s1;

    return 0;
}