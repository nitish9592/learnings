#include <iostream>
using namespace std;

class A {               //SINGLE INHERITANCE
    void apvt(){
        cout<<"this is private element of A"<<endl;
    }
    public:

    void apub(){
        cout<<"public of A"<<endl;
    }
    void getapvt(){
        apvt();//private cant be accessed directly therefore this funtion is used;
    }
};
class B {
    void bpvt(){
        cout<<"pvt of B "<<endl;
    }
    public:
    void bpub(){
        cout<<"public of B"<<endl;
    }
    void getbpvt(){
        bpvt();
    }

};
class C {
    void cpvt(){
        cout<<"pvt of C "<<endl;
    }
    public:
    void cpub(){
        cout<<"public of C"<<endl;
    }
    void getcpvt(){
        cpvt();
    }

};
class X :public A{//SINGLE INHERITANCEl

};
class Y:public A,public B{// MULTIPLE INHERITANCE//

};
class Z : public Y{//multilevel INHERITANCE//

};
class H:public X,public C{};//hybrid inheritance//note;;here we cant inherit from the Y (since A has been already inherited through X  )
int main(){
    cout<<"SINGLE INHERITANCE"<<endl;
    X x;  //SINGLE INHERITANCE
    x.apub();
    x.getapvt();//this private elment(em) is accessed through the getem wiz public 
    
    cout<<" MULTIPLE INHERITANCE"<<endl;
    Y y ;// MULTIPLE INHERITANCE//note;; AGR Y TRY KRE  X SE INHERIT KA TOH error aa jayega because y has already inheritid the a,b
    y.apub();
    y.bpub();
    y.getapvt();
    y.getbpvt();

    cout<<" MULTILEVEL INHERITANCE"<<endl;
    Z z;
    z.apub();
    z.bpub();
    z.getapvt();
    z.getbpvt();
    
    cout<<" hybrid INHERITANCE"<<endl;
    H h;
    h.apub();
    h.cpub();
    h.getapvt();
    h.getcpvt();



    
    return 0;
}