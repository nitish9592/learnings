//TYPES
//1.COMPILE TIME  2.RUM TIME
//1.1function overloading or method overloading or class overloading; --> read from notes pg 17
//1.2 oprator overloading in this code---->>
#include <iostream>
using namespace std;

class cmp{
    int real,img;

    public:
        cmp(){};//default constructor

        cmp(int real,int img){//constructor
            this->real=real;
            this->img=img;
        }

        void display(){//display
            cout<<real <<img<<"i"<<endl;
        }
        cmp operator +(cmp &C){//oprator overloading
            cmp ans;
            ans.real =real +C.real;
            ans.img =img + C.img;
            return ans;
        }
        cmp operator -(cmp &C){//oprator overloading
            cmp ans;
            ans.real =real - C.real;
            ans.img =img - C.img;
            return ans;
        }
};



int main()
{
    cmp C1(3,4);
    cmp C2(4,6);
    cmp C3=C1+C2;//similar as C1.fun(C2)
    C3.display();
    return 0;
}
//NOTE
/*In C++, the following operators cannot be overloaded: 
Scope resolution operator: (::)
Size-of operator: sizeof()
Member selector: (.)
Member pointer selector: (*)
Ternary operator: (? : )
Object type operator: typeid
*/