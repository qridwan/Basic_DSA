#include <bits/stdc++.h>
using namespace std;
// class n object
class Student
{
public: // Access modifier / Specifier => public,private, protected
    char name[100];
    int roll;
    void sayHi()
    {
        cout << "hi " << endl;
    }
};
int main()
{
    Student rahim;
    strcpy(rahim.name, "Rahim Akbar");
    rahim.roll = 56;
    rahim.sayHi();
    cout << rahim.name << " " << rahim.roll << endl;
    return 0;
}