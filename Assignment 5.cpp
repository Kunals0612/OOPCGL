#include <bits/stdc++.h>
using namespace std;
class Publication{
    public:
        string title;
        float price;
 

};
class Book: public Publication{
     public:
         int page_count;
         string auother;
     Book(int page_count, string auother, string title, float price)
     {
        this->page_count = page_count;
      
        this->auother = auother;
        this->title = title;
        this->price = price;
       
     }
     void displayBook();
};

void Book::displayBook()
{
    cout<<"The title of the book is : "<<title<<endl;
    cout<<"Price of the book is : "<<price<<endl;
    cout<<"Total page numbers are : "<<page_count<<endl;
    cout<<"Name of the auother is : "<<auother<<endl;
    cout<<endl;
}
class Tape: public Publication{
    public:
       int time;
       string composer;
    Tape(int time, string composer,string title, float price)
    {
        this->time = time;
        this->composer = composer;
        this->title = title;
        this->price = price;
    }
    void displayTape();
};
void Tape::displayTape()
{
    cout<<"The title of the Tape is : "<<title<<endl;
    cout<<"Price of the Tape is : "<<price<<endl;
    cout<<"Time of tape is : "<<time<<endl;
    cout<<"Name of composer is : "<<composer<<endl;
}
int main()
{
   string t,a,c;
   float p;
   int pc,ti;
   cout<<"Enter title of the book : "<<endl;
   cin>>t;
   cout<<"Enter Price of the book :"<<endl;
   cin>>p;
   cout<<"Enter Total page numbers : "<<endl;
   cin>>pc;
   cout<<"Name of the auother is : "<<endl;
   cin>>a;
   Book b(pc,a,t,p);
      try 
        {
            if(pc<=0) throw 0;
        }
        catch(int num)
        {
            cout<<"Page number is invalid "<<endl;    
        }
   b.displayBook();
   cout<<"Enter title of the Tape : "<<endl;
   cin>>t;
   cout<<"Enter Price of the Tape :"<<endl;
   cin>>p;
   cout<<"Enter the time of Tape : "<<endl;
   cin>>ti;
   cout<<"Enter the composer name : "<<endl;
   cin>>c;
   Tape tp(ti,c,t,p);
   tp.displayTape();
   return 0;
}
