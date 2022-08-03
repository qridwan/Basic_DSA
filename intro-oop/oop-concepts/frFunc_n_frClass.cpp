#include <bits/stdc++.h>
using namespace std;

class Parent
{
private:
    int taka;

protected:
    int password;

public:
    Parent(int tk, int pass)
    {
        taka = tk;
        password = pass;
    };
    friend class AbburFr;
    friend void tellFuncSecret(Parent *ptr);
};
class AbburFr
{
public:
    void tellSectret(Parent *ptr)
    {
        cout << ptr->taka << endl;
        cout << ptr->password << endl;
    }
};

void tellFuncSecret(Parent *ptr)
{
    cout << ptr->taka << endl;
    cout << ptr->password << endl;
}
int main()
{
    Parent pt(1500, 123123);
    AbburFr bondhu;
    bondhu.tellSectret(&pt);
    tellFuncSecret(&pt);
    return 0;
}