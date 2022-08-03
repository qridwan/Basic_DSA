#include <bits/stdc++.h>
using namespace std;

int main()
{
    string st = "ridwan";
    string a = "ssssss";
    string b = "bbbbb";
    // st.assign("hello world");
    st.pop_back();
    st.insert(1, "123");
    st.erase(1, 3);
    swap(a,b);
    cout << st << " " << a << " " << b << endl;
    return 0;
}