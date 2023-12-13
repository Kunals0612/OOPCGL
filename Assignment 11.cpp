#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
class Student
{
private:
    string name;
    string dob;
    int tnum;
    int marks;
public:
    Student()
    {
        name = "";
        dob = "";
        tnum = 0;
        marks = 0;
    }
    Student(string n, string d, int t, int m)
    {
        name = n;
        dob = d;
        tnum = t;
        marks = m;
    }
    void display()
    {
        cout << "Name: " << name << "\tDOB: " << dob << "\ttele: " << tnum << "\tMarks: " << marks << endl;
    }
    string getName() const
    {
        return name;
    }
    int getnumb() const
    {
        return tnum;
    }
};

bool Comparebyname(const Student &s1, const Student &s2)
{
    return s1.getName() < s2.getName();
}
bool Comparebynumber(const Student &s1, const Student &s2)
{
    return s1.getnumb() < s2.getnumb();
}
int main()
{
    vector<Student> v;
    Student s1("a", "403", 54444, 33);
    Student s2("b", "500", 5412, 23);
    Student s3("c", "300", 5433, 66);
    Student s4("d", "600", 54, 77);
    v.push_back(s1);
    v.push_back(s2);
    v.push_back(s3);
    v.push_back(s4);
    for (int i = 0; i < 4; i++)
    {
        v[i].display();
    }
    cout << "sorting by name: " << endl;
    sort(v.begin(), v.end(), Comparebyname);
    for (int i = 0; i < 4; i++)
    {
        v[i].display();
    }
    cout << "sorting by number: " << endl;
    sort(v.begin(), v.end(), Comparebynumber);
    for (int i = 0; i < 4; i++)
    {
        v[i].display();
    }
    return 0;
}
