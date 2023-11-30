#include <bits/stdc++.h>
using namespace std;
class Complex{
    private:
        int real;
        int img;
    public:
        void input()
        {
            cout<<"Enter the real part: ";
            cin>>real;
            cout<<"Enter the img part : ";
            cin>>img;
        }
        Complex operator +(Complex obj)
        {
            Complex c;
            c.real = real+obj.real;
            c.img = img+obj.img;
            return c;
        }
        Complex operator*(Complex obj)
        {
           Complex c;
           c.real = real*obj.real;
           c.img = img*obj.img;
           return c;
           
        }
       friend std::ostream &operator <<(ostream &out, const Complex &c)
       {
             out<<c.real;
             if(c.img >= 0)
             {
                out<<"+"<<c.img<<"i";

             }
             else
             {
                out<<"-"<<c.img<<"i";
             }
             return out;
       }
       friend std::istream & operator >>(istream &in, Complex &c)
       {
             cout<<"Enter real part:"<<endl;
             in>>c.real;
             cout<<"Enter img part:"<<endl;
             in>>c.img;
             return in;
       }
       
};
int main()
{
   Complex c1,c2;
   cout<<"Enter 1st :"<<endl;
   cin>>c1;
    cout<<"Enter 2nd :"<<endl;
   cin>>c2; 
   Complex sum = c1+c2;
   Complex multi = c1*c2;
   cout<<"sum: "<<sum<<endl;
   cout<<"product: "<<multi<<endl;


   return 0;
}