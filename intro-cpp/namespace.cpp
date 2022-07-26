#include <bits/stdc++.h>
using namespace std;

namespace one
{
    void fun()
    {
        cout << "i a namespace one" << endl;
    }
}
namespace two
{
    void fun()
    {
        cout << "i a namespace two" << endl;
    }
}
using namespace one; //default namespace one;
int main()
{
    // two::fun();
    fun();
    return 0;
}