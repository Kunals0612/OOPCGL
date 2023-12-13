#include <iostream>
#include <fstream>
using namespace std;

class fliehandling{
    int roll;
    char name[20];
    float marks;

public:
     void input(){
        ofstream fout("file name", ios::app);
        cout<<"file operations: "<<endl;
        cout<<"enter the rollno.: ";
        cin>>roll;
        fout<<roll<<endl;
        cout<<"name: ";
        cin>>name;
        fout<<name<<endl;
        cout<<"marks: ";
        cin>>marks;
        fout<<marks<<endl;
        fout.close();

     }
     void write(){
        ifstream fin("file name");
        cout<<"reading operations: "<<endl;
        while(fin>>roll>>name>>marks){
            cout<<"roll: "<<roll<<"  name: "<<name<<"  marks: "<<marks<<endl;
        }
        fin.close();
     }

};

int main(){
    fliehandling obj;
    char ch;
    do{
        obj.input();
        cout<<"Do you want to continue? (y/n) ";
        cin>>ch;
    }while((ch == 'y')||(ch == 'Y'));

    obj.write();
    return 0;
}
