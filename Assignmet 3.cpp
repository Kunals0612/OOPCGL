#include <bits/stdc++.h>
using namespace std;
class Student{
public:
string name,bloodgrp,address,cls;
int roll_no,div,dob,telph,drivlic;
    Student()
{
    cout<<"--------------student information---------------"<<endl;
    cout<<endl;
}
    Student(int d,int db,int tph,int dl, string nme, string bg, string add, string cl)
    {
    
    cls = cl;
    div = d;
    dob = db;
    telph = tph;
    drivlic = dl;
    name = nme;
    bloodgrp = bg;
    address = add;

    }
    ~Student()
    {
        cout<<"-------------END-------------"<<endl;
    }
    void display()
    {
    cout<<"Name is : "<<name<<endl;
    cout<<"Class is : "<<cls<<endl;
    cout<<"Division is : "<<div<<endl;
    cout<<"Roll no is : "<<roll_no<<endl;
    cout<<"Date of birth is : "<<dob<<endl;
    cout<<"Address is : "<<address<<endl;
    cout<<"Telephone number is : "<<telph<<endl;
    cout<<"Driving license : "<<drivlic<<endl;
    cout<<"Blood grp is : "<<bloodgrp<<endl;
    cout<<"roll no is :"<<roll_no<<endl;
    cout<<endl;

    }
    void getnumber()
    {
        try
        {
            cout<<"Enter the roll number:"<<endl;
            cin>>roll_no;
            if(roll_no<=0) throw 0;
            
        }
        catch(int num)
        {
            cout<<"Invalid input"<<endl;
        }
        
    }
    friend class Marks;

};
class Marks{
public:
int phy;
int chem;
int math;
Marks(int p,int c, int m)
{
phy = p;
chem = c;
math = m;
}

void display(Student& t)
{
cout<<"------Acedemic Information-----------"<<endl;
cout<<endl;
cout<<"Class : "<<t.cls<<endl;
cout<<"Division is  :"<<t.div<<endl;
cout<<"Roll no : "<<t.roll_no<<endl;
cout<<"Physics Marks : "<<phy<<endl;
cout<<"chemistry Marks : "<<chem<<endl;
cout<<"Math Marks : "<<math<<endl;
cout<<"Total Marks are : "<<(phy+chem+math)<<endl;
}
inline void eligible(){
    if((phy+chem+math)>=105)
    {
        cout<<"Student is pass"<<endl;
    }
    else
    {
        cout<<"Student is fail"<<endl;
    }
}
};

int main() {
int rn,d,db,tph,dl;
string nme,bg,add,cl;
cout<<"Enter the Name : "<<endl;
cin>>nme;
cout<<"Enter the class : "<<endl;
cin>>cl;
cout<<"Enter the Division : "<<endl;
cin>>d;

cout<<"Enter the Date of Birth : "<<endl;
cin>>db;
cout<<"Enter the Address : "<<endl;
cin>>add;
cout<<"Enter the Telephone number : "<<endl;
cin>>tph;
cout<<"Enter the driving license : "<<endl;
cin>>dl;
cout<<"Blood group is : "<<endl;
cin>>bg;
Student s(d,db,tph,dl,nme,bg,add,cl);
s.getnumber();
Student z;
s.display();
int p,c,m;
cout<<"Enter the marks of physics : "<<endl;
cin>>p;
cout<<"Enter the marks of chemistry : "<<endl;
cin>>c;
cout<<"Enter the marks of math : "<<endl;
cin>>m;
Marks M(p,c,m);
M.display(s);
string* batch =  NULL;
batch = new(nothrow) string;
if(!batch)
{
    cout<<"Allocation of memory failed"<<endl;
}
else{
    *batch = "H1";
    cout<<"Batch of student is : "<<*batch<<endl;
}
    M.eligible();


return 0;
}