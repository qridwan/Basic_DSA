#include <bits/stdc++.h>
using namespace std;

int main()
{
    string st;
    cout << st.capacity() << " " << st.max_size() << endl;
    st = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    cout << st.capacity() << endl; // capacity changing on runtime
    // cin >> st;
    cout << st << endl;

    string newstr = (10, "a"); // dynamic/constructor

    cout << newstr << endl;
    return 0;
}