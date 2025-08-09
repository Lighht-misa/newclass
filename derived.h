#include <iostream>

class Base{
    public:
    Base(){}
    Base(int i1,int i2):proteactednum(i2),privatenum(i1){//std::cout<<"Base's constor\n";
        }
    ~Base(){//std::cout<<"Base's destructor\n";
        }        
    void Basefunc()
       {
        std::cout<<"Basefun"<<"\n";
        std::cout<<"proteactednum="<<proteactednum<<"\n";
        std::cout<<"privatenum="<<privatenum<<"\n";
        }
        virtual void display(){
        std::cout<<"Base display"<<"\n";
        std::cout<<"proteactednum="<<proteactednum<<"\n";
        std::cout<<"privatenum="<<privatenum<<"\n";
        }
    protected:
        int proteactednum=0;
    private:
        int privatenum=0;
};
class Derived:public Base{
    public:
    Derived():Base(1,2){//std::cout<<//"Derived's constor\n";
        }
    Derived(int num1,int num2):Base(num1,num2){}
    ~Derived(){//std::cout<<//"Derived's destructor\n";
        }
    void display(){std::cout<<"Derived's display\n";}
    void Derivedfunc(){
    std::cout<<"Derivedfun"<<"\n";
    std::cout<<"proteactednum="<<proteactednum<<"\n";
    //std::cout<<"privatenum"<<privatenum;
    }
 
};